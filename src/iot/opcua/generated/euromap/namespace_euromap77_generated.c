/* WARNING: This is a generated file.
 * Any manual changes will be overwritten. */

#include "namespace_euromap77_generated.h"


/* IMMMessageClassificationEnumeration - ns=3;i=3004 */

static UA_StatusCode function_namespace_euromap77_generated_0_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_DataTypeAttributes attr = UA_DataTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "IMMMessageClassificationEnumeration");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "This Enumeration specifies the values to be used in the Classification property in the MessageConditionType and related logbook events of EUROMAP 83");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_DATATYPE,
UA_NODEID_NUMERIC(ns[3], 3004),
UA_NODEID_NUMERIC(ns[0], 29),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[3], "IMMMessageClassificationEnumeration"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_DATATYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_0_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 3004)
);
}

/* EnumValues - ns=3;i=6049 */

static UA_StatusCode function_namespace_euromap77_generated_1_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 39;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7594);
UA_EnumValueType variablenode_ns_3_i_6049_variant_DataContents[39];

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[0], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[0].value = (UA_Int64) 0;
variablenode_ns_3_i_6049_variant_DataContents[0].displayName = UA_LOCALIZEDTEXT("", "OTHER");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[1], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[1].value = (UA_Int64) 100;
variablenode_ns_3_i_6049_variant_DataContents[1].displayName = UA_LOCALIZEDTEXT("", "IMM_INJECTION_UNIT");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[2], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[2].value = (UA_Int64) 101;
variablenode_ns_3_i_6049_variant_DataContents[2].displayName = UA_LOCALIZEDTEXT("", "IMM_CLAMPING_UNIT");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[3], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[3].value = (UA_Int64) 102;
variablenode_ns_3_i_6049_variant_DataContents[3].displayName = UA_LOCALIZEDTEXT("", "IMM_HARDWARE");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[4], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[4].value = (UA_Int64) 103;
variablenode_ns_3_i_6049_variant_DataContents[4].displayName = UA_LOCALIZEDTEXT("", "IMM_COMPRESSED_AIR_CONTROL");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[5], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[5].value = (UA_Int64) 104;
variablenode_ns_3_i_6049_variant_DataContents[5].displayName = UA_LOCALIZEDTEXT("", "IMM_MACHINE_MONITORING");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[6], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[6].value = (UA_Int64) 105;
variablenode_ns_3_i_6049_variant_DataContents[6].displayName = UA_LOCALIZEDTEXT("", "IMM_MOULD");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[7], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[7].value = (UA_Int64) 106;
variablenode_ns_3_i_6049_variant_DataContents[7].displayName = UA_LOCALIZEDTEXT("", "IMM_EJECTOR");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[8], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[8].value = (UA_Int64) 107;
variablenode_ns_3_i_6049_variant_DataContents[8].displayName = UA_LOCALIZEDTEXT("", "IMM_CORE_PULL");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[9], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[9].value = (UA_Int64) 108;
variablenode_ns_3_i_6049_variant_DataContents[9].displayName = UA_LOCALIZEDTEXT("", "IMM_TABLE");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[10], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[10].value = (UA_Int64) 109;
variablenode_ns_3_i_6049_variant_DataContents[10].displayName = UA_LOCALIZEDTEXT("", "IMM_INJECTION_PROGRAM");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[11], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[11].value = (UA_Int64) 110;
variablenode_ns_3_i_6049_variant_DataContents[11].displayName = UA_LOCALIZEDTEXT("", "IMM_HYDRAULIC_TEMPERATURE_CONTROL");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[12], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[12].value = (UA_Int64) 111;
variablenode_ns_3_i_6049_variant_DataContents[12].displayName = UA_LOCALIZEDTEXT("", "IMM_CYLINDER_TEMPERATURE_CONTROL");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[13], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[13].value = (UA_Int64) 112;
variablenode_ns_3_i_6049_variant_DataContents[13].displayName = UA_LOCALIZEDTEXT("", "IMM_MOULD_TEMPERATURE_CONTROL");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[14], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[14].value = (UA_Int64) 113;
variablenode_ns_3_i_6049_variant_DataContents[14].displayName = UA_LOCALIZEDTEXT("", "IMM_HOT_RUNNER");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[15], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[15].value = (UA_Int64) 114;
variablenode_ns_3_i_6049_variant_DataContents[15].displayName = UA_LOCALIZEDTEXT("", "IMM_INTERFACES");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[16], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[16].value = (UA_Int64) 115;
variablenode_ns_3_i_6049_variant_DataContents[16].displayName = UA_LOCALIZEDTEXT("", "IMM_MEASURING_SYSTEM");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[17], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[17].value = (UA_Int64) 116;
variablenode_ns_3_i_6049_variant_DataContents[17].displayName = UA_LOCALIZEDTEXT("", "IMM_ROBOTIC_SYSTEM_INTERFACE");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[18], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[18].value = (UA_Int64) 117;
variablenode_ns_3_i_6049_variant_DataContents[18].displayName = UA_LOCALIZEDTEXT("", "IMM_SPECIAL_PURPOSE_SIGNALS");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[19], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[19].value = (UA_Int64) 118;
variablenode_ns_3_i_6049_variant_DataContents[19].displayName = UA_LOCALIZEDTEXT("", "IMM_REAL_TIME_ETHERNET_SYSTEM");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[20], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[20].value = (UA_Int64) 119;
variablenode_ns_3_i_6049_variant_DataContents[20].displayName = UA_LOCALIZEDTEXT("", "IMM_MACHINE_CONTROLLER");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[21], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[21].value = (UA_Int64) 120;
variablenode_ns_3_i_6049_variant_DataContents[21].displayName = UA_LOCALIZEDTEXT("", "IMM_SOFTWARE_MONITORING");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[22], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[22].value = (UA_Int64) 200;
variablenode_ns_3_i_6049_variant_DataContents[22].displayName = UA_LOCALIZEDTEXT("", "PERIPHERAL_EXTERNAL_DEVICE_INTERFACE");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[23], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[23].value = (UA_Int64) 201;
variablenode_ns_3_i_6049_variant_DataContents[23].displayName = UA_LOCALIZEDTEXT("", "PERIPHERAL_TEMPERATURE_CONTROL_UNIT");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[24], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[24].value = (UA_Int64) 202;
variablenode_ns_3_i_6049_variant_DataContents[24].displayName = UA_LOCALIZEDTEXT("", "PERIPHERAL_ROBOTICS_SYSTEM");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[25], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[25].value = (UA_Int64) 203;
variablenode_ns_3_i_6049_variant_DataContents[25].displayName = UA_LOCALIZEDTEXT("", "PERIPHERAL_LSR");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[26], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[26].value = (UA_Int64) 204;
variablenode_ns_3_i_6049_variant_DataContents[26].displayName = UA_LOCALIZEDTEXT("", "PERIPHERAL_STRIPPER_UNIT");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[27], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[27].value = (UA_Int64) 205;
variablenode_ns_3_i_6049_variant_DataContents[27].displayName = UA_LOCALIZEDTEXT("", "PERIPHERAL_DRYER");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[28], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[28].value = (UA_Int64) 206;
variablenode_ns_3_i_6049_variant_DataContents[28].displayName = UA_LOCALIZEDTEXT("", "PERIPHERAL_CONVEYOR_BELT");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[29], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[29].value = (UA_Int64) 207;
variablenode_ns_3_i_6049_variant_DataContents[29].displayName = UA_LOCALIZEDTEXT("", "PERIPHERAL_SORTER_UNIT");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[30], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[30].value = (UA_Int64) 208;
variablenode_ns_3_i_6049_variant_DataContents[30].displayName = UA_LOCALIZEDTEXT("", "PERIPHERAL_COLOURING_UNIT");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[31], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[31].value = (UA_Int64) 209;
variablenode_ns_3_i_6049_variant_DataContents[31].displayName = UA_LOCALIZEDTEXT("", "PERIPHERAL_FEEDING");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[32], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[32].value = (UA_Int64) 210;
variablenode_ns_3_i_6049_variant_DataContents[32].displayName = UA_LOCALIZEDTEXT("", "PERIPHERAL_EXTERNAL_ALARMS");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[33], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[33].value = (UA_Int64) 211;
variablenode_ns_3_i_6049_variant_DataContents[33].displayName = UA_LOCALIZEDTEXT("", "PERIPHERAL_VACUUM_CONTROL");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[34], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[34].value = (UA_Int64) 212;
variablenode_ns_3_i_6049_variant_DataContents[34].displayName = UA_LOCALIZEDTEXT("", "PERIPHERAL_PRINTER_INTERFACE");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[35], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[35].value = (UA_Int64) 300;
variablenode_ns_3_i_6049_variant_DataContents[35].displayName = UA_LOCALIZEDTEXT("", "OPERATION_QUALITY_MONITORING");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[36], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[36].value = (UA_Int64) 301;
variablenode_ns_3_i_6049_variant_DataContents[36].displayName = UA_LOCALIZEDTEXT("", "OPERATION_MANUAL_OPERATION");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[37], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[37].value = (UA_Int64) 302;
variablenode_ns_3_i_6049_variant_DataContents[37].displayName = UA_LOCALIZEDTEXT("", "OPERATION_EMERGENCY_STOP");

UA_init(&variablenode_ns_3_i_6049_variant_DataContents[38], &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
variablenode_ns_3_i_6049_variant_DataContents[38].value = (UA_Int64) 303;
variablenode_ns_3_i_6049_variant_DataContents[38].displayName = UA_LOCALIZEDTEXT("", "OPERATION_JOB_STATUS");
UA_Variant_setArray(&attr.value, &variablenode_ns_3_i_6049_variant_DataContents, (UA_Int32) 39, &UA_TYPES[UA_TYPES_ENUMVALUETYPE]);
attr.displayName = UA_LOCALIZEDTEXT("", "EnumValues");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6049),
UA_NODEID_NUMERIC(ns[3], 3004),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EnumValues"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);







































retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6049), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_1_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6049)
);
}

/* Euromap77_NamespaceMetadata - ns=3;i=5022 */

static UA_StatusCode function_namespace_euromap77_generated_2_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Euromap77_NamespaceMetadata");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Provides the metadata for a namespace used by the server.");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[3], 5022),
UA_NODEID_NUMERIC(ns[0], 11715),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "Euromap77_NamespaceMetadata"),
UA_NODEID_NUMERIC(ns[0], 11616),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_2_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 5022)
);
}

/* NamespaceVersion - ns=3;i=6218 */

static UA_StatusCode function_namespace_euromap77_generated_3_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6218_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6218_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6218_variant_DataContents);
*variablenode_ns_3_i_6218_variant_DataContents = UA_STRING_ALLOC("1.00");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6218_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "NamespaceVersion");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "The human readable string representing version of the namespace.");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6218),
UA_NODEID_NUMERIC(ns[3], 5022),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "NamespaceVersion"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6218_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_3_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6218)
);
}

/* StaticNodeIdTypes - ns=3;i=6219 */

static UA_StatusCode function_namespace_euromap77_generated_4_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 0;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 256);
UA_Int32 variablenode_ns_3_i_6219_variant_DataContents[1];
variablenode_ns_3_i_6219_variant_DataContents[0] = (UA_Int32) 0;
UA_Variant_setArray(&attr.value, &variablenode_ns_3_i_6219_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_IDTYPE]);
attr.displayName = UA_LOCALIZEDTEXT("", "StaticNodeIdTypes");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "A list of IdTypes for nodes which are the same in every server that exposes them.");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6219),
UA_NODEID_NUMERIC(ns[3], 5022),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "StaticNodeIdTypes"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_4_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6219)
);
}

/* NamespacePublicationDate - ns=3;i=6201 */

static UA_StatusCode function_namespace_euromap77_generated_5_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 13);
UA_DateTime *variablenode_ns_3_i_6201_variant_DataContents =  UA_DateTime_new();
if (!variablenode_ns_3_i_6201_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_DateTime_init(variablenode_ns_3_i_6201_variant_DataContents);
*variablenode_ns_3_i_6201_variant_DataContents = ( (UA_DateTime)(1525413600000 * UA_DATETIME_MSEC) + UA_DATETIME_UNIX_EPOCH);
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6201_variant_DataContents, &UA_TYPES[UA_TYPES_DATETIME]);
attr.displayName = UA_LOCALIZEDTEXT("", "NamespacePublicationDate");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "The publication date for the namespace.");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6201),
UA_NODEID_NUMERIC(ns[3], 5022),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "NamespacePublicationDate"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_DateTime_delete(variablenode_ns_3_i_6201_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_5_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6201)
);
}

/* IsNamespaceSubset - ns=3;i=6200 */

static UA_StatusCode function_namespace_euromap77_generated_6_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_3_i_6200_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_3_i_6200_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_3_i_6200_variant_DataContents);
*variablenode_ns_3_i_6200_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6200_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "IsNamespaceSubset");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "If TRUE then the server only supports a subset of the namespace.");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6200),
UA_NODEID_NUMERIC(ns[3], 5022),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "IsNamespaceSubset"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_3_i_6200_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_6_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6200)
);
}

/* NamespaceUri - ns=3;i=6205 */

static UA_StatusCode function_namespace_euromap77_generated_7_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6205_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6205_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6205_variant_DataContents);
*variablenode_ns_3_i_6205_variant_DataContents = UA_STRING_ALLOC("http://www.euromap.org/euromap77/");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6205_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "NamespaceUri");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "The URI of the namespace.");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6205),
UA_NODEID_NUMERIC(ns[3], 5022),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "NamespaceUri"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6205_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_7_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6205)
);
}

/* StaticStringNodeIdPattern - ns=3;i=6221 */

static UA_StatusCode function_namespace_euromap77_generated_8_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
attr.displayName = UA_LOCALIZEDTEXT("", "StaticStringNodeIdPattern");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "A regular expression which matches string node ids are the same in every server that exposes them.");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6221),
UA_NODEID_NUMERIC(ns[3], 5022),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "StaticStringNodeIdPattern"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_8_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6221)
);
}

/* StaticNumericNodeIdRange - ns=3;i=6220 */

static UA_StatusCode function_namespace_euromap77_generated_9_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 0;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 291);
attr.displayName = UA_LOCALIZEDTEXT("", "StaticNumericNodeIdRange");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "A list of ranges for numeric node ids which are the same in every server that exposes them.");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6220),
UA_NODEID_NUMERIC(ns[3], 5022),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "StaticNumericNodeIdRange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_9_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6220)
);
}

/* IMM_MES_InterfaceType - ns=3;i=1007 */

static UA_StatusCode function_namespace_euromap77_generated_10_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectTypeAttributes attr = UA_ObjectTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "IMM_MES_InterfaceType");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Root ObjectType representing an injection moulding machine with all its subcomponents for data exchange with an MES");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECTTYPE,
UA_NODEID_NUMERIC(ns[3], 1007),
UA_NODEID_NUMERIC(ns[0], 58),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[3], "IMM_MES_InterfaceType"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTTYPEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 1007), UA_NODEID_NUMERIC(ns[0], 41), UA_EXPANDEDNODEID_NUMERIC(ns[2], 1038), true);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 1007), UA_NODEID_NUMERIC(ns[0], 41), UA_EXPANDEDNODEID_NUMERIC(ns[2], 1011), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_10_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 1007)
);
}

/* Moulds - ns=3;i=5035 */

static UA_StatusCode function_namespace_euromap77_generated_11_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Moulds");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Container for the moulds");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[3], 5035),
UA_NODEID_NUMERIC(ns[3], 1007),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "Moulds"),
UA_NODEID_NUMERIC(ns[2], 1050),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5035), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_11_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 5035)
);
}

/* NodeVersion - ns=3;i=6074 */

static UA_StatusCode function_namespace_euromap77_generated_12_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6074_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6074_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6074_variant_DataContents);
*variablenode_ns_3_i_6074_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6074_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "NodeVersion");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6074),
UA_NODEID_NUMERIC(ns[3], 5035),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "NodeVersion"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6074_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6074), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_12_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6074)
);
}

/* MachineMESConfiguration - ns=3;i=5009 */

static UA_StatusCode function_namespace_euromap77_generated_13_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "MachineMESConfiguration");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Current configuration of a machine related to a Manufacturing Execution System (MES)");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[3], 5009),
UA_NODEID_NUMERIC(ns[3], 1007),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "MachineMESConfiguration"),
UA_NODEID_NUMERIC(ns[2], 1018),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5009), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_13_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 5009)
);
}

/* StandstillReasons - ns=3;i=6043 */

static UA_StatusCode function_namespace_euromap77_generated_14_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 0;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[2], 3015);
attr.displayName = UA_LOCALIZEDTEXT("", "StandstillReasons");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "List of the standstill reasons from which one is selected by the operator in the case of a standstill");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6043),
UA_NODEID_NUMERIC(ns[3], 5009),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "StandstillReasons"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6043), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_14_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6043)
);
}

/* MESUrl - ns=3;i=6085 */

static UA_StatusCode function_namespace_euromap77_generated_15_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6085_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6085_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6085_variant_DataContents);
*variablenode_ns_3_i_6085_variant_DataContents = UA_STRING_ALLOC("0");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6085_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "MESUrl");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "URL to display a webpage generated by the MES in a web browser integrated in the machine");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6085),
UA_NODEID_NUMERIC(ns[3], 5009),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "MESUrl"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6085_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6085), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_15_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6085)
);
}

/* StandstillReasonsLockedByMES - ns=3;i=6044 */

static UA_StatusCode function_namespace_euromap77_generated_16_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_3_i_6044_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_3_i_6044_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_3_i_6044_variant_DataContents);
*variablenode_ns_3_i_6044_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6044_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "StandstillReasonsLockedByMES");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Indication if the list StandstillReasons has been modified by the MES and may not be changed by the machine");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6044),
UA_NODEID_NUMERIC(ns[3], 5009),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "StandstillReasonsLockedByMES"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_3_i_6044_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6044), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_16_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6044)
);
}

/* MachineStatus - ns=3;i=5006 */

static UA_StatusCode function_namespace_euromap77_generated_17_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "MachineStatus");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Information on the current status of the machine");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[3], 5006),
UA_NODEID_NUMERIC(ns[3], 1007),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "MachineStatus"),
UA_NODEID_NUMERIC(ns[2], 1019),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5006), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_17_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 5006)
);
}

/* ActivateSleepMode - ns=3;i=7010 */

static UA_StatusCode function_namespace_euromap77_generated_18_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "ActivateSleepMode");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Method for activation of sleep mode");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[3], 7010),
UA_NODEID_NUMERIC(ns[3], 5006),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "ActivateSleepMode"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 7010), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_namespace_euromap77_generated_18_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 7010)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* DeactivateSleepMode - ns=3;i=7011 */

static UA_StatusCode function_namespace_euromap77_generated_19_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "DeactivateSleepMode");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Method for deactivation of sleep mode");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[3], 7011),
UA_NODEID_NUMERIC(ns[3], 5006),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "DeactivateSleepMode"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 7011), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_namespace_euromap77_generated_19_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 7011)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* IsPresent - ns=3;i=6007 */

static UA_StatusCode function_namespace_euromap77_generated_20_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_3_i_6007_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_3_i_6007_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_3_i_6007_variant_DataContents);
*variablenode_ns_3_i_6007_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6007_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "IsPresent");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Indication if the machine is physically present and connected");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6007),
UA_NODEID_NUMERIC(ns[3], 5006),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "IsPresent"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_3_i_6007_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6007), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_20_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6007)
);
}

/* Users - ns=3;i=5010 */

static UA_StatusCode function_namespace_euromap77_generated_21_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Users");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Container for the user(s) of the machine");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[3], 5010),
UA_NODEID_NUMERIC(ns[3], 5006),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "Users"),
UA_NODEID_NUMERIC(ns[2], 1048),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5010), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_21_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 5010)
);
}

/* NodeVersion - ns=3;i=6009 */

static UA_StatusCode function_namespace_euromap77_generated_22_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6009_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6009_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6009_variant_DataContents);
*variablenode_ns_3_i_6009_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6009_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "NodeVersion");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6009),
UA_NODEID_NUMERIC(ns[3], 5010),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "NodeVersion"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6009_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6009), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_22_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6009)
);
}

/* MachineMode - ns=3;i=6008 */

static UA_StatusCode function_namespace_euromap77_generated_23_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[2], 3011);
UA_Int32 *variablenode_ns_3_i_6008_variant_DataContents =  UA_Int32_new();
if (!variablenode_ns_3_i_6008_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Int32_init(variablenode_ns_3_i_6008_variant_DataContents);
*variablenode_ns_3_i_6008_variant_DataContents = (UA_Int32) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6008_variant_DataContents, &UA_TYPES[UA_TYPES_INT32]);
attr.displayName = UA_LOCALIZEDTEXT("", "MachineMode");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Current machine mode (as defined by mode selector on the machine)");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6008),
UA_NODEID_NUMERIC(ns[3], 5006),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "MachineMode"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Int32_delete(variablenode_ns_3_i_6008_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6008), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_23_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6008)
);
}

/* Jobs - ns=3;i=5004 */

static UA_StatusCode function_namespace_euromap77_generated_24_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.eventNotifier = true;
attr.displayName = UA_LOCALIZEDTEXT("", "Jobs");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Management of production jobs on the machine and information on their status including process parameters");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[3], 5004),
UA_NODEID_NUMERIC(ns[3], 1007),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "Jobs"),
UA_NODEID_NUMERIC(ns[2], 1032),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5004), UA_NODEID_NUMERIC(ns[0], 41), UA_EXPANDEDNODEID_NUMERIC(ns[2], 1028), true);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5004), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_24_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 5004)
);
}

/* ActiveJobValues - ns=3;i=5013 */

static UA_StatusCode function_namespace_euromap77_generated_25_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "ActiveJobValues");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Status of the job");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[3], 5013),
UA_NODEID_NUMERIC(ns[3], 5004),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "ActiveJobValues"),
UA_NODEID_NUMERIC(ns[2], 1031),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5013), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_25_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 5013)
);
}

/* BoxId - ns=3;i=6135 */

static UA_StatusCode function_namespace_euromap77_generated_26_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6135_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6135_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6135_variant_DataContents);
*variablenode_ns_3_i_6135_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6135_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "BoxId");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Id of the box in which the current production is put in");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6135),
UA_NODEID_NUMERIC(ns[3], 5013),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "BoxId"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6135_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6135), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_26_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6135)
);
}

/* JobStatus - ns=3;i=6134 */

static UA_StatusCode function_namespace_euromap77_generated_27_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[2], 3017);
UA_Int32 *variablenode_ns_3_i_6134_variant_DataContents =  UA_Int32_new();
if (!variablenode_ns_3_i_6134_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Int32_init(variablenode_ns_3_i_6134_variant_DataContents);
*variablenode_ns_3_i_6134_variant_DataContents = (UA_Int32) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6134_variant_DataContents, &UA_TYPES[UA_TYPES_INT32]);
attr.displayName = UA_LOCALIZEDTEXT("", "JobStatus");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Current status of the job");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6134),
UA_NODEID_NUMERIC(ns[3], 5013),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "JobStatus"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Int32_delete(variablenode_ns_3_i_6134_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6134), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_27_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6134)
);
}

/* CurrentLotName - ns=3;i=6133 */

static UA_StatusCode function_namespace_euromap77_generated_28_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6133_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6133_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6133_variant_DataContents);
*variablenode_ns_3_i_6133_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6133_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "CurrentLotName");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Name of the current production lot");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6133),
UA_NODEID_NUMERIC(ns[3], 5013),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "CurrentLotName"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6133_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6133), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_28_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6133)
);
}

/* JobTestSamplesCounter - ns=3;i=6115 */

static UA_StatusCode function_namespace_euromap77_generated_29_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 9);
UA_UInt64 *variablenode_ns_3_i_6115_variant_DataContents =  UA_UInt64_new();
if (!variablenode_ns_3_i_6115_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt64_init(variablenode_ns_3_i_6115_variant_DataContents);
*variablenode_ns_3_i_6115_variant_DataContents = (UA_UInt64) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6115_variant_DataContents, &UA_TYPES[UA_TYPES_UINT64]);
attr.displayName = UA_LOCALIZEDTEXT("", "JobTestSamplesCounter");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Number of test sample parts produced in the current job");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6115),
UA_NODEID_NUMERIC(ns[3], 5013),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "JobTestSamplesCounter"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt64_delete(variablenode_ns_3_i_6115_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6115), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_29_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6115)
);
}

/* LastCycleTime - ns=3;i=6127 */

static UA_StatusCode function_namespace_euromap77_generated_30_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 290);
UA_Double *variablenode_ns_3_i_6127_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6127_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6127_variant_DataContents);
*variablenode_ns_3_i_6127_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6127_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "LastCycleTime");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Time of the recently finished cycle");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6127),
UA_NODEID_NUMERIC(ns[3], 5013),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "LastCycleTime"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6127_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6127), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_30_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6127)
);
}

/* JobBadPartsCounter - ns=3;i=6089 */

static UA_StatusCode function_namespace_euromap77_generated_31_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 9);
UA_UInt64 *variablenode_ns_3_i_6089_variant_DataContents =  UA_UInt64_new();
if (!variablenode_ns_3_i_6089_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt64_init(variablenode_ns_3_i_6089_variant_DataContents);
*variablenode_ns_3_i_6089_variant_DataContents = (UA_UInt64) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6089_variant_DataContents, &UA_TYPES[UA_TYPES_UINT64]);
attr.displayName = UA_LOCALIZEDTEXT("", "JobBadPartsCounter");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Number of bad parts produced in the current job");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6089),
UA_NODEID_NUMERIC(ns[3], 5013),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "JobBadPartsCounter"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt64_delete(variablenode_ns_3_i_6089_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6089), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_31_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6089)
);
}

/* JobGoodPartsCounter - ns=3;i=6091 */

static UA_StatusCode function_namespace_euromap77_generated_32_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 9);
UA_UInt64 *variablenode_ns_3_i_6091_variant_DataContents =  UA_UInt64_new();
if (!variablenode_ns_3_i_6091_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt64_init(variablenode_ns_3_i_6091_variant_DataContents);
*variablenode_ns_3_i_6091_variant_DataContents = (UA_UInt64) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6091_variant_DataContents, &UA_TYPES[UA_TYPES_UINT64]);
attr.displayName = UA_LOCALIZEDTEXT("", "JobGoodPartsCounter");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Number of good parts produced in the current job");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6091),
UA_NODEID_NUMERIC(ns[3], 5013),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "JobGoodPartsCounter"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt64_delete(variablenode_ns_3_i_6091_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6091), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_32_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6091)
);
}

/* ResetJobCounters - ns=3;i=7014 */

static UA_StatusCode function_namespace_euromap77_generated_33_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "ResetJobCounters");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Setting the cycle and parts counters for the job to 0");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[3], 7014),
UA_NODEID_NUMERIC(ns[3], 5013),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "ResetJobCounters"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 7014), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_namespace_euromap77_generated_33_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 7014)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* StartJob - ns=3;i=7021 */

static UA_StatusCode function_namespace_euromap77_generated_34_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "StartJob");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "With this Method the client (e.g. MES) request the machine to change the JobStatus to JOB_IN_PRODUCTION_6");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[3], 7021),
UA_NODEID_NUMERIC(ns[3], 5013),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "StartJob"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 7021), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_namespace_euromap77_generated_34_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 7021)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* JobCycleCounter - ns=3;i=6090 */

static UA_StatusCode function_namespace_euromap77_generated_35_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 9);
UA_UInt64 *variablenode_ns_3_i_6090_variant_DataContents =  UA_UInt64_new();
if (!variablenode_ns_3_i_6090_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt64_init(variablenode_ns_3_i_6090_variant_DataContents);
*variablenode_ns_3_i_6090_variant_DataContents = (UA_UInt64) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6090_variant_DataContents, &UA_TYPES[UA_TYPES_UINT64]);
attr.displayName = UA_LOCALIZEDTEXT("", "JobCycleCounter");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Number of finished cycles in the job");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6090),
UA_NODEID_NUMERIC(ns[3], 5013),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "JobCycleCounter"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt64_delete(variablenode_ns_3_i_6090_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6090), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_35_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6090)
);
}

/* JobPartsCounter - ns=3;i=6092 */

static UA_StatusCode function_namespace_euromap77_generated_36_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 9);
UA_UInt64 *variablenode_ns_3_i_6092_variant_DataContents =  UA_UInt64_new();
if (!variablenode_ns_3_i_6092_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt64_init(variablenode_ns_3_i_6092_variant_DataContents);
*variablenode_ns_3_i_6092_variant_DataContents = (UA_UInt64) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6092_variant_DataContents, &UA_TYPES[UA_TYPES_UINT64]);
attr.displayName = UA_LOCALIZEDTEXT("", "JobPartsCounter");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Total number of parts produced in the current job");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6092),
UA_NODEID_NUMERIC(ns[3], 5013),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "JobPartsCounter"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt64_delete(variablenode_ns_3_i_6092_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6092), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_36_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6092)
);
}

/* FinishJob - ns=3;i=7016 */

static UA_StatusCode function_namespace_euromap77_generated_37_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "FinishJob");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "With this Method the client (e.g. MES) requests the machine to change the JobStatus to JOB_FINISHED_8");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[3], 7016),
UA_NODEID_NUMERIC(ns[3], 5013),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "FinishJob"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 7016), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_namespace_euromap77_generated_37_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 7016)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* InterruptJob - ns=3;i=7020 */

static UA_StatusCode function_namespace_euromap77_generated_38_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "InterruptJob");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "With this Method the client (e.g. MES) requests the machine to change the JobStatus to JOB_INTERRUPTED_7");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[3], 7020),
UA_NODEID_NUMERIC(ns[3], 5013),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "InterruptJob"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 7020), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_namespace_euromap77_generated_38_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 7020)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* StopAtCycleEnd - ns=3;i=7015 */

static UA_StatusCode function_namespace_euromap77_generated_39_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "StopAtCycleEnd");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Directs the machine to stop at the end of the current cycle");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[3], 7015),
UA_NODEID_NUMERIC(ns[3], 5013),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "StopAtCycleEnd"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 7015), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_namespace_euromap77_generated_39_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 7015)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* JobInPreparation - ns=3;i=5019 */

static UA_StatusCode function_namespace_euromap77_generated_40_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "JobInPreparation");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Job in a preparation layer of the machine");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[3], 5019),
UA_NODEID_NUMERIC(ns[3], 5004),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "JobInPreparation"),
UA_NODEID_NUMERIC(ns[2], 1024),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5019), UA_NODEID_NUMERIC(ns[0], 41), UA_EXPANDEDNODEID_NUMERIC(ns[2], 1025), true);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5019), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_40_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 5019)
);
}

/* SetCyclicJobData - ns=3;i=7026 */

static UA_StatusCode function_namespace_euromap77_generated_41_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "SetCyclicJobData");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Method for setting the data for cyclic jobs");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[3], 7026),
UA_NODEID_NUMERIC(ns[3], 5019),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "SetCyclicJobData"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 7026), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_namespace_euromap77_generated_41_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 7026)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* InputArguments - ns=3;i=6095 */

static UA_StatusCode function_namespace_euromap77_generated_42_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 14;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);
UA_Argument variablenode_ns_3_i_6095_variant_DataContents[14];

UA_init(&variablenode_ns_3_i_6095_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6095_variant_DataContents[0].name = UA_STRING("JobName");
variablenode_ns_3_i_6095_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[0], 12);
variablenode_ns_3_i_6095_variant_DataContents[0].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_3_i_6095_variant_DataContents[1], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6095_variant_DataContents[1].name = UA_STRING("JobDescription");
variablenode_ns_3_i_6095_variant_DataContents[1].dataType = UA_NODEID_NUMERIC(ns[0], 12);
variablenode_ns_3_i_6095_variant_DataContents[1].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_3_i_6095_variant_DataContents[2], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6095_variant_DataContents[2].name = UA_STRING("CustomerName");
variablenode_ns_3_i_6095_variant_DataContents[2].dataType = UA_NODEID_NUMERIC(ns[0], 12);
variablenode_ns_3_i_6095_variant_DataContents[2].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_3_i_6095_variant_DataContents[3], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6095_variant_DataContents[3].name = UA_STRING("ProductionDatasetName");
variablenode_ns_3_i_6095_variant_DataContents[3].dataType = UA_NODEID_NUMERIC(ns[0], 12);
variablenode_ns_3_i_6095_variant_DataContents[3].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_3_i_6095_variant_DataContents[4], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6095_variant_DataContents[4].name = UA_STRING("ProductionDatasetDescription");
variablenode_ns_3_i_6095_variant_DataContents[4].dataType = UA_NODEID_NUMERIC(ns[0], 12);
variablenode_ns_3_i_6095_variant_DataContents[4].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_3_i_6095_variant_DataContents[5], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6095_variant_DataContents[5].name = UA_STRING("Material");
variablenode_ns_3_i_6095_variant_DataContents[5].dataType = UA_NODEID_NUMERIC(ns[0], 12);
variablenode_ns_3_i_6095_variant_DataContents[5].valueRank = (UA_Int32) 1;

UA_init(&variablenode_ns_3_i_6095_variant_DataContents[6], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6095_variant_DataContents[6].name = UA_STRING("ProductName");
variablenode_ns_3_i_6095_variant_DataContents[6].dataType = UA_NODEID_NUMERIC(ns[0], 12);
variablenode_ns_3_i_6095_variant_DataContents[6].valueRank = (UA_Int32) 1;

UA_init(&variablenode_ns_3_i_6095_variant_DataContents[7], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6095_variant_DataContents[7].name = UA_STRING("ProductDescription");
variablenode_ns_3_i_6095_variant_DataContents[7].dataType = UA_NODEID_NUMERIC(ns[0], 12);
variablenode_ns_3_i_6095_variant_DataContents[7].valueRank = (UA_Int32) 1;

UA_init(&variablenode_ns_3_i_6095_variant_DataContents[8], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6095_variant_DataContents[8].name = UA_STRING("ContinueAtJobEnd");
variablenode_ns_3_i_6095_variant_DataContents[8].dataType = UA_NODEID_NUMERIC(ns[0], 1);
variablenode_ns_3_i_6095_variant_DataContents[8].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_3_i_6095_variant_DataContents[9], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6095_variant_DataContents[9].name = UA_STRING("NominalParts");
variablenode_ns_3_i_6095_variant_DataContents[9].dataType = UA_NODEID_NUMERIC(ns[0], 9);
variablenode_ns_3_i_6095_variant_DataContents[9].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_3_i_6095_variant_DataContents[10], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6095_variant_DataContents[10].name = UA_STRING("NominalBoxParts");
variablenode_ns_3_i_6095_variant_DataContents[10].dataType = UA_NODEID_NUMERIC(ns[0], 9);
variablenode_ns_3_i_6095_variant_DataContents[10].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_3_i_6095_variant_DataContents[11], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6095_variant_DataContents[11].name = UA_STRING("ExpectedCycleTime");
variablenode_ns_3_i_6095_variant_DataContents[11].dataType = UA_NODEID_NUMERIC(ns[0], 290);
variablenode_ns_3_i_6095_variant_DataContents[11].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_3_i_6095_variant_DataContents[12], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6095_variant_DataContents[12].name = UA_STRING("MouldId");
variablenode_ns_3_i_6095_variant_DataContents[12].dataType = UA_NODEID_NUMERIC(ns[0], 12);
variablenode_ns_3_i_6095_variant_DataContents[12].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_3_i_6095_variant_DataContents[13], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6095_variant_DataContents[13].name = UA_STRING("NumCavities");
variablenode_ns_3_i_6095_variant_DataContents[13].dataType = UA_NODEID_NUMERIC(ns[0], 7);
variablenode_ns_3_i_6095_variant_DataContents[13].valueRank = (UA_Int32) -1;
UA_Variant_setArray(&attr.value, &variablenode_ns_3_i_6095_variant_DataContents, (UA_Int32) 14, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "InputArguments");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6095),
UA_NODEID_NUMERIC(ns[3], 7026),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "InputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);














retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6095), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_42_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6095)
);
}

/* Material - ns=3;i=6111 */

static UA_StatusCode function_namespace_euromap77_generated_43_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 1;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String variablenode_ns_3_i_6111_variant_DataContents[1];
variablenode_ns_3_i_6111_variant_DataContents[0] = UA_STRING("");
UA_Variant_setArray(&attr.value, &variablenode_ns_3_i_6111_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "Material");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Array of material names used for the job");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6111),
UA_NODEID_NUMERIC(ns[3], 5019),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "Material"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6111), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_43_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6111)
);
}

/* JobName - ns=3;i=6110 */

static UA_StatusCode function_namespace_euromap77_generated_44_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6110_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6110_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6110_variant_DataContents);
*variablenode_ns_3_i_6110_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6110_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "JobName");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Name of the job");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6110),
UA_NODEID_NUMERIC(ns[3], 5019),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "JobName"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6110_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6110), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_44_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6110)
);
}

/* ProductionDatasetDescription - ns=3;i=6113 */

static UA_StatusCode function_namespace_euromap77_generated_45_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6113_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6113_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6113_variant_DataContents);
*variablenode_ns_3_i_6113_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6113_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "ProductionDatasetDescription");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Additional description of the production dataset which is needed for the job");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6113),
UA_NODEID_NUMERIC(ns[3], 5019),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "ProductionDatasetDescription"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6113_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6113), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_45_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6113)
);
}

/* ProductDescription - ns=3;i=6112 */

static UA_StatusCode function_namespace_euromap77_generated_46_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 0;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String variablenode_ns_3_i_6112_variant_DataContents[1];
variablenode_ns_3_i_6112_variant_DataContents[0] = UA_STRING("");
UA_Variant_setArray(&attr.value, &variablenode_ns_3_i_6112_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "ProductDescription");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Array of descriptions of the products produced by the job");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6112),
UA_NODEID_NUMERIC(ns[3], 5019),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "ProductDescription"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6112), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_46_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6112)
);
}

/* ContinueAtJobEnd - ns=3;i=6096 */

static UA_StatusCode function_namespace_euromap77_generated_47_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_3_i_6096_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_3_i_6096_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_3_i_6096_variant_DataContents);
*variablenode_ns_3_i_6096_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6096_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "ContinueAtJobEnd");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Indication if the machine continues the production even if the nominal output has been reached");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6096),
UA_NODEID_NUMERIC(ns[3], 5019),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "ContinueAtJobEnd"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_3_i_6096_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6096), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_47_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6096)
);
}

/* NominalParts - ns=3;i=6094 */

static UA_StatusCode function_namespace_euromap77_generated_48_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 9);
UA_UInt64 *variablenode_ns_3_i_6094_variant_DataContents =  UA_UInt64_new();
if (!variablenode_ns_3_i_6094_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt64_init(variablenode_ns_3_i_6094_variant_DataContents);
*variablenode_ns_3_i_6094_variant_DataContents = (UA_UInt64) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6094_variant_DataContents, &UA_TYPES[UA_TYPES_UINT64]);
attr.displayName = UA_LOCALIZEDTEXT("", "NominalParts");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Total number (sum of all cavities) of parts that shall be produced by the job");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6094),
UA_NODEID_NUMERIC(ns[3], 5019),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "NominalParts"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt64_delete(variablenode_ns_3_i_6094_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6094), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6094), UA_NODEID_NUMERIC(ns[0], 41), UA_EXPANDEDNODEID_NUMERIC(ns[2], 1025), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_48_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6094)
);
}

/* CustomerName - ns=3;i=6108 */

static UA_StatusCode function_namespace_euromap77_generated_49_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6108_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6108_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6108_variant_DataContents);
*variablenode_ns_3_i_6108_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6108_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "CustomerName");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Name of the cumstomer for that the job is produced");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6108),
UA_NODEID_NUMERIC(ns[3], 5019),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "CustomerName"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6108_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6108), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_49_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6108)
);
}

/* JobDescription - ns=3;i=6109 */

static UA_StatusCode function_namespace_euromap77_generated_50_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6109_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6109_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6109_variant_DataContents);
*variablenode_ns_3_i_6109_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6109_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "JobDescription");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Description of the job");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6109),
UA_NODEID_NUMERIC(ns[3], 5019),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "JobDescription"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6109_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6109), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_50_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6109)
);
}

/* ProductionDatasetName - ns=3;i=6144 */

static UA_StatusCode function_namespace_euromap77_generated_51_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6144_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6144_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6144_variant_DataContents);
*variablenode_ns_3_i_6144_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6144_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "ProductionDatasetName");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Name of the production dataset which is needed for the job");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6144),
UA_NODEID_NUMERIC(ns[3], 5019),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "ProductionDatasetName"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6144_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6144), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_51_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6144)
);
}

/* ProductName - ns=3;i=6145 */

static UA_StatusCode function_namespace_euromap77_generated_52_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 0;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String variablenode_ns_3_i_6145_variant_DataContents[1];
variablenode_ns_3_i_6145_variant_DataContents[0] = UA_STRING("");
UA_Variant_setArray(&attr.value, &variablenode_ns_3_i_6145_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "ProductName");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Array of product names produced by the job");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6145),
UA_NODEID_NUMERIC(ns[3], 5019),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "ProductName"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6145), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_52_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6145)
);
}

/* ActiveJob - ns=3;i=5002 */

static UA_StatusCode function_namespace_euromap77_generated_53_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "ActiveJob");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Job that is currently active on the machine");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[3], 5002),
UA_NODEID_NUMERIC(ns[3], 5004),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "ActiveJob"),
UA_NODEID_NUMERIC(ns[2], 1024),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5002), UA_NODEID_NUMERIC(ns[0], 41), UA_EXPANDEDNODEID_NUMERIC(ns[2], 1025), true);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5002), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_53_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 5002)
);
}

/* CustomerName - ns=3;i=6036 */

static UA_StatusCode function_namespace_euromap77_generated_54_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6036_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6036_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6036_variant_DataContents);
*variablenode_ns_3_i_6036_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6036_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "CustomerName");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Name of the cumstomer for that the job is produced");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6036),
UA_NODEID_NUMERIC(ns[3], 5002),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "CustomerName"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6036_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6036), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_54_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6036)
);
}

/* SetCyclicJobData - ns=3;i=7019 */

static UA_StatusCode function_namespace_euromap77_generated_55_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "SetCyclicJobData");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Method for setting the data for cyclic jobs");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[3], 7019),
UA_NODEID_NUMERIC(ns[3], 5002),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "SetCyclicJobData"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 7019), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_namespace_euromap77_generated_55_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 7019)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* InputArguments - ns=3;i=6019 */

static UA_StatusCode function_namespace_euromap77_generated_56_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 14;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);
UA_Argument variablenode_ns_3_i_6019_variant_DataContents[14];

UA_init(&variablenode_ns_3_i_6019_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6019_variant_DataContents[0].name = UA_STRING("JobName");
variablenode_ns_3_i_6019_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[0], 12);
variablenode_ns_3_i_6019_variant_DataContents[0].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_3_i_6019_variant_DataContents[1], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6019_variant_DataContents[1].name = UA_STRING("JobDescription");
variablenode_ns_3_i_6019_variant_DataContents[1].dataType = UA_NODEID_NUMERIC(ns[0], 12);
variablenode_ns_3_i_6019_variant_DataContents[1].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_3_i_6019_variant_DataContents[2], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6019_variant_DataContents[2].name = UA_STRING("CustomerName");
variablenode_ns_3_i_6019_variant_DataContents[2].dataType = UA_NODEID_NUMERIC(ns[0], 12);
variablenode_ns_3_i_6019_variant_DataContents[2].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_3_i_6019_variant_DataContents[3], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6019_variant_DataContents[3].name = UA_STRING("ProductionDatasetName");
variablenode_ns_3_i_6019_variant_DataContents[3].dataType = UA_NODEID_NUMERIC(ns[0], 12);
variablenode_ns_3_i_6019_variant_DataContents[3].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_3_i_6019_variant_DataContents[4], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6019_variant_DataContents[4].name = UA_STRING("ProductionDatasetDescription");
variablenode_ns_3_i_6019_variant_DataContents[4].dataType = UA_NODEID_NUMERIC(ns[0], 12);
variablenode_ns_3_i_6019_variant_DataContents[4].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_3_i_6019_variant_DataContents[5], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6019_variant_DataContents[5].name = UA_STRING("Material");
variablenode_ns_3_i_6019_variant_DataContents[5].dataType = UA_NODEID_NUMERIC(ns[0], 12);
variablenode_ns_3_i_6019_variant_DataContents[5].valueRank = (UA_Int32) 1;

UA_init(&variablenode_ns_3_i_6019_variant_DataContents[6], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6019_variant_DataContents[6].name = UA_STRING("ProductName");
variablenode_ns_3_i_6019_variant_DataContents[6].dataType = UA_NODEID_NUMERIC(ns[0], 12);
variablenode_ns_3_i_6019_variant_DataContents[6].valueRank = (UA_Int32) 1;

UA_init(&variablenode_ns_3_i_6019_variant_DataContents[7], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6019_variant_DataContents[7].name = UA_STRING("ProductDescription");
variablenode_ns_3_i_6019_variant_DataContents[7].dataType = UA_NODEID_NUMERIC(ns[0], 12);
variablenode_ns_3_i_6019_variant_DataContents[7].valueRank = (UA_Int32) 1;

UA_init(&variablenode_ns_3_i_6019_variant_DataContents[8], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6019_variant_DataContents[8].name = UA_STRING("ContinueAtJobEnd");
variablenode_ns_3_i_6019_variant_DataContents[8].dataType = UA_NODEID_NUMERIC(ns[0], 1);
variablenode_ns_3_i_6019_variant_DataContents[8].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_3_i_6019_variant_DataContents[9], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6019_variant_DataContents[9].name = UA_STRING("NominalParts");
variablenode_ns_3_i_6019_variant_DataContents[9].dataType = UA_NODEID_NUMERIC(ns[0], 9);
variablenode_ns_3_i_6019_variant_DataContents[9].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_3_i_6019_variant_DataContents[10], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6019_variant_DataContents[10].name = UA_STRING("NominalBoxParts");
variablenode_ns_3_i_6019_variant_DataContents[10].dataType = UA_NODEID_NUMERIC(ns[0], 9);
variablenode_ns_3_i_6019_variant_DataContents[10].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_3_i_6019_variant_DataContents[11], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6019_variant_DataContents[11].name = UA_STRING("ExpectedCycleTime");
variablenode_ns_3_i_6019_variant_DataContents[11].dataType = UA_NODEID_NUMERIC(ns[0], 290);
variablenode_ns_3_i_6019_variant_DataContents[11].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_3_i_6019_variant_DataContents[12], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6019_variant_DataContents[12].name = UA_STRING("MouldId");
variablenode_ns_3_i_6019_variant_DataContents[12].dataType = UA_NODEID_NUMERIC(ns[0], 12);
variablenode_ns_3_i_6019_variant_DataContents[12].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_3_i_6019_variant_DataContents[13], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6019_variant_DataContents[13].name = UA_STRING("NumCavities");
variablenode_ns_3_i_6019_variant_DataContents[13].dataType = UA_NODEID_NUMERIC(ns[0], 7);
variablenode_ns_3_i_6019_variant_DataContents[13].valueRank = (UA_Int32) -1;
UA_Variant_setArray(&attr.value, &variablenode_ns_3_i_6019_variant_DataContents, (UA_Int32) 14, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "InputArguments");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6019),
UA_NODEID_NUMERIC(ns[3], 7019),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "InputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);














retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6019), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_56_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6019)
);
}

/* ContinueAtJobEnd - ns=3;i=6035 */

static UA_StatusCode function_namespace_euromap77_generated_57_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_3_i_6035_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_3_i_6035_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_3_i_6035_variant_DataContents);
*variablenode_ns_3_i_6035_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6035_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "ContinueAtJobEnd");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Indication if the machine continues the production even if the nominal output has been reached");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6035),
UA_NODEID_NUMERIC(ns[3], 5002),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "ContinueAtJobEnd"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_3_i_6035_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6035), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_57_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6035)
);
}

