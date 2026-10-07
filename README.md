# Starbie

Starbie is a planned tiny, motion-controlled digital pet for a desk. It is inspired by the Hack Club Starbie starter project and is intended to combine a small OLED interface, motion and environmental sensing, physical buttons, custom pixel art, and a custom KiCad PCB.

> **Project status: PLANNING / FOUNDATION ONLY**
>
> The PCB, schematic, firmware behavior, manufacturing files, and hardware have **not** been completed or tested. Hardware-dependent details remain preliminary or TBD until the exact modules are selected and verified.

## Planned features

- A small animated pixel-art pet on a 0.96-inch I2C OLED
- Motion reactions using an MPU6050
- Temperature and humidity display or pet reactions using a DHT11
- Two physical buttons for interaction and menus
- USB-powered operation and USB programming through the XIAO board
- A custom KiCad PCB and custom artwork

## Planned hardware

- Seeed Studio XIAO ESP32-C3
- 0.96-inch I2C OLED module
- MPU6050 motion-sensor module
- DHT11 temperature/humidity sensor or module
- Two momentary push buttons
- USB power and programming through the XIAO
- Custom PCB, with supporting passives/connectors selected during schematic design

See [docs/HARDWARE.md](docs/HARDWARE.md) and [research/COMPONENTS.md](research/COMPONENTS.md) for assumptions and verification work. The pin assignments are centralized in [firmware/Starbie/Starbie.ino](firmware/Starbie/Starbie.ino) and documented as preliminary in [docs/PINOUT.md](docs/PINOUT.md).

## Planned firmware

The firmware will be written for Arduino-compatible ESP32-C3 support. Planned modules include display rendering, button input, motion sensing, environmental readings, pet state, menus, and animations. The current `.ino` file is intentionally a clean skeleton with no claims of physical operation.

## Planned PCB workflow

1. Verify exact modules, electrical requirements, and footprints.
2. Create a KiCad project and draw the schematic.
3. Assign symbols and verified footprints.
4. Run electrical checks and resolve real issues.
5. Create the board outline, place parts, route traces, and add a ground plane.
6. Run KiCad DRC and fix all real errors.
7. Export and inspect Gerbers only after the board is complete.
8. Manufacture and assemble only after design review.

There is currently no KiCad schematic, PCB, Gerber set, or manufactured board in this repository.

## Current status

- Repository foundation: **complete**
- Planning documentation: **complete**
- Firmware skeleton: **created; not hardware-tested**
- KiCad design: **not started**
- BOM: **preliminary; prices and sources are TBD**
- Gerbers/manufacturing: **not created**
- Hardware procurement: **not started**

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

## Eventually building and uploading firmware

When the hardware and exact board variant are verified:

1. Install the Arduino IDE.
2. Add the Espressif ESP32 board package and select the exact XIAO ESP32-C3 board variant.
3. Install the libraries selected during firmware implementation (for example, a display library and sensor libraries). The required versions will be documented before use.
4. Open `firmware/Starbie/Starbie.ino`.
5. Select the correct board and USB port.
6. Connect the XIAO by USB, compile, and upload.
7. Follow the staged hardware test checklist in [docs/PROJECT_PLAN.md](docs/PROJECT_PLAN.md).

The current skeleton has not been compiled against a board package and has not been uploaded to hardware.

## Roadmap

- [x] Create the repository foundation
- [x] Document the preliminary architecture and pinout
- [x] Create a dependency-free firmware skeleton
- [ ] Verify exact component variants and datasheets
- [ ] Create and review the KiCad schematic
- [ ] Assign verified footprints and complete PCB layout
- [ ] Run ERC/DRC and export verified Gerbers
- [ ] Procure parts and assemble a first prototype
- [ ] Implement and test firmware incrementally
- [ ] Add custom sprites, UI, reactions, and PCB artwork
- [ ] Publish final build and test documentation

## Credits and reference

Starbie is compatible in spirit with the [Hack Club Starbie starter guide](https://github.com/hackclub/starbie), which is used as a reference for the concept and beginner-friendly direction. This repository is an independent, clean project foundation and is not a blind copy of that project.

