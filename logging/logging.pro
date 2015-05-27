TEMPLATE = app
TARGET = logging
QT = core
CONFIG   += console c++11
CONFIG   -= app_bundle

SOURCES += main.cpp \
    mydebug.cpp

HEADERS += \
    mydebug.h
