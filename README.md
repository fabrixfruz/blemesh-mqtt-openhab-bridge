## 🔶 BLE Mesh Models – Generic & Lighting / Modelli BLE Mesh – Generic & Lighting

### 🧩 Generic Models / Modelli Generic

| Model Name / Nome Modello               | Function / Funzione                                     | SIG Model ID | Typical Value Range / Range Valori Tipici         |
|-----------------------------------------|---------------------------------------------------------|:------------:|----------------------------------------------------|
| Configuration Server                    | Sets up Mesh network configuration                      | 0x0000       | —                                                  |
| Health Server                           | Reports node health status                              | 0x0002       | Fault bitmap                                       |
| Health Client                           | Queries Health Server nodes                             | 0x0003       | —                                                  |
| Generic OnOff Server                    | Maintains On/Off device state                           | 0x1000       | 0 (OFF), 1 (ON)                                    |
| Generic OnOff Client                    | Sends On/Off commands                                   | 0x1001       | 0 (OFF), 1 (ON)                                    |
| Generic Level Server                    | Represents general “level” (e.g., brightness)           | 0x1002       | -32768 to +32767 (int16_t)                         |
| Generic Level Client                    | Sends Level Set/Get commands                           | 0x1003       | -32768 to +32767 (int16_t)                         |
| Generic Default Transition Time Server  | Controls default transition duration                    | 0x1004       | 0x00–0x7F                                          |
| Generic Power OnOff Server              | Controls behavior after power-up                        | 0x1006       | 0x00 (OFF), 0x01 (ON), 0x02 (RESTORE)              |
| Generic Power OnOff Setup Server        | Configures Power OnOff settings                         | 0x1007       | Same as above / Come sopra                         |

### 💡 Lighting Models / Modelli Lighting

| Model Name / Nome Modello               | Function / Funzione                                     | SIG Model ID | Typical Value Range / Range Valori Tipici         |
|-----------------------------------------|---------------------------------------------------------|:------------:|----------------------------------------------------|
| Light Lightness Server                  | Controls light brightness                              | 0x1300       | 0–65535 (uint16_t)                                 |
| Light Lightness Client                  | Sends brightness commands                              | 0x1302       | 0–65535                                            |
| Light Lightness Setup Server            | Configures default & range values                      | 0x1301       | default/range → uint16_t                           |
| Light CTL Server                        | Controls lightness + color temperature                 | 0x1303       | Light: 0–65535 / Temp: 800–20000K                  |
| Light CTL Temperature Server            | Exposes only color temperature                         | 0x1306       | Kelvin range (as configured)                      |
| Light CTL Setup Server                  | Sets CTL range & default values                        | 0x1304       | Kelvin range / default                             |
| Light HSL Server                        | Controls Hue, Saturation, Lightness                    | 0x1307       | Hue/Sat/Light: 0–65535                             |
| Light HSL Hue Server                    | Controls Hue (color tint)                              | 0x130A       | 0–65535                                            |
| Light HSL Saturation Server             | Controls color saturation                              | 0x130B       | 0 (gray) – 65535 (pure color)                      |
| Light HSL Lightness Server              | Controls lightness within HSL                          | 0x130C       | 0–65535                                            |
| Light HSL Setup Server                  | Configures range/default for HSL                       | 0x1308       | default / range → uint16_t                         |


---

## 🧮 Generic OnOff
### 🔘 Generic OnOff Model (SIG Model ID: 0x1000 / 0x1001)

| Opcode     | Funzione           | Payload                          | Risposta prevista      |
|------------|--------------------|----------------------------------|-------------------------|
| `0x82 0x01` | OnOff Get          | —                                | OnOff Status            |
| `0x82 0x02` | OnOff Set          | `1 byte` (0x00=OFF / 0x01=ON) + optional `TID` | OnOff Status (acknowledged) |
| `0x82 0x03` | OnOff Set Unack.   | come sopra                       | Nessuna risposta        |
| `0x82 0x04` | OnOff Status       | `1 byte` (stato attuale)         | —                       |

## 🌗 Generic Level Model (SIG Model ID: 0x1002 / 0x1003)

