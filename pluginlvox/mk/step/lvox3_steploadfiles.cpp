#include "lvox3_steploadfiles.h"

#include <QDialog>
#include <QDebug>

#include "ct_itemdrawable/model/outModel/ct_outstdgroupmodel.h"
#include "ct_itemdrawable/model/outModel/ct_outstdsingularitemmodel.h"
#include "ct_result/model/inModel/ct_inresultmodelnotneedinputresult.h"
#include "ct_result/model/outModel/ct_outresultmodelgroup.h"
#include "ct_result/ct_resultgroup.h"
#include "ct_itemdrawable/ct_standarditemgroup.h"
#include "ct_itemdrawable/ct_scanner.h"
#include "ct_itemdrawable/ct_scene.h"
#include "ct_itemdrawable/tools/scanner/ct_shootingpattern.h"
#include "ct_itemdrawable/tools/scanner/ct_thetaphishootingpattern.h"
#include "ct_itemdrawable/tools/scanner/ct_shootingpatternfrompointcloud.h"
#include "ct_itemdrawable/tools/scanner/ct_parallelshootingpatternfrompointcloud.h"
#include "ct_model/tools/ct_modelsearchhelper.h"

#include "ct_view/tools/ct_configurablewidgettodialog.h"
#include "ct_reader/abstract/ct_abstractreader.h"
#include "ct_reader/ct_standardreaderseparator.h"
#include "ct_reader/extensions/ct_readerpointsfilteringextension.h"
#include "ct_abstractstepplugin.h"
#include "mk/tools/lvox3_scannerutils.h"


#include "ct_iterator/ct_pointiterator.h"
#include "ct_accessor/ct_pointaccessor.h"

#include "ct_reader/extensions/ct_readerpointsfilteringextension.h"


#define SETTING_READ(NAME, NAMEVAR, TYPE)           \
do {                                                \
    value = groupFile->firstValueByTagName(NAME);   \
    if(value == NULL) {                             \
        delete reader;                              \
        return false;                               \
    }                                               \
    NAMEVAR = value->value().TYPE();                \
} while(0)

#define DEF_outResult                "LVOX3_SLF_result"
#define DEF_outGroup                 "LVOX3_SLF_group"
#define DEF_outScannerForced         "LVOX3_SLF_scanner"

LVOX3_StepLoadFiles::LVOX3_StepLoadFiles(CT_StepInitializeData &dataInit) :
    CT_AbstractStepCanBeAddedFirst(dataInit)
{
    m_reader = NULL;
    m_useUserScannerConfiguration = false;
    m_filterPointsOrigin = true;
}

LVOX3_StepLoadFiles::~LVOX3_StepLoadFiles()
{
    qDeleteAll(m_availableReaders.begin(), m_availableReaders.end());

    delete m_reader;
}

QString LVOX3_StepLoadFiles::getStepDescription() const
{
    return tr("1 - Charger des fichiers pour LVOX (LVOX 3)");
}

// Step detailed description
QString LVOX3_StepLoadFiles::getStepDetailledDescription() const
{
    return tr("Cette étape permet de charger des fichiers à l'aide de différents readers pour pouvoir créer des grilles de densité.");
}

CT_VirtualAbstractStep* LVOX3_StepLoadFiles::createNewInstance(CT_StepInitializeData &dataInit)
{
    // Creates an instance of this step
    return new LVOX3_StepLoadFiles(dataInit);
}

