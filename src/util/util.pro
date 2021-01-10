# Check if the config file exists
! include( ../../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

SOURCES += \
    splashscreen/SSplashScreen.cpp \
    dialog/STouchDialogBoot.cpp \
    dialog/STouchDialogScreensaver.cpp \
    dialog/STouchDialogTimer.cpp \
    dialog/STouchDialogTumbler.cpp \
    dialog/SAppBar.cpp \
    dialog/SInfoBar.cpp \
    dialog/STextDialog.cpp \
    dialog/SRadioDialog.cpp \
    dialog/SNavigationDrawer.cpp

HEADERS += \
    splashscreen/SSplashScreen.h \
    dialog/STouchDialogBoot.h \
    dialog/STouchDialogScreensaver.h \
    dialog/STouchDialogTimer.h \
    dialog/STouchDialogTumbler.h \
    dialog/SAppBar.h \
    dialog/SInfoBar.h \
    dialog/STextDialog.h \
    dialog/SRadioDialog.h \
    dialog/SNavigationDrawer.h

# By default, TARGET is the same as the directory, so it will make
libutil.a
