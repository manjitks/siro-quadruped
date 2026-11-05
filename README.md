# Siro Quadruped

Siro is an ESP32 controlled quadruped robot with a browser based controller and printable parts. It is an independent project inspired by the open source [Sesame Robot](https://github.com/dorianborian/sesame-robot) by Dorian Todd. The included `LICENSE` preserves the upstream Apache 2.0 license and attribution.

## Firmware setup

1. Install the ESP32 Arduino board package and select **ESP32 Dev Module**.
2. Install the **Adafruit PWM Servo Driver**, **Adafruit GFX**, and **Adafruit SSD1306** libraries.
3. Open `firmware/siro-controller/siro-controller.ino` in Arduino IDE. Keep the three adjacent headers in the same sketch folder.
4. Connect the PCA9685 I2C bus to ESP32 GPIO 21 (SDA) and GPIO 22 (SCL). The OLED is configured for I2C address `0x3C`.
5. Upload the sketch. On boot, it creates the `Siro-Controller` Wi-Fi access point. Connect to it and open `http://192.168.4.1` to use the web controller. The default password is `12345678`; change `AP_PASS` in the sketch before using the robot on a shared network.

### PCA9685 servo channels

The firmware sends servo outputs to PCA9685 channels 0–7 in this order:

| PCA9685 channel | Joint label |
| ---: | :--- |
| 0 | R1 |
| 1 | R2 |
| 2 | L1 |
| 3 | L2 |
| 4 | R4 |
| 5 | R3 |
| 6 | L3 |
| 7 | L4 |

Use a suitable external supply for the servos and connect its ground to the ESP32/PCA9685 ground. Do not power the servos from the ESP32 USB pin. The controller is tuned for MG90S type servos; check linkage direction and limits before running a gait.

For startup diagnostics, open Serial Monitor at **115200 baud**. The firmware prints the ESP32 reset reason at boot.

## Printable parts

- `hardware/printing/stl/` contains the original versioned STL set.
- `hardware/printing/stl/siro-v11/` contains the updated femur links, lower leg links, and shallow battery cover.
- `hardware/printing/stl/top-covers/` contains the alternate top covers and modular attachments.

The updated V11 links were checked as single solids. Print fit, material strength, and assembled clearances have not been validated; inspect the parts in your slicer and test cautiously before operating the robot.

## Contributing

Bug reports, build notes, firmware improvements, and printable part revisions are welcome. See [CONTRIBUTING.md](CONTRIBUTING.md) for how to submit a useful change. Please include the board/servo setup and firmware version when reporting motion or wiring issues.
