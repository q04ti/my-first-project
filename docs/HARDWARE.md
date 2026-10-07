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
- **Header/pin order:** The current STEMMA-QT CAD shows `GND`, `Vin`, `3V`, `Data`, `Clk`, `RST`. Starbie uses GND, Vin, Data, and Clk.
- **Voltage:** Adafruit describes the board as 5V-ready with an onboard regulator and boost converter. Starbie will feed Vin from 3V3.
- **Pull-ups/address:** Verify the received revision's pull-up network and I2C address configuration before bus finalization.
- **Mechanical:** Adafruit publishes separate older and STEMMA-QT board files. Use the CAD/fabrication print matching the received revision; final window and mounting dimensions remain to be extracted.
- **Status:** Exact product selected; current revision must be matched before footprint assignment.
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
- **Mechanical:** DFRobot does not provide sufficient current module mechanical data for a reliable dedicated footprint. The DFR0067 will be external and cable-connected; Starbie will use only a standard 3-pin connector.
- **Signal electrical requirements:** DFRobot documents 3.3-5 V operation and a digital single-wire interface. The onboard pull-up resistor value is not documented in the official sources reviewed; do not assume it is present or omit a resistor without checking the selected module/cable.
- **Status:** Exact SKU selected; connector-only PCB integration proposed. Module outline, mounting holes, and resistor value are intentionally not used.
- **Sources:** [product](https://www.dfrobot.com/product-174.html), [wiki](https://wiki.dfrobot.com/dfr0067/)

## Buttons — APEM MJTP1230

- **Purpose:** Two user inputs.
- **Electrical:** SPST-NO through-hole switch; one switch side to GPIO and the other to GND.
- **Mechanical:** 6 x 6 mm body, 160 gf operating force, and 0.25 mm travel; use the manufacturer drawing for exact terminal geometry and actuator height.
- **Pull-up:** ESP32 internal pull-ups; no external button resistors selected.
- **Status:** Exact 6 x 6 mm replacement selected; footprint must match the datasheet drawing.
- **Sources:** [Digi-Key](https://www.digikey.com/en/products/detail/apem-inc/MJTP1230/679-2428-ND), [APEM datasheet](https://www.apem.com/medias/sys_master/root/h7c/h00/8808403896350/TT_MJTP_PHAP33_D_US.pdf)
