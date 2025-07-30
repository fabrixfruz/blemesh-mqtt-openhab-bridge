#ifndef MESH_CONFIG_H
#define MESH_CONFIG_H

// ⚙️ Indirizzo unicast della lampadina (modifica con il tuo!)
#define SYLVANIA_ADDR 0x0002

// 🔐 AppKey e NetKey Index
#define APP_IDX 0x0000
#define NET_IDX 0x0000

#pragma once

// 📡 Opcode Bluetooth Mesh
#define OPCODE_ONOFF_GET       0x8201
#define OPCODE_ONOFF_SET       0x8202
#define OPCODE_ONOFF_SET_UNACK 0x8203
#define OPCODE_ONOFF_STATUS    0x8204

/* HSL */
#define OP_LIGHT_HSL_HUE_SET               0x8272
#define OP_LIGHT_HSL_SATURATION_SET        0x8276
#define OP_LIGHT_HSL_LIGHTNESS_SET         0x827A

/* CTL */
#define OP_LIGHT_CTL_TEMPERATURE_SET       0x825D
#define OP_LIGHT_CTL_LIGHTNESS_SET         0x825C

#endif
