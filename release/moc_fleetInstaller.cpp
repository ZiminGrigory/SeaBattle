/****************************************************************************
** Meta object code from reading C++ file 'fleetInstaller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../client/src/gameLogics/fleetInstaller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fleetInstaller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FleetInstaller_t {
    QByteArrayData data[21];
    char stringdata[231];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_FleetInstaller_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_FleetInstaller_t qt_meta_stringdata_FleetInstaller = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 15),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 15),
QT_MOC_LITERAL(4, 48, 3),
QT_MOC_LITERAL(5, 52, 14),
QT_MOC_LITERAL(6, 67, 16),
QT_MOC_LITERAL(7, 84, 6),
QT_MOC_LITERAL(8, 91, 10),
QT_MOC_LITERAL(9, 102, 7),
QT_MOC_LITERAL(10, 110, 8),
QT_MOC_LITERAL(11, 119, 2),
QT_MOC_LITERAL(12, 122, 4),
QT_MOC_LITERAL(13, 127, 11),
QT_MOC_LITERAL(14, 139, 10),
QT_MOC_LITERAL(15, 150, 17),
QT_MOC_LITERAL(16, 168, 2),
QT_MOC_LITERAL(17, 171, 21),
QT_MOC_LITERAL(18, 193, 8),
QT_MOC_LITERAL(19, 202, 13),
QT_MOC_LITERAL(20, 216, 13)
    },
    "FleetInstaller\0placementResult\0\0"
    "PlacementStatus\0res\0fleetInstalled\0"
    "QVector<ptrShip>\0_fleet\0shipPlaced\0"
    "firstId\0secondId\0id\0size\0orientation\0"
    "deleteShip\0checkIsFleetReady\0OK\0"
    "UNCORRECT_COORDINATES\0NOT_LINE\0"
    "HAVE_NOT_SHIP\0CELL_OCCUPIED\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FleetInstaller[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       1,   66, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x05,
       5,    1,   47,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       8,    2,   50,    2, 0x0a,
       8,    3,   55,    2, 0x0a,
      14,    1,   62,    2, 0x0a,
      15,    0,   65,    2, 0x08,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    0x80000000 | 3, QMetaType::Int, QMetaType::Int,    9,   10,
    0x80000000 | 3, QMetaType::Int, QMetaType::Int, QMetaType::Bool,   11,   12,   13,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Bool,

 // enums: name, flags, count, data
       3, 0x0,    5,   70,

 // enum data: key, value
      16, uint(FleetInstaller::OK),
      17, uint(FleetInstaller::UNCORRECT_COORDINATES),
      18, uint(FleetInstaller::NOT_LINE),
      19, uint(FleetInstaller::HAVE_NOT_SHIP),
      20, uint(FleetInstaller::CELL_OCCUPIED),

       0        // eod
};

void FleetInstaller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FleetInstaller *_t = static_cast<FleetInstaller *>(_o);
        switch (_id) {
        case 0: _t->placementResult((*reinterpret_cast< PlacementStatus(*)>(_a[1]))); break;
        case 1: _t->fleetInstalled((*reinterpret_cast< QVector<ptrShip>(*)>(_a[1]))); break;
        case 2: { PlacementStatus _r = _t->shipPlaced((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< PlacementStatus*>(_a[0]) = _r; }  break;
        case 3: { PlacementStatus _r = _t->shipPlaced((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< PlacementStatus*>(_a[0]) = _r; }  break;
        case 4: _t->deleteShip((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: { bool _r = _t->checkIsFleetReady();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FleetInstaller::*_t)(PlacementStatus );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FleetInstaller::placementResult)) {
                *result = 0;
            }
        }
        {
            typedef void (FleetInstaller::*_t)(QVector<ptrShip> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FleetInstaller::fleetInstalled)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject FleetInstaller::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FleetInstaller.data,
      qt_meta_data_FleetInstaller,  qt_static_metacall, 0, 0}
};


const QMetaObject *FleetInstaller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FleetInstaller::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FleetInstaller.stringdata))
        return static_cast<void*>(const_cast< FleetInstaller*>(this));
    return QObject::qt_metacast(_clname);
}

int FleetInstaller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void FleetInstaller::placementResult(PlacementStatus _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FleetInstaller::fleetInstalled(QVector<ptrShip> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
