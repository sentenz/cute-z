/* Generated from Opc.Ua.Di.Types.bsd with script /home/pi/open62541/open62541/tools/generate_datatypes.py
 * on host pi-VirtualBox by user pi at 2019-12-03 10:34:23 */

#ifndef TYPES_DI_GENERATED_H_
#define TYPES_DI_GENERATED_H_

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
#define UA_TYPES_DI_COUNT 5
extern UA_EXPORT const UA_DataType UA_TYPES_DI[UA_TYPES_DI_COUNT];

/**
 * FetchResultDataType
 * ^^^^^^^^^^^^^^^^^^^
 */
typedef void * UA_FetchResultDataType;

#define UA_TYPES_DI_FETCHRESULTDATATYPE 0

/**
 * DeviceHealthEnumeration
 * ^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef enum {
    UA_DEVICEHEALTHENUMERATION_NORMAL = 0,
    UA_DEVICEHEALTHENUMERATION_FAILURE = 1,
    UA_DEVICEHEALTHENUMERATION_CHECK_FUNCTION = 2,
    UA_DEVICEHEALTHENUMERATION_OFF_SPEC = 3,
    UA_DEVICEHEALTHENUMERATION_MAINTENANCE_REQUIRED = 4,
    __UA_DEVICEHEALTHENUMERATION_FORCE32BIT = 0x7fffffff
} UA_DeviceHealthEnumeration;
UA_STATIC_ASSERT(sizeof(UA_DeviceHealthEnumeration) == sizeof(UA_Int32), enum_must_be_32bit);

#define UA_TYPES_DI_DEVICEHEALTHENUMERATION 1

/**
 * ParameterResultDataType
 * ^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    size_t nodePathSize;
    UA_QualifiedName *nodePath;
    UA_StatusCode statusCode;
    UA_DiagnosticInfo diagnostics;
} UA_ParameterResultDataType;

#define UA_TYPES_DI_PARAMETERRESULTDATATYPE 2

/**
 * TransferResultErrorDataType
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_Int32 status;
    UA_DiagnosticInfo diagnostics;
} UA_TransferResultErrorDataType;

#define UA_TYPES_DI_TRANSFERRESULTERRORDATATYPE 3

/**
 * TransferResultDataDataType
 * ^^^^^^^^^^^^^^^^^^^^^^^^^^
 */
typedef struct {
    UA_Int32 sequenceNumber;
    UA_Boolean endOfResults;
    size_t parameterDefsSize;
    UA_ParameterResultDataType *parameterDefs;
} UA_TransferResultDataDataType;

#define UA_TYPES_DI_TRANSFERRESULTDATADATATYPE 4


_UA_END_DECLS

#endif /* TYPES_DI_GENERATED_H_ */