SettingsNodeGroup* LVOX3_StepLoadFiles::getAllSettings() const
{
    SettingsNodeGroup *root = CT_AbstractStepCanBeAddedFirst::getAllSettings();

    SettingsNodeGroup *group = new SettingsNodeGroup("LVOX3_StepLoadFiles");
    group->addValue(new SettingsNodeValue("useScannerConfiguration", m_useUserScannerConfiguration));
    group->addValue(new SettingsNodeValue("filterPointsOrigin", m_filterPointsOrigin));

    SettingsNodeGroup* groupReader = new SettingsNodeGroup("Reader");

    if(m_reader != NULL) {
        groupReader->addValue(new SettingsNodeValue("name", m_reader->GetReaderClassName()));
        groupReader->addGroup(m_reader->getAllSettings());
    }

    group->addGroup(groupReader);

    int n = m_configuration.size();

    for(int i=0; i<n; ++i) {
        const LoadFileConfiguration::Configuration& c = m_configuration.at(i);
        const auto scanDef = LVOX3_ScannerUtils::getScannerDefinition(c.scannerId);
        SettingsNodeGroup *groupFile = new SettingsNodeGroup("File");
        groupFile->addValue(new SettingsNodeValue("version", 1));
        groupFile->addValue(new SettingsNodeValue("filepath", c.filepath));
        groupFile->addValue(new SettingsNodeValue("scannerType", scanDef.label));
        groupFile->addValue(new SettingsNodeValue("clockWise", c.clockWise));
        groupFile->addValue(new SettingsNodeValue("radians", c.radians));
        groupFile->addValue(new SettingsNodeValue("scannerPositionX", c.scannerPosition.x()));
        groupFile->addValue(new SettingsNodeValue("scannerPositionY", c.scannerPosition.y()));
        groupFile->addValue(new SettingsNodeValue("scannerPositionZ", c.scannerPosition.z()));
        groupFile->addValue(new SettingsNodeValue("scannerResolutionX", c.scannerResolution.x()));
        groupFile->addValue(new SettingsNodeValue("scannerResolutionY", c.scannerResolution.y()));
        groupFile->addValue(new SettingsNodeValue("scannerThetaStart", c.scannerThetaRange.x()));
        groupFile->addValue(new SettingsNodeValue("scannerThetaEnd", c.scannerThetaRange.y()));
        groupFile->addValue(new SettingsNodeValue("scannerPhiStart", c.scannerPhiRange.x()));
        groupFile->addValue(new SettingsNodeValue("scannerPhiEnd", c.scannerPhiRange.y()));
        groupFile->addValue(new SettingsNodeValue("scannerDirectionX", c.scannerDirection.x()));
        groupFile->addValue(new SettingsNodeValue("scannerDirectionY", c.scannerDirection.y()));
        groupFile->addValue(new SettingsNodeValue("scannerDirectionZ", c.scannerDirection.z()));
        group->addGroup(groupFile);
    }

    root->addGroup(group);

    return root;
}

bool LVOX3_StepLoadFiles::setAllSettings(const SettingsNodeGroup* settings)
{
    if(!CT_AbstractStepCanBeAddedFirst::setAllSettings(settings))
        return false;

    QList<SettingsNodeGroup*> listG = settings->groupsByTagName("LVOX3_StepLoadFiles");

    if(!listG.isEmpty())
    {
        QList<LoadFileConfiguration::Configuration> confs;

        bool useUserScannerConfiguration;
        bool filterPointsOrigin;
        CT_AbstractReader* reader = NULL;

        SettingsNodeValue* value;
        SettingsNodeGroup* groupFile = listG.first();
        SETTING_READ("useScannerConfiguration", useUserScannerConfiguration, toBool);
        SETTING_READ("filterPointsOrigin", filterPointsOrigin, toBool);

        QList<SettingsNodeGroup*> listConfiguration = groupFile->groupsByTagName("File");

        groupFile = groupFile->firstGroupByTagName("Reader");

        if((groupFile == NULL) || groupFile->groups().isEmpty())
            return false;

        QString readerClassName;
        SETTING_READ("name", readerClassName, toString);

        initReaders();
        reader = getReaderByClassName(readerClassName);

        if(reader == NULL)
            return false;

        reader = reader->copy();
        reader->init(false);

        if(!reader->setAllSettings(groupFile->groups().first())) {
            delete reader;
            return false;
        }

        QListIterator<SettingsNodeGroup*> it(listConfiguration);

        while(it.hasNext())
        {
            groupFile = it.next();

            LoadFileConfiguration::Configuration c;
            QString scannerType;
            SETTING_READ("filepath", c.filepath, toString);
            SETTING_READ("scannerType", scannerType, toString);
            SETTING_READ("clockWise", c.clockWise, toDouble);
            SETTING_READ("radians", c.radians, toDouble);
            SETTING_READ("scannerPositionX", c.scannerPosition.x(), toDouble);
            SETTING_READ("scannerPositionY", c.scannerPosition.y(), toDouble);
            SETTING_READ("scannerPositionZ", c.scannerPosition.z(), toDouble);
            SETTING_READ("scannerResolutionX", c.scannerResolution.x(), toDouble);
            SETTING_READ("scannerResolutionY", c.scannerResolution.y(), toDouble);
            SETTING_READ("scannerThetaStart", c.scannerThetaRange.x(), toDouble);
            SETTING_READ("scannerThetaEnd", c.scannerThetaRange.y(), toDouble);
            SETTING_READ("scannerPhiStart", c.scannerPhiRange.x(), toDouble);
            SETTING_READ("scannerPhiEnd", c.scannerPhiRange.y(), toDouble);
            SETTING_READ("scannerDirectionX", c.scannerDirection.x(), toDouble);
            SETTING_READ("scannerDirectionY", c.scannerDirection.y(), toDouble);
            SETTING_READ("scannerDirectionZ", c.scannerDirection.z(), toDouble);

            const auto scanDef = LVOX3_ScannerUtils::getScannerDefinition(scannerType);
            c.scannerId = scanDef.id;
            confs.append(c);
        }

        delete m_reader;
        m_reader = reader;

        m_useUserScannerConfiguration = useUserScannerConfiguration;
        m_filterPointsOrigin = filterPointsOrigin;
        m_configuration = confs;

        return true;
    }

    return false;
}

