# Starbie v1 selected components

Prices below are current observed single-unit prices from the cited store/product research on 2026-10-07, in USD, before tax and shipping. They are not guaranteed quotes.

| Component | Selected Part | Manufacturer | Part Number | Source | Key Specs | Status |
|---|---|---|---|---|---|---|
| Microcontroller | XIAO ESP32C3 pre-soldered | Seeed Studio | SKU 6331 / board 113991054 family | [Seeed product page](https://www.seeedstudio.com/Seeed-Studio-XIAO-ESP32C3-Pre-Soldered-p-6331.html) | ESP32-C3, 21 x 17.8 mm, USB-C, D4/GPIO6 SDA, D5/GPIO7 SCL, 3V3 output, 5V VBUS | Selected; verify exact SKU/revision before layout |
| OLED | Monochrome 0.96-inch 128x64 OLED breakout, I2C mode | Adafruit | Product 326 | [Adafruit product page](https://www.adafruit.com/product/326) | SSD1306-family display, current six-pin header, 3-5 V input, onboard regulator/boost, auto-reset, I2C/SPI jumpers; observed price $17.50 | Selected; identify received revision before footprint assignment |
| Motion sensor | MPU-6050 6-DoF breakout | Adafruit | Product 3886 | [Adafruit product page](https://www.adafruit.com/product/3886) | 26.0 x 17.8 x 4.6 mm, 2.5 mm mounting holes, 3-5 V input, onboard 3.3 V regulator, I2C level shifting, 10 kOhm I2C pull-ups, AD0 and INT exposed; observed price $12.95 | Selected; use documented breakout signals |
| Environment sensor | Gravity DHT11 Temperature & Humidity Sensor | DFRobot | DFR0067 | [DFRobot product page](https://www.dfrobot.com/product-174.html) / [DFRobot wiki](https://wiki.dfrobot.com/dfr0067/) | 3-pin Gravity interface VCC/GND/SIG, 3.3-5 V compatible, single-wire output, module pull-up reported; observed price approximately $4.20 | Selected module; dimensions and resistor require final check |
| Button | Tactile switch, through-hole, standard 6 x 6 mm | APEM | MJTP1230 | [Digi-Key listing](https://www.digikey.com/en/products/detail/apem-inc/MJTP1230/679-2428-ND) / [APEM datasheet](https://www.apem.com/medias/sys_master/root/h7c/h00/8808403896350/TT_MJTP_PHAP33_D_US.pdf) | 6 x 6 mm SPST-NO THT, 160 gf, 0.25 mm travel; observed price approximately $0.26 each | Selected replacement; verify exact terminal drawing |

## OLED selection clarification

Product 326 is the selected exact, documented part, but it is not a four-pin-only module. The current STEMMA-QT revision's CAD file shows a six-pad header, with the documented header order `GND`, `Vin`, `3V`, `Data`, `Clk`, `RST`. Starbie v1 will use GND, Vin, Data (SDA), and Clk (SCL). This changes the carrier connector from the earlier proposed generic 1x4 to a revision-matched 1x6 header area.

Adafruit also publishes older product-326 board files. Do not mix the older and STEMMA-QT revisions when creating the carrier footprint.

## Button selection correction

The previously listed Omron B3F-4050 is a 12 x 12 mm switch, not the requested 6 x 6 mm format. It is removed from the v1 selection. APEM MJTP1230 is the replacement documented as a 6 x 6 mm through-hole switch.
