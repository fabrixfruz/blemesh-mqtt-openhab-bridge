#include <stdio.h>
#include "mesh_config.h"
#include "model_handlers.c"

uint8_t tid = 0;
esp_ble_mesh_model_t *client_model;

void app_main(void)
{
  printf("📡 ESP32 Mesh Client avviato\n");

  // TODO: Inizializzazione stack BLE Mesh e provisioning...

  // Test accensione lampadina
  vTaskDelay(5000 / portTICK_PERIOD_MS);
  send_on();

  // Test spegnimento dopo 10 sec
  vTaskDelay(10000 / portTICK_PERIOD_MS);
  send_off();
}
