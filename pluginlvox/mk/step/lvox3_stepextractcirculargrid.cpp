#include "lvox3_stepextractcirculargrid.h"

#include "ct_result/model/inModel/ct_inresultmodelgrouptocopy.h"
#include "ct_result/model/outModel/tools/ct_outresultmodelgrouptocopypossibilities.h"
#include "mk/tools/lvox3_gridtype.h"
#include "ct_result/ct_resultgroup.h"

#include "ct_view/ct_stepconfigurabledialog.h"

#include "ct_view/tools/ct_configurablewidgettodialog.h"

#include "mk/tools/lvox3_errorcode.h"

//+test lib
#include <QDebug>
//-test lib

#define DEF_SearchInSourceResult      "rs"
#define DEF_SearchInSourceGroup       "gs"
#define DEF_SearchInGroup             "grp"
#define DEF_SearchInGrid              "grid"

LVOX3_StepExtractCircularGrid::LVOX3_StepExtractCircularGrid(CT_StepInitializeData &dataInit) : CT_AbstractStep(dataInit)
{
    _x = 0.00;
    _y = 0.00;
    _radiusmin = 0.00;
    _radius = 17.00;
    _zmin = -10000;
    _zmax = 10000;
}

QString LVOX3_StepExtractCircularGrid::getStepDescription() const
{
    return tr("Extraction d'une grille circulaire");
}

// Step detailed description
QString LVOX3_StepExtractCircularGrid::getStepDetailledDescription() const
{
    return tr("Cette étape permet d'extraire une grille 3D circulaire a partir d'une grille d'entrée, le but étant d'offrir un outil se rapprochant de la réalité forestière.");
}

CT_VirtualAbstractStep* LVOX3_StepExtractCircularGrid::createNewInstance(CT_StepInitializeData &dataInit)
{
    // Creates an instance of this step
    return new LVOX3_StepExtractCircularGrid(dataInit);
}

void LVOX3_StepExtractCircularGrid::createInResultModelListProtected()
{
    // We must have
    // - at least one grid
    CT_InResultModelGroupToCopy *inResultRefCopy = createNewInResultModelForCopy(DEF_SearchInSourceResult, tr("Grille d'entrée"), "", true);
    inResultRefCopy->setZeroOrMoreRootGroup();
    inResultRefCopy->addGroupModel("", DEF_SearchInSourceGroup, CT_AbstractItemGroup::staticGetType(), tr("Groupe de référence"), "", CT_InAbstractGroupModel::CG_ChooseOneIfMultiple);
    inResultRefCopy->addItemModel(DEF_SearchInSourceGroup, DEF_SearchInGrid, CT_AbstractGrid3D::staticGetType(), tr("Grille 3D"));
}

void LVOX3_StepExtractCircularGrid::createPostConfigurationDialog()
{

    CT_StepConfigurableDialog *configDialog = newStandardPostConfigurationDialog();

    configDialog->addDouble(tr("Coordonnée X du centre de la grille à extraire:"), "m", -1e+10, 1e+10, 4, _x);
    configDialog->addDouble(tr("Coordonnée Y du centre de la grille à extraire :"), "m", -1e+10, 1e+10, 4, _y);
    configDialog->addDouble(tr("Rayon de début de la grille à extraire :"), "m", 0, 1e+10, 4, _radiusmin);
    configDialog->addDouble(tr("Rayon de la grille à extraire (maximum) :"), "m", 0.01, 1e+10, 4, _radius);
    configDialog->addDouble(tr("Niveau Z minimum :"), "m", -1e+10, 1e+10, 4, _zmin);
    configDialog->addDouble(tr("Niveau Z maximum :"), "m", -1e+10, 1e+10, 4, _zmax);

}

void LVOX3_StepExtractCircularGrid::createOutResultModelListProtected()
{
    // create a new OUT result that is a copy of the IN result selected by the user
    CT_OutResultModelGroupToCopyPossibilities *resultModel = createNewOutResultModelToCopy(DEF_SearchInSourceResult);

    if (!resultModel)
        return;

    resultModel->addItemModel(DEF_SearchInSourceGroup, _grid_ModelName, new lvox::Grid3Di(), tr("Extracted Grid"));

}

