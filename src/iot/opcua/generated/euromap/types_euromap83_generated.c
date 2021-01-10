/* Generated from Opc_Ua.EUROMAP83.1_01.Types.bsd with script /home/pi/open62541/open62541/tools/generate_datatypes.py
 * on host pi-VirtualBox by user pi at 2019-12-05 09:27:18 */

#include "types_euromap83_generated.h"

/* PIDParametersDataType */
static UA_DataTypeMember PIDParametersDataType_members[3] = {
{
    UA_TYPENAME("P") /* .memberName */
    UA_TYPES_DOUBLE, /* .memberTypeIndex */
    0, /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("I") /* .memberName */
    UA_TYPES_DOUBLE, /* .memberTypeIndex */
    offsetof(UA_PIDParametersDataType, i) - offsetof(UA_PIDParametersDataType, p) - sizeof(UA_Double), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("D") /* .memberName */
    UA_TYPES_DOUBLE, /* .memberTypeIndex */
    offsetof(UA_PIDParametersDataType, d) - offsetof(UA_PIDParametersDataType, i) - sizeof(UA_Double), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},};

/* CavityCycleQualityEnumeration */
#define CavityCycleQualityEnumeration_members NULL

/* JobStatusEnumeration */
#define JobStatusEnumeration_members NULL

/* ProductionDatasetComponentEnumeration */
#define ProductionDatasetComponentEnumeration_members NULL

/* MaintenanceStatusEnumeration */
#define MaintenanceStatusEnumeration_members NULL

/* StartEnumeration */
#define StartEnumeration_members NULL

/* CyclicJobListElementType */
static UA_DataTypeMember CyclicJobListElementType_members[18] = {
{
    UA_TYPENAME("JobName") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    0, /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("JobDescription") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_CyclicJobListElementType, jobDescription) - offsetof(UA_CyclicJobListElementType, jobName) - sizeof(UA_String), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("JobClassification") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_CyclicJobListElementType, jobClassification) - offsetof(UA_CyclicJobListElementType, jobDescription) - sizeof(UA_String), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("CustomerName") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_CyclicJobListElementType, customerName) - offsetof(UA_CyclicJobListElementType, jobClassification) - sizeof(UA_String), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("ProductionDatasetName") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_CyclicJobListElementType, productionDatasetName) - offsetof(UA_CyclicJobListElementType, customerName) - sizeof(UA_String), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("ProductionDatasetDescription") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_CyclicJobListElementType, productionDatasetDescription) - offsetof(UA_CyclicJobListElementType, productionDatasetName) - sizeof(UA_String), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("Material") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_CyclicJobListElementType, materialSize) - offsetof(UA_CyclicJobListElementType, productionDatasetDescription) - sizeof(UA_String), /* .padding */
    true, /* .namespaceZero */
    true /* .isArray */
},
{
    UA_TYPENAME("ProductName") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_CyclicJobListElementType, productNameSize) - offsetof(UA_CyclicJobListElementType, material) - sizeof(void*), /* .padding */
    true, /* .namespaceZero */
    true /* .isArray */
},
{
    UA_TYPENAME("ProductDescription") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_CyclicJobListElementType, productDescriptionSize) - offsetof(UA_CyclicJobListElementType, productName) - sizeof(void*), /* .padding */
    true, /* .namespaceZero */
    true /* .isArray */
},
{
    UA_TYPENAME("JobPriority") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_CyclicJobListElementType, jobPriority) - offsetof(UA_CyclicJobListElementType, productDescription) - sizeof(void*), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("PlannedStart") /* .memberName */
    UA_TYPES_DATETIME, /* .memberTypeIndex */
    offsetof(UA_CyclicJobListElementType, plannedStart) - offsetof(UA_CyclicJobListElementType, jobPriority) - sizeof(UA_String), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("PlannedProductionTime") /* .memberName */
    UA_TYPES_DOUBLE, /* .memberTypeIndex */
    offsetof(UA_CyclicJobListElementType, plannedProductionTime) - offsetof(UA_CyclicJobListElementType, plannedStart) - sizeof(UA_DateTime), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("LatestEnd") /* .memberName */
    UA_TYPES_DATETIME, /* .memberTypeIndex */
    offsetof(UA_CyclicJobListElementType, latestEnd) - offsetof(UA_CyclicJobListElementType, plannedProductionTime) - sizeof(UA_Double), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("NominalParts") /* .memberName */
    UA_TYPES_UINT64, /* .memberTypeIndex */
    offsetof(UA_CyclicJobListElementType, nominalParts) - offsetof(UA_CyclicJobListElementType, latestEnd) - sizeof(UA_DateTime), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("NominalBoxParts") /* .memberName */
    UA_TYPES_UINT64, /* .memberTypeIndex */
    offsetof(UA_CyclicJobListElementType, nominalBoxParts) - offsetof(UA_CyclicJobListElementType, nominalParts) - sizeof(UA_UInt64), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("ExpectedCycleTime") /* .memberName */
    UA_TYPES_DOUBLE, /* .memberTypeIndex */
    offsetof(UA_CyclicJobListElementType, expectedCycleTime) - offsetof(UA_CyclicJobListElementType, nominalBoxParts) - sizeof(UA_UInt64), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("MouldId") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_CyclicJobListElementType, mouldId) - offsetof(UA_CyclicJobListElementType, expectedCycleTime) - sizeof(UA_Double), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("NumCavities") /* .memberName */
    UA_TYPES_UINT32, /* .memberTypeIndex */
    offsetof(UA_CyclicJobListElementType, numCavities) - offsetof(UA_CyclicJobListElementType, mouldId) - sizeof(UA_String), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},};

