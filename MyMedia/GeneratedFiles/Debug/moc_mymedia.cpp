/****************************************************************************
** Meta object code from reading C++ file 'mymedia.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mymedia.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mymedia.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyMedia[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x09,
      33,    8,    8,    8, 0x09,
      57,    8,    8,    8, 0x09,
      84,    8,    8,    8, 0x09,
     112,    8,    8,    8, 0x09,
     142,    8,    8,    8, 0x09,
     171,  159,    8,    8, 0x09,
     203,  190,    8,    8, 0x09,
     230,    8,    8,    8, 0x09,
     252,    8,    8,    8, 0x09,
     276,    8,    8,    8, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_MyMedia[] = {
    "MyMedia\0\0on_clicked_phBtn_play()\0"
    "on_clicked_phBtn_stop()\0"
    "on_triggered_action_open()\0"
    "on_triggered_action_chose()\0"
    "on_doubleClicked(QModelIndex)\0"
    "on_Time_change()\0Lingth_medi\0"
    "on_start_Play(int)\0arg_Position\0"
    "on_mouse_change_value(int)\0"
    "on_sign_mouse_Press()\0on_sign_mouse_Release()\0"
    "on_clicked_phBtn_Vlm()\0"
};

void MyMedia::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyMedia *_t = static_cast<MyMedia *>(_o);
        switch (_id) {
        case 0: _t->on_clicked_phBtn_play(); break;
        case 1: _t->on_clicked_phBtn_stop(); break;
        case 2: _t->on_triggered_action_open(); break;
        case 3: _t->on_triggered_action_chose(); break;
        case 4: _t->on_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_Time_change(); break;
        case 6: _t->on_start_Play((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_mouse_change_value((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_sign_mouse_Press(); break;
        case 9: _t->on_sign_mouse_Release(); break;
        case 10: _t->on_clicked_phBtn_Vlm(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MyMedia::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyMedia::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MyMedia,
      qt_meta_data_MyMedia, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyMedia::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyMedia::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyMedia::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyMedia))
        return static_cast<void*>(const_cast< MyMedia*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MyMedia::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
