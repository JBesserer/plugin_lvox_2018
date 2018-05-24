#include "lvox3_stepcomputeprofiles.h"

#include "ct_result/model/inModel/ct_inresultmodelgrouptocopy.h"
#include "ct_result/model/outModel/tools/ct_outresultmodelgrouptocopypossibilities.h"
#include "mk/tools/lvox3_gridtype.h"
#include "ct_result/ct_resultgroup.h"

#include "ct_view/ct_stepconfigurabledialog.h"

#include "ct_view/tools/ct_configurablewidgettodialog.h"

#include "mk/tools/lvox3_errorcode.h"

// Alias for indexing in models
#define DEF_SearchInResult  "res"
#define DEF_SearchInGroup   "grp"
#define DEF_SearchInGrid    "grid"
#define MINProfile(a, b) ((a < b) ? b : a)
#define MAXProfile(a, b) ((a > b) ? b : a)

#define READSETTINGS(STRVALUENAME, VARIABLE, CONVERTO) value = group->firstValueByTagName(STRVALUENAME); \
                                                        if(value == NULL) \
                                                            return false; \
                                                        VARIABLE = value->value().CONVERTO;

LVOX3_StepComputeProfiles::LVOX3_StepComputeProfiles(CT_StepInitializeData &dataInit) : CT_AbstractStep(dataInit)
{
    m_configuration.minValue = 0.0;
    m_configuration.maxValue = 999999.00;
    m_configuration.ordonneeAxis = "Z";
    m_configuration.genAxis = "X";
    m_configuration.unitType = "Coordonnées";
    m_configuration.gridCustomized = false;
    m_configuration.genValuesInPourcent = false;
    m_configuration.minGen = -100.00;
    m_configuration.maxGen = 100.00;
    m_configuration.stepGen = 999999.00;
    m_configuration.terminalCustomized = false;
    m_configuration.abscisseOrdonneeValuesInPourcent = false;
    m_configuration.minAbscisse = -100.00;
    m_configuration.maxAbscisse = 100.00;
    m_configuration.minOrdonnee = -100.00;
    m_configuration.maxOrdonnee = 100.00;
}

QString LVOX3_StepComputeProfiles::getStepDescription() const
{
    return tr("6 - Créer des profils à partir de voxels (LVOX 3)");
}

// Step detailed description
QString LVOX3_StepComputeProfiles::getStepDetailledDescription() const
{
    return tr("Cette étape permet de créer un histogramme de densité pour toute la grille 3D ou une partie de celle-ci.");
}

CT_VirtualAbstractStep* LVOX3_StepComputeProfiles::createNewInstance(CT_StepInitializeData &dataInit)
{
    // Creates an instance of this step
    return new LVOX3_StepComputeProfiles(dataInit);
}

SettingsNodeGroup* LVOX3_StepComputeProfiles::getAllSettings() const
{
    SettingsNodeGroup *root = CT_AbstractStep::getAllSettings();

    SettingsNodeGroup *group = new SettingsNodeGroup("LVOX3_StepComputeProfiles");
    root->addGroup(group);

    qDebug()<<"Min value:"<<m_configuration.minValue;
    qDebug()<<"Max value:"<<m_configuration.maxValue;
    group->addValue(new SettingsNodeValue("version", 1));
    group->addValue(new SettingsNodeValue("minValue", m_configuration.minValue));
    group->addValue(new SettingsNodeValue("maxValue", m_configuration.maxValue));
    group->addValue(new SettingsNodeValue("ordonneeAxis", m_configuration.ordonneeAxis));
    group->addValue(new SettingsNodeValue("genAxis", m_configuration.genAxis));
    group->addValue(new SettingsNodeValue("unitType", m_configuration.unitType));
    group->addValue(new SettingsNodeValue("gridCustomized", m_configuration.gridCustomized));
    group->addValue(new SettingsNodeValue("genValuesInPourcent", m_configuration.genValuesInPourcent));
    group->addValue(new SettingsNodeValue("minGen", m_configuration.minGen));
    group->addValue(new SettingsNodeValue("maxGen", m_configuration.maxGen));
    group->addValue(new SettingsNodeValue("stepGen", m_configuration.stepGen));
    group->addValue(new SettingsNodeValue("terminalCustomized", m_configuration.terminalCustomized));
    group->addValue(new SettingsNodeValue("abscisseOrdonneeValuesInPourcent", m_configuration.abscisseOrdonneeValuesInPourcent));
    group->addValue(new SettingsNodeValue("minAbscisse", m_configuration.minAbscisse));
    group->addValue(new SettingsNodeValue("maxAbscisse", m_configuration.maxAbscisse));
    group->addValue(new SettingsNodeValue("minOrdonnee", m_configuration.minOrdonnee));
    group->addValue(new SettingsNodeValue("maxOrdonnee", m_configuration.maxOrdonnee));

    return root;
}

