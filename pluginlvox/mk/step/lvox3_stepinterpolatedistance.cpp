#include <memory>

#include "lvox3_stepinterpolatedistance.h"

#include "ct_result/model/inModel/ct_inresultmodelgrouptocopy.h"
#include "ct_result/model/outModel/tools/ct_outresultmodelgrouptocopypossibilities.h"
#include "ct_result/ct_resultgroup.h"
#include "ct_itemdrawable/ct_scene.h"
#include "ct_view/ct_stepconfigurabledialog.h"
#include "mk/tools/lvox3_gridtype.h"
#include "mk/tools/lvox3_gridtools.h"
#include "mk/tools/worker/lvox3_interpolatedistance.h"
#include "mk/tools/worker/lvox3_interpolatetrustfactor.h"
#include "mk/tools/lvox3_utils.h"

using namespace std;

LVOX3_StepInterpolateDistance::LVOX3_StepInterpolateDistance(CT_StepInitializeData &dataInit)
    : CT_AbstractStep(dataInit),
      m_interpolateRadius(1.0),
      m_interpolateDensityThreshold(0.0),
      m_interpolatePower(0),
      m_trustLowThreshold(10),
      m_trustHighThreshold(30)
{
    m_effectiveRayThresh = 10;
    m_interpolationMethod = tr("Distance");

    m_interpolationMethodCollection.insert(m_interpolationMethod, Distance);
    m_interpolationMethodCollection.insert(tr("Trust"), Trust);
    //Version from LVOX1, less accurate but faster
    m_interpolationMethodCollection.insert(tr("Z Axis Average"),ZAverage);

    // TODO : change compute method to enable do this !
    //m_interpolationMethodCollection.insert(tr("Distance and Trust"), DistanceAndTrust);
}

QString LVOX3_StepInterpolateDistance::getStepDescription() const
{
    return tr("5 - NODATA interpolation (LVOX 3)");
}

// Step detailed description
QString LVOX3_StepInterpolateDistance::getStepDetailledDescription() const
{
    return tr("Cette étape permet d'interpolation les valeurs NODATA et les codes d'erreurs(toutes valeurs négatives). Elle contient deux interpolations basées sur le voisinage (Distance et Trust) et une interpolation basée sur la moyenne des Z, plus rapide, mais moins précise.");
}

CT_VirtualAbstractStep*
LVOX3_StepInterpolateDistance::createNewInstance(CT_StepInitializeData &dataInit)
{
    // Creates an instance of this step
    return new LVOX3_StepInterpolateDistance(dataInit);
}

void LVOX3_StepInterpolateDistance::createInResultModelListProtected()
{
    /*
     * Requirements:
     *  - relative density 3D grid
     *  - theoretical rays 3D grid
     *  - blocked rays 3D grid
     */

    CT_InResultModelGroupToCopy *resultModel = createNewInResultModelForCopy(
            DEF_SearchInResult, tr("Grids"), "", true);
    resultModel->setZeroOrMoreRootGroup();

    /*
     * The main density grid
     */
    resultModel->addGroupModel("", DEF_SearchInGroup,
            CT_AbstractItemGroup::staticGetType(), tr("Group"));
    resultModel->addItemModel(DEF_SearchInGroup, DEF_SearchInGrid,
            lvox::Grid3Df::staticGetType(), tr("Density grid"));

    /*
     * The theoretical and before grid required for the trust interpolation.
     *
     * FIXME: the user must select the proper grids, otherwise the computation
     * will not be valid. Is there a way to specifically request a default
     * grid?
     *
     * ATM, the output grids are matched in order, and the default order (Nt,
     * Nb) is correct, but this is obviously flaky, the user may make a mistake easily.
     *
     * In lvox_stepcombinedentisygrids.cpp, an item attribute is requested with
     * addItemAttributeModel, but lvox3_stepgenericcomputegrids.cpp does not
     * add such attributes that would allow matching.
     *
     * FIX : No way to choose a default model. But warning ! you must not set it as optionnal because you can
     *       use it potentially in your compute. The consequence is that the user must always
     *       have it. No other solution for this. Otherwise we must create another step.
     */
    resultModel->addItemModel(DEF_SearchInGroup, DEF_Ni,
            lvox::Grid3Di::staticGetType(), tr("hits"));
    resultModel->addItemAttributeModel(DEF_Ni, "niFlagModelName",
                                       QList<QString>() << "LVOX_GRD_NI",
                                       CT_AbstractCategory::ANY, tr("isNi"));

    resultModel->addItemModel(DEF_SearchInGroup, DEF_Nt,
            lvox::Grid3Di::staticGetType(), tr("theoretical"));
    resultModel->addItemAttributeModel(DEF_Nt, "ntFlagModelName",
                                       QList<QString>() << "LVOX_GRD_NT",
                                       CT_AbstractCategory::ANY, tr("isNt"));

    resultModel->addItemModel(DEF_SearchInGroup, DEF_Nb,
            lvox::Grid3Di::staticGetType(), tr("before"));
    resultModel->addItemAttributeModel(DEF_Nb, "nbFlagModelName",
                                       QList<QString>() << "LVOX_GRD_NB",
                                       CT_AbstractCategory::ANY, tr("isNb"));
}