/* ProductionDatasetName - ns=3;i=6087 */

static UA_StatusCode function_namespace_euromap77_generated_58_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6087_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6087_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6087_variant_DataContents);
*variablenode_ns_3_i_6087_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6087_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "ProductionDatasetName");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Name of the production dataset which is needed for the job");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6087),
UA_NODEID_NUMERIC(ns[3], 5002),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "ProductionDatasetName"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6087_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6087), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_58_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6087)
);
}

/* ProductionDatasetDescription - ns=3;i=6045 */

static UA_StatusCode function_namespace_euromap77_generated_59_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6045_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6045_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6045_variant_DataContents);
*variablenode_ns_3_i_6045_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6045_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "ProductionDatasetDescription");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Additional description of the production dataset which is needed for the job");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6045),
UA_NODEID_NUMERIC(ns[3], 5002),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "ProductionDatasetDescription"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6045_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6045), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_59_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6045)
);
}

/* ProductName - ns=3;i=6088 */

static UA_StatusCode function_namespace_euromap77_generated_60_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 0;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String variablenode_ns_3_i_6088_variant_DataContents[1];
variablenode_ns_3_i_6088_variant_DataContents[0] = UA_STRING("");
UA_Variant_setArray(&attr.value, &variablenode_ns_3_i_6088_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "ProductName");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Array of product names produced by the job");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6088),
UA_NODEID_NUMERIC(ns[3], 5002),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "ProductName"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6088), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_60_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6088)
);
}

/* JobName - ns=3;i=6038 */

static UA_StatusCode function_namespace_euromap77_generated_61_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6038_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6038_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6038_variant_DataContents);
*variablenode_ns_3_i_6038_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6038_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "JobName");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Name of the job");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6038),
UA_NODEID_NUMERIC(ns[3], 5002),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "JobName"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6038_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6038), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_61_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6038)
);
}

/* ProductDescription - ns=3;i=6040 */

static UA_StatusCode function_namespace_euromap77_generated_62_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 0;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String variablenode_ns_3_i_6040_variant_DataContents[1];
variablenode_ns_3_i_6040_variant_DataContents[0] = UA_STRING("");
UA_Variant_setArray(&attr.value, &variablenode_ns_3_i_6040_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "ProductDescription");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Array of descriptions of the products produced by the job");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6040),
UA_NODEID_NUMERIC(ns[3], 5002),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "ProductDescription"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6040), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_62_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6040)
);
}

/* JobDescription - ns=3;i=6037 */

static UA_StatusCode function_namespace_euromap77_generated_63_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6037_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6037_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6037_variant_DataContents);
*variablenode_ns_3_i_6037_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6037_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "JobDescription");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Description of the job");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6037),
UA_NODEID_NUMERIC(ns[3], 5002),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "JobDescription"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6037_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6037), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_63_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6037)
);
}

/* NominalParts - ns=3;i=6003 */

static UA_StatusCode function_namespace_euromap77_generated_64_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 9);
UA_UInt64 *variablenode_ns_3_i_6003_variant_DataContents =  UA_UInt64_new();
if (!variablenode_ns_3_i_6003_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt64_init(variablenode_ns_3_i_6003_variant_DataContents);
*variablenode_ns_3_i_6003_variant_DataContents = (UA_UInt64) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6003_variant_DataContents, &UA_TYPES[UA_TYPES_UINT64]);
attr.displayName = UA_LOCALIZEDTEXT("", "NominalParts");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Total number (sum of all cavities) of parts that shall be produced by the job");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6003),
UA_NODEID_NUMERIC(ns[3], 5002),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "NominalParts"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt64_delete(variablenode_ns_3_i_6003_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6003), UA_NODEID_NUMERIC(ns[0], 41), UA_EXPANDEDNODEID_NUMERIC(ns[2], 1025), true);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6003), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_64_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6003)
);
}

/* Material - ns=3;i=6039 */

static UA_StatusCode function_namespace_euromap77_generated_65_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 1;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String variablenode_ns_3_i_6039_variant_DataContents[1];
variablenode_ns_3_i_6039_variant_DataContents[0] = UA_STRING("");
UA_Variant_setArray(&attr.value, &variablenode_ns_3_i_6039_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "Material");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Array of material names used for the job");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6039),
UA_NODEID_NUMERIC(ns[3], 5002),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "Material"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6039), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_65_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6039)
);
}

/* SendCyclicJobList - ns=3;i=7017 */

static UA_StatusCode function_namespace_euromap77_generated_66_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "SendCyclicJobList");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Sends a list of jobs for cyclic processes available on the client to the server");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[3], 7017),
UA_NODEID_NUMERIC(ns[3], 5004),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "SendCyclicJobList"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 7017), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_namespace_euromap77_generated_66_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 7017)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* InputArguments - ns=3;i=6114 */

static UA_StatusCode function_namespace_euromap77_generated_67_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 1;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);
UA_Argument variablenode_ns_3_i_6114_variant_DataContents[1];

UA_init(&variablenode_ns_3_i_6114_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6114_variant_DataContents[0].name = UA_STRING("JobList");
variablenode_ns_3_i_6114_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[2], 3022);
variablenode_ns_3_i_6114_variant_DataContents[0].valueRank = (UA_Int32) 1;
UA_Variant_setArray(&attr.value, &variablenode_ns_3_i_6114_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "InputArguments");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6114),
UA_NODEID_NUMERIC(ns[3], 7017),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "InputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6114), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_67_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6114)
);
}

/* MachineConfiguration - ns=3;i=5005 */

static UA_StatusCode function_namespace_euromap77_generated_68_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "MachineConfiguration");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Current configuration of the machine");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[3], 5005),
UA_NODEID_NUMERIC(ns[3], 1007),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "MachineConfiguration"),
UA_NODEID_NUMERIC(ns[2], 1016),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5005), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_68_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 5005)
);
}

/* GetCurrentPage - ns=3;i=7029 */

static UA_StatusCode function_namespace_euromap77_generated_69_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "GetCurrentPage");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Method for retrieving a screenshot of the control system with the currently shown contents");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[3], 7029),
UA_NODEID_NUMERIC(ns[3], 5005),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "GetCurrentPage"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 7029), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_namespace_euromap77_generated_69_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 7029)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* OutputArguments - ns=3;i=6076 */

static UA_StatusCode function_namespace_euromap77_generated_70_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 1;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);
UA_Argument variablenode_ns_3_i_6076_variant_DataContents[1];

UA_init(&variablenode_ns_3_i_6076_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6076_variant_DataContents[0].name = UA_STRING("Page");
variablenode_ns_3_i_6076_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[0], 30);
variablenode_ns_3_i_6076_variant_DataContents[0].valueRank = (UA_Int32) -1;
UA_Variant_setArray(&attr.value, &variablenode_ns_3_i_6076_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "OutputArguments");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6076),
UA_NODEID_NUMERIC(ns[3], 7029),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "OutputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6076), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_70_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6076)
);
}

/* InputArguments - ns=3;i=6075 */

static UA_StatusCode function_namespace_euromap77_generated_71_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 1;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);
UA_Argument variablenode_ns_3_i_6075_variant_DataContents[1];

UA_init(&variablenode_ns_3_i_6075_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6075_variant_DataContents[0].name = UA_STRING("VisualisationUnit");
variablenode_ns_3_i_6075_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[0], 7);
variablenode_ns_3_i_6075_variant_DataContents[0].valueRank = (UA_Int32) -1;
UA_Variant_setArray(&attr.value, &variablenode_ns_3_i_6075_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "InputArguments");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6075),
UA_NODEID_NUMERIC(ns[3], 7029),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "InputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6075), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_71_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6075)
);
}

/* UserMachineName - ns=3;i=6034 */

static UA_StatusCode function_namespace_euromap77_generated_72_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6034_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6034_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6034_variant_DataContents);
*variablenode_ns_3_i_6034_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6034_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "UserMachineName");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Description of the machine given by the machine operator or OPC client");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6034),
UA_NODEID_NUMERIC(ns[3], 5005),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "UserMachineName"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6034_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6034), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_72_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6034)
);
}

/* LocationName - ns=3;i=6029 */

static UA_StatusCode function_namespace_euromap77_generated_73_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6029_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6029_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6029_variant_DataContents);
*variablenode_ns_3_i_6029_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6029_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "LocationName");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Description of the location of the machine given by the machine operator or OPC client");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6029),
UA_NODEID_NUMERIC(ns[3], 5005),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "LocationName"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6029_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6029), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_73_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6029)
);
}

/* GetPage - ns=3;i=7030 */

static UA_StatusCode function_namespace_euromap77_generated_74_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "GetPage");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Method for retrieving the image of a page of the control system");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[3], 7030),
UA_NODEID_NUMERIC(ns[3], 5005),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "GetPage"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 7030), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_namespace_euromap77_generated_74_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 7030)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* OutputArguments - ns=3;i=6078 */

static UA_StatusCode function_namespace_euromap77_generated_75_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 1;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);
UA_Argument variablenode_ns_3_i_6078_variant_DataContents[1];

UA_init(&variablenode_ns_3_i_6078_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6078_variant_DataContents[0].name = UA_STRING("Page");
variablenode_ns_3_i_6078_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[0], 30);
variablenode_ns_3_i_6078_variant_DataContents[0].valueRank = (UA_Int32) -1;
UA_Variant_setArray(&attr.value, &variablenode_ns_3_i_6078_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "OutputArguments");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6078),
UA_NODEID_NUMERIC(ns[3], 7030),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "OutputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6078), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_75_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6078)
);
}

/* InputArguments - ns=3;i=6077 */

static UA_StatusCode function_namespace_euromap77_generated_76_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 1;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);
UA_Argument variablenode_ns_3_i_6077_variant_DataContents[1];

UA_init(&variablenode_ns_3_i_6077_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6077_variant_DataContents[0].name = UA_STRING("Id");
variablenode_ns_3_i_6077_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[0], 12);
variablenode_ns_3_i_6077_variant_DataContents[0].valueRank = (UA_Int32) -1;
UA_Variant_setArray(&attr.value, &variablenode_ns_3_i_6077_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "InputArguments");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6077),
UA_NODEID_NUMERIC(ns[3], 7030),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "InputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6077), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_76_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6077)
);
}

/* TimeZoneOffset - ns=3;i=6033 */

static UA_StatusCode function_namespace_euromap77_generated_77_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 8912);

UA_STACKARRAY(UA_TimeZoneDataType, variablenode_ns_3_i_6033_TimeZoneDataType_0, 1);
UA_init(variablenode_ns_3_i_6033_TimeZoneDataType_0, &UA_TYPES[UA_TYPES_TIMEZONEDATATYPE]);
variablenode_ns_3_i_6033_TimeZoneDataType_0->offset = (UA_Int16) 0;
variablenode_ns_3_i_6033_TimeZoneDataType_0->daylightSavingInOffset = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6033_TimeZoneDataType_0, &UA_TYPES[UA_TYPES_TIMEZONEDATATYPE]);
attr.displayName = UA_LOCALIZEDTEXT("", "TimeZoneOffset");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Difference of the local time to Coordinated Universal Time (UTC) given by the machine operator or OPC client");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6033),
UA_NODEID_NUMERIC(ns[3], 5005),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "TimeZoneOffset"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6033), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_77_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6033)
);
}

/* PageDirectory - ns=3;i=6079 */

static UA_StatusCode function_namespace_euromap77_generated_78_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 0;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[2], 3014);
UA_PageEntryDataType variablenode_ns_3_i_6079_variant_DataContents[1];

UA_init(&variablenode_ns_3_i_6079_variant_DataContents[0], &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PAGEENTRYDATATYPE]);
variablenode_ns_3_i_6079_variant_DataContents[0].id = UA_STRING("");
UA_Variant_setArray(&attr.value, &variablenode_ns_3_i_6079_variant_DataContents, (UA_Int32) 1, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PAGEENTRYDATATYPE]);
attr.displayName = UA_LOCALIZEDTEXT("", "PageDirectory");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "List of the pages that are implemented in the machine control system and are shown on the screen of the machine");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6079),
UA_NODEID_NUMERIC(ns[3], 5005),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "PageDirectory"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6079), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_78_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6079)
);
}

/* SetMachineTime - ns=3;i=7005 */

static UA_StatusCode function_namespace_euromap77_generated_79_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "SetMachineTime");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Method for setting the server time together with TimeZoneOffset");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[3], 7005),
UA_NODEID_NUMERIC(ns[3], 5005),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "SetMachineTime"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 7005), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_namespace_euromap77_generated_79_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 7005)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* InputArguments - ns=3;i=6030 */

static UA_StatusCode function_namespace_euromap77_generated_80_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 2;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);
UA_Argument variablenode_ns_3_i_6030_variant_DataContents[2];

UA_init(&variablenode_ns_3_i_6030_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6030_variant_DataContents[0].name = UA_STRING("DateTime");
variablenode_ns_3_i_6030_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[0], 13);
variablenode_ns_3_i_6030_variant_DataContents[0].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_3_i_6030_variant_DataContents[1], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6030_variant_DataContents[1].name = UA_STRING("TimeZoneOffset");
variablenode_ns_3_i_6030_variant_DataContents[1].dataType = UA_NODEID_NUMERIC(ns[0], 8912);
variablenode_ns_3_i_6030_variant_DataContents[1].valueRank = (UA_Int32) -1;
UA_Variant_setArray(&attr.value, &variablenode_ns_3_i_6030_variant_DataContents, (UA_Int32) 2, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "InputArguments");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6030),
UA_NODEID_NUMERIC(ns[3], 7005),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "InputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);


retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6030), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_80_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6030)
);
}

/* MachineMESStatus - ns=3;i=5011 */

static UA_StatusCode function_namespace_euromap77_generated_81_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.eventNotifier = true;
attr.displayName = UA_LOCALIZEDTEXT("", "MachineMESStatus");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Current status of a machine related to the MES");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[3], 5011),
UA_NODEID_NUMERIC(ns[3], 1007),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "MachineMESStatus"),
UA_NODEID_NUMERIC(ns[2], 1020),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5011), UA_NODEID_NUMERIC(ns[0], 41), UA_EXPANDEDNODEID_NUMERIC(ns[2], 1004), true);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5011), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_81_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 5011)
);
}

/* ClearMESMessage - ns=3;i=7006 */

static UA_StatusCode function_namespace_euromap77_generated_82_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "ClearMESMessage");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Method for clearing the MESMessage");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[3], 7006),
UA_NODEID_NUMERIC(ns[3], 5011),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "ClearMESMessage"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 7006), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_namespace_euromap77_generated_82_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 7006)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* SetMESMessage - ns=3;i=7009 */

static UA_StatusCode function_namespace_euromap77_generated_83_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "SetMESMessage");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Method for setting the MESMessage");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[3], 7009),
UA_NODEID_NUMERIC(ns[3], 5011),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "SetMESMessage"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 7009), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_namespace_euromap77_generated_83_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 7009)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* InputArguments - ns=3;i=6048 */

static UA_StatusCode function_namespace_euromap77_generated_84_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 3;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);
UA_Argument variablenode_ns_3_i_6048_variant_DataContents[3];

UA_init(&variablenode_ns_3_i_6048_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6048_variant_DataContents[0].name = UA_STRING("Id");
variablenode_ns_3_i_6048_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[0], 12);
variablenode_ns_3_i_6048_variant_DataContents[0].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_3_i_6048_variant_DataContents[1], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6048_variant_DataContents[1].name = UA_STRING("Message");
variablenode_ns_3_i_6048_variant_DataContents[1].dataType = UA_NODEID_NUMERIC(ns[0], 12);
variablenode_ns_3_i_6048_variant_DataContents[1].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_3_i_6048_variant_DataContents[2], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6048_variant_DataContents[2].name = UA_STRING("Severity");
variablenode_ns_3_i_6048_variant_DataContents[2].dataType = UA_NODEID_NUMERIC(ns[0], 5);
variablenode_ns_3_i_6048_variant_DataContents[2].valueRank = (UA_Int32) -1;
UA_Variant_setArray(&attr.value, &variablenode_ns_3_i_6048_variant_DataContents, (UA_Int32) 3, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "InputArguments");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6048),
UA_NODEID_NUMERIC(ns[3], 7009),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "InputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);



retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6048), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_84_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6048)
);
}

/* StandstillReasonId - ns=3;i=6073 */

static UA_StatusCode function_namespace_euromap77_generated_85_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6073_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6073_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6073_variant_DataContents);
*variablenode_ns_3_i_6073_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6073_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "StandstillReasonId");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Id of the StandstillReason set by the operator after a standstill occurs");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6073),
UA_NODEID_NUMERIC(ns[3], 5011),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "StandstillReasonId"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6073_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6073), UA_NODEID_NUMERIC(ns[0], 41), UA_EXPANDEDNODEID_NUMERIC(ns[2], 1004), true);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6073), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_85_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6073)
);
}

/* StandstillMessage - ns=3;i=5016 */

static UA_StatusCode function_namespace_euromap77_generated_86_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "StandstillMessage");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[3], 5016),
UA_NODEID_NUMERIC(ns[3], 5011),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "StandstillMessage"),
UA_NODEID_NUMERIC(ns[2], 1026),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5016), UA_NODEID_NUMERIC(ns[0], 41), UA_EXPANDEDNODEID_NUMERIC(ns[2], 1004), true);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5016), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_86_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 5016)
);
}

/* Id - ns=3;i=6053 */

static UA_StatusCode function_namespace_euromap77_generated_87_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6053_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6053_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6053_variant_DataContents);
*variablenode_ns_3_i_6053_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6053_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "Id");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Id of the message");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6053),
UA_NODEID_NUMERIC(ns[3], 5016),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "Id"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6053_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6053), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_87_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6053)
);
}

/* Classification - ns=3;i=6052 */

static UA_StatusCode function_namespace_euromap77_generated_88_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 29);
attr.displayName = UA_LOCALIZEDTEXT("", "Classification");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Classification of the message");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6052),
UA_NODEID_NUMERIC(ns[3], 5016),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "Classification"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6052), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_88_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6052)
);
}

/* Severity - ns=3;i=6055 */

static UA_StatusCode function_namespace_euromap77_generated_89_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 5);
UA_UInt16 *variablenode_ns_3_i_6055_variant_DataContents =  UA_UInt16_new();
if (!variablenode_ns_3_i_6055_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt16_init(variablenode_ns_3_i_6055_variant_DataContents);
*variablenode_ns_3_i_6055_variant_DataContents = (UA_UInt16) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6055_variant_DataContents, &UA_TYPES[UA_TYPES_UINT16]);
attr.displayName = UA_LOCALIZEDTEXT("", "Severity");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Severity of the message");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6055),
UA_NODEID_NUMERIC(ns[3], 5016),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "Severity"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt16_delete(variablenode_ns_3_i_6055_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6055), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_89_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6055)
);
}

/* Message - ns=3;i=6054 */

static UA_StatusCode function_namespace_euromap77_generated_90_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 21);
attr.displayName = UA_LOCALIZEDTEXT("", "Message");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Text of the message");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6054),
UA_NODEID_NUMERIC(ns[3], 5016),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "Message"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6054), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_90_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6054)
);
}

/* ProductionControl - ns=3;i=5015 */

static UA_StatusCode function_namespace_euromap77_generated_91_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "ProductionControl");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Control of the production of the machine by MES");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[3], 5015),
UA_NODEID_NUMERIC(ns[3], 5011),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "ProductionControl"),
UA_NODEID_NUMERIC(ns[2], 1017),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5015), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5015), UA_NODEID_NUMERIC(ns[0], 41), UA_EXPANDEDNODEID_NUMERIC(ns[2], 1004), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_91_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 5015)
);
}

/* ProductionStatus - ns=3;i=6047 */

static UA_StatusCode function_namespace_euromap77_generated_92_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[2], 3016);
UA_Int32 *variablenode_ns_3_i_6047_variant_DataContents =  UA_Int32_new();
if (!variablenode_ns_3_i_6047_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Int32_init(variablenode_ns_3_i_6047_variant_DataContents);
*variablenode_ns_3_i_6047_variant_DataContents = (UA_Int32) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6047_variant_DataContents, &UA_TYPES[UA_TYPES_INT32]);
attr.displayName = UA_LOCALIZEDTEXT("", "ProductionStatus");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Production status when the machine is in automatic or semi-automatic mode");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6047),
UA_NODEID_NUMERIC(ns[3], 5015),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "ProductionStatus"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Int32_delete(variablenode_ns_3_i_6047_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6047), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_92_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6047)
);
}

/* ProductionReleasedByMES - ns=3;i=6046 */

static UA_StatusCode function_namespace_euromap77_generated_93_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_3_i_6046_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_3_i_6046_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_3_i_6046_variant_DataContents);
*variablenode_ns_3_i_6046_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6046_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "ProductionReleasedByMES");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Indication if ProductionStatus may have the value PRODUCTION_4");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6046),
UA_NODEID_NUMERIC(ns[3], 5015),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "ProductionReleasedByMES"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_3_i_6046_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6046), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_93_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6046)
);
}

/* DisableAutomaticRun - ns=3;i=7007 */

static UA_StatusCode function_namespace_euromap77_generated_94_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "DisableAutomaticRun");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Method for disabling the semi-automatic and automatic run of the machine");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[3], 7007),
UA_NODEID_NUMERIC(ns[3], 5015),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "DisableAutomaticRun"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 7007), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_namespace_euromap77_generated_94_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 7007)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* AutomaticRunEnabled - ns=3;i=6015 */

static UA_StatusCode function_namespace_euromap77_generated_95_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_3_i_6015_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_3_i_6015_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_3_i_6015_variant_DataContents);
*variablenode_ns_3_i_6015_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6015_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "AutomaticRunEnabled");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Indication if semi-automatic and automatic run of the machine is allowed by MES");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6015),
UA_NODEID_NUMERIC(ns[3], 5015),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "AutomaticRunEnabled"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_3_i_6015_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6015), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_95_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6015)
);
}

/* EnableAutomaticRun - ns=3;i=7008 */

static UA_StatusCode function_namespace_euromap77_generated_96_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "EnableAutomaticRun");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Method for enabling the semi-automatic and automatic run of the machine");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[3], 7008),
UA_NODEID_NUMERIC(ns[3], 5015),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "EnableAutomaticRun"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 7008), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_namespace_euromap77_generated_96_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 7008)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* MESMessage - ns=3;i=5012 */

static UA_StatusCode function_namespace_euromap77_generated_97_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "MESMessage");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Text message sent from the MES to be shown on the machine");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[3], 5012),
UA_NODEID_NUMERIC(ns[3], 5011),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "MESMessage"),
UA_NODEID_NUMERIC(ns[2], 1051),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5012), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5012), UA_NODEID_NUMERIC(ns[0], 41), UA_EXPANDEDNODEID_NUMERIC(ns[2], 1004), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_97_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 5012)
);
}

/* Message - ns=3;i=6011 */

static UA_StatusCode function_namespace_euromap77_generated_98_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6011_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6011_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6011_variant_DataContents);
*variablenode_ns_3_i_6011_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6011_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "Message");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Text of the message");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6011),
UA_NODEID_NUMERIC(ns[3], 5012),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "Message"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6011_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6011), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_98_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6011)
);
}

/* Id - ns=3;i=6010 */

static UA_StatusCode function_namespace_euromap77_generated_99_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6010_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6010_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6010_variant_DataContents);
*variablenode_ns_3_i_6010_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6010_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "Id");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Id of the message");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6010),
UA_NODEID_NUMERIC(ns[3], 5012),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "Id"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6010_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6010), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_99_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6010)
);
}

/* Severity - ns=3;i=6014 */

