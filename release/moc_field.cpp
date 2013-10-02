/****************************************************************************
** Meta object code from reading C++ file 'field.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../client/src/view/field.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'field.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Field_t {
    QByteArrayData data[20];
    char stringdata[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Field_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Field_t qt_meta_stringdata_Field = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 6),
QT_MOC_LITERAL(2, 13, 0),
QT_MOC_LITERAL(3, 14, 2),
QT_MOC_LITERAL(4, 17, 9),
QT_MOC_LITERAL(5, 27, 7),
QT_MOC_LITERAL(6, 35, 8),
QT_MOC_LITERAL(7, 44, 10),
QT_MOC_LITERAL(8, 55, 14),
QT_MOC_LITERAL(9, 70, 12),
QT_MOC_LITERAL(10, 83, 16),
QT_MOC_LITERAL(11, 100, 8),
QT_MOC_LITERAL(12, 109, 7),
QT_MOC_LITERAL(13, 117, 8),
QT_MOC_LITERAL(14, 126, 7),
QT_MOC_LITERAL(15, 134, 13),
QT_MOC_LITERAL(16, 148, 5),
QT_MOC_LITERAL(17, 154, 6),
QT_MOC_LITERAL(18, 161, 16),
QT_MOC_LITERAL(19, 178, 13)
    },
    "Field\0attack\0\0id\0placeShip\0firstId\0"
    "secondId\0deleteShip\0setFirstArrows\0"
    "setNextArrow\0setEnabledItself\0switcher\0"
    "repaint\0Textures\0texture\0getCoordinate\0"
    "first\0second\0deleteShipOnCell\0"
    "deleteMessage\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Field[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x05,
       4,    2,   67,    2, 0x05,
       7,    1,   72,    2, 0x05,
       8,    1,   75,    2, 0x05,
       9,    1,   78,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
      10,    1,   81,    2, 0x0a,
      12,    2,   84,    2, 0x0a,
      15,    2,   89,    2, 0x08,
      18,    1,   94,    2, 0x08,
      19,    0,   97,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 13,    3,   14,
    QMetaType::Void, QMetaType::QPointF, QMetaType::QPointF,   16,   17,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

       0        // eod
};

void Field::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Field *_t = static_cast<Field *>(_o);
        switch (_id) {
        case 0: _t->attack((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->placeShip((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->deleteShip((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setFirstArrows((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setNextArrow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setEnabledItself((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->repaint((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Textures(*)>(_a[2]))); break;
        case 7: _t->getCoordinate((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2]))); break;
        case 8: _t->deleteShipOnCell((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->deleteMessage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Field::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Field::attack)) {
                *result = 0;
            }
        }
        {
            typedef void (Field::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Field::placeShip)) {
                *result = 1;
            }
        }
        {
            typedef void (Field::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Field::deleteShip)) {
                *result = 2;
            }
        }
        {
            typedef void (Field::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Field::setFirstArrows)) {
                *result = 3;
            }
        }
        {
            typedef void (Field::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Field::setNextArrow)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject Field::staticMetaObject = {
    { &InterfaceField::staticMetaObject, qt_meta_stringdata_Field.data,
      qt_meta_data_Field,  qt_static_metacall, 0, 0}
};


const QMetaObject *Field::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Field::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Field.stringdata))
        return static_cast<void*>(const_cast< Field*>(this));
    return InterfaceField::qt_metacast(_clname);
}

int Field::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = InterfaceField::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Field::attack(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Field::placeShip(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Field::deleteShip(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Field::setFirstArrows(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Field::setNextArrow(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
