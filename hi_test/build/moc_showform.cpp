/****************************************************************************
** Meta object code from reading C++ file 'showform.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ShowForm/showform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'showform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ShowForm[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      24,    9,    9,    9, 0x05,
      39,    9,    9,    9, 0x05,
      63,    9,    9,    9, 0x05,
      80,    9,    9,    9, 0x05,
      97,    9,    9,    9, 0x05,
     120,  114,    9,    9, 0x05,
     139,  114,    9,    9, 0x05,
     172,  157,    9,    9, 0x05,
     193,  157,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     213,    9,    9,    9, 0x08,
     228,    9,    9,    9, 0x08,
     250,    9,    9,    9, 0x08,
     271,    9,    9,    9, 0x08,
     292,    9,    9,    9, 0x08,
     317,    9,    9,    9, 0x08,
     341,    9,    9,    9, 0x08,
     364,    9,    9,    9, 0x08,
     385,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ShowForm[] = {
    "ShowForm\0\0signalPause()\0signalResume()\0"
    "signalDesktopFormShow()\0signalFastPlay()\0"
    "signalSlowPlay()\0signalRealPlay()\0"
    "value\0signalDelay10(int)\0signalDelay2(int)\0"
    "value,realPlay\0signalFF10(int,bool)\0"
    "signalFF2(int,bool)\0slotTimerOut()\0"
    "on_pb_pause_clicked()\0on_pb_fast_clicked()\0"
    "on_pb_slow_clicked()\0on_pb_realplay_clicked()\0"
    "on_pb_delay10_clicked()\0on_pb_delay1_clicked()\0"
    "on_pb_FF10_clicked()\0on_pb_FF1_clicked()\0"
};

void ShowForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ShowForm *_t = static_cast<ShowForm *>(_o);
        switch (_id) {
        case 0: _t->signalPause(); break;
        case 1: _t->signalResume(); break;
        case 2: _t->signalDesktopFormShow(); break;
        case 3: _t->signalFastPlay(); break;
        case 4: _t->signalSlowPlay(); break;
        case 5: _t->signalRealPlay(); break;
        case 6: _t->signalDelay10((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->signalDelay2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->signalFF10((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 9: _t->signalFF2((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 10: _t->slotTimerOut(); break;
        case 11: _t->on_pb_pause_clicked(); break;
        case 12: _t->on_pb_fast_clicked(); break;
        case 13: _t->on_pb_slow_clicked(); break;
        case 14: _t->on_pb_realplay_clicked(); break;
        case 15: _t->on_pb_delay10_clicked(); break;
        case 16: _t->on_pb_delay1_clicked(); break;
        case 17: _t->on_pb_FF10_clicked(); break;
        case 18: _t->on_pb_FF1_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ShowForm::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ShowForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ShowForm,
      qt_meta_data_ShowForm, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ShowForm::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ShowForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ShowForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ShowForm))
        return static_cast<void*>(const_cast< ShowForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int ShowForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void ShowForm::signalPause()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ShowForm::signalResume()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ShowForm::signalDesktopFormShow()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void ShowForm::signalFastPlay()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void ShowForm::signalSlowPlay()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void ShowForm::signalRealPlay()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void ShowForm::signalDelay10(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ShowForm::signalDelay2(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void ShowForm::signalFF10(int _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void ShowForm::signalFF2(int _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE
