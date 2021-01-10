/* WARNING: This is a generated file.
 * Any manual changes will be overwritten. */

#include "namespace_euromap_model_generated.h"


/* IMM_ManufacturerOEM_012345678 - ns=4;i=1000 */

static UA_StatusCode function_namespace_euromap_model_generated_0_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "IMM_ManufacturerOEM_012345678");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[4], 1000),
UA_NODEID_NUMERIC(ns[1], 5001),
UA_NODEID_NUMERIC(ns[0], 35),
UA_QUALIFIEDNAME(ns[4], "IMM_ManufacturerOEM_012345678"),
UA_NODEID_NUMERIC(ns[3], 1007),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[4], 1000), UA_NODEID_NUMERIC(ns[0], 41), UA_EXPANDEDNODEID_NUMERIC(ns[2], 1011), true);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[4], 1000), UA_NODEID_NUMERIC(ns[0], 41), UA_EXPANDEDNODEID_NUMERIC(ns[2], 1038), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_0_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1000)
);
}

/* PowerUnits - ns=4;i=1008 */

static UA_StatusCode function_namespace_euromap_model_generated_1_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "PowerUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[4], 1008),
UA_NODEID_NUMERIC(ns[4], 1000),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "PowerUnits"),
UA_NODEID_NUMERIC(ns[2], 1049),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_1_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1008)
);
}

/* PowerUnit_1 - ns=4;i=1109 */

static UA_StatusCode function_namespace_euromap_model_generated_2_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "PowerUnit_1");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[4], 1109),
UA_NODEID_NUMERIC(ns[4], 1008),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "PowerUnit_1"),
UA_NODEID_NUMERIC(ns[2], 1035),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_2_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1109)
);
}

/* Id - ns=4;i=1110 */

static UA_StatusCode function_namespace_euromap_model_generated_3_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_4_i_1110_variant_DataContents =  UA_String_new();
if (!variablenode_ns_4_i_1110_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_4_i_1110_variant_DataContents);
*variablenode_ns_4_i_1110_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1110_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "Id");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Id of the PowerUnit");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1110),
UA_NODEID_NUMERIC(ns[4], 1109),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "Id"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_4_i_1110_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_3_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1110)
);
}

/* Index - ns=4;i=1111 */

static UA_StatusCode function_namespace_euromap_model_generated_4_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
UA_UInt32 *variablenode_ns_4_i_1111_variant_DataContents =  UA_UInt32_new();
if (!variablenode_ns_4_i_1111_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt32_init(variablenode_ns_4_i_1111_variant_DataContents);
*variablenode_ns_4_i_1111_variant_DataContents = (UA_UInt32) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1111_variant_DataContents, &UA_TYPES[UA_TYPES_UINT32]);
attr.displayName = UA_LOCALIZEDTEXT("", "Index");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Number of the power unit");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1111),
UA_NODEID_NUMERIC(ns[4], 1109),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "Index"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt32_delete(variablenode_ns_4_i_1111_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_4_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1111)
);
}

/* IsPresent - ns=4;i=1112 */

static UA_StatusCode function_namespace_euromap_model_generated_5_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_4_i_1112_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_4_i_1112_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_4_i_1112_variant_DataContents);
*variablenode_ns_4_i_1112_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1112_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "IsPresent");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Indication if the power unit is physically present and connected");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1112),
UA_NODEID_NUMERIC(ns[4], 1109),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "IsPresent"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_4_i_1112_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_5_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1112)
);
}

/* PowerOn - ns=4;i=1113 */

static UA_StatusCode function_namespace_euromap_model_generated_6_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_4_i_1113_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_4_i_1113_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_4_i_1113_variant_DataContents);
*variablenode_ns_4_i_1113_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1113_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "PowerOn");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Indication if the PowerUnit is switched on");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1113),
UA_NODEID_NUMERIC(ns[4], 1109),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "PowerOn"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_4_i_1113_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_6_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1113)
);
}

/* ActualPressure - ns=4;i=1119 */

static UA_StatusCode function_namespace_euromap_model_generated_7_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_4_i_1119_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_4_i_1119_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_4_i_1119_variant_DataContents);
*variablenode_ns_4_i_1119_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1119_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "ActualPressure");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Current pressure of the hydraulic unit");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1119),
UA_NODEID_NUMERIC(ns[4], 1109),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "ActualPressure"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_4_i_1119_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_7_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1119)
);
}

/* EngineeringUnits - ns=4;i=1120 */

static UA_StatusCode function_namespace_euromap_model_generated_8_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_4_i_1120_EUInformation_0, 1);
UA_init(variablenode_ns_4_i_1120_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_4_i_1120_EUInformation_0->namespaceUri = UA_STRING("http://www.opcfoundation.org/UA/units/un/cefact");
variablenode_ns_4_i_1120_EUInformation_0->unitId = (UA_Int32) 4342098;
variablenode_ns_4_i_1120_EUInformation_0->displayName = UA_LOCALIZEDTEXT("", "bar");
variablenode_ns_4_i_1120_EUInformation_0->description = UA_LOCALIZEDTEXT("", "bar [unit of pressure]");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1120_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1120),
UA_NODEID_NUMERIC(ns[4], 1119),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_8_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1120)
);
}

/* EURange - ns=4;i=1121 */

static UA_StatusCode function_namespace_euromap_model_generated_9_begin(UA_Server *server, UA_UInt16* ns) {
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
UA_NODEID_NUMERIC(ns[4], 1121),
UA_NODEID_NUMERIC(ns[4], 1119),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_9_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1121)
);
}

/* ActualTemperature - ns=4;i=1122 */

static UA_StatusCode function_namespace_euromap_model_generated_10_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_4_i_1122_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_4_i_1122_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_4_i_1122_variant_DataContents);
*variablenode_ns_4_i_1122_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1122_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "ActualTemperature");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Current temperature of the PowerUnit");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1122),
UA_NODEID_NUMERIC(ns[4], 1109),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "ActualTemperature"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_4_i_1122_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_10_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1122)
);
}

/* EngineeringUnits - ns=4;i=1123 */

static UA_StatusCode function_namespace_euromap_model_generated_11_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_4_i_1123_EUInformation_0, 1);
UA_init(variablenode_ns_4_i_1123_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_4_i_1123_EUInformation_0->namespaceUri = UA_STRING("http://www.opcfoundation.org/UA/units/un/cefact");
variablenode_ns_4_i_1123_EUInformation_0->unitId = (UA_Int32) 4408652;
variablenode_ns_4_i_1123_EUInformation_0->displayName = UA_LOCALIZEDTEXT("", "°C");
variablenode_ns_4_i_1123_EUInformation_0->description = UA_LOCALIZEDTEXT("", "degree Celsius");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1123_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1123),
UA_NODEID_NUMERIC(ns[4], 1122),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_11_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1123)
);
}

/* EURange - ns=4;i=1124 */

static UA_StatusCode function_namespace_euromap_model_generated_12_begin(UA_Server *server, UA_UInt16* ns) {
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
UA_NODEID_NUMERIC(ns[4], 1124),
UA_NODEID_NUMERIC(ns[4], 1122),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_12_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1124)
);
}

/* PowerUnit_2 - ns=4;i=1114 */

static UA_StatusCode function_namespace_euromap_model_generated_13_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "PowerUnit_2");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[4], 1114),
UA_NODEID_NUMERIC(ns[4], 1008),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "PowerUnit_2"),
UA_NODEID_NUMERIC(ns[2], 1035),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_13_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1114)
);
}

/* IsPresent - ns=4;i=1117 */

static UA_StatusCode function_namespace_euromap_model_generated_14_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_4_i_1117_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_4_i_1117_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_4_i_1117_variant_DataContents);
*variablenode_ns_4_i_1117_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1117_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "IsPresent");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Indication if the power unit is physically present and connected");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1117),
UA_NODEID_NUMERIC(ns[4], 1114),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "IsPresent"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_4_i_1117_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_14_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1117)
);
}

/* ActualPressure - ns=4;i=1128 */

static UA_StatusCode function_namespace_euromap_model_generated_15_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_4_i_1128_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_4_i_1128_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_4_i_1128_variant_DataContents);
*variablenode_ns_4_i_1128_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1128_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "ActualPressure");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Current pressure of the hydraulic unit");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1128),
UA_NODEID_NUMERIC(ns[4], 1114),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "ActualPressure"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_4_i_1128_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_15_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1128)
);
}

/* EngineeringUnits - ns=4;i=1129 */

static UA_StatusCode function_namespace_euromap_model_generated_16_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_4_i_1129_EUInformation_0, 1);
UA_init(variablenode_ns_4_i_1129_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_4_i_1129_EUInformation_0->namespaceUri = UA_STRING("http://www.opcfoundation.org/UA/units/un/cefact");
variablenode_ns_4_i_1129_EUInformation_0->unitId = (UA_Int32) 4342098;
variablenode_ns_4_i_1129_EUInformation_0->displayName = UA_LOCALIZEDTEXT("", "bar");
variablenode_ns_4_i_1129_EUInformation_0->description = UA_LOCALIZEDTEXT("", "bar [unit of pressure]");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1129_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1129),
UA_NODEID_NUMERIC(ns[4], 1128),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_16_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1129)
);
}

/* EURange - ns=4;i=1130 */

static UA_StatusCode function_namespace_euromap_model_generated_17_begin(UA_Server *server, UA_UInt16* ns) {
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
UA_NODEID_NUMERIC(ns[4], 1130),
UA_NODEID_NUMERIC(ns[4], 1128),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_17_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1130)
);
}

/* PowerOn - ns=4;i=1118 */

static UA_StatusCode function_namespace_euromap_model_generated_18_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_4_i_1118_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_4_i_1118_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_4_i_1118_variant_DataContents);
*variablenode_ns_4_i_1118_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1118_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "PowerOn");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Indication if the PowerUnit is switched on");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1118),
UA_NODEID_NUMERIC(ns[4], 1114),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "PowerOn"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_4_i_1118_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_18_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1118)
);
}

/* Index - ns=4;i=1116 */

static UA_StatusCode function_namespace_euromap_model_generated_19_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
UA_UInt32 *variablenode_ns_4_i_1116_variant_DataContents =  UA_UInt32_new();
if (!variablenode_ns_4_i_1116_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt32_init(variablenode_ns_4_i_1116_variant_DataContents);
*variablenode_ns_4_i_1116_variant_DataContents = (UA_UInt32) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1116_variant_DataContents, &UA_TYPES[UA_TYPES_UINT32]);
attr.displayName = UA_LOCALIZEDTEXT("", "Index");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Number of the power unit");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1116),
UA_NODEID_NUMERIC(ns[4], 1114),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "Index"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt32_delete(variablenode_ns_4_i_1116_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_19_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1116)
);
}

/* ActualTemperature - ns=4;i=1125 */

static UA_StatusCode function_namespace_euromap_model_generated_20_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_4_i_1125_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_4_i_1125_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_4_i_1125_variant_DataContents);
*variablenode_ns_4_i_1125_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1125_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "ActualTemperature");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Current temperature of the PowerUnit");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1125),
UA_NODEID_NUMERIC(ns[4], 1114),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "ActualTemperature"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_4_i_1125_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_20_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1125)
);
}

/* EURange - ns=4;i=1127 */

static UA_StatusCode function_namespace_euromap_model_generated_21_begin(UA_Server *server, UA_UInt16* ns) {
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
UA_NODEID_NUMERIC(ns[4], 1127),
UA_NODEID_NUMERIC(ns[4], 1125),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_21_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1127)
);
}

/* EngineeringUnits - ns=4;i=1126 */

static UA_StatusCode function_namespace_euromap_model_generated_22_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_4_i_1126_EUInformation_0, 1);
UA_init(variablenode_ns_4_i_1126_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_4_i_1126_EUInformation_0->namespaceUri = UA_STRING("http://www.opcfoundation.org/UA/units/un/cefact");
variablenode_ns_4_i_1126_EUInformation_0->unitId = (UA_Int32) 4408652;
variablenode_ns_4_i_1126_EUInformation_0->displayName = UA_LOCALIZEDTEXT("", "°C");
variablenode_ns_4_i_1126_EUInformation_0->description = UA_LOCALIZEDTEXT("", "degree Celsius");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1126_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1126),
UA_NODEID_NUMERIC(ns[4], 1125),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_22_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1126)
);
}

/* Id - ns=4;i=1115 */

static UA_StatusCode function_namespace_euromap_model_generated_23_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_4_i_1115_variant_DataContents =  UA_String_new();
if (!variablenode_ns_4_i_1115_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_4_i_1115_variant_DataContents);
*variablenode_ns_4_i_1115_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1115_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "Id");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Id of the PowerUnit");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1115),
UA_NODEID_NUMERIC(ns[4], 1114),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "Id"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_4_i_1115_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_23_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1115)
);
}

/* NodeVersion - ns=4;i=1036 */

static UA_StatusCode function_namespace_euromap_model_generated_24_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_4_i_1036_variant_DataContents =  UA_String_new();
if (!variablenode_ns_4_i_1036_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_4_i_1036_variant_DataContents);
*variablenode_ns_4_i_1036_variant_DataContents = UA_STRING_ALLOC("NaN");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1036_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "NodeVersion");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1036),
UA_NODEID_NUMERIC(ns[4], 1008),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "NodeVersion"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_4_i_1036_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_24_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1036)
);
}

/* InjectionUnits - ns=4;i=1001 */

static UA_StatusCode function_namespace_euromap_model_generated_25_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "InjectionUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[4], 1001),
UA_NODEID_NUMERIC(ns[4], 1000),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "InjectionUnits"),
UA_NODEID_NUMERIC(ns[3], 1016),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_25_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1001)
);
}

/* InjectionUnit_1 - ns=4;i=1052 */

static UA_StatusCode function_namespace_euromap_model_generated_26_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "InjectionUnit_1");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[4], 1052),
UA_NODEID_NUMERIC(ns[4], 1001),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "InjectionUnit_1"),
UA_NODEID_NUMERIC(ns[3], 1028),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_26_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1052)
);
}

/* BarrelId - ns=4;i=1053 */

static UA_StatusCode function_namespace_euromap_model_generated_27_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_4_i_1053_variant_DataContents =  UA_String_new();
if (!variablenode_ns_4_i_1053_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_4_i_1053_variant_DataContents);
*variablenode_ns_4_i_1053_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1053_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "BarrelId");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Id (e.g. serial number) of the barrel");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1053),
UA_NODEID_NUMERIC(ns[4], 1052),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[3], "BarrelId"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_4_i_1053_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_27_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1053)
);
}

/* TemperatureZones - ns=4;i=1057 */

static UA_StatusCode function_namespace_euromap_model_generated_28_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "TemperatureZones");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[4], 1057),
UA_NODEID_NUMERIC(ns[4], 1052),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "TemperatureZones"),
UA_NODEID_NUMERIC(ns[2], 1055),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_28_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1057)
);
}

/* NodeVersion - ns=4;i=1058 */

static UA_StatusCode function_namespace_euromap_model_generated_29_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_4_i_1058_variant_DataContents =  UA_String_new();
if (!variablenode_ns_4_i_1058_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_4_i_1058_variant_DataContents);
*variablenode_ns_4_i_1058_variant_DataContents = UA_STRING_ALLOC("NaN");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1058_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "NodeVersion");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1058),
UA_NODEID_NUMERIC(ns[4], 1057),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "NodeVersion"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_4_i_1058_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_29_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1058)
);
}

/* BarrelTemperatureZone_1 - ns=4;i=1070 */

static UA_StatusCode function_namespace_euromap_model_generated_30_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "BarrelTemperatureZone_1");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[4], 1070),
UA_NODEID_NUMERIC(ns[4], 1057),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "BarrelTemperatureZone_1"),
UA_NODEID_NUMERIC(ns[2], 1001),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_30_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1070)
);
}

/* NominalTemperature - ns=4;i=1076 */

static UA_StatusCode function_namespace_euromap_model_generated_31_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_4_i_1076_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_4_i_1076_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_4_i_1076_variant_DataContents);
*variablenode_ns_4_i_1076_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1076_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "NominalTemperature");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Nominal temperature (absolute value)");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1076),
UA_NODEID_NUMERIC(ns[4], 1070),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "NominalTemperature"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_4_i_1076_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_31_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1076)
);
}

/* EURange - ns=4;i=1080 */

static UA_StatusCode function_namespace_euromap_model_generated_32_begin(UA_Server *server, UA_UInt16* ns) {
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
UA_NODEID_NUMERIC(ns[4], 1080),
UA_NODEID_NUMERIC(ns[4], 1076),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_32_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1080)
);
}

/* EngineeringUnits - ns=4;i=1079 */

static UA_StatusCode function_namespace_euromap_model_generated_33_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_4_i_1079_EUInformation_0, 1);
UA_init(variablenode_ns_4_i_1079_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_4_i_1079_EUInformation_0->namespaceUri = UA_STRING("http://www.opcfoundation.org/UA/units/un/cefact");
variablenode_ns_4_i_1079_EUInformation_0->unitId = (UA_Int32) 4408652;
variablenode_ns_4_i_1079_EUInformation_0->displayName = UA_LOCALIZEDTEXT("", "°C");
variablenode_ns_4_i_1079_EUInformation_0->description = UA_LOCALIZEDTEXT("", "degree Celsius");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1079_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1079),
UA_NODEID_NUMERIC(ns[4], 1076),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_33_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1079)
);
}

