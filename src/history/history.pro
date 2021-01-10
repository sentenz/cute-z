# Check if the config file exists
! include( ../../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

QT += sql network
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    STouchHistory.cpp \
    SViewHistoryOdometer.cpp \
    SModelHistoryOdometer.cpp \
    SPresenterHistoryOdometer.cpp \
    SViewHistoryOdometerDetails.cpp \
    SViewHistoryOptions.cpp

HEADERS += \
    STouchHistory.h \
    SViewHistoryOdometer.h \
    SModelHistoryOdometer.h \
    SPresenterHistoryOdometer.h \
    SViewHistoryOdometerDetails.h \
    SViewHistoryOptions.h
