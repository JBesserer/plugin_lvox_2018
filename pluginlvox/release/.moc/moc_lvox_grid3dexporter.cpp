/****************************************************************************
** Meta object code from reading C++ file 'lvox_grid3dexporter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../tools/lvox_grid3dexporter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lvox_grid3dexporter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LVOX_Grid3DExporter_t {
    QByteArrayData data[1];
    char stringdata0[20];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LVOX_Grid3DExporter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LVOX_Grid3DExporter_t qt_meta_stringdata_LVOX_Grid3DExporter = {
    {
QT_MOC_LITERAL(0, 0, 19) // "LVOX_Grid3DExporter"

    },
    "LVOX_Grid3DExporter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LVOX_Grid3DExporter[] = {

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

void LVOX_Grid3DExporter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject LVOX_Grid3DExporter::staticMetaObject = {
    { &CT_AbstractExporter::staticMetaObject, qt_meta_stringdata_LVOX_Grid3DExporter.data,
      qt_meta_data_LVOX_Grid3DExporter,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LVOX_Grid3DExporter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LVOX_Grid3DExporter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LVOX_Grid3DExporter.stringdata0))
        return static_cast<void*>(const_cast< LVOX_Grid3DExporter*>(this));
    return CT_AbstractExporter::qt_metacast(_clname);
}

int LVOX_Grid3DExporter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CT_AbstractExporter::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