bool LVOX3_StepComputeProfiles::setAllSettings(const SettingsNodeGroup *settings)
{
    if(!CT_AbstractStep::setAllSettings(settings))
        return false;

    SettingsNodeGroup* group = settings->firstGroupByTagName("LVOX3_StepComputeProfiles");

    if(group == NULL)
        return false;

    SettingsNodeValue* value;

    READSETTINGS("minValue", m_configuration.minValue, toDouble());
    READSETTINGS("maxValue", m_configuration.maxValue, toDouble());
    READSETTINGS("ordonneeAxis", m_configuration.ordonneeAxis, toString());
    READSETTINGS("genAxis", m_configuration.genAxis, toString());
    READSETTINGS("unitType", m_configuration.unitType, toString());
    READSETTINGS("gridCustomized", m_configuration.gridCustomized, toBool());
    READSETTINGS("genValuesInPourcent", m_configuration.genValuesInPourcent, toBool());
    READSETTINGS("minGen", m_configuration.minGen, toDouble());
    READSETTINGS("maxGen", m_configuration.maxGen, toDouble());
    READSETTINGS("stepGen", m_configuration.stepGen, toInt());
    READSETTINGS("terminalCustomized", m_configuration.terminalCustomized, toBool());
    READSETTINGS("abscisseOrdonneeValuesInPourcent", m_configuration.abscisseOrdonneeValuesInPourcent, toBool());
    READSETTINGS("minAbscisse", m_configuration.minAbscisse, toDouble());
    READSETTINGS("maxAbscisse", m_configuration.maxAbscisse, toDouble());
    READSETTINGS("minOrdonnee", m_configuration.minOrdonnee, toDouble());
    READSETTINGS("maxOrdonnee", m_configuration.maxOrdonnee, toDouble());

    return true;
}

void LVOX3_StepComputeProfiles::createInResultModelListProtected()
{
    // We must have
    // - at least one grid

    CT_InResultModelGroupToCopy *resultModel = createNewInResultModelForCopy(DEF_SearchInResult, tr("Grilles"));

    resultModel->setZeroOrMoreRootGroup();
    resultModel->addGroupModel("", DEF_SearchInGroup);
    resultModel->addItemModel(DEF_SearchInGroup, DEF_SearchInGrid, CT_AbstractGrid3D::staticGetType(), tr("Grille 3D"));
}

bool LVOX3_StepComputeProfiles::postConfigure()
{
    ComputeProfilesConfiguration config;
    config.setConfiguration(m_configuration);
    if(CT_ConfigurableWidgetToDialog::exec(&config) == QDialog::Accepted) {

        m_configuration = config.getConfiguration();
        setSettingsModified(true);

        return true;
    }

    return false;
}

void LVOX3_StepComputeProfiles::createOutResultModelListProtected()
{
    // create a new OUT result that is a copy of the IN result selected by the user
    CT_OutResultModelGroupToCopyPossibilities *resultModel = createNewOutResultModelToCopy(DEF_SearchInResult);

    if (resultModel != NULL) {

        resultModel->addGroupModel(DEF_SearchInGroup, m_outGroupModelName);
        //Profile
        resultModel->addItemModel(m_outGroupModelName, m_outProfileModelName, new CT_Profile<double>(), tr("Profil"));
        //Profile Grid
        resultModel->addItemModel(m_outGroupModelName,
                          m_outGrid3DModelName,
                          new lvox::Grid3Df(),
                          tr("Profile Grid"));
    }
}