/* UserChangeEnumeration */
#define UserChangeEnumeration_members NULL

/* ActiveErrorDataType */
static UA_DataTypeMember ActiveErrorDataType_members[3] = {
{
    UA_TYPENAME("Id") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    0, /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("Severity") /* .memberName */
    UA_TYPES_UINT16, /* .memberTypeIndex */
    offsetof(UA_ActiveErrorDataType, severity) - offsetof(UA_ActiveErrorDataType, id) - sizeof(UA_String), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("Message") /* .memberName */
    UA_TYPES_LOCALIZEDTEXT, /* .memberTypeIndex */
    offsetof(UA_ActiveErrorDataType, message) - offsetof(UA_ActiveErrorDataType, severity) - sizeof(UA_UInt16), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},};

/* ProductionDatasetInformationType */
static UA_DataTypeMember ProductionDatasetInformationType_members[17] = {
{
    UA_TYPENAME("Name") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    0, /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("Description") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_ProductionDatasetInformationType, description) - offsetof(UA_ProductionDatasetInformationType, name) - sizeof(UA_String), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("MESId") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_ProductionDatasetInformationType, mESId) - offsetof(UA_ProductionDatasetInformationType, description) - sizeof(UA_String), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("CreationTimestamp") /* .memberName */
    UA_TYPES_DATETIME, /* .memberTypeIndex */
    offsetof(UA_ProductionDatasetInformationType, creationTimestamp) - offsetof(UA_ProductionDatasetInformationType, mESId) - sizeof(UA_String), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("LastModificationTimestamp") /* .memberName */
    UA_TYPES_DATETIME, /* .memberTypeIndex */
    offsetof(UA_ProductionDatasetInformationType, lastModificationTimestamp) - offsetof(UA_ProductionDatasetInformationType, creationTimestamp) - sizeof(UA_DateTime), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("LastSaveTimestamp") /* .memberName */
    UA_TYPES_DATETIME, /* .memberTypeIndex */
    offsetof(UA_ProductionDatasetInformationType, lastSaveTimestamp) - offsetof(UA_ProductionDatasetInformationType, lastModificationTimestamp) - sizeof(UA_DateTime), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("UserName") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_ProductionDatasetInformationType, userName) - offsetof(UA_ProductionDatasetInformationType, lastSaveTimestamp) - sizeof(UA_DateTime), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("Components") /* .memberName */
    UA_TYPES_EUROMAP83_PRODUCTIONDATASETCOMPONENTENUMERATION, /* .memberTypeIndex */
    offsetof(UA_ProductionDatasetInformationType, componentsSize) - offsetof(UA_ProductionDatasetInformationType, userName) - sizeof(UA_String), /* .padding */
    false, /* .namespaceZero */
    true /* .isArray */
},
{
    UA_TYPENAME("Manufacturer") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_ProductionDatasetInformationType, manufacturer) - offsetof(UA_ProductionDatasetInformationType, components) - sizeof(void*), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("SerialNumber") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_ProductionDatasetInformationType, serialNumber) - offsetof(UA_ProductionDatasetInformationType, manufacturer) - sizeof(UA_String), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("Model") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_ProductionDatasetInformationType, model) - offsetof(UA_ProductionDatasetInformationType, serialNumber) - sizeof(UA_String), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("ControllerType") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_ProductionDatasetInformationType, controllerType) - offsetof(UA_ProductionDatasetInformationType, model) - sizeof(UA_String), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("UserMachineName") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_ProductionDatasetInformationType, userMachineName) - offsetof(UA_ProductionDatasetInformationType, controllerType) - sizeof(UA_String), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("LocationName") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_ProductionDatasetInformationType, locationName) - offsetof(UA_ProductionDatasetInformationType, userMachineName) - sizeof(UA_String), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("ProductName") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_ProductionDatasetInformationType, productNameSize) - offsetof(UA_ProductionDatasetInformationType, locationName) - sizeof(UA_String), /* .padding */
    true, /* .namespaceZero */
    true /* .isArray */
},
{
    UA_TYPENAME("MouldId") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_ProductionDatasetInformationType, mouldId) - offsetof(UA_ProductionDatasetInformationType, productName) - sizeof(void*), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("NumCavities") /* .memberName */
    UA_TYPES_UINT32, /* .memberTypeIndex */
    offsetof(UA_ProductionDatasetInformationType, numCavities) - offsetof(UA_ProductionDatasetInformationType, mouldId) - sizeof(UA_String), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},};