void LVOX3_StepInterpolateDistance::createPostConfigurationDialog()
{
    /*
     * FIXME:
     * - The settings for an algorithm are not disabled if the corresponding
     *   algorithm is not checked.
     * - The low/high range bound is not validated, meaning that the user can
     *   enter a lower bound greater than the higher bound.
     * - We should use a combobox instead of the checkbox for each algorithm.
     *   However, I haven't found a way to register a signal to it (not returned from the add)
     * - addWidget() is more generic, but is protected.
     *
     * FIX :
     * - Use addStringChoice() to add a combobox
     * - No way to enable/disable some widget if a specific action in the combox is choosed. The only way is
     *   to do a custom configuration dialog but it is heavier to implement.
     */
    CT_StepConfigurableDialog *configDialog = newStandardPostConfigurationDialog();

    configDialog->addStringChoice(tr("Interpolation type"), "", m_interpolationMethodCollection.keys(), m_interpolationMethod);
    configDialog->addEmpty();

    configDialog->addText(tr("Common parameters"));
    configDialog->addDouble(tr("Minimum density"), tr(""), 0.0, 1.0, 3,
            m_interpolateDensityThreshold, 0.0, tr("Minimum neighbor value to consider the voxel in the average"));
    configDialog->addDouble(tr("Interpolation radius"), tr("meter"), 0.0, 10000.0, 3, m_interpolateRadius); 

    configDialog->addEmpty();
    configDialog->addText(tr("Parameter for distance interpolation"));
    configDialog->addInt(tr("Decay power"), tr(""), 0, 100, m_interpolatePower);

    configDialog->addEmpty();

    configDialog->addText(tr("Parameters for trust interpolation"));
    configDialog->addInt(tr("Lower bound"), tr("effective rays (Nt - Nb)"), 0, 1000, m_trustLowThreshold, tr("Voxel with lower effective rays are not trusted"));
    configDialog->addInt(tr("Higher bound"), tr("effective rays (Nt - Nb)"), 0, 1000, m_trustHighThreshold, tr("Voxel with higher effective rays are fully trusted"));

    configDialog->addEmpty();
    configDialog->addText(tr("Parameter for Z axis average interpolation"));
    configDialog->addInt(tr("effective rays (Nt - Nb) Threshold"),"",0,1000, m_effectiveRayThresh,tr("Voxel with lower effective rays are considered as having a density of 0"));
}

void LVOX3_StepInterpolateDistance::createOutResultModelListProtected()
{
    // create a new OUT result that is a copy of the IN result selected by the user
    CT_OutResultModelGroupToCopyPossibilities *resultModel =
            createNewOutResultModelToCopy(DEF_SearchInResult);

    /*
     * addItemModel() declares the outputs, the object lvox::Grid3Df is only a
     * stub and is not actually used.
     *
     * FIXME: depending on the interpolation algorithm selected by the user,
     * only one grid will be produced and the output name should be different.
     *
     * FIX : just use one and choose a name that can be used for all selected algorithm....
     */
    if(resultModel != NULL) {

        resultModel->addItemModel(DEF_SearchInGroup,
                m_outInterpolatedGridModelName,
                new lvox::Grid3Df(),
                tr("Density - interpolated"));
    }
}

