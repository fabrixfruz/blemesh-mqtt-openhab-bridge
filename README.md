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

## 🧰 Setup rapido

```bash
git clone https://github.com/<tuo-username>/blemesh-mqtt-openhab-bridge
cd esp32_code
idf.py set-target esp32
idf.py build
idf.py flash
