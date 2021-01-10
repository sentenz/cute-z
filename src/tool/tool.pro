# Check if the config file exists
! include( ../../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

SOURCES += \
    STouchTools.cpp \
    STouchBar.cpp \
    STouchHome.cpp

HEADERS += \
    STouchTools.h \
    STouchBar.h \
    STouchHome.h

# By default, TARGET is the same as the directory, so it will make
libtool.a
