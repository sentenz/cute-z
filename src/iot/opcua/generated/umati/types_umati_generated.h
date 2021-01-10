/* Generated from umati.bsd with script /home/pi/open62541/open62541/tools/generate_datatypes.py
 * on host pi-VirtualBox by user pi at 2019-12-13 05:27:39 */

#ifndef TYPES_UMATI_GENERATED_H_
#define TYPES_UMATI_GENERATED_H_

#ifdef UA_ENABLE_AMALGAMATION
#include "open62541.h"
#else
#include <open62541/types.h>
#include <open62541/types_generated.h>

#endif

_UA_BEGIN_DECLS


/**
 * Every type is assigned an index in an array containing the type descriptions.
 * These descriptions are used during type handling (copying, deletion,
 * binary encoding, ...). */
#define UA_TYPES_UMATI_COUNT 9
extern UA_EXPORT const UA_DataType UA_TYPES_UMATI[UA_TYPES_UMATI_COUNT];

/**
 * NCProcessing
 * ^^^^^^^^^^^^
 */
typedef enum {
    UA_NCPROCESSING_UNDEFINED = 0,
    UA_NCPROCESSING_SINGLESTEP = 1,
    UA_NCPROCESSING_BLOCKSEQUENCE = 2,
    __UA_NCPROCESSING_FORCE32BIT = 0x7fffffff
} UA_NCProcessing;
UA_STATIC_ASSERT(sizeof(UA_NCProcessing) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_UMATI_NCPROCESSING 0

/**
 * ChannelState
 * ^^^^^^^^^^^^
 */
typedef enum {
    UA_CHANNELSTATE_ACTIVE = 0,
    UA_CHANNELSTATE_INTERRUPTED = 1,
    UA_CHANNELSTATE_RESET = 2,
    __UA_CHANNELSTATE_FORCE32BIT = 0x7fffffff
} UA_ChannelState;
UA_STATIC_ASSERT(sizeof(UA_ChannelState) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_UMATI_CHANNELSTATE 1

/**
 * LampStatus
 * ^^^^^^^^^^
 */
typedef enum {
    UA_LAMPSTATUS_OFF = 0,
    UA_LAMPSTATUS_ON = 1,
    UA_LAMPSTATUS_BLINKING = 2,
    __UA_LAMPSTATUS_FORCE32BIT = 0x7fffffff
} UA_LampStatus;
UA_STATIC_ASSERT(sizeof(UA_LampStatus) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_UMATI_LAMPSTATUS 2

/**
 * ProcessIrregularity
 * ^^^^^^^^^^^^^^^^^^^
 */
typedef enum {
    UA_PROCESSIRREGULARITY_CAPABILITYUNAVAILABLE = 0,
    UA_PROCESSIRREGULARITY_DETECTED = 1,
    UA_PROCESSIRREGULARITY_NOTDETECTED = 2,
    UA_PROCESSIRREGULARITY_NOTYETDETERMINED = 3,
    __UA_PROCESSIRREGULARITY_FORCE32BIT = 0x7fffffff
} UA_ProcessIrregularity;
UA_STATIC_ASSERT(sizeof(UA_ProcessIrregularity) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_UMATI_PROCESSIRREGULARITY 3

/**
 * WearIndication
 * ^^^^^^^^^^^^^^
 */
typedef enum {
    UA_WEARINDICATION_TIME = 0,
    UA_WEARINDICATION_NUMBEROFPARTS = 1,
    UA_WEARINDICATION_NUMBEROFUSAGES = 2,
    UA_WEARINDICATION_DISTANCE = 3,
    UA_WEARINDICATION_LENGTH = 4,
    UA_WEARINDICATION_DIAMETER = 5,
    __UA_WEARINDICATION_FORCE32BIT = 0x7fffffff
} UA_WearIndication;
UA_STATIC_ASSERT(sizeof(UA_WearIndication) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_UMATI_WEARINDICATION 4

/**
 * PartQuality
 * ^^^^^^^^^^^
 */
typedef enum {
    UA_PARTQUALITY_CAPABILITYUNAVAILABLE = 0,
    UA_PARTQUALITY_GOOD = 1,
    UA_PARTQUALITY_BAD = 2,
    UA_PARTQUALITY_NOTYETMEASURED = 3,
    __UA_PARTQUALITY_FORCE32BIT = 0x7fffffff
} UA_PartQuality;
UA_STATIC_ASSERT(sizeof(UA_PartQuality) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_UMATI_PARTQUALITY 5

/**
 * ControlMode
 * ^^^^^^^^^^^
 */
typedef enum {
    UA_CONTROLMODE_UNDEFINED = 0,
    UA_CONTROLMODE_AUTOMATIC = 1,
    UA_CONTROLMODE_AUTOSINGLESTEP = 2,
    UA_CONTROLMODE_MDAMDI = 3,
    UA_CONTROLMODE_JOGMANUAL = 4,
    UA_CONTROLMODE_JOGINCREMENT = 5,
    UA_CONTROLMODE_EDIT = 6,
    __UA_CONTROLMODE_FORCE32BIT = 0x7fffffff
} UA_ControlMode;
UA_STATIC_ASSERT(sizeof(UA_ControlMode) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_UMATI_CONTROLMODE 6

/**
 * LampColor
 * ^^^^^^^^^
 */
typedef enum {
    UA_LAMPCOLOR_GREEN = 0,
    UA_LAMPCOLOR_RED = 1,
    UA_LAMPCOLOR_YELLOW = 2,
    UA_LAMPCOLOR_BLUE = 3,
    UA_LAMPCOLOR_WHITE = 4,
    __UA_LAMPCOLOR_FORCE32BIT = 0x7fffffff
} UA_LampColor;
UA_STATIC_ASSERT(sizeof(UA_LampColor) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_UMATI_LAMPCOLOR 7

/**
 * SafetyMode
 * ^^^^^^^^^^
 */
typedef enum {
    UA_SAFETYMODE_OTHER = 0,
    UA_SAFETYMODE_AUTOMATIC = 1,
    UA_SAFETYMODE_SETUP = 2,
    UA_SAFETYMODE_PROCESS_OBSERVATION = 3,
    UA_SAFETYMODE_PROCESS_OBSERVATION_NO_CONFIRMATION = 4,
    __UA_SAFETYMODE_FORCE32BIT = 0x7fffffff
} UA_SafetyMode;
UA_STATIC_ASSERT(sizeof(UA_SafetyMode) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_UMATI_SAFETYMODE 8


_UA_END_DECLS

#endif /* TYPES_UMATI_GENERATED_H_ */
