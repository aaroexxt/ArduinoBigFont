/*

BigFont library by Aaron Becker
Inspired and adapted from many sources on the Arduino forum

Tested with both 16x2 and 20x4 LCD disolays

*/

#include <LiquidCrystal_I2C.h> //I2C liquidCrystal library
#include "bigFontChars.h" //big font chars reference

//LCD setup; modify this depending on your LCD configuration
LiquidCrystal_I2C lcd(0x27, 20, 4); //set the LCD address to 0x27 for a 20x4 display

//Variable to keep track of the last time we've updated the display
unsigned long lastUpdateTime = 0;

void setup() {
  //setup lcd
  lcd.init(); //initialize lcd
  lcd.backlight(); //enable backlight
  lcd.home(); //clear lcd

  //Assign bigFont segments write numbers
  lcd.createChar(8,C_LT);
  lcd.createChar(1,C_UB);
  lcd.createChar(2,C_RT);
  lcd.createChar(3,C_LL);
  lcd.createChar(4,C_LB);
  lcd.createChar(5,C_LR);
  lcd.createChar(6,C_UMB);
  lcd.createChar(7,C_LMB);

  //Do basic message
  lcd.clear();
  lcd.setCursor(0, 0);
  //Write "Big" at X=0 Y=0
  BFwriteString("Big", 0, 0);

  delay(3000);
}

void loop() {
  unsigned long currentTime = millis();
  if (currentTime - lastUpdateTime > 1000) { //Every 1000ms (1s)
    lastUpdateTime = currentTime;

    //Clear display
    lcd.clear();
    lcd.setCursor(0, 0);
    int ct = currentTime%1000;

    //Write seconds since init to display
    BFwriteString(String(ct), 0, 0); //write the number to the display
  }
}

int BFwriteString(String str, int xPos, int yPos) {
  int strLen = str.length()+1; //optimize gang!

  char charBuffer[strLen];
  str.toCharArray(charBuffer, strLen);

  for (int i=0; i<strLen; i++) {
    //Serial.println(charBuffer[i]);
    BFwriteChar(charBuffer[i], xPos, yPos);
    xPos+=4;
  }

  return xPos; //returns new pos
}