/* ActualTemperature - ns=4;i=1071 */

static UA_StatusCode function_namespace_euromap_model_generated_34_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_4_i_1071_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_4_i_1071_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_4_i_1071_variant_DataContents);
*variablenode_ns_4_i_1071_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1071_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "ActualTemperature");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Current temperature of the zone");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1071),
UA_NODEID_NUMERIC(ns[4], 1070),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "ActualTemperature"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_4_i_1071_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_34_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1071)
);
}

/* EURange - ns=4;i=1078 */

static UA_StatusCode function_namespace_euromap_model_generated_35_begin(UA_Server *server, UA_UInt16* ns) {
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
UA_NODEID_NUMERIC(ns[4], 1078),
UA_NODEID_NUMERIC(ns[4], 1071),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_35_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1078)
);
}

/* EngineeringUnits - ns=4;i=1077 */

static UA_StatusCode function_namespace_euromap_model_generated_36_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_4_i_1077_EUInformation_0, 1);
UA_init(variablenode_ns_4_i_1077_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_4_i_1077_EUInformation_0->namespaceUri = UA_STRING("http://www.opcfoundation.org/UA/units/un/cefact");
variablenode_ns_4_i_1077_EUInformation_0->unitId = (UA_Int32) 4408652;
variablenode_ns_4_i_1077_EUInformation_0->displayName = UA_LOCALIZEDTEXT("", "°C");
variablenode_ns_4_i_1077_EUInformation_0->description = UA_LOCALIZEDTEXT("", "degree Celsius");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1077_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1077),
UA_NODEID_NUMERIC(ns[4], 1071),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_36_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1077)
);
}

/* ControlMode - ns=4;i=1072 */

static UA_StatusCode function_namespace_euromap_model_generated_37_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[2], 3001);
UA_Int32 *variablenode_ns_4_i_1072_variant_DataContents =  UA_Int32_new();
if (!variablenode_ns_4_i_1072_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Int32_init(variablenode_ns_4_i_1072_variant_DataContents);
*variablenode_ns_4_i_1072_variant_DataContents = (UA_Int32) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1072_variant_DataContents, &UA_TYPES[UA_TYPES_INT32]);
attr.displayName = UA_LOCALIZEDTEXT("", "ControlMode");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Indication how the temperature is currently controlled");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1072),
UA_NODEID_NUMERIC(ns[4], 1070),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "ControlMode"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Int32_delete(variablenode_ns_4_i_1072_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_37_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1072)
);
}

/* Index - ns=4;i=1073 */

static UA_StatusCode function_namespace_euromap_model_generated_38_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
UA_UInt32 *variablenode_ns_4_i_1073_variant_DataContents =  UA_UInt32_new();
if (!variablenode_ns_4_i_1073_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt32_init(variablenode_ns_4_i_1073_variant_DataContents);
*variablenode_ns_4_i_1073_variant_DataContents = (UA_UInt32) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1073_variant_DataContents, &UA_TYPES[UA_TYPES_UINT32]);
attr.displayName = UA_LOCALIZEDTEXT("", "Index");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Number of the zone");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1073),
UA_NODEID_NUMERIC(ns[4], 1070),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "Index"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt32_delete(variablenode_ns_4_i_1073_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_38_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1073)
);
}

/* IsPresent - ns=4;i=1074 */

static UA_StatusCode function_namespace_euromap_model_generated_39_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_4_i_1074_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_4_i_1074_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_4_i_1074_variant_DataContents);
*variablenode_ns_4_i_1074_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1074_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "IsPresent");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Indication if the temperature zone is physically present and connected");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1074),
UA_NODEID_NUMERIC(ns[4], 1070),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "IsPresent"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_4_i_1074_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_39_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1074)
);
}

/* Name - ns=4;i=1075 */

static UA_StatusCode function_namespace_euromap_model_generated_40_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_4_i_1075_variant_DataContents =  UA_String_new();
if (!variablenode_ns_4_i_1075_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_4_i_1075_variant_DataContents);
*variablenode_ns_4_i_1075_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1075_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "Name");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Name of the zone");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1075),
UA_NODEID_NUMERIC(ns[4], 1070),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "Name"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_4_i_1075_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_40_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1075)
);
}

/* Position - ns=4;i=1081 */

static UA_StatusCode function_namespace_euromap_model_generated_41_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
UA_UInt32 *variablenode_ns_4_i_1081_variant_DataContents =  UA_UInt32_new();
if (!variablenode_ns_4_i_1081_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt32_init(variablenode_ns_4_i_1081_variant_DataContents);
*variablenode_ns_4_i_1081_variant_DataContents = (UA_UInt32) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1081_variant_DataContents, &UA_TYPES[UA_TYPES_UINT32]);
attr.displayName = UA_LOCALIZEDTEXT("", "Position");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Location of the temperature zone on a barrel. Counting starts with 1 beginning from the feeding. The highest position is at the nozzle.");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1081),
UA_NODEID_NUMERIC(ns[4], 1070),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "Position"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt32_delete(variablenode_ns_4_i_1081_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_41_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1081)
);
}

/* Index - ns=4;i=1054 */

static UA_StatusCode function_namespace_euromap_model_generated_42_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
UA_UInt32 *variablenode_ns_4_i_1054_variant_DataContents =  UA_UInt32_new();
if (!variablenode_ns_4_i_1054_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt32_init(variablenode_ns_4_i_1054_variant_DataContents);
*variablenode_ns_4_i_1054_variant_DataContents = (UA_UInt32) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1054_variant_DataContents, &UA_TYPES[UA_TYPES_UINT32]);
attr.displayName = UA_LOCALIZEDTEXT("", "Index");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Number of the injection unit");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1054),
UA_NODEID_NUMERIC(ns[4], 1052),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[3], "Index"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt32_delete(variablenode_ns_4_i_1054_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_42_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1054)
);
}

/* InProduction - ns=4;i=1055 */

static UA_StatusCode function_namespace_euromap_model_generated_43_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_4_i_1055_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_4_i_1055_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_4_i_1055_variant_DataContents);
*variablenode_ns_4_i_1055_variant_DataContents = (UA_Boolean) true;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1055_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "InProduction");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "information if the injection unit is used in the current running production");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1055),
UA_NODEID_NUMERIC(ns[4], 1052),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[3], "InProduction"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_4_i_1055_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_43_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1055)
);
}

/* IsPresent - ns=4;i=1056 */

static UA_StatusCode function_namespace_euromap_model_generated_44_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_4_i_1056_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_4_i_1056_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_4_i_1056_variant_DataContents);
*variablenode_ns_4_i_1056_variant_DataContents = (UA_Boolean) true;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1056_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "IsPresent");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Information if the injection unit is physically installed on the injection machines");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1056),
UA_NODEID_NUMERIC(ns[4], 1052),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[3], "IsPresent"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_4_i_1056_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_44_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1056)
);
}

/* NodeVersion - ns=4;i=1009 */

static UA_StatusCode function_namespace_euromap_model_generated_45_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_4_i_1009_variant_DataContents =  UA_String_new();
if (!variablenode_ns_4_i_1009_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_4_i_1009_variant_DataContents);
*variablenode_ns_4_i_1009_variant_DataContents = UA_STRING_ALLOC("NaN");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1009_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "NodeVersion");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1009),
UA_NODEID_NUMERIC(ns[4], 1001),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "NodeVersion"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_4_i_1009_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_45_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1009)
);
}

/* MachineInformation - ns=4;i=1003 */

static UA_StatusCode function_namespace_euromap_model_generated_46_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "MachineInformation");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[4], 1003),
UA_NODEID_NUMERIC(ns[4], 1000),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "MachineInformation"),
UA_NODEID_NUMERIC(ns[2], 1009),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_46_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1003)
);
}

/* ControllerName - ns=4;i=1014 */

static UA_StatusCode function_namespace_euromap_model_generated_47_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_4_i_1014_variant_DataContents =  UA_String_new();
if (!variablenode_ns_4_i_1014_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_4_i_1014_variant_DataContents);
*variablenode_ns_4_i_1014_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1014_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "ControllerName");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Name of the machine controller");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1014),
UA_NODEID_NUMERIC(ns[4], 1003),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "ControllerName"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_4_i_1014_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_47_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1014)
);
}

/* DeviceManual - ns=4;i=1015 */

static UA_StatusCode function_namespace_euromap_model_generated_48_begin(UA_Server *server, UA_UInt16* ns) {
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
UA_NODEID_NUMERIC(ns[4], 1015),
UA_NODEID_NUMERIC(ns[4], 1003),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[1], "DeviceManual"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_48_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1015)
);
}

/* DeviceRevision - ns=4;i=1016 */

static UA_StatusCode function_namespace_euromap_model_generated_49_begin(UA_Server *server, UA_UInt16* ns) {
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
UA_NODEID_NUMERIC(ns[4], 1016),
UA_NODEID_NUMERIC(ns[4], 1003),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[1], "DeviceRevision"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_49_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1016)
);
}

