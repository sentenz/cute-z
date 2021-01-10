/* Generated from Opc_Ua.EUROMAP83.1_01.Types.bsd with script /home/pi/open62541/open62541/tools/generate_datatypes.py
 * on host pi-VirtualBox by user pi at 2019-12-05 09:27:18 */

#ifndef TYPES_EUROMAP83_GENERATED_HANDLING_H_
#define TYPES_EUROMAP83_GENERATED_HANDLING_H_

#include "types_euromap83_generated.h"

_UA_BEGIN_DECLS

#if defined(__GNUC__) && __GNUC__ >= 4 && __GNUC_MINOR__ >= 6
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wmissing-field-initializers"
# pragma GCC diagnostic ignored "-Wmissing-braces"
#endif


/* PIDParametersDataType */
static UA_INLINE void
UA_PIDParametersDataType_init(UA_PIDParametersDataType *p) {
    memset(p, 0, sizeof(UA_PIDParametersDataType));
}

static UA_INLINE UA_PIDParametersDataType *
UA_PIDParametersDataType_new(void) {
    return (UA_PIDParametersDataType*)UA_new(&UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PIDPARAMETERSDATATYPE]);
}

static UA_INLINE UA_StatusCode
UA_PIDParametersDataType_copy(const UA_PIDParametersDataType *src, UA_PIDParametersDataType *dst) {
    return UA_copy(src, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PIDPARAMETERSDATATYPE]);
}

static UA_INLINE void
UA_PIDParametersDataType_deleteMembers(UA_PIDParametersDataType *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PIDPARAMETERSDATATYPE]);
}

static UA_INLINE void
UA_PIDParametersDataType_clear(UA_PIDParametersDataType *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PIDPARAMETERSDATATYPE]);
}

static UA_INLINE void
UA_PIDParametersDataType_delete(UA_PIDParametersDataType *p) {
    UA_delete(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PIDPARAMETERSDATATYPE]);
}

/* CavityCycleQualityEnumeration */
static UA_INLINE void
UA_CavityCycleQualityEnumeration_init(UA_CavityCycleQualityEnumeration *p) {
    memset(p, 0, sizeof(UA_CavityCycleQualityEnumeration));
}

static UA_INLINE UA_CavityCycleQualityEnumeration *
UA_CavityCycleQualityEnumeration_new(void) {
    return (UA_CavityCycleQualityEnumeration*)UA_new(&UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CAVITYCYCLEQUALITYENUMERATION]);
}

static UA_INLINE UA_StatusCode
UA_CavityCycleQualityEnumeration_copy(const UA_CavityCycleQualityEnumeration *src, UA_CavityCycleQualityEnumeration *dst) {
    return UA_copy(src, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CAVITYCYCLEQUALITYENUMERATION]);
}

static UA_INLINE void
UA_CavityCycleQualityEnumeration_deleteMembers(UA_CavityCycleQualityEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CAVITYCYCLEQUALITYENUMERATION]);
}

static UA_INLINE void
UA_CavityCycleQualityEnumeration_clear(UA_CavityCycleQualityEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CAVITYCYCLEQUALITYENUMERATION]);
}

static UA_INLINE void
UA_CavityCycleQualityEnumeration_delete(UA_CavityCycleQualityEnumeration *p) {
    UA_delete(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CAVITYCYCLEQUALITYENUMERATION]);
}

/* JobStatusEnumeration */
static UA_INLINE void
UA_JobStatusEnumeration_init(UA_JobStatusEnumeration *p) {
    memset(p, 0, sizeof(UA_JobStatusEnumeration));
}

static UA_INLINE UA_JobStatusEnumeration *
UA_JobStatusEnumeration_new(void) {
    return (UA_JobStatusEnumeration*)UA_new(&UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_JOBSTATUSENUMERATION]);
}

static UA_INLINE UA_StatusCode
UA_JobStatusEnumeration_copy(const UA_JobStatusEnumeration *src, UA_JobStatusEnumeration *dst) {
    return UA_copy(src, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_JOBSTATUSENUMERATION]);
}

