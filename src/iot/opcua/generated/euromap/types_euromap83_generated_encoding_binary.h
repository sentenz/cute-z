/* Generated from Opc_Ua.EUROMAP83.1_01.Types.bsd with script /home/pi/open62541/open62541/tools/generate_datatypes.py
 * on host pi-VirtualBox by user pi at 2019-12-05 09:27:18 */

#ifdef UA_ENABLE_AMALGAMATION
# include "open62541.h"
#else
# include "ua_types_encoding_binary.h"
# include "types_euromap83_generated.h"
#endif



/* PIDParametersDataType */
static UA_INLINE size_t
UA_PIDParametersDataType_calcSizeBinary(const UA_PIDParametersDataType *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PIDPARAMETERSDATATYPE]);
}
static UA_INLINE UA_StatusCode
UA_PIDParametersDataType_encodeBinary(const UA_PIDParametersDataType *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PIDPARAMETERSDATATYPE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_PIDParametersDataType_decodeBinary(const UA_ByteString *src, size_t *offset, UA_PIDParametersDataType *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PIDPARAMETERSDATATYPE], NULL);
}

/* CavityCycleQualityEnumeration */
static UA_INLINE size_t
UA_CavityCycleQualityEnumeration_calcSizeBinary(const UA_CavityCycleQualityEnumeration *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CAVITYCYCLEQUALITYENUMERATION]);
}
static UA_INLINE UA_StatusCode
UA_CavityCycleQualityEnumeration_encodeBinary(const UA_CavityCycleQualityEnumeration *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CAVITYCYCLEQUALITYENUMERATION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_CavityCycleQualityEnumeration_decodeBinary(const UA_ByteString *src, size_t *offset, UA_CavityCycleQualityEnumeration *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CAVITYCYCLEQUALITYENUMERATION], NULL);
}

/* JobStatusEnumeration */
static UA_INLINE size_t
UA_JobStatusEnumeration_calcSizeBinary(const UA_JobStatusEnumeration *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_JOBSTATUSENUMERATION]);
}
static UA_INLINE UA_StatusCode
UA_JobStatusEnumeration_encodeBinary(const UA_JobStatusEnumeration *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_JOBSTATUSENUMERATION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_JobStatusEnumeration_decodeBinary(const UA_ByteString *src, size_t *offset, UA_JobStatusEnumeration *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_JOBSTATUSENUMERATION], NULL);
}

/* ProductionDatasetComponentEnumeration */
static UA_INLINE size_t
UA_ProductionDatasetComponentEnumeration_calcSizeBinary(const UA_ProductionDatasetComponentEnumeration *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETCOMPONENTENUMERATION]);
}
static UA_INLINE UA_StatusCode
UA_ProductionDatasetComponentEnumeration_encodeBinary(const UA_ProductionDatasetComponentEnumeration *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETCOMPONENTENUMERATION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ProductionDatasetComponentEnumeration_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ProductionDatasetComponentEnumeration *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETCOMPONENTENUMERATION], NULL);
}

/* MaintenanceStatusEnumeration */
static UA_INLINE size_t
UA_MaintenanceStatusEnumeration_calcSizeBinary(const UA_MaintenanceStatusEnumeration *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_MAINTENANCESTATUSENUMERATION]);
}
static UA_INLINE UA_StatusCode
UA_MaintenanceStatusEnumeration_encodeBinary(const UA_MaintenanceStatusEnumeration *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_MAINTENANCESTATUSENUMERATION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_MaintenanceStatusEnumeration_decodeBinary(const UA_ByteString *src, size_t *offset, UA_MaintenanceStatusEnumeration *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_MAINTENANCESTATUSENUMERATION], NULL);
}

/* StartEnumeration */
static UA_INLINE size_t
UA_StartEnumeration_calcSizeBinary(const UA_StartEnumeration *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_STARTENUMERATION]);
}
static UA_INLINE UA_StatusCode
UA_StartEnumeration_encodeBinary(const UA_StartEnumeration *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_STARTENUMERATION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_StartEnumeration_decodeBinary(const UA_ByteString *src, size_t *offset, UA_StartEnumeration *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_STARTENUMERATION], NULL);
}

/* CyclicJobListElementType */
static UA_INLINE size_t
UA_CyclicJobListElementType_calcSizeBinary(const UA_CyclicJobListElementType *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CYCLICJOBLISTELEMENTTYPE]);
}
static UA_INLINE UA_StatusCode
UA_CyclicJobListElementType_encodeBinary(const UA_CyclicJobListElementType *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CYCLICJOBLISTELEMENTTYPE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_CyclicJobListElementType_decodeBinary(const UA_ByteString *src, size_t *offset, UA_CyclicJobListElementType *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CYCLICJOBLISTELEMENTTYPE], NULL);
}

/* UserChangeEnumeration */
static UA_INLINE size_t
UA_UserChangeEnumeration_calcSizeBinary(const UA_UserChangeEnumeration *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_USERCHANGEENUMERATION]);
}
static UA_INLINE UA_StatusCode
UA_UserChangeEnumeration_encodeBinary(const UA_UserChangeEnumeration *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_USERCHANGEENUMERATION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_UserChangeEnumeration_decodeBinary(const UA_ByteString *src, size_t *offset, UA_UserChangeEnumeration *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_USERCHANGEENUMERATION], NULL);
}

