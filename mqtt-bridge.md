# Bridge ESP32 BLE Mesh ↔ MQTT 🔌

## 📡 Funzionamento

ESP32 riceve comandi MQTT e li trasforma in pacchetti BLE Mesh compatibili.

| Topic MQTT       | Payload    | Azione BLE Mesh                |
|------------------|------------|--------------------------------|
| `home/light`     | `"ON"`     | Invia opcode `0x8202` (accendi)|
| `home/light`     | `"OFF"`    | Invia opcode `0x8202` (spegni) |
| `home/light`     | `"STATUS"` | Invia opcode `0x8201` (richiesta stato) |
| `home/light/status` | `"ON"` / `"OFF"` | Stato pubblicato dal nodo |

## 🔐 Struttura codice ESP32


void mqtt_event_handler(...) {
  if (topic == "home/light") {
    if (payload == "ON") send_on();
    else if (payload == "OFF") send_off();
    else if (payload == "STATUS") request_status();
  }
}


## 🏠 Integrazione con OpenHAB
Crea uno Switch item MQTT

Scrivi una regola per inviare comandi MQTT su evento

Visualizza lo stato tramite topic home/light/status

## 🚀 Estensioni
Auto-discovery MQTT (Home Assistant)

Logging storico delle accensioni

Integrazione con Node-RED