static UA_StatusCode function_namespace_euromap77_generated_100_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 5);
UA_UInt16 *variablenode_ns_3_i_6014_variant_DataContents =  UA_UInt16_new();
if (!variablenode_ns_3_i_6014_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt16_init(variablenode_ns_3_i_6014_variant_DataContents);
*variablenode_ns_3_i_6014_variant_DataContents = (UA_UInt16) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6014_variant_DataContents, &UA_TYPES[UA_TYPES_UINT16]);
attr.displayName = UA_LOCALIZEDTEXT("", "Severity");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Severity of the message");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6014),
UA_NODEID_NUMERIC(ns[3], 5012),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "Severity"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt16_delete(variablenode_ns_3_i_6014_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6014), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_100_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6014)
);
}

/* MachineInformation - ns=3;i=5001 */

static UA_StatusCode function_namespace_euromap77_generated_101_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "MachineInformation");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "General description of the machine");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[3], 5001),
UA_NODEID_NUMERIC(ns[3], 1007),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "MachineInformation"),
UA_NODEID_NUMERIC(ns[2], 1009),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5001), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_101_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 5001)
);
}

/* HardwareRevision - ns=3;i=6017 */

static UA_StatusCode function_namespace_euromap77_generated_102_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
attr.displayName = UA_LOCALIZEDTEXT("", "HardwareRevision");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Revision level of the hardware of the device");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6017),
UA_NODEID_NUMERIC(ns[3], 5001),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[1], "HardwareRevision"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6017), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_102_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6017)
);
}

/* SoftwareRevision - ns=3;i=6025 */

static UA_StatusCode function_namespace_euromap77_generated_103_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
attr.displayName = UA_LOCALIZEDTEXT("", "SoftwareRevision");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Revision level of the software/firmware of the device");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6025),
UA_NODEID_NUMERIC(ns[3], 5001),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[1], "SoftwareRevision"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6025), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_103_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6025)
);
}

/* DeviceClass - ns=3;i=6084 */

static UA_StatusCode function_namespace_euromap77_generated_104_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
attr.displayName = UA_LOCALIZEDTEXT("", "DeviceClass");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Indicates in which domain or for what purpose a device is used.");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6084),
UA_NODEID_NUMERIC(ns[3], 5001),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[1], "DeviceClass"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6084), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_104_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6084)
);
}

/* SerialNumber - ns=3;i=6024 */

static UA_StatusCode function_namespace_euromap77_generated_105_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
attr.displayName = UA_LOCALIZEDTEXT("", "SerialNumber");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Identifier that uniquely identifies, within a manufacturer, a device instance");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6024),
UA_NODEID_NUMERIC(ns[3], 5001),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[1], "SerialNumber"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6024), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_105_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6024)
);
}

/* Manufacturer - ns=3;i=6021 */

static UA_StatusCode function_namespace_euromap77_generated_106_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 21);
attr.displayName = UA_LOCALIZEDTEXT("", "Manufacturer");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Name of the company that manufactured the device");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6021),
UA_NODEID_NUMERIC(ns[3], 5001),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[1], "Manufacturer"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6021), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_106_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6021)
);
}

/* Model - ns=3;i=6022 */

static UA_StatusCode function_namespace_euromap77_generated_107_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 21);
attr.displayName = UA_LOCALIZEDTEXT("", "Model");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Model name of the device");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6022),
UA_NODEID_NUMERIC(ns[3], 5001),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[1], "Model"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6022), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_107_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6022)
);
}

/* RevisionCounter - ns=3;i=6023 */

static UA_StatusCode function_namespace_euromap77_generated_108_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 6);
attr.displayName = UA_LOCALIZEDTEXT("", "RevisionCounter");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "An incremental counter indicating the number of times the static data within the Device has been modified");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6023),
UA_NODEID_NUMERIC(ns[3], 5001),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[1], "RevisionCounter"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6023), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_108_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6023)
);
}

/* DeviceManual - ns=3;i=6004 */

static UA_StatusCode function_namespace_euromap77_generated_109_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
attr.displayName = UA_LOCALIZEDTEXT("", "DeviceManual");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Address (pathname in the file system or a URL | Web address) of user manual for the device");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6004),
UA_NODEID_NUMERIC(ns[3], 5001),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[1], "DeviceManual"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6004), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_109_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6004)
);
}

/* DeviceRevision - ns=3;i=6005 */

static UA_StatusCode function_namespace_euromap77_generated_110_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
attr.displayName = UA_LOCALIZEDTEXT("", "DeviceRevision");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Overall revision level of the device");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6005),
UA_NODEID_NUMERIC(ns[3], 5001),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[1], "DeviceRevision"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6005), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_110_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6005)
);
}

/* SupportedLogbookEvents - ns=3;i=6002 */

static UA_StatusCode function_namespace_euromap77_generated_111_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 0;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[2], 3009);
attr.displayName = UA_LOCALIZEDTEXT("", "SupportedLogbookEvents");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Information which LogbookEvents are supported by the machine");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6002),
UA_NODEID_NUMERIC(ns[3], 5001),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "SupportedLogbookEvents"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6002), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_111_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6002)
);
}

/* ControllerName - ns=3;i=6001 */

static UA_StatusCode function_namespace_euromap77_generated_112_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6001_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6001_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6001_variant_DataContents);
*variablenode_ns_3_i_6001_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6001_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "ControllerName");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Name of the machine controller");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6001),
UA_NODEID_NUMERIC(ns[3], 5001),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "ControllerName"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6001_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6001), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_112_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6001)
);
}

/* EuromapSizeIndication - ns=3;i=6204 */

static UA_StatusCode function_namespace_euromap77_generated_113_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6204_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6204_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6204_variant_DataContents);
*variablenode_ns_3_i_6204_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6204_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "EuromapSizeIndication");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Size indication of the machine in accordance with a EUROMAP recommendation");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6204),
UA_NODEID_NUMERIC(ns[3], 5001),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "EuromapSizeIndication"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6204_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6204), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_113_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6204)
);
}

/* ProductionDatasetManagement - ns=3;i=5003 */

static UA_StatusCode function_namespace_euromap77_generated_114_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "ProductionDatasetManagement");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Management of production datasets");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[3], 5003),
UA_NODEID_NUMERIC(ns[3], 1007),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "ProductionDatasetManagement"),
UA_NODEID_NUMERIC(ns[2], 1008),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5003), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_114_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 5003)
);
}

/* ProductionDatasetInPreparationStatus - ns=3;i=5014 */

static UA_StatusCode function_namespace_euromap77_generated_115_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "ProductionDatasetInPreparationStatus");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Status of the production dataset in the preparation layer");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[3], 5014),
UA_NODEID_NUMERIC(ns[3], 5003),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "ProductionDatasetInPreparationStatus"),
UA_NODEID_NUMERIC(ns[2], 1039),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5014), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_115_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 5014)
);
}

/* Information - ns=3;i=6126 */

static UA_StatusCode function_namespace_euromap77_generated_116_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[2], 3006);

UA_STACKARRAY(UA_ProductionDatasetInformationType, variablenode_ns_3_i_6126_ProductionDatasetInformationType_0, 1);
UA_init(variablenode_ns_3_i_6126_ProductionDatasetInformationType_0, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETINFORMATIONTYPE]);
variablenode_ns_3_i_6126_ProductionDatasetInformationType_0->name = UA_STRING("");
variablenode_ns_3_i_6126_ProductionDatasetInformationType_0->description = UA_STRING("");
variablenode_ns_3_i_6126_ProductionDatasetInformationType_0->mESId = UA_STRING("");
variablenode_ns_3_i_6126_ProductionDatasetInformationType_0->creationTimestamp = ( (UA_DateTime)(-2208988800000 * UA_DATETIME_MSEC) + UA_DATETIME_UNIX_EPOCH);
variablenode_ns_3_i_6126_ProductionDatasetInformationType_0->lastModificationTimestamp = ( (UA_DateTime)(-2208988800000 * UA_DATETIME_MSEC) + UA_DATETIME_UNIX_EPOCH);
variablenode_ns_3_i_6126_ProductionDatasetInformationType_0->lastSaveTimestamp = ( (UA_DateTime)(-2208988800000 * UA_DATETIME_MSEC) + UA_DATETIME_UNIX_EPOCH);
variablenode_ns_3_i_6126_ProductionDatasetInformationType_0->userName = UA_STRING("");
variablenode_ns_3_i_6126_ProductionDatasetInformationType_0->manufacturer = UA_STRING("");
variablenode_ns_3_i_6126_ProductionDatasetInformationType_0->serialNumber = UA_STRING("");
variablenode_ns_3_i_6126_ProductionDatasetInformationType_0->model = UA_STRING("");
variablenode_ns_3_i_6126_ProductionDatasetInformationType_0->controllerType = UA_STRING("");
variablenode_ns_3_i_6126_ProductionDatasetInformationType_0->userMachineName = UA_STRING("");
variablenode_ns_3_i_6126_ProductionDatasetInformationType_0->locationName = UA_STRING("");
UA_STACKARRAY(UA_String, variablenode_ns_3_i_6126_ProductionDatasetInformationType_0_productName, 1);
UA_init(variablenode_ns_3_i_6126_ProductionDatasetInformationType_0_productName, &UA_TYPES[UA_TYPES_STRING]);
variablenode_ns_3_i_6126_ProductionDatasetInformationType_0_productName[0] = UA_STRING("");
variablenode_ns_3_i_6126_ProductionDatasetInformationType_0->productNameSize = 1;
variablenode_ns_3_i_6126_ProductionDatasetInformationType_0->productName = variablenode_ns_3_i_6126_ProductionDatasetInformationType_0_productName;
variablenode_ns_3_i_6126_ProductionDatasetInformationType_0->mouldId = UA_STRING("");
variablenode_ns_3_i_6126_ProductionDatasetInformationType_0->numCavities = (UA_UInt32) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6126_ProductionDatasetInformationType_0, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETINFORMATIONTYPE]);
attr.displayName = UA_LOCALIZEDTEXT("", "Information");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Set of information on the production dataset");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6126),
UA_NODEID_NUMERIC(ns[3], 5014),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "Information"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6126), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_116_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6126)
);
}

/* SendProductionDatasetInformation - ns=3;i=7018 */

static UA_StatusCode function_namespace_euromap77_generated_117_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "SendProductionDatasetInformation");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "This Method allows sending of the description of a production dataset during the file transfer from the client to the server with ProductionDatasetTransfer");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[3], 7018),
UA_NODEID_NUMERIC(ns[3], 5003),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "SendProductionDatasetInformation"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 7018), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_namespace_euromap77_generated_117_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 7018)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* InputArguments - ns=3;i=6140 */

static UA_StatusCode function_namespace_euromap77_generated_118_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 2;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);
UA_Argument variablenode_ns_3_i_6140_variant_DataContents[2];

UA_init(&variablenode_ns_3_i_6140_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6140_variant_DataContents[0].name = UA_STRING("fileHandle");
variablenode_ns_3_i_6140_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[0], 7);
variablenode_ns_3_i_6140_variant_DataContents[0].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_3_i_6140_variant_DataContents[1], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6140_variant_DataContents[1].name = UA_STRING("Information");
variablenode_ns_3_i_6140_variant_DataContents[1].dataType = UA_NODEID_NUMERIC(ns[2], 3006);
variablenode_ns_3_i_6140_variant_DataContents[1].valueRank = (UA_Int32) -1;
UA_Variant_setArray(&attr.value, &variablenode_ns_3_i_6140_variant_DataContents, (UA_Int32) 2, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "InputArguments");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6140),
UA_NODEID_NUMERIC(ns[3], 7018),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "InputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);


retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6140), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_118_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6140)
);
}

/* GetProductionDatasetInformation - ns=3;i=7004 */

static UA_StatusCode function_namespace_euromap77_generated_119_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "GetProductionDatasetInformation");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "This Method allows reading the description of a production dataset during the file transfer from the server to the client with ProductionDatasetTransfer");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[3], 7004),
UA_NODEID_NUMERIC(ns[3], 5003),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "GetProductionDatasetInformation"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 7004), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_namespace_euromap77_generated_119_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 7004)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* InputArguments - ns=3;i=6124 */

static UA_StatusCode function_namespace_euromap77_generated_120_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 1;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);
UA_Argument variablenode_ns_3_i_6124_variant_DataContents[1];

UA_init(&variablenode_ns_3_i_6124_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6124_variant_DataContents[0].name = UA_STRING("fileHandle");
variablenode_ns_3_i_6124_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[0], 7);
variablenode_ns_3_i_6124_variant_DataContents[0].valueRank = (UA_Int32) -1;
UA_Variant_setArray(&attr.value, &variablenode_ns_3_i_6124_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "InputArguments");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6124),
UA_NODEID_NUMERIC(ns[3], 7004),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "InputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6124), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_120_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6124)
);
}

/* OutputArguments - ns=3;i=6125 */

static UA_StatusCode function_namespace_euromap77_generated_121_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 1;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);
UA_Argument variablenode_ns_3_i_6125_variant_DataContents[1];

UA_init(&variablenode_ns_3_i_6125_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6125_variant_DataContents[0].name = UA_STRING("Information");
variablenode_ns_3_i_6125_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[2], 3006);
variablenode_ns_3_i_6125_variant_DataContents[0].valueRank = (UA_Int32) -1;
UA_Variant_setArray(&attr.value, &variablenode_ns_3_i_6125_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "OutputArguments");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6125),
UA_NODEID_NUMERIC(ns[3], 7004),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "OutputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6125), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_121_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6125)
);
}

/* ActiveProductionDatasetStatus - ns=3;i=5007 */

static UA_StatusCode function_namespace_euromap77_generated_122_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "ActiveProductionDatasetStatus");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Status of the active production dataset");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[3], 5007),
UA_NODEID_NUMERIC(ns[3], 5003),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "ActiveProductionDatasetStatus"),
UA_NODEID_NUMERIC(ns[2], 1039),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5007), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_122_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 5007)
);
}

/* Information - ns=3;i=6020 */

static UA_StatusCode function_namespace_euromap77_generated_123_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[2], 3006);

UA_STACKARRAY(UA_ProductionDatasetInformationType, variablenode_ns_3_i_6020_ProductionDatasetInformationType_0, 1);
UA_init(variablenode_ns_3_i_6020_ProductionDatasetInformationType_0, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETINFORMATIONTYPE]);
variablenode_ns_3_i_6020_ProductionDatasetInformationType_0->name = UA_STRING("");
variablenode_ns_3_i_6020_ProductionDatasetInformationType_0->description = UA_STRING("");
variablenode_ns_3_i_6020_ProductionDatasetInformationType_0->mESId = UA_STRING("");
variablenode_ns_3_i_6020_ProductionDatasetInformationType_0->creationTimestamp = ( (UA_DateTime)(-2208988800000 * UA_DATETIME_MSEC) + UA_DATETIME_UNIX_EPOCH);
variablenode_ns_3_i_6020_ProductionDatasetInformationType_0->lastModificationTimestamp = ( (UA_DateTime)(-2208988800000 * UA_DATETIME_MSEC) + UA_DATETIME_UNIX_EPOCH);
variablenode_ns_3_i_6020_ProductionDatasetInformationType_0->lastSaveTimestamp = ( (UA_DateTime)(-2208988800000 * UA_DATETIME_MSEC) + UA_DATETIME_UNIX_EPOCH);
variablenode_ns_3_i_6020_ProductionDatasetInformationType_0->userName = UA_STRING("");
variablenode_ns_3_i_6020_ProductionDatasetInformationType_0->manufacturer = UA_STRING("");
variablenode_ns_3_i_6020_ProductionDatasetInformationType_0->serialNumber = UA_STRING("");
variablenode_ns_3_i_6020_ProductionDatasetInformationType_0->model = UA_STRING("");
variablenode_ns_3_i_6020_ProductionDatasetInformationType_0->controllerType = UA_STRING("");
variablenode_ns_3_i_6020_ProductionDatasetInformationType_0->userMachineName = UA_STRING("");
variablenode_ns_3_i_6020_ProductionDatasetInformationType_0->locationName = UA_STRING("");
UA_STACKARRAY(UA_String, variablenode_ns_3_i_6020_ProductionDatasetInformationType_0_productName, 1);
UA_init(variablenode_ns_3_i_6020_ProductionDatasetInformationType_0_productName, &UA_TYPES[UA_TYPES_STRING]);
variablenode_ns_3_i_6020_ProductionDatasetInformationType_0_productName[0] = UA_STRING("");
variablenode_ns_3_i_6020_ProductionDatasetInformationType_0->productNameSize = 1;
variablenode_ns_3_i_6020_ProductionDatasetInformationType_0->productName = variablenode_ns_3_i_6020_ProductionDatasetInformationType_0_productName;
variablenode_ns_3_i_6020_ProductionDatasetInformationType_0->mouldId = UA_STRING("");
variablenode_ns_3_i_6020_ProductionDatasetInformationType_0->numCavities = (UA_UInt32) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6020_ProductionDatasetInformationType_0, &UA_TYPES_EUROMAP83[UA_TYPES_EUROMAP83_PRODUCTIONDATASETINFORMATIONTYPE]);
attr.displayName = UA_LOCALIZEDTEXT("", "Information");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Set of information on the production dataset");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6020),
UA_NODEID_NUMERIC(ns[3], 5007),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "Information"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6020), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_123_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6020)
);
}

/* ProductionDatasetTransfer - ns=3;i=5008 */

static UA_StatusCode function_namespace_euromap77_generated_124_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.eventNotifier = true;
attr.displayName = UA_LOCALIZEDTEXT("", "ProductionDatasetTransfer");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Transfer of production datasets between server and client");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[3], 5008),
UA_NODEID_NUMERIC(ns[3], 5003),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "ProductionDatasetTransfer"),
UA_NODEID_NUMERIC(ns[0], 15744),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5008), UA_NODEID_NUMERIC(ns[0], 41), UA_EXPANDEDNODEID_NUMERIC(ns[2], 1040), true);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5008), UA_NODEID_NUMERIC(ns[0], 41), UA_EXPANDEDNODEID_NUMERIC(ns[2], 1007), true);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5008), UA_NODEID_NUMERIC(ns[0], 41), UA_EXPANDEDNODEID_NUMERIC(ns[2], 1006), true);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5008), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_124_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 5008)
);
}

/* CloseAndCommit - ns=3;i=7001 */

static UA_StatusCode function_namespace_euromap77_generated_125_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "CloseAndCommit");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[3], 7001),
UA_NODEID_NUMERIC(ns[3], 5008),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "CloseAndCommit"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 7001), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_namespace_euromap77_generated_125_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 7001)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* OutputArguments - ns=3;i=6028 */

static UA_StatusCode function_namespace_euromap77_generated_126_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 1;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);
UA_Argument variablenode_ns_3_i_6028_variant_DataContents[1];

UA_init(&variablenode_ns_3_i_6028_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6028_variant_DataContents[0].name = UA_STRING("CompletionStateMachine");
variablenode_ns_3_i_6028_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[0], 17);
variablenode_ns_3_i_6028_variant_DataContents[0].valueRank = (UA_Int32) -1;
UA_Variant_setArray(&attr.value, &variablenode_ns_3_i_6028_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "OutputArguments");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6028),
UA_NODEID_NUMERIC(ns[3], 7001),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "OutputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6028), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_126_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6028)
);
}

/* InputArguments - ns=3;i=6027 */

static UA_StatusCode function_namespace_euromap77_generated_127_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 1;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);
UA_Argument variablenode_ns_3_i_6027_variant_DataContents[1];

UA_init(&variablenode_ns_3_i_6027_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6027_variant_DataContents[0].name = UA_STRING("FileHandle");
variablenode_ns_3_i_6027_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[0], 7);
variablenode_ns_3_i_6027_variant_DataContents[0].valueRank = (UA_Int32) -1;
UA_Variant_setArray(&attr.value, &variablenode_ns_3_i_6027_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "InputArguments");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6027),
UA_NODEID_NUMERIC(ns[3], 7001),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "InputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6027), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_127_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6027)
);
}

/* GenerateFileForWrite - ns=3;i=7003 */

static UA_StatusCode function_namespace_euromap77_generated_128_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "GenerateFileForWrite");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[3], 7003),
UA_NODEID_NUMERIC(ns[3], 5008),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "GenerateFileForWrite"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 7003), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_namespace_euromap77_generated_128_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 7003)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* InputArguments - ns=3;i=6116 */

static UA_StatusCode function_namespace_euromap77_generated_129_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 1;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);
UA_Argument variablenode_ns_3_i_6116_variant_DataContents[1];

UA_init(&variablenode_ns_3_i_6116_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6116_variant_DataContents[0].name = UA_STRING("GenerateOptions");
variablenode_ns_3_i_6116_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[2], 3004);
variablenode_ns_3_i_6116_variant_DataContents[0].valueRank = (UA_Int32) -1;
UA_Variant_setArray(&attr.value, &variablenode_ns_3_i_6116_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "InputArguments");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6116),
UA_NODEID_NUMERIC(ns[3], 7003),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "InputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6116), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_129_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6116)
);
}

/* OutputArguments - ns=3;i=6123 */

static UA_StatusCode function_namespace_euromap77_generated_130_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 2;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);
UA_Argument variablenode_ns_3_i_6123_variant_DataContents[2];

UA_init(&variablenode_ns_3_i_6123_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6123_variant_DataContents[0].name = UA_STRING("FileNodeId");
variablenode_ns_3_i_6123_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[0], 17);
variablenode_ns_3_i_6123_variant_DataContents[0].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_3_i_6123_variant_DataContents[1], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6123_variant_DataContents[1].name = UA_STRING("FileHandle");
variablenode_ns_3_i_6123_variant_DataContents[1].dataType = UA_NODEID_NUMERIC(ns[0], 7);
variablenode_ns_3_i_6123_variant_DataContents[1].valueRank = (UA_Int32) -1;
UA_Variant_setArray(&attr.value, &variablenode_ns_3_i_6123_variant_DataContents, (UA_Int32) 2, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "OutputArguments");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6123),
UA_NODEID_NUMERIC(ns[3], 7003),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "OutputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);


retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6123), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_130_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6123)
);
}

/* GenerateFileForRead - ns=3;i=7002 */

static UA_StatusCode function_namespace_euromap77_generated_131_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "GenerateFileForRead");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[3], 7002),
UA_NODEID_NUMERIC(ns[3], 5008),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[0], "GenerateFileForRead"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 7002), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_namespace_euromap77_generated_131_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 7002)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* InputArguments - ns=3;i=6041 */

static UA_StatusCode function_namespace_euromap77_generated_132_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 1;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);
UA_Argument variablenode_ns_3_i_6041_variant_DataContents[1];

UA_init(&variablenode_ns_3_i_6041_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6041_variant_DataContents[0].name = UA_STRING("GenerateOptions");
variablenode_ns_3_i_6041_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[2], 3007);
variablenode_ns_3_i_6041_variant_DataContents[0].valueRank = (UA_Int32) -1;
UA_Variant_setArray(&attr.value, &variablenode_ns_3_i_6041_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "InputArguments");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6041),
UA_NODEID_NUMERIC(ns[3], 7002),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "InputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6041), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_132_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6041)
);
}

/* OutputArguments - ns=3;i=6042 */

static UA_StatusCode function_namespace_euromap77_generated_133_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 3;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);
UA_Argument variablenode_ns_3_i_6042_variant_DataContents[3];

UA_init(&variablenode_ns_3_i_6042_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6042_variant_DataContents[0].name = UA_STRING("FileNodeId");
variablenode_ns_3_i_6042_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[0], 17);
variablenode_ns_3_i_6042_variant_DataContents[0].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_3_i_6042_variant_DataContents[1], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6042_variant_DataContents[1].name = UA_STRING("FileHandle");
variablenode_ns_3_i_6042_variant_DataContents[1].dataType = UA_NODEID_NUMERIC(ns[0], 7);
variablenode_ns_3_i_6042_variant_DataContents[1].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_3_i_6042_variant_DataContents[2], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6042_variant_DataContents[2].name = UA_STRING("CompletionStateMachine");
variablenode_ns_3_i_6042_variant_DataContents[2].dataType = UA_NODEID_NUMERIC(ns[0], 17);
variablenode_ns_3_i_6042_variant_DataContents[2].valueRank = (UA_Int32) -1;
UA_Variant_setArray(&attr.value, &variablenode_ns_3_i_6042_variant_DataContents, (UA_Int32) 3, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "OutputArguments");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6042),
UA_NODEID_NUMERIC(ns[3], 7002),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "OutputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);



retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6042), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_133_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6042)
);
}

/* ClientProcessingTimeout - ns=3;i=6026 */

static UA_StatusCode function_namespace_euromap77_generated_134_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 290);
attr.displayName = UA_LOCALIZEDTEXT("", "ClientProcessingTimeout");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6026),
UA_NODEID_NUMERIC(ns[3], 5008),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "ClientProcessingTimeout"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6026), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_134_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6026)
);
}

/* ProductionDatasetLists - ns=3;i=5020 */

static UA_StatusCode function_namespace_euromap77_generated_135_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.eventNotifier = true;
attr.displayName = UA_LOCALIZEDTEXT("", "ProductionDatasetLists");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Functions for exchanging information on the available production datasets on client and server");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[3], 5020),
UA_NODEID_NUMERIC(ns[3], 5003),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "ProductionDatasetLists"),
UA_NODEID_NUMERIC(ns[2], 1003),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5020), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5020), UA_NODEID_NUMERIC(ns[0], 41), UA_EXPANDEDNODEID_NUMERIC(ns[2], 1040), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_135_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 5020)
);
}

/* GetProductionDatasetList - ns=3;i=7012 */

static UA_StatusCode function_namespace_euromap77_generated_136_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "GetProductionDatasetList");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[3], 7012),
UA_NODEID_NUMERIC(ns[3], 5020),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "GetProductionDatasetList"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 7012), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_namespace_euromap77_generated_136_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 7012)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* OutputArguments - ns=3;i=6138 */

static UA_StatusCode function_namespace_euromap77_generated_137_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 1;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);
UA_Argument variablenode_ns_3_i_6138_variant_DataContents[1];

UA_init(&variablenode_ns_3_i_6138_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6138_variant_DataContents[0].name = UA_STRING("ProductionDatasetList");
variablenode_ns_3_i_6138_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[2], 3006);
variablenode_ns_3_i_6138_variant_DataContents[0].valueRank = (UA_Int32) 1;
UA_Variant_setArray(&attr.value, &variablenode_ns_3_i_6138_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "OutputArguments");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6138),
UA_NODEID_NUMERIC(ns[3], 7012),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "OutputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6138), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_137_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6138)
);
}

/* InputArguments - ns=3;i=6137 */

static UA_StatusCode function_namespace_euromap77_generated_138_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 2;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);
UA_Argument variablenode_ns_3_i_6137_variant_DataContents[2];

UA_init(&variablenode_ns_3_i_6137_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6137_variant_DataContents[0].name = UA_STRING("NameFilter");
variablenode_ns_3_i_6137_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[0], 12);
variablenode_ns_3_i_6137_variant_DataContents[0].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_3_i_6137_variant_DataContents[1], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6137_variant_DataContents[1].name = UA_STRING("MouldId");
variablenode_ns_3_i_6137_variant_DataContents[1].dataType = UA_NODEID_NUMERIC(ns[0], 12);
variablenode_ns_3_i_6137_variant_DataContents[1].valueRank = (UA_Int32) -1;
UA_Variant_setArray(&attr.value, &variablenode_ns_3_i_6137_variant_DataContents, (UA_Int32) 2, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "InputArguments");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6137),
UA_NODEID_NUMERIC(ns[3], 7012),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "InputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);


retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6137), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_138_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6137)
);
}

/* SendProductionDatasetList - ns=3;i=7013 */

static UA_StatusCode function_namespace_euromap77_generated_139_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "SendProductionDatasetList");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[3], 7013),
UA_NODEID_NUMERIC(ns[3], 5020),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "SendProductionDatasetList"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 7013), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_namespace_euromap77_generated_139_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 7013)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* InputArguments - ns=3;i=6139 */

static UA_StatusCode function_namespace_euromap77_generated_140_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 1;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[0], 296);
UA_Argument variablenode_ns_3_i_6139_variant_DataContents[1];

UA_init(&variablenode_ns_3_i_6139_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_3_i_6139_variant_DataContents[0].name = UA_STRING("ProductionDatasetList");
variablenode_ns_3_i_6139_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[2], 3006);
variablenode_ns_3_i_6139_variant_DataContents[0].valueRank = (UA_Int32) 1;
UA_Variant_setArray(&attr.value, &variablenode_ns_3_i_6139_variant_DataContents, (UA_Int32) 1, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "InputArguments");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6139),
UA_NODEID_NUMERIC(ns[3], 7013),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "InputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6139), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_140_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6139)
);
}

/* PowerUnits - ns=3;i=5054 */

static UA_StatusCode function_namespace_euromap77_generated_141_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "PowerUnits");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Container for the power units");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[3], 5054),
UA_NODEID_NUMERIC(ns[3], 1007),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "PowerUnits"),
UA_NODEID_NUMERIC(ns[2], 1049),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5054), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_141_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 5054)
);
}

/* NodeVersion - ns=3;i=6086 */

static UA_StatusCode function_namespace_euromap77_generated_142_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6086_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6086_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6086_variant_DataContents);
*variablenode_ns_3_i_6086_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6086_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "NodeVersion");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6086),
UA_NODEID_NUMERIC(ns[3], 5054),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "NodeVersion"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6086_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6086), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_142_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6086)
);
}

/* Euromap77 - ns=3;i=6050 */
static const UA_Byte variablenode_ns_3_i_6050_variant_DataContents_byteArray[3396] = {60, 120, 115, 58, 115, 99, 104, 101, 109, 97, 32, 101, 108, 101, 109, 101, 110, 116, 70, 111, 114, 109, 68, 101, 102, 97, 117, 108, 116, 61, 34, 113, 117, 97, 108, 105, 102, 105, 101, 100, 34, 32, 116, 97, 114, 103, 101, 116, 78, 97, 109, 101, 115, 112, 97, 99, 101, 61, 34, 104, 116, 116, 112, 58, 47, 47, 119, 119, 119, 46, 101, 117, 114, 111, 109, 97, 112, 46, 111, 114, 103, 47, 101, 117, 114, 111, 109, 97, 112, 55, 55, 47, 84, 121, 112, 101, 115, 46, 120, 115, 100, 34, 32, 120, 109, 108, 110, 115, 58, 116, 110, 115, 61, 34, 104, 116, 116, 112, 58, 47, 47, 119, 119, 119, 46, 101, 117, 114, 111, 109, 97, 112, 46, 111, 114, 103, 47, 101, 117, 114, 111, 109, 97, 112, 55, 55, 47, 84, 121, 112, 101, 115, 46, 120, 115, 100, 34, 32, 120, 109, 108, 110, 115, 58, 117, 97, 61, 34, 104, 116, 116, 112, 58, 47, 47, 111, 112, 99, 102, 111, 117, 110, 100, 97, 116, 105, 111, 110, 46, 111, 114, 103, 47, 85, 65, 47, 50, 48, 48, 56, 47, 48, 50, 47, 84, 121, 112, 101, 115, 46, 120, 115, 100, 34, 32, 120, 109, 108, 110, 115, 58, 120, 115, 61, 34, 104, 116, 116, 112, 58, 47, 47, 119, 119, 119, 46, 119, 51, 46, 111, 114, 103, 47, 50, 48, 48, 49, 47, 88, 77, 76, 83, 99, 104, 101, 109, 97, 34, 62, 10, 32, 60, 120, 115, 58, 105, 109, 112, 111, 114, 116, 32, 110, 97, 109, 101, 115, 112, 97, 99, 101, 61, 34, 104, 116, 116, 112, 58, 47, 47, 111, 112, 99, 102, 111, 117, 110, 100, 97, 116, 105, 111, 110, 46, 111, 114, 103, 47, 85, 65, 47, 50, 48, 48, 56, 47, 48, 50, 47, 84, 121, 112, 101, 115, 46, 120, 115, 100, 34, 47, 62, 10, 32, 60, 120, 115, 58, 115, 105, 109, 112, 108, 101, 84, 121, 112, 101, 32, 110, 97, 109, 101, 61, 34, 73, 77, 77, 77, 101, 115, 115, 97, 103, 101, 67, 108, 97, 115, 115, 105, 102, 105, 99, 97, 116, 105, 111, 110, 69, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 34, 62, 10, 32, 32, 60, 120, 115, 58, 97, 110, 110, 111, 116, 97, 116, 105, 111, 110, 62, 10, 32, 32, 32, 60, 120, 115, 58, 100, 111, 99, 117, 109, 101, 110, 116, 97, 116, 105, 111, 110, 62, 84, 104, 105, 115, 32, 69, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 115, 112, 101, 99, 105, 102, 105, 101, 115, 32, 116, 104, 101, 32, 118, 97, 108, 117, 101, 115, 32, 116, 111, 32, 98, 101, 32, 117, 115, 101, 100, 32, 105, 110, 32, 116, 104, 101, 32, 67, 108, 97, 115, 115, 105, 102, 105, 99, 97, 116, 105, 111, 110, 32, 112, 114, 111, 112, 101, 114, 116, 121, 32, 105, 110, 32, 116, 104, 101, 32, 77, 101, 115, 115, 97, 103, 101, 67, 111, 110, 100, 105, 116, 105, 111, 110, 84, 121, 112, 101, 32, 97, 110, 100, 32, 114, 101, 108, 97, 116, 101, 100, 32, 108, 111, 103, 98, 111, 111, 107, 32, 101, 118, 101, 110, 116, 115, 32, 111, 102, 32, 69, 85, 82, 79, 77, 65, 80, 32, 56, 51, 60, 47, 120, 115, 58, 100, 111, 99, 117, 109, 101, 110, 116, 97, 116, 105, 111, 110, 62, 10, 32, 32, 60, 47, 120, 115, 58, 97, 110, 110, 111, 116, 97, 116, 105, 111, 110, 62, 10, 32, 32, 60, 120, 115, 58, 114, 101, 115, 116, 114, 105, 99, 116, 105, 111, 110, 32, 98, 97, 115, 101, 61, 34, 120, 115, 58, 115, 116, 114, 105, 110, 103, 34, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 79, 84, 72, 69, 82, 95, 48, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 73, 77, 77, 95, 73, 78, 74, 69, 67, 84, 73, 79, 78, 95, 85, 78, 73, 84, 95, 49, 48, 48, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 73, 77, 77, 95, 67, 76, 65, 77, 80, 73, 78, 71, 95, 85, 78, 73, 84, 95, 49, 48, 49, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 73, 77, 77, 95, 72, 65, 82, 68, 87, 65, 82, 69, 95, 49, 48, 50, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 73, 77, 77, 95, 67, 79, 77, 80, 82, 69, 83, 83, 69, 68, 95, 65, 73, 82, 95, 67, 79, 78, 84, 82, 79, 76, 95, 49, 48, 51, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 73, 77, 77, 95, 77, 65, 67, 72, 73, 78, 69, 95, 77, 79, 78, 73, 84, 79, 82, 73, 78, 71, 95, 49, 48, 52, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 73, 77, 77, 95, 77, 79, 85, 76, 68, 95, 49, 48, 53, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 73, 77, 77, 95, 69, 74, 69, 67, 84, 79, 82, 95, 49, 48, 54, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 73, 77, 77, 95, 67, 79, 82, 69, 95, 80, 85, 76, 76, 95, 49, 48, 55, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 73, 77, 77, 95, 84, 65, 66, 76, 69, 95, 49, 48, 56, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 73, 77, 77, 95, 73, 78, 74, 69, 67, 84, 73, 79, 78, 95, 80, 82, 79, 71, 82, 65, 77, 95, 49, 48, 57, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 73, 77, 77, 95, 72, 89, 68, 82, 65, 85, 76, 73, 67, 95, 84, 69, 77, 80, 69, 82, 65, 84, 85, 82, 69, 95, 67, 79, 78, 84, 82, 79, 76, 95, 49, 49, 48, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 73, 77, 77, 95, 67, 89, 76, 73, 78, 68, 69, 82, 95, 84, 69, 77, 80, 69, 82, 65, 84, 85, 82, 69, 95, 67, 79, 78, 84, 82, 79, 76, 95, 49, 49, 49, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 73, 77, 77, 95, 77, 79, 85, 76, 68, 95, 84, 69, 77, 80, 69, 82, 65, 84, 85, 82, 69, 95, 67, 79, 78, 84, 82, 79, 76, 95, 49, 49, 50, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 73, 77, 77, 95, 72, 79, 84, 95, 82, 85, 78, 78, 69, 82, 95, 49, 49, 51, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 73, 77, 77, 95, 73, 78, 84, 69, 82, 70, 65, 67, 69, 83, 95, 49, 49, 52, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 73, 77, 77, 95, 77, 69, 65, 83, 85, 82, 73, 78, 71, 95, 83, 89, 83, 84, 69, 77, 95, 49, 49, 53, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 73, 77, 77, 95, 82, 79, 66, 79, 84, 73, 67, 95, 83, 89, 83, 84, 69, 77, 95, 73, 78, 84, 69, 82, 70, 65, 67, 69, 95, 49, 49, 54, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 73, 77, 77, 95, 83, 80, 69, 67, 73, 65, 76, 95, 80, 85, 82, 80, 79, 83, 69, 95, 83, 73, 71, 78, 65, 76, 83, 95, 49, 49, 55, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 73, 77, 77, 95, 82, 69, 65, 76, 95, 84, 73, 77, 69, 95, 69, 84, 72, 69, 82, 78, 69, 84, 95, 83, 89, 83, 84, 69, 77, 95, 49, 49, 56, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 73, 77, 77, 95, 77, 65, 67, 72, 73, 78, 69, 95, 67, 79, 78, 84, 82, 79, 76, 76, 69, 82, 95, 49, 49, 57, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 73, 77, 77, 95, 83, 79, 70, 84, 87, 65, 82, 69, 95, 77, 79, 78, 73, 84, 79, 82, 73, 78, 71, 95, 49, 50, 48, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 80, 69, 82, 73, 80, 72, 69, 82, 65, 76, 95, 69, 88, 84, 69, 82, 78, 65, 76, 95, 68, 69, 86, 73, 67, 69, 95, 73, 78, 84, 69, 82, 70, 65, 67, 69, 95, 50, 48, 48, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 80, 69, 82, 73, 80, 72, 69, 82, 65, 76, 95, 84, 69, 77, 80, 69, 82, 65, 84, 85, 82, 69, 95, 67, 79, 78, 84, 82, 79, 76, 95, 85, 78, 73, 84, 95, 50, 48, 49, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 80, 69, 82, 73, 80, 72, 69, 82, 65, 76, 95, 82, 79, 66, 79, 84, 73, 67, 83, 95, 83, 89, 83, 84, 69, 77, 95, 50, 48, 50, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 80, 69, 82, 73, 80, 72, 69, 82, 65, 76, 95, 76, 83, 82, 95, 50, 48, 51, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 80, 69, 82, 73, 80, 72, 69, 82, 65, 76, 95, 83, 84, 82, 73, 80, 80, 69, 82, 95, 85, 78, 73, 84, 95, 50, 48, 52, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 80, 69, 82, 73, 80, 72, 69, 82, 65, 76, 95, 68, 82, 89, 69, 82, 95, 50, 48, 53, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 80, 69, 82, 73, 80, 72, 69, 82, 65, 76, 95, 67, 79, 78, 86, 69, 89, 79, 82, 95, 66, 69, 76, 84, 95, 50, 48, 54, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 80, 69, 82, 73, 80, 72, 69, 82, 65, 76, 95, 83, 79, 82, 84, 69, 82, 95, 85, 78, 73, 84, 95, 50, 48, 55, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 80, 69, 82, 73, 80, 72, 69, 82, 65, 76, 95, 67, 79, 76, 79, 85, 82, 73, 78, 71, 95, 85, 78, 73, 84, 95, 50, 48, 56, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 80, 69, 82, 73, 80, 72, 69, 82, 65, 76, 95, 70, 69, 69, 68, 73, 78, 71, 95, 50, 48, 57, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 80, 69, 82, 73, 80, 72, 69, 82, 65, 76, 95, 69, 88, 84, 69, 82, 78, 65, 76, 95, 65, 76, 65, 82, 77, 83, 95, 50, 49, 48, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 80, 69, 82, 73, 80, 72, 69, 82, 65, 76, 95, 86, 65, 67, 85, 85, 77, 95, 67, 79, 78, 84, 82, 79, 76, 95, 50, 49, 49, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 80, 69, 82, 73, 80, 72, 69, 82, 65, 76, 95, 80, 82, 73, 78, 84, 69, 82, 95, 73, 78, 84, 69, 82, 70, 65, 67, 69, 95, 50, 49, 50, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 79, 80, 69, 82, 65, 84, 73, 79, 78, 95, 81, 85, 65, 76, 73, 84, 89, 95, 77, 79, 78, 73, 84, 79, 82, 73, 78, 71, 95, 51, 48, 48, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 79, 80, 69, 82, 65, 84, 73, 79, 78, 95, 77, 65, 78, 85, 65, 76, 95, 79, 80, 69, 82, 65, 84, 73, 79, 78, 95, 51, 48, 49, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 79, 80, 69, 82, 65, 84, 73, 79, 78, 95, 69, 77, 69, 82, 71, 69, 78, 67, 89, 95, 83, 84, 79, 80, 95, 51, 48, 50, 34, 47, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 118, 97, 108, 117, 101, 61, 34, 79, 80, 69, 82, 65, 84, 73, 79, 78, 95, 74, 79, 66, 95, 83, 84, 65, 84, 85, 83, 95, 51, 48, 51, 34, 47, 62, 10, 32, 32, 60, 47, 120, 115, 58, 114, 101, 115, 116, 114, 105, 99, 116, 105, 111, 110, 62, 10, 32, 60, 47, 120, 115, 58, 115, 105, 109, 112, 108, 101, 84, 121, 112, 101, 62, 10, 32, 60, 120, 115, 58, 101, 108, 101, 109, 101, 110, 116, 32, 116, 121, 112, 101, 61, 34, 116, 110, 115, 58, 73, 77, 77, 77, 101, 115, 115, 97, 103, 101, 67, 108, 97, 115, 115, 105, 102, 105, 99, 97, 116, 105, 111, 110, 69, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 34, 32, 110, 97, 109, 101, 61, 34, 73, 77, 77, 77, 101, 115, 115, 97, 103, 101, 67, 108, 97, 115, 115, 105, 102, 105, 99, 97, 116, 105, 111, 110, 69, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 34, 47, 62, 10, 32, 60, 120, 115, 58, 99, 111, 109, 112, 108, 101, 120, 84, 121, 112, 101, 32, 110, 97, 109, 101, 61, 34, 76, 105, 115, 116, 79, 102, 73, 77, 77, 77, 101, 115, 115, 97, 103, 101, 67, 108, 97, 115, 115, 105, 102, 105, 99, 97, 116, 105, 111, 110, 69, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 34, 62, 10, 32, 32, 60, 120, 115, 58, 115, 101, 113, 117, 101, 110, 99, 101, 62, 10, 32, 32, 32, 60, 120, 115, 58, 101, 108, 101, 109, 101, 110, 116, 32, 109, 105, 110, 79, 99, 99, 117, 114, 115, 61, 34, 48, 34, 32, 109, 97, 120, 79, 99, 99, 117, 114, 115, 61, 34, 117, 110, 98, 111, 117, 110, 100, 101, 100, 34, 32, 116, 121, 112, 101, 61, 34, 116, 110, 115, 58, 73, 77, 77, 77, 101, 115, 115, 97, 103, 101, 67, 108, 97, 115, 115, 105, 102, 105, 99, 97, 116, 105, 111, 110, 69, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 34, 32, 110, 97, 109, 101, 61, 34, 73, 77, 77, 77, 101, 115, 115, 97, 103, 101, 67, 108, 97, 115, 115, 105, 102, 105, 99, 97, 116, 105, 111, 110, 69, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 34, 32, 110, 105, 108, 108, 97, 98, 108, 101, 61, 34, 116, 114, 117, 101, 34, 47, 62, 10, 32, 32, 60, 47, 120, 115, 58, 115, 101, 113, 117, 101, 110, 99, 101, 62, 10, 32, 60, 47, 120, 115, 58, 99, 111, 109, 112, 108, 101, 120, 84, 121, 112, 101, 62, 10, 32, 60, 120, 115, 58, 101, 108, 101, 109, 101, 110, 116, 32, 116, 121, 112, 101, 61, 34, 116, 110, 115, 58, 76, 105, 115, 116, 79, 102, 73, 77, 77, 77, 101, 115, 115, 97, 103, 101, 67, 108, 97, 115, 115, 105, 102, 105, 99, 97, 116, 105, 111, 110, 69, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 34, 32, 110, 97, 109, 101, 61, 34, 76, 105, 115, 116, 79, 102, 73, 77, 77, 77, 101, 115, 115, 97, 103, 101, 67, 108, 97, 115, 115, 105, 102, 105, 99, 97, 116, 105, 111, 110, 69, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 34, 32, 110, 105, 108, 108, 97, 98, 108, 101, 61, 34, 116, 114, 117, 101, 34, 47, 62, 10, 60, 47, 120, 115, 58, 115, 99, 104, 101, 109, 97, 62, 10};



static UA_StatusCode function_namespace_euromap77_generated_143_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 15);
UA_ByteString *variablenode_ns_3_i_6050_variant_DataContents =  UA_ByteString_new();
if (!variablenode_ns_3_i_6050_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_ByteString_init(variablenode_ns_3_i_6050_variant_DataContents);
variablenode_ns_3_i_6050_variant_DataContents->length = 3396;
variablenode_ns_3_i_6050_variant_DataContents->data = (UA_Byte *)(void*)(uintptr_t)variablenode_ns_3_i_6050_variant_DataContents_byteArray;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6050_variant_DataContents, &UA_TYPES[UA_TYPES_BYTESTRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "Euromap77");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Collects the data type descriptions of http://www.euromap.org/euromap77");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6050),
UA_NODEID_NUMERIC(ns[0], 92),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "Euromap77"),
UA_NODEID_NUMERIC(ns[0], 72),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
variablenode_ns_3_i_6050_variant_DataContents->data = NULL;
variablenode_ns_3_i_6050_variant_DataContents->length = 0;
UA_ByteString_delete(variablenode_ns_3_i_6050_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_143_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6050)
);
}

/* NamespaceUri - ns=3;i=6051 */

static UA_StatusCode function_namespace_euromap77_generated_144_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6051_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6051_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6051_variant_DataContents);
*variablenode_ns_3_i_6051_variant_DataContents = UA_STRING_ALLOC("http://www.euromap.org/euromap77/Types.xsd");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6051_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "NamespaceUri");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "A URI that uniquely identifies the dictionary.");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6051),
UA_NODEID_NUMERIC(ns[3], 6050),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "NamespaceUri"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6051_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_144_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6051)
);
}

/* InjectionUnitsType - ns=3;i=1016 */

static UA_StatusCode function_namespace_euromap77_generated_145_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectTypeAttributes attr = UA_ObjectTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "InjectionUnitsType");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Container for objects of InjectionUnitType");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECTTYPE,
UA_NODEID_NUMERIC(ns[3], 1016),
UA_NODEID_NUMERIC(ns[0], 58),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[3], "InjectionUnitsType"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTTYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_145_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 1016)
);
}

/* NodeVersion - ns=3;i=6006 */

static UA_StatusCode function_namespace_euromap77_generated_146_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6006_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6006_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6006_variant_DataContents);
*variablenode_ns_3_i_6006_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6006_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "NodeVersion");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6006),
UA_NODEID_NUMERIC(ns[3], 1016),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "NodeVersion"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6006_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6006), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_146_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6006)
);
}

/* InjectionUnits - ns=3;i=5029 */

static UA_StatusCode function_namespace_euromap77_generated_147_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "InjectionUnits");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Container for the injection units");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[3], 5029),
UA_NODEID_NUMERIC(ns[3], 1007),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "InjectionUnits"),
UA_NODEID_NUMERIC(ns[3], 1016),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5029), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_147_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 5029)
);
}