static UA_INLINE void
UA_JobStatusEnumeration_deleteMembers(UA_JobStatusEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_JOBSTATUSENUMERATION]);
}

static UA_INLINE void
UA_JobStatusEnumeration_clear(UA_JobStatusEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_JOBSTATUSENUMERATION]);
}

static UA_INLINE void
UA_JobStatusEnumeration_delete(UA_JobStatusEnumeration *p) {
    UA_delete(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_JOBSTATUSENUMERATION]);
}

/* ProductionDatasetComponentEnumeration */
static UA_INLINE void
UA_ProductionDatasetComponentEnumeration_init(UA_ProductionDatasetComponentEnumeration *p) {
    memset(p, 0, sizeof(UA_ProductionDatasetComponentEnumeration));
}

static UA_INLINE UA_ProductionDatasetComponentEnumeration *
UA_ProductionDatasetComponentEnumeration_new(void) {
    return (UA_ProductionDatasetComponentEnumeration*)UA_new(&UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETCOMPONENTENUMERATION]);
}

static UA_INLINE UA_StatusCode
UA_ProductionDatasetComponentEnumeration_copy(const UA_ProductionDatasetComponentEnumeration *src, UA_ProductionDatasetComponentEnumeration *dst) {
    return UA_copy(src, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETCOMPONENTENUMERATION]);
}

static UA_INLINE void
UA_ProductionDatasetComponentEnumeration_deleteMembers(UA_ProductionDatasetComponentEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETCOMPONENTENUMERATION]);
}

static UA_INLINE void
UA_ProductionDatasetComponentEnumeration_clear(UA_ProductionDatasetComponentEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETCOMPONENTENUMERATION]);
}

static UA_INLINE void
UA_ProductionDatasetComponentEnumeration_delete(UA_ProductionDatasetComponentEnumeration *p) {
    UA_delete(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETCOMPONENTENUMERATION]);
}

/* MaintenanceStatusEnumeration */
static UA_INLINE void
UA_MaintenanceStatusEnumeration_init(UA_MaintenanceStatusEnumeration *p) {
    memset(p, 0, sizeof(UA_MaintenanceStatusEnumeration));
}

static UA_INLINE UA_MaintenanceStatusEnumeration *
UA_MaintenanceStatusEnumeration_new(void) {
    return (UA_MaintenanceStatusEnumeration*)UA_new(&UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_MAINTENANCESTATUSENUMERATION]);
}

static UA_INLINE UA_StatusCode
UA_MaintenanceStatusEnumeration_copy(const UA_MaintenanceStatusEnumeration *src, UA_MaintenanceStatusEnumeration *dst) {
    return UA_copy(src, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_MAINTENANCESTATUSENUMERATION]);
}

static UA_INLINE void
UA_MaintenanceStatusEnumeration_deleteMembers(UA_MaintenanceStatusEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_MAINTENANCESTATUSENUMERATION]);
}

static UA_INLINE void
UA_MaintenanceStatusEnumeration_clear(UA_MaintenanceStatusEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_MAINTENANCESTATUSENUMERATION]);
}

static UA_INLINE void
UA_MaintenanceStatusEnumeration_delete(UA_MaintenanceStatusEnumeration *p) {
    UA_delete(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_MAINTENANCESTATUSENUMERATION]);
}

/* StartEnumeration */
static UA_INLINE void
UA_StartEnumeration_init(UA_StartEnumeration *p) {
    memset(p, 0, sizeof(UA_StartEnumeration));
}

static UA_INLINE UA_StartEnumeration *
UA_StartEnumeration_new(void) {
    return (UA_StartEnumeration*)UA_new(&UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_STARTENUMERATION]);
}

static UA_INLINE UA_StatusCode
UA_StartEnumeration_copy(const UA_StartEnumeration *src, UA_StartEnumeration *dst) {
    return UA_copy(src, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_STARTENUMERATION]);
}

static UA_INLINE void
UA_StartEnumeration_deleteMembers(UA_StartEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_STARTENUMERATION]);
}

