QT += core
QT -= gui

TARGET = labyrinth
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    map.cpp \
    mapload.cpp \
    waysearcher.cpp \
    mapgenerator.cpp

HEADERS += \
    map.h \
    waysearcher.h \
    labyrinth.h

