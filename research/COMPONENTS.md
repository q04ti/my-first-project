# Locked component research

## Selected exact parts

- **XIAO:** Seeed Studio XIAO ESP32C3 pre-soldered listing, SKU 6331, board family 113991054.
- **OLED:** Adafruit Monochrome 0.96-inch 128x64 OLED Graphic Display, product 326.
- **MPU6050:** Adafruit MPU-6050 6-DoF breakout, product 3886.
- **DHT11:** DFRobot Gravity DHT11 module, DFR0067.
- **Buttons:** APEM MJTP1230, two units. The previously listed Omron B3F-4050 was rejected because its body is 12 x 12 mm rather than 6 x 6 mm.

## Still verify from received parts before schematic/layout

- XIAO revision, castellated-pad dimensions, antenna keepout, and current-limit interpretation.
- Adafruit 326 received revision's exact board outline, six-pin header pitch/orientation if STEMMA-QT, I2C jumper state, pull-up network, and address.
- Adafruit 3886 header pin order, mounting-hole positions, and AD0 default state.
- DFRobot DFR0067 current module board dimensions, connector pitch/order, and onboard data pull-up.
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

- **XIAO ESP32-C3:** Seeed OPL contains an `XIAO-ESP32-C3-DIP` KiCad footprint source. It must be matched to the purchased board revision and checked for pad geometry, USB edge, and antenna keepout.
- **Adafruit 326:** Adafruit publishes separate older and STEMMA-QT Eagle board files and fabrication prints. The current STEMMA-QT CAD file shows six header pads; use the files matching the received revision to confirm board outline, header placement, display opening, and mounting holes.
- **Adafruit 3886:** Adafruit publishes product-specific Eagle board files and a fabrication print. The product page documents 26.0 x 17.8 mm, four 2.5 mm holes, and 0.1-inch header compatibility; exact coordinates still require fab-print inspection.
- **DFRobot DFR0067:** The product is selected, but the current-revision board drawing/CAD and exact connector/hole coordinates are not sufficiently verified for a footprint.
- **APEM MJTP1230:** The manufacturer/distributor documents a 6 x 6 mm THT SPST-NO switch; exact terminal geometry and actuator height must be taken from the manufacturer drawing.
