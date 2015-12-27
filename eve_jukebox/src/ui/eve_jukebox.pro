#-------------------------------------------------
#
# Project created by QtCreator 2015-11-21T18:20:45
#
#-------------------------------------------------

QT       += core gui qml quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = eve_jukebox
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp \
    controller.cpp

DISTFILES += \
    auralogo.png \
    assets/ui/main.qml \
    assets/ui/options.qml \
    assets/ui/settings.js

RESOURCES += \
    assets.qrc

HEADERS += \
    controller.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../_build/src/eve/release/ -lEve
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../_build/src/eve/debug/ -lEve
else:unix: LIBS += -L$$PWD/../../_build/src/eve/ -lEve

INCLUDEPATH += $$PWD/../../src/eve
DEPENDPATH += $$PWD/../../_build/src/eve


