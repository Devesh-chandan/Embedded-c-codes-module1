# Embedded C - Module 1 (8051 Microcontroller)

A collection of basic 8051 Embedded C programs demonstrating port I/O,
delay generation, LED patterns, counters, and character output.

## Prerequisites

- **Target MCU:** 8051 (or compatible, e.g. AT89C51/52)
- **Compiler/IDE:** Keil uVision (C51 compiler)
- **Header:** `reg51.h`
- Simulated/tested using Keil uVision simulator or Proteus with LEDs
  connected to the respective ports.

## Programs

| # | File | Description |
|---|------|-------------|
| 1 | [`01_alternating_led_pattern.c`](01_alternating_led_pattern.c) | Alternates Port 1 LEDs between `0x55` and `0xAA`. |
| 2 | [`02_led_shift_left.c`](02_led_shift_left.c) | Shifts a single lit LED left across Port 2. |
| 3 | [`03_led_shift_right.c`](03_led_shift_right.c) | Shifts a single lit LED right across Port 2. |
| 4 | [`04_binary_counter_0_to_255.c`](04_binary_counter_0_to_255.c) | Binary up-counter (0–255) displayed on Port 0. |
| 5 | [`05_alphabet_display_a_to_z.c`](05_alphabet_display_a_to_z.c) | Outputs ASCII values for `'a'` to `'z'` on Port 0. |
| 6 | [`06_two_digit_bcd_counter.c`](06_two_digit_bcd_counter.c) | Two-digit BCD counter (00–99) on Port 1. |

## Common Structure

Every program follows the same pattern:

1. Includes `reg51.h` for SFR (Special Function Register) definitions.
2. Uses a helper function `msDelay(unsigned int itime)` for a
   software-generated approximate millisecond delay via nested loops.
3. Writes patterns/values to a port (`P0`, `P1`, or `P2`) in a loop.

## How to Build/Run

1. Open Keil uVision and create a new project targeting an 8051 device
   (e.g. AT89C51).
2. Add the desired `.c` file to the project.
3. Build the project to generate the `.hex` file.
4. Load the `.hex` file into the Keil simulator or a hardware/Proteus
   circuit with LEDs connected to the relevant port(s).

## Notes

- These files were digitized/cleaned up from scanned lecture material;
  variable names, formatting, and comments have been standardized for
  readability, but the program logic is unchanged from the original.

PIC18 C18 Programs - PORTB / RB4 / Switch-Controlled I/O
==========================================================

Files included:
1. 01_PortB_00_to_FF_ForLoop.c
   Sends values 00 to FF to PORTB using a for loop.

2. 02_PortB_Toggle_SoftwareDelay.c
   Toggles PORTB between 0x00 and 0xAA using a software delay for-loop.

3. 03_PortB_Toggle_WhileLoop.c
   Continuously toggles PORTB between 0x55 and 0xAA in an infinite while loop.

4. 04_PortB_Toggle_DelayFunction.c
   Toggles PORTB between 0x55 and 0xAA using a separate calibrated delay() function.

5. 05_RB4_Toggle_DelayFunction.c
   Toggles only bit RB4 continuously using a delay() function.

6. 06_Switch_Controlled_LED_Buzzer_Relay.c
   Reads SW1 (RB4) and SW2 (RB5) to control an LED shift pattern on PORTD,
   plus a buzzer (RC2) and relay (RC1). Includes vector_relocate.h for use
   with a USB HID bootloader.

Notes / corrections made:
- C is case-sensitive. The original snippets used capitalized keywords
  (Void, Unsigned, For, While, PORT B with a space) which will not compile.
  These have been corrected to void, unsigned, for, while, PORTB.
- Header changed to the standard MPLAB C18 header <p18f4550.h>.
- Fixed a syntax error in the delay loop: "for(i=0;i<time,i++)" -> 
  "for(i=0;i<time;i++)" (comma changed to semicolon).
- Program 6 assumes vector_relocate.h is present in your project if you are
  using a USB HID bootloader; remove that #include if you are programming
  the chip directly with an ICSP programmer (e.g., PICkit).

Compiler: Microchip MPLAB C18
Target: PIC18F4550
