# Starbie v1 selected components

Prices below are current observed single-unit prices from the cited store/product research on 2026-10-07, in USD, before tax and shipping. They are not guaranteed quotes.

| Component | Selected Part | Manufacturer | Part Number | Source | Key Specs | Status |
|---|---|---|---|---|---|---|
| Microcontroller | XIAO ESP32C3 pre-soldered | Seeed Studio | SKU 6331 / board 113991054 family | [Seeed product page](https://www.seeedstudio.com/Seeed-Studio-XIAO-ESP32C3-Pre-Soldered-p-6331.html) | ESP32-C3, 21 x 17.8 mm, USB-C, D4/GPIO6 SDA, D5/GPIO7 SCL, 3V3 output, 5V VBUS | Selected; verify exact SKU/revision before layout |
| OLED | Monochrome 0.96-inch 128x64 OLED breakout, I2C mode | Adafruit | Product 326 | [Adafruit product page](https://www.adafruit.com/product/326) | SSD1306-family display, 8-pin header, 3-5 V input, onboard regulator/boost, auto-reset, I2C/SPI jumpers; observed price $17.50 | Selected; use documented 8-pin breakout, not a 4-pin generic module |
| Motion sensor | MPU-6050 6-DoF breakout | Adafruit | Product 3886 | [Adafruit product page](https://www.adafruit.com/product/3886) | 26.0 x 17.8 x 4.6 mm, 2.5 mm mounting holes, 3-5 V input, onboard 3.3 V regulator, I2C level shifting, 10 kOhm I2C pull-ups, AD0 and INT exposed; observed price $12.95 | Selected; use documented breakout signals |
| Environment sensor | Gravity DHT11 Temperature & Humidity Sensor | DFRobot | DFR0067 | [DFRobot product page](https://www.dfrobot.com/product-174.html) / [DFRobot wiki](https://wiki.dfrobot.com/dfr0067/) | 3-pin Gravity interface VCC/GND/SIG, 3.3-5 V compatible, single-wire output, module pull-up reported; observed price approximately $4.20 | Selected module; dimensions and resistor require final check |
| Button | Tactile switch, through-hole, standard 6 x 6 mm | Omron | B3F-4050 | [Digi-Key listing](https://www.digikey.com/en/products/detail/omron-electronics-inc-emc-div/B3F-4050/277486) / [Mouser datasheet](https://www.mouser.com/datasheet/2/307/en-b3f-292310.pdf) | 4-pin SPST-NO THT, 6 x 6 mm body, approximately 7.3 mm actuator height; observed price approximately $0.23 each | Selected; verify exact footprint drawing |

## OLED selection clarification

Product 326 is the selected exact, documented part, but it is not a four-pin-only module. Its 8-pin header supports I2C and SPI. Starbie v1 will use GND, Vin, Data (SDA), and Clk (SCL). This changes the carrier connector from the earlier proposed generic 1x4 to a documented 1x8 header area.

