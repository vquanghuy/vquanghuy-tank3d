/****************************************************************************
** Meta object code from reading C++ file 'QIrrlichtWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../custom_widget/QIrrlichtWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QIrrlichtWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QIrrlichtWidget_t {
    QByteArrayData data[14];
    char stringdata[165];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QIrrlichtWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QIrrlichtWidget_t qt_meta_stringdata_QIrrlichtWidget = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 19),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 20),
QT_MOC_LITERAL(4, 58, 6),
QT_MOC_LITERAL(5, 65, 10),
QT_MOC_LITERAL(6, 76, 12),
QT_MOC_LITERAL(7, 89, 5),
QT_MOC_LITERAL(8, 95, 12),
QT_MOC_LITERAL(9, 108, 9),
QT_MOC_LITERAL(10, 118, 8),
QT_MOC_LITERAL(11, 127, 10),
QT_MOC_LITERAL(12, 138, 10),
QT_MOC_LITERAL(13, 149, 14)
    },
    "QIrrlichtWidget\0updateIrrlichtQuery\0"
    "\0irr::IrrlichtDevice*\0device\0mousePress\0"
    "QMouseEvent*\0event\0mouseRelease\0"
    "mouseMove\0keyPress\0QKeyEvent*\0keyRelease\0"
    "updateIrrlicht\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QIrrlichtWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x05,
       5,    1,   52,    2, 0x05,
       8,    1,   55,    2, 0x05,
       9,    1,   58,    2, 0x05,
      10,    1,   61,    2, 0x05,
      12,    1,   64,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
      13,    1,   67,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 11,    7,
    QMetaType::Void, 0x80000000 | 11,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void QIrrlichtWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QIrrlichtWidget *_t = static_cast<QIrrlichtWidget *>(_o);
        switch (_id) {
        case 0: _t->updateIrrlichtQuery((*reinterpret_cast< irr::IrrlichtDevice*(*)>(_a[1]))); break;
        case 1: _t->mousePress((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: _t->mouseRelease((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: _t->mouseMove((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 4: _t->keyPress((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 5: _t->keyRelease((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 6: _t->updateIrrlicht((*reinterpret_cast< irr::IrrlichtDevice*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QIrrlichtWidget::*_t)(irr::IrrlichtDevice * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QIrrlichtWidget::updateIrrlichtQuery)) {
                *result = 0;
            }
        }
        {
            typedef void (QIrrlichtWidget::*_t)(QMouseEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QIrrlichtWidget::mousePress)) {
                *result = 1;
            }
        }
        {
            typedef void (QIrrlichtWidget::*_t)(QMouseEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QIrrlichtWidget::mouseRelease)) {
                *result = 2;
            }
        }
        {
            typedef void (QIrrlichtWidget::*_t)(QMouseEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QIrrlichtWidget::mouseMove)) {
                *result = 3;
            }
        }
        {
            typedef void (QIrrlichtWidget::*_t)(QKeyEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QIrrlichtWidget::keyPress)) {
                *result = 4;
            }
        }
        {
            typedef void (QIrrlichtWidget::*_t)(QKeyEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QIrrlichtWidget::keyRelease)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject QIrrlichtWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QIrrlichtWidget.data,
      qt_meta_data_QIrrlichtWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *QIrrlichtWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QIrrlichtWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QIrrlichtWidget.stringdata))
        return static_cast<void*>(const_cast< QIrrlichtWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int QIrrlichtWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void QIrrlichtWidget::updateIrrlichtQuery(irr::IrrlichtDevice * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QIrrlichtWidget::mousePress(QMouseEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QIrrlichtWidget::mouseRelease(QMouseEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QIrrlichtWidget::mouseMove(QMouseEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QIrrlichtWidget::keyPress(QKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QIrrlichtWidget::keyRelease(QKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
