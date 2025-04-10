/**
 ******************************************************************************
 * @file    sm.h
 * @author  AMS - HEA&RF BU
 * @brief   Header file for BlueNRG's security manager
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2012 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
#ifndef __SM_H__
#define __SM_H__

/******************************************************************************
 * Macros
 *****************************************************************************/

/**
 * @defgroup HIGH_LEVEL_INTERFACE HIGH_LEVEL_INTERFACE
 * @{
 */

/**
 * @addtogroup ACI_GAP ACI_GAP
 * @brief API for GAP layer.
 * @{
 */

/* IO capabilities */
/**
 * @anchor IO_capabilities
 * @name IO capabilities
 * @{
 */
#define IO_CAP_DISPLAY_ONLY (0x00)
#define IO_CAP_DISPLAY_YES_NO (0x01)
#define IO_CAP_KEYBOARD_ONLY (0x02)
#define IO_CAP_NO_INPUT_NO_OUTPUT (0x03)
#define IO_CAP_KEYBOARD_DISPLAY (0x04)
/**
 * @}
 */

/**
 * @anchor Auth_req
 * @name Authentication requirements
 * @{
 */
#define BONDING (0x01)
#define NO_BONDING (0x00)
/**
 * @}
 */

/**
 * @anchor MITM_req
 * @name MITM protection requirements
 * @{
 */
#define MITM_PROTECTION_NOT_REQUIRED (0x00)
#define MITM_PROTECTION_REQUIRED (0x01)
/**
 * @}
 */

/**
 * @anchor OOB_Data
 * @name Out-Of-Band data
 * @{
 */
#define OOB_AUTH_DATA_ABSENT (0x00)
#define OOB_AUTH_DATA_PRESENT (0x01)
/**
 * @}
 */

/**
 * @anchor Author_req
 * @name Authorization requirements
 * @{
 */
#define AUTHORIZATION_NOT_REQUIRED (0x00)
#define AUTHORIZATION_REQUIRED (0x01)
/**
 * @}
 */

/**
 * @anchor Conn_authorization
 * @name Connection authorization
 * @{
 */
#define CONNECTION_AUTHORIZED (0x01)
#define CONNECTION_REJECTED (0x02)
/**
 * @}
 */

/**
 * @anchor Use_fixed_pin
 * @name Use fixed pin
 * @{
 */
#define USE_FIXED_PIN_FOR_PAIRING (0x00)
#define DONOT_USE_FIXED_PIN_FOR_PAIRING (0x01)
/**
 * @}
 */

/**
 * @anchor link_security_status
 * @name Link security status
 * @{
 */
#define SM_LINK_AUTHENTICATED (0x01)
#define SM_LINK_AUTHORIZED (0x02)
#define SM_LINK_ENCRYPTED (0x04)
/**
 * @}
 */

/**
 * @anchor SMP_pairing_failed_codes
 * @name SMP pairing failed reason codes
 * @{
 */
#define PASSKEY_ENTRY_FAILED (0x01)
#define OOB_NOT_AVAILABLE (0x02)
#define AUTH_REQ_CANNOT_BE_MET (0x03)
#define CONFIRM_VALUE_FAILED (0x04)
#define PAIRING_NOT_SUPPORTED (0x05)
#define INSUFF_ENCRYPTION_KEY_SIZE (0x06)
#define CMD_NOT_SUPPORTED (0x07)
#define UNSPECIFIED_REASON (0x08)
#define VERY_EARLY_NEXT_ATTEMPT (0x09)
#define SM_INVALID_PARAMS (0x0A)
/**
 * @}
 */

/**
 * @anchor pairing_failed_codes
 * @name Pairing failed error codes
 * Error codes in @ref EVT_BLUE_GAP_PAIRING_CMPLT event
 * @{
 */
#define SM_PAIRING_SUCCESS (0x00)
#define SM_PAIRING_TIMEOUT (0x01)
#define SM_PAIRING_FAILED (0x02)
/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

#endif /* __SM_H__ */