static UA_INLINE void
UA_StartEnumeration_clear(UA_StartEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_STARTENUMERATION]);
}

static UA_INLINE void
UA_StartEnumeration_delete(UA_StartEnumeration *p) {
    UA_delete(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_STARTENUMERATION]);
}

/* CyclicJobListElementType */
static UA_INLINE void
UA_CyclicJobListElementType_init(UA_CyclicJobListElementType *p) {
    memset(p, 0, sizeof(UA_CyclicJobListElementType));
}

static UA_INLINE UA_CyclicJobListElementType *
UA_CyclicJobListElementType_new(void) {
    return (UA_CyclicJobListElementType*)UA_new(&UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CYCLICJOBLISTELEMENTTYPE]);
}

static UA_INLINE UA_StatusCode
UA_CyclicJobListElementType_copy(const UA_CyclicJobListElementType *src, UA_CyclicJobListElementType *dst) {
    return UA_copy(src, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CYCLICJOBLISTELEMENTTYPE]);
}

static UA_INLINE void
UA_CyclicJobListElementType_deleteMembers(UA_CyclicJobListElementType *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CYCLICJOBLISTELEMENTTYPE]);
}

static UA_INLINE void
UA_CyclicJobListElementType_clear(UA_CyclicJobListElementType *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CYCLICJOBLISTELEMENTTYPE]);
}

static UA_INLINE void
UA_CyclicJobListElementType_delete(UA_CyclicJobListElementType *p) {
    UA_delete(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CYCLICJOBLISTELEMENTTYPE]);
}

/* UserChangeEnumeration */
static UA_INLINE void
UA_UserChangeEnumeration_init(UA_UserChangeEnumeration *p) {
    memset(p, 0, sizeof(UA_UserChangeEnumeration));
}

static UA_INLINE UA_UserChangeEnumeration *
UA_UserChangeEnumeration_new(void) {
    return (UA_UserChangeEnumeration*)UA_new(&UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_USERCHANGEENUMERATION]);
}

static UA_INLINE UA_StatusCode
UA_UserChangeEnumeration_copy(const UA_UserChangeEnumeration *src, UA_UserChangeEnumeration *dst) {
    return UA_copy(src, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_USERCHANGEENUMERATION]);
}

static UA_INLINE void
UA_UserChangeEnumeration_deleteMembers(UA_UserChangeEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_USERCHANGEENUMERATION]);
}

static UA_INLINE void
UA_UserChangeEnumeration_clear(UA_UserChangeEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_USERCHANGEENUMERATION]);
}

static UA_INLINE void
UA_UserChangeEnumeration_delete(UA_UserChangeEnumeration *p) {
    UA_delete(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_USERCHANGEENUMERATION]);
}

/* ActiveErrorDataType */
static UA_INLINE void
UA_ActiveErrorDataType_init(UA_ActiveErrorDataType *p) {
    memset(p, 0, sizeof(UA_ActiveErrorDataType));
}

static UA_INLINE UA_ActiveErrorDataType *
UA_ActiveErrorDataType_new(void) {
    return (UA_ActiveErrorDataType*)UA_new(&UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_ACTIVEERRORDATATYPE]);
}

static UA_INLINE UA_StatusCode
UA_ActiveErrorDataType_copy(const UA_ActiveErrorDataType *src, UA_ActiveErrorDataType *dst) {
    return UA_copy(src, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_ACTIVEERRORDATATYPE]);
}

static UA_INLINE void
UA_ActiveErrorDataType_deleteMembers(UA_ActiveErrorDataType *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_ACTIVEERRORDATATYPE]);
}

static UA_INLINE void
UA_ActiveErrorDataType_clear(UA_ActiveErrorDataType *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_ACTIVEERRORDATATYPE]);
}

static UA_INLINE void
UA_ActiveErrorDataType_delete(UA_ActiveErrorDataType *p) {
    UA_delete(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_ACTIVEERRORDATATYPE]);
}

/* ProductionDatasetInformationType */
static UA_INLINE void
UA_ProductionDatasetInformationType_init(UA_ProductionDatasetInformationType *p) {
    memset(p, 0, sizeof(UA_ProductionDatasetInformationType));
}

