/****************************************************************************
** Meta object code from reading C++ file 'cell.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../client/src/view/cell.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cell.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Cell_t {
    QByteArrayData data[10];
    char stringdata[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Cell_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Cell_t qt_meta_stringdata_Cell = {
    {
QT_MOC_LITERAL(0, 0, 4),
QT_MOC_LITERAL(1, 5, 8),
QT_MOC_LITERAL(2, 14, 0),
QT_MOC_LITERAL(3, 15, 2),
QT_MOC_LITERAL(4, 18, 13),
QT_MOC_LITERAL(5, 32, 5),
QT_MOC_LITERAL(6, 38, 6),
QT_MOC_LITERAL(7, 45, 10),
QT_MOC_LITERAL(8, 56, 21),
QT_MOC_LITERAL(9, 78, 9)
    },
    "Cell\0attacked\0\0id\0getCoordinate\0first\0"
    "second\0deleteShip\0coordinatesOfMouseNow\0"
    "setArrows\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Cell[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x05,
       4,    2,   42,    2, 0x05,
       7,    1,   47,    2, 0x05,
       8,    1,   50,    2, 0x05,
       9,    1,   53,    2, 0x05,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QPointF, QMetaType::QPointF,    5,    6,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void Cell::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Cell *_t = static_cast<Cell *>(_o);
        switch (_id) {
        case 0: _t->attacked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->getCoordinate((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QPointF(*)>(_a[2]))); break;
        case 2: _t->deleteShip((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->coordinatesOfMouseNow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setArrows((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Cell::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Cell::attacked)) {
                *result = 0;
            }
        }
        {
            typedef void (Cell::*_t)(QPointF , QPointF );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Cell::getCoordinate)) {
                *result = 1;
            }
        }
        {
            typedef void (Cell::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Cell::deleteShip)) {
                *result = 2;
            }
        }
        {
            typedef void (Cell::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Cell::coordinatesOfMouseNow)) {
                *result = 3;
            }
        }
        {
            typedef void (Cell::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Cell::setArrows)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject Cell::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Cell.data,
      qt_meta_data_Cell,  qt_static_metacall, 0, 0}
};


const QMetaObject *Cell::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cell::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Cell.stringdata))
        return static_cast<void*>(const_cast< Cell*>(this));
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(const_cast< Cell*>(this));
    return QObject::qt_metacast(_clname);
}

int Cell::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Cell::attacked(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Cell::getCoordinate(QPointF _t1, QPointF _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Cell::deleteShip(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Cell::coordinatesOfMouseNow(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Cell::setArrows(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