| Opcode     | Funzione           | Payload                                    | Risposta prevista      |
|------------|--------------------|--------------------------------------------|-------------------------|
| `0x82 0x05` | Level Get          | —                                          | Level Status            |
| `0x82 0x06` | Level Set          | `2 byte` (int16_t livello) + `TID`        | Level Status            |
| `0x82 0x07` | Level Set Unack.   | come sopra                                 | Nessuna risposta        |
| `0x82 0x08` | Level Status       | `2 byte` livello attuale                   | —                       |


## 💡 Light Lightness Server (SIG Model ID: 0x1300 / 0x1302)

| Opcode     | Funzione           | Payload                                    | Risposta prevista      |
|------------|--------------------|--------------------------------------------|-------------------------|
| `0x82 0x4B` | Lightness Get      | —                                          | Lightness Status        |
| `0x82 0x4C` | Lightness Set      | `2 byte` lightness + `TID`                | Lightness Status        |
| `0x82 0x4D` | Lightness Set Unack. | come sopra                               | Nessuna risposta        |
| `0x82 0x4E` | Lightness Status   | `2 byte` valore attuale + opzionale target/delay | —                |

## 💡 Light CTL Model (SIG Model ID: 0x1303 / Client: 0x1305)

### 💡 Light CTL Model

| Opcode     | Funzione                  | Payload                                                                      | Risposta prevista        |
|------------|---------------------------|-------------------------------------------------------------------------------|---------------------------|
| `0x82 0x5D` | CTL Get                   | —                                                                             | CTL Status                |
| `0x82 0x5E` | CTL Set                   | `2B Lightness` + `2B Temperature (Kelvin)` + `2B Delta UV` + `TID`           | CTL Status                |
| `0x82 0x5F` | CTL Set Unack.            | come sopra                                                                   | Nessuna risposta          |
| `0x82 0x60` | CTL Status                | Lightness + Temperature + Delta UV + opzionale Target e Transizione         | —                         |
| `0x82 0x61` | CTL Temperature Get       | —                                                                             | CTL Temperature Status    |
| `0x82 0x62` | CTL Temperature Range Get | —                                                                             | CTL Temperature Range Status |
| `0x82 0x63` | CTL Default Get           | —                                                                             | CTL Default Status        |
| `0x82 0x64` | CTL Temperature Status    | Temperatura attuale + Target + Transizione                                   | —                         |
| `0x82 0x65` | CTL Default Status        | Valori di default per Lightness, Temp, DeltaUV                               | —                         |
| `0x82 0x66` | CTL Temperature Range Status | Min e Max valori consentiti Kelvin                                          | —                         |
| `0x82 0x67` | CTL Default Set           | Imposta valori di default                                                    | Nessuna o Default Status  |
| `0x82 0x68` | CTL Temperature Range Set | Imposta Range Kelvin                                                         | Nessuna o Range Status    |

🎨 Light HSL Model (SIG Model ID: 0x1307 / Client: 0x1309)

### 🎨 Light HSL Model

| Opcode     | Funzione                  | Payload                                                           | Risposta prevista        |
|------------|---------------------------|--------------------------------------------------------------------|---------------------------|
| `0x82 0x69` | HSL Get                   | —                                                                  | HSL Status                |
| `0x82 0x6A` | HSL Set                   | `2B Hue` + `2B Saturation` + `2B Lightness` + `TID`                | HSL Status                |
| `0x82 0x6B` | HSL Set Unack.            | come sopra                                                        | Nessuna risposta          |
| `0x82 0x6C` | HSL Status                | Valori attuali + Target + Transizione                             | —                         |
| `0x82 0x6D` | HSL Target Get            | —                                                                  | HSL Target Status         |
| `0x82 0x6E` | HSL Target Status         | Valori obiettivo                                                   | —                         |
| `0x82 0x6F` | HSL Default Get           | —                                                                  | HSL Default Status        |
| `0x82 0x70` | HSL Default Status        | Hue, Sat, Lightness predefiniti                                   | —                         |
| `0x82 0x71` | HSL Range Get             | —                                                                  | HSL Range Status          |
| `0x82 0x72` | HSL Range Status          | HueMin/HueMax + SatMin/SatMax                                     | —                         |
| `0x82 0x73` | HSL Default Set           | Hue + Sat + Lightness di default                                  | Nessuna o Default Status  |
| `0x82 0x74` | HSL Range Set             | Imposta limiti per Hue e Saturation                               | Nessuna o Range Status    |






Made with 🔧 curiosity by [@FabrixFruz](https://github.com/fabrixfruz)  
🇮🇹 Progetto open per maker e hacker


