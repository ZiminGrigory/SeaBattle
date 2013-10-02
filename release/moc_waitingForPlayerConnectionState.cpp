/****************************************************************************
** Meta object code from reading C++ file 'waitingForPlayerConnectionState.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../client/src/tcpClient/waitingForPlayerConnectionState.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'waitingForPlayerConnectionState.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WaitingForPlayerConnectionState_t {
    QByteArrayData data[11];
    char stringdata[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_WaitingForPlayerConnectionState_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_WaitingForPlayerConnectionState_t qt_meta_stringdata_WaitingForPlayerConnectionState = {
    {
QT_MOC_LITERAL(0, 0, 31),
QT_MOC_LITERAL(1, 32, 19),
QT_MOC_LITERAL(2, 52, 0),
QT_MOC_LITERAL(3, 53, 7),
QT_MOC_LITERAL(4, 61, 8),
QT_MOC_LITERAL(5, 70, 4),
QT_MOC_LITERAL(6, 75, 5),
QT_MOC_LITERAL(7, 81, 16),
QT_MOC_LITERAL(8, 98, 12),
QT_MOC_LITERAL(9, 111, 28),
QT_MOC_LITERAL(10, 140, 3)
    },
    "WaitingForPlayerConnectionState\0"
    "connectedWithPlayer\0\0connect\0hostName\0"
    "port\0abort\0connectedHandler\0errorHandler\0"
    "QAbstractSocket::SocketError\0err\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WaitingForPlayerConnectionState[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       3,    2,   40,    2, 0x0a,
       6,    0,   45,    2, 0x0a,
       7,    0,   46,    2, 0x08,
       8,    1,   47,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void WaitingForPlayerConnectionState::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WaitingForPlayerConnectionState *_t = static_cast<WaitingForPlayerConnectionState *>(_o);
        switch (_id) {
        case 0: _t->connectedWithPlayer(); break;
        case 1: _t->connect((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 2: _t->abort(); break;
        case 3: _t->connectedHandler(); break;
        case 4: _t->errorHandler((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WaitingForPlayerConnectionState::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WaitingForPlayerConnectionState::connectedWithPlayer)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject WaitingForPlayerConnectionState::staticMetaObject = {
    { &ClientState::staticMetaObject, qt_meta_stringdata_WaitingForPlayerConnectionState.data,
      qt_meta_data_WaitingForPlayerConnectionState,  qt_static_metacall, 0, 0}
};


const QMetaObject *WaitingForPlayerConnectionState::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WaitingForPlayerConnectionState::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WaitingForPlayerConnectionState.stringdata))
        return static_cast<void*>(const_cast< WaitingForPlayerConnectionState*>(this));
    return ClientState::qt_metacast(_clname);
}

int WaitingForPlayerConnectionState::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ClientState::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void WaitingForPlayerConnectionState::connectedWithPlayer()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
