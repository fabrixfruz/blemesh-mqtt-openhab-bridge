# BLE Mesh MQTT Bridge for OpenHAB 💡🔗

Controllo lampadine smart BLE Mesh via ESP32 + MQTT → OpenHAB.  
ESP32 agisce da client Bluetooth Mesh e riceve comandi dal broker MQTT, trasformandoli in pacchetti BLE Mesh (OnOff, Status, ecc.).

Smart lighting control over Bluetooth Mesh using ESP32 with MQTT bridge for OpenHAB automation.

![License: MIT](https://img.shields.io/badge/license-MIT-green)
![Platform: ESP32](https://img.shields.io/badge/platform-ESP32-blue)
![BLE Mesh](https://img.shields.io/badge/protocol-BLE%20Mesh-brightgreen)
![MQTT](https://img.shields.io/badge/integration-MQTT-orange)
![OpenHAB](https://img.shields.io/badge/automation-OpenHAB-yellow)

---

## 📦 Funzionalità / Features

- ✅ Controllo lampadina Sylvania Smart+ BLE Mesh
- 🔁 Invio comandi On/Off via MQTT (`home/light`)
- 🧠 Pubblicazione stato lampadina via MQTT (`home/light/status`)
- 🔧 Provisioning tramite app nRF Mesh
- 🌐 Bridge con Mosquitto e integrazione OpenHAB

---

## 🧰 Setup rapido / Quick Setup

```bash
git clone https://github.com/<tuo-username>/blemesh-mqtt-openhab-bridge
cd esp32_code
idf.py set-target esp32
idf.py build
idf.py flash
idf.py monitor


---

