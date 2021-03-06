#include <QString>
#include <QtTest>
#include <QDebug>
#include <QList>
#include <QScopedPointer>
#include <QMutableListIterator>

#include "ct_global/ct_context.h"
#include "ct_iterator/ct_pointiterator.h"
#include "ct_iterator/ct_mutablepointiterator.h"
#include "ct_itemdrawable/ct_scene.h"
#include "ct_itemdrawable/ct_pointsattributesnormal.h"
#include "ct_itemdrawable/model/abstract/ct_abstractsingularitemmodelt.h"
#include "ct_itemdrawable/model/outModel/ct_outstdsingularitemmodel.h"
#include "ct_cloud/tools/ct_globalpointcloudmanager.h"
#include "ct_cloud/tools/iglobalcloudlistener.h"
#include "ct_tools/repository/ct_repositoryaccess.h"
#include "ctlibio/readers/ct_reader_points_ascii.h"
#include "ctlibio/readers/ct_reader_ascrgb.h"
#include "ctlibio/readers/ct_reader_xyb.h"
#include "ct_reader/extensions/ct_readerpointsfilteringextension.h"

#include <functional>

typedef std::function<bool (const CT_Point& pt)> CT_FilterPoint;

const CT_FilterPoint filter_not_origin = [](const CT_Point& pt)
{
    static const Eigen::Vector3d origin(0, 0, 0);
    return (pt == origin);
};

class FilterpointsTest : public QObject
{
    Q_OBJECT

public:
    FilterpointsTest();

private Q_SLOTS:
    void testLoadPoints_ASCII();
    void testLoadPoints_ASCRGB();
    void testLoadPoints_XYB();
    void testFilterBenchmark_data();
    void testFilterBenchmark();
};

class MonitoringCloudListener : public IGlobalCloudListener {
public:
    MonitoringCloudListener() :
        m_size(0), m_max_size(0) {
        // FIXME: CT_Repository::globalCloudManager() is protected, cannot
        // call it directly. Instead, use the proxy hack.
        //PS_REPOSITORY->globalCloudManager<CT_PointData>()->addGlobalCloudListener(this);

        CT_RepositoryAccess access(PS_REPOSITORY);
        CT_AbstractGlobalCloudManager *mgr = access.globalPointCloudManager();
        mgr->addGlobalCloudListener(this);
    }
    ~MonitoringCloudListener() {
        // FIXME: cannot remove the listener. Therefore, we should never
        // delete this object. Fix that by providing a remove method.
        //auto mgr = PS_REPOSITORY->globalCloudManager<CT_PointData>();
        //mgr->removeGlobalCloudListener(this);
    }

    size_t m_size;
    size_t m_max_size;

    void reset() {
        m_size = m_max_size = 0;
    }

protected:
    virtual void cloudAdded(const size_t &size) {
        m_size += size;
        m_max_size = qMax(m_max_size, m_size);
    }

    virtual void cloudDeleted(const size_t &beginIndex, const size_t &size) {
        Q_UNUSED(beginIndex);
        m_size -= size;
    }
};

static MonitoringCloudListener* monitor;

FilterpointsTest::FilterpointsTest()
{
    // FIXME: let this leaks, because we cannot unregister the listener
    // and would cause a crash otherwise.
    monitor = new MonitoringCloudListener();
}

typedef std::function<void (const CT_Point& pt)> CT_PointCallback;

void foreach_point(CT_PCIR pcir, CT_FilterPoint filter, CT_PointCallback fn)
{
    CT_PointIterator it(pcir);
    while(it.hasNext()) {
        it.next();
        const CT_Point &p = it.currentPoint();
        if (!filter(p)) {
            fn(p);
        }
    }
}

void foreach_point(CT_PCIR pcir, CT_PointCallback fn)
{
    foreach_point(pcir, [](const CT_Point& pt){ Q_UNUSED(pt); return false; }, fn);
}

size_t count_points(CT_PCIR pcir, CT_FilterPoint filter)
{
    size_t count = 0;
    foreach_point(pcir, filter,
        [&](const CT_Point& pt){
            Q_UNUSED(pt);
            count++;
        }
    );
    return count;
}