/* HardwareRevision - ns=4;i=1017 */

static UA_StatusCode function_namespace_euromap_model_generated_50_begin(UA_Server *server, UA_UInt16* ns) {
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
UA_NODEID_NUMERIC(ns[4], 1017),
UA_NODEID_NUMERIC(ns[4], 1003),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[1], "HardwareRevision"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_50_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1017)
);
}

/* Manufacturer - ns=4;i=1018 */

static UA_StatusCode function_namespace_euromap_model_generated_51_begin(UA_Server *server, UA_UInt16* ns) {
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
UA_NODEID_NUMERIC(ns[4], 1018),
UA_NODEID_NUMERIC(ns[4], 1003),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[1], "Manufacturer"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_51_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1018)
);
}

/* Model - ns=4;i=1019 */

static UA_StatusCode function_namespace_euromap_model_generated_52_begin(UA_Server *server, UA_UInt16* ns) {
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
UA_NODEID_NUMERIC(ns[4], 1019),
UA_NODEID_NUMERIC(ns[4], 1003),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[1], "Model"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_52_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1019)
);
}

/* SoftwareRevision - ns=4;i=1022 */

static UA_StatusCode function_namespace_euromap_model_generated_53_begin(UA_Server *server, UA_UInt16* ns) {
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
UA_NODEID_NUMERIC(ns[4], 1022),
UA_NODEID_NUMERIC(ns[4], 1003),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[1], "SoftwareRevision"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_53_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1022)
);
}

/* RevisionCounter - ns=4;i=1020 */

static UA_StatusCode function_namespace_euromap_model_generated_54_begin(UA_Server *server, UA_UInt16* ns) {
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
UA_NODEID_NUMERIC(ns[4], 1020),
UA_NODEID_NUMERIC(ns[4], 1003),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[1], "RevisionCounter"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_54_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1020)
);
}

/* SupportedLogbookEvents - ns=4;i=1023 */

static UA_StatusCode function_namespace_euromap_model_generated_55_begin(UA_Server *server, UA_UInt16* ns) {
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
attr.dataType = UA_NODEID_NUMERIC(ns[2], 3009);
attr.displayName = UA_LOCALIZEDTEXT("", "SupportedLogbookEvents");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Information which LogbookEvents are supported by the machine");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1023),
UA_NODEID_NUMERIC(ns[4], 1003),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "SupportedLogbookEvents"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_55_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1023)
);
}

/* SerialNumber - ns=4;i=1021 */

static UA_StatusCode function_namespace_euromap_model_generated_56_begin(UA_Server *server, UA_UInt16* ns) {
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
UA_NODEID_NUMERIC(ns[4], 1021),
UA_NODEID_NUMERIC(ns[4], 1003),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[1], "SerialNumber"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_56_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1021)
);
}

/* MachineConfiguration - ns=4;i=1002 */

static UA_StatusCode function_namespace_euromap_model_generated_57_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "MachineConfiguration");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[4], 1002),
UA_NODEID_NUMERIC(ns[4], 1000),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "MachineConfiguration"),
UA_NODEID_NUMERIC(ns[2], 1016),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_57_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1002)
);
}

/* SetMachineTime - ns=4;i=1011 */

static UA_StatusCode function_namespace_euromap_model_generated_58_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "SetMachineTime");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[4], 1011),
UA_NODEID_NUMERIC(ns[4], 1002),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "SetMachineTime"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_namespace_euromap_model_generated_58_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1011)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* InputArguments - ns=4;i=1037 */

static UA_StatusCode function_namespace_euromap_model_generated_59_begin(UA_Server *server, UA_UInt16* ns) {
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
UA_Argument variablenode_ns_4_i_1037_variant_DataContents[2];

UA_init(&variablenode_ns_4_i_1037_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_4_i_1037_variant_DataContents[0].name = UA_STRING("DateTime");
variablenode_ns_4_i_1037_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[0], 13);
variablenode_ns_4_i_1037_variant_DataContents[0].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_4_i_1037_variant_DataContents[1], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_4_i_1037_variant_DataContents[1].name = UA_STRING("TimeZoneOffset");
variablenode_ns_4_i_1037_variant_DataContents[1].dataType = UA_NODEID_NUMERIC(ns[0], 8912);
variablenode_ns_4_i_1037_variant_DataContents[1].valueRank = (UA_Int32) -1;
UA_Variant_setArray(&attr.value, &variablenode_ns_4_i_1037_variant_DataContents, (UA_Int32) 2, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "InputArguments");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1037),
UA_NODEID_NUMERIC(ns[4], 1011),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "InputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);


return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_59_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1037)
);
}

/* UserMachineName - ns=4;i=1013 */

static UA_StatusCode function_namespace_euromap_model_generated_60_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_4_i_1013_variant_DataContents =  UA_String_new();
if (!variablenode_ns_4_i_1013_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_4_i_1013_variant_DataContents);
*variablenode_ns_4_i_1013_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1013_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "UserMachineName");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Description of the machine given by the machine operator or OPC client");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1013),
UA_NODEID_NUMERIC(ns[4], 1002),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "UserMachineName"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_4_i_1013_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_60_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1013)
);
}

/* TimeZoneOffset - ns=4;i=1012 */

static UA_StatusCode function_namespace_euromap_model_generated_61_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 8912);

UA_STACKARRAY(UA_TimeZoneDataType, variablenode_ns_4_i_1012_TimeZoneDataType_0, 1);
UA_init(variablenode_ns_4_i_1012_TimeZoneDataType_0, &UA_TYPES[UA_TYPES_TIMEZONEDATATYPE]);
variablenode_ns_4_i_1012_TimeZoneDataType_0->offset = (UA_Int16) 0;
variablenode_ns_4_i_1012_TimeZoneDataType_0->daylightSavingInOffset = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1012_TimeZoneDataType_0, &UA_TYPES[UA_TYPES_TIMEZONEDATATYPE]);
attr.displayName = UA_LOCALIZEDTEXT("", "TimeZoneOffset");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Difference of the local time to Coordinated Universal Time (UTC) given by the machine operator or OPC client");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1012),
UA_NODEID_NUMERIC(ns[4], 1002),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "TimeZoneOffset"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_61_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1012)
);
}

/* LocationName - ns=4;i=1010 */

static UA_StatusCode function_namespace_euromap_model_generated_62_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_4_i_1010_variant_DataContents =  UA_String_new();
if (!variablenode_ns_4_i_1010_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_4_i_1010_variant_DataContents);
*variablenode_ns_4_i_1010_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1010_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "LocationName");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Description of the location of the machine given by the machine operator or OPC client");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1010),
UA_NODEID_NUMERIC(ns[4], 1002),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "LocationName"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_4_i_1010_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_62_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1010)
);
}

/* MachineMESStatus - ns=4;i=1005 */

static UA_StatusCode function_namespace_euromap_model_generated_63_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "MachineMESStatus");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[4], 1005),
UA_NODEID_NUMERIC(ns[4], 1000),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "MachineMESStatus"),
UA_NODEID_NUMERIC(ns[2], 1020),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
retVal |= UA_Server_addReference(server, UA_NODEID_NUMERIC(ns[4], 1005), UA_NODEID_NUMERIC(ns[0], 41), UA_EXPANDEDNODEID_NUMERIC(ns[2], 1004), true);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_63_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1005)
);
}

/* ProductionControl - ns=4;i=1028 */

static UA_StatusCode function_namespace_euromap_model_generated_64_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "ProductionControl");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[4], 1028),
UA_NODEID_NUMERIC(ns[4], 1005),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "ProductionControl"),
UA_NODEID_NUMERIC(ns[2], 1017),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_64_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1028)
);
}

/* EnableAutomaticRun - ns=4;i=1043 */

static UA_StatusCode function_namespace_euromap_model_generated_65_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "EnableAutomaticRun");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[4], 1043),
UA_NODEID_NUMERIC(ns[4], 1028),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "EnableAutomaticRun"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_namespace_euromap_model_generated_65_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1043)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* DisableAutomaticRun - ns=4;i=1042 */

static UA_StatusCode function_namespace_euromap_model_generated_66_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "DisableAutomaticRun");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[4], 1042),
UA_NODEID_NUMERIC(ns[4], 1028),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "DisableAutomaticRun"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_namespace_euromap_model_generated_66_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1042)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* ProductionStatus - ns=4;i=1045 */

