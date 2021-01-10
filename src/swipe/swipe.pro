# Check if the config file exists
! include( ../../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

SOURCES += \
    list/SFlickable.cpp \
    list/SFlickableTicker.cpp \
    list/STouchFlickableList.cpp

HEADERS += \
    list/SFlickable.h \
    list/SFlickableTicker.h \
    list/STouchFlickableList.h

# By default, TARGET is the same as the directory, so it will make
libswipe.a
