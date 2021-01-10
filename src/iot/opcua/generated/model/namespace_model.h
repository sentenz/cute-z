#ifndef NAMESPACE_MODEL_H_
#define NAMESPACE_MODEL_H_

#ifdef UA_ENABLE_AMALGAMATION
# include "open62541.h"
#else // UA_ENABLE_AMALGAMATION
# include <open62541/server.h>
#endif

_UA_BEGIN_DECLS


/* Method variables */

extern UA_Boolean ua_nfcRunning;
extern bool ua_nfcStart;
extern bool ua_nfcPause;
extern bool ua_nfcStop;
extern bool ua_nfcResume;
extern int ua_nfcData;

/* A&C variables */

UA_NodeId conditionSourceAC;
UA_NodeId conditionInstanceAC_1;
UA_NodeId conditionInstanceAC_2;

/* Event variables */

UA_NodeId eventType;

/* Namespace variables */

UA_UInt16 ns[2];

/* Event functions */

UA_StatusCode setupEvent(UA_Server *server, UA_NodeId *outId);
UA_StatusCode triggerEvent(UA_Server *server);
UA_StatusCode generateEventMethodCallback(UA_Server *server,
                            const UA_NodeId *sessionId, void *sessionHandle,
                            const UA_NodeId *methodId, void *methodContext,
                            const UA_NodeId *objectId, void *objectContext,
                            size_t inputSize, const UA_Variant *input,
                            size_t outputSize, UA_Variant *output);

/* A&C functions */

UA_StatusCode addACConditionSourceObject(UA_Server *server);
UA_StatusCode addACCondition_1(UA_Server *server);
UA_StatusCode addACCondition_2(UA_Server *server);
void addACVariableChangeSeverityOfCondition(UA_Server *server, UA_NodeId* outNodeId);
extern UA_StatusCode setSeverityOfCondition(UA_Server *server, UA_UInt16 severity);
void afterACWriteVariableCallback(UA_Server *server,
               const UA_NodeId *sessionId, void *sessionContext,
               const UA_NodeId *nodeId, void *nodeContext,
               const UA_NumericRange *range, const UA_DataValue *data);

/* Method start callback */

UA_StatusCode generateStartMethodCallback(UA_Server *server,
           const UA_NodeId *sessionId, void *sessionContext,
           const UA_NodeId *methodId, void *methodContext,
           const UA_NodeId *objectId, void *objectContext,
           size_t inputSize, const UA_Variant *input,
           size_t outputSize, UA_Variant *output);
UA_StatusCode generatePauseMethodCallback(UA_Server *server,
           const UA_NodeId *sessionId, void *sessionContext,
           const UA_NodeId *methodId, void *methodContext,
           const UA_NodeId *objectId, void *objectContext,
           size_t inputSize, const UA_Variant *input,
           size_t outputSize, UA_Variant *output);
UA_StatusCode generateStopMethodCallback(UA_Server *server,
           const UA_NodeId *sessionId, void *sessionContext,
           const UA_NodeId *methodId, void *methodContext,
           const UA_NodeId *objectId, void *objectContext,
           size_t inputSize, const UA_Variant *input,
           size_t outputSize, UA_Variant *output);
UA_StatusCode generateResumeMethodCallback(UA_Server *server,
           const UA_NodeId *sessionId, void *sessionContext,
           const UA_NodeId *methodId, void *methodContext,
           const UA_NodeId *objectId, void *objectContext,
           size_t inputSize, const UA_Variant *input,
           size_t outputSize, UA_Variant *output);

/* Monitored item update */

extern UA_StatusCode updateMonitoredItem(UA_Server *server, UA_Float value);
void processDataChangeMonitoredItemCallback(UA_Server *server, UA_UInt32 monitoredItemId,
                               void *monitoredItemContext, const UA_NodeId *nodeId,
                               void *nodeContext, UA_UInt32 attributeId,
                               const UA_DataValue *value);

/* Namespace model function */

UA_StatusCode function_namespace_model_0(UA_Server *server, UA_UInt16* ns);
UA_StatusCode function_namespace_model_1(UA_Server *server, UA_UInt16* ns);
UA_StatusCode function_namespace_model_2(UA_Server *server, UA_UInt16* ns);
UA_StatusCode function_namespace_model_3(UA_Server *server, UA_UInt16* ns);
UA_StatusCode function_namespace_model_4(UA_Server *server, UA_UInt16* ns);
UA_StatusCode function_namespace_model_5(UA_Server *server, UA_UInt16* ns);
UA_StatusCode function_namespace_model_6(UA_Server *server, UA_UInt16* ns);

extern UA_StatusCode namespace_model(UA_Server *server);

_UA_END_DECLS

#endif /* NAMESPACE_MODEL_H_ */
