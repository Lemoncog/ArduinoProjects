void setup()  { 
  
  Serial.begin(9600);
  
  // declare pin 9 to be an output:
  pinMode(9, OUTPUT);
  beep(50);
  beep(50);
  beep(50);
  delay(1000);
} 

void loop()  { 
  //beep(100); 
  
  toneIt();
  
  read(A0);
}

void toneIt(unsigned char delayms) {
  tone(9, 10);
  delay(delayms);
  noTone(9);
}

void beep(unsigned char delayms){
  analogWrite(9, 10);      // Almost any value can be used except 0 and 255
                           // experiment to get the best tone
  delay(delayms);          // wait for a delayms ms
  analogWrite(9, 0);       // 0 turns it off
  delay(delayms);          // wait for a delayms ms   
}  

void read(unsigned int inPin)
{
  int sensorValue = analogRead(A0);   // read the input pin
  float voltage= sensorValue * (5.0 / 1023.0);
  String printThis = "Pin Value = " + String(sensorValue);
  
  Serial.println(printThis);
}
