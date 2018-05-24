#ifndef LVOX3_MERGEGRIDS_H
#define LVOX3_MERGEGRIDS_H

#include <memory>
#include <QVector>
#include "mk/tools/lvox3_utils.h"
#include "mk/tools/lvox3_factory.hpp"
#include "lvox_sharedfortest.h"

#define LVOX_REDUCER_RDI "MaxRDI"
#define LVOX_REDUCER_TRUST "MaxTrust"
#define LVOX_REDUCER_TRUST_RATIO "MaxTrustRatio"
#define LVOX_REDUCER_HITS "MaxNi"
#define LVOX_REDUCER_SUM_RATIO "SumRatio"
#define LVOX_REDUCER_WEIGHTED_RDI "WeightedRDI"

struct LVOXSHAREDFORTEST_EXPORT VoxelData {
    void load(LVOXGridSet *g, size_t idx);
    void commit(LVOXGridSet *g, size_t idx);
    int nt;
    int nb;
    int ni;
    float rd;
};

class LVOXSHAREDFORTEST_EXPORT VoxelReducerOptions {
public:
    VoxelReducerOptions() :
        reducerLabel(),
        ignoreVoxelZeroDensity(true),
        effectiveRaysThreshold(10) {}
    QString reducerLabel;
    bool ignoreVoxelZeroDensity;
    int effectiveRaysThreshold;
};

class LVOXSHAREDFORTEST_EXPORT VoxelReducer {
public:
    VoxelReducer();
    VoxelReducer(VoxelReducerOptions& opts);
    virtual ~VoxelReducer();
    virtual void init(VoxelData &data);
    virtual void join(const VoxelData &rhs) = 0;
    virtual VoxelData& value();
    VoxelData m_data;
    VoxelReducerOptions m_opts;
};

class LVOXSHAREDFORTEST_EXPORT VoxelReducerMaxRDI : public VoxelReducer {
public:
    void join(const VoxelData &rhs);
};

class LVOXSHAREDFORTEST_EXPORT VoxelReducerMaxTrust : public VoxelReducer {
public:
    void join(const VoxelData &rhs);
};

class LVOXSHAREDFORTEST_EXPORT VoxelReducerMaxTrustRatio : public VoxelReducer {
public:
    void join(const VoxelData &rhs);
};

class LVOXSHAREDFORTEST_EXPORT VoxelReducerMaxNi : public VoxelReducer {
public:
    void join(const VoxelData &rhs);
};

class LVOXSHAREDFORTEST_EXPORT VoxelReducerSumRatio : public VoxelReducer {
public:
    void join(const VoxelData &rhs);
    VoxelData& value();
};

//This class is a weighted RDI value of all the scans following the rule of:
//[ (Nt-Nb)1 × RDI1] + [ (Nt-Nb)2 × RDI2] +[ (Nt-Nb)3 × RDI3] +[ (Nt-Nb)4 × RDI4]/[(Nt-Nb)1 +(Nt-Nb)2 +(Nt-Nb)3 +(Nt-Nb)4]
//The numbers 1,2,3,4 are only to represent every scanner
class LVOXSHAREDFORTEST_EXPORT VoxelReducerWeightedRDI : public VoxelReducer {
public:
    void join(const VoxelData &rhs);
    VoxelData& value();
private:
    int ntMinusNb;
    double tempRDI;
};

struct LVOXSHAREDFORTEST_EXPORT VoxelReducerDefinitionStruct {
    QString label;
    QString name;
    QString desc;
};

#include <functional>
typedef std::function<bool (const size_t &)> ProgressMonitor;

// TODO: LVOX3_MergeGrids should be converted to singleton

class LVOXSHAREDFORTEST_EXPORT LVOX3_MergeGrids
{
public:
    LVOX3_MergeGrids();

    static void apply(LVOXGridSet *merged, QVector<LVOXGridSet*> *gs,
                      VoxelReducer *reducer);

    static void apply(LVOXGridSet *merged, QVector<LVOXGridSet*> *gs,
                      VoxelReducer *reducer, ProgressMonitor monitor);

    static const QVector<VoxelReducerDefinitionStruct> getReducerList();

    std::unique_ptr<VoxelReducer> makeReducer(QString &label);

private:
    Factory<VoxelReducer> f;
    static const QVector<VoxelReducerDefinitionStruct> m_voxelReducerDefinitions;
};

#endif // LVOX3_MERGEGRIDS_H
