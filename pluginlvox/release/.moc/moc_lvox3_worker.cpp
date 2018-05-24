/****************************************************************************
** Meta object code from reading C++ file 'lvox3_worker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mk/tools/worker/lvox3_worker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lvox3_worker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LVOX3_Worker_t {
    QByteArrayData data[8];
    char stringdata0[79];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LVOX3_Worker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LVOX3_Worker_t qt_meta_stringdata_LVOX3_Worker = {
    {
QT_MOC_LITERAL(0, 0, 12), // "LVOX3_Worker"
QT_MOC_LITERAL(1, 13, 15), // "progressChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 8), // "progress"
QT_MOC_LITERAL(4, 39, 15), // "cancelRequested"
QT_MOC_LITERAL(5, 55, 8), // "finished"
QT_MOC_LITERAL(6, 64, 7), // "compute"
QT_MOC_LITERAL(7, 72, 6) // "cancel"

    },
    "LVOX3_Worker\0progressChanged\0\0progress\0"
    "cancelRequested\0finished\0compute\0"
    "cancel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LVOX3_Worker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    0,   42,    2, 0x06 /* Public */,
       5,    0,   43,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   44,    2, 0x0a /* Public */,
       7,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LVOX3_Worker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LVOX3_Worker *_t = static_cast<LVOX3_Worker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->progressChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->cancelRequested(); break;
        case 2: _t->finished(); break;
        case 3: _t->compute(); break;
        case 4: _t->cancel(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LVOX3_Worker::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LVOX3_Worker::progressChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (LVOX3_Worker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LVOX3_Worker::cancelRequested)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (LVOX3_Worker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LVOX3_Worker::finished)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject LVOX3_Worker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LVOX3_Worker.data,
      qt_meta_data_LVOX3_Worker,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LVOX3_Worker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LVOX3_Worker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LVOX3_Worker.stringdata0))
        return static_cast<void*>(const_cast< LVOX3_Worker*>(this));
    return QObject::qt_metacast(_clname);
}

int LVOX3_Worker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void LVOX3_Worker::progressChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LVOX3_Worker::cancelRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void LVOX3_Worker::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
