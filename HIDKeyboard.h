
/****************************************************************************
 * HIDKeyboard.h
 *
 * Written by Chris Taylor for SparkFun Electronics, 10/12/12
 *
 * This code is released on the Beerware License. If you use it to make 
 * something cool, and you ever happen to meet me, buy me a beer.
 * 
 * For use with the Arduino-keyboard-0.3 ATMega8U2 firmware from Darran.
 * For full installation instructions, see README.txt.
 * 
 * Defines functions and tables needed to translate keyboard values into HID
 * values and send to the ATMega8U2 on an UNO running the Arduino-keyboard 
 * firmware. 
 *
 * For full function usage instructions, see HIDKeyboard.cpp and README.txt
 *
 ****************************************************************************/

#ifndef HIDKeyboard_h
#define HIDKeyboard_h

#include "Arduino.h"

/****************************************************************************
 * SPECIAL CHARACTER DEFINES
 *
 * These are the HID values for keys that do not output characters
 *
 ****************************************************************************/

// HID Values of Function Keys
#define F1 0x3a
#define F2 0x3b
#define F3 0x3c
#define F4 0x3d
#define F5 0x3e
#define F6 0x3f
#define F7 0x40
#define F8 0x41
#define F9 0x42
#define F10 0x43
#define F11 0x44
#define F12 0x45

// HID Values of Special Keys
#define ENTER 0x28
#define ESCAPE 0x29
#define BACKSPACE 0x2a
#define TAB 0x2b
#define SPACEBAR 0x2c
#define CAPSLOCK 0x39
#define PRINTSCREEN 0x46
#define SCROLLLOCK 0x47
#define PAUSE 0x48
#define INSERT 0x49
#define HOME 0x4a
#define PAGEUP 0x4b
#define DELETE 0x4c
#define END 0x4d
#define PAGEDOWN 0x4e
#define RIGHTARROW 0x4f
#define LEFTARROW 0x50 
#define DOWNARROW 0x51
#define UPARROW 0x52

// HID Values of Keypad Keys
#define NUMLOCK 0x53
#define KEYPADSLASH 0x54
#define KEYPADSTAR 0x55
#define KEYPADMINUS 0x56
#define KEYPADPLUS 0x57
#define KEYPADENTER 0x58
#define KEYPAD1 0x59
#define KEYPAD2 0x5a
#define KEYPAD3 0x5b
#define KEYPAD4 0x5c
#define KEYPAD5 0x5d
#define KEYPAD6 0x5e
#define KEYPAD7 0x5f
#define KEYPAD8 0x60
#define KEYPAD9 0x61
#define KEYPAD0 0x62
#define KEYPADPERIOD 0x63

// HID Values of System Keys
#define KEYBOARDAPPLICATION 0x65
#define KEYBOARDPOWER 0x66
#define VOLUMEMUTE 0x7f
#define VOLUMEUP 0x80
#define VOLUMEDOWN 0x81

// Common-use modifiers
#define CTRL 0x01
#define SHIFT 0x02
#define ALT 0x04
#define GUI 0x08


/****************************************************************************
 *
 * ASCII->HID LOOKUP TABLE
 *	
 *	Taken from the HID Table definition at 
 * 		http://www.usb.org/developers/devclass_docs/Hut1_11.pdf
 * 	
 *  This array maps the ASCII value of a type-able character to its 
 *  corresponding HID value. 
 *
 *	Example:
 *		'a' = ASCII value 97 = HID value 0x04
 * 		HIDTable['a'] = HIDTable[97] = 0x04
 *
 * 	NOTE:
 *		"Shift Modified" HID values are the same as the non Shift-Modified values
 * 		for any given character, e.g. the HID value for '2' is equal to the 
 *		HID value for '@'. The Shift-Modified value is sent by setting the
 *		modifier value (buf[0]) to the corresponding modifier value in the 
 *    modifier table. 
 *
 ****************************************************************************/
const static uint8_t HIDTable[] =  {
	0x00, // 0
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2A, 0x00, 0x00, // 10
	0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 20
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x29, 0x00, 0x00, 0x00, // 30
	0x00, 0x2c, 0x1e, 0x34, 0x20, 0x21, 0x22, 0x24, 0x34, 0x26, // 40
	0x27, 0x25, 0x2e, 0x36, 0x2d, 0x37, 0x38, 0x27, 0x1e, 0x1f, // 50
	0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x33, 0x33, 0x36, // 60
	0x2e, 0x37, 0x38, 0x1f, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, // 70
	0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, // 80
	0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, // 90
	0x2f, 0x31, 0x30, 0x23, 0x2d, 0x35, 0x04, 0x05, 0x06, 0x07, // 100
	0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, // 110
	0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, // 120
	0x1c, 0x1d, 0x2f, 0x31, 0x30, 0x35, 127 // 127
};


/****************************************************************************
 * 
 * ASCII->MODIFIER LOOKUP TABLE
 * 
 * 	Looks up whether or not the HID report should use the SHIFT modifier. 
 * 
 * 	Example:
 *		The character '2' and the character '@' have different ASCII values but
 * 		the same HID value. This table uses the ASCII value to determine if 
 *		we should hold shift while sending the key. e.g.:
 *
 *			HIDTable['2'] = 0x1f  and  modifierTable['2'] = 0 
 *			HIDTable['@'] = 0x1f  and  modifierTable['@'] = SHIFT
 *
 *  There's probaly a better way to do this, but it's functional.
 *
 ****************************************************************************/
const static uint8_t modifierTable[] = {
	0x00, // 0
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 					// 10
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 					// 20
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 					// 30
  0x00, 0x00, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, 0x00, SHIFT, 	// 40
  SHIFT, 0x00, SHIFT, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 				// 50
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, SHIFT, 0x00, SHIFT, 				// 60
  0x00, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, 	// 70
  SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, // 80
  SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, // 90
  0x00, 0x00, 0x00, SHIFT, SHIFT, 0x00, 0x00, 0x00, 0x00, 0x00, 				// 100
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 					// 110
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 					// 120
  0x00, 0x00, SHIFT, SHIFT, SHIFT, SHIFT, 0x00 // 127
};


class HIDKeyboard
{
	public:
		// Constructor
		HIDKeyboard();
		// Public functions
		void begin(); // Starts the required serial communication (9600 baud)
		void pressKey(uint8_t modifier, uint8_t key); // Looks up key in HIDTable and sends with a modifier
		void pressKey(uint8_t key); // Sends key report without modifier (modifier = 0)
		void pressSpecialKey(uint8_t modifier, uint8_t specialKey); // Sends specialKey with a modifier
		void pressSpecialKey(uint8_t specialKey); // Sends specialKey without modifier
		void releaseKey(); // Releases keys (clears key and modifier)
		void print(char* sequence); // Prints string <sequence>
		void println(char* sequence); // Prints string <sequence> followed by a carriage return
	private:
		// HID report buffer
		uint8_t buf[8]; // In report, buf[0] = modifier and buf[2] = key HID value
};

#endif
