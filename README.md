# UsbLcd

## What it is

UsbLcd is a simple Arduino program that I use to display messages sent over USB on an I²C LCD display.

## Dependencies

UsbLcd requires the Wire library from Arduino and the [LiquidCrystal_I2C library](https://www.arduinolibraries.info/libraries/liquid-crystal-i2-c).

## How to use it

Simply send messages over USB to your Arduino and (if you've got everything connected correctly) it will display your message on the LCD.

The backlight is off until the first message is received, just remove the `lcd.noBacklight()` from `lcdInit()` if you do not want this.

You can also use commands to enable or disable the backlight. Just send either `DISP_BL_OFF` or `DISP_BL_ON` as a message.

UsbLcd returns `MSG_OK` or `CMD_OK` when your message or command was successfully received.