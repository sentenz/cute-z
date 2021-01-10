/* Generated from Opc_Ua.EUROMAP83.1_01.Types.bsd with script /home/pi/open62541/open62541/tools/generate_datatypes.py
 * on host pi-VirtualBox by user pi at 2019-12-05 09:27:18 */

#ifndef TYPES_EUROMAP83_GENERATED_H_
#define TYPES_EUROMAP83_GENERATED_H_

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
#define UA_TYPES_EUROMAP83_COUNT 25
extern UA_EXPORT const UA_DataType UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_COUNT];

/**
 * PIDParametersDataType
 * ^^^^^^^^^^^^^^^^^^^^^
 * Structure for storing the parameters of a PID controller */
typedef struct {
    UA_Double p;
    UA_Double i;
    UA_Double d;
} UA_PIDParametersDataType;

#define UA_TYPES_EUROMAP83_PIDPARAMETERSDATATYPE 0

/**
 * CavityCycleQualityEnumeration
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 * Quality of the cycle for each cavity */
typedef enum {
    UA_CAVITYCYCLEQUALITYENUMERATION_NO_PART = 0,
    UA_CAVITYCYCLEQUALITYENUMERATION_GOOD_PART = 1,
    UA_CAVITYCYCLEQUALITYENUMERATION_BAD_PART = 2,
    UA_CAVITYCYCLEQUALITYENUMERATION_REWORK = 3,
    __UA_CAVITYCYCLEQUALITYENUMERATION_FORCE32BIT = 0x7fffffff
} UA_CavityCycleQualityEnumeration;
UA_STATIC_ASSERT(sizeof(UA_CavityCycleQualityEnumeration) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_EUROMAP83_CAVITYCYCLEQUALITYENUMERATION 1

/**
 * JobStatusEnumeration
 * ^^^^^^^^^^^^^^^^^^^^
 * Current status of the job */
typedef enum {
    UA_JOBSTATUSENUMERATION_OTHER = 0,
    UA_JOBSTATUSENUMERATION_TRANSFERRED_ASSIGNED = 1,
    UA_JOBSTATUSENUMERATION_SET_UP_ACTIVE = 2,
    UA_JOBSTATUSENUMERATION_SET_UP_INTERRUPTED = 3,
    UA_JOBSTATUSENUMERATION_SET_UP_FINISHED = 4,
    UA_JOBSTATUSENUMERATION_START_UP_ACTIVE = 5,
    UA_JOBSTATUSENUMERATION_JOB_IN_PRODUCTION = 6,
    UA_JOBSTATUSENUMERATION_JOB_INTERRUPTED = 7,
    UA_JOBSTATUSENUMERATION_JOB_FINISHED = 8,
    UA_JOBSTATUSENUMERATION_TEAR_DOWN_ACTIVE = 9,
    UA_JOBSTATUSENUMERATION_TEAR_DOWN_INTERRUPTED = 10,
    UA_JOBSTATUSENUMERATION_TEAR_DOWN_FINISHED = 11,
    __UA_JOBSTATUSENUMERATION_FORCE32BIT = 0x7fffffff
} UA_JobStatusEnumeration;
UA_STATIC_ASSERT(sizeof(UA_JobStatusEnumeration) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_EUROMAP83_JOBSTATUSENUMERATION 2

/**
 * ProductionDatasetComponentEnumeration
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 * Informs for which machines information is included in the production dataset file */
typedef enum {
    UA_PRODUCTIONDATASETCOMPONENTENUMERATION_IMM = 0,
    UA_PRODUCTIONDATASETCOMPONENTENUMERATION_ROBOT = 1,
    __UA_PRODUCTIONDATASETCOMPONENTENUMERATION_FORCE32BIT = 0x7fffffff
} UA_ProductionDatasetComponentEnumeration;
UA_STATIC_ASSERT(sizeof(UA_ProductionDatasetComponentEnumeration) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_EUROMAP83_PRODUCTIONDATASETCOMPONENTENUMERATION 3

/**
 * MaintenanceStatusEnumeration
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 * Maintenance status of a machine/device/component */
typedef enum {
    UA_MAINTENANCESTATUSENUMERATION_NOT_DUE = 0,
    UA_MAINTENANCESTATUSENUMERATION_WARNING = 1,
    UA_MAINTENANCESTATUSENUMERATION_DUE = 2,
    __UA_MAINTENANCESTATUSENUMERATION_FORCE32BIT = 0x7fffffff
} UA_MaintenanceStatusEnumeration;
UA_STATIC_ASSERT(sizeof(UA_MaintenanceStatusEnumeration) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_EUROMAP83_MAINTENANCESTATUSENUMERATION 4

/**
 * StartEnumeration
 * ^^^^^^^^^^^^^^^^
 */
typedef enum {
    UA_STARTENUMERATION_NOT_READY_TO_START = 0,
    UA_STARTENUMERATION_READY_TO_START = 1,
    UA_STARTENUMERATION_START_REQUESTED = 2,
    UA_STARTENUMERATION_STARTED = 3,
    UA_STARTENUMERATION_STOP_REQUESTED = 4,
    __UA_STARTENUMERATION_FORCE32BIT = 0x7fffffff
} UA_StartEnumeration;
UA_STATIC_ASSERT(sizeof(UA_StartEnumeration) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_EUROMAP83_STARTENUMERATION 5

/**
 * CyclicJobListElementType
 * ^^^^^^^^^^^^^^^^^^^^^^^^
 * Description of a job in a cyclic job list */
typedef struct {
    UA_String jobName;
    UA_String jobDescription;
    UA_String jobClassification;
    UA_String customerName;
    UA_String productionDatasetName;
    UA_String productionDatasetDescription;
    size_t materialSize;
    UA_String *material;
    size_t productNameSize;
    UA_String *productName;
    size_t productDescriptionSize;
    UA_String *productDescription;
    UA_String jobPriority;
    UA_DateTime plannedStart;
    UA_Double plannedProductionTime;
    UA_DateTime latestEnd;
    UA_UInt64 nominalParts;
    UA_UInt64 nominalBoxParts;
    UA_Double expectedCycleTime;
    UA_String mouldId;
    UA_UInt32 numCavities;
} UA_CyclicJobListElementType;

#define UA_TYPES_EUROMAP83_CYCLICJOBLISTELEMENTTYPE 6

/**
 * UserChangeEnumeration
 * ^^^^^^^^^^^^^^^^^^^^^
 * Information if a user logs in or off */
typedef enum {
    UA_USERCHANGEENUMERATION_LOG_ON = 0,
    UA_USERCHANGEENUMERATION_LOG_OFF = 1,
    __UA_USERCHANGEENUMERATION_FORCE32BIT = 0x7fffffff
} UA_UserChangeEnumeration;
UA_STATIC_ASSERT(sizeof(UA_UserChangeEnumeration) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_EUROMAP83_USERCHANGEENUMERATION 7

/**
 * ActiveErrorDataType
 * ^^^^^^^^^^^^^^^^^^^
 * Iinformation about an active error in a device */
typedef struct {
    UA_String id;
    UA_UInt16 severity;
    UA_LocalizedText message;
} UA_ActiveErrorDataType;

#define UA_TYPES_EUROMAP83_ACTIVEERRORDATATYPE 8

/**
 * ProductionDatasetInformationType
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 * Information on a production dataset */
typedef struct {
    UA_String name;
    UA_String description;
    UA_String mESId;
    UA_DateTime creationTimestamp;
    UA_DateTime lastModificationTimestamp;
    UA_DateTime lastSaveTimestamp;
    UA_String userName;
    size_t componentsSize;
    UA_ProductionDatasetComponentEnumeration *components;
    UA_String manufacturer;
    UA_String serialNumber;
    UA_String model;
    UA_String controllerType;
    UA_String userMachineName;
    UA_String locationName;
    size_t productNameSize;
    UA_String *productName;
    UA_String mouldId;
    UA_UInt32 numCavities;
} UA_ProductionDatasetInformationType;

#define UA_TYPES_EUROMAP83_PRODUCTIONDATASETINFORMATIONTYPE 9

/**
 * JobListElementType
 * ^^^^^^^^^^^^^^^^^^
 * Description of a job in a job list */
typedef struct {
    UA_String jobName;
    UA_String jobDescription;
    UA_String jobClassification;
    UA_String customerName;
    UA_String productionDatasetName;
    UA_String productionDatasetDescription;
    size_t materialSize;
    UA_String *material;
    size_t productNameSize;
    UA_String *productName;
    size_t productDescriptionSize;
    UA_String *productDescription;
    UA_String jobPriority;
    UA_DateTime plannedStart;
    UA_Double plannedProductionTime;
    UA_DateTime latestEnd;
} UA_JobListElementType;

#define UA_TYPES_EUROMAP83_JOBLISTELEMENTTYPE 10

/**
 * ProductionStatusEnumeration
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^^
 * Production status of the machine */
typedef enum {
    UA_PRODUCTIONSTATUSENUMERATION_OTHER = 0,
    UA_PRODUCTIONSTATUSENUMERATION_NO_PRODUCTION = 1,
    UA_PRODUCTIONSTATUSENUMERATION_START_UP = 2,
    UA_PRODUCTIONSTATUSENUMERATION_READY_FOR_PRODUCTION = 3,
    UA_PRODUCTIONSTATUSENUMERATION_PRODUCTION = 4,
    UA_PRODUCTIONSTATUSENUMERATION_DRY_RUN = 5,
    __UA_PRODUCTIONSTATUSENUMERATION_FORCE32BIT = 0x7fffffff
} UA_ProductionStatusEnumeration;
UA_STATIC_ASSERT(sizeof(UA_ProductionStatusEnumeration) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_EUROMAP83_PRODUCTIONSTATUSENUMERATION 11

/**
 * ControlModeEnumeration
 * ^^^^^^^^^^^^^^^^^^^^^^
 * Indication how the parameter is currently controlled */
typedef enum {
    UA_CONTROLMODEENUMERATION_OTHER = 0,
    UA_CONTROLMODEENUMERATION_OFF = 1,
    UA_CONTROLMODEENUMERATION_AUTOMATIC = 2,
    UA_CONTROLMODEENUMERATION_TUNING = 3,
    UA_CONTROLMODEENUMERATION_STANDBY = 4,
    UA_CONTROLMODEENUMERATION_OPEN_LOOP = 5,
    UA_CONTROLMODEENUMERATION_ONLY_MEASUREMENT = 6,
    __UA_CONTROLMODEENUMERATION_FORCE32BIT = 0x7fffffff
} UA_ControlModeEnumeration;
UA_STATIC_ASSERT(sizeof(UA_ControlModeEnumeration) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_EUROMAP83_CONTROLMODEENUMERATION 12

/**
 * CycleQualityEnumeration
 * ^^^^^^^^^^^^^^^^^^^^^^^
 * Quality of the whole cycle */
typedef enum {
    UA_CYCLEQUALITYENUMERATION_GOOD_CYCLE = 0,
    UA_CYCLEQUALITYENUMERATION_BAD_CYCLE = 1,
    UA_CYCLEQUALITYENUMERATION_TEST_SAMPLE_CYCLE = 2,
    UA_CYCLEQUALITYENUMERATION_FAILED_CYCLE = 3,
    __UA_CYCLEQUALITYENUMERATION_FORCE32BIT = 0x7fffffff
} UA_CycleQualityEnumeration;
UA_STATIC_ASSERT(sizeof(UA_CycleQualityEnumeration) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_EUROMAP83_CYCLEQUALITYENUMERATION 13

/**
 * MachineModeEnumeration
 * ^^^^^^^^^^^^^^^^^^^^^^
 * Current machine mode (as defined by mode selector on the machine) */
typedef enum {
    UA_MACHINEMODEENUMERATION_OTHER = 0,
    UA_MACHINEMODEENUMERATION_AUTOMATIC = 1,
    UA_MACHINEMODEENUMERATION_SEMI_AUTOMATIC = 2,
    UA_MACHINEMODEENUMERATION_MANUAL = 3,
    UA_MACHINEMODEENUMERATION_SETUP = 4,
    UA_MACHINEMODEENUMERATION_SLEEP = 5,
    __UA_MACHINEMODEENUMERATION_FORCE32BIT = 0x7fffffff
} UA_MachineModeEnumeration;
UA_STATIC_ASSERT(sizeof(UA_MachineModeEnumeration) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_EUROMAP83_MACHINEMODEENUMERATION 14

/**
 * LogbookEventsEnumeration
 * ^^^^^^^^^^^^^^^^^^^^^^^^
 * Information which LogbookEvents are supported by the machine */
typedef enum {
    UA_LOGBOOKEVENTSENUMERATION_PARAMETER_CHANGE = 0,
    UA_LOGBOOKEVENTSENUMERATION_USER = 1,
    UA_LOGBOOKEVENTSENUMERATION_REMOTE_ACCESS = 2,
    UA_LOGBOOKEVENTSENUMERATION_SEQUENCE_CHANGE = 3,
    UA_LOGBOOKEVENTSENUMERATION_MACHINE_MODE_CHANGE = 4,
    UA_LOGBOOKEVENTSENUMERATION_PRODUCTION_STATUS_CHANGE = 5,
    UA_LOGBOOKEVENTSENUMERATION_PRODUCTION_DATASET_CHANGE = 6,
    UA_LOGBOOKEVENTSENUMERATION_PRODUCTION_DATASET_FROZEN = 7,
    UA_LOGBOOKEVENTSENUMERATION_STANDSTILL_REASON = 8,
    UA_LOGBOOKEVENTSENUMERATION_MESSAGE = 9,
    UA_LOGBOOKEVENTSENUMERATION_USER_FEEDBACK = 10,
    __UA_LOGBOOKEVENTSENUMERATION_FORCE32BIT = 0x7fffffff
} UA_LogbookEventsEnumeration;
UA_STATIC_ASSERT(sizeof(UA_LogbookEventsEnumeration) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_EUROMAP83_LOGBOOKEVENTSENUMERATION 15

/**
 * SequenceChangeEnumeration
 * ^^^^^^^^^^^^^^^^^^^^^^^^^
 * Classification of production sequence change */
typedef enum {
    UA_SEQUENCECHANGEENUMERATION_UPDATE = 0,
    UA_SEQUENCECHANGEENUMERATION_ADD = 1,
    UA_SEQUENCECHANGEENUMERATION_MODIFY = 2,
    UA_SEQUENCECHANGEENUMERATION_MOVE = 3,
    UA_SEQUENCECHANGEENUMERATION_DELETE = 4,
    __UA_SEQUENCECHANGEENUMERATION_FORCE32BIT = 0x7fffffff
} UA_SequenceChangeEnumeration;
UA_STATIC_ASSERT(sizeof(UA_SequenceChangeEnumeration) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_EUROMAP83_SEQUENCECHANGEENUMERATION 16

/**
 * PageEntryDataType
 * ^^^^^^^^^^^^^^^^^
 * Information on a page that is implemented in the machine control system and shown on the screen of the machine */
typedef struct {
    UA_String id;
    UA_LocalizedText title;
} UA_PageEntryDataType;

#define UA_TYPES_EUROMAP83_PAGEENTRYDATATYPE 17

/**
 * StorageEnumeration
 * ^^^^^^^^^^^^^^^^^^
 * Indication which parts of the production dataset shall be activated in the machine control after writing */
typedef enum {
    UA_STORAGEENUMERATION_PRODUCTION = 1,
    UA_STORAGEENUMERATION_PREPARATION = 2,
    UA_STORAGEENUMERATION_FILE_SYSTEM = 4,
    __UA_STORAGEENUMERATION_FORCE32BIT = 0x7fffffff
} UA_StorageEnumeration;
UA_STATIC_ASSERT(sizeof(UA_StorageEnumeration) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_EUROMAP83_STORAGEENUMERATION 18

/**
 * EventOriginatorEnumeration
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^
 * Originator of an event */
typedef enum {
    UA_EVENTORIGINATORENUMERATION_OTHER = 0,
    UA_EVENTORIGINATORENUMERATION_MACHINE = 1,
    UA_EVENTORIGINATORENUMERATION_OPERATOR = 2,
    UA_EVENTORIGINATORENUMERATION_MES = 3,
    UA_EVENTORIGINATORENUMERATION_PERIPHERAL_DEVICE = 4,
    __UA_EVENTORIGINATORENUMERATION_FORCE32BIT = 0x7fffffff
} UA_EventOriginatorEnumeration;
UA_STATIC_ASSERT(sizeof(UA_EventOriginatorEnumeration) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_EUROMAP83_EVENTORIGINATORENUMERATION 19

/**
 * TemperatureZoneClassificationEnumeration
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 * Type of the temperature zone */
typedef enum {
    UA_TEMPERATUREZONECLASSIFICATIONENUMERATION_OTHER = 0,
    UA_TEMPERATUREZONECLASSIFICATIONENUMERATION_HEATING = 1,
    UA_TEMPERATUREZONECLASSIFICATIONENUMERATION_COOLING = 2,
    UA_TEMPERATUREZONECLASSIFICATIONENUMERATION_TEMPERATURE_CONTROL = 3,
    UA_TEMPERATUREZONECLASSIFICATIONENUMERATION_HOT_RUNNER = 4,
    UA_TEMPERATUREZONECLASSIFICATIONENUMERATION_MEASURING = 5,
    __UA_TEMPERATUREZONECLASSIFICATIONENUMERATION_FORCE32BIT = 0x7fffffff
} UA_TemperatureZoneClassificationEnumeration;
UA_STATIC_ASSERT(sizeof(UA_TemperatureZoneClassificationEnumeration) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_EUROMAP83_TEMPERATUREZONECLASSIFICATIONENUMERATION 20

/**
 * StandstillReasonType
 * ^^^^^^^^^^^^^^^^^^^^
 * Description of a standstill reason */
typedef struct {
    UA_String id;
    UA_LocalizedText text;
    UA_Boolean lockedByMES;
} UA_StandstillReasonType;

#define UA_TYPES_EUROMAP83_STANDSTILLREASONTYPE 21

/**
 * MouldStatusEnumeration
 * ^^^^^^^^^^^^^^^^^^^^^^
 * Current (physical) status of the mould */
typedef enum {
    UA_MOULDSTATUSENUMERATION_OTHER = 0,
    UA_MOULDSTATUSENUMERATION_MOULD_NOT_INSTALLED = 1,
    UA_MOULDSTATUSENUMERATION_MOULD_CHANGE = 2,
    UA_MOULDSTATUSENUMERATION_MOULD_INSTALLED = 3,
    __UA_MOULDSTATUSENUMERATION_FORCE32BIT = 0x7fffffff
} UA_MouldStatusEnumeration;
UA_STATIC_ASSERT(sizeof(UA_MouldStatusEnumeration) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_EUROMAP83_MOULDSTATUSENUMERATION 22

/**
 * ProductionDatasetWriteOptionsType
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 * Used as GenerateOptions in the Method GenerateFileForWrite in ProductionDatasetTransfer */
typedef struct {
    UA_StorageEnumeration storage;
    UA_String name;
    size_t componentsSize;
    UA_ProductionDatasetComponentEnumeration *components;
} UA_ProductionDatasetWriteOptionsType;

#define UA_TYPES_EUROMAP83_PRODUCTIONDATASETWRITEOPTIONSTYPE 23

/**
 * ProductionDatasetReadOptionsType
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 * Used as GenerateOptions in the Method GenerateFileForRead in ProductionDatasetTransfer */
typedef struct {
    UA_StorageEnumeration storage;
    UA_String name;
} UA_ProductionDatasetReadOptionsType;

#define UA_TYPES_EUROMAP83_PRODUCTIONDATASETREADOPTIONSTYPE 24


_UA_END_DECLS

#endif /* TYPES_EUROMAP83_GENERATED_H_ */
