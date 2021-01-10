# Check if the config file exists
! include( ../../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

QT += network
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    Calculator.cpp \
    SMAC.cpp \
    SLogger.cpp

HEADERS +=  \
    Calculator.h \
    SMAC.h \
    SLogger.h