CT_PCIR filter_cloud_copy_fixed(CT_PCIR orig, CT_FilterPoint filter)
{
    // Compute the size of the new cloud
    size_t count = count_points(orig, filter);
    if (count == orig->size()) {
        // do not create a copy if no point is filtered
        return orig;
    }

    // copy only the non-filtered points in the new point cloud
    CT_PCIR pcir = PS_REPOSITORY->createNewPointCloud(count);
    CT_MutablePointIterator it(pcir);
    foreach_point(orig, filter,
        [&](const CT_Point& pt){
            it.next();
            it.replaceCurrentPoint(pt);
        }
    );
    return pcir;
}


CT_PCIR filter_cloud_copy_variable(CT_PCIR orig, CT_FilterPoint filter)
{
    // copy only the non-filtered points in the new point cloud
    CT_AbstractUndefinedSizePointCloud *cloud = PS_REPOSITORY->createNewUndefinedSizePointCloud();

    foreach_point(orig, filter,
        [&](const CT_Point& pt){
            cloud->addPoint(pt);
        }
    );
    return PS_REPOSITORY->registerUndefinedSizePointCloud(cloud);
}

CT_PCIR filter_cloud_inplace(CT_PCIR orig, CT_FilterPoint filter)
{
    /*
     * Maintain src and dst indices. When a filtered element is reached,
     * increment src, but not dst. The next non-filtered element is copied from
     * src to dst and overwrites the filtered elements.
     *
     * This should be the optimal method to filter a point cloud. It does not
     * create a copy (reduced max memory) and scan the points only once.
     *
     * FIXME: how to resize the point cloud?
     */

    CT_PointIterator src(orig);
    CT_MutablePointIterator dst(orig);
    size_t srcIdx = 0;
    size_t dstIdx = 0;
    while(src.hasNext()) {
        src.next();
        const CT_Point &srcPt = src.currentPoint();
        if (filter(srcPt)) {
            // we keep the point
            dst.next();
            if (srcIdx != dstIdx) {
                // move data only if the src is different than dst
                dst.replaceCurrentPoint(srcPt);
            }
            dstIdx++;
        }
        srcIdx++;
    }
    return orig;
}

CT_Scene *findScene(CT_AbstractReader *reader)
{
    QListIterator<CT_OutStdSingularItemModel*> it(reader->outItemDrawableModels());
    while(it.hasNext()) {
        CT_OutStdSingularItemModel *model = it.next();

        /*
         * Beware: takeItemDrawableOfModel assumes that the client takes
         * the ownership of the object. The CT_AbstractSingularItemDrawable
         * keeps a ref on the cloud point. If the item leaks, then the refcount
         * never reaches zero and then the entire cloud point leaks.
         */

        QList<CT_AbstractSingularItemDrawable*> items =
                reader->itemDrawableOfModel(model->uniqueName());
        QMutableListIterator<CT_AbstractSingularItemDrawable*> itI(items);
        while(itI.hasNext()) {
            CT_AbstractSingularItemDrawable* item = itI.next();
            if (CT_Scene *scene = dynamic_cast<CT_Scene*>(item)) {
                return scene;
            }
        }
    }
    return nullptr;
}

void checkReader(CT_AbstractReader *reader, QString fname, size_t expSize)
{

    CT_ReaderPointsFilteringExtension* extReader = dynamic_cast<CT_ReaderPointsFilteringExtension*>(reader);

    QVERIFY(extReader != nullptr);

    monitor->reset();
    QString path(SRCDIR + fname);
    reader->init();
    reader->setFilePath(path);
    extReader->setPointsFilter(filter_not_origin);

    CT_RepositoryAccess access(PS_REPOSITORY);
    QVERIFY2(reader->readFile(), "failed to read file");
    CT_Scene *scene = findScene(reader);
    QVERIFY(scene != nullptr);
    QCOMPARE(scene->getPointCloudIndexRegistered()->size(), expSize);
    QCOMPARE(access.globalPointCloudManager()->globalAbstractCloud()->memoryUsed(), 12 * expSize);
    delete reader;
    QCOMPARE(access.globalPointCloudManager()->globalAbstractCloud()->memoryUsed(), size_t(0));
    QCOMPARE(monitor->m_max_size, expSize);
    monitor->reset();
}

