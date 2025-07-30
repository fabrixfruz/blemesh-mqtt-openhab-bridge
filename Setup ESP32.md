## 🔧 1. Installa tool ESP-IDF
ESP32 supporta Bluetooth Mesh stack ufficiale via ESP-IDF.

Scarica l’ultima versione da esp-idf

Installa Python, CMake, Git se non presenti

Clona l’esempio Mesh da:
```
git clone https://github.com/espressif/esp-idf
cd esp-idf/examples/bluetooth/esp_ble_mesh
```
Consiglio: usa light_client come base.
---
##📦 2. Configura modello Generic OnOff Client
Nel file main.c, modifica il payload come segue:
```
esp_ble_mesh_generic_client_set_state_t set = {0};
set.onoff_set.op_en = false;
set.onoff_set.onoff = 0x01; // Accensione
set.onoff_set.tid = tid++;  // Incrementale

esp_ble_mesh_msg_ctx_t ctx = {
  .net_idx = net_idx,
  .app_idx = app_idx,
  .addr    = unicast_addr_lampadina,
  .send_ttl = 3,
  .send_rel = false
};

esp_ble_mesh_generic_client_set_state(client_model, &ctx, &set);
```
✅ Personalizza unicast_addr_lampadina con l’indirizzo visto in nRF Mesh.
---
##🔐 3. Chiavi e binding
Importa nel codice:

NetKey e AppKey che hai generato nella rete (visibili in nRF Mesh)

Usa esp_ble_mesh_node_provision() per inserire ESP32 come client provisionato

Oppure:

Provisiona ESP32 via app nRF Mesh come nodo nuovo

Binda il client al modello Generic OnOff Server della lampadina

---

## 🔁 Comandi automatici
Puoi schedulare in app_main():

Timer per toggle ciclico ogni X secondi

GPIO come interruttore (es. pulsante fisico)

Serial input da PC → cambia stato della lampadina da terminale
---
##🎓Integrare con MQTT & openHAB
Una volta funzionante:

Aggiungi connessione Wi-Fi

Usa esp-mqtt per ricevere messaggi da openHAB

Converti MQTT → comando Mesh

→ La tua lampadina sarà Mesh + MQTT hybrid 🧠



