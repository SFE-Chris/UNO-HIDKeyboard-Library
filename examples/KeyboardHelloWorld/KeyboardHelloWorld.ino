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

uint8_t buf[8] = {
    0
  };

  uint8_t buf2[8] = {
    0
  };

  uint8_t buf16[16] = {
    0
  };



HIDKeyboard keyboard; // Initialize HIDKeyboard object
HIDKeyboard keyboard1; // Initialize HIDKeyboard object

void setup() {
  keyboard.begin(); // Start communication
  keyboard1.begin(); // Start communication
  Serial.begin(9600);
  delay(2000); // Wait for device to be found as a keyboard
}

void loop() {
  
  // Send first Hello World using the println() function
//  keyboard.println("Hello World!");
  
  // Send second Hello World using unique keypresses
//  keyboard.pressKey('H');
//  keyboard.releaseKey();
//  keyboard.pressKey('e');
//  keyboard.releaseKey();
//  keyboard.pressKey('l');
//  keyboard.releaseKey();
//  keyboard.pressKey('l');
//  keyboard.releaseKey();
//  keyboard.pressKey('o');
//  keyboard.releaseKey();
//  keyboard.pressKey(' ');
//  keyboard.releaseKey();
//  keyboard.pressKey('W');
//  keyboard.releaseKey();
//  keyboard.pressKey('o');
//  keyboard.releaseKey();
//  keyboard.pressKey('r');sssssssssssssssssssss
//  keyboard.releaseKey();cccc
//  keyboard.pressKey('l');
//  keyboard.releaseKey();
//  keyboard.pressKey('d');
//  keyboard.releaseKey();
//  keyboard.pressKey('!');
//  keyboard.releaseKey();
//  keyboard.pressKey(224,'s'); // Notice use of pressSpecialKey for ENTER
//  delay(5000);
//  keyboard.releaseKey();
//  keyboard.pressKey(225,'s'); // Notice use of pressSpecialKey for ENTER
//  delay(5000);
//  keyboard.releaseKey();
//  keyboard.pressKey(17,'s'); // R crtl
//  delay(10000);
//  keyboard.releaseKey();
//  keyboard.pressKey('0');
//  keyboard.releaseKey();
//  delay(5000);
//  keyboard.pressKey(18,'s'); // R crtl + L shift
//  delay(10000);
//  keyboard.releaseKey();
//  keyboard.pressKey('0');
//  keyboard.releaseKey();
//  keyboard.pressKey(19,'s'); // R crtl + L shift 
//  delay(5000);
//  keyboard.releaseKey();
//  keyboard.pressKey('0');
//  keyboard.releaseKey();
//  keyboard.pressKey(20,'s'); // R crtl + L alt
//  delay(10000);
//  keyboard.releaseKey();
//  keyboard.pressKey('1');
//  keyboard.releaseKey();
//  keyboard.pressKey(21,'s'); // R crtl + L alt
//  delay(5000);
//  keyboard.releaseKey();
//  keyboard.pressKey('2');
//  keyboard.releaseKey();
//  keyboard.pressKey(22,'s'); // R crtl + L alt + L shift
//  delay(5000);
//  keyboard.releaseKey();
//  keyboard.pressKey('3');
//  keyboard.releaseKey();
//  keyboard.pressKey(23,'s'); // R crtl + L alt + L shift
//  delay(5000);
//  keyboard.releaseKey();
//  keyboard.pressKey('4');
//  keyboard.releaseKey();
//  keyboard.pressKey(24,'s'); // R crtl + L GUI
//  delay(5000);
//  keyboard.releaseKey();
//  keyboard.pressKey('5');
//  keyboard.releaseKey();
//  keyboard.pressKey(25,'s'); // L crtl + L GUI
//  delay(5000);
//  keyboard.releaseKey();
//  keyboard.pressKey('6');
//  keyboard.releaseKey();
//  keyboard.pressKey(26,'s'); // R crtl + L GUI + L shift
//  delay(5000);
//  keyboard.releaseKey();
//  keyboard.pressKey('7');
//  keyboard.releaseKey();
//  keyboard.pressKey(27,'s'); // R crtl + L GUI + L shift
//  delay(5000);
//  keyboard.releaseKey();
//  keyboard.pressKey('9');
//  keyboard.releaseKey();
//  keyboard.pressKey(29,'s'); // L crtl + L GUI + L shift
//  delay(5000);
//  keyboard.releaseKey();
//  keyboard.pressKey('2');
//  keyboard.releaseKey();
//  keyboard.pressKey(30,'s'); // R crtl + L GUI + L Alt + L shift
//  delay(5000);
//  keyboard.releaseKey();
//  keyboard.pressKey('3');
//  keyboard.releaseKey();
//  keyboard.pressKey(31,'s'); // R crtl + L GUI + L Alt + L shift
//  delay(5000);
//  keyboard.releaseKey();
//  keyboard.pressKey('4');
//  keyboard.releaseKey();
//  keyboard.pressKey(32,'s'); // R shift
//  delay(5000);
//  keyboard.releaseKey();
//  keyboard.pressKey('5');
//  keyboard.releaseKey();
//  keyboard.pressKey(33,'s'); // L crtl + R shift
//  delay(5000);

 

//  buf16[2] = 0x73;
//  buf16[10] = 0x58;
//  Serial.write(buf16,16);
//  
//  buf16[2] = 0;
//  buf16[10] = 0;
//  Serial.write(buf16,16);
//  delay(5000);



    
    buf[3] = 0xe0;//funciona!!
    Serial.write(buf,8);
    buf[2] = 0x73;
    Serial.write(buf,8);
    delay(10000);
    releaser();
    Serial.write(buf,8);

    
    buf[3] = 0xe0;//funciona!!
    buf[4] = 0xe1;//funciona!!
    Serial.write(buf,8);
    buf[2] = 0x73;
    Serial.write(buf,8);
    delay(10000);
    releaser();
    Serial.write(buf,8);


    buf[3] = 0xe0;//funciona!!
    buf[4] = 0xe1;//funciona!!
    buf[5] = 0xe2;//funciona!!
    Serial.write(buf,8);
    buf[2] = 0x73;
    Serial.write(buf,8);
    delay(10000);
    releaser();
    Serial.write(buf,8);

    
    buf[3] = 0xe0;//funciona!!
    buf[4] = 0xe1;//funciona!!
    buf[5] = 0xe2;//funciona!!
    buf[6] = 0xe3;//funciona!!
    buf[2] = 0x73;
    Serial.write(buf,8);
    delay(10000);
    releaser();
    Serial.write(buf,8);

    
    buf[3] = 0xe0;//funciona!!
    buf[4] = 0xe1;//funciona!!
    buf[5] = 0xe2;//funciona!!
    buf[6] = 0xe3;//funciona!!
    buf[7] = 0x27;//funciona!!
    buf[2] = 0x73;
    Serial.write(buf,8);
    delay(10000);
    releaser();
    Serial.write(buf,8);
    
    
//  keyboard.pressKey(63,'s'); // R Alt (Gr)
  
//  keyboard.releaseKey();
//  keyboard.pressKey('6');
//  keyboard.releaseKey();
//  keyboard.pressKey(64,'s'); // L Crtl + R Alt (Gr)
//  delay(5000);
  keyboard.releaseKey();
//  keyboard.pressKey('7');
//  keyboard.releaseKey();
//  keyboard.pressKey(65,'s'); // L Crtl + R Alt (Gr)
//  delay(5000);
//  keyboard.releaseKey();
//  keyboard.pressKey('8');
//  keyboard.releaseKey();
//  keyboard.pressKey(128,'s'); // L Gui (Maybe is the same value as Right GUI???)
//  delay(5000);
//  keyboard.releaseKey();
//  keyboard.pressKey('9');
//  keyboard.releaseKey();
//  keyboard.pressKey(129,'s'); // L Crtl + L Gui (Maybe is the same value as Right GUI???)
//  delay(5000);
//  keyboard.releaseKey();
//  keyboard.pressKey('a');
//  keyboard.releaseKey();
//  keyboard.pressKey(255,'s'); // R Crtl + R alt + L shift + L Gui (Maybe is the same value as Right GUI???)
//  delay(5000);
//  keyboard.releaseKey();
//  keyboard.pressKey('b');
//  keyboard.releaseKey();
//  keyboard.pressKey(256,'s'); //nothing? fn?
//  delay(5000);
//  keyboard.releaseKey();
//  keyboard.pressKey('d');
//  keyboard.releaseKey();
//  keyboard.pressKey(257,'s'); // L crtl
//  delay(5000);
//  keyboard.releaseKey();
//  keyboard.pressKey('e');
//  keyboard.releaseKey();
//  keyboard.pressKey(41,'s'); 
//  delay(5000);
  
//  keyboard.releaseKey();
//  keyboard.pressKey('a');
//  keyboard.releaseKey();
  //    keyboard.pressKey(228,'s'); // Notice use of pressSpecialKey for ENTER
//  delay(5000);
//  keyboard.releaseKey();
//  delay(5000);
//  keyboard.pressKey(229,'s'); // Notice use of pressSpecialKey for ENTER
//  delay(5000);
//  keyboard.releaseKey();
//  delay(5000);
//  keyboard.pressKey(230,'s'); // Notice use of pressSpecialKey for ENTER
//  delay(5000);
//  keyboard.releaseKey();
//  keyboard.pressKey(231,'s'); // Notice use of pressSpecialKey for ENTER
//  delay(5000);
//  keyboard.releaseKey();
//  delay(5000);

//Serial.println((CTRL | SHIFT | ALT | GUI));
  
  // Send third Hello World using print() and key modifiers. 
//  keyboard.pressKey(SHIFT, 'h'); // Holds Shift and presses 'h'
//  keyboard.releaseKey();
//  keyboard.print("ello ");
//  keyboard.pressKey(SHIFT, 'w'); // Holds Shift and presses 'w'
//  keyboard.releaseKey();
//  keyboard.print("orld");
//  keyboard.pressKey(SHIFT, '1'); // Holds Shift and presses '1'
//  keyboard.releaseKey();
  
  
}


void releaser(){
  buf[0]=0;
  buf[1]=0;
  buf[2]=0;
  buf[3]=0;
  buf[4]=0;
  buf[5]=0;
  buf[6]=0;
  buf[7]=0;
}
