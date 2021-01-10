#include "namespace_model.h"

/*
 * Event functions
 */

/* Event variables */

// TODO: Event severity
// The Event Severity value is currently only set in generate*MethodCallback.
// If Event Severity is importent, create function to change Event Severity
// from e.g. STouchNfc.
UA_UInt16 eventSeverity = 0;

/* Event setup function */

UA_StatusCode
setupEvent(UA_Server *server, UA_NodeId *outId) {
    UA_StatusCode retval = UA_Server_createEvent(server, eventType, outId);
    if (retval != UA_STATUSCODE_GOOD) {
        UA_LOG_WARNING(UA_Log_Stdout, UA_LOGCATEGORY_SERVER,
                       "createEvent failed. StatusCode %s", UA_StatusCode_name(retval));
        return retval;
    }

    /* Set the Event Attributes */
    /* Setting the Time is required or else the event will not show up in UAExpert! */
    UA_DateTime eventTime = UA_DateTime_now();
    UA_Server_writeObjectProperty_scalar(server, *outId, UA_QUALIFIEDNAME(ns[0], "Time"),
                                         &eventTime, &UA_TYPES[UA_TYPES_DATETIME]);

    /* Read attribute */
    char string[11];
    UA_Variant *variant = UA_Variant_new();
    retval = UA_Server_readValue(server, UA_NODEID_NUMERIC(ns[1], 62000), variant);
    if(retval == UA_STATUSCODE_GOOD && UA_Variant_isScalar(variant) &&
       variant->type == &UA_TYPES[UA_TYPES_FLOAT]) {
        sprintf(string, "%f", *(UA_Float*)variant->data);
        printf("Event data is: %s\n", string);
#ifdef S_DEBUG_SYSTEM
        UA_LOG_WARNING(UA_Log_Stdout, UA_LOGCATEGORY_SERVER,
                       "Event data is %s", string);
#endif
    } else {
#ifdef S_DEBUG_SYSTEM
        UA_LOG_WARNING(UA_Log_Stdout, UA_LOGCATEGORY_SERVER,
                       "No Event data");
#endif
    }
    UA_Variant_delete(variant);
    /* Write message */
    UA_LocalizedText eventMessage = UA_LOCALIZEDTEXT("en-US", string);
    UA_Server_writeObjectProperty_scalar(server, *outId, UA_QUALIFIEDNAME(ns[0], "Message"),
                                         &eventMessage, &UA_TYPES[UA_TYPES_LOCALIZEDTEXT]);

    /* Write severity */
    UA_Server_writeObjectProperty_scalar(server, *outId, UA_QUALIFIEDNAME(ns[0], "Severity"),
                                         &eventSeverity, &UA_TYPES[UA_TYPES_UINT16]);

    /* Write source */
    UA_String eventSourceName = UA_STRING("Server");
    UA_Server_writeObjectProperty_scalar(server, *outId, UA_QUALIFIEDNAME(ns[0], "SourceName"),
                                         &eventSourceName, &UA_TYPES[UA_TYPES_STRING]);

    return UA_STATUSCODE_GOOD;
}

/* Event trigger function */

UA_StatusCode
triggerEvent(UA_Server *server) {
    /* set up event */
    UA_NodeId eventNodeId;
    UA_StatusCode retval = setupEvent(server, &eventNodeId);
    if (retval != UA_STATUSCODE_GOOD) {
#ifdef S_DEBUG_SYSTEM
        UA_LOG_WARNING(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                       "Creating event failed. StatusCode %s", UA_StatusCode_name(retval));
#endif
        return retval;
    }

    retval = UA_Server_triggerEvent(server,
                                    eventNodeId,
                                    UA_NODEID_NUMERIC(ns[0], UA_NS0ID_SERVER),
                                    NULL, UA_TRUE);
    if (retval != UA_STATUSCODE_GOOD)
#ifdef S_DEBUG_SYSTEM
        UA_LOG_WARNING(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                       "Triggering event failed. StatusCode %s", UA_StatusCode_name(retval));
#endif

    return retval;
}