static UA_INLINE UA_ProductionDatasetInformationType *
UA_ProductionDatasetInformationType_new(void) {
    return (UA_ProductionDatasetInformationType*)UA_new(&UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETINFORMATIONTYPE]);
}

static UA_INLINE UA_StatusCode
UA_ProductionDatasetInformationType_copy(const UA_ProductionDatasetInformationType *src, UA_ProductionDatasetInformationType *dst) {
    return UA_copy(src, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETINFORMATIONTYPE]);
}

static UA_INLINE void
UA_ProductionDatasetInformationType_deleteMembers(UA_ProductionDatasetInformationType *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETINFORMATIONTYPE]);
}

static UA_INLINE void
UA_ProductionDatasetInformationType_clear(UA_ProductionDatasetInformationType *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETINFORMATIONTYPE]);
}

static UA_INLINE void
UA_ProductionDatasetInformationType_delete(UA_ProductionDatasetInformationType *p) {
    UA_delete(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETINFORMATIONTYPE]);
}

/* JobListElementType */
static UA_INLINE void
UA_JobListElementType_init(UA_JobListElementType *p) {
    memset(p, 0, sizeof(UA_JobListElementType));
}

static UA_INLINE UA_JobListElementType *
UA_JobListElementType_new(void) {
    return (UA_JobListElementType*)UA_new(&UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_JOBLISTELEMENTTYPE]);
}

static UA_INLINE UA_StatusCode
UA_JobListElementType_copy(const UA_JobListElementType *src, UA_JobListElementType *dst) {
    return UA_copy(src, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_JOBLISTELEMENTTYPE]);
}

static UA_INLINE void
UA_JobListElementType_deleteMembers(UA_JobListElementType *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_JOBLISTELEMENTTYPE]);
}

static UA_INLINE void
UA_JobListElementType_clear(UA_JobListElementType *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_JOBLISTELEMENTTYPE]);
}

static UA_INLINE void
UA_JobListElementType_delete(UA_JobListElementType *p) {
    UA_delete(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_JOBLISTELEMENTTYPE]);
}

/* ProductionStatusEnumeration */
static UA_INLINE void
UA_ProductionStatusEnumeration_init(UA_ProductionStatusEnumeration *p) {
    memset(p, 0, sizeof(UA_ProductionStatusEnumeration));
}

static UA_INLINE UA_ProductionStatusEnumeration *
UA_ProductionStatusEnumeration_new(void) {
    return (UA_ProductionStatusEnumeration*)UA_new(&UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONSTATUSENUMERATION]);
}

static UA_INLINE UA_StatusCode
UA_ProductionStatusEnumeration_copy(const UA_ProductionStatusEnumeration *src, UA_ProductionStatusEnumeration *dst) {
    return UA_copy(src, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONSTATUSENUMERATION]);
}

static UA_INLINE void
UA_ProductionStatusEnumeration_deleteMembers(UA_ProductionStatusEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONSTATUSENUMERATION]);
}

static UA_INLINE void
UA_ProductionStatusEnumeration_clear(UA_ProductionStatusEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONSTATUSENUMERATION]);
}

static UA_INLINE void
UA_ProductionStatusEnumeration_delete(UA_ProductionStatusEnumeration *p) {
    UA_delete(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONSTATUSENUMERATION]);
}

/* ControlModeEnumeration */
static UA_INLINE void
UA_ControlModeEnumeration_init(UA_ControlModeEnumeration *p) {
    memset(p, 0, sizeof(UA_ControlModeEnumeration));
}

static UA_INLINE UA_ControlModeEnumeration *
UA_ControlModeEnumeration_new(void) {
    return (UA_ControlModeEnumeration*)UA_new(&UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CONTROLMODEENUMERATION]);
}

static UA_INLINE UA_StatusCode
UA_ControlModeEnumeration_copy(const UA_ControlModeEnumeration *src, UA_ControlModeEnumeration *dst) {
    return UA_copy(src, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CONTROLMODEENUMERATION]);
}

