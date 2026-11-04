# Siro Quadruped

ESP32 quadruped firmware and printable parts for Siro, an independent robot inspired by the open-source [Sesame Robot](https://github.com/dorianborian/sesame-robot) by Dorian Todd. The upstream Apache-2.0 license is included.

## Firmware

Open `firmware/siro-controller/siro-controller.ino` in Arduino IDE with its adjacent headers. Target: ESP32 Dev Module. Install Adafruit PWM Servo Driver, Adafruit GFX, and Adafruit SSD1306 libraries. The sketch creates the `Siro-Controller` Wi-Fi network; change the default password before deployment. Serial Monitor at 115200 baud prints the ESP32 reset reason at boot.

## Printable parts

- Original STL library: `hardware/printing/stl/`
- Updated V11 parts: `hardware/printing/stl/siro-v11/` (four femur links, four lower-leg links, and the shallow battery cover)

The updated links were checked as single solids; slicer fit and physical strength were not validated. Review before printing.