static UA_StatusCode function_namespace_euromap_model_generated_67_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[2], 3016);
UA_Int32 *variablenode_ns_4_i_1045_variant_DataContents =  UA_Int32_new();
if (!variablenode_ns_4_i_1045_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Int32_init(variablenode_ns_4_i_1045_variant_DataContents);
*variablenode_ns_4_i_1045_variant_DataContents = (UA_Int32) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1045_variant_DataContents, &UA_TYPES[UA_TYPES_INT32]);
attr.displayName = UA_LOCALIZEDTEXT("", "ProductionStatus");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Production status when the machine is in automatic or semi-automatic mode");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1045),
UA_NODEID_NUMERIC(ns[4], 1028),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "ProductionStatus"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Int32_delete(variablenode_ns_4_i_1045_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_67_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1045)
);
}

/* AutomaticRunEnabled - ns=4;i=1041 */

static UA_StatusCode function_namespace_euromap_model_generated_68_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_4_i_1041_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_4_i_1041_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_4_i_1041_variant_DataContents);
*variablenode_ns_4_i_1041_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1041_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "AutomaticRunEnabled");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Indication if semi-automatic and automatic run of the machine is allowed by MES");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1041),
UA_NODEID_NUMERIC(ns[4], 1028),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "AutomaticRunEnabled"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_4_i_1041_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_68_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1041)
);
}

/* ProductionReleasedByMES - ns=4;i=1044 */

static UA_StatusCode function_namespace_euromap_model_generated_69_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_4_i_1044_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_4_i_1044_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_4_i_1044_variant_DataContents);
*variablenode_ns_4_i_1044_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1044_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "ProductionReleasedByMES");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Indication if ProductionStatus may have the value PRODUCTION_4");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1044),
UA_NODEID_NUMERIC(ns[4], 1028),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "ProductionReleasedByMES"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_4_i_1044_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_69_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1044)
);
}

/* SetMESMessage - ns=4;i=1029 */

static UA_StatusCode function_namespace_euromap_model_generated_70_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "SetMESMessage");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[4], 1029),
UA_NODEID_NUMERIC(ns[4], 1005),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "SetMESMessage"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_namespace_euromap_model_generated_70_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1029)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* InputArguments - ns=4;i=1046 */

static UA_StatusCode function_namespace_euromap_model_generated_71_begin(UA_Server *server, UA_UInt16* ns) {
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
UA_Argument variablenode_ns_4_i_1046_variant_DataContents[3];

UA_init(&variablenode_ns_4_i_1046_variant_DataContents[0], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_4_i_1046_variant_DataContents[0].name = UA_STRING("Id");
variablenode_ns_4_i_1046_variant_DataContents[0].dataType = UA_NODEID_NUMERIC(ns[0], 12);
variablenode_ns_4_i_1046_variant_DataContents[0].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_4_i_1046_variant_DataContents[1], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_4_i_1046_variant_DataContents[1].name = UA_STRING("Message");
variablenode_ns_4_i_1046_variant_DataContents[1].dataType = UA_NODEID_NUMERIC(ns[0], 12);
variablenode_ns_4_i_1046_variant_DataContents[1].valueRank = (UA_Int32) -1;

UA_init(&variablenode_ns_4_i_1046_variant_DataContents[2], &UA_TYPES[UA_TYPES_ARGUMENT]);
variablenode_ns_4_i_1046_variant_DataContents[2].name = UA_STRING("Severity");
variablenode_ns_4_i_1046_variant_DataContents[2].dataType = UA_NODEID_NUMERIC(ns[0], 5);
variablenode_ns_4_i_1046_variant_DataContents[2].valueRank = (UA_Int32) -1;
UA_Variant_setArray(&attr.value, &variablenode_ns_4_i_1046_variant_DataContents, (UA_Int32) 3, &UA_TYPES[UA_TYPES_ARGUMENT]);
attr.displayName = UA_LOCALIZEDTEXT("", "InputArguments");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1046),
UA_NODEID_NUMERIC(ns[4], 1029),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "InputArguments"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);



return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_71_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1046)
);
}

/* ClearMESMessage - ns=4;i=1026 */

static UA_StatusCode function_namespace_euromap_model_generated_72_begin(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_MethodAttributes attr = UA_MethodAttributes_default;
attr.executable = true;
attr.userExecutable = true;
attr.displayName = UA_LOCALIZEDTEXT("", "ClearMESMessage");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_METHOD,
UA_NODEID_NUMERIC(ns[4], 1026),
UA_NODEID_NUMERIC(ns[4], 1005),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "ClearMESMessage"),
 UA_NODEID_NULL,
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_METHODATTRIBUTES],NULL, NULL);
return retVal;
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

static UA_StatusCode function_namespace_euromap_model_generated_72_finish(UA_Server *server, UA_UInt16* ns) {
#ifdef UA_ENABLE_METHODCALLS
return UA_Server_addMethodNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1026)
, NULL, 0, NULL, 0, NULL);
#else
return UA_STATUSCODE_GOOD;
#endif /* UA_ENABLE_METHODCALLS */
}

/* MESMessage - ns=4;i=1027 */

static UA_StatusCode function_namespace_euromap_model_generated_73_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "MESMessage");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[4], 1027),
UA_NODEID_NUMERIC(ns[4], 1005),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "MESMessage"),
UA_NODEID_NUMERIC(ns[2], 1051),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_73_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1027)
);
}

/* Id - ns=4;i=1038 */

static UA_StatusCode function_namespace_euromap_model_generated_74_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_4_i_1038_variant_DataContents =  UA_String_new();
if (!variablenode_ns_4_i_1038_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_4_i_1038_variant_DataContents);
*variablenode_ns_4_i_1038_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1038_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "Id");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Id of the message");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1038),
UA_NODEID_NUMERIC(ns[4], 1027),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "Id"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_4_i_1038_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_74_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1038)
);
}

/* Message - ns=4;i=1039 */

static UA_StatusCode function_namespace_euromap_model_generated_75_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_4_i_1039_variant_DataContents =  UA_String_new();
if (!variablenode_ns_4_i_1039_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_4_i_1039_variant_DataContents);
*variablenode_ns_4_i_1039_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1039_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "Message");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Text of the message");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1039),
UA_NODEID_NUMERIC(ns[4], 1027),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "Message"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_4_i_1039_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_75_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1039)
);
}

/* Severity - ns=4;i=1040 */

static UA_StatusCode function_namespace_euromap_model_generated_76_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 5);
UA_UInt16 *variablenode_ns_4_i_1040_variant_DataContents =  UA_UInt16_new();
if (!variablenode_ns_4_i_1040_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt16_init(variablenode_ns_4_i_1040_variant_DataContents);
*variablenode_ns_4_i_1040_variant_DataContents = (UA_UInt16) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1040_variant_DataContents, &UA_TYPES[UA_TYPES_UINT16]);
attr.displayName = UA_LOCALIZEDTEXT("", "Severity");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Severity of the message");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1040),
UA_NODEID_NUMERIC(ns[4], 1027),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "Severity"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt16_delete(variablenode_ns_4_i_1040_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_76_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1040)
);
}

/* StandstillMessage - ns=4;i=1030 */

static UA_StatusCode function_namespace_euromap_model_generated_77_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "StandstillMessage");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[4], 1030),
UA_NODEID_NUMERIC(ns[4], 1005),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "StandstillMessage"),
UA_NODEID_NUMERIC(ns[2], 1026),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_77_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1030)
);
}

/* Classification - ns=4;i=1047 */

static UA_StatusCode function_namespace_euromap_model_generated_78_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[3], 3004);
attr.displayName = UA_LOCALIZEDTEXT("", "Classification");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Classification of the message");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1047),
UA_NODEID_NUMERIC(ns[4], 1030),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "Classification"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_78_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1047)
);
}

/* Severity - ns=4;i=1050 */

static UA_StatusCode function_namespace_euromap_model_generated_79_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 5);
UA_UInt16 *variablenode_ns_4_i_1050_variant_DataContents =  UA_UInt16_new();
if (!variablenode_ns_4_i_1050_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt16_init(variablenode_ns_4_i_1050_variant_DataContents);
*variablenode_ns_4_i_1050_variant_DataContents = (UA_UInt16) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1050_variant_DataContents, &UA_TYPES[UA_TYPES_UINT16]);
attr.displayName = UA_LOCALIZEDTEXT("", "Severity");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Severity of the message");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1050),
UA_NODEID_NUMERIC(ns[4], 1030),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "Severity"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt16_delete(variablenode_ns_4_i_1050_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_79_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1050)
);
}

/* Message - ns=4;i=1049 */

static UA_StatusCode function_namespace_euromap_model_generated_80_begin(UA_Server *server, UA_UInt16* ns) {
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
UA_NODEID_NUMERIC(ns[4], 1049),
UA_NODEID_NUMERIC(ns[4], 1030),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "Message"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_80_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1049)
);
}

/* Id - ns=4;i=1048 */