/* NodeVersion - ns=3;i=6056 */

static UA_StatusCode function_namespace_euromap77_generated_148_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6056_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6056_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6056_variant_DataContents);
*variablenode_ns_3_i_6056_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6056_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "NodeVersion");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6056),
UA_NODEID_NUMERIC(ns[3], 5029),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "NodeVersion"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6056_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6056), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_148_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6056)
);
}

/* InjectionUnitType - ns=3;i=1028 */

static UA_StatusCode function_namespace_euromap77_generated_149_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectTypeAttributes attr = UA_ObjectTypeAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "InjectionUnitType");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Description and status of an injection unit");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECTTYPE,
UA_NODEID_NUMERIC(ns[3], 1028),
UA_NODEID_NUMERIC(ns[0], 58),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[3], "InjectionUnitType"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTTYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_149_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 1028)
);
}

/* TemperatureZones - ns=3;i=5017 */

static UA_StatusCode function_namespace_euromap77_generated_150_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "TemperatureZones");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "container for the barrel temperature zones of the injection unit");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[3], 5017),
UA_NODEID_NUMERIC(ns[3], 1028),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "TemperatureZones"),
UA_NODEID_NUMERIC(ns[2], 1055),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5017), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_150_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 5017)
);
}

/* NodeVersion - ns=3;i=6057 */

static UA_StatusCode function_namespace_euromap77_generated_151_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6057_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6057_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6057_variant_DataContents);
*variablenode_ns_3_i_6057_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6057_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "NodeVersion");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6057),
UA_NODEID_NUMERIC(ns[3], 5017),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "NodeVersion"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6057_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6057), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_151_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6057)
);
}

/* ScrewId - ns=3;i=6106 */

static UA_StatusCode function_namespace_euromap77_generated_152_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6106_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6106_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6106_variant_DataContents);
*variablenode_ns_3_i_6106_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6106_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "ScrewId");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Id of the screw installed in the injection unit");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6106),
UA_NODEID_NUMERIC(ns[3], 1028),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[3], "ScrewId"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6106_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6106), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_152_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6106)
);
}

/* Index - ns=3;i=6724 */

static UA_StatusCode function_namespace_euromap77_generated_153_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
UA_UInt32 *variablenode_ns_3_i_6724_variant_DataContents =  UA_UInt32_new();
if (!variablenode_ns_3_i_6724_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt32_init(variablenode_ns_3_i_6724_variant_DataContents);
*variablenode_ns_3_i_6724_variant_DataContents = (UA_UInt32) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6724_variant_DataContents, &UA_TYPES[UA_TYPES_UINT32]);
attr.displayName = UA_LOCALIZEDTEXT("", "Index");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Number of the injection unit");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6724),
UA_NODEID_NUMERIC(ns[3], 1028),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[3], "Index"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt32_delete(variablenode_ns_3_i_6724_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6724), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_153_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6724)
);
}

/* IsPresent - ns=3;i=6098 */

static UA_StatusCode function_namespace_euromap77_generated_154_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_3_i_6098_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_3_i_6098_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_3_i_6098_variant_DataContents);
*variablenode_ns_3_i_6098_variant_DataContents = (UA_Boolean) true;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6098_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "IsPresent");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Information if the injection unit is physically installed on the injection machines");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6098),
UA_NODEID_NUMERIC(ns[3], 1028),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[3], "IsPresent"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_3_i_6098_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6098), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_154_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6098)
);
}

/* InProduction - ns=3;i=6099 */

static UA_StatusCode function_namespace_euromap77_generated_155_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_3_i_6099_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_3_i_6099_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_3_i_6099_variant_DataContents);
*variablenode_ns_3_i_6099_variant_DataContents = (UA_Boolean) true;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6099_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "InProduction");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "information if the injection unit is used in the current running production");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6099),
UA_NODEID_NUMERIC(ns[3], 1028),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[3], "InProduction"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_3_i_6099_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6099), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_155_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6099)
);
}

/* InjectionUnit_<Nr> - ns=3;i=5027 */

static UA_StatusCode function_namespace_euromap77_generated_156_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "InjectionUnit_<Nr>");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[3], 5027),
UA_NODEID_NUMERIC(ns[3], 1016),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "InjectionUnit_<Nr>"),
UA_NODEID_NUMERIC(ns[3], 1028),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5027), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 11508), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_156_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 5027)
);
}

/* InProduction - ns=3;i=6178 */

static UA_StatusCode function_namespace_euromap77_generated_157_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_3_i_6178_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_3_i_6178_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_3_i_6178_variant_DataContents);
*variablenode_ns_3_i_6178_variant_DataContents = (UA_Boolean) true;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6178_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "InProduction");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "information if the injection unit is used in the current running production");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6178),
UA_NODEID_NUMERIC(ns[3], 5027),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[3], "InProduction"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_3_i_6178_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6178), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_157_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6178)
);
}

/* ScrewId - ns=3;i=6185 */

static UA_StatusCode function_namespace_euromap77_generated_158_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6185_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6185_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6185_variant_DataContents);
*variablenode_ns_3_i_6185_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6185_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "ScrewId");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Id of the screw installed in the injection unit");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6185),
UA_NODEID_NUMERIC(ns[3], 5027),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[3], "ScrewId"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6185_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6185), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_158_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6185)
);
}

/* Index - ns=3;i=6157 */

static UA_StatusCode function_namespace_euromap77_generated_159_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
UA_UInt32 *variablenode_ns_3_i_6157_variant_DataContents =  UA_UInt32_new();
if (!variablenode_ns_3_i_6157_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt32_init(variablenode_ns_3_i_6157_variant_DataContents);
*variablenode_ns_3_i_6157_variant_DataContents = (UA_UInt32) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6157_variant_DataContents, &UA_TYPES[UA_TYPES_UINT32]);
attr.displayName = UA_LOCALIZEDTEXT("", "Index");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Number of the injection unit");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6157),
UA_NODEID_NUMERIC(ns[3], 5027),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[3], "Index"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt32_delete(variablenode_ns_3_i_6157_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6157), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_159_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6157)
);
}

/* TemperatureZones - ns=3;i=5018 */

static UA_StatusCode function_namespace_euromap77_generated_160_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "TemperatureZones");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "container for the barrel temperature zones of the injection unit");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[3], 5018),
UA_NODEID_NUMERIC(ns[3], 5027),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "TemperatureZones"),
UA_NODEID_NUMERIC(ns[2], 1055),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 5018), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_160_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 5018)
);
}

/* NodeVersion - ns=3;i=6058 */

static UA_StatusCode function_namespace_euromap77_generated_161_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6058_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6058_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6058_variant_DataContents);
*variablenode_ns_3_i_6058_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6058_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "NodeVersion");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6058),
UA_NODEID_NUMERIC(ns[3], 5018),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "NodeVersion"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6058_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6058), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_161_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6058)
);
}

/* ScrewVolume - ns=3;i=6186 */

static UA_StatusCode function_namespace_euromap77_generated_162_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6186_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6186_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6186_variant_DataContents);
*variablenode_ns_3_i_6186_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6186_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "ScrewVolume");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "volume of the screw installed in the injection unit");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6186),
UA_NODEID_NUMERIC(ns[3], 5027),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "ScrewVolume"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6186_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6186), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_162_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6186)
);
}

/* EngineeringUnits - ns=3;i=6031 */

static UA_StatusCode function_namespace_euromap77_generated_163_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_3_i_6031_EUInformation_0, 1);
UA_init(variablenode_ns_3_i_6031_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_3_i_6031_EUInformation_0->namespaceUri = UA_STRING("");
variablenode_ns_3_i_6031_EUInformation_0->unitId = (UA_Int32) -1;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6031_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6031),
UA_NODEID_NUMERIC(ns[3], 6186),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6031), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_163_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6031)
);
}

/* EURange - ns=3;i=6187 */

static UA_StatusCode function_namespace_euromap77_generated_164_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6187),
UA_NODEID_NUMERIC(ns[3], 6186),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6187), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_164_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6187)
);
}

/* MaxScrewStroke - ns=3;i=6180 */

static UA_StatusCode function_namespace_euromap77_generated_165_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6180_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6180_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6180_variant_DataContents);
*variablenode_ns_3_i_6180_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6180_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "MaxScrewStroke");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "maximum stroke of the screw installed in the injection unit");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6180),
UA_NODEID_NUMERIC(ns[3], 5027),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "MaxScrewStroke"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6180_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6180), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_165_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6180)
);
}

/* EngineeringUnits - ns=3;i=6181 */

static UA_StatusCode function_namespace_euromap77_generated_166_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6181),
UA_NODEID_NUMERIC(ns[3], 6180),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6181), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_166_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6181)
);
}

/* EURange - ns=3;i=6182 */

static UA_StatusCode function_namespace_euromap77_generated_167_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6182),
UA_NODEID_NUMERIC(ns[3], 6180),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6182), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_167_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6182)
);
}

/* IsPresent - ns=3;i=6179 */

static UA_StatusCode function_namespace_euromap77_generated_168_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_3_i_6179_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_3_i_6179_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_3_i_6179_variant_DataContents);
*variablenode_ns_3_i_6179_variant_DataContents = (UA_Boolean) true;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6179_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "IsPresent");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Information if the injection unit is physically installed on the injection machines");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6179),
UA_NODEID_NUMERIC(ns[3], 5027),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[3], "IsPresent"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_3_i_6179_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6179), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_168_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6179)
);
}

/* ScrewDiameter - ns=3;i=6183 */

static UA_StatusCode function_namespace_euromap77_generated_169_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6183_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6183_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6183_variant_DataContents);
*variablenode_ns_3_i_6183_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6183_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "ScrewDiameter");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "diameter of the screw installed in the injection unit");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6183),
UA_NODEID_NUMERIC(ns[3], 5027),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "ScrewDiameter"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6183_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6183), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_169_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6183)
);
}

/* EURange - ns=3;i=6184 */

static UA_StatusCode function_namespace_euromap77_generated_170_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6184),
UA_NODEID_NUMERIC(ns[3], 6183),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6184), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_170_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6184)
);
}

/* EngineeringUnits - ns=3;i=6252 */

static UA_StatusCode function_namespace_euromap77_generated_171_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_3_i_6252_EUInformation_0, 1);
UA_init(variablenode_ns_3_i_6252_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_3_i_6252_EUInformation_0->namespaceUri = UA_STRING("");
variablenode_ns_3_i_6252_EUInformation_0->unitId = (UA_Int32) -1;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6252_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6252),
UA_NODEID_NUMERIC(ns[3], 6183),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6252), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_171_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6252)
);
}

/* BarrelId - ns=3;i=6018 */

static UA_StatusCode function_namespace_euromap77_generated_172_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6018_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6018_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6018_variant_DataContents);
*variablenode_ns_3_i_6018_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6018_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "BarrelId");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Id (e.g. serial number) of the barrel");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6018),
UA_NODEID_NUMERIC(ns[3], 5027),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[3], "BarrelId"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6018_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6018), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_172_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6018)
);
}

/* ScrewVolume - ns=3;i=6104 */

static UA_StatusCode function_namespace_euromap77_generated_173_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6104_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6104_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6104_variant_DataContents);
*variablenode_ns_3_i_6104_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6104_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "ScrewVolume");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "volume of the screw installed in the injection unit");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6104),
UA_NODEID_NUMERIC(ns[3], 1028),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "ScrewVolume"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6104_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6104), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_173_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6104)
);
}

/* EURange - ns=3;i=6105 */

static UA_StatusCode function_namespace_euromap77_generated_174_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6105),
UA_NODEID_NUMERIC(ns[3], 6104),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6105), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_174_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6105)
);
}

/* EngineeringUnits - ns=3;i=6251 */

static UA_StatusCode function_namespace_euromap77_generated_175_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_3_i_6251_EUInformation_0, 1);
UA_init(variablenode_ns_3_i_6251_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_3_i_6251_EUInformation_0->namespaceUri = UA_STRING("");
variablenode_ns_3_i_6251_EUInformation_0->unitId = (UA_Int32) -1;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6251_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6251),
UA_NODEID_NUMERIC(ns[3], 6104),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6251), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_175_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6251)
);
}

/* ScrewDiameter - ns=3;i=6100 */

static UA_StatusCode function_namespace_euromap77_generated_176_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6100_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6100_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6100_variant_DataContents);
*variablenode_ns_3_i_6100_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6100_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "ScrewDiameter");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "diameter of the screw installed in the injection unit");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6100),
UA_NODEID_NUMERIC(ns[3], 1028),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "ScrewDiameter"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6100_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6100), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_176_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6100)
);
}

/* EURange - ns=3;i=6101 */

static UA_StatusCode function_namespace_euromap77_generated_177_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6101),
UA_NODEID_NUMERIC(ns[3], 6100),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6101), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_177_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6101)
);
}

/* EngineeringUnits - ns=3;i=6691 */

static UA_StatusCode function_namespace_euromap77_generated_178_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_3_i_6691_EUInformation_0, 1);
UA_init(variablenode_ns_3_i_6691_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_3_i_6691_EUInformation_0->namespaceUri = UA_STRING("");
variablenode_ns_3_i_6691_EUInformation_0->unitId = (UA_Int32) -1;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6691_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6691),
UA_NODEID_NUMERIC(ns[3], 6100),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6691), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_178_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6691)
);
}

/* MaxScrewStroke - ns=3;i=6102 */

static UA_StatusCode function_namespace_euromap77_generated_179_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6102_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6102_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6102_variant_DataContents);
*variablenode_ns_3_i_6102_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6102_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "MaxScrewStroke");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "maximum stroke of the screw installed in the injection unit");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6102),
UA_NODEID_NUMERIC(ns[3], 1028),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "MaxScrewStroke"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6102_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6102), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_179_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6102)
);
}

/* EURange - ns=3;i=6103 */

static UA_StatusCode function_namespace_euromap77_generated_180_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6103),
UA_NODEID_NUMERIC(ns[3], 6102),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6103), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_180_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6103)
);
}

/* EngineeringUnits - ns=3;i=6689 */

static UA_StatusCode function_namespace_euromap77_generated_181_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6689),
UA_NODEID_NUMERIC(ns[3], 6102),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6689), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_181_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6689)
);
}

/* BarrelId - ns=3;i=6097 */

static UA_StatusCode function_namespace_euromap77_generated_182_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6097_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6097_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6097_variant_DataContents);
*variablenode_ns_3_i_6097_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6097_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "BarrelId");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Id (e.g. serial number) of the barrel");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6097),
UA_NODEID_NUMERIC(ns[3], 1028),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[3], "BarrelId"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6097_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6097), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_182_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6097)
);
}

/* Euromap77 - ns=3;i=6012 */
static const UA_Byte variablenode_ns_3_i_6012_variant_DataContents_byteArray[3274] = {60, 111, 112, 99, 58, 84, 121, 112, 101, 68, 105, 99, 116, 105, 111, 110, 97, 114, 121, 32, 120, 109, 108, 110, 115, 58, 120, 115, 105, 61, 34, 104, 116, 116, 112, 58, 47, 47, 119, 119, 119, 46, 119, 51, 46, 111, 114, 103, 47, 50, 48, 48, 49, 47, 88, 77, 76, 83, 99, 104, 101, 109, 97, 45, 105, 110, 115, 116, 97, 110, 99, 101, 34, 32, 120, 109, 108, 110, 115, 58, 116, 110, 115, 61, 34, 104, 116, 116, 112, 58, 47, 47, 119, 119, 119, 46, 101, 117, 114, 111, 109, 97, 112, 46, 111, 114, 103, 47, 101, 117, 114, 111, 109, 97, 112, 55, 55, 47, 34, 32, 68, 101, 102, 97, 117, 108, 116, 66, 121, 116, 101, 79, 114, 100, 101, 114, 61, 34, 76, 105, 116, 116, 108, 101, 69, 110, 100, 105, 97, 110, 34, 32, 120, 109, 108, 110, 115, 58, 111, 112, 99, 61, 34, 104, 116, 116, 112, 58, 47, 47, 111, 112, 99, 102, 111, 117, 110, 100, 97, 116, 105, 111, 110, 46, 111, 114, 103, 47, 66, 105, 110, 97, 114, 121, 83, 99, 104, 101, 109, 97, 47, 34, 32, 120, 109, 108, 110, 115, 58, 117, 97, 61, 34, 104, 116, 116, 112, 58, 47, 47, 111, 112, 99, 102, 111, 117, 110, 100, 97, 116, 105, 111, 110, 46, 111, 114, 103, 47, 85, 65, 47, 34, 32, 84, 97, 114, 103, 101, 116, 78, 97, 109, 101, 115, 112, 97, 99, 101, 61, 34, 104, 116, 116, 112, 58, 47, 47, 119, 119, 119, 46, 101, 117, 114, 111, 109, 97, 112, 46, 111, 114, 103, 47, 101, 117, 114, 111, 109, 97, 112, 55, 55, 47, 34, 62, 10, 32, 60, 111, 112, 99, 58, 73, 109, 112, 111, 114, 116, 32, 78, 97, 109, 101, 115, 112, 97, 99, 101, 61, 34, 104, 116, 116, 112, 58, 47, 47, 111, 112, 99, 102, 111, 117, 110, 100, 97, 116, 105, 111, 110, 46, 111, 114, 103, 47, 85, 65, 47, 34, 47, 62, 10, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 84, 121, 112, 101, 32, 76, 101, 110, 103, 116, 104, 73, 110, 66, 105, 116, 115, 61, 34, 51, 50, 34, 32, 78, 97, 109, 101, 61, 34, 73, 77, 77, 77, 101, 115, 115, 97, 103, 101, 67, 108, 97, 115, 115, 105, 102, 105, 99, 97, 116, 105, 111, 110, 69, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 34, 62, 10, 32, 32, 60, 111, 112, 99, 58, 68, 111, 99, 117, 109, 101, 110, 116, 97, 116, 105, 111, 110, 62, 84, 104, 105, 115, 32, 69, 110, 117, 109, 101, 114, 97, 116, 105, 111, 110, 32, 115, 112, 101, 99, 105, 102, 105, 101, 115, 32, 116, 104, 101, 32, 118, 97, 108, 117, 101, 115, 32, 116, 111, 32, 98, 101, 32, 117, 115, 101, 100, 32, 105, 110, 32, 116, 104, 101, 32, 67, 108, 97, 115, 115, 105, 102, 105, 99, 97, 116, 105, 111, 110, 32, 112, 114, 111, 112, 101, 114, 116, 121, 32, 105, 110, 32, 116, 104, 101, 32, 77, 101, 115, 115, 97, 103, 101, 67, 111, 110, 100, 105, 116, 105, 111, 110, 84, 121, 112, 101, 32, 97, 110, 100, 32, 114, 101, 108, 97, 116, 101, 100, 32, 108, 111, 103, 98, 111, 111, 107, 32, 101, 118, 101, 110, 116, 115, 32, 111, 102, 32, 69, 85, 82, 79, 77, 65, 80, 32, 56, 51, 60, 47, 111, 112, 99, 58, 68, 111, 99, 117, 109, 101, 110, 116, 97, 116, 105, 111, 110, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 79, 84, 72, 69, 82, 34, 32, 86, 97, 108, 117, 101, 61, 34, 48, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 73, 77, 77, 95, 73, 78, 74, 69, 67, 84, 73, 79, 78, 95, 85, 78, 73, 84, 34, 32, 86, 97, 108, 117, 101, 61, 34, 49, 48, 48, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 73, 77, 77, 95, 67, 76, 65, 77, 80, 73, 78, 71, 95, 85, 78, 73, 84, 34, 32, 86, 97, 108, 117, 101, 61, 34, 49, 48, 49, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 73, 77, 77, 95, 72, 65, 82, 68, 87, 65, 82, 69, 34, 32, 86, 97, 108, 117, 101, 61, 34, 49, 48, 50, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 73, 77, 77, 95, 67, 79, 77, 80, 82, 69, 83, 83, 69, 68, 95, 65, 73, 82, 95, 67, 79, 78, 84, 82, 79, 76, 34, 32, 86, 97, 108, 117, 101, 61, 34, 49, 48, 51, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 73, 77, 77, 95, 77, 65, 67, 72, 73, 78, 69, 95, 77, 79, 78, 73, 84, 79, 82, 73, 78, 71, 34, 32, 86, 97, 108, 117, 101, 61, 34, 49, 48, 52, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 73, 77, 77, 95, 77, 79, 85, 76, 68, 34, 32, 86, 97, 108, 117, 101, 61, 34, 49, 48, 53, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 73, 77, 77, 95, 69, 74, 69, 67, 84, 79, 82, 34, 32, 86, 97, 108, 117, 101, 61, 34, 49, 48, 54, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 73, 77, 77, 95, 67, 79, 82, 69, 95, 80, 85, 76, 76, 34, 32, 86, 97, 108, 117, 101, 61, 34, 49, 48, 55, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 73, 77, 77, 95, 84, 65, 66, 76, 69, 34, 32, 86, 97, 108, 117, 101, 61, 34, 49, 48, 56, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 73, 77, 77, 95, 73, 78, 74, 69, 67, 84, 73, 79, 78, 95, 80, 82, 79, 71, 82, 65, 77, 34, 32, 86, 97, 108, 117, 101, 61, 34, 49, 48, 57, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 73, 77, 77, 95, 72, 89, 68, 82, 65, 85, 76, 73, 67, 95, 84, 69, 77, 80, 69, 82, 65, 84, 85, 82, 69, 95, 67, 79, 78, 84, 82, 79, 76, 34, 32, 86, 97, 108, 117, 101, 61, 34, 49, 49, 48, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 73, 77, 77, 95, 67, 89, 76, 73, 78, 68, 69, 82, 95, 84, 69, 77, 80, 69, 82, 65, 84, 85, 82, 69, 95, 67, 79, 78, 84, 82, 79, 76, 34, 32, 86, 97, 108, 117, 101, 61, 34, 49, 49, 49, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 73, 77, 77, 95, 77, 79, 85, 76, 68, 95, 84, 69, 77, 80, 69, 82, 65, 84, 85, 82, 69, 95, 67, 79, 78, 84, 82, 79, 76, 34, 32, 86, 97, 108, 117, 101, 61, 34, 49, 49, 50, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 73, 77, 77, 95, 72, 79, 84, 95, 82, 85, 78, 78, 69, 82, 34, 32, 86, 97, 108, 117, 101, 61, 34, 49, 49, 51, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 73, 77, 77, 95, 73, 78, 84, 69, 82, 70, 65, 67, 69, 83, 34, 32, 86, 97, 108, 117, 101, 61, 34, 49, 49, 52, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 73, 77, 77, 95, 77, 69, 65, 83, 85, 82, 73, 78, 71, 95, 83, 89, 83, 84, 69, 77, 34, 32, 86, 97, 108, 117, 101, 61, 34, 49, 49, 53, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 73, 77, 77, 95, 82, 79, 66, 79, 84, 73, 67, 95, 83, 89, 83, 84, 69, 77, 95, 73, 78, 84, 69, 82, 70, 65, 67, 69, 34, 32, 86, 97, 108, 117, 101, 61, 34, 49, 49, 54, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 73, 77, 77, 95, 83, 80, 69, 67, 73, 65, 76, 95, 80, 85, 82, 80, 79, 83, 69, 95, 83, 73, 71, 78, 65, 76, 83, 34, 32, 86, 97, 108, 117, 101, 61, 34, 49, 49, 55, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 73, 77, 77, 95, 82, 69, 65, 76, 95, 84, 73, 77, 69, 95, 69, 84, 72, 69, 82, 78, 69, 84, 95, 83, 89, 83, 84, 69, 77, 34, 32, 86, 97, 108, 117, 101, 61, 34, 49, 49, 56, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 73, 77, 77, 95, 77, 65, 67, 72, 73, 78, 69, 95, 67, 79, 78, 84, 82, 79, 76, 76, 69, 82, 34, 32, 86, 97, 108, 117, 101, 61, 34, 49, 49, 57, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 73, 77, 77, 95, 83, 79, 70, 84, 87, 65, 82, 69, 95, 77, 79, 78, 73, 84, 79, 82, 73, 78, 71, 34, 32, 86, 97, 108, 117, 101, 61, 34, 49, 50, 48, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 80, 69, 82, 73, 80, 72, 69, 82, 65, 76, 95, 69, 88, 84, 69, 82, 78, 65, 76, 95, 68, 69, 86, 73, 67, 69, 95, 73, 78, 84, 69, 82, 70, 65, 67, 69, 34, 32, 86, 97, 108, 117, 101, 61, 34, 50, 48, 48, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 80, 69, 82, 73, 80, 72, 69, 82, 65, 76, 95, 84, 69, 77, 80, 69, 82, 65, 84, 85, 82, 69, 95, 67, 79, 78, 84, 82, 79, 76, 95, 85, 78, 73, 84, 34, 32, 86, 97, 108, 117, 101, 61, 34, 50, 48, 49, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 80, 69, 82, 73, 80, 72, 69, 82, 65, 76, 95, 82, 79, 66, 79, 84, 73, 67, 83, 95, 83, 89, 83, 84, 69, 77, 34, 32, 86, 97, 108, 117, 101, 61, 34, 50, 48, 50, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 80, 69, 82, 73, 80, 72, 69, 82, 65, 76, 95, 76, 83, 82, 34, 32, 86, 97, 108, 117, 101, 61, 34, 50, 48, 51, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 80, 69, 82, 73, 80, 72, 69, 82, 65, 76, 95, 83, 84, 82, 73, 80, 80, 69, 82, 95, 85, 78, 73, 84, 34, 32, 86, 97, 108, 117, 101, 61, 34, 50, 48, 52, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 80, 69, 82, 73, 80, 72, 69, 82, 65, 76, 95, 68, 82, 89, 69, 82, 34, 32, 86, 97, 108, 117, 101, 61, 34, 50, 48, 53, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 80, 69, 82, 73, 80, 72, 69, 82, 65, 76, 95, 67, 79, 78, 86, 69, 89, 79, 82, 95, 66, 69, 76, 84, 34, 32, 86, 97, 108, 117, 101, 61, 34, 50, 48, 54, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 80, 69, 82, 73, 80, 72, 69, 82, 65, 76, 95, 83, 79, 82, 84, 69, 82, 95, 85, 78, 73, 84, 34, 32, 86, 97, 108, 117, 101, 61, 34, 50, 48, 55, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 80, 69, 82, 73, 80, 72, 69, 82, 65, 76, 95, 67, 79, 76, 79, 85, 82, 73, 78, 71, 95, 85, 78, 73, 84, 34, 32, 86, 97, 108, 117, 101, 61, 34, 50, 48, 56, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 80, 69, 82, 73, 80, 72, 69, 82, 65, 76, 95, 70, 69, 69, 68, 73, 78, 71, 34, 32, 86, 97, 108, 117, 101, 61, 34, 50, 48, 57, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 80, 69, 82, 73, 80, 72, 69, 82, 65, 76, 95, 69, 88, 84, 69, 82, 78, 65, 76, 95, 65, 76, 65, 82, 77, 83, 34, 32, 86, 97, 108, 117, 101, 61, 34, 50, 49, 48, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 80, 69, 82, 73, 80, 72, 69, 82, 65, 76, 95, 86, 65, 67, 85, 85, 77, 95, 67, 79, 78, 84, 82, 79, 76, 34, 32, 86, 97, 108, 117, 101, 61, 34, 50, 49, 49, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 80, 69, 82, 73, 80, 72, 69, 82, 65, 76, 95, 80, 82, 73, 78, 84, 69, 82, 95, 73, 78, 84, 69, 82, 70, 65, 67, 69, 34, 32, 86, 97, 108, 117, 101, 61, 34, 50, 49, 50, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 79, 80, 69, 82, 65, 84, 73, 79, 78, 95, 81, 85, 65, 76, 73, 84, 89, 95, 77, 79, 78, 73, 84, 79, 82, 73, 78, 71, 34, 32, 86, 97, 108, 117, 101, 61, 34, 51, 48, 48, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 79, 80, 69, 82, 65, 84, 73, 79, 78, 95, 77, 65, 78, 85, 65, 76, 95, 79, 80, 69, 82, 65, 84, 73, 79, 78, 34, 32, 86, 97, 108, 117, 101, 61, 34, 51, 48, 49, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 79, 80, 69, 82, 65, 84, 73, 79, 78, 95, 69, 77, 69, 82, 71, 69, 78, 67, 89, 95, 83, 84, 79, 80, 34, 32, 86, 97, 108, 117, 101, 61, 34, 51, 48, 50, 34, 47, 62, 10, 32, 32, 60, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 86, 97, 108, 117, 101, 32, 78, 97, 109, 101, 61, 34, 79, 80, 69, 82, 65, 84, 73, 79, 78, 95, 74, 79, 66, 95, 83, 84, 65, 84, 85, 83, 34, 32, 86, 97, 108, 117, 101, 61, 34, 51, 48, 51, 34, 47, 62, 10, 32, 60, 47, 111, 112, 99, 58, 69, 110, 117, 109, 101, 114, 97, 116, 101, 100, 84, 121, 112, 101, 62, 10, 60, 47, 111, 112, 99, 58, 84, 121, 112, 101, 68, 105, 99, 116, 105, 111, 110, 97, 114, 121, 62, 10};



