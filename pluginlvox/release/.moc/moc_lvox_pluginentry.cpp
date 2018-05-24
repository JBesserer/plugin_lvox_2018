/****************************************************************************
** Meta object code from reading C++ file 'lvox_pluginentry.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lvox_pluginentry.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lvox_pluginentry.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LVOX_PluginEntry_t {
    QByteArrayData data[1];
    char stringdata0[17];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LVOX_PluginEntry_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LVOX_PluginEntry_t qt_meta_stringdata_LVOX_PluginEntry = {
    {
QT_MOC_LITERAL(0, 0, 16) // "LVOX_PluginEntry"

    },
    "LVOX_PluginEntry"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LVOX_PluginEntry[] = {

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

void LVOX_PluginEntry::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject LVOX_PluginEntry::staticMetaObject = {
    { &PluginEntryInterface::staticMetaObject, qt_meta_stringdata_LVOX_PluginEntry.data,
      qt_meta_data_LVOX_PluginEntry,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LVOX_PluginEntry::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LVOX_PluginEntry::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LVOX_PluginEntry.stringdata0))
        return static_cast<void*>(const_cast< LVOX_PluginEntry*>(this));
    if (!strcmp(_clname, "com.krebs.michael.ONF.PluginSharedV2.PluginEntryInterface"))
        return static_cast< PluginEntryInterface*>(const_cast< LVOX_PluginEntry*>(this));
    return PluginEntryInterface::qt_metacast(_clname);
}

int LVOX_PluginEntry::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PluginEntryInterface::qt_metacall(_c, _id, _a);
    return _id;
}

QT_PLUGIN_METADATA_SECTION const uint qt_section_alignment_dummy = 42;

#ifdef QT_NO_DEBUG

QT_PLUGIN_METADATA_SECTION
static const unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', ' ',
    'q',  'b',  'j',  's',  0x01, 0x00, 0x00, 0x00,
    0xc4, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
    0xb0, 0x00, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x03, 0x00, 'I',  'I',  'D',  0x00, 0x00, 0x00,
    '9',  0x00, 'c',  'o',  'm',  '.',  'k',  'r', 
    'e',  'b',  's',  '.',  'm',  'i',  'c',  'h', 
    'a',  'e',  'l',  '.',  'O',  'N',  'F',  '.', 
    'P',  'l',  'u',  'g',  'i',  'n',  'S',  'h', 
    'a',  'r',  'e',  'd',  'V',  '2',  '.',  'P', 
    'l',  'u',  'g',  'i',  'n',  'E',  'n',  't', 
    'r',  'y',  'I',  'n',  't',  'e',  'r',  'f', 
    'a',  'c',  'e',  0x00, 0x9b, 0x0c, 0x00, 0x00,
    0x09, 0x00, 'c',  'l',  'a',  's',  's',  'N', 
    'a',  'm',  'e',  0x00, 0x10, 0x00, 'L',  'V', 
    'O',  'X',  '_',  'P',  'l',  'u',  'g',  'i', 
    'n',  'E',  'n',  't',  'r',  'y',  0x00, 0x00,
    ':',  ' ',  0xa1, 0x00, 0x07, 0x00, 'v',  'e', 
    'r',  's',  'i',  'o',  'n',  0x00, 0x00, 0x00,
    0x11, 0x00, 0x00, 0x00, 0x05, 0x00, 'd',  'e', 
    'b',  'u',  'g',  0x00, 0x95, 0x14, 0x00, 0x00,
    0x08, 0x00, 'M',  'e',  't',  'a',  'D',  'a', 
    't',  'a',  0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 0x94, 0x00, 0x00, 0x00,
    'T',  0x00, 0x00, 0x00, 0x88, 0x00, 0x00, 0x00,
    'x',  0x00, 0x00, 0x00
};

#else // QT_NO_DEBUG

QT_PLUGIN_METADATA_SECTION
static const unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', ' ',
    'q',  'b',  'j',  's',  0x01, 0x00, 0x00, 0x00,
    0xc4, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
    0xb0, 0x00, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x03, 0x00, 'I',  'I',  'D',  0x00, 0x00, 0x00,
    '9',  0x00, 'c',  'o',  'm',  '.',  'k',  'r', 
    'e',  'b',  's',  '.',  'm',  'i',  'c',  'h', 
    'a',  'e',  'l',  '.',  'O',  'N',  'F',  '.', 
    'P',  'l',  'u',  'g',  'i',  'n',  'S',  'h', 
    'a',  'r',  'e',  'd',  'V',  '2',  '.',  'P', 
    'l',  'u',  'g',  'i',  'n',  'E',  'n',  't', 
    'r',  'y',  'I',  'n',  't',  'e',  'r',  'f', 
    'a',  'c',  'e',  0x00, 0x95, 0x0c, 0x00, 0x00,
    0x08, 0x00, 'M',  'e',  't',  'a',  'D',  'a', 
    't',  'a',  0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x1b, 0x10, 0x00, 0x00, 0x09, 0x00, 'c',  'l', 
    'a',  's',  's',  'N',  'a',  'm',  'e',  0x00,
    0x10, 0x00, 'L',  'V',  'O',  'X',  '_',  'P', 
    'l',  'u',  'g',  'i',  'n',  'E',  'n',  't', 
    'r',  'y',  0x00, 0x00, '1',  0x00, 0x00, 0x00,
    0x05, 0x00, 'd',  'e',  'b',  'u',  'g',  0x00,
    ':',  ' ',  0xa1, 0x00, 0x07, 0x00, 'v',  'e', 
    'r',  's',  'i',  'o',  'n',  0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 'T',  0x00, 0x00, 0x00,
    'p',  0x00, 0x00, 0x00, 0x94, 0x00, 0x00, 0x00,
    0xa0, 0x00, 0x00, 0x00
};
#endif // QT_NO_DEBUG

QT_MOC_EXPORT_PLUGIN(LVOX_PluginEntry, LVOX_PluginEntry)

QT_WARNING_POP
QT_END_MOC_NAMESPACE
