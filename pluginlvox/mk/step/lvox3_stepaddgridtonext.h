/**
 * @author Jeremy Besserer-Lemay (AMVALOR)
 * @date 09.04.2018
 * @version 1
 */
#ifndef LVOX3_STEPADDGRIDTONEXT_H
#define LVOX3_STEPADDGRIDTONEXT_H

#include "ct_step/abstract/ct_abstractstep.h"
#include "ct_tools/model/ct_autorenamemodels.h"

/**
 * @brief This class aims to be able to add a 3D grid to a result so that you can use it in genericcomputegrids lvox3 calculation.
 *        The class would benefit more from being able to incorporate Alexander's recommandation for multiple point of view.
 */
class LVOX3_StepAddGridToNext : public CT_AbstractStep
{
    Q_OBJECT
public:
    enum GridType {
        Ni = 0,
        Nt,
        Nb
    };

    LVOX3_StepAddGridToNext(CT_StepInitializeData &dataInit);

    /**
     * @brief Return a short description of what do this class
     */
    QString getStepDescription() const;

    /*! \brief Step detailed description
     *
     * Return a detailed description of the step function
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
     * @brief This method creates a window for the user to set the different parameters of the step.
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
    QHash<QString, GridType> m_gridTypeCollection;
    QString m_gridType;

    CT_AutoRenameModels _grid_ModelName;
    CT_AutoRenameModels _NiFlag_ModelName;
    CT_AutoRenameModels _NtFlag_ModelName;
    CT_AutoRenameModels _NbFlag_ModelName;

};

#endif // LVOX3_STEPADDGRIDTONEXT_H