CT_ShootingPattern *LVOX3_StepLoadFiles::makeShootingPattern(
        const LoadFileConfiguration::Configuration &conf, CT_PCIR pcir)
{
    /* TODO: Move this factory to the CT_Scanner class. Requires to move the
     * Configuration class used by the UI (simplifies passing arguments).
     */
    CT_ShootingPattern *pattern = nullptr;
    double hFov = NULL;
    double vFov = NULL;

    switch (conf.scannerId) {
    case ScannerSphericPointCloud:
    {
        return new CT_ShootingPatternFromPointCloud(conf.scannerPosition, pcir);
        break;
    }
    case ScannerPlanePointCloud:
        return new CT_ParallelShootingPatternFromPointCloud(conf.scannerPosition,
                                                            conf.scannerDirection,
                                                            pcir);
        break;
    case ScannerSphericTheoreticScanner:
        // TODO : zVector !
        hFov = conf.scannerThetaRange.y() - conf.scannerThetaRange.x();
        vFov = conf.scannerPhiRange.y() - conf.scannerPhiRange.x();
        pattern = new CT_ThetaPhiShootingPattern(conf.scannerPosition,
                                                 hFov, vFov,
                                                 conf.scannerResolution.x(),
                                                 conf.scannerResolution.y(),
                                                 conf.scannerThetaRange.x(),
                                                 conf.scannerPhiRange.x(),
                                                 Eigen::Vector3d(0, 0, 1),
                                                 conf.clockWise,
                                                 conf.radians);
        break;
    case ScannerSphericTheoreticCustom:
    {
        // TODO : zVector !
        hFov = conf.scannerThetaRange.y() - conf.scannerThetaRange.x();
        vFov = conf.scannerPhiRange.y() - conf.scannerPhiRange.x();
        pattern = new CT_ThetaPhiShootingPattern(conf.scannerPosition,
                                                 hFov, vFov,
                                                 conf.scannerResolution.x(),
                                                 conf.scannerResolution.y(),
                                                 conf.scannerThetaRange.x(),
                                                 conf.scannerPhiRange.x(),
                                                 Eigen::Vector3d(0, 0, 1),
                                                 conf.clockWise,
                                                 conf.radians);
        break;
    }
    default:
        break;
    }
    return pattern;
}

void LVOX3_StepLoadFiles::createInResultModelListProtected()
{
    setNotNeedInputResult();
}

bool LVOX3_StepLoadFiles::postConfigure()
{
    initReaders();

    LoadFileConfiguration c;
    c.setReaders(m_availableReaders);
    c.setCurrentReaderByClassName(m_reader != NULL ? m_reader->GetReaderClassName() : "");
    c.setConfiguration(m_configuration);
    c.setFilterPointsOrigin(m_filterPointsOrigin);

    if(CT_ConfigurableWidgetToDialog::exec(&c) == QDialog::Rejected)
        return false;

    QList<LoadFileConfiguration::Configuration> configs = c.getConfiguration();
    CT_AbstractReader* reader = c.getReaderToUse()->copy();

    if(reader->setFilePath(configs.first().filepath)) {
        reader->setFilePathCanBeModified(false);
        bool ok = reader->configure();
        reader->setFilePathCanBeModified(true);

        if(ok) {
            delete m_reader;
            m_reader = reader;
            m_configuration = configs;
            m_useUserScannerConfiguration = false;

            foreach(const LoadFileConfiguration::Configuration& config, configs) {
                if(LVOX3_ScannerUtils::isCustomScannerConfiguration(config.scannerId)) {

                    m_useUserScannerConfiguration = true;
                    break;
                }
            }

            m_filterPointsOrigin = c.isFilterPointsOrigin();
            setSettingsModified(true);
            return true;
        }
    }

    return false;
}

