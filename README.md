# ArduinoBigFont
 Arduino library for printing large double height font on a LCD (I2C compatible)

## Usage: Check BigFontDemo/BigFontDemo.ino

The demo is currently set up for a 20x4 I2C LCD which is the one I used on my ebike project (BikeOSMkII repo). Feel free to change this to whatever you want.

Note: the font is double height, meaning that you can print two lines on a 20x4 display and a single line on a 16x2 display. All characters (except space and a few exceptions) are 4 characters wide, meaning you can print up to 5 characters on a 20x4 display (and 4 on a 16x2).

### How does it work?

The library uses the custom character functionality of the Hitachi HD44780 (or similar) controller, combined with the LiquidCrystal library, to register a number of new reusable parts of the bigger font (similar to sprite atlas in rendering). Then, these are printed to make readable text.
