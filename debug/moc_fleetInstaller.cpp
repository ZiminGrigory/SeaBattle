/****************************************************************************
** Meta object code from reading C++ file 'fleetInstaller.h'
**
** Created: Mon 2. Sep 19:29:36 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/fleetInstaller.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fleetInstaller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FleetInstaller[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       1,   24, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      20,   16,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      59,   53,   15,   15, 0x0a,

 // enums: name, flags, count, data
      80, 0x0,    5,   28,

 // enum data: key, value
      96, uint(FleetInstaller::OK),
      99, uint(FleetInstaller::UNCORRECT_COORDINATES),
     121, uint(FleetInstaller::NOT_LINE),
     130, uint(FleetInstaller::HAVE_NOT_SHIP),
     144, uint(FleetInstaller::CELL_OCCUPIED),

       0        // eod
};

static const char qt_meta_stringdata_FleetInstaller[] = {
    "FleetInstaller\0\0res\0"
    "placementResult(PlacementStatus)\0cells\0"
    "shipPlaced(CellPair)\0PlacementStatus\0"
    "OK\0UNCORRECT_COORDINATES\0NOT_LINE\0"
    "HAVE_NOT_SHIP\0CELL_OCCUPIED\0"
};

void FleetInstaller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        FleetInstaller *_t = static_cast<FleetInstaller *>(_o);
        switch (_id) {
        case 0: _t->placementResult((*reinterpret_cast< PlacementStatus(*)>(_a[1]))); break;
        case 1: _t->shipPlaced((*reinterpret_cast< CellPair(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData FleetInstaller::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject FleetInstaller::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FleetInstaller,
      qt_meta_data_FleetInstaller, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FleetInstaller::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FleetInstaller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FleetInstaller::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FleetInstaller))
        return static_cast<void*>(const_cast< FleetInstaller*>(this));
    return QObject::qt_metacast(_clname);
}

int FleetInstaller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void FleetInstaller::placementResult(PlacementStatus _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
