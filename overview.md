# BLE Mesh MQTT Bridge — Overview 💡📡

## 🧠 Architettura del sistema

Il progetto collega tre mondi:

- ESP32 con stack BLE Mesh → controlla dispositivi come lampadine Sylvania
- Broker MQTT (es. Mosquitto) → riceve comandi e invia messaggi allo ESP32
- OpenHAB → interfaccia utente e automazione che usa MQTT come backend

```plaintext
[OpenHAB UI] → MQTT → ESP32 → BLE Mesh → Lampadina Smart+
                             ↑
                         Status opcode → MQTT → OpenHAB

## 📦 Componenti principali
ESP32 con modello Generic OnOff Client

Lampadina provisionata con Generic OnOff Server

Topics MQTT:

home/light: comandi

home/light/status: risposta BLE

OpenHAB items/rules → interfaccia utente

## 🎯 Obiettivo
Automazione luci BLE Mesh con comandi MQTT standard, senza dipendenza da app proprietarie.
