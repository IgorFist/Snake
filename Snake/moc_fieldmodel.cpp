/****************************************************************************
** Meta object code from reading C++ file 'fieldmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "fieldmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fieldmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FieldModel_t {
    QByteArrayData data[12];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FieldModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FieldModel_t qt_meta_stringdata_FieldModel = {
    {
QT_MOC_LITERAL(0, 0, 10), // "FieldModel"
QT_MOC_LITERAL(1, 11, 11), // "dataUpdated"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 12), // "scoreUpdated"
QT_MOC_LITERAL(4, 37, 12), // "speedUpdated"
QT_MOC_LITERAL(5, 50, 17), // "gameStatusChanged"
QT_MOC_LITERAL(6, 68, 10), // "GameStatus"
QT_MOC_LITERAL(7, 79, 7), // "newGame"
QT_MOC_LITERAL(8, 87, 9), // "pauseGame"
QT_MOC_LITERAL(9, 97, 8), // "gameOver"
QT_MOC_LITERAL(10, 106, 7), // "speedUp"
QT_MOC_LITERAL(11, 114, 4) // "move"

    },
    "FieldModel\0dataUpdated\0\0scoreUpdated\0"
    "speedUpdated\0gameStatusChanged\0"
    "GameStatus\0newGame\0pauseGame\0gameOver\0"
    "speedUp\0move"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FieldModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    1,   60,    2, 0x06 /* Public */,
       4,    1,   63,    2, 0x06 /* Public */,
       5,    1,   66,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   69,    2, 0x0a /* Public */,
       8,    0,   70,    2, 0x0a /* Public */,
       9,    0,   71,    2, 0x0a /* Public */,
      10,    0,   72,    2, 0x0a /* Public */,
      11,    0,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 6,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FieldModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FieldModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataUpdated(); break;
        case 1: _t->scoreUpdated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->speedUpdated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->gameStatusChanged((*reinterpret_cast< GameStatus(*)>(_a[1]))); break;
        case 4: _t->newGame(); break;
        case 5: _t->pauseGame(); break;
        case 6: _t->gameOver(); break;
        case 7: _t->speedUp(); break;
        case 8: _t->move(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FieldModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FieldModel::dataUpdated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FieldModel::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FieldModel::scoreUpdated)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FieldModel::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FieldModel::speedUpdated)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FieldModel::*)(GameStatus );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FieldModel::gameStatusChanged)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FieldModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_FieldModel.data,
    qt_meta_data_FieldModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FieldModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FieldModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FieldModel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FieldModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void FieldModel::dataUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FieldModel::scoreUpdated(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FieldModel::speedUpdated(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FieldModel::gameStatusChanged(GameStatus _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