void LVOX3_StepComputeProfiles::compute()
{
    CT_ResultGroup* outResult = getOutResultList().first();

    Vector3SizeT indexGenAbscisseOrdonnee;

    Eigen::Vector3i axeOrdonnee(1, 0, 0);
    Eigen::Vector3i axeAbscisse(1, 0, 0);
    Eigen::Vector3i axeGen(1, 0, 0);

    if(m_configuration.ordonneeAxis.toLower() == "y")
        axeOrdonnee = Eigen::Vector3i(0, 1, 0);
    else if(m_configuration.ordonneeAxis.toLower() == "z")
        axeOrdonnee = Eigen::Vector3i(0, 0, 1);

    if(m_configuration.genAxis.toLower() == "y")
        axeGen = Eigen::Vector3i(0, 1, 0);
    else if(m_configuration.genAxis.toLower() == "z")
        axeGen = Eigen::Vector3i(0, 0, 1);

    axeAbscisse = axeOrdonnee.cross(axeGen).array().abs();

    Eigen::Array3i colLinLevelIndex(0, 0, 0);
    colLinLevelIndex = colLinLevelIndex + (axeOrdonnee.cast<int>().array() * 2);
    colLinLevelIndex = colLinLevelIndex + (axeAbscisse.cast<int>().array() * 1);



    CT_ResultGroupIterator itGrp(outResult, this, DEF_SearchInGroup);

    while (itGrp.hasNext() && !isStopped())
    {
        CT_StandardItemGroup *group = dynamic_cast<CT_StandardItemGroup*>((CT_AbstractItemGroup*)itGrp.next());
        const CT_AbstractGrid3D* inGrid = (const CT_AbstractGrid3D*) group->firstItemByINModelName(this, DEF_SearchInGrid);


        QList<double> axisMinMax;


        if (inGrid != NULL)
        {
            if((inGrid->xdim() > 0)
                    && (inGrid->ydim() > 0)
                    && (inGrid->zdim() > 0)
                    && (inGrid->resolution() > 0)) {

                //Declaring output grid to be able to export personalized grid of profile
                lvox::Grid3Df *profileGrid = new lvox::Grid3Df(m_outGrid3DModelName.completeName(), outResult, inGrid->minX(), inGrid->minY(), inGrid->minZ(), inGrid->xdim(), inGrid->ydim(), inGrid->zdim(), inGrid->resolution(), lvox::Max_Error_Code, 0);

                //Declaration of generation axii
                Vector3SizeT startEndStepGen(0, 0, 1);
                Vector3SizeT startEndStepOrdonnee(0, 0, 1);
                Vector3SizeT startEndStepAbscisse(0, 0, 1);

                Vector3SizeT gridDim(inGrid->xdim(), inGrid->ydim(), inGrid->zdim());

                size_t genDim = gridDim.dot(axeGen.cast<size_t>());
                size_t ordonneeDim = gridDim.dot(axeOrdonnee.cast<size_t>());
                size_t abscisseDim = gridDim.dot(axeAbscisse.cast<size_t>());

                size_t* col = NULL;
                size_t* lin = NULL;
                size_t* level = NULL;

                bool ok;
                double NAValue = inGrid->NAAsString().toDouble(&ok);

                if (!ok)
                    NAValue = -std::numeric_limits<double>::max();

                col = &indexGenAbscisseOrdonnee(colLinLevelIndex(0));
                lin = &indexGenAbscisseOrdonnee(colLinLevelIndex(1));
                level = &indexGenAbscisseOrdonnee(colLinLevelIndex(2));

                //Transforms the values in meters into voxels if grid personnalized (TOSELF: There's so much repetition it actually hurts my brain, will need to fix that, if possible)
                if(m_configuration.gridCustomized){
                    if(m_configuration.unitType.toLower() == "coordonnées"){
                        axisMinMax = changeToVoxel(inGrid);
                        //If both gen and abs/ord aren't in percentages
                        if(!m_configuration.abscisseOrdonneeValuesInPourcent && !m_configuration.genValuesInPourcent){
                            setStartEnd(axisMinMax.at(0), axisMinMax.at(1), startEndStepOrdonnee, ordonneeDim, m_configuration.abscisseOrdonneeValuesInPourcent);
                            setStartEnd(axisMinMax.at(2), axisMinMax.at(3), startEndStepAbscisse, abscisseDim, m_configuration.abscisseOrdonneeValuesInPourcent);
                            setStartEnd(axisMinMax.at(4),axisMinMax.at(5), startEndStepGen, genDim, m_configuration.genValuesInPourcent);
                            setStep(axisMinMax.at(6), startEndStepGen, m_configuration.genValuesInPourcent);

                        }else if(!m_configuration.abscisseOrdonneeValuesInPourcent){
                            setStartEnd(axisMinMax.at(0),axisMinMax.at(1), startEndStepOrdonnee, ordonneeDim, m_configuration.abscisseOrdonneeValuesInPourcent);
                            setStartEnd(axisMinMax.at(2), axisMinMax.at(3), startEndStepAbscisse, abscisseDim, m_configuration.abscisseOrdonneeValuesInPourcent);
                            setStartEnd(m_configuration.minGen, m_configuration.maxGen, startEndStepGen, genDim, m_configuration.genValuesInPourcent);
                            setStep(m_configuration.stepGen, startEndStepGen, m_configuration.genValuesInPourcent);

                        }else if(!m_configuration.genValuesInPourcent){
                            setStartEnd(m_configuration.minOrdonnee, m_configuration.maxOrdonnee, startEndStepOrdonnee, ordonneeDim, m_configuration.abscisseOrdonneeValuesInPourcent);
                            setStartEnd(m_configuration.minAbscisse, m_configuration.maxAbscisse, startEndStepAbscisse, abscisseDim, m_configuration.abscisseOrdonneeValuesInPourcent);
                            setStartEnd(axisMinMax.at(0), axisMinMax.at(1), startEndStepGen, genDim, m_configuration.genValuesInPourcent);
                            setStep(axisMinMax.at(2), startEndStepGen, m_configuration.genValuesInPourcent);
                        }
                    }else if(m_configuration.unitType.toLower() == "voxel" || (m_configuration.abscisseOrdonneeValuesInPourcent && m_configuration.genValuesInPourcent)){
                        //if voxels is chosen or both are percentages, goes straight to startEndStep
                        setStartEnd(m_configuration.minOrdonnee, m_configuration.maxOrdonnee, startEndStepOrdonnee, ordonneeDim, m_configuration.abscisseOrdonneeValuesInPourcent);
                        setStartEnd(m_configuration.minAbscisse, m_configuration.maxAbscisse, startEndStepAbscisse, abscisseDim, m_configuration.abscisseOrdonneeValuesInPourcent);
                        setStartEnd(m_configuration.minGen, m_configuration.maxGen, startEndStepGen, genDim, m_configuration.genValuesInPourcent);
                        setStep(m_configuration.stepGen, startEndStepGen, m_configuration.genValuesInPourcent);
                    }
                }else{ //FIXME : hardcoded for full grid because of new way to put coordinates in, which makes it not work properly (minus values)
                    setStartEnd(0, 999999, startEndStepOrdonnee, ordonneeDim, m_configuration.abscisseOrdonneeValuesInPourcent);
                    setStartEnd(0, 999999, startEndStepAbscisse, abscisseDim, m_configuration.abscisseOrdonneeValuesInPourcent);
                    setStartEnd(0, 999999, startEndStepGen, genDim, m_configuration.genValuesInPourcent);
                    setStep(999999, startEndStepGen, m_configuration.genValuesInPourcent);
                }


                CT_Profile<double>* outProfile;

                for (size_t currentProfileIndex = startEndStepGen(0); currentProfileIndex < startEndStepGen(1); currentProfileIndex += startEndStepGen(2))
                {
                    outProfile = createProfile(outResult, inGrid, currentProfileIndex, axeGen, axeOrdonnee, NAValue);

                    size_t begin = currentProfileIndex;
                    size_t end = qMin(startEndStepGen(1), begin + startEndStepGen(2));

                    for(indexGenAbscisseOrdonnee(0) = begin; indexGenAbscisseOrdonnee(0) < end; indexGenAbscisseOrdonnee(0) += 1)
                    {
                        for (indexGenAbscisseOrdonnee(1) = startEndStepAbscisse(0);  indexGenAbscisseOrdonnee(1) < startEndStepAbscisse(1); indexGenAbscisseOrdonnee(1) += startEndStepAbscisse(2))
                        {
                            for (indexGenAbscisseOrdonnee(2) = startEndStepOrdonnee(0); indexGenAbscisseOrdonnee(2) < startEndStepOrdonnee(1); indexGenAbscisseOrdonnee(2) += startEndStepOrdonnee(2))
                            {
                                size_t index;
                                inGrid->index(*col, *lin, *level, index);
                                double value = inGrid->valueAtIndexAsDouble(index);

                                if (value > m_configuration.minValue && value < m_configuration.maxValue){
                                    profileGrid->addValueAtIndex(index,value);
                                    //if the value is below 0, it counts the number of them per level, instead of normal behaviour.
                                    if(value >= 0){
                                        outProfile->addValueAtIndex(indexGenAbscisseOrdonnee(2), value);
                                    }else{
                                        outProfile->addValueAtIndex(indexGenAbscisseOrdonnee(2), 1);
                                    }
                                }
                            }
                        }
                    }
                    addProfile(outProfile, outResult, group,profileGrid);
                }
            }
        }
    }
}

