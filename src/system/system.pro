# Check if the config file exists
! include( ../../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

QT += sql

SOURCES += \
    encoder/SThreadEncoder.cpp \
    encoder/STouchEncoder.cpp \
    encoder/SControlEncoder.cpp \
    panel/STouchPanel.cpp \
    nfc/SThreadNFC.cpp \
    nfc/STouchNFC.cpp \
    nfc/SControlNFC.cpp

HEADERS +=  \
    encoder/SThreadEncoder.h \
    encoder/STouchEncoder.h \
    encoder/SControlEncoder.h \
    panel/STouchPanel.h \
    nfc/SThreadNFC.h \
    nfc/STouchNFC.h \
    nfc/SControlNFC.h


# By default, TARGET is the same as the directory, so it will make
libsystem.a
