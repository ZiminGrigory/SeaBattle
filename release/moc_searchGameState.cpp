/****************************************************************************
** Meta object code from reading C++ file 'searchGameState.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../client/src/tcpClient/searchGameState.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'searchGameState.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SearchGameState_t {
    QByteArrayData data[8];
    char stringdata[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SearchGameState_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SearchGameState_t qt_meta_stringdata_SearchGameState = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 7),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 8),
QT_MOC_LITERAL(4, 34, 4),
QT_MOC_LITERAL(5, 39, 5),
QT_MOC_LITERAL(6, 45, 16),
QT_MOC_LITERAL(7, 62, 24)
    },
    "SearchGameState\0connect\0\0hostName\0"
    "port\0abort\0connectedHandler\0"
    "connectionTimeoutHandler\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SearchGameState[] = {

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
       1,    2,   34,    2, 0x0a,
       5,    0,   39,    2, 0x0a,
       6,    0,   40,    2, 0x08,
       7,    0,   41,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SearchGameState::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SearchGameState *_t = static_cast<SearchGameState *>(_o);
        switch (_id) {
        case 0: _t->connect((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 1: _t->abort(); break;
        case 2: _t->connectedHandler(); break;
        case 3: _t->connectionTimeoutHandler(); break;
        default: ;
        }
    }
}

const QMetaObject SearchGameState::staticMetaObject = {
    { &ClientState::staticMetaObject, qt_meta_stringdata_SearchGameState.data,
      qt_meta_data_SearchGameState,  qt_static_metacall, 0, 0}
};


const QMetaObject *SearchGameState::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SearchGameState::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SearchGameState.stringdata))
        return static_cast<void*>(const_cast< SearchGameState*>(this));
    return ClientState::qt_metacast(_clname);
}

int SearchGameState::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ClientState::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
