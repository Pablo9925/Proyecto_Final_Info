/****************************************************************************
** Meta object code from reading C++ file 'personaje.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Videojuego/personaje.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'personaje.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_personaje_t {
    QByteArrayData data[6];
    char stringdata0[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_personaje_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_personaje_t qt_meta_stringdata_personaje = {
    {
QT_MOC_LITERAL(0, 0, 9), // "personaje"
QT_MOC_LITERAL(1, 10, 8), // "disparar"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 8), // "apunalar"
QT_MOC_LITERAL(4, 29, 14), // "animacionsalto"
QT_MOC_LITERAL(5, 44, 12) // "muerte_anima"

    },
    "personaje\0disparar\0\0apunalar\0"
    "animacionsalto\0muerte_anima"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_personaje[] = {

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
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x0a /* Public */,
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void personaje::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        personaje *_t = static_cast<personaje *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->disparar(); break;
        case 1: _t->apunalar(); break;
        case 2: _t->animacionsalto(); break;
        case 3: _t->muerte_anima(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject personaje::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_personaje.data,
      qt_meta_data_personaje,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *personaje::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *personaje::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_personaje.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(this);
    return QObject::qt_metacast(_clname);
}

int personaje::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