static UA_StatusCode function_namespace_euromap_model_generated_81_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_4_i_1048_variant_DataContents =  UA_String_new();
if (!variablenode_ns_4_i_1048_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_4_i_1048_variant_DataContents);
*variablenode_ns_4_i_1048_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1048_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "Id");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Id of the message");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1048),
UA_NODEID_NUMERIC(ns[4], 1030),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "Id"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_4_i_1048_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_81_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1048)
);
}

/* StandstillReasonId - ns=4;i=1031 */

static UA_StatusCode function_namespace_euromap_model_generated_82_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_4_i_1031_variant_DataContents =  UA_String_new();
if (!variablenode_ns_4_i_1031_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_4_i_1031_variant_DataContents);
*variablenode_ns_4_i_1031_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1031_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "StandstillReasonId");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Id of the StandstillReason set by the operator after a standstill occurs");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1031),
UA_NODEID_NUMERIC(ns[4], 1005),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "StandstillReasonId"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_4_i_1031_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_82_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1031)
);
}

/* MachineMESConfiguration - ns=4;i=1004 */

static UA_StatusCode function_namespace_euromap_model_generated_83_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "MachineMESConfiguration");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[4], 1004),
UA_NODEID_NUMERIC(ns[4], 1000),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "MachineMESConfiguration"),
UA_NODEID_NUMERIC(ns[2], 1018),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_83_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1004)
);
}

/* StandstillReasonsLockedByMES - ns=4;i=1025 */

static UA_StatusCode function_namespace_euromap_model_generated_84_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_4_i_1025_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_4_i_1025_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_4_i_1025_variant_DataContents);
*variablenode_ns_4_i_1025_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1025_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "StandstillReasonsLockedByMES");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Indication if the list StandstillReasons has been modified by the MES and may not be changed by the machine");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1025),
UA_NODEID_NUMERIC(ns[4], 1004),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "StandstillReasonsLockedByMES"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_4_i_1025_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_84_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1025)
);
}

/* StandstillReasons - ns=4;i=1024 */

static UA_StatusCode function_namespace_euromap_model_generated_85_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 3;
attr.accessLevel = 3;
attr.valueRank = 1;
attr.arrayDimensionsSize = 1;
UA_UInt32 arrayDimensions[1];
arrayDimensions[0] = 1;
attr.arrayDimensions = &arrayDimensions[0];
attr.dataType = UA_NODEID_NUMERIC(ns[2], 3015);
attr.displayName = UA_LOCALIZEDTEXT("", "StandstillReasons");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "List of the standstill reasons from which one is selected by the operator in the case of a standstill");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1024),
UA_NODEID_NUMERIC(ns[4], 1004),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "StandstillReasons"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_85_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1024)
);
}

/* Moulds - ns=4;i=1007 */

static UA_StatusCode function_namespace_euromap_model_generated_86_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Moulds");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[4], 1007),
UA_NODEID_NUMERIC(ns[4], 1000),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "Moulds"),
UA_NODEID_NUMERIC(ns[2], 1050),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_86_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1007)
);
}

/* Mould_1 - ns=4;i=1090 */

static UA_StatusCode function_namespace_euromap_model_generated_87_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Mould_1");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[4], 1090),
UA_NODEID_NUMERIC(ns[4], 1007),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "Mould_1"),
UA_NODEID_NUMERIC(ns[2], 1029),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_87_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1090)
);
}

/* TemperatureZones - ns=4;i=1096 */

static UA_StatusCode function_namespace_euromap_model_generated_88_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "TemperatureZones");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[4], 1096),
UA_NODEID_NUMERIC(ns[4], 1090),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "TemperatureZones"),
UA_NODEID_NUMERIC(ns[2], 1055),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_88_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1096)
);
}

/* NodeVersion - ns=4;i=1097 */

static UA_StatusCode function_namespace_euromap_model_generated_89_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_4_i_1097_variant_DataContents =  UA_String_new();
if (!variablenode_ns_4_i_1097_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_4_i_1097_variant_DataContents);
*variablenode_ns_4_i_1097_variant_DataContents = UA_STRING_ALLOC("NaN");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1097_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "NodeVersion");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1097),
UA_NODEID_NUMERIC(ns[4], 1096),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "NodeVersion"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_4_i_1097_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_89_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1097)
);
}

/* MouldTemperatureZone_1 - ns=4;i=1098 */

static UA_StatusCode function_namespace_euromap_model_generated_90_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "MouldTemperatureZone_1");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[4], 1098),
UA_NODEID_NUMERIC(ns[4], 1096),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "MouldTemperatureZone_1"),
UA_NODEID_NUMERIC(ns[2], 1034),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_90_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1098)
);
}

/* NominalTemperature - ns=4;i=1104 */

static UA_StatusCode function_namespace_euromap_model_generated_91_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_4_i_1104_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_4_i_1104_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_4_i_1104_variant_DataContents);
*variablenode_ns_4_i_1104_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1104_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "NominalTemperature");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Nominal temperature (absolute value)");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1104),
UA_NODEID_NUMERIC(ns[4], 1098),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "NominalTemperature"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_4_i_1104_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_91_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1104)
);
}

/* EngineeringUnits - ns=4;i=1107 */

static UA_StatusCode function_namespace_euromap_model_generated_92_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_4_i_1107_EUInformation_0, 1);
UA_init(variablenode_ns_4_i_1107_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_4_i_1107_EUInformation_0->namespaceUri = UA_STRING("http://www.opcfoundation.org/UA/units/un/cefact");
variablenode_ns_4_i_1107_EUInformation_0->unitId = (UA_Int32) 4408652;
variablenode_ns_4_i_1107_EUInformation_0->displayName = UA_LOCALIZEDTEXT("", "°C");
variablenode_ns_4_i_1107_EUInformation_0->description = UA_LOCALIZEDTEXT("", "degree Celsius");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1107_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1107),
UA_NODEID_NUMERIC(ns[4], 1104),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_92_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1107)
);
}

/* EURange - ns=4;i=1108 */

static UA_StatusCode function_namespace_euromap_model_generated_93_begin(UA_Server *server, UA_UInt16* ns) {
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
UA_NODEID_NUMERIC(ns[4], 1108),
UA_NODEID_NUMERIC(ns[4], 1104),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_93_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1108)
);
}

/* IsPresent - ns=4;i=1102 */

static UA_StatusCode function_namespace_euromap_model_generated_94_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_4_i_1102_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_4_i_1102_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_4_i_1102_variant_DataContents);
*variablenode_ns_4_i_1102_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1102_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "IsPresent");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Indication if the temperature zone is physically present and connected");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1102),
UA_NODEID_NUMERIC(ns[4], 1098),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "IsPresent"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_4_i_1102_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_94_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1102)
);
}

/* Name - ns=4;i=1103 */

static UA_StatusCode function_namespace_euromap_model_generated_95_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_4_i_1103_variant_DataContents =  UA_String_new();
if (!variablenode_ns_4_i_1103_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_4_i_1103_variant_DataContents);
*variablenode_ns_4_i_1103_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1103_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "Name");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Name of the zone");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1103),
UA_NODEID_NUMERIC(ns[4], 1098),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "Name"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_4_i_1103_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_95_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1103)
);
}

/* ControlMode - ns=4;i=1100 */

static UA_StatusCode function_namespace_euromap_model_generated_96_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[2], 3001);
UA_Int32 *variablenode_ns_4_i_1100_variant_DataContents =  UA_Int32_new();
if (!variablenode_ns_4_i_1100_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Int32_init(variablenode_ns_4_i_1100_variant_DataContents);
*variablenode_ns_4_i_1100_variant_DataContents = (UA_Int32) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1100_variant_DataContents, &UA_TYPES[UA_TYPES_INT32]);
attr.displayName = UA_LOCALIZEDTEXT("", "ControlMode");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Indication how the temperature is currently controlled");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1100),
UA_NODEID_NUMERIC(ns[4], 1098),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "ControlMode"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Int32_delete(variablenode_ns_4_i_1100_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_96_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1100)
);
}

/* Index - ns=4;i=1101 */

static UA_StatusCode function_namespace_euromap_model_generated_97_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
UA_UInt32 *variablenode_ns_4_i_1101_variant_DataContents =  UA_UInt32_new();
if (!variablenode_ns_4_i_1101_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt32_init(variablenode_ns_4_i_1101_variant_DataContents);
*variablenode_ns_4_i_1101_variant_DataContents = (UA_UInt32) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1101_variant_DataContents, &UA_TYPES[UA_TYPES_UINT32]);
attr.displayName = UA_LOCALIZEDTEXT("", "Index");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Number of the zone");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1101),
UA_NODEID_NUMERIC(ns[4], 1098),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "Index"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt32_delete(variablenode_ns_4_i_1101_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_97_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1101)
);
}

/* ActualTemperature - ns=4;i=1099 */

