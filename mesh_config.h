#ifndef MESH_CONFIG_H
#define MESH_CONFIG_H

// ⚙️ Indirizzo unicast della lampadina (modifica con il tuo!)
#define SYLVANIA_ADDR 0x0003

// 🔐 AppKey e NetKey Index
#define APP_IDX 0x0000
#define NET_IDX 0x0000

// 📡 Opcode Bluetooth Mesh
#define OPCODE_ONOFF_GET       0x8201
#define OPCODE_ONOFF_SET       0x8202
#define OPCODE_ONOFF_SET_UNACK 0x8203
#define OPCODE_ONOFF_STATUS    0x8204

#endif
