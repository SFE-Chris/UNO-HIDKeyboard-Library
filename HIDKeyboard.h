
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
 * https://www.usb.org/sites/default/files/documents/hut1_12v2.pdf (12 should work, but was originally made for 11v1.)
 * 0x04 to 0x27 are numbers and letters that does output characters but are hard to input as a search.
 * Those keys are NOT MODIFIERS and should go on buf[2]
 *
 ****************************************************************************/

// HID Values of Function Keys - NOT MODIFIES KEYS! - 174  HIDs

#define ERROR_ROLLOVER 0x01 
#define POST_FAIL 0x02
#define ERROR_UNDEFINED 0x03

#define ENTER 0x28
#define ESCAPE 0x29
#define BACKSPACE 0x2a
#define TAB 0x2b
#define SPACEBAR 0x2c
#define MINUS_UNDERSCORE 0x2d
#define IGUAL_PLUS 0x2e
#define BRACKETS_RIGHT 0x2f
#define BRACKETS_LEFT 0x30
#define BACK_LASH 0x31
#define NONUS_HASHTAG 0x32
#define SEMI_COLON 0x33
#define SINGLE_QUOTE 0x34
#define TILDE_GRAVEACCENT 0x35
#define COMMA 0x36
#define DOT 0x37
#define FORWARD_SLASH 0x38


// back to non output

#define CAPSLOCK 0x39
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
#define KEYPAD_DELETE 0x63
#define NONUS_BACK_SLASH 0x64
#define KEYBOARDAPPLICATION 0x65
#define KEYBOARDPOWER 0x66
#define EQUAL 0x67
#define F13 0x68
#define F14 0x69
#define F15 0x6a
#define F16 0x6b
#define F17 0x6c
#define F18 0x6d
#define F19 0x6e
#define F20 0x6f
#define F21 0x70
#define F22 0x71
#define F23 0x72
#define F24 0x73
#define EXECUTE 0x74
#define HELP 0x75
#define MENU 0x76
#define SELECT 0x77
#define STOP 0x78
#define AGAIN 0x79
#define UNDO 0x7a
#define CUT 0x7b
#define COPY 0x7c
#define PASTE 0x7D
#define FIND 0x7e
#define VOLUMEMUTE 0x7f
#define VOLUMEUP 0x80
#define VOLUMEDOWN 0x81
#define LOCK_CAPS_LOCK 0x82
#define LOCK_NUM_LOCK 0x83
#define LOCK_SCROLL_LOCK 0x84
#define KEYPAD_COMMA 0x85
#define EQUAL_SIGN 0x86

//other alphabets keys (hiragana, katakana...) no function on AT-104 keyboards
#define INTERNATIONAL1 0x87
#define INTERNATIONAL2 0x88
#define INTERNATIONAL3 0x89
#define INTERNATIONAL4 0x8a
#define INTERNATIONAL5 0x8b
#define INTERNATIONAL6 0x8c
#define INTERNATIONAL7 0x8d
#define INTERNATIONAL8 0x8e
#define INTERNATIONAL9 0x8f


