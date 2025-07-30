# BLE Mesh MQTT Bridge — Overview

## Architettura

[OpenHAB UI] → MQTT → ESP32 → BLE Mesh → Lampadina Smart+
                             ↑
                         Status opcode → MQTT → OpenHAB

## Componenti

- ESP32: Generic OnOff Client
- Lampadina: Generic OnOff Server
- MQTT topics:
  - home/light
  - home/light/status

## Obiettivo

Controllo BLE Mesh tramite MQTT per automazione open-source e locale.