//Creates the density profile of the inGrid + personnalized information
CT_Profile<double>* LVOX3_StepComputeProfiles::createProfile(CT_ResultGroup* outResult,
                                                             const CT_AbstractGrid3D* grid,
                                                             const size_t& currentIndex,
                                                             const Eigen::Vector3i& axeNormal,
                                                             const Eigen::Vector3i& axeOrdonnee,
                                                             double NAValue) const
{
    Eigen::Array3d gridMin(grid->minX(), grid->minY(), grid->minZ());
    Eigen::Array3d finalMin = gridMin + (axeNormal.cast<double>().array()*(((double)currentIndex)*grid->resolution()));

    size_t profileSize = Vector3SizeT(grid->xdim(), grid->ydim(), grid->zdim()).dot(axeOrdonnee.cast<size_t>());

    // TODO : add an orientation vector to the class CT_Profile !
    return new CT_Profile<double>(m_outProfileModelName.completeName(),
                                  outResult,
                                  finalMin.x(),
                                  finalMin.y(),
                                  finalMin.z(),
                                  axeOrdonnee.x(),
                                  axeOrdonnee.y(),
                                  axeOrdonnee.z(),
                                  profileSize,
                                  grid->resolution(),
                                  NAValue,
                                  0.0);
}

//Adds the profile and the profile grid to the view
void LVOX3_StepComputeProfiles::addProfile(CT_Profile<double> *profile, CT_ResultGroup* outResult, CT_StandardItemGroup *group, lvox::Grid3Df* grid)
{
    CT_StandardItemGroup* newGroup = new CT_StandardItemGroup(m_outGroupModelName.completeName(),
                                                              outResult);


    profile->computeMinMax();
    grid->computeMinMax();

    group->addGroup(newGroup);
    newGroup->addItemDrawable(profile);
    newGroup->addItemDrawable(grid);

}