/* Event callback method */

UA_StatusCode
generateEventMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output) {
#ifdef S_DEBUG_SYSTEM
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                "Creating event");
#endif

    /* trigger event */
    return triggerEvent(server);
}

/*
 * A&C
 */

/* A&C functions */

UA_StatusCode
addACConditionSourceObject(UA_Server *server) {
    UA_ObjectAttributes object_attr = UA_ObjectAttributes_default;
    object_attr.eventNotifier = 1;

    object_attr.displayName = UA_LOCALIZEDTEXT("en", "ConditionSourceObject");
    UA_StatusCode retval =  UA_Server_addObjectNode(server,
                                                    UA_NODEID_NULL,
                                                    UA_NODEID_NULL,
                                                    UA_NODEID_NULL,
                                                    UA_QUALIFIEDNAME(ns[0], "ConditionSourceObject"),
                                                    UA_NODEID_NUMERIC(ns[0], UA_NS0ID_BASEOBJECTTYPE),
                                                    object_attr,
                                                    NULL,
                                                    &conditionSourceAC);

    if (retval != UA_STATUSCODE_GOOD) {
#ifdef S_DEBUG_SYSTEM
        UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                     "creating Condition Source failed. StatusCode %s", UA_StatusCode_name(retval));
#endif
    }

    /* ConditionSource should be EventNotifier of another Object (usually the Server Object).
     * If this Reference is not created by user then the A&C Server will create "HasEventSource"
     * reference to the Server Object automatically when the condition is created*/
    retval = UA_Server_addReference(server,
                                    UA_NODEID_NUMERIC(ns[0], UA_NS0ID_SERVER),
                                    UA_NODEID_NUMERIC(ns[0], UA_NS0ID_HASNOTIFIER),
                                    UA_EXPANDEDNODEID_NUMERIC(conditionSourceAC.namespaceIndex,
                                                              conditionSourceAC.identifier.numeric),
                                    UA_TRUE);

    return retval;
}

/**
 * create a condition instance from OffNormalAlarmType. The condition source is the Object created in
 * addACConditionSourceObject(). The condition will be exposed in Address Space through the HasComponent
 * reference to the condition source.
 */
UA_StatusCode
addACCondition_1(UA_Server *server) {
    UA_StatusCode retval = addACConditionSourceObject(server);
    if (retval != UA_STATUSCODE_GOOD) {
#ifdef S_DEBUG_SYSTEM
        UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                     "creating Condition Source failed. StatusCode %s", UA_StatusCode_name(retval));
#endif
    }

    retval = UA_Server_createCondition(server,
                                       UA_NODEID_NULL,
                                       UA_NODEID_NUMERIC(ns[0], UA_NS0ID_OFFNORMALALARMTYPE),
                                       UA_QUALIFIEDNAME(ns[0], "Condition 1"),
                                       conditionSourceAC,
                                       UA_NODEID_NUMERIC(ns[0], UA_NS0ID_HASCOMPONENT),
                                       &conditionInstanceAC_1);

    return retval;
}

/**
 * create a condition instance from OffNormalAlarmType. The condition source is the server Object.
 * The condition won't be exposed in Address Space.
 */
UA_StatusCode
addACCondition_2(UA_Server *server) {
    UA_StatusCode retval = UA_Server_createCondition(server,
                                                     UA_NODEID_NULL,
                                                     UA_NODEID_NUMERIC(ns[0], UA_NS0ID_OFFNORMALALARMTYPE),
                                                     UA_QUALIFIEDNAME(ns[0], "Condition 2"),
                                                     UA_NODEID_NUMERIC(ns[0], UA_NS0ID_SERVER),
                                                     UA_NODEID_NULL,
                                                     &conditionInstanceAC_2);

    return retval;
}

