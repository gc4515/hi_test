/****************************************************************************
** Meta object code from reading C++ file 'vdecthread.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../vdec2Vo/vdecthread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vdecthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VdecThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      28,   12,   11,   11, 0x0a,
      56,   11,   11,   11, 0x0a,
      68,   11,   11,   11, 0x0a,
      81,   11,   11,   11, 0x0a,
      96,   11,   11,   11, 0x0a,
     111,   11,   11,   11, 0x0a,
     143,  126,   11,   11, 0x0a,
     165,  126,   11,   11, 0x0a,
     212,  186,   11,   11, 0x0a,
     236,  186,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_VdecThread[] = {
    "VdecThread\0\0filepath,status\0"
    "slotVideoPlay(QString,bool)\0slotPause()\0"
    "slotResume()\0slotFastPlay()\0slotSlowPlay()\0"
    "slotRealPlay()\0value,playStatus\0"
    "slotDelay10(int,bool)\0slotDelay2(int,bool)\0"
    "value,realPlay,playStatus\0"
    "slotFF10(int,bool,bool)\0slotFF2(int,bool,bool)\0"
};

void VdecThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        VdecThread *_t = static_cast<VdecThread *>(_o);
        switch (_id) {
        case 0: _t->slotVideoPlay((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->slotPause(); break;
        case 2: _t->slotResume(); break;
        case 3: _t->slotFastPlay(); break;
        case 4: _t->slotSlowPlay(); break;
        case 5: _t->slotRealPlay(); break;
        case 6: _t->slotDelay10((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 7: _t->slotDelay2((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 8: _t->slotFF10((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 9: _t->slotFF2((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData VdecThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VdecThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_VdecThread,
      qt_meta_data_VdecThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VdecThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VdecThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VdecThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VdecThread))
        return static_cast<void*>(const_cast< VdecThread*>(this));
    return QThread::qt_metacast(_clname);
}

int VdecThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
