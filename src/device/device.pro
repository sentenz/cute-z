# Check if the config file exists
! include( ../../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    SEngine.cpp

HEADERS += \
    SEngine.h