bool LVOX3_StepLoadFiles::protectedInitAfterConfiguration()
{
    if(m_reader != NULL)
        m_reader->createOutItemDrawableModelList();

    return m_reader != NULL;
}

void LVOX3_StepLoadFiles::createOutResultModelListProtected()
{
    if(m_reader == NULL)
        return;

    CT_OutStdGroupModel *root = new CT_OutStdGroupModel(DEF_outGroup);

    QListIterator<CT_OutStdSingularItemModel*> it(m_reader->outItemDrawableModels());

    while(it.hasNext())
    {
        CT_OutStdSingularItemModel *model = it.next();
        root->addItem((CT_OutStdSingularItemModel*)model->copy());
    }

    QListIterator<CT_OutStdGroupModel*> itG(m_reader->outGroupsModel());

    while(itG.hasNext())
    {
        CT_OutStdGroupModel *model = itG.next();
        root->addGroup((CT_OutStdGroupModel*)model->copy());
    }

    CT_FileHeader *header = m_reader->createHeaderPrototype();

    if(header != NULL)
        root->addItem(new CT_OutStdSingularItemModel("", header, tr("Entête de fichier")), m_autoRenameFileHeader);

    root->addItem(new CT_OutStdSingularItemModel(DEF_outScannerForced, new CT_Scanner(), tr("Scanner LVOX"), tr("Shooting Pattern/Position/Direction/Angle forced by user")));

    addOutResultModel(new CT_OutResultModelGroup(DEF_outResult, root, "Result"));
}

