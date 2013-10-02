/****************************************************************************
** Meta object code from reading C++ file 'gameMaster.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../client/src/gameLogics/gameMaster.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gameMaster.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GameMaster_t {
    QByteArrayData data[11];
    char stringdata[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GameMaster_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GameMaster_t qt_meta_stringdata_GameMaster = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 19),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 7),
QT_MOC_LITERAL(4, 40, 6),
QT_MOC_LITERAL(5, 47, 9),
QT_MOC_LITERAL(6, 57, 14),
QT_MOC_LITERAL(7, 72, 2),
QT_MOC_LITERAL(8, 75, 12),
QT_MOC_LITERAL(9, 88, 10),
QT_MOC_LITERAL(10, 99, 8)
    },
    "GameMaster\0playerReadyToBattle\0\0Player*\0"
    "sender\0offerTurn\0informOpponent\0id\0"
    "AttackStatus\0turnResult\0nextTurn\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameMaster[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08,
       5,    0,   37,    2, 0x08,
       6,    2,   38,    2, 0x08,
      10,    1,   43,    2, 0x08,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 8,    7,    9,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void GameMaster::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameMaster *_t = static_cast<GameMaster *>(_o);
        switch (_id) {
        case 0: _t->playerReadyToBattle((*reinterpret_cast< Player*(*)>(_a[1]))); break;
        case 1: _t->offerTurn(); break;
        case 2: _t->informOpponent((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< AttackStatus(*)>(_a[2]))); break;
        case 3: _t->nextTurn((*reinterpret_cast< AttackStatus(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Player* >(); break;
            }
            break;
        }
    }
}

const QMetaObject GameMaster::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GameMaster.data,
      qt_meta_data_GameMaster,  qt_static_metacall, 0, 0}
};


const QMetaObject *GameMaster::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameMaster::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameMaster.stringdata))
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
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
