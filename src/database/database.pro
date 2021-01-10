# Check if the config file exists
! include( ../../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

QT += sql network
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    SDatabaseOdometer.cpp

HEADERS += \
    SDatabaseOdometer.h
