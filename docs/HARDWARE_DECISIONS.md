# Starbie hardware decisions

This is the review record before schematic capture. Confidence describes confidence in the decision for the stated first prototype, not electrical validation.

| Decision | Reason | Source | Confidence | What still needs verification |
|---|---|---|---|---|
| Use Seeed Studio XIAO ESP32C3 as the controller | It supplies the required ESP32-C3 Arduino path, USB-C access, compact 21 x 17.8 mm board, and published D4/D5 I2C pins | [Seeed XIAO ESP32C3 Getting Started](https://wiki.seeedstudio.com/XIAO_ESP32C3_Getting_Started/) | High | Exact product revision, 3V3 current limit, pad geometry, footprint, antenna keepout |
| Keep D4/GPIO6 and D5/GPIO7 for the shared I2C bus | Seeed publishes D4 as SDA/GPIO6 and D5 as SCL/GPIO7 | [Seeed pin map](https://wiki.seeedstudio.com/XIAO_ESP32C3_Getting_Started/) | High | Confirm selected modules' pin order, pull-ups, and addresses |
| Avoid GPIO2, GPIO8, and GPIO9 | Seeed identifies them as ESP32-C3 strapping pins that can affect boot | [Seeed strapping-pin guidance](https://wiki.seeedstudio.com/XIAO_ESP32C3_Getting_Started/) | High | Check any future redesign before reusing these pins |
| USB-C through the XIAO is revision-1 power | It avoids unnecessary battery and regulator complexity while retaining programming access | [Seeed power and battery guidance](https://wiki.seeedstudio.com/XIAO_ESP32C3_Getting_Started/) | High | Verify total 3V3 load and USB cable access in the mechanical design |
| Power verified external modules from XIAO 3V3 | The sensor logic should remain compatible with the ESP32-C3; this avoids 5 V level uncertainty | [Seeed pin map/power pins](https://wiki.seeedstudio.com/XIAO_ESP32C3_Getting_Started/) | Medium | Confirm each selected module's supply and logic specification |
| Use a 4-pin I2C OLED module connector, not a unique OLED part yet | Many modules expose GND/VCC/SCL/SDA, but listings vary and no exact module was uniquely identified | [Winstar 4-pin OLED reference](https://www.winstar.com.tw/products/oled-module/graphic-oled-display/4-pin-oled.html) | Medium | Select manufacturer/part number, voltage, address, dimensions, pin order, pull-ups |
| Mount a complete MPU6050 module rather than the bare IC | A module is safer for a beginner first PCB because it reduces fine-pitch assembly and unknown support circuitry | [TDK/InvenSense MPU-6050 datasheet](https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Datasheet1.pdf) | Medium | Select module; verify regulator, level shifting, pull-ups, decoupling, pinout |
| Use MPU6050 AD0 low and address 0x68 | This is the datasheet's default address and no second IMU is planned | [TDK/InvenSense MPU-6050 datasheet](https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Datasheet1.pdf) | High | Confirm selected module does not force AD0 high |
| Leave MPU6050 INT unused in revision 1 | Polling is simpler for first firmware and the planned pinout has no spare dedicated signal requirement | [TDK/InvenSense MPU-6050 datasheet](https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Datasheet1.pdf) | Medium | Reserve an optional pad if the selected module exposes INT |
| Prefer a 3-pin DHT11 module | It is mechanically and electrically simpler than a bare 4-pin sensor if its onboard pull-up is verified | [DHT11 technical datasheet reference](https://www.mouser.com/datasheet/2/758/DHT11-Technical-Data-Sheet-Translated-Version-1143054.pdf) | Medium | Exact module, pull-up presence, voltage, footprint, data timing |
| Use active-low through-hole 6 x 6 mm buttons with internal pull-ups | THT is robust for a beginner board; internal pull-ups avoid unnecessary resistors | [Digi-Key KiCad footprint example](https://github.com/Digi-Key/digikey-kicad-library/blob/master/digikey-footprints.pretty/Switch_Tactile_THT_6x6mm_MJTP1230.kicad_mod) | Medium | Exact switch datasheet, footprint, actuator height, firmware debounce |
| Do not add a regulator, battery system, or generic protection network yet | The preferred architecture is USB through the XIAO and adding unverified parts would increase risk | Seeed power guidance linked above | Medium | Revisit after module current and power requirements are known |
| Treat external I2C pull-ups and DHT pull-up as conditional | Modules may already include these resistors; duplicating them can overload the bus or be redundant | Selected-module schematics required; SSD1306 and DHT references above | Medium | Inspect exact module schematics before final BOM/schematic |

## Explicit discrepancy with the starter guide

The starter guide's GPIO assignments are consistent with Seeed's published XIAO ESP32C3 pin map for D4/GPIO6, D5/GPIO7, D1/GPIO3, D2/GPIO4, and D3/GPIO5. The guide does not by itself establish the exact module voltage, connector ordering, pull-up population, or board footprint. Those remain `TBD`.

Seeed's own page also lists two different 3V3 output-current figures (500 mA in the specifications table and 700 mA in the power-pin section). Starbie will not use either number as a design guarantee until the specific board documentation and total load are reviewed.

