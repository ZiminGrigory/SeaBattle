/****************************************************************************
** Meta object code from reading C++ file 'gameMaster.h'
**
** Created: Mon 2. Sep 19:29:36 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/gameMaster.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gameMaster.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GameMaster[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      27,   24,   11,   11, 0x0a,
      60,   47,   11,   11, 0x0a,
      98,   87,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GameMaster[] = {
    "GameMaster\0\0offerTurn()\0id\0"
    "informOpponent(int)\0attackResult\0"
    "informPlayer(AttackStatus)\0turnResult\0"
    "nextTurn(AttackStatus)\0"
};

void GameMaster::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GameMaster *_t = static_cast<GameMaster *>(_o);
        switch (_id) {
        case 0: _t->offerTurn(); break;
        case 1: _t->informOpponent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->informPlayer((*reinterpret_cast< AttackStatus(*)>(_a[1]))); break;
        case 3: _t->nextTurn((*reinterpret_cast< AttackStatus(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GameMaster::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GameMaster::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GameMaster,
      qt_meta_data_GameMaster, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GameMaster::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GameMaster::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GameMaster::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameMaster))
        return static_cast<void*>(const_cast< GameMaster*>(this));
    return QObject::qt_metacast(_clname);
}

int GameMaster::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