static UA_INLINE void
UA_ControlModeEnumeration_deleteMembers(UA_ControlModeEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CONTROLMODEENUMERATION]);
}

static UA_INLINE void
UA_ControlModeEnumeration_clear(UA_ControlModeEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CONTROLMODEENUMERATION]);
}

static UA_INLINE void
UA_ControlModeEnumeration_delete(UA_ControlModeEnumeration *p) {
    UA_delete(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CONTROLMODEENUMERATION]);
}

/* CycleQualityEnumeration */
static UA_INLINE void
UA_CycleQualityEnumeration_init(UA_CycleQualityEnumeration *p) {
    memset(p, 0, sizeof(UA_CycleQualityEnumeration));
}

static UA_INLINE UA_CycleQualityEnumeration *
UA_CycleQualityEnumeration_new(void) {
    return (UA_CycleQualityEnumeration*)UA_new(&UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CYCLEQUALITYENUMERATION]);
}

static UA_INLINE UA_StatusCode
UA_CycleQualityEnumeration_copy(const UA_CycleQualityEnumeration *src, UA_CycleQualityEnumeration *dst) {
    return UA_copy(src, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CYCLEQUALITYENUMERATION]);
}

static UA_INLINE void
UA_CycleQualityEnumeration_deleteMembers(UA_CycleQualityEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CYCLEQUALITYENUMERATION]);
}

static UA_INLINE void
UA_CycleQualityEnumeration_clear(UA_CycleQualityEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CYCLEQUALITYENUMERATION]);
}

static UA_INLINE void
UA_CycleQualityEnumeration_delete(UA_CycleQualityEnumeration *p) {
    UA_delete(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CYCLEQUALITYENUMERATION]);
}

/* MachineModeEnumeration */
static UA_INLINE void
UA_MachineModeEnumeration_init(UA_MachineModeEnumeration *p) {
    memset(p, 0, sizeof(UA_MachineModeEnumeration));
}

static UA_INLINE UA_MachineModeEnumeration *
UA_MachineModeEnumeration_new(void) {
    return (UA_MachineModeEnumeration*)UA_new(&UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_MACHINEMODEENUMERATION]);
}

static UA_INLINE UA_StatusCode
UA_MachineModeEnumeration_copy(const UA_MachineModeEnumeration *src, UA_MachineModeEnumeration *dst) {
    return UA_copy(src, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_MACHINEMODEENUMERATION]);
}

static UA_INLINE void
UA_MachineModeEnumeration_deleteMembers(UA_MachineModeEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_MACHINEMODEENUMERATION]);
}

static UA_INLINE void
UA_MachineModeEnumeration_clear(UA_MachineModeEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_MACHINEMODEENUMERATION]);
}

static UA_INLINE void
UA_MachineModeEnumeration_delete(UA_MachineModeEnumeration *p) {
    UA_delete(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_MACHINEMODEENUMERATION]);
}

/* LogbookEventsEnumeration */
static UA_INLINE void
UA_LogbookEventsEnumeration_init(UA_LogbookEventsEnumeration *p) {
    memset(p, 0, sizeof(UA_LogbookEventsEnumeration));
}

static UA_INLINE UA_LogbookEventsEnumeration *
UA_LogbookEventsEnumeration_new(void) {
    return (UA_LogbookEventsEnumeration*)UA_new(&UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_LOGBOOKEVENTSENUMERATION]);
}

static UA_INLINE UA_StatusCode
UA_LogbookEventsEnumeration_copy(const UA_LogbookEventsEnumeration *src, UA_LogbookEventsEnumeration *dst) {
    return UA_copy(src, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_LOGBOOKEVENTSENUMERATION]);
}

static UA_INLINE void
UA_LogbookEventsEnumeration_deleteMembers(UA_LogbookEventsEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_LOGBOOKEVENTSENUMERATION]);
}

static UA_INLINE void
UA_LogbookEventsEnumeration_clear(UA_LogbookEventsEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_LOGBOOKEVENTSENUMERATION]);
}

static UA_INLINE void
UA_LogbookEventsEnumeration_delete(UA_LogbookEventsEnumeration *p) {
    UA_delete(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_LOGBOOKEVENTSENUMERATION]);
}

/* SequenceChangeEnumeration */
static UA_INLINE void
UA_SequenceChangeEnumeration_init(UA_SequenceChangeEnumeration *p) {
    memset(p, 0, sizeof(UA_SequenceChangeEnumeration));
}

static UA_INLINE UA_SequenceChangeEnumeration *
UA_SequenceChangeEnumeration_new(void) {
    return (UA_SequenceChangeEnumeration*)UA_new(&UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_SEQUENCECHANGEENUMERATION]);
}

static UA_INLINE UA_StatusCode
UA_SequenceChangeEnumeration_copy(const UA_SequenceChangeEnumeration *src, UA_SequenceChangeEnumeration *dst) {
    return UA_copy(src, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_SEQUENCECHANGEENUMERATION]);
}

static UA_INLINE void
UA_SequenceChangeEnumeration_deleteMembers(UA_SequenceChangeEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_SEQUENCECHANGEENUMERATION]);
}

static UA_INLINE void
UA_SequenceChangeEnumeration_clear(UA_SequenceChangeEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_SEQUENCECHANGEENUMERATION]);
}

static UA_INLINE void
UA_SequenceChangeEnumeration_delete(UA_SequenceChangeEnumeration *p) {
    UA_delete(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_SEQUENCECHANGEENUMERATION]);
}

/* PageEntryDataType */
static UA_INLINE void
UA_PageEntryDataType_init(UA_PageEntryDataType *p) {
    memset(p, 0, sizeof(UA_PageEntryDataType));
}

static UA_INLINE UA_PageEntryDataType *
UA_PageEntryDataType_new(void) {
    return (UA_PageEntryDataType*)UA_new(&UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PAGEENTRYDATATYPE]);
}

static UA_INLINE UA_StatusCode
UA_PageEntryDataType_copy(const UA_PageEntryDataType *src, UA_PageEntryDataType *dst) {
    return UA_copy(src, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PAGEENTRYDATATYPE]);
}

static UA_INLINE void
UA_PageEntryDataType_deleteMembers(UA_PageEntryDataType *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PAGEENTRYDATATYPE]);
}

static UA_INLINE void
UA_PageEntryDataType_clear(UA_PageEntryDataType *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PAGEENTRYDATATYPE]);
}

static UA_INLINE void
UA_PageEntryDataType_delete(UA_PageEntryDataType *p) {
    UA_delete(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PAGEENTRYDATATYPE]);
}

/* StorageEnumeration */
static UA_INLINE void
UA_StorageEnumeration_init(UA_StorageEnumeration *p) {
    memset(p, 0, sizeof(UA_StorageEnumeration));
}

static UA_INLINE UA_StorageEnumeration *
UA_StorageEnumeration_new(void) {
    return (UA_StorageEnumeration*)UA_new(&UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_STORAGEENUMERATION]);
}

static UA_INLINE UA_StatusCode
UA_StorageEnumeration_copy(const UA_StorageEnumeration *src, UA_StorageEnumeration *dst) {
    return UA_copy(src, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_STORAGEENUMERATION]);
}

static UA_INLINE void
UA_StorageEnumeration_deleteMembers(UA_StorageEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_STORAGEENUMERATION]);
}

static UA_INLINE void
UA_StorageEnumeration_clear(UA_StorageEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_STORAGEENUMERATION]);
}

static UA_INLINE void
UA_StorageEnumeration_delete(UA_StorageEnumeration *p) {
    UA_delete(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_STORAGEENUMERATION]);
}

/* EventOriginatorEnumeration */
static UA_INLINE void
UA_EventOriginatorEnumeration_init(UA_EventOriginatorEnumeration *p) {
    memset(p, 0, sizeof(UA_EventOriginatorEnumeration));
}

