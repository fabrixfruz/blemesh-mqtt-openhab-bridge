#include "esp_ble_mesh_generic_model_api.h"
#include "mesh_config.h"

extern uint8_t tid;
extern esp_ble_mesh_model_t *client_model;

void send_on() {
  esp_ble_mesh_generic_client_set_state_t set = {0};
  set.onoff_set.onoff = 1;
  set.onoff_set.tid = tid++;

  esp_ble_mesh_msg_ctx_t ctx = {
    .net_idx = NET_IDX,
    .app_idx = APP_IDX,
    .addr = SYLVANIA_ADDR,
    .send_ttl = 3,
  };

  esp_ble_mesh_generic_client_set_state(client_model, &ctx, &set);
}

void send_off() {
  esp_ble_mesh_generic_client_set_state_t set = {0};
  set.onoff_set.onoff = 0;
  set.onoff_set.tid = tid++;

  esp_ble_mesh_msg_ctx_t ctx = {
    .net_idx = NET_IDX,
    .app_idx = APP_IDX,
    .addr = SYLVANIA_ADDR,
    .send_ttl = 3,
  };

  esp_ble_mesh_generic_client_set_state(client_model, &ctx, &set);
}
