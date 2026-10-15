# Motion Detection Alert System

An Arduino Uno project that detects motion with a PIR sensor. When motion is detected, two red LEDs blink and a 128 × 64 SSD1306 OLED displays **DANGER DETECTED**. When the area is clear, the OLED displays **Status: Secure**.

## Components

- Arduino Uno
- PIR motion sensor
- 128 × 64 SSD1306 I²C OLED display (address `0x3C`)
- 2 red LEDs
- 2 × 220 Ω resistors
- Jumper wires

## Wiring

| Component | Connection |
| --- | --- |
| PIR `VCC` | Arduino `5V` |
| PIR `GND` | Arduino `GND` |
| PIR `OUT` | Arduino digital pin `2` |
| OLED `VCC` | Arduino `5V` |
| OLED `GND` | Arduino `GND` |
| OLED `SDA` | Arduino `A4` (I²C data) |
| OLED `SCL` | Arduino `A5` (I²C clock) |
| LED 1 anode (+) | Arduino pin `8` through a 220 Ω resistor |
| LED 1 cathode (-) | Arduino `GND` |
| LED 2 anode (+) | Arduino pin `9` through a 220 Ω resistor |
| LED 2 cathode (-) | Arduino `GND` |

Use a current-limiting resistor in series with each LED, as shown in the circuit diagram.

## Libraries

Install these Arduino libraries before compiling the sketch:

- Adafruit GFX Library
- Adafruit SSD1306

`Wire` is included with the Arduino AVR board package and does not need to be installed separately.

## Run

1. Open `sketch.ino` in the Arduino IDE or open the project in Wokwi.
2. Select **Arduino Uno** as the board and install the libraries listed above if prompted.
3. Upload the sketch to the board, or start the Wokwi simulation.
4. Trigger the PIR sensor. On startup, the display shows **System Armed...** for two seconds; detected motion turns on the alert display and blinks both LEDs.

The sketch writes diagnostic output to the serial monitor at **9600 baud**. The PIR sensor may need a short stabilization period after power-up before its readings settle.
