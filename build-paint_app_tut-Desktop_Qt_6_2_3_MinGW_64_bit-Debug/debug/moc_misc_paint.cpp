/****************************************************************************
** Meta object code from reading C++ file 'misc_paint.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
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
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Misc_Paint_t {
    const uint offsetsAndSize[60];
    char stringdata0[288];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Misc_Paint_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Misc_Paint_t qt_meta_stringdata_Misc_Paint = {
    {
QT_MOC_LITERAL(0, 10), // "Misc_Paint"
QT_MOC_LITERAL(11, 12), // "colorChanged"
QT_MOC_LITERAL(24, 0), // ""
QT_MOC_LITERAL(25, 3), // "arg"
QT_MOC_LITERAL(29, 4), // "open"
QT_MOC_LITERAL(34, 4), // "save"
QT_MOC_LITERAL(39, 8), // "penColor"
QT_MOC_LITERAL(48, 14), // "penColorButton"
QT_MOC_LITERAL(63, 14), // "setColorButton"
QT_MOC_LITERAL(78, 8), // "penWidth"
QT_MOC_LITERAL(87, 17), // "colorPickerButton"
QT_MOC_LITERAL(105, 5), // "about"
QT_MOC_LITERAL(111, 6), // "zoomIn"
QT_MOC_LITERAL(118, 7), // "zoomOut"
QT_MOC_LITERAL(126, 4), // "undo"
QT_MOC_LITERAL(131, 4), // "redo"
QT_MOC_LITERAL(136, 8), // "setErase"
QT_MOC_LITERAL(145, 9), // "newWindow"
QT_MOC_LITERAL(155, 9), // "fill_tool"
QT_MOC_LITERAL(165, 9), // "line_tool"
QT_MOC_LITERAL(175, 12), // "resizeCanvas"
QT_MOC_LITERAL(188, 10), // "selectTool"
QT_MOC_LITERAL(199, 9), // "shapeTool"
QT_MOC_LITERAL(209, 11), // "penTypeTool"
QT_MOC_LITERAL(221, 13), // "setColorMode1"
QT_MOC_LITERAL(235, 13), // "setColorMode2"
QT_MOC_LITERAL(249, 13), // "opacityChange"
QT_MOC_LITERAL(263, 3), // "val"
QT_MOC_LITERAL(267, 14), // "onColorChanged"
QT_MOC_LITERAL(282, 5) // "color"

    },
    "Misc_Paint\0colorChanged\0\0arg\0open\0"
    "save\0penColor\0penColorButton\0"
    "setColorButton\0penWidth\0colorPickerButton\0"
    "about\0zoomIn\0zoomOut\0undo\0redo\0setErase\0"
    "newWindow\0fill_tool\0line_tool\0"
    "resizeCanvas\0selectTool\0shapeTool\0"
    "penTypeTool\0setColorMode1\0setColorMode2\0"
    "opacityChange\0val\0onColorChanged\0color"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Misc_Paint[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       1,  193, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  164,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,  167,    2, 0x08,    4 /* Private */,
       5,    0,  168,    2, 0x08,    5 /* Private */,
       6,    0,  169,    2, 0x08,    6 /* Private */,
       7,    0,  170,    2, 0x08,    7 /* Private */,
       8,    0,  171,    2, 0x08,    8 /* Private */,
       9,    0,  172,    2, 0x08,    9 /* Private */,
      10,    0,  173,    2, 0x08,   10 /* Private */,
      11,    0,  174,    2, 0x08,   11 /* Private */,
      12,    0,  175,    2, 0x08,   12 /* Private */,
      13,    0,  176,    2, 0x08,   13 /* Private */,
      14,    0,  177,    2, 0x08,   14 /* Private */,
      15,    0,  178,    2, 0x08,   15 /* Private */,
      16,    0,  179,    2, 0x08,   16 /* Private */,
      17,    0,  180,    2, 0x08,   17 /* Private */,
      18,    0,  181,    2, 0x08,   18 /* Private */,
      19,    0,  182,    2, 0x08,   19 /* Private */,
      20,    0,  183,    2, 0x08,   20 /* Private */,
      21,    0,  184,    2, 0x08,   21 /* Private */,
      22,    0,  185,    2, 0x08,   22 /* Private */,
      23,    0,  186,    2, 0x08,   23 /* Private */,
      24,    0,  187,    2, 0x08,   24 /* Private */,
      25,    0,  188,    2, 0x08,   25 /* Private */,
      26,    1,  189,    2, 0x08,   26 /* Private */,
      28,    0,  192,    2, 0x08,   28 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QColor,    3,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   27,
    QMetaType::Void,

 // properties: name, type, flags
      29, QMetaType::QColor, 0x00015001, uint(0), 0,

       0        // eod
};

void Misc_Paint::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Misc_Paint *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->colorChanged((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 1: _t->open(); break;
        case 2: _t->save(); break;
        case 3: _t->penColor(); break;
        case 4: _t->penColorButton(); break;
        case 5: _t->setColorButton(); break;
        case 6: _t->penWidth(); break;
        case 7: _t->colorPickerButton(); break;
        case 8: _t->about(); break;
        case 9: _t->zoomIn(); break;
        case 10: _t->zoomOut(); break;
        case 11: _t->undo(); break;
        case 12: _t->redo(); break;
        case 13: _t->setErase(); break;
        case 14: _t->newWindow(); break;
        case 15: _t->fill_tool(); break;
        case 16: _t->line_tool(); break;
        case 17: _t->resizeCanvas(); break;
        case 18: _t->selectTool(); break;
        case 19: _t->shapeTool(); break;
        case 20: _t->penTypeTool(); break;
        case 21: _t->setColorMode1(); break;
        case 22: _t->setColorMode2(); break;
        case 23: _t->opacityChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->onColorChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Misc_Paint::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Misc_Paint::colorChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Misc_Paint *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QColor*>(_v) = _t->color(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject Misc_Paint::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Misc_Paint.offsetsAndSize,
    qt_meta_data_Misc_Paint,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Misc_Paint_t
, QtPrivate::TypeAndForceComplete<QColor, std::true_type>, QtPrivate::TypeAndForceComplete<Misc_Paint, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QColor, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


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
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 25;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Misc_Paint::colorChanged(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
