/*********************************************************************************
 * KeyboardHelloWorld.ini
 * Written by Chris Taylor for SparkFun Electronics, 10/15/12
 * 
 * NOTE: This example will not work on a "normal" UNO. It requires that the 
 * arduino-keyboard firmware be installed on the ATMega8U2. Please see
 *   https://github.com/SFE-Chris/UNO-HIDKeyboard-Library
 *
 * Simple sketch to type "Hello World!" three times in three different ways
 *
 ********************************************************************************/
#include <HIDKeyboard.h>

HIDKeyboard keyboard; // Initialize HIDKeyboard object

void setup() {
  keyboard.begin(); // Start communication
  delay(2000); // Wait for device to be found as a keyboard
}

void loop() {
  
  // Send first Hello World using the println() function
  keyboard.println("Hello World!");
  
  // Send second Hello World using unique keypresses
  keyboard.pressKey('H');
  keyboard.releaseKey();
  keyboard.pressKey('e');
  keyboard.releaseKey();
  keyboard.pressKey('l');
  keyboard.releaseKey();
  keyboard.pressKey('l');
  keyboard.releaseKey();
  keyboard.pressKey('o');
  keyboard.releaseKey();
  keyboard.pressKey(' ');
  keyboard.releaseKey();
  keyboard.pressKey('W');
  keyboard.releaseKey();
  keyboard.pressKey('o');
  keyboard.releaseKey();
  keyboard.pressKey('r');
  keyboard.releaseKey();
  keyboard.pressKey('l');
  keyboard.releaseKey();
  keyboard.pressKey('d');
  keyboard.releaseKey();
  keyboard.pressKey('!');
  keyboard.releaseKey();
  keyboard.pressSpecialKey(ENTER); // Notice use of pressSpecialKey for ENTER
  keyboard.releaseKey();
  
  // Send third Hello World using print() and key modifiers. 
  keyboard.pressKey(SHIFT, 'h'); // Holds Shift and presses 'h'
  keyboard.releaseKey();
  keyboard.print("ello ");
  keyboard.pressKey(SHIFT, 'w'); // Holds Shift and presses 'w'
  keyboard.releaseKey();
  keyboard.print("orld");
  keyboard.pressKey(SHIFT, '1'); // Holds Shift and presses '1'
  keyboard.releaseKey();
  
  while(1);
}
