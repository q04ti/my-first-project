# Starbie v1 hardware decisions

`VERIFIED` is stated by the cited source. `PROPOSED` is the selected implementation. `TBD` is required before schematic/layout.

| Decision | Reason | Source | Confidence | What still needs verification |
|---|---|---|---|---|
| Select Seeed XIAO ESP32C3 pre-soldered SKU 6331 / 113991054 | Exact purchasable Seeed product with USB-C and published pin map; the product PDF identifies the 21.0 x 17.8 mm board family | [Seeed product](https://www.seeedstudio.com/Seeed-Studio-XIAO-ESP32C3-Pre-Soldered-p-6331.html), [product PDF](https://files.seeedstudio.com/Bazaar/product_pdf/113991054.pdf), [wiki](https://wiki.seeedstudio.com/XIAO_ESP32C3_Getting_Started/) | High | Confirm the purchased board revision and antenna keepout/pad land geometry |
| Use Seeed OPL XIAO-ESP32-C3-DIP as the candidate footprint | Official OPL source provides the candidate 14-pad-per-side, 2.54 mm DIP arrangement | [Seeed OPL library](https://github.com/Seeed-Studio/OPL_Kicad_Library/tree/master/Seeed%20Studio%20XIAO%20Series%20Library) | Medium | This remains a candidate only; the exact SKU/revision USB edge, pad land dimensions, board edge, antenna location, and keepout are not fully reconciled |
| Select Adafruit product 326 current STEMMA-QT variant | Official current Eagle board file identifies a 29.21 x 31.75 mm board and six labeled header signals | [Adafruit 326](https://www.adafruit.com/product/326), [OLED CAD](https://github.com/adafruit/Adafruit-128x64-Monochrome-OLED-PCB) | High | Ensure the purchased board is the STEMMA-QT variant, not an older Product 326 revision |
| Use a revision-matched OLED header area | Current STEMMA-QT CAD shows six header pads and older product-326 files differ; this avoids mixing revisions or guessing a generic module | [Adafruit OLED downloads](https://learn.adafruit.com/monochrome-oled-breakouts/downloads), [Adafruit CAD repository](https://github.com/adafruit/Adafruit-128x64-Monochrome-OLED-PCB) | High | Confirm received revision, six-pad pitch/orientation, display window, and mounting holes |
| Select Adafruit product 3886 MPU6050 breakout | Official Eagle board file defines a 25.40 x 17.78 mm carrier and 2.54 mm header; a connector-only Starbie interface avoids relying on module mounting holes | [Adafruit 3886](https://www.adafruit.com/product/3886), [MPU6050 CAD](https://github.com/adafruit/Adafruit-MPU6050-PCB) | High | Confirm the purchased board's header labeling and use a standard 1x8 connector |
| Use MPU6050 address 0x68 and leave INT unassigned | Default address and polling are simplest for v1 | [TDK datasheet](https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Datasheet1.pdf), [Adafruit pinouts](https://learn.adafruit.com/mpu6050-6-dof-accelerometer-and-gyro/pinouts) | Medium | Confirm AD0 default and optional connector signal |
| Keep DFRobot DFR0067 as an external sensor | DFRobot identifies the SKU, 3-pin Gravity interface, 3.3-5 V operation, and digital single-wire output, but does not publish enough current mechanical data for a module footprint | [DFRobot product](https://www.dfrobot.com/product-174.html), [wiki](https://wiki.dfrobot.com/dfr0067/) | High | Module dimensions and mounting holes are intentionally not used |
| Use a connector-only DFR0067 interface | Avoids a fragile module-specific outline and unverified hole pattern while retaining the selected sensor | [DFRobot PH2.0 cable](https://www.dfrobot.com/product-2554.html); standard KiCad 2.00 mm header family | High | Confirm the chosen connector's exact mating housing and pin-1/pin-order orientation; do not assume generic Gravity order |
| Replace MJTP1230 with Omron B3F-1000 | Commonly available 6 x 6 mm, 4-pin through-hole tactile switch with an authoritative manufacturer drawing and standard THT switch geometry | [Omron B3F datasheet](https://omronfs.omron.com/en_US/ecb/products/pdf/en-b3f.pdf) | High | Confirm the purchased B3F-1000 suffix and actuator height before enclosure design |
| Use active-low buttons with internal pull-ups | Simple short-trace input circuit without extra resistors | Firmware skeleton and ESP32 Arduino GPIO behavior | Medium | Debounce implementation and hardware test |
| Do not initially add external I2C/DHT pull-ups | Avoid unverified duplicate pull-ups; DFR0067's official pages reviewed do not document a resistor value | [Adafruit 326](https://www.adafruit.com/product/326), [Adafruit 3886](https://learn.adafruit.com/mpu6050-6-dof-accelerometer-and-gyro/pinouts), [DFRobot DFR0067](https://www.dfrobot.com/product-174.html) | Medium | Inspect received modules and calculate bus resistance; add a DHT pull-up only if required by the actual sensor interface |

## Architecture change

The earlier generic four-pin OLED proposal is replaced by the exact, documented Adafruit product 326. The current STEMMA-QT board file shows a six-pad header (`GND`, `Vin`, `3V`, `Data`, `Clk`, `RST`), while the repository also contains older product-326 board files. The carrier must use the CAD/fabrication files matching the purchased revision; do not invent a generic 1x4 footprint or mix revisions.

## Schematic and PCB readiness

- **READY FOR SCHEMATIC:** The electrical architecture and MCU pin assignment are sufficiently defined. The schematic may use generic connector symbols and placeholder footprints.
- **NOT READY FOR PCB:** Final XIAO geometry, the selected OLED revision's physical header orientation, the exact MPU6050 connector implementation, and the DFR0067 mating connector still require physical verification before placement or routing.
- **BLOCKED ITEMS:** XIAO antenna/USB clearance reconciliation, exact DFR0067 physical pin order, and final connector/switch footprint selection.

The DFR0067 connector is intentionally represented as a keyed three-pin interface. Its physical pin order must be verified against the purchased cable at manufacturing time; no unproven VCC/GND/SIG order is encoded in the schematic.

## Mechanical verification decisions

- **PROPOSED:** Use product-specific CAD/fabrication sources for the XIAO, Adafruit 326, and Adafruit 3886 rather than redraw their outlines from nominal dimensions.
- **PROPOSED:** Use removable through-hole headers for the external modules in the first prototype. This makes replacement and orientation checking easier than direct soldering.
- **TBD:** Select the exact revision-matched OLED and confirm the XIAO purchased revision before footprint assignment.
- **TBD:** Do not set the Starbie PCB outline or mounting-hole pattern until the display window and enclosure are designed.
- **RESOLVED FOR PCB ARCHITECTURE:** DFR0067 is external; Starbie uses only a labeled 3-pin connector, with no module outline or mounting holes.
- **TBD:** Confirm the selected 2.00 mm connector mates with the DFRobot Gravity cable and choose keyed or unkeyed hardware.
- **DEFERRED TO PCB:** XIAO revision-matched geometry and antenna keepout are required before layout. During layout, keep the antenna-side region free of copper, traces, mounting hardware, and conductive enclosure material until the exact source geometry is copied.
- **DEFERRED TO MANUFACTURING VERIFICATION:** DFR0067 cable pin-1/pin-order mapping remains unresolved; do not fabricate a VCC/GND/SIG mapping from assumptions.
