# Check if the config file exists
! include( ../../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

SOURCES += \
    shttp.cpp

HEADERS += \
    shttp.h

# By default, TARGET is the same as the directory, so it will make
libnetwork.a
