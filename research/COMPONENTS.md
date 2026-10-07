# Locked component research

## Selected exact parts

- **XIAO:** Seeed Studio XIAO ESP32C3 pre-soldered listing, SKU 6331, board family 113991054.
- **OLED:** Adafruit Monochrome 0.96-inch 128x64 OLED Graphic Display, product 326.
- **MPU6050:** Adafruit MPU-6050 6-DoF breakout, product 3886.
- **DHT11:** DFRobot Gravity DHT11 module, DFR0067.
- **Buttons:** Omron B3F-4050, two units.

## Still verify from received parts before schematic/layout

- XIAO revision, castellated-pad dimensions, antenna keepout, and current-limit interpretation.
- Adafruit 326 current revision's exact board outline, 8-pin header pitch/orientation, I2C jumper state, pull-up network, and address.
- Adafruit 3886 header pin order, mounting-hole positions, and AD0 default state.
- DFRobot DFR0067 current module board dimensions, connector pitch/order, and onboard data pull-up.
- Omron B3F-4050 exact terminal geometry, footprint pad/hole sizes, and 7.3 mm actuator clearance.
- Aggregate 3V3 current and whether selected modules' pull-ups create an acceptable I2C resistance.

## Components intentionally not added

- No external voltage regulator.
- No Li-ion battery connector or charging circuit.
- No external button pull-up resistors.
- No external I2C pull-up resistors initially.
- No DHT11 pull-up initially; add one only if the received DFR0067 module lacks it.
- No fabricated footprints or KiCad libraries.