/* JobListElementType */
static UA_DataTypeMember JobListElementType_members[13] = {
{
    UA_TYPENAME("JobName") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    0, /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("JobDescription") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_JobListElementType, jobDescription) - offsetof(UA_JobListElementType, jobName) - sizeof(UA_String), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("JobClassification") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_JobListElementType, jobClassification) - offsetof(UA_JobListElementType, jobDescription) - sizeof(UA_String), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("CustomerName") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_JobListElementType, customerName) - offsetof(UA_JobListElementType, jobClassification) - sizeof(UA_String), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("ProductionDatasetName") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_JobListElementType, productionDatasetName) - offsetof(UA_JobListElementType, customerName) - sizeof(UA_String), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("ProductionDatasetDescription") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_JobListElementType, productionDatasetDescription) - offsetof(UA_JobListElementType, productionDatasetName) - sizeof(UA_String), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("Material") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_JobListElementType, materialSize) - offsetof(UA_JobListElementType, productionDatasetDescription) - sizeof(UA_String), /* .padding */
    true, /* .namespaceZero */
    true /* .isArray */
},
{
    UA_TYPENAME("ProductName") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_JobListElementType, productNameSize) - offsetof(UA_JobListElementType, material) - sizeof(void*), /* .padding */
    true, /* .namespaceZero */
    true /* .isArray */
},
{
    UA_TYPENAME("ProductDescription") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_JobListElementType, productDescriptionSize) - offsetof(UA_JobListElementType, productName) - sizeof(void*), /* .padding */
    true, /* .namespaceZero */
    true /* .isArray */
},
{
    UA_TYPENAME("JobPriority") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_JobListElementType, jobPriority) - offsetof(UA_JobListElementType, productDescription) - sizeof(void*), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("PlannedStart") /* .memberName */
    UA_TYPES_DATETIME, /* .memberTypeIndex */
    offsetof(UA_JobListElementType, plannedStart) - offsetof(UA_JobListElementType, jobPriority) - sizeof(UA_String), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("PlannedProductionTime") /* .memberName */
    UA_TYPES_DOUBLE, /* .memberTypeIndex */
    offsetof(UA_JobListElementType, plannedProductionTime) - offsetof(UA_JobListElementType, plannedStart) - sizeof(UA_DateTime), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("LatestEnd") /* .memberName */
    UA_TYPES_DATETIME, /* .memberTypeIndex */
    offsetof(UA_JobListElementType, latestEnd) - offsetof(UA_JobListElementType, plannedProductionTime) - sizeof(UA_Double), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},};