void FilterpointsTest::testLoadPoints_ASCII()
{
    //QSharedPointer<CT_Reader_Points_ASCII> reader(new CT_Reader_Points_ASCII());
    CT_Reader_Points_ASCII *reader = new CT_Reader_Points_ASCII();
    reader->setXColumnIndex(0);
    reader->setYColumnIndex(1);
    reader->setZColumnIndex(2);
    // Do not read the colors, they are floats and not integers
    //reader->setRedColumnIndex(3);
    //reader->setGreenColumnIndex(4);
    //reader->setBlueColumnIndex(5);
    reader->setNxColumnIndex(6);
    reader->setNyColumnIndex(7);
    reader->setNzColumnIndex(8);
    reader->setHasHeader(true);
    reader->setValueSeparator(" ");

    checkReader(reader, "./mini.asc", 5);
}

void FilterpointsTest::testLoadPoints_ASCRGB()
{
    CT_Reader_ASCRGB *reader = new CT_Reader_ASCRGB();
    checkReader(reader, "./mini.asc", 5);
}

void FilterpointsTest::testLoadPoints_XYB()
{
    CT_Reader_XYB *reader = new CT_Reader_XYB();
    checkReader(reader, "./mini.xyb", 5);
}

CT_PCIR createPointCloud(int n, int mod)
{
    CT_PCIR pcir = PS_REPOSITORY->createNewPointCloud(n);
    CT_MutablePointIterator it(pcir);
    int count = 0;
    const CT_Point pt_not_zero = Eigen::Vector3d(1, 2, 3);
    const CT_Point pt_zero = Eigen::Vector3d(0, 0, 0);
    while(it.hasNext()) {
        it.next();
        if (count++ % mod) {
            it.replaceCurrentPoint(pt_not_zero);
        } else {
            it.replaceCurrentPoint(pt_zero);
        }
    }
    return pcir;
}

enum FilterMethod {
    FILTER_COPY_FIXED,
    FILTER_COPY_VARIABLE,
    FILTER_INPLACE,
};

void FilterpointsTest::testFilterBenchmark_data()
{
    QTest::addColumn<int>("filter_method");
    QTest::newRow("FILTER_COPY_FIXED") << (int)FILTER_COPY_FIXED;
    QTest::newRow("FILTER_COPY_VARIABLE") << (int)FILTER_COPY_VARIABLE;
    QTest::newRow("FILTER_INPLACE") << (int)FILTER_INPLACE;
}

void FilterpointsTest::testFilterBenchmark()
{
    QFETCH(int, filter_method);
    int n = 1E6;
    int mod = 10;
    CT_PCIR pcir = createPointCloud(n, mod);
    CT_PCIR result;

    switch(filter_method) {
    case FILTER_COPY_FIXED:
        QBENCHMARK_ONCE {
            result = filter_cloud_copy_fixed(
                        pcir, filter_not_origin);
        }
        QCOMPARE(result->size(), (size_t) n - (n / mod));
        break;
    case FILTER_COPY_VARIABLE:
        QBENCHMARK_ONCE {
            result = filter_cloud_copy_variable(
                        pcir, filter_not_origin);
        }
        QCOMPARE(result->size(), (size_t) n - (n / mod));
        break;
    case FILTER_INPLACE:
        QBENCHMARK_ONCE {
            result = filter_cloud_inplace(
                        pcir, filter_not_origin);
        }
        break;
    default:
        break;
    }
    // FIXME: uncomment once the resize works
    //QCOMPARE(result->size(), (unsigned long) n - (n / mod));
}

QTEST_APPLESS_MAIN(FilterpointsTest)

#include "tst_filterpointstest.moc"