void
addACVariableChangeSeverityOfCondition(UA_Server *server, UA_NodeId* outNodeId) {
    UA_VariableAttributes attr = UA_VariableAttributes_default;
    attr.displayName = UA_LOCALIZEDTEXT("en", "SeverityCondition");
    attr.description = UA_LOCALIZEDTEXT("en", "Change Severity Condition.");
    attr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;

    UA_UInt16 severityValue = 0;
    UA_Variant_setScalar(&attr.value, &severityValue, &UA_TYPES[UA_TYPES_UINT16]);
    UA_Server_addVariableNode(server,
                              UA_NODEID_NUMERIC(ns[1], 63000),
                              UA_NODEID_NUMERIC(ns[0], UA_NS0ID_OBJECTSFOLDER),
                              UA_NODEID_NUMERIC(ns[0], UA_NS0ID_ORGANIZES),
                              UA_QUALIFIEDNAME(ns[0], "SeverityCondition"),
                              UA_NODEID_NUMERIC(ns[0], UA_NS0ID_BASEDATAVARIABLETYPE),
                              attr,
                              NULL,
                              outNodeId);
}

UA_StatusCode
setSeverityOfCondition(UA_Server *server, UA_UInt16 severity) {
    /* Write a A&C - Severity
     *
     * https://reference.opcfoundation.org/v104/Core/docs/Part5/6.4.2/
     *
     * Severity
     * ----------------------------
     * HIGH	            801 – 1 000
     * MEDIUM HIGH	    601 – 800
     * MEDIUM	        401 – 600
     * MEDIUM LOW	    201 – 400
     * LOW	            1 – 200
     * IDLE             0
     */

    UA_StatusCode retval = UA_STATUSCODE_GOOD;

    UA_Variant var;
    UA_Variant_init(&var);
    UA_Variant_setScalar(&var, &severity, &UA_TYPES[UA_TYPES_UINT16]);
    retval = UA_Server_writeValue(server,
                                  UA_NODEID_NUMERIC(ns[1], 63000),
                                  var);

    return retval;
}

/**
 * the callback only changes the severity field of the condition 2. The severity
 * field is of ConditionVariableType, so changes in it triggers an event notification
 * automatically by the server.
 */
void
afterACWriteVariableCallback(UA_Server *server,
               const UA_NodeId *sessionId, void *sessionContext,
               const UA_NodeId *nodeId, void *nodeContext,
               const UA_NumericRange *range, const UA_DataValue *data) {
   /**
    * another way to set fields of conditions
    */
    UA_Server_writeObjectProperty_scalar(server,
                                         conditionInstanceAC_2,
                                         UA_QUALIFIEDNAME(ns[0], "Severity"),
                                         (UA_UInt16 *)data->value.data,
                                         &UA_TYPES[UA_TYPES_UINT16]);
}

/*
 * Method functions
 */

/* Method variables */

UA_Boolean ua_nfcRunning = true;
bool ua_nfcStart = false;
bool ua_nfcPause = false;
bool ua_nfcStop = false;
bool ua_nfcResume = false;
int ua_nfcData = 0;

/* Method start callback */

UA_StatusCode
generateStartMethodCallback(UA_Server *server,
           const UA_NodeId *sessionId, void *sessionContext,
           const UA_NodeId *methodId, void *methodContext,
           const UA_NodeId *objectId, void *objectContext,
           size_t inputSize, const UA_Variant *input,
           size_t outputSize, UA_Variant *output) {
    /* input is a scalar integer (checked by the server) */
    int in = *(int*)input[0].data;
    ua_nfcData = in;
    ua_nfcStart = true;

    /* trigger event */
//    eventSeverity = 1;
//    triggerEvent(server);
    /* trigger A&C */
    setSeverityOfCondition(server, 1);

#ifdef S_DEBUG_SYSTEM
    UA_LOG_WARNING(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                   "Method call startMethod was successful, returned values: %i, %i, %d",
                   in,
                   ua_nfcData,
                   ua_nfcStart);
#endif

    return UA_STATUSCODE_GOOD;
}

/* Method pause callback */

