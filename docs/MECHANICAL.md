# Starbie v1 mechanical concept

This is a placement concept only. It does not define a final PCB outline or fabricate any footprint.

## Proposed PCB dimensions

**TBD.** The final outline depends on the selected enclosure, the actual Adafruit OLED revision and display window, the XIAO USB edge, and whether the sensor boards are mounted as removable modules or as board-edge connectors.

Do not begin board-edge routing or manufacturing based on a guessed dimension.

## Placement concept

- **OLED:** Place at the user-facing front/top of the enclosure. Reserve the display window and keep the revision-matched interface accessible from the rear or underside. Confirm the product 326 board outline and header orientation from Adafruit's fabrication print.
- **XIAO:** Place near a board edge with USB-C access. Orient the antenna toward an enclosure edge with the documented keepout respected. Avoid copper and traces in the antenna keepout area.
- **Buttons:** Place two APEM MJTP1230 switches along the front or side user-facing edge. Reserve clearance for the datasheet actuator height and the intended enclosure button openings.
- **MPU6050:** Place the Adafruit 3886 module away from button force and tall enclosure walls. Keep its axes orientation documented so firmware reactions match the physical design. The breakout's four mounting holes can be used if the carrier mechanically supports them.
- **DHT11:** Keep the DFRobot DFR0067 as an external, cable-connected sensor. The Starbie PCB carries only a standard 3-pin connector; the sensor module itself is not mounted on the PCB. Keep the remote sensor at an airflow-exposed location and away from heat sources.

## Connector strategy

These are proposed first-prototype interfaces, not fabricated footprints:

| Component | Connector type | Pin count | Pitch | Orientation | Mounting method |
|---|---|---:|---:|---|---|
| Adafruit 326 OLED | Through-hole pin header/socket interface matching the received breakout revision | 6 on current STEMMA-QT CAD | 2.54 mm | Vertical, final direction to match product 326 CAD | Removable header preferred |
| Adafruit 3886 MPU6050 | Through-hole header/socket interface matching the breakout; optional INT/AD0 signals | 8 | 2.54 mm | Vertical, keyed by silkscreen rather than assumed pin order | Removable header preferred; use module holes if the enclosure supports them |
| DFRobot DFR0067 | Standard 1x3 through-hole header for the external Gravity cable | 3 | 2.00 mm proposed Gravity pitch | Vertical, pin 1 VCC, pin 2 GND, pin 3 SIG; label every pin | Through-hole header, no DFR0067 module footprint |
| APEM MJTP1230 | No separate connector; switch terminals are the PCB interface | THT terminals | Datasheet-specific | Top-side actuator | Direct through-hole soldering |

The OLED and MPU6050 options remain conditional until their product-specific CAD/fabrication prints are inspected. The DFR0067 module outline is intentionally not used; only the connector/cable mating detail remains to be confirmed.

## USB-C access

The XIAO USB-C connector must remain reachable from the enclosure exterior. The exact edge setback and opening are TBD until the XIAO mechanical drawing and enclosure concept are selected.

## Antenna keepout

Use the keepout shown in the selected XIAO mechanical/CAD source. Do not place copper pours, traces, mounting hardware, or conductive enclosure material in that region. The exact keepout geometry must be copied from the verified source during PCB layout; it is not reproduced here from memory.

## Mounting holes

The Starbie carrier mounting-hole pattern is **TBD**. It depends on the enclosure and whether the Adafruit MPU6050 breakout holes are used as part of the mechanical stack.

Known module information:

- Adafruit 3886: four 2.5 mm mounting holes are documented.
- DFRobot DFR0067: no module mounting holes are needed on the Starbie PCB because the sensor is external and cable-connected. Do not use unverified module dimensions or hole spacing.
- Adafruit product 326: use the current fabrication print to determine whether the selected revision has usable mounting holes; do not assume generic OLED-board dimensions.

## Enclosure considerations

- Provide a visible OLED window without covering the active area.
- Provide button openings that match the exact actuator height and switch alignment.
- Provide airflow openings around the DHT11.
- Keep the MPU6050 orientation fixed and documented.
- Preserve USB cable bend clearance.
- Preserve XIAO antenna clearance.
- Allow access for programming and service before committing to a sealed enclosure.

## Mechanical sources

- [Seeed XIAO ESP32C3 documentation](https://wiki.seeedstudio.com/XIAO_ESP32C3_Getting_Started/)
- [Seeed OPL KiCad library](https://github.com/Seeed-Studio/OPL_Kicad_Library/tree/master/Seeed%20Studio%20XIAO%20Series%20Library)
- [Adafruit product 326 CAD and fabrication files](https://learn.adafruit.com/monochrome-oled-breakouts/downloads)
- [Adafruit product 3886 CAD and fabrication files](https://learn.adafruit.com/mpu6050-6-dof-accelerometer-and-gyro/downloads)
- [DFRobot DFR0067 product documentation](https://www.dfrobot.com/product-174.html)
- [APEM MJTP1230 datasheet](https://www.apem.com/medias/sys_master/root/h7c/h00/8808403896350/TT_MJTP_PHAP33_D_US.pdf)
