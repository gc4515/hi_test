/****************************************************************************
** Meta object code from reading C++ file 'logiclayer.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../hi_test/logiclayer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logiclayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Logiclayer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      26,   11,   11,   11, 0x05,
      57,   41,   11,   11, 0x05,
      87,   11,   11,   11, 0x05,
     110,   41,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     139,   41,   11,   11, 0x0a,
     167,   11,   11,   11, 0x0a,
     179,   11,   11,   11, 0x0a,
     192,   11,   11,   11, 0x0a,
     214,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Logiclayer[] = {
    "Logiclayer\0\0signalPause()\0signalResume()\0"
    "filepath,status\0signalVideoPlay(QString,bool)\0"
    "signalVideoPlayStart()\0"
    "signalRealPlay(QString,bool)\0"
    "slotVideoShow(QString,bool)\0slotPause()\0"
    "slotResume()\0slotDesktopFormShow()\0"
    "slotSelectFile()\0"
};

void Logiclayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Logiclayer *_t = static_cast<Logiclayer *>(_o);
        switch (_id) {
        case 0: _t->signalPause(); break;
        case 1: _t->signalResume(); break;
        case 2: _t->signalVideoPlay((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->signalVideoPlayStart(); break;
        case 4: _t->signalRealPlay((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->slotVideoShow((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->slotPause(); break;
        case 7: _t->slotResume(); break;
        case 8: _t->slotDesktopFormShow(); break;
        case 9: _t->slotSelectFile(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Logiclayer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Logiclayer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Logiclayer,
      qt_meta_data_Logiclayer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Logiclayer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Logiclayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Logiclayer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Logiclayer))
        return static_cast<void*>(const_cast< Logiclayer*>(this));
    return QObject::qt_metacast(_clname);
}

int Logiclayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Logiclayer::signalPause()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Logiclayer::signalResume()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Logiclayer::signalVideoPlay(QString _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Logiclayer::signalVideoPlayStart()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Logiclayer::signalRealPlay(QString _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
