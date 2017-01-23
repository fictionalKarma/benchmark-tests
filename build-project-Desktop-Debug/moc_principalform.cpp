/****************************************************************************
** Meta object code from reading C++ file 'principalform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ProjPOO/principalform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'principalform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_principalForm_t {
    QByteArrayData data[10];
    char stringdata[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_principalForm_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_principalForm_t qt_meta_stringdata_principalForm = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 23),
QT_MOC_LITERAL(2, 38, 0),
QT_MOC_LITERAL(3, 39, 21),
QT_MOC_LITERAL(4, 61, 23),
QT_MOC_LITERAL(5, 85, 7),
QT_MOC_LITERAL(6, 93, 12),
QT_MOC_LITERAL(7, 106, 30),
QT_MOC_LITERAL(8, 137, 24),
QT_MOC_LITERAL(9, 162, 26)
    },
    "principalForm\0on_pushButton_4_clicked\0"
    "\0on_pushButton_clicked\0on_pushButton_2_clicked\0"
    "checked\0handleButton\0"
    "on_pushButton_4_button_clicked\0"
    "hasNoChildren_actualBoss\0"
    "on_previous_button_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_principalForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08,
       3,    0,   55,    2, 0x08,
       4,    0,   56,    2, 0x08,
       4,    1,   57,    2, 0x08,
       6,    0,   60,    2, 0x08,
       7,    0,   61,    2, 0x08,
       8,    0,   62,    2, 0x08,
       9,    0,   63,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,

       0        // eod
};

void principalForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        principalForm *_t = static_cast<principalForm *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_4_clicked(); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->on_pushButton_2_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->handleButton(); break;
        case 5: _t->on_pushButton_4_button_clicked(); break;
        case 6: { bool _r = _t->hasNoChildren_actualBoss();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: _t->on_previous_button_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject principalForm::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_principalForm.data,
      qt_meta_data_principalForm,  qt_static_metacall, 0, 0}
};


const QMetaObject *principalForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *principalForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_principalForm.stringdata))
        return static_cast<void*>(const_cast< principalForm*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int principalForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
