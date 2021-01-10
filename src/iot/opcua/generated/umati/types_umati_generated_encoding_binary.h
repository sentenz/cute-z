/* Generated from umati.bsd with script /home/pi/open62541/open62541/tools/generate_datatypes.py
 * on host pi-VirtualBox by user pi at 2019-12-13 05:27:39 */

#ifdef UA_ENABLE_AMALGAMATION
# include "open62541.h"
#else
# include "ua_types_encoding_binary.h"
# include "types_umati_generated.h"
#endif



/* NCProcessing */
static UA_INLINE size_t
UA_NCProcessing_calcSizeBinary(const UA_NCProcessing *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_UMATI[UA_TYPES_UMATI_NCPROCESSING]);
}
static UA_INLINE UA_StatusCode
UA_NCProcessing_encodeBinary(const UA_NCProcessing *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_UMATI[UA_TYPES_UMATI_NCPROCESSING], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_NCProcessing_decodeBinary(const UA_ByteString *src, size_t *offset, UA_NCProcessing *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_UMATI[UA_TYPES_UMATI_NCPROCESSING], NULL);
}

/* ChannelState */
static UA_INLINE size_t
UA_ChannelState_calcSizeBinary(const UA_ChannelState *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_UMATI[UA_TYPES_UMATI_CHANNELSTATE]);
}
static UA_INLINE UA_StatusCode
UA_ChannelState_encodeBinary(const UA_ChannelState *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_UMATI[UA_TYPES_UMATI_CHANNELSTATE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ChannelState_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ChannelState *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_UMATI[UA_TYPES_UMATI_CHANNELSTATE], NULL);
}

/* LampStatus */
static UA_INLINE size_t
UA_LampStatus_calcSizeBinary(const UA_LampStatus *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_UMATI[UA_TYPES_UMATI_LAMPSTATUS]);
}
static UA_INLINE UA_StatusCode
UA_LampStatus_encodeBinary(const UA_LampStatus *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_UMATI[UA_TYPES_UMATI_LAMPSTATUS], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_LampStatus_decodeBinary(const UA_ByteString *src, size_t *offset, UA_LampStatus *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_UMATI[UA_TYPES_UMATI_LAMPSTATUS], NULL);
}

/* ProcessIrregularity */
static UA_INLINE size_t
UA_ProcessIrregularity_calcSizeBinary(const UA_ProcessIrregularity *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_UMATI[UA_TYPES_UMATI_PROCESSIRREGULARITY]);
}
static UA_INLINE UA_StatusCode
UA_ProcessIrregularity_encodeBinary(const UA_ProcessIrregularity *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_UMATI[UA_TYPES_UMATI_PROCESSIRREGULARITY], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ProcessIrregularity_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ProcessIrregularity *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_UMATI[UA_TYPES_UMATI_PROCESSIRREGULARITY], NULL);
}

/* WearIndication */
static UA_INLINE size_t
UA_WearIndication_calcSizeBinary(const UA_WearIndication *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_UMATI[UA_TYPES_UMATI_WEARINDICATION]);
}
static UA_INLINE UA_StatusCode
UA_WearIndication_encodeBinary(const UA_WearIndication *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_UMATI[UA_TYPES_UMATI_WEARINDICATION], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_WearIndication_decodeBinary(const UA_ByteString *src, size_t *offset, UA_WearIndication *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_UMATI[UA_TYPES_UMATI_WEARINDICATION], NULL);
}

/* PartQuality */
static UA_INLINE size_t
UA_PartQuality_calcSizeBinary(const UA_PartQuality *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_UMATI[UA_TYPES_UMATI_PARTQUALITY]);
}
static UA_INLINE UA_StatusCode
UA_PartQuality_encodeBinary(const UA_PartQuality *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_UMATI[UA_TYPES_UMATI_PARTQUALITY], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_PartQuality_decodeBinary(const UA_ByteString *src, size_t *offset, UA_PartQuality *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_UMATI[UA_TYPES_UMATI_PARTQUALITY], NULL);
}

/* ControlMode */
static UA_INLINE size_t
UA_ControlMode_calcSizeBinary(const UA_ControlMode *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_UMATI[UA_TYPES_UMATI_CONTROLMODE]);
}
static UA_INLINE UA_StatusCode
UA_ControlMode_encodeBinary(const UA_ControlMode *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_UMATI[UA_TYPES_UMATI_CONTROLMODE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_ControlMode_decodeBinary(const UA_ByteString *src, size_t *offset, UA_ControlMode *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_UMATI[UA_TYPES_UMATI_CONTROLMODE], NULL);
}

/* LampColor */
static UA_INLINE size_t
UA_LampColor_calcSizeBinary(const UA_LampColor *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_UMATI[UA_TYPES_UMATI_LAMPCOLOR]);
}
static UA_INLINE UA_StatusCode
UA_LampColor_encodeBinary(const UA_LampColor *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_UMATI[UA_TYPES_UMATI_LAMPCOLOR], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_LampColor_decodeBinary(const UA_ByteString *src, size_t *offset, UA_LampColor *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_UMATI[UA_TYPES_UMATI_LAMPCOLOR], NULL);
}

/* SafetyMode */
static UA_INLINE size_t
UA_SafetyMode_calcSizeBinary(const UA_SafetyMode *src) {
    return UA_calcSizeBinary(src, &UA_TYPES_UMATI[UA_TYPES_UMATI_SAFETYMODE]);
}
static UA_INLINE UA_StatusCode
UA_SafetyMode_encodeBinary(const UA_SafetyMode *src, UA_Byte **bufPos, const UA_Byte *bufEnd) {
    return UA_encodeBinary(src, &UA_TYPES_UMATI[UA_TYPES_UMATI_SAFETYMODE], bufPos, &bufEnd, NULL, NULL);
}
static UA_INLINE UA_StatusCode
UA_SafetyMode_decodeBinary(const UA_ByteString *src, size_t *offset, UA_SafetyMode *dst) {
    return UA_decodeBinary(src, offset, dst, &UA_TYPES_UMATI[UA_TYPES_UMATI_SAFETYMODE], NULL);
}
