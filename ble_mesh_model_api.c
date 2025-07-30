#include "ble_mesh_opcodes.h"
#include "ble_mesh_models.h"
#include "esp_ble_mesh_generic_model_api.h"

// Esempio di funzione per inviare Generic OnOff Set
esp_err_t ble_mesh_generic_onoff_set(uint16_t dst_addr, bool onoff, uint8_t tid)
{
    esp_ble_mesh_client_common_param_t common = {
        .opcode = OP_GENERIC_ONOFF_SET,
        .model  = &client_models[0],        // assume OnOff CLI è in posizione 0
        .ctx.net_idx = 0,
        .ctx.app_idx = 0,
        .ctx.addr    = dst_addr,
        .ctx.send_ttl= 3,
        .msg_timeout = 0,
    };
    esp_ble_mesh_generic_client_set_state_t set = {
        .onoff_set.onoff = onoff,
        .onoff_set.tid   = tid,
    };
    return esp_ble_mesh_generic_client_set_state(&common, &set);
}

// Esempio di funzione per inviare Generic Level Set
esp_err_t ble_mesh_generic_level_set(uint16_t dst_addr, int16_t level, uint8_t tid)
{
    esp_ble_mesh_client_common_param_t common = {
        .opcode = OP_GENERIC_LEVEL_SET,
        .model  = &client_models[1],        // assume Level CLI è in posizione 1
        .ctx.net_idx = 0,
        .ctx.app_idx = 0,
        .ctx.addr    = dst_addr,
        .ctx.send_ttl= 3,
    };
    esp_ble_mesh_generic_client_set_state_t set = {
        .level_set.level = level,
        .level_set.tid   = tid,
    };
    return esp_ble_mesh_generic_client_set_state(&common, &set);
}

// ... e così via per gli altri modelli ...
