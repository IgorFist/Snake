QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    celldecorator.cpp \
    controller.cpp \
    fieldmodel.cpp \
    fieldview.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    celldecorator.h \
    controller.h \
    fieldmodel.h \
    fieldview.h \
    mainwindow.h


