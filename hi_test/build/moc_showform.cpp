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
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      24,    9,    9,    9, 0x05,
      39,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      63,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ShowForm[] = {
    "ShowForm\0\0signalPause()\0signalResume()\0"
    "signalDesktopFormShow()\0on_pb_pause_clicked()\0"
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
        case 3: _t->on_pb_pause_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
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
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
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
QT_END_MOC_NAMESPACE
