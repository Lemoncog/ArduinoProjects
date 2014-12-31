/*
  Button
 
 Turns on and off a light emitting diode(LED) connected to digital  
 pin 13, when pressing a pushbutton attached to pin 2.
 
 
 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground
 
 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.
 
 
 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Button
 */
#include "pitches.h"
// constants won't change. They're used here to
// set pin numbers:
const int buttonPinA = 2;     // the number of the pushbutton pin
const int buttonPinB = 3;
const int buttonPinC = 4;
const int buttonPinD = 5;
const int buttonPinE = 6;
// variables will change: 
int buttonState = 0;         // variable for reading the pushbutton status
int light = 0;

const int arraySize = 4;
int buttonPins[] = { buttonPinA, buttonPinB, buttonPinC, buttonPinD, buttonPinE };
int notes[] = { NOTE_A1, NOTE_B2, NOTE_D4, NOTE_E5 };

void setup() {
  Serial.begin(9600);
  
  // initialize the pushbutton pin as an input:
  for(int i = 0; i < arraySize; i++) {
    pinMode(buttonPins[i], INPUT);    
  }
}

void loop(){
  //Average now is  50
  
  //Read in distance sensor
  light = analogRead(0);
  
  int offsetTone = (((light-50)/100.0) * 4000);
  Serial.println(String(light) + ":" + String(offsetTone));
  
  // read the state of the pushbutton value: nb
  for(int i = 0; i < arraySize; i++) {
    buttonState = digitalRead(buttonPins[i]);
    
    String readState = "HIGH";
    if(buttonState == HIGH) {            
      tone(9, notes[i]+offsetTone);
    } else {
      readState = "LOW";
      noTone(9);
    }
    
    String toPrint = "---Button " + String(i) + ":" + readState;
    //Serial.print(toPrint);
  }

  //Serial.println();
  //delay(5000);
}