static UA_INLINE UA_EventOriginatorEnumeration *
UA_EventOriginatorEnumeration_new(void) {
    return (UA_EventOriginatorEnumeration*)UA_new(&UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_EVENTORIGINATORENUMERATION]);
}

static UA_INLINE UA_StatusCode
UA_EventOriginatorEnumeration_copy(const UA_EventOriginatorEnumeration *src, UA_EventOriginatorEnumeration *dst) {
    return UA_copy(src, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_EVENTORIGINATORENUMERATION]);
}

static UA_INLINE void
UA_EventOriginatorEnumeration_deleteMembers(UA_EventOriginatorEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_EVENTORIGINATORENUMERATION]);
}

static UA_INLINE void
UA_EventOriginatorEnumeration_clear(UA_EventOriginatorEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_EVENTORIGINATORENUMERATION]);
}

static UA_INLINE void
UA_EventOriginatorEnumeration_delete(UA_EventOriginatorEnumeration *p) {
    UA_delete(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_EVENTORIGINATORENUMERATION]);
}

/* TemperatureZoneClassificationEnumeration */
static UA_INLINE void
UA_TemperatureZoneClassificationEnumeration_init(UA_TemperatureZoneClassificationEnumeration *p) {
    memset(p, 0, sizeof(UA_TemperatureZoneClassificationEnumeration));
}

static UA_INLINE UA_TemperatureZoneClassificationEnumeration *
UA_TemperatureZoneClassificationEnumeration_new(void) {
    return (UA_TemperatureZoneClassificationEnumeration*)UA_new(&UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_TEMPERATUREZONECLASSIFICATIONENUMERATION]);
}

static UA_INLINE UA_StatusCode
UA_TemperatureZoneClassificationEnumeration_copy(const UA_TemperatureZoneClassificationEnumeration *src, UA_TemperatureZoneClassificationEnumeration *dst) {
    return UA_copy(src, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_TEMPERATUREZONECLASSIFICATIONENUMERATION]);
}

static UA_INLINE void
UA_TemperatureZoneClassificationEnumeration_deleteMembers(UA_TemperatureZoneClassificationEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_TEMPERATUREZONECLASSIFICATIONENUMERATION]);
}

static UA_INLINE void
UA_TemperatureZoneClassificationEnumeration_clear(UA_TemperatureZoneClassificationEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_TEMPERATUREZONECLASSIFICATIONENUMERATION]);
}

static UA_INLINE void
UA_TemperatureZoneClassificationEnumeration_delete(UA_TemperatureZoneClassificationEnumeration *p) {
    UA_delete(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_TEMPERATUREZONECLASSIFICATIONENUMERATION]);
}

/* StandstillReasonType */
static UA_INLINE void
UA_StandstillReasonType_init(UA_StandstillReasonType *p) {
    memset(p, 0, sizeof(UA_StandstillReasonType));
}

static UA_INLINE UA_StandstillReasonType *
UA_StandstillReasonType_new(void) {
    return (UA_StandstillReasonType*)UA_new(&UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_STANDSTILLREASONTYPE]);
}

static UA_INLINE UA_StatusCode
UA_StandstillReasonType_copy(const UA_StandstillReasonType *src, UA_StandstillReasonType *dst) {
    return UA_copy(src, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_STANDSTILLREASONTYPE]);
}

static UA_INLINE void
UA_StandstillReasonType_deleteMembers(UA_StandstillReasonType *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_STANDSTILLREASONTYPE]);
}

static UA_INLINE void
UA_StandstillReasonType_clear(UA_StandstillReasonType *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_STANDSTILLREASONTYPE]);
}

static UA_INLINE void
UA_StandstillReasonType_delete(UA_StandstillReasonType *p) {
    UA_delete(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_STANDSTILLREASONTYPE]);
}

/* MouldStatusEnumeration */
static UA_INLINE void
UA_MouldStatusEnumeration_init(UA_MouldStatusEnumeration *p) {
    memset(p, 0, sizeof(UA_MouldStatusEnumeration));
}

