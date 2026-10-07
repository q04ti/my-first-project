# Component research checklist

This is a verification checklist, not a list of assumed final parts. Complete it with datasheet links, exact part numbers, and KiCad footprint references before procurement or schematic finalization.

## Verify before buying

- [ ] Exact XIAO ESP32-C3 variant
- [ ] Exact OLED module
- [ ] OLED voltage
- [ ] OLED connector/pin arrangement
- [ ] MPU6050 module pinout
- [ ] DHT11 module versus bare sensor
- [ ] Button footprint
- [ ] USB/programming access
- [ ] PCB dimensions
- [ ] Mounting holes
- [ ] Required passives
- [ ] Voltage regulation requirements
- [ ] Decoupling capacitors
- [ ] Pull-up resistors if required
- [ ] Any other components discovered during schematic design

## Questions to answer

### Controller

- Which exact XIAO ESP32-C3 board revision will be used?
- Which pins are exposed and how do board labels map to ESP32 GPIO numbers?
- Will the XIAO be socketed, soldered directly, or mounted another way?
- What antenna keepout and USB access does the board require?

### Modules

- What controller and I2C address does the OLED use?
- Does each module have onboard regulation or level shifting?
- Are I2C pull-ups already fitted, and are their values suitable for the shared bus?
- Does the MPU6050 module expose or require an interrupt?
- Is the DHT11 a three-pin module or a bare sensor requiring a pull-up?

### PCB and power

- What final board dimensions and mounting-hole pattern are needed?
- Which connectors make assembly and testing safer?
- Is regulation required, or can the verified XIAO rail power the selected modules?
- What local decoupling is required by each selected part?
- Which test points should be included?

No prices, sources, or exact part numbers are asserted until these questions are answered.

