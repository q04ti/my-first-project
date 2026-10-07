# Component research and pre-purchase checklist

This document records what is known from manufacturer/datasheet sources and what must still be verified. It is not a procurement list.

## Controller — XIAO ESP32C3

**Verified from Seeed:** product name, 21 x 17.8 mm size, D0-D10 GPIO mapping, D4/GPIO6 I2C SDA, D5/GPIO7 I2C SCL, 5V/VBUS, regulated 3V3 output, boot/reset controls, and battery pads.

**TBD before layout:**

- Exact current XIAO product/revision and purchase SKU
- 3V3 external-current limit: Seeed's page states both 500 mA and 700 mA in different sections
- Castellated pad dimensions and a verified KiCad footprint
- Antenna keepout and USB edge clearance
- Whether the XIAO will be soldered directly or socketed

## OLED

- [ ] Select a uniquely identified 0.96-inch 128x64 monochrome SSD1306 I2C module
- [ ] Verify supply voltage and 3.3 V logic compatibility
- [ ] Verify connector pin order: GND/VCC/SCL/SDA is common, not universal
- [ ] Verify I2C address (normally 0x3C or 0x3D)
- [ ] Verify reset handling
- [ ] Verify onboard I2C pull-ups
- [ ] Record module dimensions, mounting holes, display window, and connector spacing

## MPU6050

- [x] Verify IC supply range and AD0 address behavior from the IC datasheet
- [ ] Select a specific breakout/module
- [ ] Verify whether it has a regulator, level shifting, pull-ups, and decoupling
- [ ] Verify the module pin order and footprint
- [ ] Decide whether to expose INT as an optional pad
- [ ] Confirm module orientation for motion interpretation

## DHT11

- [ ] Select a specific 3-pin module or 4-pin bare sensor
- [ ] Verify the exact supply range
- [ ] Verify whether the module includes the required data pull-up
- [ ] If bare, add the datasheet-recommended data pull-up and leave the NC pin unconnected
- [ ] Verify mechanical footprint and airflow placement

## Buttons

- [ ] Select an exact 6 x 6 mm through-hole tactile switch
- [ ] Match the footprint to its datasheet, including pin spacing and actuator height
- [ ] Use active-low GPIO inputs with internal pull-ups unless testing shows a need for external resistors
- [ ] Define firmware debounce behavior

## Power and passives

- [ ] Confirm the aggregate 3V3 current budget for the selected OLED and modules
- [ ] Inspect module schematics for onboard decoupling and I2C pull-ups
- [ ] Add external I2C pull-ups only if the selected bus needs them
- [ ] Add a 5.1 kOhm DHT pull-up only if the selected sensor/module does not already provide one
- [ ] Add local 100 nF decoupling only where the selected part/module datasheet requires it
- [ ] Confirm no separate regulator is needed
- [ ] Confirm all module logic is safe at 3.3 V

## PCB and manufacturing

- [ ] Confirm final board dimensions and mounting holes
- [ ] Confirm OLED window and module orientation
- [ ] Confirm USB-C access and XIAO antenna keepout
- [ ] Confirm module connector orientation and serviceability
- [ ] Choose a verified XIAO symbol/footprint source
- [ ] Create schematic only after the above decisions are reviewed