/* ProductionStatusEnumeration */
#define ProductionStatusEnumeration_members NULL

/* ControlModeEnumeration */
#define ControlModeEnumeration_members NULL

/* CycleQualityEnumeration */
#define CycleQualityEnumeration_members NULL

/* MachineModeEnumeration */
#define MachineModeEnumeration_members NULL

/* LogbookEventsEnumeration */
#define LogbookEventsEnumeration_members NULL

/* SequenceChangeEnumeration */
#define SequenceChangeEnumeration_members NULL

/* PageEntryDataType */
static UA_DataTypeMember PageEntryDataType_members[2] = {
{
    UA_TYPENAME("Id") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    0, /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("Title") /* .memberName */
    UA_TYPES_LOCALIZEDTEXT, /* .memberTypeIndex */
    offsetof(UA_PageEntryDataType, title) - offsetof(UA_PageEntryDataType, id) - sizeof(UA_String), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},};

/* StorageEnumeration */
#define StorageEnumeration_members NULL

/* EventOriginatorEnumeration */
#define EventOriginatorEnumeration_members NULL

/* TemperatureZoneClassificationEnumeration */
#define TemperatureZoneClassificationEnumeration_members NULL

/* StandstillReasonType */
static UA_DataTypeMember StandstillReasonType_members[3] = {
{
    UA_TYPENAME("Id") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    0, /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("Text") /* .memberName */
    UA_TYPES_LOCALIZEDTEXT, /* .memberTypeIndex */
    offsetof(UA_StandstillReasonType, text) - offsetof(UA_StandstillReasonType, id) - sizeof(UA_String), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("LockedByMES") /* .memberName */
    UA_TYPES_BOOLEAN, /* .memberTypeIndex */
    offsetof(UA_StandstillReasonType, lockedByMES) - offsetof(UA_StandstillReasonType, text) - sizeof(UA_LocalizedText), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},};

/* MouldStatusEnumeration */
#define MouldStatusEnumeration_members NULL

/* ProductionDatasetWriteOptionsType */
static UA_DataTypeMember ProductionDatasetWriteOptionsType_members[3] = {
{
    UA_TYPENAME("Storage") /* .memberName */
    UA_TYPES_EUROMAP83_STORAGEENUMERATION, /* .memberTypeIndex */
    0, /* .padding */
    false, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("Name") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_ProductionDatasetWriteOptionsType, name) - offsetof(UA_ProductionDatasetWriteOptionsType, storage) - sizeof(UA_StorageEnumeration), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("Components") /* .memberName */
    UA_TYPES_EUROMAP83_PRODUCTIONDATASETCOMPONENTENUMERATION, /* .memberTypeIndex */
    offsetof(UA_ProductionDatasetWriteOptionsType, componentsSize) - offsetof(UA_ProductionDatasetWriteOptionsType, name) - sizeof(UA_String), /* .padding */
    false, /* .namespaceZero */
    true /* .isArray */
},};

