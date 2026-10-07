# Starbie hardware architecture

> **Design status: research complete for a preliminary architecture.**
>
> `VERIFIED` means supported by the cited manufacturer/datasheet source. `PROPOSED` means the recommended first-design choice. `TBD` means it must be checked against the exact part before schematic capture. This is not an electrical validation report.

## Seeed Studio XIAO ESP32C3

- **Purpose:** Main microcontroller, USB-C programming interface, wireless capability, and application logic.
- **Interface:** Arduino-compatible ESP32-C3; the published XIAO pin map exposes I2C on D4/GPIO6 and D5/GPIO7.
- **Expected voltage:** `VERIFIED`: Seeed documents 5V as USB VBUS and 3V3 as regulated output. The same page reports both 500 mA (specifications table) and 700 mA (power-pin section) for 3V3 output; treat the usable external-current budget as `TBD` until the board revision and regulator limits are confirmed.
- **Important design considerations:** Board size is documented as 21 x 17.8 mm. GPIO2, GPIO8, and GPIO9 are ESP32-C3 strapping pins; this design avoids them. The board has reset and boot buttons, so do not reuse those functions mechanically without checking the board.
- **Battery:** `VERIFIED`: the board supports a 3.7 V lithium battery through underside battery pads and includes charging/discharge management. Battery use is intentionally excluded from Starbie revision 1.
- **PCB footprint:** `PROPOSED`: place the XIAO as a daughterboard using a verified castellated-pad footprint or two matching 1x7 connector rows. No official Seeed KiCad symbol/footprint was identified in the cited documentation; a community footprint may be used only after pad and keepout verification.
- **Status:** `VERIFIED` product family and pin map; exact procurement revision and footprint `TBD`.
- **Source:** [Seeed XIAO ESP32C3 Getting Started](https://wiki.seeedstudio.com/XIAO_ESP32C3_Getting_Started/), [Seeed product PDF](https://files.seeedstudio.com/Bazaar/product_pdf/113991054.pdf)

## 0.96-inch 128x64 SSD1306 I2C OLED

- **Purpose:** Pixel-art pet, menus, sensor values, and animations.
- **Interface:** `PROPOSED`: 4-pin I2C module using GND, VCC, SCL, and SDA. I2C is shared with the MPU6050.
- **Expected voltage:** `TBD`: SSD1306 is the controller, not a unique module specification. Module supply and logic behavior vary. Use 3.3 V only after the selected module datasheet confirms it.
- **Address:** `PROPOSED`: 0x3C is the first address to check; 0x3D is also common and must be confirmed by the selected module.
- **Reset:** `TBD`: a 4-pin I2C module normally does not expose a separate reset pin; verify the selected module's controller wiring.
- **Pull-ups:** `TBD`: do not assume every module has pull-ups. Inspect the selected module schematic or measure/verify its resistor network before adding another pair.
- **Connector/footprint:** `PROPOSED`: a clearly labeled 1x4, 2.54 mm through-hole connector area, with pin order explicitly documented on the PCB. The exact module and mechanical outline remain `TBD`.
- **Status:** Interface choice proposed; exact manufacturer, part number, voltage, address, pin order, and footprint `TBD`.
- **Source:** [Solomon Systech SSD1306 product page](https://www.solomon-systech.com/en/product/advanced-display-ic/oled-display-driver-controller/ssd1306/), [Winstar 4-pin OLED reference](https://www.winstar.com.tw/products/oled-module/graphic-oled-display/4-pin-oled.html)

## MPU6050 motion sensor

- **Purpose:** Detect motion and orientation changes.
- **Interface:** I2C on the shared SDA/SCL bus. AD0 selects the address.
- **Supply and logic:** `VERIFIED` for the IC: the MPU-6050 supply range is approximately 2.375-3.46 V in the TDK/InvenSense datasheet. A breakout's 5 V claim is a property of that breakout, not the IC.
- **Address:** `VERIFIED`: AD0 low gives 0x68; AD0 high gives 0x69.
- **Interrupt:** `VERIFIED`: INT is an available programmable interrupt output. `PROPOSED`: leave INT unconnected in revision 1 and poll the sensor; reserve an optional test/pad connection if the chosen module exposes it.
- **Architecture choice:** `PROPOSED: A`, mount a complete breakout/module through a labeled connector rather than place the bare IC. This is safer for a first board because the module handles fine-pitch assembly and may include regulation/decoupling, while the custom PCB remains a simple carrier. The exact module must still be verified; GY-521 boards are not interchangeable assumptions.
- **Power:** `PROPOSED`: power a verified 3.3 V-compatible module from the XIAO 3V3 rail. Never rely on a generic breakout's regulator or level shifting without its schematic.
- **Connector/footprint:** `PROPOSED`: labeled 1x4 or 1x6 2.54 mm connector area matching the selected module. Exact pin order and mechanical outline `TBD`.
- **Status:** IC electrical facts verified; selected module and footprint `TBD`.
- **Source:** [TDK/InvenSense MPU-6000/6050 datasheet](https://invensense.tdk.com/wp-content/uploads/2015/02/MPU-6000-Datasheet1.pdf), [Adafruit MPU6050 pinout reference](https://learn.adafruit.com/mpu6050-6-dof-accelerometer-and-gyro/pinouts)

## DHT11

- **Purpose:** Low-rate temperature and humidity readings.
- **Interface:** Single-wire digital data on GPIO3.
- **Supply:** `VERIFIED` for common DHT11 datasheet versions: approximately 3.0-5.5 V; verify the exact sensor/module revision.
- **Implementation choice:** `PROPOSED: B`, use a common 3-pin module only if its schematic confirms VCC, DATA, GND and an onboard pull-up. It is simpler to wire and replace than a bare four-pin sensor.
- **Bare-sensor alternative:** A bare 4-pin device normally leaves pin 3 unconnected and requires a data pull-up. A 5.1 kOhm pull-up is a common datasheet recommendation for short connections; this is a conditional component, not a reason to add it blindly to the module design.
- **Footprint:** `TBD`: use the exact selected module connector or the exact bare-sensor datasheet footprint.
- **Status:** Module approach proposed; exact module, pull-up presence, footprint, and voltage behavior `TBD`.
- **Source:** [DHT11 technical datasheet reference](https://www.mouser.com/datasheet/2/758/DHT11-Technical-Data-Sheet-Translated-Version-1143054.pdf)

## Two momentary buttons

- **Purpose:** User interaction and menu navigation.
- **Interface:** GPIO4 and GPIO5, active-low is proposed.
- **Electrical connection:** `PROPOSED`: one switch terminal to GPIO and the other to GND, using the ESP32 internal pull-up. This avoids two external resistors and keeps the first PCB simple. Firmware must use `INPUT_PULLUP` and debounce the inputs before hardware testing.
- **Mechanical choice:** `PROPOSED`: standard 6 x 6 mm through-hole tactile switches for mechanical strength and beginner-friendly hand assembly.
- **Footprint:** `TBD`: select the exact switch first, then use its matching KiCad THT footprint. A generic `SW_PUSH_6mm`-style footprint is not proof of compatibility.
- **Status:** Electrical strategy proposed; exact switch and footprint `TBD`.
- **Source:** [Digi-Key KiCad 6 mm THT footprint example](https://github.com/Digi-Key/digikey-kicad-library/blob/master/digikey-footprints.pretty/Switch_Tactile_THT_6x6mm_MJTP1230.kicad_mod)

## USB and power

- **Purpose:** USB-C power and programming through the XIAO.
- **Architecture:** `PROPOSED`: USB-C enters the XIAO only; external modules use the XIAO's verified 3V3 and GND pins. Do not add a battery system in revision 1.
- **5V/VBUS:** `VERIFIED`: Seeed documents the 5V pin as USB VBUS. It is not a regulated 5 V rail for arbitrary loads.
- **Passives/protection:** No additional regulator, battery connector, or protection network is proposed at this stage. Add only what the selected module datasheets and schematic review require.
- **Status:** USB-first architecture proposed; current budget, rail decoupling, and exact module compatibility `TBD`.

## Custom PCB

- **Purpose:** Mechanical carrier and interconnect for the XIAO, module connectors, buttons, and optional passives.
- **Architecture:** `PROPOSED`: XIAO near a board edge for USB access and antenna clearance; OLED connector/area at the front; MPU6050 connector away from button mechanics; DHT11 connector at an airflow-exposed edge; buttons on the user-facing edge.
- **Mechanical considerations:** Final board outline, mounting holes, connector orientation, OLED window, XIAO antenna keepout, and module clearances are all `TBD`.
- **Status:** Architecture proposed; no schematic or PCB exists.

