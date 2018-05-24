//+test lib
#include <QDebug>
//-test lib

#include "lvox3_stepcomputelvoxgrids.h"

#include "ct_result/model/inModel/ct_inresultmodelgrouptocopy.h"
#include "ct_result/model/outModel/tools/ct_outresultmodelgrouptocopypossibilities.h"

#include "ct_result/ct_resultgroup.h"

#include "ct_itemdrawable/ct_scene.h"
#include "ct_itemdrawable/ct_scanner.h"
#include "ct_itemdrawable/ct_shootingpatternd.h"
#include "ct_itemdrawable/ct_grid3d.h"
#include "ct_itemdrawable/abstract/ct_abstractimage2d.h"

#include "ct_view/ct_stepconfigurabledialog.h"
#include "ct_view/ct_buttongroup.h"

#include "mk/tools/worker/lvox3_filtervoxelsbyzvaluesofraster.h"
#include "mk/tools/worker/lvox3_computehits.h"
#include "mk/tools/worker/lvox3_computebefore.h"
#include "mk/tools/worker/lvox3_computetheoriticals.h"
#include "mk/tools/worker/lvox3_computeall.h"
#include "mk/tools/lvox3_computelvoxgridspreparator.h"
#include "mk/tools/lvox3_gridtype.h"
#include "mk/tools/lvox3_errorcode.h"

#define DEF_SearchInResult      "r"
#define DEF_SearchInGroup       "gr"
#define DEF_SearchInScene       "sc"
#define DEF_SearchInScan        "sca"
#define DEF_SearchInShotPattern "pat"
#define DEF_SearchInMNT         "mnt"
#define DEF_SearchInSky         "sky"

/**
 * @brief Compute the LVOX Ni, Nb, Nt grids
 */
LVOX3_StepComputeLvoxGrids::LVOX3_StepComputeLvoxGrids(CT_StepInitializeData &dataInit) : CT_AbstractStep(dataInit)
{
    m_resolution = 0.5;
    m_computeDistances = false;
    m_gridMode = lvox::BoundingBoxOfTheScene;
    m_coordinates.x() = -20.0;
    m_coordinates.y() = -20.0;
    m_coordinates.z() = -10.0;
    m_scannerRange = 0;

    m_dimensions.x() = 80;
    m_dimensions.y() = 80;
    m_dimensions.z() = 80;
}

/**
 * @brief Return a short description of what this class does
 */
QString LVOX3_StepComputeLvoxGrids::getStepDescription() const
{
    return tr("2 - Calculer les grilles LVOX (LVOX 3)");
}

/*! \brief Step detailed description
 *
 * Return a detailed description of the step function
 */
QString LVOX3_StepComputeLvoxGrids::getStepDetailledDescription() const
{
    return tr("Cette étape permet de créer une grille 3D pour les bons tirs, les tirs théoriques et les tirs interceptés à partir d'un taille de voxel défini.");
}

/**
 * @brief Return a new empty instance of this class
 */
CT_VirtualAbstractStep* LVOX3_StepComputeLvoxGrids::createNewInstance(CT_StepInitializeData &dataInit)
{
    // Creates an instance of this step
    return new LVOX3_StepComputeLvoxGrids(dataInit);
}

/**
 * @brief This method defines what kind of input the step can accept
 */
void LVOX3_StepComputeLvoxGrids::createInResultModelListProtected()
{
    // We must have
    // - a scene
    // - a scanner OR a shooting pattern to simulate shots (at least one is obligatory)
    // - an MNT (optionnal)

    CT_InResultModelGroupToCopy *resultScan = createNewInResultModelForCopy(DEF_SearchInResult, tr("Scène"), "", true);
    resultScan->setZeroOrMoreRootGroup();
    resultScan->addGroupModel("", DEF_SearchInGroup, CT_AbstractItemGroup::staticGetType(), tr("Scan"));
    resultScan->addItemModel(DEF_SearchInGroup, DEF_SearchInScene, CT_Scene::staticGetType(), tr("Scène"));

    // TODO : in ComputreeV5 set the scanner and the pattern in an exclusive group
    resultScan->addItemModel(DEF_SearchInGroup, DEF_SearchInScan, CT_Scanner::staticGetType(), tr("Scanner"), tr("The scanner is used to simulate the shooting pattern. If it was not present choose at least a shooting pattern !"), CT_InAbstractModel::C_ChooseOneIfMultiple, CT_InAbstractModel::F_IsOptional);
    resultScan->addItemModel(DEF_SearchInGroup, DEF_SearchInShotPattern, CT_ShootingPatternD::staticGetType(), tr("Shooting pattern"), tr("The shooting pattern is used to simulate it. If it was not present choose at least a scanner !"), CT_InAbstractModel::C_ChooseOneIfMultiple, CT_InAbstractModel::F_IsOptional);

    resultScan->addItemModel(DEF_SearchInGroup, DEF_SearchInMNT, CT_AbstractImage2D::staticGetType(), tr("MNT"), "", CT_InAbstractModel::C_ChooseOneIfMultiple, CT_InAbstractModel::F_IsOptional);
    resultScan->addItemModel(DEF_SearchInGroup, DEF_SearchInSky, CT_AbstractImage2D::staticGetType(), tr("MNC"), "", CT_InAbstractModel::C_ChooseOneIfMultiple, CT_InAbstractModel::F_IsOptional);
}

