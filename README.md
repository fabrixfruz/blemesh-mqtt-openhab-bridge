# blemesh-mqtt-openhab-bridge
ESP32 client BLE Mesh + MQTT bridge per Smart Lighting

# BLE Mesh MQTT Bridge for OpenHAB 💡🔗

Controllo lampadine smart BLE Mesh via ESP32 + bridge MQTT per automazione OpenHAB.  
ESP32 agisce come client BLE Mesh → riceve comandi da broker MQTT e li trasforma in pacchetti Mesh (OnOff, Status...).

Smart lighting control over Bluetooth Mesh using ESP32 with MQTT bridge for OpenHAB automation.

---

## 📦 Features / Funzionalità

- ✅ Controllo lampadina Sylvania Smart+ BLE Mesh
- 🔁 Invio comandi On/Off via MQTT topic
- 🧠 Pubblicazione dello stato della lampadina (Status opcode)
- 📡 Bridge con Mosquitto + OpenHAB (config inclusa)
- 📲 ESP32 con stack BLE Mesh ufficiale + esp-mqtt
- 🌐 Progetto completamente open-source, documentato in italiano e inglese

---

## 📡 MQTT Topics

| Topic                | Payload            | Azione / Action               |
|---------------------|--------------------|-------------------------------|
| `home/light`        | `"ON"` / `"OFF"`   | Accende/spegne la lampadina   |
| `home/light`        | `"STATUS"`         | Richiede stato BLE            |
| `home/light/status` | `"ON"` / `"OFF"`   | Stato ritornato via ESP32     |

---

## 🏠 Integrazione OpenHAB

📁 `openhab_config/`:
- `lampadina.items` → Definisce lo switch virtuale
- `mqtt.rules` → Regole di automazione MQTT ↔ BLE
- `things.json` → Configurazione MQTT broker

---

## 📘 Documentazione / Docs

📂 `docs/`:
- `overview.md` → Architettura e flusso dati
- `provisioning-guide.md` → Come provisionare la lampadina con nRF Mesh
- `mqtt-bridge.md` → Dettagli bridge ESP32 ↔ MQTT

---

## 🎬 Demo / Screenshot

*(Puoi aggiungere una GIF o screenshot qui)*  
![BLE Mesh provisioning](extras/nrf_mesh_map.png)  
📺 [Video demo](https://youtu.be/link-demo)

---

## 🧪 Roadmap

- Web UI embedded su ESP32
- Dashboard Node-RED
- Supporto multi-hop BLE Mesh
- OTA firmware & telemetria MQTT

---

## 📜 License

MIT — Open hardware + software. Fork, migliora, condividi!

---

Made with 🔧 curiosity by [@Fabrizio](https://github.com/<tuo-username>)  
🇮🇹 Progetto open per maker e hacker

## 🧰 Setup rapido

```bash
git clone https://github.com/<tuo-username>/blemesh-mqtt-openhab-bridge
cd esp32_code
idf.py set-target esp32
idf.py build
idf.py flash
