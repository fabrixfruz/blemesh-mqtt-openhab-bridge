#include "ble_mesh_opcodes.h"
#include "ble_mesh_models.h"
#include "esp_ble_mesh_utils.h"
#include "esp_ble_mesh_generic_model_api.h"
#include "esp_ble_mesh_health_client_api.h"

// ---------- Generic OnOff Client Ops & Callback ----------

static const esp_ble_mesh_model_op_t gen_onoff_cli_op[] = {
    ESP_BLE_MESH_MODEL_OP(OP_GENERIC_ONOFF_STATUS, 2),
    ESP_BLE_MESH_MODEL_OP_END,
};

static void gen_onoff_status_cb(esp_ble_mesh_model_t *model,
                                esp_ble_mesh_msg_ctx_t *ctx,
                                uint32_t length, uint8_t *value)
{
    bool onoff = value[0];
    printf("[OnOff Status] addr=0x%04x, onoff=%d\n", ctx->addr, onoff);
}

// ---------- Generic Level Client Ops & Callback ----------

static const esp_ble_mesh_model_op_t gen_level_cli_op[] = {
    ESP_BLE_MESH_MODEL_OP(OP_GENERIC_LEVEL_STATUS, 3),
    ESP_BLE_MESH_MODEL_OP_END,
};

static void gen_level_status_cb(esp_ble_mesh_model_t *model,
                                esp_ble_mesh_msg_ctx_t *ctx,
                                uint32_t length, uint8_t *value)
{
    int16_t level = (value[1] << 8) | value[0];
    printf("[Level Status] addr=0x%04x, level=%d\n", ctx->addr, level);
}

// ... analoghi op/mapping/status per gli altri client models ...

// Array di tutti i modelli client da registrare nell’elemento
esp_ble_mesh_model_t client_models[] = {
    ESP_BLE_MESH_MODEL_GEN_ONOFF_CLI(&gen_onoff_cli_op, NULL, gen_onoff_status_cb),
    ESP_BLE_MESH_MODEL_GEN_LEVEL_CLI(&gen_level_cli_op, NULL, gen_level_status_cb),
    ESP_BLE_MESH_MODEL_GEN_DEF_TRANS_TIME_CLI(NULL, NULL, NULL),
    ESP_BLE_MESH_MODEL_GEN_POWER_ONOFF_CLI(NULL, NULL, NULL),
    ESP_BLE_MESH_MODEL_GEN_POWER_ONOFF_SETUP_CLI(NULL, NULL, NULL),
    ESP_BLE_MESH_MODEL_LIGHT_LIGHTNESS_CLI(NULL, NULL, NULL),
};

