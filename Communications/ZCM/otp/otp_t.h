// THIS IS AN AUTOMATICALLY GENERATED FILE.
// DO NOT MODIFY BY HAND!!
//
// Generated by zcm-gen

#include <stdint.h>
#include <stdlib.h>
#include <zcm/zcm_coretypes.h>
#include <zcm/zcm.h>

#ifndef _otp_t_h
#define _otp_t_h

#ifdef __cplusplus
extern "C" {
#endif

#define OTP_T_IS_LITTLE_ENDIAN 0
typedef struct _otp_t otp_t;
struct _otp_t
{
    int8_t     state;
    float      roll;
    float      pitch;
    float      yaw;
    float      acceleration;
    float      position;
    float      angular_rate;
};

/**
 * Create a deep copy of a otp_t.
 * When no longer needed, destroy it with otp_t_destroy()
 */
otp_t* otp_t_copy(const otp_t* to_copy);

/**
 * Destroy an instance of otp_t created by otp_t_copy()
 */
void otp_t_destroy(otp_t* to_destroy);

/**
 * Identifies a single subscription.  This is an opaque data type.
 */
typedef struct _otp_t_subscription_t otp_t_subscription_t;

/**
 * Prototype for a callback function invoked when a message of type
 * otp_t is received.
 */
typedef void(*otp_t_handler_t)(const zcm_recv_buf_t* rbuf,
             const char* channel, const otp_t* msg, void* userdata);

/**
 * Publish a message of type otp_t using ZCM.
 *
 * @param zcm The ZCM instance to publish with.
 * @param channel The channel to publish on.
 * @param msg The message to publish.
 * @return 0 on success, <0 on error.  Success means ZCM has transferred
 * responsibility of the message data to the OS.
 */
int otp_t_publish(zcm_t* zcm, const char* channel, const otp_t* msg);

/**
 * Subscribe to messages of type otp_t using ZCM.
 *
 * @param zcm The ZCM instance to subscribe with.
 * @param channel The channel to subscribe to.
 * @param handler The callback function invoked by ZCM when a message is received.
 *                This function is invoked by ZCM during calls to zcm_handle() and
 *                zcm_handle_timeout().
 * @param userdata An opaque pointer passed to @p handler when it is invoked.
 * @return pointer to subscription type, NULL if failure. Must clean up
 *         dynamic memory by passing the pointer to otp_t_unsubscribe.
 */
otp_t_subscription_t* otp_t_subscribe(zcm_t* zcm, const char* channel, otp_t_handler_t handler, void* userdata);

/**
 * Removes and destroys a subscription created by otp_t_subscribe()
 */
int otp_t_unsubscribe(zcm_t* zcm, otp_t_subscription_t* hid);
/**
 * Encode a message of type otp_t into binary form.
 *
 * @param buf The output buffer.
 * @param offset Encoding starts at this byte offset into @p buf.
 * @param maxlen Maximum number of bytes to write.  This should generally
 *               be equal to otp_t_encoded_size().
 * @param msg The message to encode.
 * @return The number of bytes encoded, or <0 if an error occured.
 */
int otp_t_encode(void* buf, uint32_t offset, uint32_t maxlen, const otp_t* p);

/**
 * Decode a message of type otp_t from binary form.
 * When decoding messages containing strings or variable-length arrays, this
 * function may allocate memory.  When finished with the decoded message,
 * release allocated resources with otp_t_decode_cleanup().
 *
 * @param buf The buffer containing the encoded message
 * @param offset The byte offset into @p buf where the encoded message starts.
 * @param maxlen The maximum number of bytes to read while decoding.
 * @param msg Output parameter where the decoded message is stored
 * @return The number of bytes decoded, or <0 if an error occured.
 */
int otp_t_decode(const void* buf, uint32_t offset, uint32_t maxlen, otp_t* msg);

/**
 * Release resources allocated by otp_t_decode()
 * @return 0
 */
int otp_t_decode_cleanup(otp_t* p);

/**
 * Check how many bytes are required to encode a message of type otp_t
 */
uint32_t otp_t_encoded_size(const otp_t* p);

// ZCM support functions. Users should not call these
int64_t  __otp_t_get_hash(void);
uint64_t __otp_t_hash_recursive(const __zcm_hash_ptr* p);
int      __otp_t_encode_array(void* buf, uint32_t offset, uint32_t maxlen, const otp_t* p, uint32_t elements);
int      __otp_t_decode_array(const void* buf, uint32_t offset, uint32_t maxlen, otp_t* p, uint32_t elements);
int      __otp_t_decode_array_cleanup(otp_t* p, uint32_t elements);
uint32_t __otp_t_encoded_array_size(const otp_t* p, uint32_t elements);
uint32_t __otp_t_clone_array(const otp_t* p, otp_t* q, uint32_t elements);

#ifdef __cplusplus
}
#endif

#endif
