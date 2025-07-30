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

Made with 🔧 curiosity by [@FabrixFruz](https://github.com/fabrixfruz)  
🇮🇹 Progetto open per maker e hacker


