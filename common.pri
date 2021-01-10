# Includes common configuration for all subdirectory .pro files.

if (win32) {
    LIBS_PATH = S:/Qt/Projects/libs
} else {
    LIBS_PATH = /usr/include
}

TEMPLATE = lib

QT += gui core sql network svg qml quick

# Define Qt Charts or Qwt Charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#greaterThan(QT_MAJOR_VERSION, 6) {
#    greaterThan(QT_MINOR_VERSION, 0) {
#        QT += charts
#        DEFINES += S_QT
#    } else {
#        INCLUDEPATH += $${LIBS_PATH}/qwt-6.1.3/src
#        CONFIG += qt qwt
#        if (win32) {
#            LIBS += $${LIBS_PATH}/qwt-6.1.3/lib/qwtd.dll
#        } else {
#            LIBS += -L$${LIBS_PATH}/qwt-6.1.3/lib -lqwt
#        }
#    }
#}

###########
# DEFINES #
###########

# Linux OS
!win32:DEFINES += S_EMBEDDED
# Debug
DEFINES += S_DEBUG
DEFINES += S_DEBUG_SYSTEM
#DEFINES += S_DEBUG_T
#DEFINES += S_LOGGER
DEFINES += UA_ARCHITECTURE_POSIX UA_ENABLE_AMALGAMATION

#########
# FLAGS #
#########

QMAKE_CFLAGS += -std=c11
QMAKE_CXXFLAGS += -std=c++1y -lm
#-O2
!win32:QMAKE_CXXFLAGS += -fconcepts
# flags from open62541
# -pipe -w  -Wall -Wextra -Wpedantic -Werror -Wno-static-in-inline -Wno-overlength-strings -Wno-unused-parameter -Wc++-compat -Wformat -Wformat-security -Wformat-nonliteral -Wmissing-prototypes -Wstrict-prototypes -Wredundant-decls -Wuninitialized -Winit-self -Wcast-qual -Wstrict-overflow -Wnested-externs -Wmultichar -Wundef -fno-strict-aliasing -fexceptions -fstack-protector-strong -g -flto -fno-fat-lto-objects -Wshadow -Wconversion -fvisibility=hidden -fPIC
# flag for gnu89 inlines header (.inl)
# -fgnu89-inline

##########
# CONFIG #
##########

CONFIG += qt qwt c++14 static
if (win32) {
    CONFIG += debug
} else {
#    CONFIG += release
    CONFIG += debug
}

########
# LIBS #
########

if (win32) {
    LIBS += -L$${LIBS_PATH}/fftw-3.3.4 -lfftw3-3 \
            -L$${LIBS_PATH}/qwt-6.1.3/lib/qwtd.dll
} else {
    LIBS += -lm \
            -lfftw3 \
            -lnfc \
            -lmosquittopp -lmosquitto \
            -lqwt-qt5
}

###############
# INCLUDEPATH #
###############

INCLUDEPATH += \
    $$PWD/src/components/ \
#    $$top_srcdir/src/components/ \
    $$PWD/lib/internal/sentenz/ \
    $$PWD/lib/external/tiny-dnn/ \
    $$PWD/lib/external/libnfc-1.7.1/include/ \
    $$PWD/lib/external/qwt/

INCLUDEPATH +=  \
    $${LIBS_PATH}/eigen3 \

win32:INCLUDEPATH += $${LIBS_PATH}/fftw-3.3.4

#####################
# SOURCES & HEADERS #
#####################

SOURCES += \
    $$PWD/lib/internal/sentenz/src/Spectrum/Hilbert.cpp \
    $$PWD/lib/internal/sentenz/src/IIR/Butterworth.cpp


HEADERS += \
    $$PWD/lib/internal/sentenz/src/Spectrum/Hilbert.hpp \
    $$PWD/lib/internal/sentenz/src/IIR/Butterworth.hpp

#HEADERS += $$PWD/src/iot/opcua/generated/open62541/open62541.h
#SOURCES += $$PWD/src/iot/opcua/generated/open62541/open62541.c

if (!win32) {
    SOURCES += \
        $${LIBS_PATH}/libnfc-1.7.1/utils/mifare.c \
        $${LIBS_PATH}/libnfc-1.7.1/utils/nfcmfclassic.cpp \
        $${LIBS_PATH}/sentenz/src/Bus/gpio.c \
        $${LIBS_PATH}/sentenz/src/Bus/spi.c

    HEADERS += \
        $${LIBS_PATH}/libnfc-1.7.1/utils/mifare.h \
        $${LIBS_PATH}/libnfc-1.7.1/utils/nfcmfclassic.hpp \
        $${LIBS_PATH}/sentenz/src/Bus/gpio.h \
        $${LIBS_PATH}/sentenz/src/Bus/spi.h
}

###########
# DESTDIR #
###########

CONFIG(debug, debug|release) {
    DESTDIR = ../../bin/debug
} else {
    DESTDIR = ../../bin/release
}

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR     = $$DESTDIR/.moc
RCC_DIR     = $$DESTDIR/.qrc
UI_DIR      = $$DESTDIR/.u
