# Starbie v1 mechanical concept

This is a placement concept only. It does not define a final PCB outline or fabricate any footprint.

## Proposed PCB dimensions

**TBD.** The final outline depends on the selected enclosure, the actual Adafruit OLED revision and display window, the XIAO USB edge, and whether the sensor boards are mounted as removable modules or as board-edge connectors.

Do not begin board-edge routing or manufacturing based on a guessed dimension.

## Placement concept

- **OLED:** Place the current Adafruit 326 STEMMA-QT board at the user-facing front/top. Its official Eagle board file defines a 29.21 x 31.75 mm outline and a six-signal header area; use a standard 1x6, 2.54 mm connector and do not assume the older eight-pin revision.
- **XIAO:** Place near a board edge with USB-C access. The official XIAO-ESP32-C3-DIP OPL footprint is reserved as the PCB-layout candidate, but its revision-specific antenna/USB geometry remains deferred. During initial layout, keep the antenna-side board area as a copper-free, trace-free mechanical exclusion zone and place the USB opening on the opposite edge of the carrier concept; copy exact clearances from the purchased board before releasing PCB files.
- **Buttons:** Place two Omron B3F-1000 6 x 6 mm THT switches along the front or side user-facing edge. Confirm the purchased actuator-height suffix before enclosure design.
- **MPU6050:** Use the Adafruit product 3886 only as an external module on a standard 1x8, 2.54 mm connector. Its official board file is 25.40 x 17.78 mm; Starbie does not need a dedicated module outline or mounting-hole footprint for v1.
- **DHT11:** Keep the DFRobot DFR0067 as an external, cable-connected sensor. The Starbie PCB carries only a standard 3-pin connector; the sensor module itself is not mounted on the PCB. Keep the remote sensor at an airflow-exposed location and away from heat sources.

## Connector strategy

These are proposed first-prototype interfaces, not fabricated footprints:

| Component | Connector type | Pin count | Pitch | Orientation | Mounting method |
|---|---|---:|---:|---|---|
| Adafruit 326 OLED | Standard through-hole pin header/socket matching current STEMMA-QT board | 6 | 2.54 mm | Vertical; pin labels on the carrier must read GND, Vin, 3V, Data, Clk, RST | Removable header/socket |
| Adafruit 3886 MPU6050 | Standard through-hole header/socket; module is external | 8 | 2.54 mm | Vertical; label signals from the Adafruit board, do not infer by position | Removable header/socket |
| DFRobot DFR0067 | DFRobot Gravity PH2.0 3-pin cable interface | 3 | 2.00 mm | Polarized/keyed PH2.0 mating direction; pin-1 and VCC/GND/SIG order unresolved | Through-hole 1x3 header or matching keyed receptacle only after pin mapping is proven; no module footprint |
| Omron B3F-1000 | No separate connector; switch terminals are the PCB interface | 4 THT terminals | Manufacturer drawing | Top-side actuator | Direct through-hole soldering |

The DFR0067 module outline is intentionally not used. The OLED and MPU6050 carrier interfaces can use standard connectors; final revision matching remains required for the OLED purchase and XIAO integration.

## USB-C access

The XIAO USB-C connector must remain reachable from the enclosure exterior. The exact edge setback and opening are TBD until the XIAO mechanical drawing and enclosure concept are selected.

## Antenna keepout

Use the keepout shown in the selected XIAO mechanical/CAD source. Do not place copper pours, traces, mounting hardware, or conductive enclosure material in that region. The exact keepout geometry must be copied from the verified source during PCB layout; it is not reproduced here from memory.

This uncertainty does not block schematic capture because it affects placement and copper geometry only. It remains a PCB-layout blocker.

## Mounting holes

The Starbie carrier mounting-hole pattern is **TBD**. It depends on the enclosure and whether the Adafruit MPU6050 breakout holes are used as part of the mechanical stack.

Known module information:

- Adafruit 3886: four 2.5 mm mounting holes are documented.
- DFRobot DFR0067: no module mounting holes are needed on the Starbie PCB because the sensor is external and cable-connected.
- Adafruit product 326: official current STEMMA-QT Eagle board file defines the 29.21 x 31.75 mm board outline; do not mix it with the older product-326 board files.

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
- [Seeed XIAO ESP32-C3 product/mechanical PDF](https://files.seeedstudio.com/products/113991054/files/hardware/Seeed-Studio-XIAO-ESP32-C3-v1.0-SCH%26PCB.pdf)
- [Seeed OPL KiCad library](https://github.com/Seeed-Studio/OPL_Kicad_Library/tree/master/Seeed%20Studio%20XIAO%20Series%20Library)
- [Adafruit product 326 CAD and fabrication files](https://learn.adafruit.com/monochrome-oled-breakouts/downloads)
- [Adafruit product 3886 CAD and fabrication files](https://learn.adafruit.com/mpu6050-6-dof-accelerometer-and-gyro/downloads)
- [DFRobot DFR0067 product documentation](https://www.dfrobot.com/product-174.html)
- [APEM MJTP/PHAP33 series](https://www.apem.com/idec-apem/en_UK/medias/MJTPSERIES17NOV2021.pdf)
- [DFRobot PH2.0 cable](https://www.dfrobot.com/product-2554.html)