/* ActiveErrorDataType */
static UA_INLINE size_t
UA_ActiveErrorDataType_calcSizeBinary(const UA_ActiveErrorDataType *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_ACTIVEERRORDATATYPE]);
}
static UA_INLINE UA_StatusCode
UA_ActiveErrorDataType_encodeBinary(const UA_ActiveErrorDataType *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_ACTIVEERRORDATATYPE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ActiveErrorDataType_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ActiveErrorDataType *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_ACTIVEERRORDATATYPE], NULL);
}

/* ProductionDatasetInformationType */
static UA_INLINE size_t
UA_ProductionDatasetInformationType_calcSizeBinary(const UA_ProductionDatasetInformationType *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETINFORMATIONTYPE]);
}
static UA_INLINE UA_StatusCode
UA_ProductionDatasetInformationType_encodeBinary(const UA_ProductionDatasetInformationType *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETINFORMATIONTYPE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ProductionDatasetInformationType_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ProductionDatasetInformationType *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETINFORMATIONTYPE], NULL);
}

/* JobListElementType */
static UA_INLINE size_t
UA_JobListElementType_calcSizeBinary(const UA_JobListElementType *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_JOBLISTELEMENTTYPE]);
}
static UA_INLINE UA_StatusCode
UA_JobListElementType_encodeBinary(const UA_JobListElementType *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_JOBLISTELEMENTTYPE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_JobListElementType_decodeBinary(const UA_ByteString *src, size_t *offset, UA_JobListElementType *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_JOBLISTELEMENTTYPE], NULL);
}

/* ProductionStatusEnumeration */
static UA_INLINE size_t
UA_ProductionStatusEnumeration_calcSizeBinary(const UA_ProductionStatusEnumeration *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONSTATUSENUMERATION]);
}
static UA_INLINE UA_StatusCode
UA_ProductionStatusEnumeration_encodeBinary(const UA_ProductionStatusEnumeration *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONSTATUSENUMERATION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ProductionStatusEnumeration_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ProductionStatusEnumeration *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONSTATUSENUMERATION], NULL);
}

/* ControlModeEnumeration */
static UA_INLINE size_t
UA_ControlModeEnumeration_calcSizeBinary(const UA_ControlModeEnumeration *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CONTROLMODEENUMERATION]);
}
static UA_INLINE UA_StatusCode
UA_ControlModeEnumeration_encodeBinary(const UA_ControlModeEnumeration *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CONTROLMODEENUMERATION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ControlModeEnumeration_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ControlModeEnumeration *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CONTROLMODEENUMERATION], NULL);
}

/* CycleQualityEnumeration */
static UA_INLINE size_t
UA_CycleQualityEnumeration_calcSizeBinary(const UA_CycleQualityEnumeration *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CYCLEQUALITYENUMERATION]);
}
static UA_INLINE UA_StatusCode
UA_CycleQualityEnumeration_encodeBinary(const UA_CycleQualityEnumeration *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CYCLEQUALITYENUMERATION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_CycleQualityEnumeration_decodeBinary(const UA_ByteString *src, size_t *offset, UA_CycleQualityEnumeration *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_CYCLEQUALITYENUMERATION], NULL);
}

/* MachineModeEnumeration */
static UA_INLINE size_t
UA_MachineModeEnumeration_calcSizeBinary(const UA_MachineModeEnumeration *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_MACHINEMODEENUMERATION]);
}
static UA_INLINE UA_StatusCode
UA_MachineModeEnumeration_encodeBinary(const UA_MachineModeEnumeration *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_MACHINEMODEENUMERATION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_MachineModeEnumeration_decodeBinary(const UA_ByteString *src, size_t *offset, UA_MachineModeEnumeration *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_MACHINEMODEENUMERATION], NULL);
}

/* LogbookEventsEnumeration */
static UA_INLINE size_t
UA_LogbookEventsEnumeration_calcSizeBinary(const UA_LogbookEventsEnumeration *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_LOGBOOKEVENTSENUMERATION]);
}
static UA_INLINE UA_StatusCode
UA_LogbookEventsEnumeration_encodeBinary(const UA_LogbookEventsEnumeration *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_LOGBOOKEVENTSENUMERATION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_LogbookEventsEnumeration_decodeBinary(const UA_ByteString *src, size_t *offset, UA_LogbookEventsEnumeration *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_LOGBOOKEVENTSENUMERATION], NULL);
}

/* SequenceChangeEnumeration */
static UA_INLINE size_t
UA_SequenceChangeEnumeration_calcSizeBinary(const UA_SequenceChangeEnumeration *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_SEQUENCECHANGEENUMERATION]);
}
static UA_INLINE UA_StatusCode
UA_SequenceChangeEnumeration_encodeBinary(const UA_SequenceChangeEnumeration *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_SEQUENCECHANGEENUMERATION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_SequenceChangeEnumeration_decodeBinary(const UA_ByteString *src, size_t *offset, UA_SequenceChangeEnumeration *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_SEQUENCECHANGEENUMERATION], NULL);
}

