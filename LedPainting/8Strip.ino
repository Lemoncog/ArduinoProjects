#include "BitStrip.h"

extern byte FONT[217][8];
//TMP36 Pin Variables
const int ledCount = 10;
int ledPins[] = { 2, 3, 4, 5, 6, 7, 8, 9 };   // an array of pin numbers to which LEDs are attached
const int PINSTRIP[] = { 1, 2, 4, 8, 16, 32, 64, 128 };
int rowIndex = 0;
int characterIndex = 0;
/*
* setup() - this function runs once when you turn your Arduino on
* We initialize the serial connection with the computer
*/
void setup()
{
    Serial.begin(9600); //Start the serial connection with the computer
    //to view the result open the serial monitor
    // loop over the pin array and set them all to output:
    for (int thisLed = 0; thisLed < ledCount; thisLed++) {
        pinMode(ledPins[thisLed], OUTPUT);
    }
}

byte* fontLookUp(char character) {
    int lookupIndex = ((int) character) - 32;
    return FONT[lookupIndex];
}

void loop() // run over and over again
{
    Serial.println("LOOP");
    delay(500); //waiting a second
    //Take 1 which is !
    //char[] fullSentance = "Hello Ellie!!!";
    //char letter = fullSentance[characterIndex];
    byte* bitExclamation = fontLookUp('O');

    // loop over the LED array:
    for (int thisLed = 0; thisLed < ledCount; thisLed++) {
        if(PINSTRIP[thisLed] & bitExclamation[rowIndex]) {
          //Serial.print("on");
          digitalWrite(ledPins[thisLed], HIGH);
        } else {
          //Serial.print("off");
          digitalWrite(ledPins[thisLed], LOW);
        }
    }
    
    rowIndex = rowIndex + 1;

    //Wrap index
    if(rowIndex == 8) {
        rowIndex = 0;
        characterIndex++;
    }
}


