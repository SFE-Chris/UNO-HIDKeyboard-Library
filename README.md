# HIDKeyboard

Originally written by Chris Taylor, this project has been depricated on Chris's part for ~10 years, so I fixed it up a bit for my own uses.

The Arduino Installation files were obtained from https://github.com/unkwneuser/aurdino-uno-as-hid, but originated from https://mitchtech.net/arduino-usb-hid-keyboard/.

## LIBRARY INSTALLATION:

1. Download the .ZIP file of this repo
2. Open the Arduino IDE and navigate the menu to:
    `Sketch >> Include Library >> Add .ZIP Library`
3. Choose the `HIDKeyboard.ZIP` file
    
## ARDUINO INSTALLATION
(designed for unix-based systems)

1.  Install `dfu-programmer` with your package manager
2.  Unzip the .ZIP file of this repo
3.  `cd` to the unzipped directory of this repo: 
    `cd ~/Downloads/HIDKeyboard-Library`
5.  Plug in Arduino
6.  Run the flash file:
    `./flash`
    - You will be asked to 'reset the arduino.' This can be done by [shorting the top two pins in the ICSP2 pin cluster](https://user-images.githubusercontent.com/78560204/170391534-72d23c35-3f7f-4784-8d81-31873ce41b71.png).

## LIBRARY DOCS:

The library defines a series of functions that make sending HID codes intuitive. Rather than having to look up and send HID codes for every character, the library takes care of it for you. Here's the jist:

Each HID report is sent as a key plus a modifier. The modifiers are CTRL, ALT, SHIFT, and GUI. By default each key is sent with a modifier of zero. The modifiers can be masked together to send more complex commands. The function pressKey() is overloaded to do this. For example:

```
// To send the keypress 'k', use
		
pressKey('k');
	
// To send the keypress CTRL+ALT+k, use

pressKey((CTRL | ALT), 'k');
```

There are similar functions for "Special Keys" like F1 that do not appear in the ASCII table. The values for these keys are defined in HIDKeyboard.h and are sent using the pressSpecialKey() function. For example:
```
// To send the keypress TAB, use
		
pressSpecialKey(TAB);
	
// To send the keypress CTRL+ALT+TAB, use

pressSpecialKey((CTRL | ALT), TAB);
```

There are also functions for printing ASCII strings, similar to the Serial.print() and println() functions. All of the functions are listed below:
```
begin()  // Initializes the HIDKeyboard object by ending any Serial communication and resetting it to 9600 baud

pressKey(modifier, key)
pressKey(key)

pressSpecialKey(modifier, key)
pressSpecialKey(key)

releaseKey()  // Releases any keys and modifiers that are currently down. NOTE: the pressKey and pressSpecialKey functions DO NOT release the key. releaseKey must be used to release the key. 

print()  // Sends keypresses for a full string. For example print("Hello World!");

println()  // Sends keypresses for a full string, followed by a carriage return (enter). 
```

### SKETCH EXAMPLE:
```
#include <HIDKeyboard.h>
HIDKeyboard Keyboard; 

void setup() {
    Keyboard.begin();  // Initializes keyboard
    delay(2000);  // Delay for 2 seconds
}	

void loop() {
    Keyboard.println("Hello World!");  // Types "Hello World!" followed by a carriage return
    Keyboard.pressSpecialKey(ENTER);  // Sends an "Enter" keypress
    Keyboard.releaseKey();  // Releases "Enter"
    Keyboard.pressKey('a');  // Types 'a'
    Keyboard.releaseKey();  // Releases the 'a' key
    Keyboard.pressKey(SHIFT, 'a');  // Types 'A'
    Keyboard.releaseKey();  // Releases 'a' and SHIFT
    while(1);  // Hold forever
}
```

### OUTPUT:
```
Hello World!

aA
```

For more examples, please see the included examples folder. 

