/**
 * @author Michael Krebs (AMVALOR)
 * @date 25.01.2017
 * @version 1
 */
#ifndef LVOX3_STEPINTERPOLATEDISTANCE_H
#define LVOX3_STEPINTERPOLATEDISTANCE_H


#include "ct_step/abstract/ct_abstractstep.h"
#include "ct_tools/model/ct_autorenamemodels.h"
#include "mk/tools/lvox3_gridtype.h"

/**
 * @brief Compute the sky of a scene
 */
class LVOX3_StepInterpolateDistance : public CT_AbstractStep
{
    Q_OBJECT

public:
    enum InterpolationMethod {
        Distance = 0,
        Trust,
        DistanceAndTrust,
        ZAverage
    };

    LVOX3_StepInterpolateDistance(CT_StepInitializeData &dataInit);

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

    /**
     * @brief This method interpolates the density grid based on the LVOX1 version of Z axis average interpolation
     */
    void ZAverageInterpolation(const lvox::Grid3Df *INdensityGrid,lvox::Grid3Df* const OUTdensityGrid,const lvox::Grid3Di *hitGrid,const lvox::Grid3Di *theoreticalGrid,const lvox::Grid3Di *beforeGrid);

private:
    QHash<QString, InterpolationMethod> m_interpolationMethodCollection;

    double  m_interpolateRadius;
    QString m_interpolationMethod;

    /**
     * Distance interpolation
     */
    double  m_interpolateDensityThreshold;
    int     m_interpolatePower;

    /**
     * Trust interpolation
     */
    bool    m_enableInterpolateTrust;
    int     m_trustLowThreshold;
    int     m_trustHighThreshold;

    /**
     * Z Average interpolation
     */
    int     m_effectiveRayThresh;
    int     m_numZCalculatedOn;

    CT_AutoRenameModels m_outInterpolatedGridModelName;

private slots:
    /**
     * @brief Called when the progress changed of the worker that compute number of points in the grid
     */
    void workerProgressChanged(int p);
};

#endif // LVOX3_STEPINTERPOLATEDISTANCE_H
