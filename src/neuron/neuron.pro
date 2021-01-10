# Check if the config file exists
! include( ../../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

DEFINES += DNN_USE_IMAGE_API

SOURCES += \
#    mnist/strainmnist.cpp \
    mnist/sneuronmnist.cpp

#    mnist/quantized.cpp \
#    mnist/train.cpp \

HEADERS += \
#    mnist/strainmnist.h \
    mnist/sneuronmnist.h

# By default, TARGET is the same as the directory, so it will make
libneuron.a
