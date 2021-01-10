# Check if the config file exists
!include( ../../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

TEMPLATE = app

QTPLUGIN += qjpeg qgif

CONFIG += plugin

#LIBS += ../../$$top_builddir/bin/debug/libcomponents.a \
#        ../../$$top_builddir/libwidget.a
#PRE_TARGETDEPS += ../../$$top_builddir/bin/debug/libcomponents.a \
#                  ../../$$top_builddir/libwidget.a

SOURCES += main.cpp \
    SCentral.cpp \
    SGlobal.cpp \
    SMain.cpp

HEADERS += \
    SCentral.h \
    SGlobal.h \
    SMain.h

CONFIG(debug, debug|release) {
    DESTDIR = ../../bin/debug
    LIBS += -L../../bin/debug \
        -lfunction \
        -lsystem \
        -lsettings \
        -ldatabase \
        -lhistory \
        -ltool \
        -ldevice \
        -ldriver \
        -lkeyboard \
#        -liot \
        -lanalytics \
        -lneuron \
        -lnetwork \
        -lutil \
        -lwidget \
        -lcomponents
} else {
    DESTDIR = ../../bin/release
    LIBS += -L../../bin/release \
        -lfunction \
        -lsystem \
        -lsettings \
        -ldatabase \
        -lhistory \
        -ltool \
        -ldevice \
        -ldriver \
        -lkeyboard \
#        -liot \
        -lanalytics \
        -lneuron \
        -lnetwork \
        -lutil \
        -lwidget \
        -lcomponents
}

RESOURCES += \
    images.qrc
