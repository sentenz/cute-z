# Check if the config file exists
! include( ../../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

QT += network

SOURCES += \
    STouchRegistration.cpp

HEADERS += \
    STouchRegistration.h

# By default, TARGET is the same as the directory, so it will make
libmanager.a
