TEMPLATE = app
TARGET = logging
QT = widgets
CONFIG   += console c++11
CONFIG   -= app_bundle

SOURCES += main.cpp \
    mydebug.cpp

HEADERS += \
    mydebug.h
