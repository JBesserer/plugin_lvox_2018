#include "lvox3_computetheoriticals.h"

#include "mk/tools/traversal/woo/lvox3_grid3dwootraversalalgorithm.h"
#include "mk/tools/traversal/woo/visitor/lvox3_countvisitor.h"
#include "mk/tools/traversal/woo/visitor/lvox3_distancevisitor.h"
#include "mk/tools/lvox3_errorcode.h"

LVOX3_ComputeTheoriticals::LVOX3_ComputeTheoriticals(CT_ShootingPattern* pattern,
                                                     lvox::Grid3Di* theoricals,
                                                     lvox::Grid3Df* shotDeltaDistance) : LVOX3_Worker()
{
    m_pattern = pattern;
    m_outputTheoriticalGrid = theoricals;
    m_outputDeltaTheoriticalGrid = shotDeltaDistance;
}

LVOX3_ComputeTheoriticals::~LVOX3_ComputeTheoriticals()
{
}

void LVOX3_ComputeTheoriticals::doTheJob()
{
    // Creates visitors
    QVector<LVOX3_Grid3DVoxelWooVisitor*> list;

    LVOX3_CountVisitor<lvox::Grid3DiType> countVisitor(m_outputTheoriticalGrid);
    LVOX3_DistanceVisitor<lvox::Grid3DfType> distVisitor(m_outputDeltaTheoriticalGrid);

    list.append(&countVisitor);

    if (m_outputDeltaTheoriticalGrid != NULL)
        list.append(&distVisitor);

    // Creates traversal algorithm
    LVOX3_Grid3DWooTraversalAlgorithm<lvox::Grid3DiType> algo(m_outputTheoriticalGrid, true, list);

    const size_t nShot = m_pattern->getNumberOfShots();

    setProgressRange(0, (m_outputDeltaTheoriticalGrid != NULL) ? nShot+1 : nShot);

    for(size_t i=0; (i<nShot) && !mustCancel(); ++i) {
        const CT_Shot shot = m_pattern->getShotAt(i);

        // algo already check if the ray touch the grid or not so we don't have to do twice !
        algo.compute(shot.getOrigin(), shot.getDirection());

        setProgress(i);
    }

    // Don't forget to calculate min and max in order to visualize it as a colored map
    m_outputTheoriticalGrid->computeMinMax();

    if ((m_outputDeltaTheoriticalGrid != NULL)
            && !mustCancel())
    {
        const size_t size = m_outputDeltaTheoriticalGrid->nCells();

        // To get the mean distance we have to divide each voxel the sum of distances by the number of hits
        for (size_t i = 0 ; (i < size) && !mustCancel(); ++i )
        {
            const float nHits =  m_outputTheoriticalGrid->valueAtIndex(i);

            if (nHits <= 0)
                m_outputDeltaTheoriticalGrid->setValueAtIndex(i, nHits); // TODO : check if must set an error code here
            else
                m_outputDeltaTheoriticalGrid->setValueAtIndex(i, m_outputDeltaTheoriticalGrid->valueAtIndex(i)/nHits);
        }

        m_outputDeltaTheoriticalGrid->computeMinMax();

        setProgress(nShot+1);
    }

}