UA_StatusCode
generatePauseMethodCallback(UA_Server *server,
           const UA_NodeId *sessionId, void *sessionContext,
           const UA_NodeId *methodId, void *methodContext,
           const UA_NodeId *objectId, void *objectContext,
           size_t inputSize, const UA_Variant *input,
           size_t outputSize, UA_Variant *output) {
    ua_nfcPause = true;

    /* trigger event */
//    eventSeverity = 2;
//    triggerEvent(server);
    /* trigger A&C */
    setSeverityOfCondition(server, 2);

#ifdef S_DEBUG_SYSTEM
    UA_LOG_WARNING(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                   "Method call pauseMethod was successful");
#endif

    return UA_STATUSCODE_GOOD;
}

/* Method stop callback */

UA_StatusCode
generateStopMethodCallback(UA_Server *server,
           const UA_NodeId *sessionId, void *sessionContext,
           const UA_NodeId *methodId, void *methodContext,
           const UA_NodeId *objectId, void *objectContext,
           size_t inputSize, const UA_Variant *input,
           size_t outputSize, UA_Variant *output) {
    ua_nfcStop = true;

    /* trigger event */
//    eventSeverity = 0;
//    triggerEvent(server);
    /* trigger A&C */
    setSeverityOfCondition(server, 0);

#ifdef S_DEBUG_SYSTEM
    UA_LOG_WARNING(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                   "Method call stopMethod was successful");
#endif

    return UA_STATUSCODE_GOOD;
}

/* Method resume callback */

UA_StatusCode
generateResumeMethodCallback(UA_Server *server,
           const UA_NodeId *sessionId, void *sessionContext,
           const UA_NodeId *methodId, void *methodContext,
           const UA_NodeId *objectId, void *objectContext,
           size_t inputSize, const UA_Variant *input,
           size_t outputSize, UA_Variant *output) {

    /* extern usage */
    ua_nfcResume = true;
    /* trigger event */
//    eventSeverity = 1;
//    triggerEvent(server);
    /* trigger A&C */
    setSeverityOfCondition(server, 1);

#ifdef S_DEBUG_SYSTEM
    UA_LOG_WARNING(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                   "Method call Resume was successful");
#endif

    return UA_STATUSCODE_GOOD;
}

/*
 * Monitored Items
 */

/* Monitored item update */

UA_StatusCode
updateMonitoredItem(UA_Server *server, UA_Float value) {
    UA_StatusCode retval = UA_STATUSCODE_GOOD;

    /* Write a different integer value */
    UA_Variant var;
    UA_Variant_init(&var);
    UA_Variant_setScalar(&var, &value, &UA_TYPES[UA_TYPES_FLOAT]);
    retval = UA_Server_writeValue(server,
                                  UA_NODEID_NUMERIC(ns[1], 62000),
                                  var);

    return retval;
}

/* Monitored item notification callback */

void
processDataChangeMonitoredItemCallback(UA_Server *server, UA_UInt32 monitoredItemId,
                               void *monitoredItemContext, const UA_NodeId *nodeId,
                               void *nodeContext, UA_UInt32 attributeId,
                               const UA_DataValue *value) {
#ifdef S_DEBUG_SYSTEM
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                "Received Notification");
#endif

    /* trigger event */
//    triggerEvent(server);
}

/*
 * Namespace functions
 */

/* NfcStartProcessing - ns=2;i=60000 */

