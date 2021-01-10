# Check if the config file exists
! include( ../../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    opcua/generated/umati/namespace_umati_generated.c \
    opcua/generated/umati/types_umati_generated.c \
    opcua/generated/model/namespace_model.c \
    mqtt/SMqtt.cpp \
    opcua/SThreadServer.cpp

HEADERS += \
    opcua/generated/umati/namespace_umati_generated.h \
    opcua/generated/umati/types_umati_generated.h \
    opcua/generated/model/namespace_model.h \
    mqtt/SMqtt.h \
    opcua/SThreadServer.h

HEADERS += opcua/generated/open62541/open62541.h
SOURCES += opcua/generated/open62541/open62541.c
