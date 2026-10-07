# Locked component research

## Selected exact parts

- **XIAO:** Seeed Studio XIAO ESP32C3 pre-soldered listing, SKU 6331, board family 113991054.
- **OLED:** Adafruit Monochrome 0.96-inch 128x64 OLED Graphic Display, product 326.
- **MPU6050:** Adafruit MPU-6050 6-DoF breakout, product 3886.
- **DHT11:** DFRobot Gravity DHT11 module, DFR0067.
- **Buttons:** APEM MJTP1230, two units. The previously listed Omron B3F-4050 was rejected because its body is 12 x 12 mm rather than 6 x 6 mm.

## Still verify from received parts before schematic/layout

- XIAO purchased revision, castellated-pad land dimensions, USB edge, antenna keepout, and current-limit interpretation.
- Adafruit 326 purchase variant matching the current STEMMA-QT CAD; do not use the older eight-pin revision.
- Adafruit 3886 received-board labels; Starbie uses a standard connector and does not depend on the module outline.
- DFRobot DFR0067 onboard data pull-up. The PH2.0 connector family is confirmed by DFRobot's cable listing; module dimensions are intentionally not used.
- APEM MJTP1230 exact terminal geometry, footprint pad/hole sizes, and actuator clearance.
- Aggregate 3V3 current and whether selected modules' pull-ups create an acceptable I2C resistance.

## Components intentionally not added

- No external voltage regulator.
- No Li-ion battery connector or charging circuit.
- No external button pull-up resistors.
- No external I2C pull-up resistors initially.
- No DHT11 pull-up initially; add one only if the received DFR0067 module lacks it.
- No fabricated footprints or KiCad libraries.

## Mechanical verification status

- **XIAO ESP32-C3:** Seeed product PDF and OPL provide the selected board family and candidate DIP footprint. Antenna keepout and final purchased-board matching remain unresolved.
- **Adafruit 326:** Current STEMMA-QT Eagle board file defines 29.21 x 31.75 mm and the six labeled signals; use a standard 1x6, 2.54 mm connector and do not mix older files.
- **Adafruit 3886:** Official Eagle board file defines 25.40 x 17.78 mm and 2.54 mm header geometry. Use a standard 1x8 connector; no carrier module footprint is needed.
- **DFRobot DFR0067:** Keep the module external. Use a labeled 3-pin connector-only interface and do not depend on undocumented module dimensions, mounting holes, or resistor value. Confirm the selected connector mates with the Gravity cable.
- **APEM MJTP1230:** Manufacturer family documentation identifies the 6 x 6 mm THT family and approximately 4.3 mm nominal height, but exact terminal/hole geometry still must be extracted before footprint assignment.
