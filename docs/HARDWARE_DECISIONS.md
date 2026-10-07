# Starbie v1 hardware decisions

`VERIFIED` is stated by the cited source. `PROPOSED` is the selected implementation. `TBD` is required before schematic/layout.

| Decision | Reason | Source | Confidence | What still needs verification |
|---|---|---|---|---|
| Select Seeed XIAO ESP32C3 pre-soldered SKU 6331 / 113991054 family | Exact purchasable Seeed product with USB-C and published pin map | [Seeed product](https://www.seeedstudio.com/Seeed-Studio-XIAO-ESP32C3-Pre-Soldered-p-6331.html), [wiki](https://wiki.seeedstudio.com/XIAO_ESP32C3_Getting_Started/) | High | Exact revision, pad dimensions, antenna keepout, 3V3 current limit |
| Direct-solder the XIAO castellated pads | Avoids an additional connector and keeps the carrier small | [Seeed schematic](https://files.seeedstudio.com/Seeeduino-XIAO-ESP32C3-SCH.pdf) | Medium | Official mechanical drawing and pad geometry |
| Select Adafruit product 326 OLED | Exact documented product with I2C/SPI configuration | [Adafruit 326](https://www.adafruit.com/product/326), [wiring](https://learn.adafruit.com/monochrome-oled-breakouts/wiring-128x64-oleds) | High | Current revision outline, header orientation, pull-ups, address |
| Use an 8-pin OLED header area | Product 326 is an 8-pin breakout; this avoids guessing a generic 4-pin module | [Adafruit wiring](https://learn.adafruit.com/monochrome-oled-breakouts/wiring-128x64-oleds) | High | Final pitch/orientation and display window |
| Select Adafruit product 3886 MPU6050 breakout | Exact documented breakout has 3-5 V input, regulator, level shifting, pull-ups, AD0, and INT | [Adafruit 3886](https://www.adafruit.com/product/3886) | High | Received-board header order and orientation |
| Use MPU6050 address 0x68 and leave INT unassigned | Default address and polling are simplest for v1 | [TDK datasheet](https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Datasheet1.pdf), [Adafruit pinouts](https://learn.adafruit.com/mpu6050-6-dof-accelerometer-and-gyro/pinouts) | Medium | Confirm AD0 default and optional connector signal |
| Select DFRobot DFR0067 DHT11 module | Exact SKU with documented 3-pin Gravity interface | [DFRobot product](https://www.dfrobot.com/product-174.html), [wiki](https://wiki.dfrobot.com/dfr0067/) | Medium | Current dimensions, connector drawing, onboard pull-up |
| Select Omron B3F-4050 buttons | Identifiable 6 x 6 mm THT part with distributor listing and datasheet | [Digi-Key](https://www.digikey.com/en/products/detail/omron-electronics-inc-emc-div/B3F-4050/277486), [datasheet](https://www.mouser.com/datasheet/2/307/en-b3f-292310.pdf) | High | Exact terminal geometry and actuator clearance |
| Use active-low buttons with internal pull-ups | Simple short-trace input circuit without extra resistors | Firmware skeleton and ESP32 Arduino GPIO behavior | Medium | Debounce implementation and hardware test |
| Do not initially add external I2C/DHT pull-ups | Selected module documentation reports onboard support; duplication can be harmful or redundant | [Adafruit 326](https://www.adafruit.com/product/326), [Adafruit 3886](https://learn.adafruit.com/mpu6050-6-dof-accelerometer-and-gyro/pinouts), [DFRobot DFR0067](https://www.dfrobot.com/product-174.html) | Medium | Inspect received revisions and calculate bus resistance |

## Architecture change

The earlier generic four-pin OLED proposal is replaced by the exact, documented Adafruit product 326. It uses an 8-pin header in I2C mode; the carrier must use that documented arrangement instead of inventing a generic 1x4 footprint.
