/****************************************************************************
** Meta object code from reading C++ file 'vdec.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../vdec2Vo/vdec.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vdec.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vdec[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,    6,    5,    5, 0x05,
      52,    5,    5,    5, 0x05,
      69,    5,    5,    5, 0x05,
      86,    5,    5,    5, 0x05,
     109,  103,    5,    5, 0x05,
     128,  103,    5,    5, 0x05,
     146,  103,    5,    5, 0x05,
     162,  103,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
     177,    5,    5,    5, 0x0a,
     189,    5,    5,    5, 0x0a,
     202,    5,    5,    5, 0x0a,
     217,    5,    5,    5, 0x0a,
     232,    5,    5,    5, 0x0a,
     247,  103,    5,    5, 0x0a,
     264,  103,    5,    5, 0x0a,
     280,  103,    5,    5, 0x0a,
     294,  103,    5,    5, 0x0a,
     307,    6,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_vdec[] = {
    "vdec\0\0filepath,status\0"
    "signalVideoPlay(QString,bool)\0"
    "signalFastPlay()\0signalSlowPlay()\0"
    "signalRealPlay()\0value\0signalDelay10(int)\0"
    "signalDelay2(int)\0signalFF10(int)\0"
    "signalFF2(int)\0slotPause()\0slotResume()\0"
    "slotFastPlay()\0slotSlowPlay()\0"
    "slotRealPlay()\0slotDelay10(int)\0"
    "slotDelay2(int)\0slotFF10(int)\0"
    "slotFF2(int)\0slotVideoPlay(QString,bool)\0"
};

void vdec::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        vdec *_t = static_cast<vdec *>(_o);
        switch (_id) {
        case 0: _t->signalVideoPlay((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->signalFastPlay(); break;
        case 2: _t->signalSlowPlay(); break;
        case 3: _t->signalRealPlay(); break;
        case 4: _t->signalDelay10((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->signalDelay2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->signalFF10((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->signalFF2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->slotPause(); break;
        case 9: _t->slotResume(); break;
        case 10: _t->slotFastPlay(); break;
        case 11: _t->slotSlowPlay(); break;
        case 12: _t->slotRealPlay(); break;
        case 13: _t->slotDelay10((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->slotDelay2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->slotFF10((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->slotFF2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->slotVideoPlay((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData vdec::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vdec::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_vdec,
      qt_meta_data_vdec, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vdec::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vdec::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vdec::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vdec))
        return static_cast<void*>(const_cast< vdec*>(this));
    return QObject::qt_metacast(_clname);
}

int vdec::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void vdec::signalVideoPlay(const QString & _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void vdec::signalFastPlay()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void vdec::signalSlowPlay()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void vdec::signalRealPlay()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void vdec::signalDelay10(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void vdec::signalDelay2(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void vdec::signalFF10(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void vdec::signalFF2(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
