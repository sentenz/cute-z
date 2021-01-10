# Check if the config file exists
! include( ../../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    SCanvas.cpp \
    STouchScreenlock.cpp \
    STouchKeyboard.cpp \
    STouchCalculator.cpp \
    SColorSquare.cpp \
    SColorRgb.cpp \
    STouchColorKeyboard.cpp \
    SDigitsKeyboard.cpp


HEADERS += \
    SCanvas.h \
    STouchScreenlock.h \
    STouchKeyboard.h \
    STouchCalculator.h \
    SColorSquare.h \
    SColorRgb.h \
    STouchColorKeyboard.h \
    SDigitsKeyboard.h


# QML C++
RESOURCES = qml.qrc

SOURCES += \
#    SBackendKeyboard.cpp \
#    SLoadKeyboard.cpp

HEADERS += \
#    SBackendKeyboard.h \
#    SLoadKeyboard.h \

DISTFILES += \
#    STouchCanvas.qml
