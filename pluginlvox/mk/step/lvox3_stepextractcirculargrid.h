#ifndef LVOX3_STEPEXTRACTCIRCULARGRID_H
#define LVOX3_STEPEXTRACTCIRCULARGRID_H

#include "ct_step/abstract/ct_abstractstep.h"
#include "ct_tools/model/ct_autorenamemodels.h"

#include "ct_itemdrawable/abstract/ct_abstractgrid3d.h"

class LVOX3_StepExtractCircularGrid: public CT_AbstractStep
{
    Q_OBJECT
public:
    LVOX3_StepExtractCircularGrid(CT_StepInitializeData &dataInit);
    
    /**
     * @brief Return a short description of what do this class
     */
    QString getStepDescription() const;

    /*! \brief Step detailled description
     *
     * Return a detailled description of the step function
     */
    QString getStepDetailledDescription() const;
    /**
     * @brief Return a new empty instance of this class
     */
    CT_VirtualAbstractStep* createNewInstance(CT_StepInitializeData &dataInit);
protected:
    /**
     * @brief This method defines what kind of input the step can accept
     */
    void createInResultModelListProtected();

    /**
     * @brief Show the post configuration dialog.
     *
     * If you want to show your own configuration dialog your must overload this method and show your dialog when this method is called. Don't forget
     * to call the method "setSettingsModified(true)" if your settings is modified (if user accept your dialog).
     *
     * @return true if the settings was modified.
     */
    void createPostConfigurationDialog();

    /**
     * @brief This method defines what kind of output the step produces
     */
    void createOutResultModelListProtected();

    /**
     * @brief This method do the job
     */
    void compute();
private:
    double _x;                            /*!< Coordonnee X du centre de la grille a extraire*/
    double _y;                            /*!< Coordonnee Y du centre de la grille a extraire*/
    double _radiusmin;                    /*!< Rayon (m) de debut de la grille a extraire*/
    double _radius;                       /*!< Rayon (m) de la grille a extraire*/
    double _zmin;                         /*!< Z minimum de la grille a extraire*/
    double _zmax;                         /*!< Z maximum de la grille a extraire*/

    CT_AutoRenameModels _grid_ModelName;

    bool evaluateVoxel(Eigen::Vector3d centerCoords, double gridResolution);
};

#endif // LVOX3_STEPEXTRACTCIRCULARGRID_H