void LVOX3_StepInterpolateDistance::compute()
{
    CT_ResultGroup* outResult = getOutResultList().first();

    CT_ResultGroupIterator itGrp(outResult, this, DEF_SearchInGroup);

    while(itGrp.hasNext() && !isStopped()) {
        /*
         * Two casts are required, the group iterator returns const objects and
         * because addItemDrawable() is called, it has to be non const.
         */
        CT_StandardItemGroup *group = dynamic_cast<CT_StandardItemGroup*>((CT_AbstractItemGroup*)itGrp.next());

        lvox::Grid3Df *grid_density = dynamic_cast<lvox::Grid3Df*>(group->firstItemByINModelName(this, DEF_SearchInGrid));
        lvox::Grid3Di *grid_ni = dynamic_cast<lvox::Grid3Di*>(group->firstItemByINModelName(this, DEF_Ni));
        lvox::Grid3Di *grid_nt = dynamic_cast<lvox::Grid3Di*>(group->firstItemByINModelName(this, DEF_Nt));
        lvox::Grid3Di *grid_nb = dynamic_cast<lvox::Grid3Di*>(group->firstItemByINModelName(this, DEF_Nb));

        if(!(grid_density && grid_nt && grid_nb))
            continue;

        LVOX3_Worker *worker = NULL;
        lvox::Grid3Df *out = NULL;

        if (m_interpolationMethodCollection.value(m_interpolationMethod) == Distance) {
            out = (lvox::Grid3Df*) grid_density->copy(
                    m_outInterpolatedGridModelName.completeName(),
                    outResult, CT_ResultCopyModeList());
            worker = new LVOX3_InterpolateDistance(
                    grid_density, out, m_interpolateRadius,
                    m_interpolatePower, m_interpolateDensityThreshold);
        }else if(m_interpolationMethodCollection.value(m_interpolationMethod) == Trust) {
            out = (lvox::Grid3Df*) grid_density->copy(
                    m_outInterpolatedGridModelName.completeName(),
                    outResult, CT_ResultCopyModeList());
            worker = new LVOX3_InterpolateTrustFactor(
                    grid_density, grid_nt, grid_nb, out, m_interpolateRadius,
                    m_trustLowThreshold, m_trustHighThreshold);
        }else if(m_interpolationMethodCollection.value(m_interpolationMethod) == ZAverage){
            out = (lvox::Grid3Df*) grid_density->copy(
                    m_outInterpolatedGridModelName.completeName(),
                    outResult, CT_ResultCopyModeList());
            ZAverageInterpolation(grid_density,out,grid_ni,grid_nt,grid_nb);
            //TODO: Encapsulate ZAverage in a class to be able to add a worker to it and make it standard with other methods
            out->computeMinMax();
            group->addItemDrawable(out);
        }

        if(worker != NULL) {

            connect(worker, SIGNAL(progressChanged(int)), this, SLOT(workerProgressChanged(int)), Qt::DirectConnection);

            worker->compute();
            out->computeMinMax();

            group->addItemDrawable(out);

            delete worker;

            /*
             * We change the model name to match the currently selected
             * interpolation method.
             *
             * FIXME: that actually doesn't work.
             * FIX : you change the name of the itemdrawable so if you go in a table view you will show this name
             */
            //item->m_result->setDisplayableName(item->m_name);
        }
    }
}

//This method interpolates the density grid based on the LVOX1 version of Z axis average interpolation
void LVOX3_StepInterpolateDistance::ZAverageInterpolation(const lvox::Grid3Df *INdensityGrid, lvox::Grid3Df* const OUTdensityGrid,const lvox::Grid3Di *hitGrid,const lvox::Grid3Di *theoreticalGrid,const lvox::Grid3Di *beforeGrid){
    // loop on z levels
    for (size_t zz = 0 ;  zz < INdensityGrid->zdim() ; zz++)
    {
        float meanDensity = 0;
        size_t ncells = 0;
        // Compute mean value for the level z
        for (size_t yy = 0 ;  yy < INdensityGrid->ydim() ; yy++)
        {
            for (size_t xx = 0 ;  xx < INdensityGrid->xdim() ; xx++)
            {
                float value = INdensityGrid->value(xx, yy, zz);
                if (value > 0) // empty cells don't count for the mean density
                {
                    meanDensity += value;
                    ncells++;
                }
            }
        }
        meanDensity /= ncells;

        // set mean value for all NA cells
        for (size_t yy = 0 ;  yy < INdensityGrid->ydim() ; yy++)
        {
            for (size_t xx = 0 ;  xx < INdensityGrid->xdim() ; xx++)
            {
                float value = INdensityGrid->value(xx, yy, zz);
                if (value < 0 ) // replace NA values or incoherent density results
                {
                    //If even one ray was intercepted in the voxel
                    if(hitGrid->value(xx, yy, zz) >= 1){
                        int rays = theoreticalGrid->value(xx,yy,zz) - beforeGrid->value(xx,yy,zz);
                        //If the number of rays is under the number of effective rays, should more or less always be true
                        if(rays <= m_effectiveRayThresh){
                            OUTdensityGrid->setValue(xx, yy, zz, meanDensity);
                        }else { //Weird fringe case where Ni > Nt-Nb, error code -4 (Because the density value cant be negative and have more effectiveRayThresh than 10(default rayThresh)
                            OUTdensityGrid->setValue(xx, yy, zz, 0.0);
                        }
                    } else {
                        OUTdensityGrid->setValue(xx, yy, zz, 0.0);
                    }
                } else { // else if not a NA : keep the IN value
                    OUTdensityGrid->setValue(xx, yy, zz, value);
                }
            }
        }
    }
}

void LVOX3_StepInterpolateDistance::workerProgressChanged(int p)
{
    setProgress(p);
}
