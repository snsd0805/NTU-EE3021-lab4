/**
 ******************************************************************************
 * @file    bluenrg_hal_aci.c
 * @author  AMS - HEA&RF BU
 * @brief   File with HCI commands for BlueNRG FW6.0 and above
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2013 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
#include "bluenrg_hal_aci.h"
#include "bluenrg_aci_const.h"
#include "bluenrg_def.h"
#include "bluenrg_gap.h"
#include "bluenrg_gatt_server.h"
#include "bluenrg_types.h"
#include "hci_const.h"

#define MIN(a, b) ((a) < (b)) ? (a) : (b)
#define MAX(a, b) ((a) > (b)) ? (a) : (b)

tBleStatus aci_hal_get_fw_build_number(uint16_t *build_number) {
    struct hci_request rq;
    hal_get_fw_build_number_rp rp;

    BLUENRG_memset(&rq, 0, sizeof(rq));
    rq.ogf = OGF_VENDOR_CMD;
    rq.ocf = OCF_HAL_GET_FW_BUILD_NUMBER;
    rq.rparam = &rp;
    rq.rlen = sizeof(rp);

    if (hci_send_req(&rq, FALSE) < 0)
	return BLE_STATUS_TIMEOUT;

    if (rp.status)
	return rp.status;

    *build_number = rp.build_number;

    return 0;
}

tBleStatus aci_hal_write_config_data(uint8_t offset,
				     uint8_t len,
				     const uint8_t *val) {
    struct hci_request rq;
    uint8_t status;
    uint8_t buffer[HCI_MAX_PAYLOAD_SIZE];
    uint8_t indx = 0;

    if ((len + 2) > HCI_MAX_PAYLOAD_SIZE)
	return BLE_STATUS_INVALID_PARAMS;

    buffer[indx] = offset;
    indx++;

    buffer[indx] = len;
    indx++;

    BLUENRG_memcpy(buffer + indx, val, len);
    indx += len;

    BLUENRG_memset(&rq, 0, sizeof(rq));
    rq.ogf = OGF_VENDOR_CMD;
    rq.ocf = OCF_HAL_WRITE_CONFIG_DATA;
    rq.cparam = (void *)buffer;
    rq.clen = indx;
    rq.rparam = &status;
    rq.rlen = 1;

    if (hci_send_req(&rq, FALSE) < 0)
	return BLE_STATUS_TIMEOUT;

    return status;
}

tBleStatus aci_hal_read_config_data(uint8_t offset, uint16_t data_len, uint8_t *data_len_out_p, uint8_t *data) {
    struct hci_request rq;
    hal_read_config_data_cp cp;
    hal_read_config_data_rp rp;

    cp.offset = offset;

    BLUENRG_memset(&rq, 0, sizeof(rq));
    rq.ogf = OGF_VENDOR_CMD;
    rq.ocf = OCF_HAL_READ_CONFIG_DATA;
    rq.cparam = &cp;
    rq.clen = sizeof(cp);
    rq.rparam = &rp;
    rq.rlen = sizeof(rp);

    if (hci_send_req(&rq, FALSE) < 0)
	return BLE_STATUS_TIMEOUT;

    if (rp.status)
	return rp.status;

    *data_len_out_p = rq.rlen - 1;

    BLUENRG_memcpy(data, rp.data, MIN(data_len, *data_len_out_p));

    return 0;
}

tBleStatus aci_hal_set_tx_power_level(uint8_t en_high_power, uint8_t pa_level) {
    struct hci_request rq;
    hal_set_tx_power_level_cp cp;
    uint8_t status;

    cp.en_high_power = en_high_power;
    cp.pa_level = pa_level;

    BLUENRG_memset(&rq, 0, sizeof(rq));
    rq.ogf = OGF_VENDOR_CMD;
    rq.ocf = OCF_HAL_SET_TX_POWER_LEVEL;
    rq.cparam = &cp;
    rq.clen = HAL_SET_TX_POWER_LEVEL_CP_SIZE;
    rq.rparam = &status;
    rq.rlen = 1;

    if (hci_send_req(&rq, FALSE) < 0)
	return BLE_STATUS_TIMEOUT;

    return status;
}

tBleStatus aci_hal_le_tx_test_packet_number(uint32_t *number_of_packets) {
    struct hci_request rq;
    hal_le_tx_test_packet_number_rp resp;

    BLUENRG_memset(&rq, 0, sizeof(rq));
    rq.ogf = OGF_VENDOR_CMD;
    rq.ocf = OCF_HAL_LE_TX_TEST_PACKET_NUMBER;
    rq.rparam = &resp;
    rq.rlen = sizeof(resp);

    if (hci_send_req(&rq, FALSE) < 0)
	return BLE_STATUS_TIMEOUT;

    if (resp.status) {
	return resp.status;
    }

    *number_of_packets = btohl(resp.number_of_packets);

    return 0;
}

tBleStatus aci_hal_device_standby(void) {
    struct hci_request rq;
    uint8_t status;

    BLUENRG_memset(&rq, 0, sizeof(rq));
    rq.ogf = OGF_VENDOR_CMD;
    rq.ocf = OCF_HAL_DEVICE_STANDBY;
    rq.rparam = &status;
    rq.rlen = 1;

    if (hci_send_req(&rq, FALSE) < 0)
	return BLE_STATUS_TIMEOUT;

    return status;
}

tBleStatus aci_hal_tone_start(uint8_t rf_channel) {
    struct hci_request rq;
    hal_tone_start_cp cp;
    uint8_t status;

    cp.rf_channel = rf_channel;

    BLUENRG_memset(&rq, 0, sizeof(rq));
    rq.ogf = OGF_VENDOR_CMD;
    rq.ocf = OCF_HAL_TONE_START;
    rq.cparam = &cp;
    rq.clen = HAL_TONE_START_CP_SIZE;
    rq.rparam = &status;
    rq.rlen = 1;

    if (hci_send_req(&rq, FALSE) < 0)
	return BLE_STATUS_TIMEOUT;

    return status;
}

tBleStatus aci_hal_tone_stop(void) {
    struct hci_request rq;
    uint8_t status;

    BLUENRG_memset(&rq, 0, sizeof(rq));
    rq.ogf = OGF_VENDOR_CMD;
    rq.ocf = OCF_HAL_TONE_STOP;
    rq.rparam = &status;
    rq.rlen = 1;

    if (hci_send_req(&rq, FALSE) < 0)
	return BLE_STATUS_TIMEOUT;

    return status;
}

tBleStatus aci_hal_get_link_status(uint8_t link_status[8], uint16_t conn_handle[8]) {
    struct hci_request rq;
    hal_get_link_status_rp rp;

    BLUENRG_memset(&rq, 0, sizeof(rq));
    rq.ogf = OGF_VENDOR_CMD;
    rq.ocf = OCF_HAL_GET_LINK_STATUS;
    rq.rparam = &rp;
    rq.rlen = sizeof(rp);

    if (hci_send_req(&rq, FALSE) < 0)
	return BLE_STATUS_TIMEOUT;

    if (rp.status)
	return rp.status;

    BLUENRG_memcpy(link_status, rp.link_status, 8);
    for (int i = 0; i < 8; i++)
	conn_handle[i] = btohs(rp.conn_handle[i]);

    return 0;
}

tBleStatus aci_hal_get_anchor_period(uint32_t *anchor_period, uint32_t *max_free_slot) {
    struct hci_request rq;
    hal_get_anchor_period_rp rp;

    BLUENRG_memset(&rq, 0, sizeof(rq));
    rq.ogf = OGF_VENDOR_CMD;
    rq.ocf = OCF_HAL_GET_ANCHOR_PERIOD;
    rq.rparam = &rp;
    rq.rlen = sizeof(rp);

    if (hci_send_req(&rq, FALSE) < 0)
	return BLE_STATUS_TIMEOUT;

    if (rp.status)
	return rp.status;

    *anchor_period = btohl(rp.anchor_period);
    *max_free_slot = btohl(rp.max_free_slot);

    return 0;
}
