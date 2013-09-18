QT       -= gui

TARGET = CountersSystem
TEMPLATE = lib
CONFIG += staticlib c++11

HEADERS += CountersSystem.h \
    Counter.h

SOURCES += CountersSystem.cpp \
    Counter.cpp