#define LANG1 0x90
#define LANG2 0x91
#define LANG3 0x92
#define LANG4 0x93
#define LANG5 0x94
#define LANG6 0x95
#define LANG7 0x96
#define LANG8 0x97
#define LANG9 0x98
#define ALTERNATE_ERASE 0x99
#define SYSREQ_ATTENTION 0x9a
#define CANCEL 0x9b
#define CLEAR 0x9c
#define PRIOR 0x9d
#define RETURN 0x9e
#define SEPARATOR 0x9f
#define OUT 0xa0
#define OPER 0xa1
#define CLEAR_AGAIN 0xa2
#define CRSEL_PROPS 0xa3
#define EXSEL 0xa4
// A5-AF are reserved.
#define KEYPAD_0 0xb0
#define KEYPAD_00 0xb1
#define THOUSANDS_SEPARATOR 0xb2
#define DECIMAL_SEPARATOR 0xb3
#define CURRENCY_UNIT 0xb4
#define CURRENCY_SUBUNIT 0xb5
#define KEYPAD_PARENTESES_RIGHT 0xb6
#define KEYPAD_PARENTESES_LEFT 0xb7
#define KEYPAD_CURLY_BRACKETS_RIGHT 0xb8
#define KEYPAD_CURLY_BRACKETS_LEFT 0xb9
#define KEYPAD_TAB xba
#define KEYPAD_BACKSPACE 0xbb
#define KEYPAD_A 0xbc
#define KEYPAD_B 0xbd
#define KEYPAD_C 0xbe
#define KEYPAD_D 0xbf
#define KEYPAD_E 0xc0
#define KEYPAD_F 0xc1
#define KEYPAD_XOR 0xc2
#define KEYPAD_GRAVE_ACCENT 0xc3
#define KEYPAD_PERCENTAGE 0xc4
#define KEYPAD_LESS_THAN 0xc5
#define KEYPAD_MORE_THAN 0xc6
#define KEYPAD_COMMERCIAL_E 0xc7
#define KEYPAD_DOUBLE_COMMERCIAL_E 0xc8
#define KEYPAD_BAR 0xc9
#define KEYPAD_DOUBLE_BAR 0xca
#define KEYPAD_COLON 0xcb
#define KEYPAD_HASHTAG 0xcc
#define KEYPAD_SPACE 0xcd
#define KEYPAD_AT_SIGN 0xce
#define KEYPAD_EXCLAMATION 0xcf
#define KEYPAD_MEMORY_STORE 0xd0
#define KEYPAD_MEMORY_RECALL 0xd1
#define KEYPAD_MEMORY_CLEAR 0xd2
#define KEYPAD_MEMORY_ADD 0xd3
#define KEYPAD_MEMORY_SUBTRACT 0xd4
#define KEYPAD_MEMORY_MULTIPLY 0xd5
#define KEYPAD_MEMORY_DIVIDE 0xd6
#define KEYPAD_PLUS_MINUS 0xd7
#define KEYPAD_CLEAR 0xd8
#define KEYPAD_CLEAR_ENTRY 0xd9
#define KEYPAD_BINARY 0xda
#define KEYPAD_OCTAL 0xdb
#define KEYPAD_DECIMAL 0xdc
#define KEYPAD_HEXADECIMAL 0xdd
// DE-DF are Reserved
// 224-231 seams to work fine on buf[2] (not intensivily checked), but were remapped from buf[0] as 'modifiers keys'. 



/****************************************************************************
 * Modifiers
 *
 * The sum of the modifiers numbers create a create a conjunct modifier, as in ALT_CRTL = 0x05 = 0x01 + 0x04. 
 * They are treated as Binary numbers (1 - LControl ,2 - LShift ,4 - LAlt,8 - LGui,16 - RControl,32 - RShift,64 - RAlt,128 - RGui).
 * As both Right and Left keys seams to not be registered toghether, we have a total of 9.396 combinations (according to my calculations, that are probably underestimated).
 * Those keys are MODIFIERS and should go on buf[0]
 *
 ****************************************************************************/

#define CTRL 0x01 //Left
#define SHIFT 0x02 //Left
#define ALT 0x04 //Left
#define GUI 0x08 // windows key - Left
#define RIGHT_CRTL 0x10
#define RIGHT_SHIFT 0x20
#define RIGHT_ALT 0x40
#define ALT_GR 0x40
// R_GUI does exist but as per my testing, windows treats it as the same as L_GUI.

//Commum combinations
#define CRTL_SHIFT 0x03 
#define ALT_CTRL 0x05
#define ALT_SHIFT 0x06
#define ALT_CRTL_SHIFT 0x07

//More combinations
#define GUI_CTRL 0x09
#define GUI_SHIFT 0x0a
#define GUI_CRTL_SHIFT 0x0b
#define GUI_ALT 0x0c
#define GUI_ALT_CTRL 0x0d
#define GUI_ALT_SHIFT 0x0e
#define GUI_ALT_CRTL_SHIFT 0x0f




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
  0x00, 0x00, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, SHIFT, 	// 40
  SHIFT, 0x00, SHIFT, SHIFT, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 				// 50
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
