/**
 ******************************************************************************
 * @file    link_layer.h
 * @author  AMS - HEA&RF BU
 * @brief   Header file for BlueNRG's link layer.
 *          It contains definition of functions for link layer, most of which
 *          are mapped to HCI commands
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
#ifndef _LINK_LAYER_H
#define _LINK_LAYER_H

#include "bluenrg_def.h"

/**
 * @addtogroup HIGH_LEVEL_INTERFACE HIGH_LEVEL_INTERFACE
 * @{
 */

/**
 * @addtogroup ACI_GAP ACI_GAP
 * @brief API for GAP layer.
 * @{
 */

/**
 *@name Advertising filter
 *Advertising policy for filtering (white list related)
 *@{
 */
#define NO_WHITE_LIST_USE (0x00)	/**< Process scan and connection requests from all devices (i.e., the White List is not in use) */
#define WHITE_LIST_FOR_ONLY_SCAN (0x01) /**< Process connection requests from all devices and only scan requests from devices that are in the White List */
#define WHITE_LIST_FOR_ONLY_CONN (0x02) /**< Process scan requests from all devices and only connection requests from devices that are in the White List */
#define WHITE_LIST_FOR_ALL (0x03)	/**< Process scan and connection requests only from devices in the White List. */
/**
 * @}
 */

/**
 * Bluetooth 48 bit address (in little-endian order).
 */
typedef uint8_t tBDAddr[6];

/**
 *@name Bluetooth address types
 * Bluetooth address types
 *@{
 */
#define PUBLIC_ADDR (0)
#define RANDOM_ADDR (1)
#define STATIC_RANDOM_ADDR (1)
#define RESOLVABLE_PRIVATE_ADDR (2)
#define NON_RESOLVABLE_PRIVATE_ADDR (3)
/**
 * @}
 */

/**
 *@name Directed advertising types
 * Type of advertising during directed advertising
 *@{
 */
#define HIGH_DUTY_CYCLE_DIRECTED_ADV (1)
#define LOW_DUTY_CYCLE_DIRECTED_ADV (4)
/**
 * @}
 */

/**
 * @name Advertising type
 * @{
 */

/**
 * undirected scannable and connectable
 */
#define ADV_IND (0x00)

/**
 * directed non scannable
 */
#define ADV_DIRECT_IND (0x01)

/**
 * scannable non connectable
 */
#define ADV_SCAN_IND (0x02)

/**
 * non-connectable and no scan response
 */
#define ADV_NONCONN_IND (0x03)

/**
 * scan response
 */
#define SCAN_RSP (0x04)

/**
 * @}
 */

/* 0X05-0XFF RESERVED */

/**
 * @name Advertising ranges
 * @{
 */

/**
 * lowest allowed interval value for connectable types(20ms)..multiple of 625us
 */
#define ADV_INTERVAL_LOWEST_CONN (0X0020)

/**
 * highest allowed interval value (10.24s)..multiple of 625us.
 */
#define ADV_INTERVAL_HIGHEST (0X4000)

/**
 * lowest allowed interval value for non connectable types
 * (100ms)..multiple of 625us.
 */
#define ADV_INTERVAL_LOWEST_NONCONN (0X00a0)

/**
 * @}
 */

/**
 * @name Advertising channels
 * @{
 */
#define ADV_CH_37 0x01
#define ADV_CH_38 0x02
#define ADV_CH_39 0x04
/**
 * @}
 */

/**
 * @name Scan_types Scan types
 * @{
 */
#define PASSIVE_SCAN 0
#define ACTIVE_SCAN 1
/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

#endif /* _LINK_LAYER_H */
