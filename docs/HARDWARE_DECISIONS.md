# Starbie v1 hardware decisions

`VERIFIED` is stated by the cited source. `PROPOSED` is the selected implementation. `TBD` is required before schematic/layout.

| Decision | Reason | Source | Confidence | What still needs verification |
|---|---|---|---|---|
| Select Seeed XIAO ESP32C3 pre-soldered SKU 6331 / 113991054 family | Exact purchasable Seeed product with USB-C and published pin map | [Seeed product](https://www.seeedstudio.com/Seeed-Studio-XIAO-ESP32C3-Pre-Soldered-p-6331.html), [wiki](https://wiki.seeedstudio.com/XIAO_ESP32C3_Getting_Started/) | High | Exact revision, pad dimensions, antenna keepout, 3V3 current limit |
| Direct-solder the XIAO castellated pads | Avoids an additional connector and keeps the carrier small | [Seeed schematic](https://files.seeedstudio.com/Seeeduino-XIAO-ESP32C3-SCH.pdf) | Medium | Official mechanical drawing and pad geometry |
| Select Adafruit product 326 OLED | Exact documented product with I2C/SPI configuration | [Adafruit 326](https://www.adafruit.com/product/326), [wiring](https://learn.adafruit.com/monochrome-oled-breakouts/wiring-128x64-oleds) | High | Current revision outline, header orientation, pull-ups, address |
| Use a revision-matched OLED header area | Current STEMMA-QT CAD shows six header pads and older product-326 files differ; this avoids mixing revisions or guessing a generic module | [Adafruit OLED downloads](https://learn.adafruit.com/monochrome-oled-breakouts/downloads), [Adafruit CAD repository](https://github.com/adafruit/Adafruit-128x64-Monochrome-OLED-PCB) | High | Confirm received revision, six-pad pitch/orientation, display window, and mounting holes |
| Select Adafruit product 3886 MPU6050 breakout | Exact documented breakout has 3-5 V input, regulator, level shifting, pull-ups, AD0, and INT | [Adafruit 3886](https://www.adafruit.com/product/3886) | High | Received-board header order and orientation |
| Use MPU6050 address 0x68 and leave INT unassigned | Default address and polling are simplest for v1 | [TDK datasheet](https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Datasheet1.pdf), [Adafruit pinouts](https://learn.adafruit.com/mpu6050-6-dof-accelerometer-and-gyro/pinouts) | Medium | Confirm AD0 default and optional connector signal |
| Keep DFRobot DFR0067 as an external sensor | DFRobot identifies the SKU, 3-pin Gravity interface, 3.3-5 V operation, and digital single-wire output, but does not publish enough current mechanical data for a module footprint | [DFRobot product](https://www.dfrobot.com/product-174.html), [wiki](https://wiki.dfrobot.com/dfr0067/) | High | Confirm the selected cable/receptacle mating details; module dimensions and mounting holes are intentionally not used |
| Use a connector-only DFR0067 interface | Avoids a fragile module-specific outline and unverified hole pattern while retaining the selected sensor | DFRobot Gravity documentation; standard KiCad 2.00 mm header family | High | Confirm connector keying/orientation and cable availability before footprint assignment |
| Replace Omron B3F-4050 with APEM MJTP1230 | B3F-4050 is 12 x 12 mm and does not meet the requested 6 x 6 mm format; MJTP1230 is a documented 6 x 6 mm THT alternative | [Digi-Key](https://www.digikey.com/en/products/detail/apem-inc/MJTP1230/679-2428-ND), [APEM datasheet](https://www.apem.com/medias/sys_master/root/h7c/h00/8808403896350/TT_MJTP_PHAP33_D_US.pdf) | High | Confirm exact terminal geometry, actuator height, and library footprint |
| Use active-low buttons with internal pull-ups | Simple short-trace input circuit without extra resistors | Firmware skeleton and ESP32 Arduino GPIO behavior | Medium | Debounce implementation and hardware test |
| Do not initially add external I2C/DHT pull-ups | Avoid unverified duplicate pull-ups; DFR0067's official pages reviewed do not document a resistor value | [Adafruit 326](https://www.adafruit.com/product/326), [Adafruit 3886](https://learn.adafruit.com/mpu6050-6-dof-accelerometer-and-gyro/pinouts), [DFRobot DFR0067](https://www.dfrobot.com/product-174.html) | Medium | Inspect received modules and calculate bus resistance; add a DHT pull-up only if required by the actual sensor interface |

## Architecture change

The earlier generic four-pin OLED proposal is replaced by the exact, documented Adafruit product 326. The current STEMMA-QT board file shows a six-pad header (`GND`, `Vin`, `3V`, `Data`, `Clk`, `RST`), while the repository also contains older product-326 board files. The carrier must use the CAD/fabrication files matching the purchased revision; do not invent a generic 1x4 footprint or mix revisions.

## Mechanical verification decisions

- **PROPOSED:** Use product-specific CAD/fabrication sources for the XIAO, Adafruit 326, and Adafruit 3886 rather than redraw their outlines from nominal dimensions.
- **PROPOSED:** Use removable through-hole headers for the external modules in the first prototype. This makes replacement and orientation checking easier than direct soldering.
- **TBD:** Select the exact revision-matched OLED and MPU6050 connector orientation after the current module drawings or physical samples are inspected.
- **TBD:** Do not set the Starbie PCB outline or mounting-hole pattern until the display window and enclosure are designed.
- **RESOLVED FOR PCB ARCHITECTURE:** DFR0067 is external; Starbie uses only a labeled 3-pin connector, with no module outline or mounting holes.
- **TBD:** Confirm the selected 2.00 mm connector mates with the DFRobot Gravity cable and choose keyed or unkeyed hardware.