void LVOX3_StepComputeProfiles::setStartEnd(size_t min, size_t max, LVOX3_StepComputeProfiles::Vector3SizeT &startEndStep, const size_t &dim, bool minAndMaxInPourcent)
{
    if(minAndMaxInPourcent) {
        min = (dim*min)/100;
        max = (dim*max)/100;
    }

    startEndStep(0) = qMin(dim-1, min);
    startEndStep(1) = qMax(startEndStep(0), qMin(dim, max));
}

void LVOX3_StepComputeProfiles::setStep(size_t step, LVOX3_StepComputeProfiles::Vector3SizeT &startEndStep, bool stepInPourcent)
{
    size_t dim = startEndStep(1)-startEndStep(0);

    if(stepInPourcent) {
        step = (dim*step)/100;
    }

    startEndStep(2) = qMax((size_t)1, qMin(startEndStep(1)-startEndStep(0), step));
}

//Changes the user entered values for axis limits from coordinates to voxels (to remove user calculation)
QList<double> LVOX3_StepComputeProfiles::changeToVoxel(const CT_AbstractGrid3D* inGrid){
    QList<double> axisMinMax;
    QList<double> coordinates;
    int voxelGridLowerX;
    int voxelGridLowerY;
    int voxelGridLowerZ;

    //Have to round because it does floor or ceiling in the function setStartEnd, which plays with data accuracy
    voxelGridLowerX = round(std::fabs(inGrid->minX()));
    voxelGridLowerY = round(std::fabs(inGrid->minY()));
    voxelGridLowerZ = round(std::fabs(inGrid->minZ()));

    //Ordonnee axis meter distance from grid lower left point calculation (MIN and MAX are declared at the top of this file)
    if(m_configuration.ordonneeAxis.toLower() == "x"){
        coordinates.append(MINProfile(m_configuration.minOrdonnee,inGrid->minX()) + voxelGridLowerX);
        coordinates.append(MAXProfile(m_configuration.maxOrdonnee,inGrid->maxX()) + voxelGridLowerX);
    }else if(m_configuration.ordonneeAxis.toLower() == "y"){
        coordinates.append(MINProfile(m_configuration.minOrdonnee,inGrid->minY()) + voxelGridLowerY);
        coordinates.append(MAXProfile(m_configuration.maxOrdonnee,inGrid->maxY()) + voxelGridLowerY);
    }else if(m_configuration.ordonneeAxis.toLower() == "z"){
        coordinates.append(MINProfile(m_configuration.minOrdonnee,inGrid->minZ()) + voxelGridLowerZ);
        coordinates.append(MAXProfile(m_configuration.maxOrdonnee,inGrid->maxZ()) + voxelGridLowerZ);
    }

    //Abscisse axis meter distance from grid lower left point calculation
    if((m_configuration.ordonneeAxis.toLower() == "x" && m_configuration.genAxis.toLower()=="y")||(m_configuration.ordonneeAxis.toLower() == "y" && m_configuration.genAxis.toLower()=="x")){
        coordinates.append(MINProfile(m_configuration.minAbscisse,inGrid->minZ()) + voxelGridLowerZ);
        coordinates.append(MAXProfile(m_configuration.maxAbscisse,inGrid->maxZ()) + voxelGridLowerZ);
    }else if(m_configuration.ordonneeAxis.toLower() == "z" && m_configuration.genAxis.toLower()=="x"){
        coordinates.append(MINProfile(m_configuration.minAbscisse,inGrid->minY()) + voxelGridLowerY);
        coordinates.append(MAXProfile(m_configuration.maxAbscisse,inGrid->maxY()) + voxelGridLowerY);
    }else if(m_configuration.ordonneeAxis.toLower() == "z" && m_configuration.genAxis.toLower()=="y"){
        coordinates.append(MINProfile(m_configuration.minAbscisse,inGrid->minX()) + voxelGridLowerX);
        coordinates.append(MAXProfile(m_configuration.maxAbscisse,inGrid->maxX()) + voxelGridLowerX);
    }

    //Gen axis meter distance from grid lower left point calculation
    if(m_configuration.genAxis.toLower()=="x"){
        coordinates.append(MINProfile(m_configuration.minGen,inGrid->minX()) + voxelGridLowerX);
        coordinates.append(MAXProfile(m_configuration.maxGen,inGrid->maxX()) + voxelGridLowerX);
    }else if(m_configuration.genAxis.toLower()=="y"){
        coordinates.append(MINProfile(m_configuration.minGen,inGrid->minY()) + voxelGridLowerY);
        coordinates.append(MAXProfile(m_configuration.maxGen,inGrid->maxY()) + voxelGridLowerY);
    }

    //If the grid calculations are not based on percentages
    if(!m_configuration.abscisseOrdonneeValuesInPourcent && !m_configuration.genValuesInPourcent){
        axisMinMax.append(coordinates.at(0)/inGrid->resolution());
        axisMinMax.append(coordinates.at(1)/inGrid->resolution());
        axisMinMax.append(coordinates.at(2)/inGrid->resolution());
        axisMinMax.append(coordinates.at(3)/inGrid->resolution());
        axisMinMax.append(coordinates.at(4)/inGrid->resolution());
        axisMinMax.append(coordinates.at(5)/inGrid->resolution());
        axisMinMax.append(m_configuration.stepGen/inGrid->resolution());
    }else if(!m_configuration.abscisseOrdonneeValuesInPourcent){
        axisMinMax.append(coordinates.at(0)/inGrid->resolution());
        axisMinMax.append(coordinates.at(1)/inGrid->resolution());
        axisMinMax.append(coordinates.at(2)/inGrid->resolution());
        axisMinMax.append(coordinates.at(3)/inGrid->resolution());
    }else if(!m_configuration.genValuesInPourcent){
        axisMinMax.append(coordinates.at(4)/inGrid->resolution());
        axisMinMax.append(coordinates.at(5)/inGrid->resolution());
        axisMinMax.append(m_configuration.stepGen/inGrid->resolution()); //Step Gen is in meters when coordinates is taken
    }

    return axisMinMax;
}
