/****************************************************************************
** Meta object code from reading C++ file 'desktopform.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ShowForm/desktopform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'desktopform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DesktopForm[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      29,   13,   12,   12, 0x05,
      58,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      77,   12,   12,   12, 0x08,
      98,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DesktopForm[] = {
    "DesktopForm\0\0filepath,status\0"
    "signalRealPlay(QString,bool)\0"
    "signalSelectFile()\0on_pb_show_clicked()\0"
    "on_pb_document_clicked()\0"
};

void DesktopForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DesktopForm *_t = static_cast<DesktopForm *>(_o);
        switch (_id) {
        case 0: _t->signalRealPlay((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->signalSelectFile(); break;
        case 2: _t->on_pb_show_clicked(); break;
        case 3: _t->on_pb_document_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DesktopForm::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DesktopForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DesktopForm,
      qt_meta_data_DesktopForm, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DesktopForm::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DesktopForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DesktopForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DesktopForm))
        return static_cast<void*>(const_cast< DesktopForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int DesktopForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void DesktopForm::signalRealPlay(QString _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DesktopForm::signalSelectFile()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
