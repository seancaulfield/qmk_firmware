# infinity875

![infinity875](https://i.imgur.com/qt4YBwSh.jpeg)

The Infinity 87.5 is in the popular A87 form factor with Top-sided USB Type-C and supports BOTH the F12 and F13 footprints, so it’s compatible with a number of TKL boards like Geonworks Frog/F1-8x; KFE-CE; Singa Jaguar, among others.

* Keyboard Maintainer: [Mechlovin' Studio](https://github.com/mechlovin)
* Hardware Supported: Infinity87.5, Atmega32u4
* Hardware Availability: [GB](https://geekhack.org/index.php?topic=115251.0), [CBB Planet](https://cbbplanet.com/products/infinity-87-5-pcb), [Mechlovin' Studio](https://mechlovin.studio)

Make example for this keyboard (after setting up your build environment):

    make mechlovin/infinity875/rev1:default

Flashing example for this keyboard:

    make mechlovin/infinity875/rev1:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 4 ways:

* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available.
* **Bootloader reset**: hold ESC (0,0) key while plugging in (jump to bootloader)
* **Bootmagic reset**: hold Insert (1,13) key while pluging in (jump to bootloader and reset EEPROM)
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
