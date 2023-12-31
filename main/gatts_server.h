#ifndef _GATTS_SERVER_H_
#define _GATTS_SERVER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shtc3.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_bt.h"
#include "esp_gap_ble_api.h"
#include "esp_gatts_api.h"
#include "esp_bt_main.h"
#include "esp_gatt_common_api.h"

/* Attributes State Machine */
enum
{
    IDX_SVC,
    IDX_CHAR_A,
    IDX_CHAR_VAL_A,
    IDX_CHAR_CFG_A,

    IDX_CHAR_B, //用于读取温湿度
    IDX_CHAR_VAL_B,

    IDX_CHAR_C, //用于接收LEDC命令
    IDX_CHAR_VAL_C,

    IDX_CHAR_D, //用于接收RGB命令
    IDX_CHAR_VAL_D,

    HRS_IDX_NB,
};



#define GATTS_TABLE_TAG "GATTS_TABLE_DEMO"

#define PROFILE_NUM                 1
#define PROFILE_APP_IDX             0
#define ESP_APP_ID                  0x55
#define SAMPLE_DEVICE_NAME          "ESP_GATTS_DEMO_sop"
#define SVC_INST_ID                 0 //服务ID


/* The max length of characteristic value. When the GATT client performs a write or prepare write operation,
*  the data length must be less than GATTS_DEMO_CHAR_VAL_LEN_MAX.
*/
#define GATTS_DEMO_CHAR_VAL_LEN_MAX 500
#define PREPARE_BUF_MAX_SIZE        1024
#define CHAR_DECLARATION_SIZE       (sizeof(uint8_t))
#define ADV_CONFIG_FLAG             (1 << 0)
#define SCAN_RSP_CONFIG_FLAG        (1 << 1)

void Bluetooth_init();
uint8_t get_brightness();
uint8_t* get_rgb_num();



#endif



