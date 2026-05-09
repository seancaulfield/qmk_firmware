# isoish87

TKL PCB with ISO layout and some opinions. ;P

Specifically, I'm en-US but prefer the ISO enter key, so enjoy using "Terminal ISO" layout, or as I've dubbed it, "ISO(ish)."

The 87 is for the "preferred" layout, though it's not the 87 you're thinking -- bottom row is Tsangan (7u spacebar, so 86 keys), but right shift is split (so +1 for 87).:w

* Keyboard Maintainer: [schizobovine](https://github.com/seancaulfield)
* Hardware Supported: ISO(ish)87 PCB
* Hardware Availability: [ISO(ish)87 PCB KiCad files](https://github.com/seancaulfield/isoish87/)

Make example for this keyboard (after setting up your build environment):

    make isoish87:default

Flashing example for this keyboard:

    make isoish87:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (Escape) and plug in the keyboard
* **Physical reset button**: Hold down BOOT1. Press RESET1. Release BOOT1.
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available

Once in the bootloader, the keyboard PCB should show up as a USB mass storage device.