static UA_StatusCode function_namespace_euromap77_generated_183_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 15);
UA_ByteString *variablenode_ns_3_i_6012_variant_DataContents =  UA_ByteString_new();
if (!variablenode_ns_3_i_6012_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_ByteString_init(variablenode_ns_3_i_6012_variant_DataContents);
variablenode_ns_3_i_6012_variant_DataContents->length = 3274;
variablenode_ns_3_i_6012_variant_DataContents->data = (UA_Byte *)(void*)(uintptr_t)variablenode_ns_3_i_6012_variant_DataContents_byteArray;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6012_variant_DataContents, &UA_TYPES[UA_TYPES_BYTESTRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "Euromap77");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Collects the data type descriptions of http://www.euromap.org/euromap77");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6012),
UA_NODEID_NUMERIC(ns[0], 93),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "Euromap77"),
UA_NODEID_NUMERIC(ns[0], 72),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
variablenode_ns_3_i_6012_variant_DataContents->data = NULL;
variablenode_ns_3_i_6012_variant_DataContents->length = 0;
UA_ByteString_delete(variablenode_ns_3_i_6012_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_183_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6012)
);
}

/* NamespaceUri - ns=3;i=6013 */

static UA_StatusCode function_namespace_euromap77_generated_184_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_3_i_6013_variant_DataContents =  UA_String_new();
if (!variablenode_ns_3_i_6013_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_3_i_6013_variant_DataContents);
*variablenode_ns_3_i_6013_variant_DataContents = UA_STRING_ALLOC("http://www.euromap.org/euromap77/");
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6013_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "NamespaceUri");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "A URI that uniquely identifies the dictionary.");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6013),
UA_NODEID_NUMERIC(ns[3], 6012),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "NamespaceUri"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_3_i_6013_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_184_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6013)
);
}

/* InjectionUnitCycleParametersType - ns=3;i=1039 */

static UA_StatusCode function_namespace_euromap77_generated_185_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectTypeAttributes attr = UA_ObjectTypeAttributes_default;
attr.isAbstract = true;
attr.displayName = UA_LOCALIZEDTEXT("", "InjectionUnitCycleParametersType");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECTTYPE,
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 58),
UA_NODEID_NUMERIC(ns[0], 45),
UA_QUALIFIEDNAME(ns[3], "InjectionUnitCycleParametersType"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTTYPEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_185_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 1039)
);
}

/* HoldHydraulicPressureAverage - ns=3;i=6146 */

static UA_StatusCode function_namespace_euromap77_generated_186_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6146_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6146_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6146_variant_DataContents);
*variablenode_ns_3_i_6146_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6146_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "HoldHydraulicPressureAverage");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Average holding pressure in the hydraulic cylinder");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6146),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "HoldHydraulicPressureAverage"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6146_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6146), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_186_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6146)
);
}

/* EngineeringUnits - ns=3;i=6454 */

static UA_StatusCode function_namespace_euromap77_generated_187_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_3_i_6454_EUInformation_0, 1);
UA_init(variablenode_ns_3_i_6454_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_3_i_6454_EUInformation_0->namespaceUri = UA_STRING("");
variablenode_ns_3_i_6454_EUInformation_0->unitId = (UA_Int32) -1;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6454_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6454),
UA_NODEID_NUMERIC(ns[3], 6146),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6454), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_187_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6454)
);
}

/* EURange - ns=3;i=6147 */

static UA_StatusCode function_namespace_euromap77_generated_188_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6147),
UA_NODEID_NUMERIC(ns[3], 6146),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6147), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_188_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6147)
);
}

/* PlastificationCircumferentialSpeedMaximum - ns=3;i=6211 */

static UA_StatusCode function_namespace_euromap77_generated_189_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6211_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6211_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6211_variant_DataContents);
*variablenode_ns_3_i_6211_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6211_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "PlastificationCircumferentialSpeedMaximum");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Maximum screw circumferential speed for plastification (e.g. mm/s)");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6211),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "PlastificationCircumferentialSpeedMaximum"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6211_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6211), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_189_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6211)
);
}

/* EURange - ns=3;i=6214 */

static UA_StatusCode function_namespace_euromap77_generated_190_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6214),
UA_NODEID_NUMERIC(ns[3], 6211),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6214), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_190_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6214)
);
}

/* EngineeringUnits - ns=3;i=6473 */

static UA_StatusCode function_namespace_euromap77_generated_191_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_3_i_6473_EUInformation_0, 1);
UA_init(variablenode_ns_3_i_6473_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_3_i_6473_EUInformation_0->namespaceUri = UA_STRING("");
variablenode_ns_3_i_6473_EUInformation_0->unitId = (UA_Int32) -1;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6473_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6473),
UA_NODEID_NUMERIC(ns[3], 6211),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6473), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_191_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6473)
);
}

/* PlastificationHydraulicPressureAverage - ns=3;i=6194 */

static UA_StatusCode function_namespace_euromap77_generated_192_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6194_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6194_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6194_variant_DataContents);
*variablenode_ns_3_i_6194_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6194_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "PlastificationHydraulicPressureAverage");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Average plastification pressure in cylinder");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6194),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "PlastificationHydraulicPressureAverage"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6194_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6194), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_192_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6194)
);
}

/* EngineeringUnits - ns=3;i=6080 */

static UA_StatusCode function_namespace_euromap77_generated_193_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6080),
UA_NODEID_NUMERIC(ns[3], 6194),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6080), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_193_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6080)
);
}

/* EURange - ns=3;i=6195 */

static UA_StatusCode function_namespace_euromap77_generated_194_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6195),
UA_NODEID_NUMERIC(ns[3], 6194),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6195), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_194_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6195)
);
}

/* PlastificationHydraulicPressureMaximum - ns=3;i=6197 */

static UA_StatusCode function_namespace_euromap77_generated_195_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6197_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6197_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6197_variant_DataContents);
*variablenode_ns_3_i_6197_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6197_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "PlastificationHydraulicPressureMaximum");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Maximum plastification pressure in cylinder");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6197),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "PlastificationHydraulicPressureMaximum"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6197_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6197), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_195_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6197)
);
}

/* EngineeringUnits - ns=3;i=6471 */

static UA_StatusCode function_namespace_euromap77_generated_196_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_3_i_6471_EUInformation_0, 1);
UA_init(variablenode_ns_3_i_6471_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_3_i_6471_EUInformation_0->namespaceUri = UA_STRING("");
variablenode_ns_3_i_6471_EUInformation_0->unitId = (UA_Int32) -1;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6471_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6471),
UA_NODEID_NUMERIC(ns[3], 6197),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6471), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_196_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6471)
);
}

/* EURange - ns=3;i=6206 */

static UA_StatusCode function_namespace_euromap77_generated_197_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6206),
UA_NODEID_NUMERIC(ns[3], 6197),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6206), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_197_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6206)
);
}

/* CushionVolume - ns=3;i=6441 */

static UA_StatusCode function_namespace_euromap77_generated_198_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6441_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6441_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6441_variant_DataContents);
*variablenode_ns_3_i_6441_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6441_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "CushionVolume");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Material volume remained in front of the screw after injection and holding pressure");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6441),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "CushionVolume"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6441_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6441), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_198_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6441)
);
}

/* EngineeringUnits - ns=3;i=6475 */

static UA_StatusCode function_namespace_euromap77_generated_199_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6475),
UA_NODEID_NUMERIC(ns[3], 6441),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6475), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_199_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6475)
);
}

/* EURange - ns=3;i=6442 */

static UA_StatusCode function_namespace_euromap77_generated_200_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6442),
UA_NODEID_NUMERIC(ns[3], 6441),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6442), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_200_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6442)
);
}

/* PlastificationSpecificPressureMaximum - ns=3;i=6069 */

static UA_StatusCode function_namespace_euromap77_generated_201_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6069_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6069_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6069_variant_DataContents);
*variablenode_ns_3_i_6069_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6069_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "PlastificationSpecificPressureMaximum");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Maximum plastification pressure in front of the screw tip");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6069),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "PlastificationSpecificPressureMaximum"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6069_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6069), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_201_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6069)
);
}

/* EngineeringUnits - ns=3;i=6082 */

static UA_StatusCode function_namespace_euromap77_generated_202_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6082),
UA_NODEID_NUMERIC(ns[3], 6069),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6082), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_202_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6082)
);
}

/* EURange - ns=3;i=6070 */

static UA_StatusCode function_namespace_euromap77_generated_203_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6070),
UA_NODEID_NUMERIC(ns[3], 6069),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6070), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_203_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6070)
);
}

/* TransferCavityPressure - ns=3;i=6117 */

static UA_StatusCode function_namespace_euromap77_generated_204_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6117_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6117_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6117_variant_DataContents);
*variablenode_ns_3_i_6117_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6117_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "TransferCavityPressure");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Cavity pressure in the mould during switch-over to the holding pressure");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6117),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "TransferCavityPressure"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6117_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6117), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_204_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6117)
);
}

/* EURange - ns=3;i=6128 */

static UA_StatusCode function_namespace_euromap77_generated_205_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6128),
UA_NODEID_NUMERIC(ns[3], 6117),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6128), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_205_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6128)
);
}

/* EngineeringUnits - ns=3;i=6428 */

static UA_StatusCode function_namespace_euromap77_generated_206_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_3_i_6428_EUInformation_0, 1);
UA_init(variablenode_ns_3_i_6428_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_3_i_6428_EUInformation_0->namespaceUri = UA_STRING("");
variablenode_ns_3_i_6428_EUInformation_0->unitId = (UA_Int32) -1;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6428_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6428),
UA_NODEID_NUMERIC(ns[3], 6117),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6428), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_206_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6428)
);
}

/* TransferVolume - ns=3;i=6254 */

static UA_StatusCode function_namespace_euromap77_generated_207_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6254_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6254_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6254_variant_DataContents);
*variablenode_ns_3_i_6254_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6254_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "TransferVolume");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Switch-over point to the holding pressure via volume");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6254),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "TransferVolume"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6254_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6254), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_207_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6254)
);
}

/* EngineeringUnits - ns=3;i=6481 */

static UA_StatusCode function_namespace_euromap77_generated_208_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_3_i_6481_EUInformation_0, 1);
UA_init(variablenode_ns_3_i_6481_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_3_i_6481_EUInformation_0->namespaceUri = UA_STRING("");
variablenode_ns_3_i_6481_EUInformation_0->unitId = (UA_Int32) -1;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6481_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6481),
UA_NODEID_NUMERIC(ns[3], 6254),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6481), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_208_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6481)
);
}

/* EURange - ns=3;i=6427 */

static UA_StatusCode function_namespace_euromap77_generated_209_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6427),
UA_NODEID_NUMERIC(ns[3], 6254),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6427), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_209_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6427)
);
}

/* DecompressionVolumeBeforePlastification - ns=3;i=6064 */

static UA_StatusCode function_namespace_euromap77_generated_210_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6064_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6064_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6064_variant_DataContents);
*variablenode_ns_3_i_6064_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6064_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "DecompressionVolumeBeforePlastification");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Decompression before plastification is the movement of the screw in the opposite direction to injection");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6064),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "DecompressionVolumeBeforePlastification"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6064_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6064), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_210_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6064)
);
}

/* EURange - ns=3;i=6136 */

static UA_StatusCode function_namespace_euromap77_generated_211_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6136),
UA_NODEID_NUMERIC(ns[3], 6064),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6136), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_211_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6136)
);
}

/* EngineeringUnits - ns=3;i=6450 */

static UA_StatusCode function_namespace_euromap77_generated_212_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_3_i_6450_EUInformation_0, 1);
UA_init(variablenode_ns_3_i_6450_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_3_i_6450_EUInformation_0->namespaceUri = UA_STRING("");
variablenode_ns_3_i_6450_EUInformation_0->unitId = (UA_Int32) -1;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6450_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6450),
UA_NODEID_NUMERIC(ns[3], 6064),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6450), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_212_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6450)
);
}

/* InjectionSpeedAverage - ns=3;i=6065 */

static UA_StatusCode function_namespace_euromap77_generated_213_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6065_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6065_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6065_variant_DataContents);
*variablenode_ns_3_i_6065_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6065_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "InjectionSpeedAverage");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Average injection speed (e.g. mm/s)");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6065),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "InjectionSpeedAverage"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6065_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6065), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_213_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6065)
);
}

/* EURange - ns=3;i=6066 */

static UA_StatusCode function_namespace_euromap77_generated_214_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6066),
UA_NODEID_NUMERIC(ns[3], 6065),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6066), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_214_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6066)
);
}

/* EngineeringUnits - ns=3;i=6016 */

static UA_StatusCode function_namespace_euromap77_generated_215_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6016),
UA_NODEID_NUMERIC(ns[3], 6065),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6016), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_215_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6016)
);
}

/* HoldSpecificPressureMaximum - ns=3;i=6152 */

static UA_StatusCode function_namespace_euromap77_generated_216_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6152_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6152_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6152_variant_DataContents);
*variablenode_ns_3_i_6152_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6152_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "HoldSpecificPressureMaximum");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Maximum holding pressure in front of the screw");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6152),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "HoldSpecificPressureMaximum"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6152_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6152), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_216_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6152)
);
}

/* EngineeringUnits - ns=3;i=6457 */

static UA_StatusCode function_namespace_euromap77_generated_217_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_3_i_6457_EUInformation_0, 1);
UA_init(variablenode_ns_3_i_6457_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_3_i_6457_EUInformation_0->namespaceUri = UA_STRING("");
variablenode_ns_3_i_6457_EUInformation_0->unitId = (UA_Int32) -1;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6457_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6457),
UA_NODEID_NUMERIC(ns[3], 6152),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6457), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_217_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6457)
);
}

/* EURange - ns=3;i=6153 */

static UA_StatusCode function_namespace_euromap77_generated_218_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6153),
UA_NODEID_NUMERIC(ns[3], 6152),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6153), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_218_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6153)
);
}

/* PlastificationSpecificPressureAverage - ns=3;i=6067 */

static UA_StatusCode function_namespace_euromap77_generated_219_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6067_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6067_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6067_variant_DataContents);
*variablenode_ns_3_i_6067_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6067_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "PlastificationSpecificPressureAverage");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Average plastification pressure in front of the screw tip");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6067),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "PlastificationSpecificPressureAverage"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6067_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6067), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_219_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6067)
);
}

/* EngineeringUnits - ns=3;i=6081 */

static UA_StatusCode function_namespace_euromap77_generated_220_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6081),
UA_NODEID_NUMERIC(ns[3], 6067),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6081), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_220_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6081)
);
}

/* EURange - ns=3;i=6068 */

static UA_StatusCode function_namespace_euromap77_generated_221_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6068),
UA_NODEID_NUMERIC(ns[3], 6067),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6068), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_221_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6068)
);
}

/* InjectionTime - ns=3;i=6060 */

static UA_StatusCode function_namespace_euromap77_generated_222_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 290);
UA_Double *variablenode_ns_3_i_6060_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6060_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6060_variant_DataContents);
*variablenode_ns_3_i_6060_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6060_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "InjectionTime");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Time required to fill the cavity or mould");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6060),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "InjectionTime"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6060_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6060), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_222_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6060)
);
}

/* InjectionSpeedMaximum - ns=3;i=6061 */

static UA_StatusCode function_namespace_euromap77_generated_223_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6061_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6061_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6061_variant_DataContents);
*variablenode_ns_3_i_6061_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6061_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "InjectionSpeedMaximum");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Maximum injection speed (e.g. mm/s)");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6061),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "InjectionSpeedMaximum"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6061_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6061), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_223_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6061)
);
}

/* EngineeringUnits - ns=3;i=6032 */

static UA_StatusCode function_namespace_euromap77_generated_224_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6032),
UA_NODEID_NUMERIC(ns[3], 6061),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6032), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_224_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6032)
);
}

/* EURange - ns=3;i=6062 */

static UA_StatusCode function_namespace_euromap77_generated_225_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6062),
UA_NODEID_NUMERIC(ns[3], 6061),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6062), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_225_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6062)
);
}

/* TransferHydraulicPressure - ns=3;i=6156 */

static UA_StatusCode function_namespace_euromap77_generated_226_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6156_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6156_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6156_variant_DataContents);
*variablenode_ns_3_i_6156_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6156_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "TransferHydraulicPressure");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Hydraulic pressure in the cylinder during switch-over to the holding pressure");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6156),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "TransferHydraulicPressure"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6156_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6156), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_226_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6156)
);
}

/* EngineeringUnits - ns=3;i=6458 */

static UA_StatusCode function_namespace_euromap77_generated_227_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_3_i_6458_EUInformation_0, 1);
UA_init(variablenode_ns_3_i_6458_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_3_i_6458_EUInformation_0->namespaceUri = UA_STRING("");
variablenode_ns_3_i_6458_EUInformation_0->unitId = (UA_Int32) -1;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6458_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6458),
UA_NODEID_NUMERIC(ns[3], 6156),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6458), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_227_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6458)
);
}

/* EURange - ns=3;i=6162 */

static UA_StatusCode function_namespace_euromap77_generated_228_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6162),
UA_NODEID_NUMERIC(ns[3], 6156),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6162), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_228_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6162)
);
}

/* PlastificationVolume - ns=3;i=6063 */

static UA_StatusCode function_namespace_euromap77_generated_229_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6063_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6063_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6063_variant_DataContents);
*variablenode_ns_3_i_6063_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6063_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "PlastificationVolume");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Volume dosed by the machine for the next injection shot");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6063),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "PlastificationVolume"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6063_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6063), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_229_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6063)
);
}

/* EURange - ns=3;i=6227 */

static UA_StatusCode function_namespace_euromap77_generated_230_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6227),
UA_NODEID_NUMERIC(ns[3], 6063),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6227), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_230_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6227)
);
}

/* EngineeringUnits - ns=3;i=6477 */

static UA_StatusCode function_namespace_euromap77_generated_231_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_3_i_6477_EUInformation_0, 1);
UA_init(variablenode_ns_3_i_6477_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_3_i_6477_EUInformation_0->namespaceUri = UA_STRING("");
variablenode_ns_3_i_6477_EUInformation_0->unitId = (UA_Int32) -1;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6477_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6477),
UA_NODEID_NUMERIC(ns[3], 6063),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6477), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_231_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6477)
);
}

/* FlowIndex - ns=3;i=6160 */

static UA_StatusCode function_namespace_euromap77_generated_232_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6160_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6160_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6160_variant_DataContents);
*variablenode_ns_3_i_6160_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6160_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "FlowIndex");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Flow index");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6160),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "FlowIndex"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6160_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6160), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_232_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6160)
);
}

/* EngineeringUnits - ns=3;i=6168 */

static UA_StatusCode function_namespace_euromap77_generated_233_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6168),
UA_NODEID_NUMERIC(ns[3], 6160),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6168), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_233_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6168)
);
}

