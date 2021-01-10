/* Generated from Opc_Ua.EUROMAP77.1_00.Types.bsd with script /home/pi/open62541/open62541/tools/generate_datatypes.py
 * on host pi-VirtualBox by user pi at 2019-12-05 09:27:18 */

#ifdef UA_ENABLE_AMALGAMATION
# include "open62541.h"
#else
# include "ua_types_encoding_binary.h"
# include "types_euromap77_generated.h"
#endif



/* IMMMessageClassificationEnumeration */
static UA_INLINE size_t
UA_IMMMessageClassificationEnumeration_calcSizeBinary(const UA_IMMMessageClassificationEnumeration *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_EUROMAP77[UA_TYPES_EUROMAP77_IMMMESSAGECLASSIFICATIONENUMERATION]);
}
static UA_INLINE UA_StatusCode
UA_IMMMessageClassificationEnumeration_encodeBinary(const UA_IMMMessageClassificationEnumeration *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_EUROMAP77[UA_TYPES_EUROMAP77_IMMMESSAGECLASSIFICATIONENUMERATION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_IMMMessageClassificationEnumeration_decodeBinary(const UA_ByteString *src, size_t *offset, UA_IMMMessageClassificationEnumeration *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_EUROMAP77[UA_TYPES_EUROMAP77_IMMMESSAGECLASSIFICATIONENUMERATION], NULL);
}