static UA_StatusCode function_namespace_euromap_model_generated_98_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 11);
UA_Double *variablenode_ns_4_i_1099_variant_DataContents =  UA_Double_new();
if (!variablenode_ns_4_i_1099_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Double_init(variablenode_ns_4_i_1099_variant_DataContents);
*variablenode_ns_4_i_1099_variant_DataContents = (UA_Double) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1099_variant_DataContents, &UA_TYPES[UA_TYPES_DOUBLE]);
attr.displayName = UA_LOCALIZEDTEXT("", "ActualTemperature");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Current temperature of the zone");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1099),
UA_NODEID_NUMERIC(ns[4], 1098),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "ActualTemperature"),
UA_NODEID_NUMERIC(ns[0], 2368),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Double_delete(variablenode_ns_4_i_1099_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_98_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1099)
);
}

/* EngineeringUnits - ns=4;i=1105 */

static UA_StatusCode function_namespace_euromap_model_generated_99_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 887);

UA_STACKARRAY(UA_EUInformation, variablenode_ns_4_i_1105_EUInformation_0, 1);
UA_init(variablenode_ns_4_i_1105_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
variablenode_ns_4_i_1105_EUInformation_0->namespaceUri = UA_STRING("http://www.opcfoundation.org/UA/units/un/cefact");
variablenode_ns_4_i_1105_EUInformation_0->unitId = (UA_Int32) 4408652;
variablenode_ns_4_i_1105_EUInformation_0->displayName = UA_LOCALIZEDTEXT("", "°C");
variablenode_ns_4_i_1105_EUInformation_0->description = UA_LOCALIZEDTEXT("", "degree Celsius");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1105_EUInformation_0, &UA_TYPES[UA_TYPES_EUINFORMATION]);
attr.displayName = UA_LOCALIZEDTEXT("", "EngineeringUnits");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1105),
UA_NODEID_NUMERIC(ns[4], 1099),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EngineeringUnits"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);

return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_99_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1105)
);
}

/* EURange - ns=4;i=1106 */

static UA_StatusCode function_namespace_euromap_model_generated_100_begin(UA_Server *server, UA_UInt16* ns) {
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
UA_NODEID_NUMERIC(ns[4], 1106),
UA_NODEID_NUMERIC(ns[4], 1099),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "EURange"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_100_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1106)
);
}

/* MouldStatus - ns=4;i=1095 */

static UA_StatusCode function_namespace_euromap_model_generated_101_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[2], 3008);
UA_Int32 *variablenode_ns_4_i_1095_variant_DataContents =  UA_Int32_new();
if (!variablenode_ns_4_i_1095_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Int32_init(variablenode_ns_4_i_1095_variant_DataContents);
*variablenode_ns_4_i_1095_variant_DataContents = (UA_Int32) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1095_variant_DataContents, &UA_TYPES[UA_TYPES_INT32]);
attr.displayName = UA_LOCALIZEDTEXT("", "MouldStatus");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Current (physical) status of the mould");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1095),
UA_NODEID_NUMERIC(ns[4], 1090),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "MouldStatus"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Int32_delete(variablenode_ns_4_i_1095_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_101_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1095)
);
}

/* IsPresent - ns=4;i=1094 */

static UA_StatusCode function_namespace_euromap_model_generated_102_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_4_i_1094_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_4_i_1094_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_4_i_1094_variant_DataContents);
*variablenode_ns_4_i_1094_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1094_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "IsPresent");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Indication if the mould is physically present and connected");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1094),
UA_NODEID_NUMERIC(ns[4], 1090),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "IsPresent"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_4_i_1094_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_102_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1094)
);
}

/* Description - ns=4;i=1091 */

static UA_StatusCode function_namespace_euromap_model_generated_103_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_4_i_1091_variant_DataContents =  UA_String_new();
if (!variablenode_ns_4_i_1091_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_4_i_1091_variant_DataContents);
*variablenode_ns_4_i_1091_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1091_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "Description");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Description of the installed mould");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1091),
UA_NODEID_NUMERIC(ns[4], 1090),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "Description"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_4_i_1091_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_103_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1091)
);
}

/* Id - ns=4;i=1092 */

static UA_StatusCode function_namespace_euromap_model_generated_104_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_4_i_1092_variant_DataContents =  UA_String_new();
if (!variablenode_ns_4_i_1092_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_4_i_1092_variant_DataContents);
*variablenode_ns_4_i_1092_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1092_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "Id");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Id of the installed mould");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1092),
UA_NODEID_NUMERIC(ns[4], 1090),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "Id"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_4_i_1092_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_104_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1092)
);
}

/* Index - ns=4;i=1093 */

static UA_StatusCode function_namespace_euromap_model_generated_105_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 7);
UA_UInt32 *variablenode_ns_4_i_1093_variant_DataContents =  UA_UInt32_new();
if (!variablenode_ns_4_i_1093_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_UInt32_init(variablenode_ns_4_i_1093_variant_DataContents);
*variablenode_ns_4_i_1093_variant_DataContents = (UA_UInt32) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1093_variant_DataContents, &UA_TYPES[UA_TYPES_UINT32]);
attr.displayName = UA_LOCALIZEDTEXT("", "Index");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Number of the mould");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1093),
UA_NODEID_NUMERIC(ns[4], 1090),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "Index"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_UInt32_delete(variablenode_ns_4_i_1093_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_105_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1093)
);
}

/* NodeVersion - ns=4;i=1035 */

static UA_StatusCode function_namespace_euromap_model_generated_106_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_4_i_1035_variant_DataContents =  UA_String_new();
if (!variablenode_ns_4_i_1035_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_4_i_1035_variant_DataContents);
*variablenode_ns_4_i_1035_variant_DataContents = UA_STRING_ALLOC("NaN");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1035_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "NodeVersion");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1035),
UA_NODEID_NUMERIC(ns[4], 1007),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "NodeVersion"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_4_i_1035_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_106_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1035)
);
}

/* MachineStatus - ns=4;i=1006 */

static UA_StatusCode function_namespace_euromap_model_generated_107_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "MachineStatus");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[4], 1006),
UA_NODEID_NUMERIC(ns[4], 1000),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[3], "MachineStatus"),
UA_NODEID_NUMERIC(ns[2], 1019),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_107_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1006)
);
}

/* MachineMode - ns=4;i=1033 */

static UA_StatusCode function_namespace_euromap_model_generated_108_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[2], 3011);
UA_Int32 *variablenode_ns_4_i_1033_variant_DataContents =  UA_Int32_new();
if (!variablenode_ns_4_i_1033_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Int32_init(variablenode_ns_4_i_1033_variant_DataContents);
*variablenode_ns_4_i_1033_variant_DataContents = (UA_Int32) 0;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1033_variant_DataContents, &UA_TYPES[UA_TYPES_INT32]);
attr.displayName = UA_LOCALIZEDTEXT("", "MachineMode");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Current machine mode (as defined by mode selector on the machine)");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1033),
UA_NODEID_NUMERIC(ns[4], 1006),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "MachineMode"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Int32_delete(variablenode_ns_4_i_1033_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_108_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1033)
);
}

/* Users - ns=4;i=1034 */

static UA_StatusCode function_namespace_euromap_model_generated_109_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "Users");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[4], 1034),
UA_NODEID_NUMERIC(ns[4], 1006),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "Users"),
UA_NODEID_NUMERIC(ns[2], 1048),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_109_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1034)
);
}

/* User_1 - ns=4;i=1082 */

static UA_StatusCode function_namespace_euromap_model_generated_110_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "User_1");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[4], 1082),
UA_NODEID_NUMERIC(ns[4], 1034),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "User_1"),
UA_NODEID_NUMERIC(ns[2], 1045),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_110_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1082)
);
}

/* Name - ns=4;i=1085 */

static UA_StatusCode function_namespace_euromap_model_generated_111_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_4_i_1085_variant_DataContents =  UA_String_new();
if (!variablenode_ns_4_i_1085_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_4_i_1085_variant_DataContents);
*variablenode_ns_4_i_1085_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1085_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "Name");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Name of the user");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1085),
UA_NODEID_NUMERIC(ns[4], 1082),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "Name"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_4_i_1085_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_111_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1085)
);
}

/* Id - ns=4;i=1083 */

static UA_StatusCode function_namespace_euromap_model_generated_112_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_4_i_1083_variant_DataContents =  UA_String_new();
if (!variablenode_ns_4_i_1083_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_4_i_1083_variant_DataContents);
*variablenode_ns_4_i_1083_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1083_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "Id");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Id of the user");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1083),
UA_NODEID_NUMERIC(ns[4], 1082),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "Id"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_4_i_1083_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_112_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1083)
);
}

/* IsPresent - ns=4;i=1084 */

static UA_StatusCode function_namespace_euromap_model_generated_113_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_4_i_1084_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_4_i_1084_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_4_i_1084_variant_DataContents);
*variablenode_ns_4_i_1084_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1084_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "IsPresent");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "The machine can have instances for the maximum number of users that can be simultaneously logged in. TRUE if the instance of UserType represents a user that is currently logged in.");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1084),
UA_NODEID_NUMERIC(ns[4], 1082),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "IsPresent"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_4_i_1084_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_113_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1084)
);
}

