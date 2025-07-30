# ESP32 BLE Mesh Client — Minimal Project

Accende e spegne una lampadina BLE Mesh (es. Sylvania Smart+).  
Compatibile con ESP-IDF, provisioning via nRF Mesh, test via log seriale.

## Setup rapido

```bash
git clone https://github.com/<tuo-username>/esp32_ble_mesh_client
cd esp32_ble_mesh_client
idf.py set-target esp32
idf.py build
idf.py flash
idf.py monitor
```

# Primo test
Provisiona la lampadina con nRF Mesh (vedi docs/provisioning-guide.md)

Imposta SYLVANIA_ADDR in mesh_config.h

Ricompila e flasha

Osserva la lampadina accendersi e spegnersi automaticamente
---

