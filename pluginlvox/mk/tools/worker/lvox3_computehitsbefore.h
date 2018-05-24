/**
 * @author Jeremy Besserer-Lemay (AMVALOR)
 * @date 13.03.2018
 * @version 1
 */

#ifndef LVOX3_COMPUTEHITSBEFORE_H
#define LVOX3_COMPUTEHITSBEFORE_H

#include "lvox3_worker.h"
#include "mk/tools/lvox3_gridtype.h"

#include "ct_itemdrawable/ct_scene.h"
#include "ct_itemdrawable/ct_grid3d.h"
#include "ct_itemdrawable/tools/scanner/ct_shootingpattern.h"

/*!
 * @brief Computes the "hits" and "before" grids of the scene,
 * this class was made in an attempt to merge computes and restrain number of threads used for laptop users.
 */
class LVOXSHAREDFORTEST_EXPORT LVOX3_ComputeHitsBefore : public LVOX3_Worker
{
    Q_OBJECT

public:
    /**
     * @brief Create an object that will do the job.
     * @param pattern : shooting pattern
     * @param pointCloudIndex : index of points
     * @param before : store the number of hits that were not stopped
     * @param shotDeltaDistance  : store the distance between the first intersection point (IN) AND the second intersection point (OUT)
     * @param hits : store the number of hits
     * @param shotInDistance  : store the distance between the first intersection point of the shot, the voxel AND the hitted point
     * @param shotOutDistance  : store the distance between the second intersection point of the shot, the voxel AND the hitted point
     */
    LVOX3_ComputeHitsBefore(CT_ShootingPattern* pattern,
                        const CT_AbstractPointCloudIndex* pointCloudIndex,
                        lvox::Grid3Di* before,
                        lvox::Grid3Df* shotDeltaDistance = NULL,lvox::Grid3Di* hits = NULL,
                        lvox::Grid3Df* shotInDistance = NULL,
                        lvox::Grid3Df* shotOutDistance = NULL);

protected:
    /**
     * @brief Do the job
     */
    void doTheJob();

private:
    CT_ShootingPattern*                 m_pattern;
    const CT_AbstractPointCloudIndex*   m_pointCloudIndex;
    lvox::Grid3Di*                      m_before;
    lvox::Grid3Df*                      m_shotDeltaDistance;
    lvox::Grid3Di*                      m_hits;
    lvox::Grid3Df*                      m_shotInDistance;
    lvox::Grid3Df*                      m_shotOutDistance;
};

#endif // LVOX3_COMPUTEHITSBEFORE_H
