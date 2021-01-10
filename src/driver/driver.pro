# Check if the config file exists
! include( ../../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    SGPIO.cpp \
    SEncoder25PRSBE.cpp

HEADERS += \
    SGPIO.h \
    SEncoder25PRSBE.h
