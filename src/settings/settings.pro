# Check if the config file exists
! include( ../../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

QT += sql network

SOURCES += \
    stouchsettings.cpp \
    stouchsettingscode.cpp \
    stouchsettingsreset.cpp \
    stouchsettingsdesign.cpp \
    stouchsettingssystem.cpp \
    systems/stouchsettingssystemencoder.cpp \
    systems/stouchsettingssystemnfc.cpp \
    stouchsettingsregion.cpp \
    region/stouchdatetime.cpp \
    region/stouchlanguage.cpp \
    stouchsettingsinfo.cpp \
    info/stouchinfomaintenance.cpp \
    info/stouchinfomodule.cpp \
    info/stouchinfosentenz.cpp

HEADERS += \
    stouchsettings.h \
    stouchsettingscode.h \
    stouchsettingsreset.h \
    stouchsettingsdesign.h \
    stouchsettingssystem.h \
    systems/stouchsettingssystemencoder.h \
    systems/stouchsettingssystemnfc.h \
    stouchsettingsregion.h \
    region/stouchdatetime.h \
    region/stouchlanguage.h \
    stouchsettingsinfo.h \
    info/stouchinfomaintenance.h \
    info/stouchinfomodule.h \
    info/stouchinfosentenz.h

# By default, TARGET is the same as the directory, so it will make
libsettings.a
