# 4x4 Matrix Keypad Interface with KL25Z Microcontroller
This project demonstrates how to interface a 4x4 matrix keypad with the KL25Z microcontroller.The keypad is scanned using embedded C programming, and the pressed key is identified and displayed on a terminal emulator, such as TeraTerm.

## Key Features
**Key Identification:** Each key press on the 4x4 matrix keypad is detected and identified.

**Alpha-Numeric Display:** The alpha-numeric value of the pressed key is displayed on the terminal emulator, except for the * and # keys.

**Custom Display:**
Pressing the * key displays your name.
Pressing the # key displays your ID number.

4x4 matrix keyboard

![image](https://github.com/user-attachments/assets/76a7804d-8b3b-487a-beb9-2b0d862b1644)


## How to Use
Connect the Hardware: Set up the keypad and microcontroller as described in the hardware requirements.

Interfacing of 4x4 matrix keyboard

![image](https://github.com/user-attachments/assets/0e99467d-352e-45fd-a37e-8e067c11ab2a)

![image](https://github.com/user-attachments/assets/5f97e69c-f8ae-4575-8bb2-14c6f22c9e62)



Upload the Program: Flash the embedded C program to the KL25Z microcontroller.

Open TeraTerm: Launch TeraTerm or your preferred terminal emulator and connect it to the KL25Z.

Test the Keypad:

Press any key on the keypad and observe the corresponding value displayed on the terminal.
Press * to display your name.
Press # to display your ID number.

## Project Files
project.c: The main source code file that implements the keypad scanning algorithm and displays the output.
