/****************************************************************************
** Meta object code from reading C++ file 'interfaces.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../computreev5/pluginshared/interfaces.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'interfaces.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OctreeInterface_t {
    QByteArrayData data[5];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OctreeInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OctreeInterface_t qt_meta_stringdata_OctreeInterface = {
    {
QT_MOC_LITERAL(0, 0, 15), // "OctreeInterface"
QT_MOC_LITERAL(1, 16, 25), // "octreeMustBeReconstructed"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 3), // "val"
QT_MOC_LITERAL(4, 47, 22) // "constructionInProgress"

    },
    "OctreeInterface\0octreeMustBeReconstructed\0"
    "\0val\0constructionInProgress"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OctreeInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       4,    1,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void OctreeInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OctreeInterface *_t = static_cast<OctreeInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->octreeMustBeReconstructed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->constructionInProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (OctreeInterface::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OctreeInterface::octreeMustBeReconstructed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (OctreeInterface::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OctreeInterface::constructionInProgress)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject OctreeInterface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_OctreeInterface.data,
      qt_meta_data_OctreeInterface,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *OctreeInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OctreeInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OctreeInterface.stringdata0))
        return static_cast<void*>(const_cast< OctreeInterface*>(this));
    return QObject::qt_metacast(_clname);
}

int OctreeInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void OctreeInterface::octreeMustBeReconstructed(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void OctreeInterface::constructionInProgress(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_CameraInterface_t {
    QByteArrayData data[49];
    char stringdata0[492];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CameraInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CameraInterface_t qt_meta_stringdata_CameraInterface = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CameraInterface"
QT_MOC_LITERAL(1, 16, 18), // "coordinatesChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 4), // "setX"
QT_MOC_LITERAL(4, 41, 1), // "x"
QT_MOC_LITERAL(5, 43, 4), // "setY"
QT_MOC_LITERAL(6, 48, 1), // "y"
QT_MOC_LITERAL(7, 50, 4), // "setZ"
QT_MOC_LITERAL(8, 55, 1), // "z"
QT_MOC_LITERAL(9, 57, 5), // "setCX"
QT_MOC_LITERAL(10, 63, 2), // "cx"
QT_MOC_LITERAL(11, 66, 5), // "setCY"
QT_MOC_LITERAL(12, 72, 2), // "cy"
QT_MOC_LITERAL(13, 75, 5), // "setCZ"
QT_MOC_LITERAL(14, 81, 2), // "cz"
QT_MOC_LITERAL(15, 84, 5), // "setRX"
QT_MOC_LITERAL(16, 90, 4), // "xRot"
QT_MOC_LITERAL(17, 95, 5), // "setRY"
QT_MOC_LITERAL(18, 101, 4), // "yRot"
QT_MOC_LITERAL(19, 106, 5), // "setRZ"
QT_MOC_LITERAL(20, 112, 4), // "zRot"
QT_MOC_LITERAL(21, 117, 7), // "setType"
QT_MOC_LITERAL(22, 125, 27), // "CameraInterface::CameraType"
QT_MOC_LITERAL(23, 153, 4), // "type"
QT_MOC_LITERAL(24, 158, 11), // "setPosition"
QT_MOC_LITERAL(25, 170, 10), // "redrawView"
QT_MOC_LITERAL(26, 181, 14), // "setSceneCenter"
QT_MOC_LITERAL(27, 196, 16), // "setViewDirection"
QT_MOC_LITERAL(28, 213, 2), // "rx"
QT_MOC_LITERAL(29, 216, 2), // "ry"
QT_MOC_LITERAL(30, 219, 2), // "rz"
QT_MOC_LITERAL(31, 222, 14), // "setOrientation"
QT_MOC_LITERAL(32, 237, 2), // "q0"
QT_MOC_LITERAL(33, 240, 2), // "q1"
QT_MOC_LITERAL(34, 243, 2), // "q2"
QT_MOC_LITERAL(35, 246, 2), // "q3"
QT_MOC_LITERAL(36, 249, 15), // "showEntireScene"
QT_MOC_LITERAL(37, 265, 12), // "homePosition"
QT_MOC_LITERAL(38, 278, 18), // "alignCameraToXAxis"
QT_MOC_LITERAL(39, 297, 18), // "alignCameraToYAxis"
QT_MOC_LITERAL(40, 316, 18), // "alignCameraToZAxis"
QT_MOC_LITERAL(41, 335, 16), // "initCameraCenter"
QT_MOC_LITERAL(42, 352, 32), // "fixCameraCenterToItemsBarycenter"
QT_MOC_LITERAL(43, 385, 40), // "fixCameraCenterToSelectedItem..."
QT_MOC_LITERAL(44, 426, 23), // "fitCameraToVisibleItems"
QT_MOC_LITERAL(45, 450, 17), // "fitToSpecifiedBox"
QT_MOC_LITERAL(46, 468, 15), // "Eigen::Vector3d"
QT_MOC_LITERAL(47, 484, 3), // "bot"
QT_MOC_LITERAL(48, 488, 3) // "top"

    },
    "CameraInterface\0coordinatesChanged\0\0"
    "setX\0x\0setY\0y\0setZ\0z\0setCX\0cx\0setCY\0"
    "cy\0setCZ\0cz\0setRX\0xRot\0setRY\0yRot\0"
    "setRZ\0zRot\0setType\0CameraInterface::CameraType\0"
    "type\0setPosition\0redrawView\0setSceneCenter\0"
    "setViewDirection\0rx\0ry\0rz\0setOrientation\0"
    "q0\0q1\0q2\0q3\0showEntireScene\0homePosition\0"
    "alignCameraToXAxis\0alignCameraToYAxis\0"
    "alignCameraToZAxis\0initCameraCenter\0"
    "fixCameraCenterToItemsBarycenter\0"
    "fixCameraCenterToSelectedItemsBarycenter\0"
    "fitCameraToVisibleItems\0fitToSpecifiedBox\0"
    "Eigen::Vector3d\0bot\0top"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CameraInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      29,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  159,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,  160,    2, 0x0a /* Public */,
       5,    1,  163,    2, 0x0a /* Public */,
       7,    1,  166,    2, 0x0a /* Public */,
       9,    1,  169,    2, 0x0a /* Public */,
      11,    1,  172,    2, 0x0a /* Public */,
      13,    1,  175,    2, 0x0a /* Public */,
      15,    1,  178,    2, 0x0a /* Public */,
      17,    1,  181,    2, 0x0a /* Public */,
      19,    1,  184,    2, 0x0a /* Public */,
      21,    1,  187,    2, 0x0a /* Public */,
      24,    4,  190,    2, 0x0a /* Public */,
      24,    3,  199,    2, 0x2a /* Public | MethodCloned */,
      26,    4,  206,    2, 0x0a /* Public */,
      26,    3,  215,    2, 0x2a /* Public | MethodCloned */,
      27,    4,  222,    2, 0x0a /* Public */,
      27,    3,  231,    2, 0x2a /* Public | MethodCloned */,
      31,    5,  238,    2, 0x0a /* Public */,
      31,    4,  249,    2, 0x2a /* Public | MethodCloned */,
      36,    0,  258,    2, 0x0a /* Public */,
      37,    0,  259,    2, 0x0a /* Public */,
      38,    0,  260,    2, 0x0a /* Public */,
      39,    0,  261,    2, 0x0a /* Public */,
      40,    0,  262,    2, 0x0a /* Public */,
      41,    0,  263,    2, 0x0a /* Public */,
      42,    0,  264,    2, 0x0a /* Public */,
      43,    0,  265,    2, 0x0a /* Public */,
      44,    0,  266,    2, 0x0a /* Public */,
      45,    2,  267,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Double,   10,
    QMetaType::Void, QMetaType::Double,   12,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void, QMetaType::Double,   18,
    QMetaType::Void, QMetaType::Double,   20,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Bool,    4,    6,    8,   25,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    4,    6,    8,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Bool,   10,   12,   14,   25,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,   10,   12,   14,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Bool,   28,   29,   30,   25,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,   28,   29,   30,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Bool,   32,   33,   34,   35,   25,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,   32,   33,   34,   35,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 46, 0x80000000 | 46,   47,   48,

       0        // eod
};

void CameraInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CameraInterface *_t = static_cast<CameraInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->coordinatesChanged(); break;
        case 1: _t->setX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->setY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->setZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->setCX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->setCY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->setCZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->setRX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->setRY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->setRZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->setType((*reinterpret_cast< CameraInterface::CameraType(*)>(_a[1]))); break;
        case 11: _t->setPosition((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 12: _t->setPosition((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 13: _t->setSceneCenter((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 14: _t->setSceneCenter((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 15: _t->setViewDirection((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 16: _t->setViewDirection((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 17: _t->setOrientation((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 18: _t->setOrientation((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 19: _t->showEntireScene(); break;
        case 20: _t->homePosition(); break;
        case 21: _t->alignCameraToXAxis(); break;
        case 22: _t->alignCameraToYAxis(); break;
        case 23: _t->alignCameraToZAxis(); break;
        case 24: _t->initCameraCenter(); break;
        case 25: _t->fixCameraCenterToItemsBarycenter(); break;
        case 26: _t->fixCameraCenterToSelectedItemsBarycenter(); break;
        case 27: _t->fitCameraToVisibleItems(); break;
        case 28: _t->fitToSpecifiedBox((*reinterpret_cast< const Eigen::Vector3d(*)>(_a[1])),(*reinterpret_cast< const Eigen::Vector3d(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CameraInterface::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CameraInterface::coordinatesChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CameraInterface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CameraInterface.data,
      qt_meta_data_CameraInterface,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CameraInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CameraInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CameraInterface.stringdata0))
        return static_cast<void*>(const_cast< CameraInterface*>(this));
    return QObject::qt_metacast(_clname);
}

int CameraInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 29)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 29;
    }
    return _id;
}

// SIGNAL 0
void CameraInterface::coordinatesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_GraphicsViewSignalEmitterInterface_t {
    QByteArrayData data[4];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GraphicsViewSignalEmitterInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GraphicsViewSignalEmitterInterface_t qt_meta_stringdata_GraphicsViewSignalEmitterInterface = {
    {
QT_MOC_LITERAL(0, 0, 34), // "GraphicsViewSignalEmitterInte..."
QT_MOC_LITERAL(1, 35, 14), // "drawingStarted"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 15) // "drawingFinished"

    },
    "GraphicsViewSignalEmitterInterface\0"
    "drawingStarted\0\0drawingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphicsViewSignalEmitterInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,
       3,    0,   25,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GraphicsViewSignalEmitterInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GraphicsViewSignalEmitterInterface *_t = static_cast<GraphicsViewSignalEmitterInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->drawingStarted(); break;
        case 1: _t->drawingFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GraphicsViewSignalEmitterInterface::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicsViewSignalEmitterInterface::drawingStarted)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GraphicsViewSignalEmitterInterface::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicsViewSignalEmitterInterface::drawingFinished)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject GraphicsViewSignalEmitterInterface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GraphicsViewSignalEmitterInterface.data,
      qt_meta_data_GraphicsViewSignalEmitterInterface,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GraphicsViewSignalEmitterInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphicsViewSignalEmitterInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GraphicsViewSignalEmitterInterface.stringdata0))
        return static_cast<void*>(const_cast< GraphicsViewSignalEmitterInterface*>(this));
    return QObject::qt_metacast(_clname);
}

int GraphicsViewSignalEmitterInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void GraphicsViewSignalEmitterInterface::drawingStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GraphicsViewSignalEmitterInterface::drawingFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
struct qt_meta_stringdata_DocumentInterface_t {
    QByteArrayData data[3];
    char stringdata0[43];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DocumentInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DocumentInterface_t qt_meta_stringdata_DocumentInterface = {
    {
QT_MOC_LITERAL(0, 0, 17), // "DocumentInterface"
QT_MOC_LITERAL(1, 18, 23), // "constructOctreeOfPoints"
QT_MOC_LITERAL(2, 42, 0) // ""

    },
    "DocumentInterface\0constructOctreeOfPoints\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DocumentInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void DocumentInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DocumentInterface *_t = static_cast<DocumentInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->constructOctreeOfPoints(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject DocumentInterface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DocumentInterface.data,
      qt_meta_data_DocumentInterface,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DocumentInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DocumentInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DocumentInterface.stringdata0))
        return static_cast<void*>(const_cast< DocumentInterface*>(this));
    return QObject::qt_metacast(_clname);
}

int DocumentInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_PluginEntryInterface_t {
    QByteArrayData data[1];
    char stringdata0[21];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PluginEntryInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PluginEntryInterface_t qt_meta_stringdata_PluginEntryInterface = {
    {
QT_MOC_LITERAL(0, 0, 20) // "PluginEntryInterface"

    },
    "PluginEntryInterface"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PluginEntryInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void PluginEntryInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject PluginEntryInterface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PluginEntryInterface.data,
      qt_meta_data_PluginEntryInterface,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PluginEntryInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PluginEntryInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PluginEntryInterface.stringdata0))
        return static_cast<void*>(const_cast< PluginEntryInterface*>(this));
    return QObject::qt_metacast(_clname);
}

int PluginEntryInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
