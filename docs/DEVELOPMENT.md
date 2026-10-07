# Development workflow

## Working principles

- Treat the pinout and component list as preliminary until verified from datasheets.
- Keep hardware-independent firmware changes small and readable.
- Record assumptions and decisions in the relevant documentation.
- Never call a schematic, PCB, or firmware behavior tested until the applicable tool or hardware test has actually been run.

## Suggested order

1. Verify component variants and collect datasheets.
2. Update the BOM and pinout with verified information.
3. Create the KiCad schematic and run ERC.
4. Assign reviewed footprints and create the PCB layout.
5. Run DRC and inspect the manufacturing outputs.
6. Set up Arduino support and add one hardware feature at a time.
7. Test power, USB programming, display, buttons, motion, and environmental sensing separately.

## Firmware development

The initial skeleton intentionally avoids external library includes so the repository can be prepared before library choices are final. When a module is verified, add its library and a small test path, then document the selected library and version here.

## Design records

Use the research notes and project plan to record unresolved questions. Do not silently turn a TBD value into a final electrical assumption.

