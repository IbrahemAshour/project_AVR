# AVR Calculator Project with Keypad and LCD👨‍💻（*＾-＾*）

This project implements a basic calculator using an AVR microcontroller, a keypad for input, and an LCD display for output. The calculator supports addition, subtraction, multiplication, and division operations.

## Features

- Arithmetic operations: Addition (+), Subtraction (-), Multiplication (*), Division (/)
- User-friendly keypad input
- Output displayed on an LCD screen

## Hardware Requirements⚡

1. AVR microcontroller (e.g., ATmega16)
2. 4x4  Matrix Keypad
3. LCD Display (16x2 or similar)
4. Crystal oscillator for microcontroller (e.g., 16MHz)
5. wires for connections

## Circuit Diagram

![image](https://github.com/IbrahemAshour/project_AVR/assets/100946510/50a06ec7-f573-431e-ba68-0b532b3c1111)


## Connections

- Connect the keypad to the appropriate pins on the microcontroller.
- Connect the LCD to the microcontroller for data and control.
- Ensure proper power supply connections.

## Usage

1. Connect the AVR microcontroller to the keypad and LCD based on the circuit diagram.
2. Compile and upload the calculator firmware to the microcontroller.
3. Power on the system.
4. Use the keypad to input arithmetic expressions.
5. View the results on the connected LCD display.
## user options for LCD ❗❕
Can use the LCD with two mode (four bit mode and eight bit mode)use for reduse the number of bins used from ATmega32 to LCD
## Building and Flashing

1. Set up the AVR development environment (e.g., AVR-GCC, AVRDUDE).
2. Clone this repository:
## Video Test

(https://drive.google.com/file/d/1N1R4RXEDvSbS2i0MVaaOLb5aQ22BpHZo/view?usp=sharing)
## Input Validation
The calculator includes input validation to handle invalid expressions gracefully. If an invalid expression is entered, the calculator will display an error message on the LCD and prompt for a new input.

## Error Handling
Error handling is implemented for scenarios such as division by zero or overflow. The calculator will display appropriate error messages when such conditions occur.

## Contributing
Feel free to contribute to this project by opening issues or pull requests. Your feedback and improvements are highly appreciated.
   ```bash