/**
 * @brief This method creates a window for the user to set the different parameters of the step.
 */
void LVOX3_StepComputeLvoxGrids::createPostConfigurationDialog()
{
    CT_StepConfigurableDialog *configDialog = newStandardPostConfigurationDialog();

    //********************************************//
    //              Attributes of LVox            //
    //********************************************//
    configDialog->addDouble(tr("Resolution of the grids"),tr("meters"),0.0001,10000,2, m_resolution );
    configDialog->addBool("", "", tr("Compute Distances"), m_computeDistances);

    //Defines the grid params
    configDialog->addText(tr("Reference for (minX, minY, minZ) corner of the grid :"),"", "");

    CT_ButtonGroup &bg_gridMode = configDialog->addButtonGroup(m_gridMode);
    configDialog->addExcludeValue("", "", tr("Default mode : Bounding box of the scene"), bg_gridMode, 0);
    configDialog->addExcludeValue("", "", tr("Custom mode : Relative to folowing coordinates:"), bg_gridMode, 1);
    configDialog->addExcludeValue("", "", tr("Custom mode : Relative to folowing coordinates + custom dimensions:"), bg_gridMode, 2);
    configDialog->addExcludeValue("", "", tr("Custom mode : centered on folowing coordinates + custom dimensions:"), bg_gridMode, 3,"Cette option est différente des trois autres: \nles coordonnées X,Y,Z sont le point centre de la grille\nla dimension est la dimension totale divisée également à partir du point central.");

#ifdef CT_LARCHIHEADER_H
    configDialog->addExcludeValue("", "", tr("Automatic mode : use grid paramters from grid file"), bg_gridMode, 4);
    configDialog->addFileChoice(tr("Choisir le fichier .grid"), CT_FileChoiceButton::OneExistingFile, "Fichier L-Architect (*.grid)", m_gridFilePath);
#endif

    float maxFloat = std::numeric_limits<float>::max();
    float minFloat = -maxFloat;

    configDialog->addText(tr("Parameter for default mode:"),"", "");
    configDialog->addInt(tr("Scanner range:"), "", 0, 1000, m_scannerRange,"Cette option défini la portée du scanneur(rayon du cercle). Si la valeur est 0, elle n'est pas prise en compte.");

    configDialog->addText(tr("Parameters for custom modes:"),"", "");
    configDialog->addDouble(tr("X coordinate:"), "", minFloat, maxFloat, 4, m_coordinates.x());
    configDialog->addDouble(tr("Y coordinate:"), "", minFloat, maxFloat, 4, m_coordinates.y());
    configDialog->addDouble(tr("Z coordinate:"), "", minFloat, maxFloat, 4, m_coordinates.z());

    configDialog->addInt(tr("X dimension:"), "", 1, 1000, m_dimensions.x());
    configDialog->addInt(tr("Y dimension:"), "", 1, 1000, m_dimensions.y());
    configDialog->addInt(tr("Z dimension:"), "", 1, 1000, m_dimensions.z());
    configDialog->addEmpty();
    configDialog->addText(tr("<b>Attention: une résolution de 1 cm pour une zone de 10m^3 prend au moins 12GB de mémoire. Un manque d'espace causera un arrêt forcé de CompuTree.</b>"),"", "");
}

/**
 * @brief This method defines what kind of output the step produces
 */
