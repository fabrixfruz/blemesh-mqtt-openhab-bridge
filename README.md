## 🧩 Obiettivo: Simulare un client Mesh con ESP32 per controllo automatico della lampadina

## 🎯 Fasi del workflow
1. Setup ESP32 come nodo client

    Provisioning (separato o statico)

    Integrazione con modelli Generic OnOff Client

2 Binding con Application Key

    Binding del modello OnOff Client con la stessa AppKey usata nel Server (lampadina)

3. Configurazione addressing

    Pubblica verso l’Unicast address della lampadina

    (Opzione: usa un Group address se vuoi scalare)

4. Invio comando OnOffSet

   Sia manuale da codice, sia ciclico/timed

   Visual feedback tramite log seriale o LED ESP32

## 💻 Codice ESP32 base per invio comando
   Ecco uno snippet semplificato:

```
   esp_ble_mesh_generic_client_set_state_t set;
set.onoff_set.op_en = false;
set.onoff_set.onoff = 0x01;  // 0x01 = ON, 0x00 = OFF
set.onoff_set.tid = 0x00;

esp_ble_mesh_model_t *client_model = get_generic_onoff_client_model();  // tuo puntatore al modello
esp_ble_mesh_msg_ctx_t ctx = {
  .net_idx = net_idx,
  .app_idx = app_idx,
  .addr = unicast_addr_lampadina,
  .send_ttl = TTL,
  .send_rel = false
};

esp_ble_mesh_generic_client_set_state(client_model, &ctx, &set);
```
## 📌 Puoi sostituire onoff = 0x00 per spegnere e schedulare via timer o evento GPIO.

## 🛠️ Debug e Log
   Log via seriale per conferma di invio

   LED ESP per mostrare stato di comando (ON/OFF)

   Sniffing con nRF Connect per verificare pacchetti
