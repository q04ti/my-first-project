# Planned hardware

This document describes the intended architecture, not a verified electrical design. Exact module variants and datasheets must be checked before the schematic is finalized.

## Seeed Studio XIAO ESP32-C3

- **Purpose:** Main microcontroller, USB programming interface, and application logic.
- **Interface:** Arduino-compatible ESP32-C3; I2C and digital GPIO are planned.
- **Expected voltage:** TBD for the selected board revision and exposed pins. Verify the official XIAO ESP32-C3 documentation before connecting modules.
- **Important design considerations:** Confirm the exact board variant, pin mapping, boot/programming behavior, USB connector, power pins, and antenna keepout.
- **Status:** Planned; exact procurement variant TBD.

## 0.96-inch I2C OLED

- **Purpose:** Display the pet, menus, sensor values, and animations.
- **Interface:** I2C, planned on SDA GPIO6 and SCL GPIO7.
- **Expected voltage:** TBD. Verify the controller, module supply range, logic levels, address, and whether the board includes regulation or level shifting.
- **Important design considerations:** Verify connector order, display orientation, I2C address, library compatibility, current draw, and footprint.
- **Status:** Planned; exact module TBD.

## MPU6050

- **Purpose:** Detect motion and orientation changes for pet reactions.
- **Interface:** I2C, sharing the planned OLED bus.
- **Expected voltage:** TBD for the selected breakout/module. Verify whether it accepts the intended supply and logic levels.
- **Important design considerations:** Verify module pinout, I2C address configuration, pull-ups, interrupt pin needs, mounting orientation, and library compatibility.
- **Status:** Planned; exact module TBD.

## DHT11

- **Purpose:** Provide temperature and humidity readings.
- **Interface:** Single-wire digital data signal on planned GPIO3.
- **Expected voltage:** TBD for a module versus a bare sensor. Verify data timing, pull-up requirements, and module pinout.
- **Important design considerations:** DHT11 readings are slow and low precision. Decide whether to use a module or bare sensor and verify its footprint and recommended support circuit.
- **Status:** Planned; module/sensor choice TBD. Firmware can be disabled with `USE_DHT11`.

## Two momentary push buttons

- **Purpose:** User input for menus and pet interaction.
- **Interface:** Digital inputs on planned GPIO4 and GPIO5.
- **Expected voltage:** TBD based on the chosen input configuration and board logic levels.
- **Important design considerations:** Choose pull-up or pull-down behavior after schematic review, define debounce behavior, and verify the mechanical footprint and mounting direction.
- **Status:** Planned; exact buttons and footprints TBD.

## USB and power

- **Purpose:** Power the device and provide programming/debug access through the XIAO.
- **Interface:** USB connector on the XIAO board; internal modules use the board's available power rails.
- **Expected voltage:** USB input and board rail details are TBD pending the exact XIAO documentation.
- **Important design considerations:** Do not connect USB power rails blindly. Verify current budget, protection, grounding, cable access, and whether the custom PCB hosts the XIAO or only connects to it.
- **Status:** Planned; electrical implementation TBD.

## Custom PCB

- **Purpose:** Mechanically and electrically connect the selected modules and provide the final device shape.
- **Interface:** KiCad schematic and PCB layout.
- **Expected voltage:** TBD after the power tree and module requirements are verified.
- **Important design considerations:** Define board dimensions, mounting holes, edge access, antenna keepout, clearances, assembly method, test points, and enclosure constraints.
- **Status:** Not started; no PCB exists yet.

## Optional connectors and support components

- **Purpose:** May provide module connections, test access, mounting, decoupling, pull-ups, or protection.
- **Interface:** TBD during schematic design.
- **Expected voltage:** TBD.
- **Important design considerations:** Add only after a selected part or verified design requirement calls for it. Do not treat common passives or connectors as final without a schematic and datasheet review.
- **Status:** To be determined during Phase 0 and Phase 1.