void LVOX3_StepComputeLvoxGrids::createOutResultModelListProtected()
{
    // create a new OUT result that is a copy of the IN result selected by the user
    CT_OutResultModelGroupToCopyPossibilities *res = createNewOutResultModelToCopy(DEF_SearchInResult);

    if (res != NULL)
    {
        // Add all grids : Ni, Nt,Nb
        res->addItemModel(DEF_SearchInGroup, _hits_ModelName, new lvox::Grid3Di(), tr("Hits"));
        res->addItemAttributeModel(_hits_ModelName, _NiFlag_ModelName, new CT_StdItemAttributeT<bool>("LVOX_GRD_NI"), tr("isNi"));

        res->addItemModel(DEF_SearchInGroup, _theo_ModelName, new lvox::Grid3Di(), tr("Theoretical"));
        res->addItemAttributeModel(_theo_ModelName, _NtFlag_ModelName, new CT_StdItemAttributeT<bool>("LVOX_GRD_NT"), tr("isNt"));

        res->addItemModel(DEF_SearchInGroup, _bef_ModelName, new lvox::Grid3Di(), tr("Before"));
        res->addItemAttributeModel(_bef_ModelName, _NbFlag_ModelName, new CT_StdItemAttributeT<bool>("LVOX_GRD_NB"), tr("isNb"));
        // and if must compute distance, grids with distance
        if (m_computeDistances)
        {
            res->addItemModel(DEF_SearchInGroup, _deltain_ModelName, new lvox::Grid3Df(), tr("DeltaIn"));
            res->addItemModel(DEF_SearchInGroup, _deltaout_ModelName, new lvox::Grid3Df(), tr("DeltaOut"));
            res->addItemModel(DEF_SearchInGroup, _deltatheo_ModelName, new lvox::Grid3Df(), tr("Deltatheoretical"));
            res->addItemModel(DEF_SearchInGroup, _deltabef_ModelName, new lvox::Grid3Df(), tr("DeltaBefore"));
        }
    }
}

/**
 * @brief This method does the job
 * It creates three 3D grids from point cloud information and user defined voxel size (Hits, Theoritical Rays, Before Rays)
 */