/* ProductionDatasetReadOptionsType */
static UA_DataTypeMember ProductionDatasetReadOptionsType_members[2] = {
{
    UA_TYPENAME("Storage") /* .memberName */
    UA_TYPES_EUROMAP83_STORAGEENUMERATION, /* .memberTypeIndex */
    0, /* .padding */
    false, /* .namespaceZero */
    false /* .isArray */
},
{
    UA_TYPENAME("Name") /* .memberName */
    UA_TYPES_STRING, /* .memberTypeIndex */
    offsetof(UA_ProductionDatasetReadOptionsType, name) - offsetof(UA_ProductionDatasetReadOptionsType, storage) - sizeof(UA_StorageEnumeration), /* .padding */
    true, /* .namespaceZero */
    false /* .isArray */
},};
const UA_DataType UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_COUNT] = {
/* PIDParametersDataType */
{
    UA_TYPENAME("PIDParametersDataType") /* .typeName */
    {3, UA_NODEIDTYPE_NUMERIC, {3023}}, /* .typeId */
    sizeof(UA_PIDParametersDataType), /* .memSize */
    UA_TYPES_EUROMAP83_PIDPARAMETERSDATATYPE, /* .typeIndex */
    UA_DATATYPEKIND_STRUCTURE, /* .typeKind */
    true, /* .pointerFree */
    false, /* .overlayable */
    3, /* .membersSize */
    5017, /* .binaryEncodingId */
    PIDParametersDataType_members /* .members */
},
/* CavityCycleQualityEnumeration */
{
    UA_TYPENAME("CavityCycleQualityEnumeration") /* .typeName */
    {3, UA_NODEIDTYPE_NUMERIC, {3020}}, /* .typeId */
    sizeof(UA_CavityCycleQualityEnumeration), /* .memSize */
    UA_TYPES_INT32, /* .typeIndex */
    UA_DATATYPEKIND_ENUM, /* .typeKind */
    true, /* .pointerFree */
    UA_BINARY_OVERLAYABLE_INTEGER, /* .overlayable */
    0, /* .membersSize */
    0, /* .binaryEncodingId */
    CavityCycleQualityEnumeration_members /* .members */
},
/* JobStatusEnumeration */
{
    UA_TYPENAME("JobStatusEnumeration") /* .typeName */
    {3, UA_NODEIDTYPE_NUMERIC, {3017}}, /* .typeId */
    sizeof(UA_JobStatusEnumeration), /* .memSize */
    UA_TYPES_INT32, /* .typeIndex */
    UA_DATATYPEKIND_ENUM, /* .typeKind */
    true, /* .pointerFree */
    UA_BINARY_OVERLAYABLE_INTEGER, /* .overlayable */
    0, /* .membersSize */
    0, /* .binaryEncodingId */
    JobStatusEnumeration_members /* .members */
},
/* ProductionDatasetComponentEnumeration */
{
    UA_TYPENAME("ProductionDatasetComponentEnumeration") /* .typeName */
    {3, UA_NODEIDTYPE_NUMERIC, {3002}}, /* .typeId */
    sizeof(UA_ProductionDatasetComponentEnumeration), /* .memSize */
    UA_TYPES_INT32, /* .typeIndex */
    UA_DATATYPEKIND_ENUM, /* .typeKind */
    true, /* .pointerFree */
    UA_BINARY_OVERLAYABLE_INTEGER, /* .overlayable */
    0, /* .membersSize */
    0, /* .binaryEncodingId */
    ProductionDatasetComponentEnumeration_members /* .members */
},
/* MaintenanceStatusEnumeration */
{
    UA_TYPENAME("MaintenanceStatusEnumeration") /* .typeName */
    {3, UA_NODEIDTYPE_NUMERIC, {3013}}, /* .typeId */
    sizeof(UA_MaintenanceStatusEnumeration), /* .memSize */
    UA_TYPES_INT32, /* .typeIndex */
    UA_DATATYPEKIND_ENUM, /* .typeKind */
    true, /* .pointerFree */
    UA_BINARY_OVERLAYABLE_INTEGER, /* .overlayable */
    0, /* .membersSize */
    0, /* .binaryEncodingId */
    MaintenanceStatusEnumeration_members /* .members */
},
/* StartEnumeration */
{
    UA_TYPENAME("StartEnumeration") /* .typeName */
    {3, UA_NODEIDTYPE_NUMERIC, {3025}}, /* .typeId */
    sizeof(UA_StartEnumeration), /* .memSize */
    UA_TYPES_INT32, /* .typeIndex */
    UA_DATATYPEKIND_ENUM, /* .typeKind */
    true, /* .pointerFree */
    UA_BINARY_OVERLAYABLE_INTEGER, /* .overlayable */
    0, /* .membersSize */
    0, /* .binaryEncodingId */
    StartEnumeration_members /* .members */
},
/* CyclicJobListElementType */
{
    UA_TYPENAME("CyclicJobListElementType") /* .typeName */
    {3, UA_NODEIDTYPE_NUMERIC, {3022}}, /* .typeId */
    sizeof(UA_CyclicJobListElementType), /* .memSize */
    UA_TYPES_EUROMAP83_CYCLICJOBLISTELEMENTTYPE, /* .typeIndex */
    UA_DATATYPEKIND_STRUCTURE, /* .typeKind */
    false, /* .pointerFree */
    false, /* .overlayable */
    18, /* .membersSize */
    5041, /* .binaryEncodingId */
    CyclicJobListElementType_members /* .members */
},
/* UserChangeEnumeration */
{
    UA_TYPENAME("UserChangeEnumeration") /* .typeName */
    {3, UA_NODEIDTYPE_NUMERIC, {3010}}, /* .typeId */
    sizeof(UA_UserChangeEnumeration), /* .memSize */
    UA_TYPES_INT32, /* .typeIndex */
    UA_DATATYPEKIND_ENUM, /* .typeKind */
    true, /* .pointerFree */
    UA_BINARY_OVERLAYABLE_INTEGER, /* .overlayable */
    0, /* .membersSize */
    0, /* .binaryEncodingId */
    UserChangeEnumeration_members /* .members */
},
/* ActiveErrorDataType */
{
    UA_TYPENAME("ActiveErrorDataType") /* .typeName */
    {3, UA_NODEIDTYPE_NUMERIC, {3028}}, /* .typeId */
    sizeof(UA_ActiveErrorDataType), /* .memSize */
    UA_TYPES_EUROMAP83_ACTIVEERRORDATATYPE, /* .typeIndex */
    UA_DATATYPEKIND_STRUCTURE, /* .typeKind */
    false, /* .pointerFree */
    false, /* .overlayable */
    3, /* .membersSize */
    5048, /* .binaryEncodingId */
    ActiveErrorDataType_members /* .members */
},
/* ProductionDatasetInformationType */
{
    UA_TYPENAME("ProductionDatasetInformationType") /* .typeName */
    {3, UA_NODEIDTYPE_NUMERIC, {3006}}, /* .typeId */
    sizeof(UA_ProductionDatasetInformationType), /* .memSize */
    UA_TYPES_EUROMAP83_PRODUCTIONDATASETINFORMATIONTYPE, /* .typeIndex */
    UA_DATATYPEKIND_STRUCTURE, /* .typeKind */
    false, /* .pointerFree */
    false, /* .overlayable */
    17, /* .membersSize */
    5004, /* .binaryEncodingId */
    ProductionDatasetInformationType_members /* .members */
},
/* JobListElementType */
{
    UA_TYPENAME("JobListElementType") /* .typeName */
    {3, UA_NODEIDTYPE_NUMERIC, {3021}}, /* .typeId */
    sizeof(UA_JobListElementType), /* .memSize */
    UA_TYPES_EUROMAP83_JOBLISTELEMENTTYPE, /* .typeIndex */
    UA_DATATYPEKIND_STRUCTURE, /* .typeKind */
    false, /* .pointerFree */
    false, /* .overlayable */
    13, /* .membersSize */
    5036, /* .binaryEncodingId */
    JobListElementType_members /* .members */
},
/* ProductionStatusEnumeration */
{
    UA_TYPENAME("ProductionStatusEnumeration") /* .typeName */
    {3, UA_NODEIDTYPE_NUMERIC, {3016}}, /* .typeId */
    sizeof(UA_ProductionStatusEnumeration), /* .memSize */
    UA_TYPES_INT32, /* .typeIndex */
    UA_DATATYPEKIND_ENUM, /* .typeKind */
    true, /* .pointerFree */
    UA_BINARY_OVERLAYABLE_INTEGER, /* .overlayable */
    0, /* .membersSize */
    0, /* .binaryEncodingId */
    ProductionStatusEnumeration_members /* .members */
},
/* ControlModeEnumeration */
{
    UA_TYPENAME("ControlModeEnumeration") /* .typeName */
    {3, UA_NODEIDTYPE_NUMERIC, {3001}}, /* .typeId */
    sizeof(UA_ControlModeEnumeration), /* .memSize */
    UA_TYPES_INT32, /* .typeIndex */
    UA_DATATYPEKIND_ENUM, /* .typeKind */
    true, /* .pointerFree */
    UA_BINARY_OVERLAYABLE_INTEGER, /* .overlayable */
    0, /* .membersSize */
    0, /* .binaryEncodingId */
    ControlModeEnumeration_members /* .members */
},
/* CycleQualityEnumeration */
{
    UA_TYPENAME("CycleQualityEnumeration") /* .typeName */
    {3, UA_NODEIDTYPE_NUMERIC, {3019}}, /* .typeId */
    sizeof(UA_CycleQualityEnumeration), /* .memSize */
    UA_TYPES_INT32, /* .typeIndex */
    UA_DATATYPEKIND_ENUM, /* .typeKind */
    true, /* .pointerFree */
    UA_BINARY_OVERLAYABLE_INTEGER, /* .overlayable */
    0, /* .membersSize */
    0, /* .binaryEncodingId */
    CycleQualityEnumeration_members /* .members */
},
/* MachineModeEnumeration */
{
    UA_TYPENAME("MachineModeEnumeration") /* .typeName */
    {3, UA_NODEIDTYPE_NUMERIC, {3011}}, /* .typeId */
    sizeof(UA_MachineModeEnumeration), /* .memSize */
    UA_TYPES_INT32, /* .typeIndex */
    UA_DATATYPEKIND_ENUM, /* .typeKind */
    true, /* .pointerFree */
    UA_BINARY_OVERLAYABLE_INTEGER, /* .overlayable */
    0, /* .membersSize */
    0, /* .binaryEncodingId */
    MachineModeEnumeration_members /* .members */
},
/* LogbookEventsEnumeration */
{
    UA_TYPENAME("LogbookEventsEnumeration") /* .typeName */
    {3, UA_NODEIDTYPE_NUMERIC, {3009}}, /* .typeId */
    sizeof(UA_LogbookEventsEnumeration), /* .memSize */
    UA_TYPES_INT32, /* .typeIndex */
    UA_DATATYPEKIND_ENUM, /* .typeKind */
    true, /* .pointerFree */
    UA_BINARY_OVERLAYABLE_INTEGER, /* .overlayable */
    0, /* .membersSize */
    0, /* .binaryEncodingId */
    LogbookEventsEnumeration_members /* .members */
},
/* SequenceChangeEnumeration */
{
    UA_TYPENAME("SequenceChangeEnumeration") /* .typeName */
    {3, UA_NODEIDTYPE_NUMERIC, {3012}}, /* .typeId */
    sizeof(UA_SequenceChangeEnumeration), /* .memSize */
    UA_TYPES_INT32, /* .typeIndex */
    UA_DATATYPEKIND_ENUM, /* .typeKind */
    true, /* .pointerFree */
    UA_BINARY_OVERLAYABLE_INTEGER, /* .overlayable */
    0, /* .membersSize */
    0, /* .binaryEncodingId */
    SequenceChangeEnumeration_members /* .members */
},
/* PageEntryDataType */
{
    UA_TYPENAME("PageEntryDataType") /* .typeName */
    {3, UA_NODEIDTYPE_NUMERIC, {3014}}, /* .typeId */
    sizeof(UA_PageEntryDataType), /* .memSize */
    UA_TYPES_EUROMAP83_PAGEENTRYDATATYPE, /* .typeIndex */
    UA_DATATYPEKIND_STRUCTURE, /* .typeKind */
    false, /* .pointerFree */
    false, /* .overlayable */
    2, /* .membersSize */
    5024, /* .binaryEncodingId */
    PageEntryDataType_members /* .members */
},
/* StorageEnumeration */
{
    UA_TYPENAME("StorageEnumeration") /* .typeName */
    {3, UA_NODEIDTYPE_NUMERIC, {3005}}, /* .typeId */
    sizeof(UA_StorageEnumeration), /* .memSize */
    UA_TYPES_INT32, /* .typeIndex */
    UA_DATATYPEKIND_ENUM, /* .typeKind */
    true, /* .pointerFree */
    UA_BINARY_OVERLAYABLE_INTEGER, /* .overlayable */
    0, /* .membersSize */
    0, /* .binaryEncodingId */
    StorageEnumeration_members /* .members */
},
/* EventOriginatorEnumeration */
{
    UA_TYPENAME("EventOriginatorEnumeration") /* .typeName */
    {3, UA_NODEIDTYPE_NUMERIC, {3018}}, /* .typeId */
    sizeof(UA_EventOriginatorEnumeration), /* .memSize */
    UA_TYPES_INT32, /* .typeIndex */
    UA_DATATYPEKIND_ENUM, /* .typeKind */
    true, /* .pointerFree */
    UA_BINARY_OVERLAYABLE_INTEGER, /* .overlayable */
    0, /* .membersSize */
    0, /* .binaryEncodingId */
    EventOriginatorEnumeration_members /* .members */
},
/* TemperatureZoneClassificationEnumeration */
{
    UA_TYPENAME("TemperatureZoneClassificationEnumeration") /* .typeName */
    {3, UA_NODEIDTYPE_NUMERIC, {3029}}, /* .typeId */
    sizeof(UA_TemperatureZoneClassificationEnumeration), /* .memSize */
    UA_TYPES_INT32, /* .typeIndex */
    UA_DATATYPEKIND_ENUM, /* .typeKind */
    true, /* .pointerFree */
    UA_BINARY_OVERLAYABLE_INTEGER, /* .overlayable */
    0, /* .membersSize */
    0, /* .binaryEncodingId */
    TemperatureZoneClassificationEnumeration_members /* .members */
},
/* StandstillReasonType */
{
    UA_TYPENAME("StandstillReasonType") /* .typeName */
    {3, UA_NODEIDTYPE_NUMERIC, {3015}}, /* .typeId */
    sizeof(UA_StandstillReasonType), /* .memSize */
    UA_TYPES_EUROMAP83_STANDSTILLREASONTYPE, /* .typeIndex */
    UA_DATATYPEKIND_STRUCTURE, /* .typeKind */
    false, /* .pointerFree */
    false, /* .overlayable */
    3, /* .membersSize */
    5026, /* .binaryEncodingId */
    StandstillReasonType_members /* .members */
},
/* MouldStatusEnumeration */
{
    UA_TYPENAME("MouldStatusEnumeration") /* .typeName */
    {3, UA_NODEIDTYPE_NUMERIC, {3008}}, /* .typeId */
    sizeof(UA_MouldStatusEnumeration), /* .memSize */
    UA_TYPES_INT32, /* .typeIndex */
    UA_DATATYPEKIND_ENUM, /* .typeKind */
    true, /* .pointerFree */
    UA_BINARY_OVERLAYABLE_INTEGER, /* .overlayable */
    0, /* .membersSize */
    0, /* .binaryEncodingId */
    MouldStatusEnumeration_members /* .members */
},
/* ProductionDatasetWriteOptionsType */
{
    UA_TYPENAME("ProductionDatasetWriteOptionsType") /* .typeName */
    {3, UA_NODEIDTYPE_NUMERIC, {3004}}, /* .typeId */
    sizeof(UA_ProductionDatasetWriteOptionsType), /* .memSize */
    UA_TYPES_EUROMAP83_PRODUCTIONDATASETWRITEOPTIONSTYPE, /* .typeIndex */
    UA_DATATYPEKIND_STRUCTURE, /* .typeKind */
    false, /* .pointerFree */
    false, /* .overlayable */
    3, /* .membersSize */
    5005, /* .binaryEncodingId */
    ProductionDatasetWriteOptionsType_members /* .members */
},
/* ProductionDatasetReadOptionsType */
{
    UA_TYPENAME("ProductionDatasetReadOptionsType") /* .typeName */
    {3, UA_NODEIDTYPE_NUMERIC, {3007}}, /* .typeId */
    sizeof(UA_ProductionDatasetReadOptionsType), /* .memSize */
    UA_TYPES_EUROMAP83_PRODUCTIONDATASETREADOPTIONSTYPE, /* .typeIndex */
    UA_DATATYPEKIND_STRUCTURE, /* .typeKind */
    false, /* .pointerFree */
    false, /* .overlayable */
    2, /* .membersSize */
    5012, /* .binaryEncodingId */
    ProductionDatasetReadOptionsType_members /* .members */
},
};

