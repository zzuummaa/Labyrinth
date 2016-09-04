QT += core
QT -= gui

TARGET = labyrinth
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    map.cpp \
    mapload.cpp

HEADERS += \
    map.h

