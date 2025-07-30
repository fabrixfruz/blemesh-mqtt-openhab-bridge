#include "ble_mesh_model_api.h"

void app_main(void)
{
    uint8_t tid = 0;

    // Dopo init BLE Mesh e provisioning...
    // Accendo un nodo con address 0x0003
    ble_mesh_generic_onoff_set(0x0003, true, ++tid);

    vTaskDelay(2000 / portTICK_PERIOD_MS);

    // Spengo lo stesso nodo
    ble_mesh_generic_onoff_set(0x0003, false, ++tid);
}
