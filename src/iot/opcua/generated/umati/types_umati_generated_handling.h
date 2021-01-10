/* Generated from umati.bsd with script /home/pi/open62541/open62541/tools/generate_datatypes.py
 * on host pi-VirtualBox by user pi at 2019-12-13 05:27:39 */

#ifndef TYPES_UMATI_GENERATED_HANDLING_H_
#define TYPES_UMATI_GENERATED_HANDLING_H_

#include "types_umati_generated.h"

_UA_BEGIN_DECLS

#if defined(__GNUC__) && __GNUC__ >= 4 && __GNUC_MINOR__ >= 6
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wmissing-field-initializers"
# pragma GCC diagnostic ignored "-Wmissing-braces"
#endif


/* NCProcessing */
static UA_INLINE void
UA_NCProcessing_init(UA_NCProcessing *p) {
    memset(p, 0, sizeof(UA_NCProcessing));
}

static UA_INLINE UA_NCProcessing *
UA_NCProcessing_new(void) {
    return (UA_NCProcessing*)UA_new(&UA_TYPES_UMATI[UA_TYPES_UMATI_NCPROCESSING]);
}

static UA_INLINE UA_StatusCode
UA_NCProcessing_copy(const UA_NCProcessing *src, UA_NCProcessing *dst) {
    return UA_copy(src, dst, &UA_TYPES_UMATI[UA_TYPES_UMATI_NCPROCESSING]);
}

static UA_INLINE void
UA_NCProcessing_deleteMembers(UA_NCProcessing *p) {
    UA_clear(p, &UA_TYPES_UMATI[UA_TYPES_UMATI_NCPROCESSING]);
}

static UA_INLINE void
UA_NCProcessing_clear(UA_NCProcessing *p) {
    UA_clear(p, &UA_TYPES_UMATI[UA_TYPES_UMATI_NCPROCESSING]);
}

static UA_INLINE void
UA_NCProcessing_delete(UA_NCProcessing *p) {
    UA_delete(p, &UA_TYPES_UMATI[UA_TYPES_UMATI_NCPROCESSING]);
}

/* ChannelState */
static UA_INLINE void
UA_ChannelState_init(UA_ChannelState *p) {
    memset(p, 0, sizeof(UA_ChannelState));
}

static UA_INLINE UA_ChannelState *
UA_ChannelState_new(void) {
    return (UA_ChannelState*)UA_new(&UA_TYPES_UMATI[UA_TYPES_UMATI_CHANNELSTATE]);
}

static UA_INLINE UA_StatusCode
UA_ChannelState_copy(const UA_ChannelState *src, UA_ChannelState *dst) {
    return UA_copy(src, dst, &UA_TYPES_UMATI[UA_TYPES_UMATI_CHANNELSTATE]);
}

static UA_INLINE void
UA_ChannelState_deleteMembers(UA_ChannelState *p) {
    UA_clear(p, &UA_TYPES_UMATI[UA_TYPES_UMATI_CHANNELSTATE]);
}

static UA_INLINE void
UA_ChannelState_clear(UA_ChannelState *p) {
    UA_clear(p, &UA_TYPES_UMATI[UA_TYPES_UMATI_CHANNELSTATE]);
}

static UA_INLINE void
UA_ChannelState_delete(UA_ChannelState *p) {
    UA_delete(p, &UA_TYPES_UMATI[UA_TYPES_UMATI_CHANNELSTATE]);
}

/* LampStatus */
static UA_INLINE void
UA_LampStatus_init(UA_LampStatus *p) {
    memset(p, 0, sizeof(UA_LampStatus));
}

static UA_INLINE UA_LampStatus *
UA_LampStatus_new(void) {
    return (UA_LampStatus*)UA_new(&UA_TYPES_UMATI[UA_TYPES_UMATI_LAMPSTATUS]);
}

static UA_INLINE UA_StatusCode
UA_LampStatus_copy(const UA_LampStatus *src, UA_LampStatus *dst) {
    return UA_copy(src, dst, &UA_TYPES_UMATI[UA_TYPES_UMATI_LAMPSTATUS]);
}

static UA_INLINE void
UA_LampStatus_deleteMembers(UA_LampStatus *p) {
    UA_clear(p, &UA_TYPES_UMATI[UA_TYPES_UMATI_LAMPSTATUS]);
}

static UA_INLINE void
UA_LampStatus_clear(UA_LampStatus *p) {
    UA_clear(p, &UA_TYPES_UMATI[UA_TYPES_UMATI_LAMPSTATUS]);
}

static UA_INLINE void
UA_LampStatus_delete(UA_LampStatus *p) {
    UA_delete(p, &UA_TYPES_UMATI[UA_TYPES_UMATI_LAMPSTATUS]);
}

/* ProcessIrregularity */
static UA_INLINE void
UA_ProcessIrregularity_init(UA_ProcessIrregularity *p) {
    memset(p, 0, sizeof(UA_ProcessIrregularity));
}

static UA_INLINE UA_ProcessIrregularity *
UA_ProcessIrregularity_new(void) {
    return (UA_ProcessIrregularity*)UA_new(&UA_TYPES_UMATI[UA_TYPES_UMATI_PROCESSIRREGULARITY]);
}

static UA_INLINE UA_StatusCode
UA_ProcessIrregularity_copy(const UA_ProcessIrregularity *src, UA_ProcessIrregularity *dst) {
    return UA_copy(src, dst, &UA_TYPES_UMATI[UA_TYPES_UMATI_PROCESSIRREGULARITY]);
}

static UA_INLINE void
UA_ProcessIrregularity_deleteMembers(UA_ProcessIrregularity *p) {
    UA_clear(p, &UA_TYPES_UMATI[UA_TYPES_UMATI_PROCESSIRREGULARITY]);
}

static UA_INLINE void
UA_ProcessIrregularity_clear(UA_ProcessIrregularity *p) {
    UA_clear(p, &UA_TYPES_UMATI[UA_TYPES_UMATI_PROCESSIRREGULARITY]);
}

static UA_INLINE void
UA_ProcessIrregularity_delete(UA_ProcessIrregularity *p) {
    UA_delete(p, &UA_TYPES_UMATI[UA_TYPES_UMATI_PROCESSIRREGULARITY]);
}

/* WearIndication */
static UA_INLINE void
UA_WearIndication_init(UA_WearIndication *p) {
    memset(p, 0, sizeof(UA_WearIndication));
}

static UA_INLINE UA_WearIndication *
UA_WearIndication_new(void) {
    return (UA_WearIndication*)UA_new(&UA_TYPES_UMATI[UA_TYPES_UMATI_WEARINDICATION]);
}

static UA_INLINE UA_StatusCode
UA_WearIndication_copy(const UA_WearIndication *src, UA_WearIndication *dst) {
    return UA_copy(src, dst, &UA_TYPES_UMATI[UA_TYPES_UMATI_WEARINDICATION]);
}

static UA_INLINE void
UA_WearIndication_deleteMembers(UA_WearIndication *p) {
    UA_clear(p, &UA_TYPES_UMATI[UA_TYPES_UMATI_WEARINDICATION]);
}

static UA_INLINE void
UA_WearIndication_clear(UA_WearIndication *p) {
    UA_clear(p, &UA_TYPES_UMATI[UA_TYPES_UMATI_WEARINDICATION]);
}

static UA_INLINE void
UA_WearIndication_delete(UA_WearIndication *p) {
    UA_delete(p, &UA_TYPES_UMATI[UA_TYPES_UMATI_WEARINDICATION]);
}

/* PartQuality */
static UA_INLINE void
UA_PartQuality_init(UA_PartQuality *p) {
    memset(p, 0, sizeof(UA_PartQuality));
}

static UA_INLINE UA_PartQuality *
UA_PartQuality_new(void) {
    return (UA_PartQuality*)UA_new(&UA_TYPES_UMATI[UA_TYPES_UMATI_PARTQUALITY]);
}

static UA_INLINE UA_StatusCode
UA_PartQuality_copy(const UA_PartQuality *src, UA_PartQuality *dst) {
    return UA_copy(src, dst, &UA_TYPES_UMATI[UA_TYPES_UMATI_PARTQUALITY]);
}

static UA_INLINE void
UA_PartQuality_deleteMembers(UA_PartQuality *p) {
    UA_clear(p, &UA_TYPES_UMATI[UA_TYPES_UMATI_PARTQUALITY]);
}

static UA_INLINE void
UA_PartQuality_clear(UA_PartQuality *p) {
    UA_clear(p, &UA_TYPES_UMATI[UA_TYPES_UMATI_PARTQUALITY]);
}

static UA_INLINE void
UA_PartQuality_delete(UA_PartQuality *p) {
    UA_delete(p, &UA_TYPES_UMATI[UA_TYPES_UMATI_PARTQUALITY]);
}

/* ControlMode */
static UA_INLINE void
UA_ControlMode_init(UA_ControlMode *p) {
    memset(p, 0, sizeof(UA_ControlMode));
}

static UA_INLINE UA_ControlMode *
UA_ControlMode_new(void) {
    return (UA_ControlMode*)UA_new(&UA_TYPES_UMATI[UA_TYPES_UMATI_CONTROLMODE]);
}

static UA_INLINE UA_StatusCode
UA_ControlMode_copy(const UA_ControlMode *src, UA_ControlMode *dst) {
    return UA_copy(src, dst, &UA_TYPES_UMATI[UA_TYPES_UMATI_CONTROLMODE]);
}

static UA_INLINE void
UA_ControlMode_deleteMembers(UA_ControlMode *p) {
    UA_clear(p, &UA_TYPES_UMATI[UA_TYPES_UMATI_CONTROLMODE]);
}

static UA_INLINE void
UA_ControlMode_clear(UA_ControlMode *p) {
    UA_clear(p, &UA_TYPES_UMATI[UA_TYPES_UMATI_CONTROLMODE]);
}

static UA_INLINE void
UA_ControlMode_delete(UA_ControlMode *p) {
    UA_delete(p, &UA_TYPES_UMATI[UA_TYPES_UMATI_CONTROLMODE]);
}

/* LampColor */
static UA_INLINE void
UA_LampColor_init(UA_LampColor *p) {
    memset(p, 0, sizeof(UA_LampColor));
}

static UA_INLINE UA_LampColor *
UA_LampColor_new(void) {
    return (UA_LampColor*)UA_new(&UA_TYPES_UMATI[UA_TYPES_UMATI_LAMPCOLOR]);
}

static UA_INLINE UA_StatusCode
UA_LampColor_copy(const UA_LampColor *src, UA_LampColor *dst) {
    return UA_copy(src, dst, &UA_TYPES_UMATI[UA_TYPES_UMATI_LAMPCOLOR]);
}

static UA_INLINE void
UA_LampColor_deleteMembers(UA_LampColor *p) {
    UA_clear(p, &UA_TYPES_UMATI[UA_TYPES_UMATI_LAMPCOLOR]);
}

static UA_INLINE void
UA_LampColor_clear(UA_LampColor *p) {
    UA_clear(p, &UA_TYPES_UMATI[UA_TYPES_UMATI_LAMPCOLOR]);
}

static UA_INLINE void
UA_LampColor_delete(UA_LampColor *p) {
    UA_delete(p, &UA_TYPES_UMATI[UA_TYPES_UMATI_LAMPCOLOR]);
}

/* SafetyMode */
static UA_INLINE void
UA_SafetyMode_init(UA_SafetyMode *p) {
    memset(p, 0, sizeof(UA_SafetyMode));
}

static UA_INLINE UA_SafetyMode *
UA_SafetyMode_new(void) {
    return (UA_SafetyMode*)UA_new(&UA_TYPES_UMATI[UA_TYPES_UMATI_SAFETYMODE]);
}

static UA_INLINE UA_StatusCode
UA_SafetyMode_copy(const UA_SafetyMode *src, UA_SafetyMode *dst) {
    return UA_copy(src, dst, &UA_TYPES_UMATI[UA_TYPES_UMATI_SAFETYMODE]);
}

static UA_INLINE void
UA_SafetyMode_deleteMembers(UA_SafetyMode *p) {
    UA_clear(p, &UA_TYPES_UMATI[UA_TYPES_UMATI_SAFETYMODE]);
}

static UA_INLINE void
UA_SafetyMode_clear(UA_SafetyMode *p) {
    UA_clear(p, &UA_TYPES_UMATI[UA_TYPES_UMATI_SAFETYMODE]);
}

static UA_INLINE void
UA_SafetyMode_delete(UA_SafetyMode *p) {
    UA_delete(p, &UA_TYPES_UMATI[UA_TYPES_UMATI_SAFETYMODE]);
}

#if defined(__GNUC__) && __GNUC__ >= 4 && __GNUC_MINOR__ >= 6
# pragma GCC diagnostic pop
#endif

_UA_END_DECLS

#endif /* TYPES_UMATI_GENERATED_HANDLING_H_ */
