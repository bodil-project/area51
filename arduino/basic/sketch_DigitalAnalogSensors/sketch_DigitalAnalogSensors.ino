/*
Modify these variables to change parameters.
At the bottom of the code there are functions that are activated based on the sensor readings.
Add your own code inside these functions if you wish to use this code as a starting point.
The code is well-commented, so you should be able to follow easily.
----By Tyson Popynick 2016 - Free to modify or use unrestricted without credit or remuneration. ----
*/
//Variables:
int debug_showDigital = 1; //Show digital result in serial output?
int debug_showAnalog = 1;  //Show analog result in serial output?
int timeDelay = 20;       //Time to wait between readings. 1000 = 1 second.
int thresholdVal = 500;    //Threshold level for triggers

int redPin = 6;
int grnPin = 5;
int bluPin = 9;
int digPin = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(digPin, INPUT); //Set the digital pin to input. Analog pins are automatically input.
  Serial.begin(9600); //Start serial communication with the Arduino
  Serial.println("Arduino Analog/Digital module sketch...\nSerial Started."); //The arduino sends this through the serial monitor to show it is ready.
/*
  pinMode(redPin, OUTPUT);
  pinMode(grnPin, OUTPUT);
  pinMode(bluPin, OUTPUT);

  analogWrite(redPin, 0);
  analogWrite(grnPin, 0);
  analogWrite(bluPin, 0);
*/
}
void loop() {
  //Read the sensor and store the values.
  int digitalVal = digitalRead(digPin); //Read Digital pin and store result
  int analogVal = analogRead(A0); //Read analog pin and store result
  //Debug output
  if (debug_showDigital) { //If the debug_showDigital variable is set to 1 output data to serial.
    Serial.print("Digital Result: ");
    Serial.print(digitalVal);
    if (debug_showAnalog) {
      Serial.print(" ");
    } else {
      Serial.print("\n");
    }
  }
  if (debug_showAnalog) { //If the debug_showAnalog variable is set to 1 output data to serial.
    Serial.print("Analog Result: ");
    Serial.println(analogVal);
  }
  //Trigger any relevant functions
  if (digitalVal == HIGH) { //Digital result = 1
    highTrigger();
  }
  if (digitalVal == LOW) { //Digital result = 0
    lowTrigger();
  }
  if (analogVal >= thresholdVal) { //Value above or equal to threshold
    analogHigh(analogVal);
  }
  if (analogVal < thresholdVal) { //value lower than threshold
    analogLow(analogVal);
  }
  //Delay
  delay(timeDelay); //Wait for specified period, then repeat.
}
//Custom Functions
void highTrigger() { //Code inside this function is run if the sensor is HIGH or "triggered"
  //analogWrite(redPin, 255);
}
void lowTrigger() { //Code here is run if the sensor is LOW or "not triggered" 
  //analogWrite(redPin, 10);
}
void analogHigh(int value) {
//The code in here will be run if the analog result is higher than the threshold you set in the variable section at the top of this code
  //analogWrite(grnPin, 255);
}
void analogLow(int value) {
//The code in here will be run if the analog result is higher than the threshold you set in the variable section at the top of this code
  //analogWrite(grnPin, 10);
} 
