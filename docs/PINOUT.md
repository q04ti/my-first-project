# Starbie v1 preliminary pinout

The XIAO GPIO mapping is supported by Seeed's published pin map. Module connector pin order is based on selected product documentation but must still be checked against received hardware before layout.

| Component | Signal | XIAO pin | ESP32 GPIO | Interface | Status |
|---|---|---:|---:|---|---|
| Adafruit 326 OLED | Data/SDA | D4 | GPIO6 | I2C | Selected product |
| Adafruit 3886 MPU6050 | SDA | D4 | GPIO6 | I2C | Selected product |
| Adafruit 326 OLED | Clk/SCL | D5 | GPIO7 | I2C | Selected product |
| Adafruit 3886 MPU6050 | SCL | D5 | GPIO7 | I2C | Selected product |
| DFRobot DFR0067 | SIG | D1 | GPIO3 | Single-wire digital | Selected product |
| Omron B3F-4050 SW1 | Active-low input | D2 | GPIO4 | Digital input | Proposed internal pull-up |
| Omron B3F-4050 SW2 | Active-low input | D3 | GPIO5 | Digital input | Proposed internal pull-up |
| Selected modules | 3V3/Vin as documented | 3V3 | — | Power | Verify current budget |
| Selected modules | GND | GND | — | Ground | Required |
| Adafruit 3886 | INT | Not assigned | — | Optional interrupt | Expose only as optional connector signal |
| Adafruit 3886 | AD0 | Module default | — | Address select | Verify default is low / 0x68 |

## OLED connector change

The selected Adafruit 326 is an 8-pin breakout, not a 4-pin-only module. The carrier should provide a documented 1x8 header area. Only GND, Vin, Data, and Clk are used for Starbie's I2C design; the remaining pins are not assigned to XIAO GPIOs.

GPIO2, GPIO8, and GPIO9 remain unused because Seeed identifies them as ESP32-C3 strapping pins.