static UA_INLINE UA_MouldStatusEnumeration *
UA_MouldStatusEnumeration_new(void) {
    return (UA_MouldStatusEnumeration*)UA_new(&UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_MOULDSTATUSENUMERATION]);
}

static UA_INLINE UA_StatusCode
UA_MouldStatusEnumeration_copy(const UA_MouldStatusEnumeration *src, UA_MouldStatusEnumeration *dst) {
    return UA_copy(src, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_MOULDSTATUSENUMERATION]);
}

static UA_INLINE void
UA_MouldStatusEnumeration_deleteMembers(UA_MouldStatusEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_MOULDSTATUSENUMERATION]);
}

static UA_INLINE void
UA_MouldStatusEnumeration_clear(UA_MouldStatusEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_MOULDSTATUSENUMERATION]);
}

static UA_INLINE void
UA_MouldStatusEnumeration_delete(UA_MouldStatusEnumeration *p) {
    UA_delete(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_MOULDSTATUSENUMERATION]);
}

/* ProductionDatasetWriteOptionsType */
static UA_INLINE void
UA_ProductionDatasetWriteOptionsType_init(UA_ProductionDatasetWriteOptionsType *p) {
    memset(p, 0, sizeof(UA_ProductionDatasetWriteOptionsType));
}

static UA_INLINE UA_ProductionDatasetWriteOptionsType *
UA_ProductionDatasetWriteOptionsType_new(void) {
    return (UA_ProductionDatasetWriteOptionsType*)UA_new(&UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETWRITEOPTIONSTYPE]);
}

static UA_INLINE UA_StatusCode
UA_ProductionDatasetWriteOptionsType_copy(const UA_ProductionDatasetWriteOptionsType *src, UA_ProductionDatasetWriteOptionsType *dst) {
    return UA_copy(src, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETWRITEOPTIONSTYPE]);
}

static UA_INLINE void
UA_ProductionDatasetWriteOptionsType_deleteMembers(UA_ProductionDatasetWriteOptionsType *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETWRITEOPTIONSTYPE]);
}

static UA_INLINE void
UA_ProductionDatasetWriteOptionsType_clear(UA_ProductionDatasetWriteOptionsType *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETWRITEOPTIONSTYPE]);
}

static UA_INLINE void
UA_ProductionDatasetWriteOptionsType_delete(UA_ProductionDatasetWriteOptionsType *p) {
    UA_delete(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETWRITEOPTIONSTYPE]);
}

/* ProductionDatasetReadOptionsType */
static UA_INLINE void
UA_ProductionDatasetReadOptionsType_init(UA_ProductionDatasetReadOptionsType *p) {
    memset(p, 0, sizeof(UA_ProductionDatasetReadOptionsType));
}

static UA_INLINE UA_ProductionDatasetReadOptionsType *
UA_ProductionDatasetReadOptionsType_new(void) {
    return (UA_ProductionDatasetReadOptionsType*)UA_new(&UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETREADOPTIONSTYPE]);
}

static UA_INLINE UA_StatusCode
UA_ProductionDatasetReadOptionsType_copy(const UA_ProductionDatasetReadOptionsType *src, UA_ProductionDatasetReadOptionsType *dst) {
    return UA_copy(src, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETREADOPTIONSTYPE]);
}

static UA_INLINE void
UA_ProductionDatasetReadOptionsType_deleteMembers(UA_ProductionDatasetReadOptionsType *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETREADOPTIONSTYPE]);
}

static UA_INLINE void
UA_ProductionDatasetReadOptionsType_clear(UA_ProductionDatasetReadOptionsType *p) {
    UA_clear(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETREADOPTIONSTYPE]);
}

static UA_INLINE void
UA_ProductionDatasetReadOptionsType_delete(UA_ProductionDatasetReadOptionsType *p) {
    UA_delete(p, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETREADOPTIONSTYPE]);
}

#if defined(__GNUC__) && __GNUC__ >= 4 && __GNUC_MINOR__ >= 6
# pragma GCC diagnostic pop
#endif

_UA_END_DECLS

#endif /* TYPES_EUROMAP83_GENERATED_HANDLING_H_ */