/* NodeVersion - ns=4;i=1051 */

static UA_StatusCode function_namespace_euromap_model_generated_114_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_4_i_1051_variant_DataContents =  UA_String_new();
if (!variablenode_ns_4_i_1051_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_4_i_1051_variant_DataContents);
*variablenode_ns_4_i_1051_variant_DataContents = UA_STRING_ALLOC("NaN");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1051_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "NodeVersion");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1051),
UA_NODEID_NUMERIC(ns[4], 1034),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[0], "NodeVersion"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_4_i_1051_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_114_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1051)
);
}

/* User_2 - ns=4;i=1086 */

static UA_StatusCode function_namespace_euromap_model_generated_115_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_ObjectAttributes attr = UA_ObjectAttributes_default;
attr.displayName = UA_LOCALIZEDTEXT("", "User_2");
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_OBJECT,
UA_NODEID_NUMERIC(ns[4], 1086),
UA_NODEID_NUMERIC(ns[4], 1034),
UA_NODEID_NUMERIC(ns[0], 47),
UA_QUALIFIEDNAME(ns[2], "User_2"),
UA_NODEID_NUMERIC(ns[2], 1045),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_OBJECTATTRIBUTES],NULL, NULL);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_115_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1086)
);
}

/* Id - ns=4;i=1087 */

static UA_StatusCode function_namespace_euromap_model_generated_116_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_4_i_1087_variant_DataContents =  UA_String_new();
if (!variablenode_ns_4_i_1087_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_4_i_1087_variant_DataContents);
*variablenode_ns_4_i_1087_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1087_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "Id");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Id of the user");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1087),
UA_NODEID_NUMERIC(ns[4], 1086),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "Id"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_4_i_1087_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_116_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1087)
);
}

/* Name - ns=4;i=1089 */

static UA_StatusCode function_namespace_euromap_model_generated_117_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 12);
UA_String *variablenode_ns_4_i_1089_variant_DataContents =  UA_String_new();
if (!variablenode_ns_4_i_1089_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_String_init(variablenode_ns_4_i_1089_variant_DataContents);
*variablenode_ns_4_i_1089_variant_DataContents = UA_STRING_ALLOC("");
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1089_variant_DataContents, &UA_TYPES[UA_TYPES_STRING]);
attr.displayName = UA_LOCALIZEDTEXT("", "Name");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Name of the user");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1089),
UA_NODEID_NUMERIC(ns[4], 1086),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "Name"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_String_delete(variablenode_ns_4_i_1089_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_117_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1089)
);
}

/* IsPresent - ns=4;i=1088 */

static UA_StatusCode function_namespace_euromap_model_generated_118_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_4_i_1088_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_4_i_1088_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_4_i_1088_variant_DataContents);
*variablenode_ns_4_i_1088_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1088_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "IsPresent");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "The machine can have instances for the maximum number of users that can be simultaneously logged in. TRUE if the instance of UserType represents a user that is currently logged in.");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1088),
UA_NODEID_NUMERIC(ns[4], 1086),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "IsPresent"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_4_i_1088_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_118_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1088)
);
}

/* IsPresent - ns=4;i=1032 */

static UA_StatusCode function_namespace_euromap_model_generated_119_begin(UA_Server *server, UA_UInt16* ns) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
UA_VariableAttributes attr = UA_VariableAttributes_default;
attr.minimumSamplingInterval = 0.000000;
attr.userAccessLevel = 1;
attr.accessLevel = 1;
/* Value rank inherited */
attr.valueRank = -1;
attr.dataType = UA_NODEID_NUMERIC(ns[0], 1);
UA_Boolean *variablenode_ns_4_i_1032_variant_DataContents =  UA_Boolean_new();
if (!variablenode_ns_4_i_1032_variant_DataContents) return UA_STATUSCODE_BADOUTOFMEMORY;
UA_Boolean_init(variablenode_ns_4_i_1032_variant_DataContents);
*variablenode_ns_4_i_1032_variant_DataContents = (UA_Boolean) false;
UA_Variant_setScalar(&attr.value, variablenode_ns_4_i_1032_variant_DataContents, &UA_TYPES[UA_TYPES_BOOLEAN]);
attr.displayName = UA_LOCALIZEDTEXT("", "IsPresent");
#ifdef UA_ENABLE_NODESET_COMPILER_DESCRIPTIONS
attr.description = UA_LOCALIZEDTEXT("", "Indication if the machine is physically present and connected");
#endif
retVal |= UA_Server_addNode_begin(server, UA_NODECLASS_VARIABLE,
UA_NODEID_NUMERIC(ns[4], 1032),
UA_NODEID_NUMERIC(ns[4], 1006),
UA_NODEID_NUMERIC(ns[0], 46),
UA_QUALIFIEDNAME(ns[2], "IsPresent"),
UA_NODEID_NUMERIC(ns[0], 68),
(const UA_NodeAttributes*)&attr, &UA_TYPES[UA_TYPES_VARIABLEATTRIBUTES],NULL, NULL);
UA_Boolean_delete(variablenode_ns_4_i_1032_variant_DataContents);
return retVal;
}

static UA_StatusCode function_namespace_euromap_model_generated_119_finish(UA_Server *server, UA_UInt16* ns) {
return UA_Server_addNode_finish(server, 
UA_NODEID_NUMERIC(ns[4], 1032)
);
}

UA_StatusCode namespace_euromap_model_generated(UA_Server *server) {
UA_StatusCode retVal = UA_STATUSCODE_GOOD;
/* Use namespace ids generated by the server */
UA_UInt16 ns[5];
ns[0] = UA_Server_addNamespace(server, "http://opcfoundation.org/UA/");
ns[1] = UA_Server_addNamespace(server, "http://opcfoundation.org/UA/DI/");
ns[2] = UA_Server_addNamespace(server, "http://www.euromap.org/euromap83/");
ns[3] = UA_Server_addNamespace(server, "http://www.euromap.org/euromap77/");
ns[4] = UA_Server_addNamespace(server, "http://www.OEM.com/siemens/euromap77Demo");
bool dummy = (
!(retVal = function_namespace_euromap_model_generated_0_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_1_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_2_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_3_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_4_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_5_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_6_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_7_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_8_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_9_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_10_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_11_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_12_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_13_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_14_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_15_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_16_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_17_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_18_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_19_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_20_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_21_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_22_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_23_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_24_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_25_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_26_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_27_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_28_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_29_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_30_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_31_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_32_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_33_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_34_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_35_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_36_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_37_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_38_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_39_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_40_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_41_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_42_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_43_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_44_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_45_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_46_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_47_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_48_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_49_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_50_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_51_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_52_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_53_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_54_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_55_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_56_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_57_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_58_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_59_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_60_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_61_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_62_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_63_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_64_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_65_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_66_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_67_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_68_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_69_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_70_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_71_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_72_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_73_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_74_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_75_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_76_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_77_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_78_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_79_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_80_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_81_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_82_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_83_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_84_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_85_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_86_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_87_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_88_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_89_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_90_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_91_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_92_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_93_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_94_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_95_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_96_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_97_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_98_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_99_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_100_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_101_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_102_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_103_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_104_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_105_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_106_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_107_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_108_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_109_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_110_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_111_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_112_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_113_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_114_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_115_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_116_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_117_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_118_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_119_begin(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_119_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_118_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_117_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_116_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_115_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_114_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_113_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_112_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_111_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_110_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_109_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_108_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_107_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_106_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_105_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_104_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_103_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_102_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_101_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_100_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_99_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_98_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_97_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_96_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_95_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_94_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_93_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_92_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_91_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_90_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_89_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_88_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_87_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_86_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_85_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_84_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_83_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_82_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_81_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_80_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_79_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_78_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_77_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_76_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_75_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_74_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_73_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_72_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_71_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_70_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_69_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_68_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_67_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_66_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_65_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_64_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_63_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_62_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_61_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_60_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_59_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_58_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_57_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_56_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_55_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_54_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_53_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_52_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_51_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_50_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_49_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_48_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_47_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_46_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_45_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_44_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_43_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_42_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_41_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_40_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_39_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_38_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_37_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_36_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_35_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_34_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_33_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_32_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_31_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_30_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_29_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_28_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_27_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_26_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_25_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_24_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_23_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_22_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_21_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_20_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_19_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_18_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_17_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_16_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_15_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_14_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_13_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_12_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_11_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_10_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_9_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_8_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_7_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_6_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_5_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_4_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_3_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_2_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_1_finish(server, ns)) &&
!(retVal = function_namespace_euromap_model_generated_0_finish(server, ns)) 
); (void)(dummy);
return retVal;
}
