/****************************************************************************
** Meta object code from reading C++ file 'client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../client/src/tcpClient/client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Client_t {
    QByteArrayData data[13];
    char stringdata[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Client_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Client_t qt_meta_stringdata_Client = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 19),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 19),
QT_MOC_LITERAL(4, 48, 5),
QT_MOC_LITERAL(5, 54, 7),
QT_MOC_LITERAL(6, 62, 8),
QT_MOC_LITERAL(7, 71, 21),
QT_MOC_LITERAL(8, 93, 4),
QT_MOC_LITERAL(9, 98, 5),
QT_MOC_LITERAL(10, 104, 15),
QT_MOC_LITERAL(11, 120, 5),
QT_MOC_LITERAL(12, 126, 4)
    },
    "Client\0connectedWithServer\0\0"
    "connectedWithPlayer\0error\0message\0"
    "received\0Protocol::RequestType\0type\0"
    "bytes\0connectToServer\0abort\0send\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Client[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x05,
       3,    0,   50,    2, 0x05,
       4,    1,   51,    2, 0x05,
       6,    2,   54,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
      10,    0,   59,    2, 0x0a,
      11,    0,   60,    2, 0x0a,
      12,    2,   61,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, 0x80000000 | 7, QMetaType::QByteArray,    8,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7, QMetaType::QByteArray,    8,    9,

       0        // eod
};

void Client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Client *_t = static_cast<Client *>(_o);
        switch (_id) {
        case 0: _t->connectedWithServer(); break;
        case 1: _t->connectedWithPlayer(); break;
        case 2: _t->error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->received((*reinterpret_cast< Protocol::RequestType(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        case 4: _t->connectToServer(); break;
        case 5: _t->abort(); break;
        case 6: _t->send((*reinterpret_cast< Protocol::RequestType(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Client::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::connectedWithServer)) {
                *result = 0;
            }
        }
        {
            typedef void (Client::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::connectedWithPlayer)) {
                *result = 1;
            }
        }
        {
            typedef void (Client::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::error)) {
                *result = 2;
            }
        }
        {
            typedef void (Client::*_t)(Protocol::RequestType , const QByteArray & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::received)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Client::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Client.data,
      qt_meta_data_Client,  qt_static_metacall, 0, 0}
};


const QMetaObject *Client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Client::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Client.stringdata))
        return static_cast<void*>(const_cast< Client*>(this));
    return QObject::qt_metacast(_clname);
}

int Client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Client::connectedWithServer()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Client::connectedWithPlayer()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Client::error(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Client::received(Protocol::RequestType _t1, const QByteArray & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