void LVOX3_StepExtractCircularGrid::compute()
{
    CT_ResultGroup* outResult = getOutResultList().first();

    CT_ResultGroupIterator itR(outResult, this, DEF_SearchInSourceGroup);

    QList<lvox::Grid3Df*> listGrids;

    //For every grid in the result
    while (itR.hasNext() && !isStopped())
    {
        CT_StandardItemGroup *group = dynamic_cast<CT_StandardItemGroup*>((CT_AbstractItemGroup*)itR.next());

        const CT_AbstractGrid3D* inGrid = (const CT_AbstractGrid3D*) group->firstItemByINModelName(this, DEF_SearchInGrid);
        size_t counterVoxels = 0;
        size_t n_voxels;
        //Number of voxels depending on grid resolution
        n_voxels = (inGrid->xdim()*inGrid->ydim()*inGrid->zdim());

        qDebug()<<"Number of voxels:"<<n_voxels;
        if (inGrid != NULL)
        {
            if((inGrid->xdim() > 0)
                    && (inGrid->ydim() > 0)
                    && (inGrid->zdim() > 0)
                    && (inGrid->resolution() > 0)) {
                //Declaring output grid to be able to export personalized grid of profile
                lvox::Grid3Df *outGrid = new lvox::Grid3Df(_grid_ModelName.completeName(), outResult, inGrid->minX(), inGrid->minY(), inGrid->minZ(), inGrid->xdim(), inGrid->ydim(), inGrid->zdim(), inGrid->resolution(), lvox::Max_Error_Code, 0);


                group->addItemDrawable(outGrid);
                listGrids.append(outGrid);
                for(size_t col = 0;col <inGrid->xdim() && (!isStopped());col++){
                    for(size_t lin = 0;lin <inGrid->ydim() && (!isStopped());lin++){
                        for(size_t level = 0;level <inGrid->zdim() && (!isStopped());level++){
                            Eigen::Vector3d centerCoordVoxel;
                            size_t index;
                            inGrid->index(col, lin, level, index);
                            double value = inGrid->valueAtIndexAsDouble(index);
                            inGrid->getCellCenterCoordinates(index,centerCoordVoxel);
                            if(evaluateVoxel(centerCoordVoxel, inGrid->resolution())){
                                outGrid->addValueAtIndex(index,value);
                            }else{
                                outGrid->addValueAtIndex(index,0.0);
                            }
                            ++counterVoxels;
                            // progres de 0 à 100
                            setProgress((100.0*counterVoxels)/n_voxels);
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < listGrids.length();i++){
        listGrids.at(i)->computeMinMax();
    }
}

//Test to see if any part of the voxel is inside the radius of the extracted grid (If it is, it is added to the extracted grid)
bool LVOX3_StepExtractCircularGrid::evaluateVoxel(Eigen::Vector3d centerCoords, double gridResolution){
    cv::Point2d centerPoint(_x,_y);
    cv::Point2d topLeftPoint(centerCoords(0)-gridResolution,centerCoords(1)+gridResolution);
    cv::Point2d topRightPoint(centerCoords(0)+gridResolution,centerCoords(1)+gridResolution);
    cv::Point2d bottomLeftPoint(centerCoords(0)-gridResolution,centerCoords(1)-gridResolution);
    cv::Point2d bottomRightPoint(centerCoords(0)+gridResolution,centerCoords(1)-gridResolution);
    cv::Point2d currentVoxelCenterPoint(centerCoords(0),centerCoords(1));

    //2D plane visualization of voxel square (topleft,topright,center,bottomleft,bottomright points)
    //If any of those points are in the distance, they are added to the grid.
    //Note: I could have done the computation for distances with sqrt(pow()+pow()). I do think the code is easier to read this way
    //I will change it, if it's considered to lack performance compared to the other method
    double distance = cv::norm(cv::Mat(centerPoint),cv::Mat(currentVoxelCenterPoint));
    if(distance>= _radiusmin && distance <= _radius){
        if(centerCoords(2)>=_zmin && centerCoords(2)<=_zmax)
            return true;
    }
    distance = cv::norm(cv::Mat(centerPoint),cv::Mat(topLeftPoint));
    if(distance>= _radiusmin && distance <= _radius){
        if(centerCoords(2)>=_zmin && centerCoords(2)<=_zmax)
            return true;
    }
    distance = cv::norm(cv::Mat(centerPoint),cv::Mat(topRightPoint));
    if(distance>= _radiusmin && distance <= _radius){
        if(centerCoords(2)>=_zmin && centerCoords(2)<=_zmax)
            return true;
    }
    distance = cv::norm(cv::Mat(centerPoint),cv::Mat(bottomLeftPoint));
    if(distance>= _radiusmin && distance <= _radius){
        if(centerCoords(2)>=_zmin && centerCoords(2)<=_zmax)
            return true;
    }
    distance = cv::norm(cv::Mat(centerPoint),cv::Mat(bottomRightPoint));
    if(distance>= _radiusmin && distance <= _radius){
        if(centerCoords(2)>=_zmin && centerCoords(2)<=_zmax)
            return true;
    }

    return false;
}
