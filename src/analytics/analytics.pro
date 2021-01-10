# Check if the config file exists
!include( ../../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

QT += sql
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    stouchanalytics.cpp \
    stouchanalyticsinputs.cpp \
    stouchanalyticsiot.cpp \
    stouchanalyticsplottemperaturecpu.cpp

HEADERS += \
    stouchanalytics.h \
    stouchanalyticsinputs.h \
    stouchanalyticsiot.h \
    stouchanalyticsplottemperaturecpu.h