int BFwriteChar(char tW, int offsetX, int offsetY) {
  if (tW >= 65 && tW <= 90) {
    tW = tolower(tW);
  }
  boolean halfWidthChar = false;
  switch (tW) { //lower case char, will only affect letters
    case '0':
    case 'o':
      lcd.setCursor(offsetX, offsetY); 
      lcd.write(8);  
      lcd.write(1); 
      lcd.write(2);
      lcd.setCursor(offsetX, offsetY+1); 
      lcd.write(3);  
      lcd.write(4);  
      lcd.write(5);
      break;
    case '1':
      lcd.setCursor(offsetX, offsetY);
      lcd.write(1);
      lcd.write(2);
      lcd.setCursor(offsetX+1, offsetY+1);
      lcd.write(255);
      break;
    case '2':
      lcd.setCursor(offsetX, offsetY);
      lcd.write(6);
      lcd.write(6);
      lcd.write(2);
      lcd.setCursor(offsetX, offsetY+1);
      lcd.write(3);
      lcd.write(7);
      lcd.write(7);
      break;
    case '3':
      lcd.setCursor(offsetX, offsetY);
      lcd.write(6);
      lcd.write(6);
      lcd.write(2);
      lcd.setCursor(offsetX, offsetY+1);
      lcd.write(7);
      lcd.write(7);
      lcd.write(5); 
      break;
    case '4':
      lcd.setCursor(offsetX, offsetY);
      lcd.write(3);
      lcd.write(4);
      lcd.write(2);
      lcd.setCursor(offsetX+2, offsetY+1);
      lcd.write(255);
      break;
    case '5':
      lcd.setCursor(offsetX, offsetY);
      lcd.write(255);
      lcd.write(6);
      lcd.write(6);
      lcd.setCursor(offsetX, offsetY+1);
      lcd.write(7);
      lcd.write(7);
      lcd.write(5);
      break;
    case '6':
      lcd.setCursor(offsetX, offsetY);
      lcd.write(8);
      lcd.write(6);
      lcd.write(6);
      lcd.setCursor(offsetX, offsetY+1);
      lcd.write(3);
      lcd.write(7);
      lcd.write(5);
      break;
    case '7':
      lcd.setCursor(offsetX, offsetY);
      lcd.write(1);
      lcd.write(1);
      lcd.write(2);
      lcd.setCursor(offsetX+1, offsetY+1);
      lcd.write(8);
      break;
    case '8':
      lcd.setCursor(offsetX, offsetY);
      lcd.write(8);
      lcd.write(6);
      lcd.write(2);
      lcd.setCursor(offsetX, offsetY+1);
      lcd.write(3);
      lcd.write(7);
      lcd.write(5);
      break;
    case '9':
      lcd.setCursor(offsetX, offsetY);
      lcd.write(8);
      lcd.write(6);
      lcd.write(2);
      lcd.setCursor(offsetX+2, offsetY+1);
      lcd.write(255);
      break;
    case 'a':
      lcd.setCursor(offsetX, offsetY);
      lcd.write(8);
      lcd.write(6);
      lcd.write(2);
      lcd.setCursor(offsetX, offsetY+1);
      lcd.write(255);
      lcd.write(254);
      lcd.write(255);
      break;
    case 'b':
      lcd.setCursor(offsetX, offsetY);
      lcd.write(255);
      lcd.write(6);
      lcd.write(5);
      lcd.setCursor(offsetX, offsetY+1);
      lcd.write(255);
      lcd.write(7);
      lcd.write(2);
      break;
    case 'c':
      lcd.setCursor(offsetX, offsetY);
      lcd.write(8);
      lcd.write(1);
      lcd.write(1);
      lcd.setCursor(offsetX, offsetY+1);
      lcd.write(3);
      lcd.write(4);
      lcd.write(4);
      break;
    case 'd':
      lcd.setCursor(offsetX, offsetY); 
      lcd.write(255);  
      lcd.write(1); 
      lcd.write(2);
      lcd.setCursor(offsetX, offsetY+1); 
      lcd.write(255);  
      lcd.write(4);  
      lcd.write(5);
      break;
    case 'e':
      lcd.setCursor(offsetX, offsetY);
      lcd.write(255);
      lcd.write(6);
      lcd.write(6);
      lcd.setCursor(offsetX, offsetY+1);
      lcd.write(255);
      lcd.write(7);
      lcd.write(7); 
      break;
    case 'f':
      lcd.setCursor(offsetX, offsetY);
      lcd.write(255);
      lcd.write(6);
      lcd.write(6);
      lcd.setCursor(offsetX, offsetY+1);
      lcd.write(255);
      break;
    case 'g':
      lcd.setCursor(offsetX, offsetY);
      lcd.write(8);
      lcd.write(1);
      lcd.write(1);
      lcd.setCursor(offsetX, offsetY+1);
      lcd.write(3);
      lcd.write(4);
      lcd.write(2);
      break;
    case 'h':
      lcd.setCursor(offsetX, offsetY);
      lcd.write(255);
      lcd.write(4);
      lcd.write(255);
      lcd.setCursor(offsetX, offsetY+1);
      lcd.write(255);
      lcd.write(254);
      lcd.write(255); 
      break;
    case 'i':
      lcd.setCursor(offsetX, offsetY);
      lcd.write(1);
      lcd.write(255);
      lcd.write(1);
      lcd.setCursor(offsetX, offsetY+1);
      lcd.write(4);
      lcd.write(255);
      lcd.write(4);
      break;
    case 'j':
      lcd.setCursor(offsetX+2, offsetY);
      lcd.write(255);
      lcd.setCursor(offsetX, offsetY+1);
      lcd.write(4);
      lcd.write(4);
      lcd.write(5);
      break;
    case 'k':
      lcd.setCursor(offsetX, offsetY);
      lcd.write(255);
      lcd.write(4);
      lcd.write(5);
      lcd.setCursor(offsetX, offsetY+1);
      lcd.write(255);
      lcd.write(254);
      lcd.write(2); 
      break;
    case 'l':
      lcd.setCursor(offsetX, offsetY);
      lcd.write(255);
      lcd.setCursor(offsetX, offsetY+1);
      lcd.write(255);
      lcd.write(4);
      lcd.write(4);
      break;
    case 'm':
      lcd.setCursor(offsetX, offsetY);
      lcd.write(8);
      lcd.write(3);
      lcd.write(5);
      lcd.write(2);
      lcd.setCursor(offsetX, offsetY+1);
      lcd.write(255);
      lcd.write(254);
      lcd.write(254);
      lcd.write(255);
      break;
    case 'n':
      lcd.setCursor(offsetX, offsetY);
      lcd.write(8);
      lcd.write(2);
      lcd.write(254);
      lcd.write(255);
      lcd.setCursor(offsetX, offsetY+1);
      lcd.write(255);
      lcd.write(254);
      lcd.write(3);
      lcd.write(5);
      break;
    case 'p':
      lcd.setCursor(offsetX, offsetY);
      lcd.write(255);
      lcd.write(6);
      lcd.write(2);
      lcd.setCursor(offsetX, offsetY+1);
      lcd.write(255);
      break;
    case 'q':
      lcd.setCursor(offsetX, offsetY);
      lcd.write(8);
      lcd.write(1);
      lcd.write(2);
      lcd.setCursor(offsetX, offsetY+1);
      lcd.write(3);
      lcd.write(4);
      lcd.write(255);
      lcd.write(4);
      break;
    case 'r':
      lcd.setCursor(offsetX, offsetY);
      lcd.write(255);
      lcd.write(6);
      lcd.write(2);
      lcd.setCursor(offsetX, offsetY+1);
      lcd.write(255);
      lcd.write(254);
      lcd.write(2); 
      break;
    case 's':
      lcd.setCursor(offsetX, offsetY);
      lcd.write(8);
      lcd.write(6);
      lcd.write(6);
      lcd.setCursor(offsetX, offsetY+1);
      lcd.write(7);
      lcd.write(7);
      lcd.write(5);
      break;
    case 't':
      lcd.setCursor(offsetX, offsetY);
      lcd.write(1);
      lcd.write(255);
      lcd.write(1);
      lcd.setCursor(offsetX, offsetY+1);
      lcd.write(254);
      lcd.write(255);
      break;
    case 'u':
      lcd.setCursor(offsetX, offsetY); 
      lcd.write(255);  
      lcd.write(254); 
      lcd.write(255);
      lcd.setCursor(offsetX, offsetY+1); 
      lcd.write(3);  
      lcd.write(4);  
      lcd.write(5);
      break;
    case 'v':
      lcd.setCursor(offsetX, offsetY); 
      lcd.write(3);  
      lcd.write(254);
      lcd.write(254); 
      lcd.write(5);
      lcd.setCursor(offsetX+1, offsetY+1); 
      lcd.write(2);  
      lcd.write(8);
      break;
    case 'w':
      lcd.setCursor(offsetX, offsetY);
      lcd.write(255);
      lcd.write(254);
      lcd.write(254);
      lcd.write(255);
      lcd.setCursor(offsetX, offsetY+1);
      lcd.write(3);
      lcd.write(8);
      lcd.write(2);
      lcd.write(5);
      break;
    case 'x':
      lcd.setCursor(offsetX, offsetY);
      lcd.write(3);
      lcd.write(4);
      lcd.write(5);
      lcd.setCursor(offsetX, offsetY+1);
      lcd.write(8);
      lcd.write(254);
      lcd.write(2); 
      break;
    case 'y':
      lcd.setCursor(offsetX, offsetY);
      lcd.write(3);
      lcd.write(4);
      lcd.write(5);
      lcd.setCursor(offsetX+1, offsetY+1);
      lcd.write(255);
      break;
    case 'z':
      lcd.setCursor(offsetX, offsetY);
      lcd.write(1);
      lcd.write(6);
      lcd.write(5);
      lcd.setCursor(offsetX, offsetY+1);
      lcd.write(8);
      lcd.write(7);
      lcd.write(4);
      break;
    case '?': //question mark?
      lcd.setCursor(offsetX, offsetY);
      lcd.write(1);
      lcd.write(6);
      lcd.write(2);
      lcd.setCursor(offsetX, offsetY+1);
      lcd.write(254);
      lcd.write(7);
      break;
    case '!': //Exclamation mark?
      lcd.setCursor(offsetX, offsetY);
      lcd.write(255);
      lcd.setCursor(offsetX, offsetY+1);
      lcd.write(7);
      break;
    //HALF WIDTH CHARACTERS
    case '.':
      halfWidthChar = true;
      lcd.setCursor(offsetX, offsetY+1);
      lcd.write(4); //CLB
      break;
    case ':':
      halfWidthChar = true;
      lcd.setCursor(offsetX, offsetY);
      lcd.write(1); //CUB
      lcd.setCursor(offsetX, offsetY+1);
      lcd.write(4); //CLB
      break;
  }
  return offsetX+((halfWidthChar) ? 2 : 4); //return new xPos
}