# Starbie v1 preliminary pinout

The XIAO GPIO mapping is supported by Seeed's published pin map. The OLED uses the current Product 326 STEMMA-QT labels, the MPU6050 uses a labeled 1x8 connector, and the external DFR0067 uses PH2.0 `VCC/GND/SIG` wiring. These labels must still be checked against received hardware before layout.

| Component | Signal | XIAO pin | ESP32 GPIO | Interface | Status |
|---|---|---:|---:|---|---|
| Adafruit 326 OLED | Data/SDA | D4 | GPIO6 | I2C | Selected product |
| Adafruit 3886 MPU6050 | SDA | D4 | GPIO6 | I2C | Selected product |
| Adafruit 326 OLED | Clk/SCL | D5 | GPIO7 | I2C | Selected product |
| Adafruit 3886 MPU6050 | SCL | D5 | GPIO7 | I2C | Selected product |
| DFRobot DFR0067 external connector pin 3 | SIG | D1 | GPIO3 | Single-wire digital | Proposed connector-only interface |
| APEM MJTP1230 SW1 | Active-low input | D2 | GPIO4 | Digital input | Proposed internal pull-up |
| APEM MJTP1230 SW2 | Active-low input | D3 | GPIO5 | Digital input | Proposed internal pull-up |
| Selected modules | 3V3/Vin as documented | 3V3 | — | Power | Verify current budget |
| Selected modules | GND | GND | — | Ground | Required |
| DFRobot DFR0067 external connector pin 1 | VCC | 3V3 | — | Power | PH2.0 connector; verify cable pin-1 orientation |
| DFRobot DFR0067 external connector pin 2 | GND | GND | — | Ground | PH2.0 connector; verify cable pin-1 orientation |
| Adafruit 3886 | INT | Not assigned | — | Optional interrupt | Expose only as optional connector signal |
| Adafruit 3886 | AD0 | Module default | — | Address select | Verify default is low / 0x68 |

## OLED connector change

The selected Adafruit 326 is not a 4-pin-only module. The current STEMMA-QT CAD shows a 1x6 header: GND, Vin, 3V, Data, Clk, RST. Only GND, Vin, Data, and Clk are used for Starbie's I2C design; the remaining pins are not assigned to XIAO GPIOs. Confirm the received revision before choosing a carrier header.

GPIO2, GPIO8, and GPIO9 remain unused because Seeed identifies them as ESP32-C3 strapping pins.

The DFR0067 module is not mounted on the PCB. Starbie exposes a labeled external PH2.0 3-pin connector intended for `VCC`, `GND`, `SIG` order. Confirm the selected cable's keyed orientation and pin order before schematic capture.
