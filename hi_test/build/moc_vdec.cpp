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
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,    6,    5,    5, 0x05,
      52,    5,    5,    5, 0x05,
      66,    5,    5,    5, 0x05,
      81,    5,    5,    5, 0x05,
      98,    5,    5,    5, 0x05,
     115,    5,    5,    5, 0x05,
     149,  132,    5,    5, 0x05,
     173,  132,    5,    5, 0x05,
     222,  196,    5,    5, 0x05,
     248,  196,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
     273,    5,    5,    5, 0x0a,
     285,    5,    5,    5, 0x0a,
     298,    5,    5,    5, 0x0a,
     313,    5,    5,    5, 0x0a,
     328,    5,    5,    5, 0x0a,
     349,  343,    5,    5, 0x0a,
     366,  343,    5,    5, 0x0a,
     397,  382,    5,    5, 0x0a,
     416,  382,    5,    5, 0x0a,
     434,    6,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_vdec[] = {
    "vdec\0\0filepath,status\0"
    "signalVideoPlay(QString,bool)\0"
    "signalPause()\0signalResume()\0"
    "signalFastPlay()\0signalSlowPlay()\0"
    "signalRealPlay()\0value,playStatus\0"
    "signalDelay10(int,bool)\0signalDelay2(int,bool)\0"
    "value,realPlay,playStatus\0"
    "signalFF10(int,bool,bool)\0"
    "signalFF2(int,bool,bool)\0slotPause()\0"
    "slotResume()\0slotFastPlay()\0slotSlowPlay()\0"
    "slotRealPlay()\0value\0slotDelay10(int)\0"
    "slotDelay2(int)\0value,realPlay\0"
    "slotFF10(int,bool)\0slotFF2(int,bool)\0"
    "slotVideoPlay(QString,bool)\0"
};

void vdec::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        vdec *_t = static_cast<vdec *>(_o);
        switch (_id) {
        case 0: _t->signalVideoPlay((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->signalPause(); break;
        case 2: _t->signalResume(); break;
        case 3: _t->signalFastPlay(); break;
        case 4: _t->signalSlowPlay(); break;
        case 5: _t->signalRealPlay(); break;
        case 6: _t->signalDelay10((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 7: _t->signalDelay2((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 8: _t->signalFF10((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 9: _t->signalFF2((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 10: _t->slotPause(); break;
        case 11: _t->slotResume(); break;
        case 12: _t->slotFastPlay(); break;
        case 13: _t->slotSlowPlay(); break;
        case 14: _t->slotRealPlay(); break;
        case 15: _t->slotDelay10((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->slotDelay2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->slotFF10((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 18: _t->slotFF2((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 19: _t->slotVideoPlay((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
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
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
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
void vdec::signalPause()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void vdec::signalResume()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void vdec::signalFastPlay()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void vdec::signalSlowPlay()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void vdec::signalRealPlay()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void vdec::signalDelay10(int _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void vdec::signalDelay2(int _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void vdec::signalFF10(int _t1, bool _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void vdec::signalFF2(int _t1, bool _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE
