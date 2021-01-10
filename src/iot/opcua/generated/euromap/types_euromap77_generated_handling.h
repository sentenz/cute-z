/* Generated from Opc_Ua.EUROMAP77.1_00.Types.bsd with script /home/pi/open62541/open62541/tools/generate_datatypes.py
 * on host pi-VirtualBox by user pi at 2019-12-05 09:27:18 */

#ifndef TYPES_EUROMAP77_GENERATED_HANDLING_H_
#define TYPES_EUROMAP77_GENERATED_HANDLING_H_

#include "types_euromap77_generated.h"

_UA_BEGIN_DECLS

#if defined(__GNUC__) && __GNUC__ >= 4 && __GNUC_MINOR__ >= 6
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wmissing-field-initializers"
# pragma GCC diagnostic ignored "-Wmissing-braces"
#endif


/* IMMMessageClassificationEnumeration */
static UA_INLINE void
UA_IMMMessageClassificationEnumeration_init(UA_IMMMessageClassificationEnumeration *p) {
    memset(p, 0, sizeof(UA_IMMMessageClassificationEnumeration));
}

static UA_INLINE UA_IMMMessageClassificationEnumeration *
UA_IMMMessageClassificationEnumeration_new(void) {
    return (UA_IMMMessageClassificationEnumeration*)UA_new(&UA_TYPES_EUROMAP77[UA_TYPES_EUROMAP77_IMMMESSAGECLASSIFICATIONENUMERATION]);
}

static UA_INLINE UA_StatusCode
UA_IMMMessageClassificationEnumeration_copy(const UA_IMMMessageClassificationEnumeration *src, UA_IMMMessageClassificationEnumeration *dst) {
    return UA_copy(src, dst, &UA_TYPES_EUROMAP77[UA_TYPES_EUROMAP77_IMMMESSAGECLASSIFICATIONENUMERATION]);
}

static UA_INLINE void
UA_IMMMessageClassificationEnumeration_deleteMembers(UA_IMMMessageClassificationEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP77[UA_TYPES_EUROMAP77_IMMMESSAGECLASSIFICATIONENUMERATION]);
}

static UA_INLINE void
UA_IMMMessageClassificationEnumeration_clear(UA_IMMMessageClassificationEnumeration *p) {
    UA_clear(p, &UA_TYPES_EUROMAP77[UA_TYPES_EUROMAP77_IMMMESSAGECLASSIFICATIONENUMERATION]);
}

static UA_INLINE void
UA_IMMMessageClassificationEnumeration_delete(UA_IMMMessageClassificationEnumeration *p) {
    UA_delete(p, &UA_TYPES_EUROMAP77[UA_TYPES_EUROMAP77_IMMMESSAGECLASSIFICATIONENUMERATION]);
}

#if defined(__GNUC__) && __GNUC__ >= 4 && __GNUC_MINOR__ >= 6
# pragma GCC diagnostic pop
#endif

_UA_END_DECLS

#endif /* TYPES_EUROMAP77_GENERATED_HANDLING_H_ */