UA_StatusCode
function_namespace_model_0(UA_Server *server, UA_UInt16* ns) {
    UA_StatusCode retval = UA_STATUSCODE_GOOD;

#ifdef UA_ENABLE_METHODCALLS
    /* Method start with in arguments */
    UA_MethodAttributes methodAttributes = UA_MethodAttributes_default;
    methodAttributes.description = UA_LOCALIZEDTEXT("en-US", "Start NFC processing.");
    methodAttributes.displayName = UA_LOCALIZEDTEXT("en-US", "NfcStartProcessing");
    methodAttributes.executable = true;
    methodAttributes.userExecutable = true;

    UA_Argument input;
    UA_Argument_init(&input);
    input.dataType = UA_TYPES[UA_TYPES_INT32].typeId;
    input.description = UA_LOCALIZEDTEXT("en-US", "Input");
    input.name = UA_STRING("Input");
    input.valueRank = UA_VALUERANK_SCALAR; // uaexpert will crash if set to 0

    retval = UA_Server_addMethodNode(server,
                            UA_NODEID_NUMERIC(ns[1], 60000),
                            UA_NODEID_NUMERIC(ns[0], UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(ns[0], UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(ns[1], "NfcStartProcessing"),
                            methodAttributes,
                            &generateStartMethodCallback, /* callback of the method node */
                            1, &input, 0, NULL, NULL, NULL);
#endif

    return retval;
}

/* NfcPauseProcessing - ns=2;i=60001 */

UA_StatusCode
function_namespace_model_1(UA_Server *server, UA_UInt16* ns) {
    UA_StatusCode retval = UA_STATUSCODE_GOOD;

#ifdef UA_ENABLE_METHODCALLS
    /* Method pause without arguments */
    UA_MethodAttributes methodAttributes = UA_MethodAttributes_default;
    methodAttributes.description = UA_LOCALIZEDTEXT("en-US", "Pause NFC processing.");
    methodAttributes.displayName = UA_LOCALIZEDTEXT("en-US", "NfcPauseProcessing");
    methodAttributes.executable = true;
    methodAttributes.userExecutable = true;

    retval = UA_Server_addMethodNode(server,
                            UA_NODEID_NUMERIC(ns[1], 60001),
                            UA_NODEID_NUMERIC(ns[0], UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(ns[0], UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(ns[1], "NfcPauseProcessing"),
                            methodAttributes,
                            &generatePauseMethodCallback, /* callback of the method node */
                            0, NULL, 0, NULL, NULL, NULL);
#endif

    return retval;
}

/* NfcStopProcessing - ns=2;i=60002 */

UA_StatusCode
function_namespace_model_2(UA_Server *server, UA_UInt16* ns) {
    UA_StatusCode retval = UA_STATUSCODE_GOOD;

#ifdef UA_ENABLE_METHODCALLS
    /* Method pause without arguments */
    UA_MethodAttributes methodAttributes = UA_MethodAttributes_default;
    methodAttributes.description = UA_LOCALIZEDTEXT("en-US", "Stop NFC processing.");
    methodAttributes.displayName = UA_LOCALIZEDTEXT("en-US", "NfcStopProcessing");
    methodAttributes.executable = true;
    methodAttributes.userExecutable = true;

    retval = UA_Server_addMethodNode(server,
                            UA_NODEID_NUMERIC(ns[1], 60002),
                            UA_NODEID_NUMERIC(ns[0], UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(ns[0], UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(ns[1], "NfcStopProcessing"),
                            methodAttributes,
                            &generateStopMethodCallback, /* callback of the method node */
                            0, NULL, 0, NULL, NULL, NULL);
#endif

    return retval;
}

/* NfcResumeProcessing - ns=2;i=60003 */

UA_StatusCode
function_namespace_model_3(UA_Server *server, UA_UInt16* ns) {
    UA_StatusCode retval = UA_STATUSCODE_GOOD;

#ifdef UA_ENABLE_METHODCALLS
    /* Method pause without arguments */
    UA_MethodAttributes methodAttributes = UA_MethodAttributes_default;
    methodAttributes.description = UA_LOCALIZEDTEXT("en-US", "Resume NFC processing.");
    methodAttributes.displayName = UA_LOCALIZEDTEXT("en-US", "NfcResumeProcessing");
    methodAttributes.executable = true;
    methodAttributes.userExecutable = true;

    retval = UA_Server_addMethodNode(server,
                            UA_NODEID_NUMERIC(ns[1], 60003),
                            UA_NODEID_NUMERIC(ns[0], UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(ns[0], UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(ns[1], "NfcResumeProcessing"),
                            methodAttributes,
                            &generateResumeMethodCallback, /* callback of the method node */
                            0, NULL, 0, NULL, NULL, NULL);
#endif

    return retval;
}
/* NfcProcessValue - ns=2;i=62000 */

UA_StatusCode
function_namespace_model_4(UA_Server *server, UA_UInt16* ns) {
    UA_StatusCode retval = UA_STATUSCODE_GOOD;

    /* add a variable node to the server */
    UA_VariableAttributes var = UA_VariableAttributes_default;
    var.description = UA_LOCALIZEDTEXT("en-US", "NFC process value.");
    var.displayName = UA_LOCALIZEDTEXT("en-US", "NfcMonitoredProcessValue");
    var.accessLevel = UA_ACCESSLEVELMASK_READ;
    var.dataType = UA_TYPES[UA_TYPES_FLOAT].typeId;
    var.valueRank = UA_VALUERANK_SCALAR;
    UA_Float value = 0.0;
    UA_Variant_setScalar(&var.value, &value, &UA_TYPES[UA_TYPES_FLOAT]);
    retval = UA_Server_addVariableNode(server,
                                       UA_NODEID_NUMERIC(ns[1], 62000),
                                       UA_NODEID_NUMERIC(ns[0], UA_NS0ID_OBJECTSFOLDER),
                                       UA_NODEID_NUMERIC(ns[0], UA_NS0ID_ORGANIZES),
                                       UA_QUALIFIEDNAME(ns[1], "NfcProcessValue"),
                                       UA_NODEID_NUMERIC(ns[0], UA_NS0ID_BASEDATAVARIABLETYPE),
                                       var, NULL, NULL);

    UA_NodeId nodeId = UA_NODEID_NUMERIC(ns[1], 62000);
    UA_MonitoredItemCreateRequest request = UA_MonitoredItemCreateRequest_default(nodeId);
    request.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
    UA_Server_createDataChangeMonitoredItem(server,
                                            UA_TIMESTAMPSTORETURN_SOURCE,
                                            request,
                                            NULL,
                                            processDataChangeMonitoredItemCallback);

    return retval;
}

/* NfcEventProcessing - ns=2;i=61000 */

UA_StatusCode
function_namespace_model_5(UA_Server *server, UA_UInt16* ns) {
    UA_StatusCode retval = UA_STATUSCODE_GOOD;

    UA_ObjectTypeAttributes typeAttributes = UA_ObjectTypeAttributes_default;
    typeAttributes.description = UA_LOCALIZEDTEXT("en-US", "The simple event type we created.");
    typeAttributes.displayName = UA_LOCALIZEDTEXT("en-US", "SimpleEventType");
    retval = UA_Server_addObjectTypeNode(server,
                                         UA_NODEID_NULL,
                                         UA_NODEID_NUMERIC(ns[0], UA_NS0ID_BASEEVENTTYPE),
                                         UA_NODEID_NUMERIC(ns[0], UA_NS0ID_HASSUBTYPE),
                                         UA_QUALIFIEDNAME(ns[0], "SimpleEventType"),
                                         typeAttributes,
                                         NULL,
                                         &eventType);

    /* Method pause without arguments */
    UA_MethodAttributes methodAttributes = UA_MethodAttributes_default;
    methodAttributes.description = UA_LOCALIZEDTEXT("en-US", "Generate an event at NFC processing time.");
    methodAttributes.displayName = UA_LOCALIZEDTEXT("en-US", "NfcEventProcessing");
    methodAttributes.executable = true;
    methodAttributes.userExecutable = true;

    retval = UA_Server_addMethodNode(server,
                            UA_NODEID_NUMERIC(ns[1], 61000),
                            UA_NODEID_NUMERIC(ns[0], UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(ns[0], UA_NS0ID_HASORDEREDCOMPONENT),
                            UA_QUALIFIEDNAME(ns[1], "NfcEventProcessing"),
                            methodAttributes,
                            &generateEventMethodCallback, /* callback of the method node */
                            0, NULL, 0, NULL, NULL, NULL);

    return retval;
}

/* NfcACProcessing - ns=2;i=63000 */

UA_StatusCode
function_namespace_model_6(UA_Server *server, UA_UInt16* ns) {
    UA_NodeId variable_2;
    UA_ValueCallback callback;
    callback.onRead = NULL;

    /**
       * exposed condition 1. We will add to it user specific callbacks when entering enabled state,
       * when acknowledging and when confirming
       */
    UA_StatusCode retval = addACCondition_1(server);
    if (retval != UA_STATUSCODE_GOOD) {
#ifdef S_DEBUG_SYSTEM
        UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                     "adding condition 1 failed. StatusCode %s", UA_StatusCode_name(retval));
#endif
        return retval;
    }

    /**
     * unexposed condition 2. No user specific callbacks, so the server will behave in a standard manner
     * upon entering enabled state, acknowledging and confirming.
     * We will set Retain field to true and enable the condition so we can receive event
     * notifications (we cannot call enable method on unexposed condition using a
     * client like UaExpert or Softing).
     */
    retval = addACCondition_2(server);
    if (retval != UA_STATUSCODE_GOOD) {
#ifdef S_DEBUG_SYSTEM
        UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                     "adding condition 2 failed. StatusCode %s", UA_StatusCode_name(retval));
#endif
        return retval;
    }

    UA_Boolean retain = UA_TRUE;
    UA_Server_writeObjectProperty_scalar(server,
                                         conditionInstanceAC_2,
                                         UA_QUALIFIEDNAME(ns[0], "Retain"),
                                         &retain,
                                         &UA_TYPES[UA_TYPES_BOOLEAN]);

    UA_Variant value;
    UA_Boolean enabledStateId = true;
    UA_QualifiedName enabledStateField = UA_QUALIFIEDNAME(ns[0],"EnabledState");
    UA_QualifiedName enabledStateIdField = UA_QUALIFIEDNAME(ns[0],"Id");
    UA_Variant_setScalar(&value, &enabledStateId, &UA_TYPES[UA_TYPES_BOOLEAN]);
    retval = UA_Server_setConditionVariableFieldProperty(server,
                                                         conditionInstanceAC_2,
                                                         &value,
                                                         enabledStateField,
                                                         enabledStateIdField);
    if (retval != UA_STATUSCODE_GOOD) {
#ifdef S_DEBUG_SYSTEM
        UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                     "Setting EnabledState/Id Field failed. StatusCode %s", UA_StatusCode_name(retval));
#endif
        return retval;
    }

    /**
     * severity can change internally also when the condition disabled and retain is false. However,
     * in this case no events will be generated.
     */
    addACVariableChangeSeverityOfCondition(server, &variable_2);

    callback.onWrite = afterACWriteVariableCallback;
    retval = UA_Server_setVariableNode_valueCallback(server, variable_2, callback);
    if (retval != UA_STATUSCODE_GOOD) {
#ifdef S_DEBUG_SYSTEM
        UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                     "setting variable 2 Callback failed. StatusCode %s", UA_StatusCode_name(retval));
#endif
        return retval;
    }

    return retval;
}

/* Namespace model function */

UA_StatusCode namespace_model(UA_Server *server) {
    UA_StatusCode retval = UA_STATUSCODE_GOOD;
    /* Use namespace ids generated by the server */
    ns[0] = UA_Server_addNamespace(server, "http://opcfoundation.org/UA/");
    ns[1] = UA_Server_addNamespace(server, "http://opcfoundation.org/UA/model");
    bool dummy = (
                !(retval = function_namespace_model_0(server, ns)) &&
                !(retval = function_namespace_model_1(server, ns)) &&
                !(retval = function_namespace_model_2(server, ns)) &&
                !(retval = function_namespace_model_3(server, ns)) &&
                !(retval = function_namespace_model_4(server, ns)) &&
                !(retval = function_namespace_model_5(server, ns)) &&
                !(retval = function_namespace_model_6(server, ns))
    ); (void)(dummy);
    return retval;
}
