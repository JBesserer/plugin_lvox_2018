#ifndef LVOX3_INTERPOLATEKRIGING_H
#define LVOX3_INTERPOLATEKRIGING_H

#include <QObject>
#include "lvox3_worker.h"
#include "mk/tools/lvox3_gridtype.h"

class LVOX3_InterpolateKriging : public LVOX3_Worker
{
    Q_OBJECT
public:
    /**
     * @brief Construct this worker
     * @param originalDensityGrid : the original density grid to get values of density
     * @param beforeGrid : before grid to get values
     * @param theoriticalsGrid : theoriticals grid to get values
     * @param outDensityGrid : the density grid that will be modified with new density values
     * @param radius : max radius to search cells
     * @param effectiveRayThreshold : minimum number of effective ray (Nt-Nb must be > to threshold) to have a trust factor > 0
     */
    LVOX3_InterpolateKriging(const lvox::Grid3Df *originalDensityGrid,
                             const lvox::Grid3Di *beforeGrid,
                             const lvox::Grid3Di *theoriticalsGrid,
                             lvox::Grid3Df * const outDensityGrid,
                             double radius);

protected:
    /**
     * @brief Do the job
     */
    void doTheJob();

    void krigepointBinomial();
    double variogram(Eigen::Vector2d points, int a, int b, double nugget, double sill, double range);
    double anisotropic_distance(Eigen::Vector2d points, int a, int b);

private:
    lvox::Grid3Df*      m_originalDensityGrid;
    lvox::Grid3Di*      m_beforeGrid;
    lvox::Grid3Di*      m_theoriticalsGrid;
    lvox::Grid3Df*      m_outDensityGrid;
    lvox::Grid3Di*      m_hitGrid;
    double              m_radius; 
};

#endif // LVOX3_INTERPOLATEKRIGING_H
