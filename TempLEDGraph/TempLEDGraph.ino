
    //TMP36 Pin Variables
    int sensorPin = 0; //the analog pin the TMP36's Vout (sense) pin is connected to
    const int ledCount = 10;
    int ledPins[] = { 2, 3, 4, 5, 6, 7,8,9,10,11 };   // an array of pin numbers to which LEDs are attached
    //the resolution is 10 mV / degree centigrade with a
    //500 mV offset to allow for negative temperatures
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

    void loop() // run over and over again
    {
        //getting the voltage reading from the temperature sensor
        int reading = analogRead(sensorPin);
        // converting that reading to voltage, for 3.3v arduino use 3.3
        float voltage = reading * 5.0;
        voltage /= 1024.0;
        // print out the voltage
        Serial.print(voltage); Serial.println(" volts");
        // now print out the temperature
        float temperatureC = (voltage - 0.5) * 100 ; //converting from 10 mv per degree wit 500 mV offset
        //to degrees ((voltage - 500mV) times 100)
        Serial.print(temperatureC); Serial.println(" degrees C");
        // now convert to Fahrenheit
        float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
        Serial.print(temperatureF); Serial.println(" degrees F");
        delay(1000); //waiting a second

        // read the potentiometer:
        //int sensorReading = analogRead(analogPin);
        // map the result to a range from 0 to the number of LEDs:
        int ledLevel = map(temperatureC, 11, 31, 0, ledCount);

        // loop over the LED array:
        for (int thisLed = 0; thisLed < ledCount; thisLed++) {
        // if the array element's index is less than ledLevel,
        // turn the pin for this element on:
        if (thisLed < ledLevel) {
            digitalWrite(ledPins[thisLed], HIGH);
        }
        // turn off all pins higher than the ledLevel:
        else {
            digitalWrite(ledPins[thisLed], LOW);
        }
      }
    }


