/****************************************************************************
** Meta object code from reading C++ file 'Myplay.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Myplay.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Myplay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Myplay[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,
      34,   22,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      50,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Myplay[] = {
    "Myplay\0\0Time_change()\0Length_medi\0"
    "start_Play(int)\0on_timeout_change_time_str()\0"
};

void Myplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Myplay *_t = static_cast<Myplay *>(_o);
        switch (_id) {
        case 0: _t->Time_change(); break;
        case 1: _t->start_Play((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_timeout_change_time_str(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Myplay::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Myplay::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Myplay,
      qt_meta_data_Myplay, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Myplay::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Myplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Myplay::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Myplay))
        return static_cast<void*>(const_cast< Myplay*>(this));
    return QObject::qt_metacast(_clname);
}

int Myplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Myplay::Time_change()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Myplay::start_Play(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