void LVOX3_StepComputeLvoxGrids::compute()
{
    CT_ResultGroup* outResult = getOutResultList().first();

    CT_ResultGroupIterator itGrp(outResult, this, DEF_SearchInGroup);

    LVOX3_ComputeLVOXGridsPreparator::Coordinates coo;
    coo.coordinate = m_coordinates;
    coo.dimension = m_dimensions.cast<double>();

    LVOX3_ComputeLVOXGridsPreparator p;
    LVOX3_ComputeLVOXGridsPreparator::Result pRes = p.prepare(this,
                                                              itGrp,
                                                              DEF_SearchInScene,
                                                              DEF_SearchInScan,
                                                              DEF_SearchInShotPattern,
                                                              DEF_SearchInMNT,
                                                              DEF_SearchInSky,
                                                              m_resolution,
                                                              (lvox::GridMode)m_gridMode,
                                                              coo,
                                                              m_gridFilePath.isEmpty() ? "" : m_gridFilePath.first(),
                                                              m_scannerRange);

    //If the grid had it's dimension fitted according to config
    if(pRes.valid) {
        LVOX3_ComputeAll workersManager; //Worker manager (Thread and progress manager)
        LVOX3_ComputeLVOXGridsPreparator::Result::ToComputeCollectionIterator it(pRes.elementsToCompute);

        while (it.hasNext()
               && !isStopped())
        {
            it.next();
            CT_AbstractItemGroup* group = it.key();
            const LVOX3_ComputeLVOXGridsPreparator::ToCompute& tc = it.value();

            lvox::Grid3Di*   hitGrid = NULL;
            lvox::Grid3Di*   theoriticalGrid = NULL;
            lvox::Grid3Di*   beforeGrid = NULL;

            //Used to compute distances (when option is checked)
            lvox::Grid3Df*   deltaInGrid = NULL;
            lvox::Grid3Df*   deltaOutGrid = NULL;
            lvox::Grid3Df*   deltaTheoritical = NULL;
            lvox::Grid3Df*   deltaBefore = NULL;

            LVOX3_ComputeTheoriticals* theoriticalWorker = NULL;
            LVOX3_ComputeHits* hitsWorker = NULL;
            LVOX3_ComputeBefore* beforeWorker = NULL;

            //Used to pass to voxel filtering step more easily
            QList<CT_AbstractGrid3D*> allGrids;

            // Declaring the output grids
            hitGrid = lvox::Grid3Di::createGrid3DFromXYZCoords(_hits_ModelName.completeName(), outResult, pRes.minBBox.x(), pRes.minBBox.y(), pRes.minBBox.z(), pRes.maxBBox.x(), pRes.maxBBox.y(), pRes.maxBBox.z(), m_resolution, lvox::Max_Error_Code, 0, true);
            theoriticalGrid = new lvox::Grid3Di(_theo_ModelName.completeName(), outResult, hitGrid->minX(), hitGrid->minY(), hitGrid->minZ(), hitGrid->xdim(), hitGrid->ydim(), hitGrid->zdim(), m_resolution, lvox::Max_Error_Code, 0);
            beforeGrid = new lvox::Grid3Di(_bef_ModelName.completeName(), outResult, hitGrid->minX(), hitGrid->minY(), hitGrid->minZ(), hitGrid->xdim(), hitGrid->ydim(), hitGrid->zdim(), m_resolution, lvox::Max_Error_Code, 0);

            allGrids.append(hitGrid);
            allGrids.append(theoriticalGrid);
            allGrids.append(beforeGrid);

            hitGrid->addItemAttribute(new CT_StdItemAttributeT<bool>(_NiFlag_ModelName.completeName(), "LVOX_GRD_NI", outResult, true));
            theoriticalGrid->addItemAttribute(new CT_StdItemAttributeT<bool>(_NtFlag_ModelName.completeName(), "LVOX_GRD_NT", outResult, true));
            beforeGrid->addItemAttribute(new CT_StdItemAttributeT<bool>(_NbFlag_ModelName.completeName(), "LVOX_GRD_NB", outResult, true));

            group->addItemDrawable(hitGrid);
            group->addItemDrawable(theoriticalGrid);
            group->addItemDrawable(beforeGrid);
            // and if must compute distance, grids with distance
            if (m_computeDistances)
            {
                deltaInGrid = new lvox::Grid3Df(_deltain_ModelName.completeName(), outResult, hitGrid->minX(), hitGrid->minY(), hitGrid->minZ(), hitGrid->xdim(), hitGrid->ydim(), hitGrid->zdim(), m_resolution, -1, 0);
                deltaOutGrid = new lvox::Grid3Df(_deltaout_ModelName.completeName(), outResult, hitGrid->minX(), hitGrid->minY(), hitGrid->minZ(), hitGrid->xdim(), hitGrid->ydim(), hitGrid->zdim(), m_resolution, -1, 0);
                deltaTheoritical = new lvox::Grid3Df(_deltatheo_ModelName.completeName(), outResult, hitGrid->minX(), hitGrid->minY(), hitGrid->minZ(), hitGrid->xdim(), hitGrid->ydim(), hitGrid->zdim(), m_resolution, -1, 0);
                deltaBefore = new lvox::Grid3Df(_deltabef_ModelName.completeName(), outResult, hitGrid->minX(), hitGrid->minY(), hitGrid->minZ(), hitGrid->xdim(), hitGrid->ydim(), hitGrid->zdim(), m_resolution, -1, 0);

                group->addItemDrawable(deltaInGrid);
                group->addItemDrawable(deltaOutGrid);
                group->addItemDrawable(deltaTheoritical);
                group->addItemDrawable(deltaBefore);
            }
            hitsWorker = new LVOX3_ComputeHits(tc.pattern, tc.scene->getPointCloudIndex(), hitGrid, deltaInGrid, deltaOutGrid);
            theoriticalWorker = new LVOX3_ComputeTheoriticals(tc.pattern, theoriticalGrid, deltaTheoritical);
            beforeWorker = new LVOX3_ComputeBefore(tc.pattern, tc.scene->getPointCloudIndex(), beforeGrid, deltaBefore);
            workersManager.addWorker(1, hitsWorker);
            workersManager.addWorker(1, theoriticalWorker);
            workersManager.addWorker(1, beforeWorker);

            LVOX3_FilterVoxelsByZValuesOfRaster* filterVoxelsBelowMNTWorker = NULL;
            LVOX3_FilterVoxelsByZValuesOfRaster* filterVoxelsInSkyWorker = NULL;

            if(tc.mnt != NULL)
                filterVoxelsBelowMNTWorker = new LVOX3_FilterVoxelsByZValuesOfRaster(allGrids, tc.mnt, LVOX3_FilterVoxelsByZValuesOfRaster::Below, lvox::MNT);

            if(tc.sky != NULL)
                filterVoxelsInSkyWorker = new LVOX3_FilterVoxelsByZValuesOfRaster(allGrids, tc.sky, LVOX3_FilterVoxelsByZValuesOfRaster::Above, lvox::Sky);

            if(filterVoxelsBelowMNTWorker != NULL)
                workersManager.addWorker(0, filterVoxelsBelowMNTWorker);

            if(filterVoxelsInSkyWorker != NULL)
                workersManager.addWorker(0, filterVoxelsInSkyWorker);
        }

        //Connected to show progress of the workers
        connect(&workersManager, SIGNAL(progressChanged(int)), this, SLOT(progressChanged(int)), Qt::DirectConnection);
        connect(this, SIGNAL(stopped()), &workersManager, SLOT(cancel()), Qt::DirectConnection);

        workersManager.compute();
    }
}

/**
 * @brief Called from worker manager when progress changed
 */
void LVOX3_StepComputeLvoxGrids::progressChanged(int p)
{
    setProgress(p);
}

