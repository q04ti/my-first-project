# Preliminary pinout

> **PRELIMINARY — NOT A FINAL ELECTRICAL DESIGN**
>
> These assignments follow the starter-guide plan and are centralized in the firmware configuration. They must be checked against the exact XIAO ESP32-C3 board documentation and the selected module pinouts before schematic finalization.

| Component | Signal | XIAO pin | ESP32 GPIO | Interface | Status |
|---|---|---:|---:|---|---|
| OLED | SDA | D4 | GPIO6 | I2C | Preliminary |
| MPU6050 | SDA | D4 | GPIO6 | I2C | Preliminary |
| OLED | SCL | D5 | GPIO7 | I2C | Preliminary |
| MPU6050 | SCL | D5 | GPIO7 | I2C | Preliminary |
| DHT11 | DATA | D1 | GPIO3 | Single-wire digital | Preliminary |
| Button 1 | Input | D2 | GPIO4 | Digital input | Preliminary |
| Button 2 | Input | D3 | GPIO5 | Digital input | Preliminary |

Power, ground, pull-ups, interrupt lines, and any optional signals are TBD until the exact modules are selected.

