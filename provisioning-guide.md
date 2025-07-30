
---

## 🧭 `provisioning-guide.md` — Provisioning con nRF Mesh


# Guida al Provisioning BLE Mesh con nRF Mesh 📲


## 🔧 Requisiti

- App [nRF Mesh](https://play.google.com/store/apps/details?id=no.nordicsemi.android.nrfmeshprovisioner)
- Lampadina Sylvania Smart+ non provisionata (Sylvania Smart+ 60A19CBLE Bluetooth)
- ESP32 (opzionale, per provisioning automatico)

## 📝 Passaggi

1. Avvia l’app nRF Mesh
2. Premi `+` per aggiungere un nuovo nodo
3. Seleziona la lampadina `sigmesh` dalla lista
4. Assegna un nome al nodo (es. `SylA19-001`)
5. Completa provisioning con `Static OOB = 0` (automatico)

## ⚙️ Configura il modello

- Vai sul nodo → Element → Model
- Individua `Generic OnOff Server`
- Esegui il **binding** con una Application Key
- Imposta indirizzo publish/subscription

## ✅ Test

Dopo provisioning e binding:
- Vai nel modello → `Set OnOff`
- Premi `ON` / `OFF`
- La lampadina dovrebbe reagire
