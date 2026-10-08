# Starbie

Starbie is a tiny, motion-controlled digital pet for a desk, inspired by the Hack Club Starbie starter project. The project combines a small OLED interface, motion and environmental sensing, physical buttons, custom pixel art, and a custom KiCad PCB.

![Starbie PCB](assets/pcb-art/starbie-pcb.png)

## Current status

- The Starbie schematic is completed.
- The PCB layout is completed and the board has been routed.
- Gerber and drill fabrication files have been generated in [hardware/manufacturing/gerbers/](hardware/manufacturing/gerbers/).
- Firmware is present at [firmware/Starbie/Starbie.ino](firmware/Starbie/Starbie.ino).
- The project is awaiting hardware assembly and testing.

## Hardware

- Seeed Studio XIAO ESP32-C3
- 0.96-inch I2C OLED module
- MPU6050 motion-sensor module
- DHT11 temperature/humidity sensor or module
- Two momentary push buttons
- Custom Starbie PCB

See [docs/HARDWARE.md](docs/HARDWARE.md), [research/COMPONENTS.md](research/COMPONENTS.md), and [hardware/BOM/BOM.csv](hardware/BOM/BOM.csv) for the current hardware information. Pin assignments are documented in [docs/PINOUT.md](docs/PINOUT.md).

## Firmware

The firmware is in [firmware/Starbie/Starbie.ino](firmware/Starbie/Starbie.ino). It is currently awaiting hardware assembly and testing.

## PCB and fabrication files

The KiCad project files are in [hardware/kicad/](hardware/kicad/):

- [Starbie.kicad_pro](hardware/kicad/Starbie.kicad_pro)
- [Starbie.kicad_sch](hardware/kicad/Starbie.kicad_sch)
- [Starbie.kicad_pcb](hardware/kicad/Starbie.kicad_pcb)

The generated Gerber, Gerber job, and drill files are in [hardware/manufacturing/gerbers/](hardware/manufacturing/gerbers/).

## Repository structure

```text
.
├── README.md
├── LICENSE
├── COMPONENTS.md
├── docs/
├── hardware/
│   ├── kicad/
│   ├── manufacturing/
│   └── BOM/
├── firmware/Starbie/
├── assets/
└── research/
```

## Roadmap

- [x] Create the repository foundation
- [x] Document the hardware architecture and pinout
- [x] Create the firmware file
- [x] Complete the KiCad schematic
- [x] Complete and route the PCB layout
- [x] Generate Gerber and drill fabrication files
- [ ] Assemble the hardware
- [ ] Test the assembled hardware
- [ ] Implement and test firmware incrementally
- [ ] Add custom sprites, UI, reactions, and PCB artwork

## Credits and reference

Starbie is compatible in spirit with the [Hack Club Starbie starter guide](https://github.com/hackclub/starbie), which is used as a reference for the concept and beginner-friendly direction. This repository is an independent project.