/* EURange - ns=3;i=6163 */

static UA_StatusCode function_namespace_euromap77_generated_234_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6163),
UA_NODEID_NUMERIC(ns[3], 6160),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6163), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_234_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6163)
);
}

/* HoldSpecificPressureAverage - ns=3;i=6150 */

static UA_StatusCode function_namespace_euromap77_generated_235_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6150_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6150_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6150_variant_DataContents);
*variablenode_ns_3_i_6150_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6150_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "HoldSpecificPressureAverage");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Average holding pressure in front of the screw");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6150),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "HoldSpecificPressureAverage"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6150_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6150), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_235_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6150)
);
}

/* EngineeringUnits - ns=3;i=6456 */

static UA_StatusCode function_namespace_euromap77_generated_236_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_3_i_6456_EUInformation_0, 1);
UA_init(variablenode_ns_3_i_6456_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_3_i_6456_EUInformation_0->namespaceUri = UA_STRING("");
variablenode_ns_3_i_6456_EUInformation_0->unitId = (UA_Int32) -1;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6456_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6456),
UA_NODEID_NUMERIC(ns[3], 6150),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6456), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_236_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6456)
);
}

/* EURange - ns=3;i=6151 */

static UA_StatusCode function_namespace_euromap77_generated_237_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6151),
UA_NODEID_NUMERIC(ns[3], 6150),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6151), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_237_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6151)
);
}

/* Index - ns=3;i=6107 */

static UA_StatusCode function_namespace_euromap77_generated_238_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
UA_UInt32 *variablenode_ns_3_i_6107_variant_DataContents =  UA_UInt32_new();
if (!variablenode_ns_3_i_6107_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt32_init(variablenode_ns_3_i_6107_variant_DataContents);
*variablenode_ns_3_i_6107_variant_DataContents = (UA_UInt32) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6107_variant_DataContents, &UA_TYPES[UA_TYPES_UINT32]);
attr.displayName = UA_LOCALIZEDTEXT("", "Index");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Index of the injection unit");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6107),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[3], "Index"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt32_delete(variablenode_ns_3_i_6107_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6107), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_238_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6107)
);
}

/* BackPressure - ns=3;i=6118 */

static UA_StatusCode function_namespace_euromap77_generated_239_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6118_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6118_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6118_variant_DataContents);
*variablenode_ns_3_i_6118_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6118_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "BackPressure");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Back pressure is the melt-pressure against the screw movement during dosage");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6118),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "BackPressure"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6118_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6118), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_239_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6118)
);
}

/* EngineeringUnits - ns=3;i=6120 */

static UA_StatusCode function_namespace_euromap77_generated_240_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_3_i_6120_EUInformation_0, 1);
UA_init(variablenode_ns_3_i_6120_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_3_i_6120_EUInformation_0->namespaceUri = UA_STRING("");
variablenode_ns_3_i_6120_EUInformation_0->unitId = (UA_Int32) -1;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6120_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6120),
UA_NODEID_NUMERIC(ns[3], 6118),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6120), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_240_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6120)
);
}

/* EURange - ns=3;i=6119 */

static UA_StatusCode function_namespace_euromap77_generated_241_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6119),
UA_NODEID_NUMERIC(ns[3], 6118),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6119), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_241_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6119)
);
}

/* PlastificationRotationalSpeedAverage - ns=3;i=6223 */

static UA_StatusCode function_namespace_euromap77_generated_242_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6223_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6223_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6223_variant_DataContents);
*variablenode_ns_3_i_6223_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6223_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "PlastificationRotationalSpeedAverage");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Average plastification speed of the injection unit (RPM)");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6223),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "PlastificationRotationalSpeedAverage"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6223_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6223), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_242_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6223)
);
}

/* EngineeringUnits - ns=3;i=6474 */

static UA_StatusCode function_namespace_euromap77_generated_243_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_3_i_6474_EUInformation_0, 1);
UA_init(variablenode_ns_3_i_6474_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_3_i_6474_EUInformation_0->namespaceUri = UA_STRING("");
variablenode_ns_3_i_6474_EUInformation_0->unitId = (UA_Int32) -1;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6474_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6474),
UA_NODEID_NUMERIC(ns[3], 6223),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6474), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_243_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6474)
);
}

/* EURange - ns=3;i=6224 */

static UA_StatusCode function_namespace_euromap77_generated_244_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6224),
UA_NODEID_NUMERIC(ns[3], 6223),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6224), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_244_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6224)
);
}

/* HydraulicPressureMaximum - ns=3;i=6188 */

static UA_StatusCode function_namespace_euromap77_generated_245_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6188_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6188_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6188_variant_DataContents);
*variablenode_ns_3_i_6188_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6188_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "HydraulicPressureMaximum");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Maximum pressure in the hydraulic cylinder");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6188),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "HydraulicPressureMaximum"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6188_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6188), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_245_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6188)
);
}

/* EngineeringUnits - ns=3;i=6459 */

static UA_StatusCode function_namespace_euromap77_generated_246_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_3_i_6459_EUInformation_0, 1);
UA_init(variablenode_ns_3_i_6459_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_3_i_6459_EUInformation_0->namespaceUri = UA_STRING("");
variablenode_ns_3_i_6459_EUInformation_0->unitId = (UA_Int32) -1;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6459_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6459),
UA_NODEID_NUMERIC(ns[3], 6188),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6459), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_246_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6459)
);
}

/* EURange - ns=3;i=6191 */

static UA_StatusCode function_namespace_euromap77_generated_247_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6191),
UA_NODEID_NUMERIC(ns[3], 6188),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6191), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_247_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6191)
);
}

/* InjectionStartPosition - ns=3;i=6164 */

static UA_StatusCode function_namespace_euromap77_generated_248_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6164_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6164_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6164_variant_DataContents);
*variablenode_ns_3_i_6164_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6164_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "InjectionStartPosition");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Start position of the injection");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6164),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "InjectionStartPosition"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6164_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6164), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_248_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6164)
);
}

/* EURange - ns=3;i=6165 */

static UA_StatusCode function_namespace_euromap77_generated_249_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6165),
UA_NODEID_NUMERIC(ns[3], 6164),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6165), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_249_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6165)
);
}

/* EngineeringUnits - ns=3;i=6169 */

static UA_StatusCode function_namespace_euromap77_generated_250_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6169),
UA_NODEID_NUMERIC(ns[3], 6164),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6169), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_250_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6169)
);
}

/* PlastificationRotationalSpeedMaximum - ns=3;i=6225 */

static UA_StatusCode function_namespace_euromap77_generated_251_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6225_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6225_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6225_variant_DataContents);
*variablenode_ns_3_i_6225_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6225_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "PlastificationRotationalSpeedMaximum");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Maximum plastification speed of the injection unit (RPM)");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6225),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "PlastificationRotationalSpeedMaximum"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6225_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6225), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_251_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6225)
);
}

/* EURange - ns=3;i=6226 */

static UA_StatusCode function_namespace_euromap77_generated_252_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6226),
UA_NODEID_NUMERIC(ns[3], 6225),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6226), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_252_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6226)
);
}

/* EngineeringUnits - ns=3;i=6476 */

static UA_StatusCode function_namespace_euromap77_generated_253_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_3_i_6476_EUInformation_0, 1);
UA_init(variablenode_ns_3_i_6476_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_3_i_6476_EUInformation_0->namespaceUri = UA_STRING("");
variablenode_ns_3_i_6476_EUInformation_0->unitId = (UA_Int32) -1;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6476_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6476),
UA_NODEID_NUMERIC(ns[3], 6225),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6476), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_253_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6476)
);
}

/* TransferSpecificPressure - ns=3;i=6228 */

static UA_StatusCode function_namespace_euromap77_generated_254_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6228_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6228_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6228_variant_DataContents);
*variablenode_ns_3_i_6228_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6228_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "TransferSpecificPressure");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Pressure in front of the screw tip during switch-over to the holding pressure");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6228),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "TransferSpecificPressure"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6228_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6228), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_254_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6228)
);
}

/* EURange - ns=3;i=6246 */

static UA_StatusCode function_namespace_euromap77_generated_255_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6246),
UA_NODEID_NUMERIC(ns[3], 6228),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6246), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_255_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6246)
);
}

/* EngineeringUnits - ns=3;i=6478 */

static UA_StatusCode function_namespace_euromap77_generated_256_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_3_i_6478_EUInformation_0, 1);
UA_init(variablenode_ns_3_i_6478_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_3_i_6478_EUInformation_0->namespaceUri = UA_STRING("");
variablenode_ns_3_i_6478_EUInformation_0->unitId = (UA_Int32) -1;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6478_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6478),
UA_NODEID_NUMERIC(ns[3], 6228),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6478), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_256_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6478)
);
}

/* DosingTime - ns=3;i=6059 */

static UA_StatusCode function_namespace_euromap77_generated_257_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 290);
UA_Double *variablenode_ns_3_i_6059_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6059_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6059_variant_DataContents);
*variablenode_ns_3_i_6059_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6059_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "DosingTime");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Time to melt-up the plastic granulates and feed the melt for the next injection shot to the front of the screw");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6059),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "DosingTime"),
UA_NODEID_NUMERIC(ns[0], 63),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6059_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6059), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_257_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6059)
);
}

/* VPChangeOverPosition - ns=3;i=6166 */

static UA_StatusCode function_namespace_euromap77_generated_258_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6166_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6166_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6166_variant_DataContents);
*variablenode_ns_3_i_6166_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6166_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "VPChangeOverPosition");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Screw position at switching between injection (V) and holding pressure (P)");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6166),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "VPChangeOverPosition"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6166_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6166), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_258_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6166)
);
}

/* EURange - ns=3;i=6167 */

static UA_StatusCode function_namespace_euromap77_generated_259_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6167),
UA_NODEID_NUMERIC(ns[3], 6166),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6167), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_259_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6167)
);
}

/* EngineeringUnits - ns=3;i=6170 */

static UA_StatusCode function_namespace_euromap77_generated_260_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6170),
UA_NODEID_NUMERIC(ns[3], 6166),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6170), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_260_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6170)
);
}

/* HoldHydraulicPressureMaximum - ns=3;i=6148 */

static UA_StatusCode function_namespace_euromap77_generated_261_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6148_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6148_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6148_variant_DataContents);
*variablenode_ns_3_i_6148_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6148_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "HoldHydraulicPressureMaximum");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Maximum holding pressure in the hydraulic cylinder");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6148),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "HoldHydraulicPressureMaximum"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6148_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6148), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_261_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6148)
);
}

/* EURange - ns=3;i=6149 */

static UA_StatusCode function_namespace_euromap77_generated_262_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6149),
UA_NODEID_NUMERIC(ns[3], 6148),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6149), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_262_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6149)
);
}

/* EngineeringUnits - ns=3;i=6455 */

static UA_StatusCode function_namespace_euromap77_generated_263_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_3_i_6455_EUInformation_0, 1);
UA_init(variablenode_ns_3_i_6455_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_3_i_6455_EUInformation_0->namespaceUri = UA_STRING("");
variablenode_ns_3_i_6455_EUInformation_0->unitId = (UA_Int32) -1;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6455_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6455),
UA_NODEID_NUMERIC(ns[3], 6148),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6455), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_263_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6455)
);
}

/* PlastificationCircumferentialSpeedAverage - ns=3;i=6208 */

static UA_StatusCode function_namespace_euromap77_generated_264_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6208_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6208_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6208_variant_DataContents);
*variablenode_ns_3_i_6208_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6208_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "PlastificationCircumferentialSpeedAverage");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Average screw circumferential speed for plastification (e.g. mm/s)");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6208),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "PlastificationCircumferentialSpeedAverage"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6208_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6208), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_264_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6208)
);
}

/* EURange - ns=3;i=6210 */

static UA_StatusCode function_namespace_euromap77_generated_265_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6210),
UA_NODEID_NUMERIC(ns[3], 6208),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6210), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_265_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6210)
);
}

/* EngineeringUnits - ns=3;i=6472 */

static UA_StatusCode function_namespace_euromap77_generated_266_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_3_i_6472_EUInformation_0, 1);
UA_init(variablenode_ns_3_i_6472_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_3_i_6472_EUInformation_0->namespaceUri = UA_STRING("");
variablenode_ns_3_i_6472_EUInformation_0->unitId = (UA_Int32) -1;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6472_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6472),
UA_NODEID_NUMERIC(ns[3], 6208),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6472), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_266_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6472)
);
}

/* CushionStroke - ns=3;i=6093 */

static UA_StatusCode function_namespace_euromap77_generated_267_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6093_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6093_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6093_variant_DataContents);
*variablenode_ns_3_i_6093_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6093_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "CushionStroke");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Stroke position at cushion");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6093),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "CushionStroke"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6093_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6093), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_267_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6093)
);
}

/* EURange - ns=3;i=6121 */

static UA_StatusCode function_namespace_euromap77_generated_268_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6121),
UA_NODEID_NUMERIC(ns[3], 6093),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6121), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_268_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6121)
);
}

/* EngineeringUnits - ns=3;i=6122 */

static UA_StatusCode function_namespace_euromap77_generated_269_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6122),
UA_NODEID_NUMERIC(ns[3], 6093),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6122), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_269_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6122)
);
}

/* SpecificPressureMaximum - ns=3;i=6247 */

static UA_StatusCode function_namespace_euromap77_generated_270_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6247_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6247_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6247_variant_DataContents);
*variablenode_ns_3_i_6247_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6247_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "SpecificPressureMaximum");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Pressure in front of the screw tip");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6247),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "SpecificPressureMaximum"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6247_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6247), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_270_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6247)
);
}

/* EngineeringUnits - ns=3;i=6479 */

static UA_StatusCode function_namespace_euromap77_generated_271_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_3_i_6479_EUInformation_0, 1);
UA_init(variablenode_ns_3_i_6479_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_3_i_6479_EUInformation_0->namespaceUri = UA_STRING("");
variablenode_ns_3_i_6479_EUInformation_0->unitId = (UA_Int32) -1;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6479_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6479),
UA_NODEID_NUMERIC(ns[3], 6247),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6479), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_271_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6479)
);
}

/* EURange - ns=3;i=6248 */

static UA_StatusCode function_namespace_euromap77_generated_272_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6248),
UA_NODEID_NUMERIC(ns[3], 6247),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6248), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_272_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6248)
);
}

/* CavityPressureMaximum - ns=3;i=6129 */

static UA_StatusCode function_namespace_euromap77_generated_273_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6129_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6129_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6129_variant_DataContents);
*variablenode_ns_3_i_6129_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6129_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "CavityPressureMaximum");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Maximum pressure during the injection process in the cavity or mould");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6129),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "CavityPressureMaximum"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6129_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6129), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_273_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6129)
);
}

/* EngineeringUnits - ns=3;i=6448 */

static UA_StatusCode function_namespace_euromap77_generated_274_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_3_i_6448_EUInformation_0, 1);
UA_init(variablenode_ns_3_i_6448_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_3_i_6448_EUInformation_0->namespaceUri = UA_STRING("");
variablenode_ns_3_i_6448_EUInformation_0->unitId = (UA_Int32) -1;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6448_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6448),
UA_NODEID_NUMERIC(ns[3], 6129),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6448), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_274_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6448)
);
}

/* EURange - ns=3;i=6130 */

static UA_StatusCode function_namespace_euromap77_generated_275_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6130),
UA_NODEID_NUMERIC(ns[3], 6129),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6130), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_275_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6130)
);
}

/* TransferStroke - ns=3;i=6071 */

static UA_StatusCode function_namespace_euromap77_generated_276_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6071_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6071_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6071_variant_DataContents);
*variablenode_ns_3_i_6071_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6071_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "TransferStroke");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Switch-over point to the holding pressure via stroke");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6071),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "TransferStroke"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6071_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6071), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_276_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6071)
);
}

/* EngineeringUnits - ns=3;i=6083 */

static UA_StatusCode function_namespace_euromap77_generated_277_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6083),
UA_NODEID_NUMERIC(ns[3], 6071),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6083), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_277_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6083)
);
}

/* EURange - ns=3;i=6072 */

static UA_StatusCode function_namespace_euromap77_generated_278_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6072),
UA_NODEID_NUMERIC(ns[3], 6071),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6072), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_278_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6072)
);
}

/* DecompressionVolumeAfterPlastification - ns=3;i=6131 */

static UA_StatusCode function_namespace_euromap77_generated_279_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_3_i_6131_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_3_i_6131_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_3_i_6131_variant_DataContents);
*variablenode_ns_3_i_6131_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6131_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "DecompressionVolumeAfterPlastification");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Decompression after plastification is the movement of the screw in the opposite direction to injection");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6131),
UA_NODEID_NUMERIC(ns[3], 1039),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "DecompressionVolumeAfterPlastification"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_3_i_6131_variant_DataContents);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6131), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 80), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_279_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6131)
);
}

/* EngineeringUnits - ns=3;i=6449 */

static UA_StatusCode function_namespace_euromap77_generated_280_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_3_i_6449_EUInformation_0, 1);
UA_init(variablenode_ns_3_i_6449_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_3_i_6449_EUInformation_0->namespaceUri = UA_STRING("");
variablenode_ns_3_i_6449_EUInformation_0->unitId = (UA_Int32) -1;
UA_Variant_setScalar(&attr.value, variablenode_ns_3_i_6449_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6449),
UA_NODEID_NUMERIC(ns[3], 6131),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6449), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_280_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6449)
);
}

/* EURange - ns=3;i=6132 */

static UA_StatusCode function_namespace_euromap77_generated_281_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 884);
attr.displayName = UA_LOCALIZEDTEXT("", "EURange");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[3], 6132),
UA_NODEID_NUMERIC(ns[3], 6131),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[3], 6132), UA_NODEID_NUMERIC(ns[0], 37), UA_EXPANDEDNODEID_NUMERIC(ns[0], 78), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap77_generated_281_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[3], 6132)
);
}

UA_StatusCode namespace_euromap77_generated(UA_Server *server) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
/* Use namespace ids generated by the server */
UA_UInt16 ns[4];
ns[0] = UA_Server_addNamespace(server, "http://opcfoundation.org/UA/");
ns[1] = UA_Server_addNamespace(server, "http://opcfoundation.org/UA/DI/");
ns[2] = UA_Server_addNamespace(server, "http://www.euromap.org/euromap83/");
ns[3] = UA_Server_addNamespace(server, "http://www.euromap.org/euromap77/");
bool dummy = (
!(retVal = function_namespace_euromap77_generated_0_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_1_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_2_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_3_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_4_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_5_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_6_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_7_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_8_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_9_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_10_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_11_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_12_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_13_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_14_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_15_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_16_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_17_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_18_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_19_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_20_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_21_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_22_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_23_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_24_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_25_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_26_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_27_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_28_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_29_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_30_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_31_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_32_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_33_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_34_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_35_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_36_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_37_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_38_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_39_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_40_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_41_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_42_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_43_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_44_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_45_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_46_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_47_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_48_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_49_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_50_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_51_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_52_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_53_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_54_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_55_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_56_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_57_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_58_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_59_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_60_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_61_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_62_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_63_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_64_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_65_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_66_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_67_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_68_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_69_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_70_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_71_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_72_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_73_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_74_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_75_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_76_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_77_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_78_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_79_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_80_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_81_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_82_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_83_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_84_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_85_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_86_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_87_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_88_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_89_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_90_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_91_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_92_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_93_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_94_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_95_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_96_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_97_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_98_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_99_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_100_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_101_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_102_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_103_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_104_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_105_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_106_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_107_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_108_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_109_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_110_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_111_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_112_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_113_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_114_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_115_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_116_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_117_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_118_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_119_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_120_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_121_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_122_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_123_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_124_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_125_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_126_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_127_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_128_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_129_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_130_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_131_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_132_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_133_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_134_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_135_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_136_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_137_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_138_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_139_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_140_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_141_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_142_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_143_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_144_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_145_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_146_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_147_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_148_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_149_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_150_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_151_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_152_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_153_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_154_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_155_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_156_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_157_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_158_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_159_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_160_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_161_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_162_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_163_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_164_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_165_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_166_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_167_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_168_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_169_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_170_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_171_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_172_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_173_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_174_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_175_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_176_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_177_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_178_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_179_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_180_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_181_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_182_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_183_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_184_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_185_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_186_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_187_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_188_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_189_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_190_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_191_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_192_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_193_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_194_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_195_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_196_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_197_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_198_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_199_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_200_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_201_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_202_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_203_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_204_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_205_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_206_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_207_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_208_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_209_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_210_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_211_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_212_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_213_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_214_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_215_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_216_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_217_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_218_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_219_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_220_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_221_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_222_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_223_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_224_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_225_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_226_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_227_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_228_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_229_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_230_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_231_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_232_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_233_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_234_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_235_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_236_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_237_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_238_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_239_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_240_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_241_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_242_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_243_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_244_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_245_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_246_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_247_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_248_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_249_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_250_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_251_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_252_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_253_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_254_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_255_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_256_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_257_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_258_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_259_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_260_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_261_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_262_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_263_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_264_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_265_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_266_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_267_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_268_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_269_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_270_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_271_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_272_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_273_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_274_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_275_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_276_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_277_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_278_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_279_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_280_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_281_begin(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_281_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_280_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_279_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_278_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_277_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_276_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_275_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_274_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_273_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_272_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_271_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_270_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_269_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_268_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_267_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_266_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_265_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_264_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_263_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_262_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_261_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_260_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_259_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_258_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_257_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_256_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_255_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_254_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_253_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_252_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_251_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_250_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_249_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_248_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_247_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_246_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_245_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_244_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_243_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_242_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_241_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_240_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_239_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_238_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_237_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_236_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_235_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_234_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_233_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_232_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_231_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_230_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_229_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_228_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_227_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_226_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_225_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_224_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_223_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_222_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_221_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_220_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_219_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_218_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_217_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_216_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_215_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_214_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_213_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_212_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_211_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_210_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_209_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_208_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_207_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_206_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_205_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_204_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_203_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_202_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_201_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_200_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_199_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_198_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_197_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_196_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_195_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_194_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_193_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_192_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_191_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_190_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_189_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_188_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_187_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_186_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_185_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_184_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_183_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_182_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_181_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_180_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_179_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_178_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_177_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_176_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_175_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_174_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_173_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_172_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_171_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_170_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_169_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_168_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_167_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_166_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_165_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_164_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_163_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_162_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_161_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_160_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_159_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_158_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_157_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_156_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_155_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_154_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_153_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_152_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_151_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_150_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_149_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_148_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_147_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_146_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_145_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_144_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_143_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_142_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_141_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_140_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_139_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_138_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_137_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_136_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_135_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_134_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_133_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_132_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_131_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_130_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_129_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_128_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_127_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_126_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_125_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_124_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_123_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_122_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_121_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_120_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_119_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_118_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_117_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_116_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_115_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_114_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_113_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_112_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_111_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_110_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_109_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_108_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_107_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_106_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_105_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_104_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_103_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_102_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_101_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_100_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_99_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_98_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_97_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_96_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_95_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_94_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_93_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_92_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_91_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_90_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_89_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_88_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_87_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_86_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_85_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_84_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_83_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_82_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_81_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_80_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_79_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_78_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_77_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_76_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_75_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_74_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_73_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_72_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_71_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_70_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_69_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_68_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_67_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_66_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_65_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_64_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_63_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_62_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_61_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_60_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_59_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_58_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_57_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_56_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_55_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_54_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_53_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_52_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_51_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_50_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_49_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_48_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_47_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_46_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_45_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_44_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_43_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_42_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_41_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_40_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_39_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_38_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_37_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_36_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_35_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_34_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_33_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_32_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_31_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_30_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_29_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_28_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_27_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_26_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_25_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_24_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_23_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_22_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_21_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_20_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_19_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_18_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_17_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_16_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_15_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_14_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_13_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_12_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_11_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_10_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_9_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_8_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_7_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_6_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_5_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_4_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_3_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_2_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_1_finish(server, ns)) &&
!(retVal = function_namespace_euromap77_generated_0_finish(server, ns)) 
); (void)(dummy);
return retVal;
}
