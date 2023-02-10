/****************************************************************************
** Meta object code from reading C++ file 'misc_paint.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../paint_app_tut/misc_paint.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'misc_paint.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Misc_Paint_t {
    const uint offsetsAndSize[46];
    char stringdata0[215];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Misc_Paint_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Misc_Paint_t qt_meta_stringdata_Misc_Paint = {
    {
QT_MOC_LITERAL(0, 10), // "Misc_Paint"
QT_MOC_LITERAL(11, 4), // "open"
QT_MOC_LITERAL(16, 0), // ""
QT_MOC_LITERAL(17, 4), // "save"
QT_MOC_LITERAL(22, 8), // "penColor"
QT_MOC_LITERAL(31, 14), // "penColorButton"
QT_MOC_LITERAL(46, 8), // "penWidth"
QT_MOC_LITERAL(55, 17), // "colorPickerButton"
QT_MOC_LITERAL(73, 5), // "about"
QT_MOC_LITERAL(79, 6), // "zoomIn"
QT_MOC_LITERAL(86, 7), // "zoomOut"
QT_MOC_LITERAL(94, 4), // "undo"
QT_MOC_LITERAL(99, 4), // "redo"
QT_MOC_LITERAL(104, 8), // "setErase"
QT_MOC_LITERAL(113, 9), // "newWindow"
QT_MOC_LITERAL(123, 12), // "resizeCanvas"
QT_MOC_LITERAL(136, 10), // "selectTool"
QT_MOC_LITERAL(147, 9), // "shapeTool"
QT_MOC_LITERAL(157, 11), // "penTypeTool"
QT_MOC_LITERAL(169, 13), // "setColorMode1"
QT_MOC_LITERAL(183, 13), // "setColorMode2"
QT_MOC_LITERAL(197, 13), // "opacityChange"
QT_MOC_LITERAL(211, 3) // "val"

    },
    "Misc_Paint\0open\0\0save\0penColor\0"
    "penColorButton\0penWidth\0colorPickerButton\0"
    "about\0zoomIn\0zoomOut\0undo\0redo\0setErase\0"
    "newWindow\0resizeCanvas\0selectTool\0"
    "shapeTool\0penTypeTool\0setColorMode1\0"
    "setColorMode2\0opacityChange\0val"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Misc_Paint[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  134,    2, 0x08,    1 /* Private */,
       3,    0,  135,    2, 0x08,    2 /* Private */,
       4,    0,  136,    2, 0x08,    3 /* Private */,
       5,    0,  137,    2, 0x08,    4 /* Private */,
       6,    0,  138,    2, 0x08,    5 /* Private */,
       7,    0,  139,    2, 0x08,    6 /* Private */,
       8,    0,  140,    2, 0x08,    7 /* Private */,
       9,    0,  141,    2, 0x08,    8 /* Private */,
      10,    0,  142,    2, 0x08,    9 /* Private */,
      11,    0,  143,    2, 0x08,   10 /* Private */,
      12,    0,  144,    2, 0x08,   11 /* Private */,
      13,    0,  145,    2, 0x08,   12 /* Private */,
      14,    0,  146,    2, 0x08,   13 /* Private */,
      15,    0,  147,    2, 0x08,   14 /* Private */,
      16,    0,  148,    2, 0x08,   15 /* Private */,
      17,    0,  149,    2, 0x08,   16 /* Private */,
      18,    0,  150,    2, 0x08,   17 /* Private */,
      19,    0,  151,    2, 0x08,   18 /* Private */,
      20,    0,  152,    2, 0x08,   19 /* Private */,
      21,    1,  153,    2, 0x08,   20 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   22,

       0        // eod
};

void Misc_Paint::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Misc_Paint *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->open(); break;
        case 1: _t->save(); break;
        case 2: _t->penColor(); break;
        case 3: _t->penColorButton(); break;
        case 4: _t->penWidth(); break;
        case 5: _t->colorPickerButton(); break;
        case 6: _t->about(); break;
        case 7: _t->zoomIn(); break;
        case 8: _t->zoomOut(); break;
        case 9: _t->undo(); break;
        case 10: _t->redo(); break;
        case 11: _t->setErase(); break;
        case 12: _t->newWindow(); break;
        case 13: _t->resizeCanvas(); break;
        case 14: _t->selectTool(); break;
        case 15: _t->shapeTool(); break;
        case 16: _t->penTypeTool(); break;
        case 17: _t->setColorMode1(); break;
        case 18: _t->setColorMode2(); break;
        case 19: _t->opacityChange((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Misc_Paint::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Misc_Paint.offsetsAndSize,
    qt_meta_data_Misc_Paint,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Misc_Paint_t
, QtPrivate::TypeAndForceComplete<Misc_Paint, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *Misc_Paint::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Misc_Paint::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Misc_Paint.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Misc_Paint::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 20;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
