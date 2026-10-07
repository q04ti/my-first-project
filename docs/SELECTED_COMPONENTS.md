# Starbie v1 selected components

Prices below are current observed single-unit prices from the cited store/product research on 2026-10-07, in USD, before tax and shipping. They are not guaranteed quotes.

| Component | Selected Part | Manufacturer | Part Number | Source | Key Specs | Status |
|---|---|---|---|---|---|---|
| Microcontroller | XIAO ESP32C3 pre-soldered | Seeed Studio | SKU 6331 / board 113991054 | [Seeed product page](https://www.seeedstudio.com/Seeed-Studio-XIAO-ESP32C3-Pre-Soldered-p-6331.html), [product PDF](https://files.seeedstudio.com/Bazaar/product_pdf/113991054.pdf) | ESP32-C3, 21 x 17.8 mm, USB-C, 14 castellated pads per side at 2.54 mm pitch in the official DIP footprint source | Selected; revision, pad land geometry, and antenna keepout remain blockers |
| OLED | Monochrome 0.96-inch 128x64 OLED STEMMA-QT breakout, I2C mode | Adafruit | Product 326 current STEMMA-QT variant | [Adafruit product page](https://www.adafruit.com/product/326), [official CAD](https://github.com/adafruit/Adafruit-128x64-Monochrome-OLED-PCB) | Official board file: 29.21 x 31.75 mm outline; six labeled signals GND, Vin, 3V, Data, Clk, Rst; 2.54 mm header | Verified for connector-only carrier; do not use older eight-pin files |
| Motion sensor | MPU-6050 6-DoF breakout | Adafruit | Product 3886 | [Adafruit product page](https://www.adafruit.com/product/3886), [official CAD](https://github.com/adafruit/Adafruit-MPU6050-PCB) | Official board file: 25.40 x 17.78 mm outline; 2.54 mm header; use a standard 1x8 connector and no module footprint | Verified for connector-only carrier |
| Environment sensor | Gravity DHT11 Temperature & Humidity Sensor | DFRobot | DFR0067 | [DFRobot product page](https://www.dfrobot.com/product-174.html) / [DFRobot wiki](https://wiki.dfrobot.com/dfr0067/) | 3-pin Gravity interface, 3.3-5 V compatible, single-wire output; observed price approximately $4.20 | Selected external module; no dedicated module footprint; resistor value not documented in reviewed official sources |
| Button | Tactile switch, through-hole, standard 6 x 6 mm | Omron | B3F-1000 | [Omron B3F datasheet](https://omronfs.omron.com/en_US/ecb/products/pdf/en-b3f.pdf) | 6 x 6 mm, 4-pin SPST-NO THT family with manufacturer mechanical drawing | Selected replacement; confirm exact actuator-height suffix before enclosure design |

## OLED selection clarification

Product 326 is the selected exact, documented part, but it is not a four-pin-only module. The current STEMMA-QT revision's CAD file shows a six-pad header, with the documented header order `GND`, `Vin`, `3V`, `Data`, `Clk`, `RST`. Starbie v1 will use GND, Vin, Data (SDA), and Clk (SCL). This changes the carrier connector from the earlier proposed generic 1x4 to a revision-matched 1x6 header area.

Adafruit also publishes older product-326 board files. Do not mix the older and STEMMA-QT revisions when creating the carrier footprint.

## Button selection correction

The previously listed Omron B3F-4050 is a 12 x 12 mm switch, not the requested 6 x 6 mm format. It is removed from the v1 selection. Omron B3F-1000 is now the selected 6 x 6 mm through-hole replacement; its exact actuator-height suffix must be fixed before enclosure design.