void LVOX3_StepLoadFiles::compute()
{
    CT_ResultGroup *out_res = getOutResultList().first();

    int i = 0;
    size_t sceneTotalPoints = 0;
    size_t filteredPoints = 0;
    int nFilesProgress = 0; //Used to count the number of files
    QListIterator<LoadFileConfiguration::Configuration> it(m_configuration);

    /*
     * Configure the filter of the reader based on the selected option
     */
    if (m_filterPointsOrigin) {
        CT_ReaderPointsFilteringExtension* readerWithFilter = dynamic_cast<CT_ReaderPointsFilteringExtension*>(m_reader);

        if(readerWithFilter != NULL) {
            readerWithFilter->setPointsFilter([](const CT_Point &pt){
                return (pt == Eigen::Vector3d::Zero());
            });
        }
    }
    //Counts the number of files (There has to be a more efficient way) used for progress bar
    while(it.hasNext()){
        nFilesProgress++;
        it.next();
    }
    it.toFront();//Brings pointer back to front after counting

    /*
     * Load all files
     */
    while(it.hasNext())
    {


        const LoadFileConfiguration::Configuration& config = it.next();

        CT_FileHeader *header = NULL;

        if(m_reader->setFilePath(config.filepath)
                && ((header = m_reader->readHeader()) != NULL)
                && m_reader->readFile()) {

            CT_StandardItemGroup *group = new CT_StandardItemGroup(DEF_outGroup, out_res);

            QListIterator<CT_OutStdSingularItemModel*> it(m_reader->outItemDrawableModels());
            CT_Scene *scene = nullptr;

            while(it.hasNext())
            {
                CT_OutStdSingularItemModel *model = it.next();
                CT_OutAbstractItemModel *modelCreation = (CT_OutAbstractItemModel*)PS_MODELS->searchModelForCreation(model->uniqueName(), out_res);

                QList<CT_AbstractSingularItemDrawable*> items = m_reader->takeItemDrawableOfModel(model->uniqueName(), out_res, modelCreation);
                QListIterator<CT_AbstractSingularItemDrawable*> itI(items);

                while(itI.hasNext()) {
                    CT_AbstractSingularItemDrawable* item = itI.next();

                    if (CT_Scene *scn = dynamic_cast<CT_Scene*>(item)) {
                        scene = scn;
                        //Test to see which points are filtered, it doesn't seem to filter anything, since the filter is looking for points on 0,0,0 and there are none.
//                        CT_PointIterator itPointCloud(scene->getPointCloudIndex());
//                        size_t numberPoints = itPointCloud.size();
//                        sceneTotalPoints += itPointCloud.size();

//                        if (m_filterPointsOrigin) {
//                            qDebug()<<"Filter Option is on!";
//                            CT_ReaderPointsFilteringExtension* readerWithFilter = dynamic_cast<CT_ReaderPointsFilteringExtension*>(m_reader);

//                            if(readerWithFilter != NULL) {
//                                qDebug()<<"Reader with Filter exists!";
//                                while(itPointCloud.hasNext() && !isStopped())
//                                {
//                                    const CT_Point &point = itPointCloud.next().currentPoint();

//                                    if(readerWithFilter->isPointFiltered(point))
//                                        ++filteredPoints;
//                                }
//                            }
//                        }
                    }

                    group->addItemDrawable(item);
                }
            }

            QListIterator<CT_OutStdGroupModel*> itG(m_reader->outGroupsModel());

            while(itG.hasNext())
            {
                CT_OutStdGroupModel *model = itG.next();
                CT_OutAbstractItemModel *modelCreation = (CT_OutAbstractItemModel*)PS_MODELS->searchModelForCreation(model->uniqueName(), out_res);

                QList<CT_AbstractItemGroup*> groups = m_reader->takeGroupOfModel(model->uniqueName(), out_res, modelCreation);
                QListIterator<CT_AbstractItemGroup*> itI(groups);

                while(itI.hasNext())
                    group->addGroup(itI.next());
            }

            header->changeResult(out_res);
            header->setModel(m_autoRenameFileHeader.completeName());

            group->addItemDrawable(header);

            if (!scene) {
                PS_LOG->addErrorMessage(this, tr("CT_Scene object not found or loaded object has no scene."));
            }
            if(scene) {
                CT_PCIR pcir = scene->getPointCloudIndexRegistered();
                CT_ShootingPattern *pattern = makeShootingPattern(config, pcir);
                //Creates Scanner LVOX, to take in account custom shooting patterns and scanner position shifts
                if(pattern != NULL) {
                    CT_Scanner *scanner = new CT_Scanner(DEF_outScannerForced, out_res, i, pattern);

                    group->addItemDrawable(scanner);
                }
            }

            out_res->addGroup(group);

            ++i; 
            //Each file is an equal percentage of loading
            setProgress((100.00/nFilesProgress)*i);
        } else {
            delete header;
        }
    }
    PS_LOG->addMessage(LogInterface::info, LogInterface::step, QString(tr("La scène d'entrée comporte %1 points.")).arg(sceneTotalPoints));
    PS_LOG->addMessage(LogInterface::info, LogInterface::step, QString(tr("La scène d'entrée comporte %1 points filtrés.")).arg(filteredPoints));
}

void LVOX3_StepLoadFiles::initReaders()
{
    if(m_availableReaders.isEmpty()) {
        // get the plugin manager
        PluginManagerInterface *pm = PS_CONTEXT->pluginManager();
        int s = pm->countPluginLoaded();

        // for each plugin
        for(int i=0; i<s; ++i)
        {
            CT_AbstractStepPlugin *p = pm->getPlugin(i);

            // get readers
            QList<CT_StandardReaderSeparator*> rsl = p->getReadersAvailable();
            QListIterator<CT_StandardReaderSeparator*> itR(rsl);

            while(itR.hasNext())
            {
                CT_StandardReaderSeparator *rs = itR.next();
                QListIterator<CT_AbstractReader*> itE(rs->readers());

                while(itE.hasNext())
                {
                    CT_AbstractReader *reader = itE.next()->copy();
                    reader->init(false);

                    // and add it to the list
                    m_availableReaders.append(reader);
                }
            }
        }
    }
}

CT_AbstractReader* LVOX3_StepLoadFiles::getReaderByClassName(const QString &className) const
{
    QListIterator<CT_AbstractReader*> it(m_availableReaders);

    while(it.hasNext()) {
        CT_AbstractReader* r = it.next();

        if(r->GetReaderClassName() == className) {
            return r;
        }
    }

    return NULL;
}