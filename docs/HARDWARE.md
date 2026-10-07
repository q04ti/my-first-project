# Starbie v1 selected hardware

This records selected purchasable parts. The design is not electrically validated and no KiCad design exists.

## XIAO ESP32C3 — Seeed Studio SKU 6331 / 113991054 family

- **Purpose:** ESP32-C3 controller and USB-C programming/power board.
- **Dimensions:** 21 x 17.8 mm.
- **Pin mapping:** D4/GPIO6 SDA, D5/GPIO7 SCL, D1/GPIO3, D2/GPIO4, D3/GPIO5.
- **Power:** 5V is USB VBUS; 3V3 is regulated output. Seeed's page contains conflicting 500 mA and 700 mA 3V3 figures, so no maximum external load is claimed.
- **Integration:** Proposed direct soldering of castellated pads using verified official mechanical data. No fabricated footprint is present.
- **Status:** Selected part family; exact board revision/pad drawing TBD.
- **Sources:** [product](https://www.seeedstudio.com/Seeed-Studio-XIAO-ESP32C3-Pre-Soldered-p-6331.html), [pinout](https://wiki.seeedstudio.com/XIAO_ESP32C3_Getting_Started/), [schematic](https://files.seeedstudio.com/Seeeduino-XIAO-ESP32C3-SCH.pdf)

## OLED — Adafruit product 326

- **Purpose:** 0.96-inch, 128x64 monochrome OLED.
- **Interface:** I2C selected using the board jumpers; `Data` is SDA and `Clk` is SCL.
- **Header/pin order:** `GND`, `Vin`, `3V`, `Data`, `Clk`, `RST`, `DC`, `CS`. Starbie uses GND, Vin, Data, and Clk.
- **Voltage:** Adafruit describes the board as 5V-ready with an onboard regulator and boost converter. Starbie will feed Vin from 3V3.
- **Pull-ups/address:** Verify the received revision's pull-up network and I2C address configuration before bus finalization.
- **Mechanical:** Use the product's documented breakout/header arrangement; final window and mounting dimensions must be taken from current product CAD/drawing.
- **Status:** Exact product selected; connector orientation and received-revision drawing TBD.
- **Sources:** [product](https://www.adafruit.com/product/326), [I2C wiring](https://learn.adafruit.com/monochrome-oled-breakouts/wiring-128x64-oleds)

## MPU6050 — Adafruit product 3886

- **Purpose:** Motion/orientation sensing.
- **Interface:** I2C; AD0 selects 0x68/0x69; INT is available.
- **Voltage:** Breakout accepts 3-5 V input and includes a regulator.
- **Logic:** Adafruit documents I2C level shifting and 10 kOhm pull-ups.
- **Pin signals:** Vin, 3Vo, GND, SCL, SDA, INT, AD0 and support pins; verify physical header labeling on the received board.
- **Dimensions:** 26.0 x 17.8 x 4.6 mm; four 2.5 mm mounting holes.
- **INT:** Optional connector signal, not assigned to a Starbie GPIO in v1.
- **Status:** Exact product selected; final connector/header arrangement TBD.
- **Sources:** [product](https://www.adafruit.com/product/3886), [pinouts](https://learn.adafruit.com/mpu6050-6-dof-accelerometer-and-gyro/pinouts)

## DHT11 — DFRobot DFR0067

- **Purpose:** Temperature and humidity.
- **Interface/pin order:** Gravity 3-pin interface: `VCC`, `GND`, `SIG`.
- **Voltage:** 3.3-5 V compatibility is documented by DFRobot.
- **Pull-up:** Intended as plug-and-play; confirm the onboard pull-up from the current module revision before omitting an external resistor.
- **Mechanical:** Current module dimensions and connector drawing must be taken from DFRobot mechanical files before footprint creation.
- **Status:** Exact SKU selected; onboard resistor and mechanical drawing TBD.
- **Sources:** [product](https://www.dfrobot.com/product-174.html), [wiki](https://wiki.dfrobot.com/dfr0067/)

## Buttons — Omron B3F-4050

- **Purpose:** Two user inputs.
- **Electrical:** SPST-NO, four through-hole terminals; one switch side to GPIO and the other to GND.
- **Mechanical:** 6 x 6 mm body, approximately 7.3 mm actuator height; use the manufacturer drawing for pad geometry.
- **Pull-up:** ESP32 internal pull-ups; no external button resistors selected.
- **Status:** Exact part selected; footprint must match the datasheet drawing.
- **Sources:** [Digi-Key](https://www.digikey.com/en/products/detail/omron-electronics-inc-emc-div/B3F-4050/277486), [Mouser datasheet](https://www.mouser.com/datasheet/2/307/en-b3f-292310.pdf)