/* PageEntryDataType */
static UA_INLINE size_t
UA_PageEntryDataType_calcSizeBinary(const UA_PageEntryDataType *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PAGEENTRYDATATYPE]);
}
static UA_INLINE UA_StatusCode
UA_PageEntryDataType_encodeBinary(const UA_PageEntryDataType *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PAGEENTRYDATATYPE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_PageEntryDataType_decodeBinary(const UA_ByteString *src, size_t *offset, UA_PageEntryDataType *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PAGEENTRYDATATYPE], NULL);
}

/* StorageEnumeration */
static UA_INLINE size_t
UA_StorageEnumeration_calcSizeBinary(const UA_StorageEnumeration *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_STORAGEENUMERATION]);
}
static UA_INLINE UA_StatusCode
UA_StorageEnumeration_encodeBinary(const UA_StorageEnumeration *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_STORAGEENUMERATION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_StorageEnumeration_decodeBinary(const UA_ByteString *src, size_t *offset, UA_StorageEnumeration *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_STORAGEENUMERATION], NULL);
}

/* EventOriginatorEnumeration */
static UA_INLINE size_t
UA_EventOriginatorEnumeration_calcSizeBinary(const UA_EventOriginatorEnumeration *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_EVENTORIGINATORENUMERATION]);
}
static UA_INLINE UA_StatusCode
UA_EventOriginatorEnumeration_encodeBinary(const UA_EventOriginatorEnumeration *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_EVENTORIGINATORENUMERATION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_EventOriginatorEnumeration_decodeBinary(const UA_ByteString *src, size_t *offset, UA_EventOriginatorEnumeration *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_EVENTORIGINATORENUMERATION], NULL);
}

/* TemperatureZoneClassificationEnumeration */
static UA_INLINE size_t
UA_TemperatureZoneClassificationEnumeration_calcSizeBinary(const UA_TemperatureZoneClassificationEnumeration *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_TEMPERATUREZONECLASSIFICATIONENUMERATION]);
}
static UA_INLINE UA_StatusCode
UA_TemperatureZoneClassificationEnumeration_encodeBinary(const UA_TemperatureZoneClassificationEnumeration *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_TEMPERATUREZONECLASSIFICATIONENUMERATION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_TemperatureZoneClassificationEnumeration_decodeBinary(const UA_ByteString *src, size_t *offset, UA_TemperatureZoneClassificationEnumeration *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_TEMPERATUREZONECLASSIFICATIONENUMERATION], NULL);
}

/* StandstillReasonType */
static UA_INLINE size_t
UA_StandstillReasonType_calcSizeBinary(const UA_StandstillReasonType *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_STANDSTILLREASONTYPE]);
}
static UA_INLINE UA_StatusCode
UA_StandstillReasonType_encodeBinary(const UA_StandstillReasonType *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_STANDSTILLREASONTYPE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_StandstillReasonType_decodeBinary(const UA_ByteString *src, size_t *offset, UA_StandstillReasonType *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_STANDSTILLREASONTYPE], NULL);
}

/* MouldStatusEnumeration */
static UA_INLINE size_t
UA_MouldStatusEnumeration_calcSizeBinary(const UA_MouldStatusEnumeration *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_MOULDSTATUSENUMERATION]);
}
static UA_INLINE UA_StatusCode
UA_MouldStatusEnumeration_encodeBinary(const UA_MouldStatusEnumeration *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_MOULDSTATUSENUMERATION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_MouldStatusEnumeration_decodeBinary(const UA_ByteString *src, size_t *offset, UA_MouldStatusEnumeration *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_MOULDSTATUSENUMERATION], NULL);
}

/* ProductionDatasetWriteOptionsType */
static UA_INLINE size_t
UA_ProductionDatasetWriteOptionsType_calcSizeBinary(const UA_ProductionDatasetWriteOptionsType *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETWRITEOPTIONSTYPE]);
}
static UA_INLINE UA_StatusCode
UA_ProductionDatasetWriteOptionsType_encodeBinary(const UA_ProductionDatasetWriteOptionsType *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETWRITEOPTIONSTYPE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ProductionDatasetWriteOptionsType_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ProductionDatasetWriteOptionsType *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETWRITEOPTIONSTYPE], NULL);
}

/* ProductionDatasetReadOptionsType */
static UA_INLINE size_t
UA_ProductionDatasetReadOptionsType_calcSizeBinary(const UA_ProductionDatasetReadOptionsType *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETREADOPTIONSTYPE]);
}
static UA_INLINE UA_StatusCode
UA_ProductionDatasetReadOptionsType_encodeBinary(const UA_ProductionDatasetReadOptionsType *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETREADOPTIONSTYPE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ProductionDatasetReadOptionsType_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ProductionDatasetReadOptionsType *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETREADOPTIONSTYPE], NULL);
}
