# RK71 RGB ISO

![RK71 RGB ISO](https://i.ibb.co/396ntThR/RK71-rgb-iso.jpg)


Royal Kludge RK71 hotswap dual mode, rgb edition.

- MCU: HFD2201KBA (rebrand SN32F248BF)
- PCB: 130-83601-13; REV: 02; 2021/03/29
- Wired only

Based on previous work by [DEREFERENC3D](https://github.com/DEREFERENC3D) and [fpb](https://github.com/fpb)

Keyboard Maintainer: [palm]


Building instructions
-----------------

Make example for this keyboard:

    $ make royal_kludge/rk71_rgb_iso:default


## Bootloader

Enter the bootloader:

- Physical reset: Short-circuit the pins located under the printed circuit board as shown below, with the GND. And plug in the keyboard
- After install QMK: Press `FN + ESC`, the key mapped to `QK_BOOT`.

![Bootloader mode](https://i.ibb.co/yFDVgMH8/RK71-bootloader.jpg) 

