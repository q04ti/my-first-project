# Starbie preliminary pinout

> **PRELIMINARY — research-supported mapping, not final electrical validation.**
>
> Seeed's published XIAO ESP32C3 pin map confirms D4/GPIO6 as SDA, D5/GPIO7 as SCL, and the D1-D3 GPIO labels used below. Power, pull-ups, module pin order, and footprints still require verification.

| Component | Signal | XIAO pin | ESP32 GPIO | Interface | Status |
|---|---|---:|---:|---|---|
| OLED | SDA | D4 | GPIO6 | I2C | VERIFIED mapping / module TBD |
| MPU6050 | SDA | D4 | GPIO6 | I2C | VERIFIED mapping / module TBD |
| OLED | SCL | D5 | GPIO7 | I2C | VERIFIED mapping / module TBD |
| MPU6050 | SCL | D5 | GPIO7 | I2C | VERIFIED mapping / module TBD |
| DHT11 | DATA | D1 | GPIO3 | Single-wire digital | Proposed / sensor module TBD |
| Button 1 | Input, active-low proposed | D2 | GPIO4 | Digital input | Proposed |
| Button 2 | Input, active-low proposed | D3 | GPIO5 | Digital input | Proposed |
| OLED / MPU6050 / DHT11 | 3V3 | 3V3 | — | Power | Proposed; module limits TBD |
| All modules | GND | GND | — | Ground | Proposed |

GPIO2, GPIO8, and GPIO9 are documented ESP32-C3 strapping pins and are intentionally not used for Starbie peripherals.

**Source:** [Seeed XIAO ESP32C3 Getting Started](https://wiki.seeedstudio.com/XIAO_ESP32C3_Getting_Started/)

