/**
 * @author Michael Krebs (AMVALOR)
 * @date 25.01.2017
 * @version 1
 */
#ifndef LVOX3_STEPCOMPUTESKY_H
#define LVOX3_STEPCOMPUTESKY_H


#include "ct_step/abstract/ct_abstractstep.h"
#include "ct_tools/model/ct_autorenamemodels.h"

/**
 * @brief Compute the sky of a scene
 */
class LVOX3_StepComputeSky : public CT_AbstractStep
{
    Q_OBJECT

public:
    LVOX3_StepComputeSky(CT_StepInitializeData &dataInit);

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
    int     m_minimumNumberOfPoints;
    double  m_gridResolution;

    CT_AutoRenameModels m_outDSMModelName;
    CT_AutoRenameModels m_outZMaxModelName;
    CT_AutoRenameModels m_outHitGridModelName;

private slots:
    /**
     * @brief Called when the progress changed of the worker that compute number of points in the grid
     */
    void workerProgressChanged(int p);
};

#endif // LVOX3_STEPCOMPUTESKY_H
