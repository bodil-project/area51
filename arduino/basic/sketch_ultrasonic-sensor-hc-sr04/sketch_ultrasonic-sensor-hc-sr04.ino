/*********************************
 * 
 * HC-SR04
 * 
 * 
 * VCC 5V 
 * Trig
 * Echo
 * Gnd
 * 
 *********************************/

class Runnable {
  static Runnable *headRunnable;
  Runnable *nextRunnable;

public:
  Runnable() {
    nextRunnable = headRunnable;
    headRunnable = this;
  }

  virtual void setupRunnable() = 0;
  virtual void loopRunnable() = 0;

  static void setupAll() {
    for (Runnable *r = headRunnable; r; r = r->nextRunnable)
      r->setupRunnable();
  }

  static void loopAll() {
    for (Runnable *r = headRunnable; r; r = r->nextRunnable)
      r->loopRunnable();
  }
};

Runnable *Runnable::headRunnable = NULL;

enum DistanceMeasurement {
  DM_CM = 0,
  DM_MM = 1
};


class DistanceSensor: public Runnable {
  byte triggerPin;
  byte echoPin;
  float v;
  DistanceMeasurement distanceMeasurement;
public:
  int distance;
  DistanceSensor(byte triggerPin, byte echoPin, DistanceMeasurement distanceMeasurement = DM_CM) {
    this->triggerPin = triggerPin;
    this->echoPin = echoPin;
    this->distanceMeasurement = distanceMeasurement;
    switch(this->distanceMeasurement) {
      case DM_CM: v = 0.034; break;
      case DM_MM: v = 0.34;  break;
    }
  }
  void setupRunnable() {
    pinMode(this->triggerPin, OUTPUT);
    pinMode(this->echoPin, INPUT);
  }

  void loopRunnable() {
    // Clear the trigPin
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
  
    // Sets the trigPin on HIGH state for 10 microseconds to trig the measurement
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
  
    // Reads the echopin, returns the sound wave travel time in microseconds
    int duration = pulseIn(echoPin, HIGH);
  
    // Calculating the distance
    // Time = distance / speed
    // Distance = Time * speed
    // Distance = Trigger + Echo hence vu/2
    distance = duration * v / 2;  // mm
    
  
    // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.print(distance);
    switch(distanceMeasurement) {
      case DM_CM: Serial.println(" cm"); break;
      case DM_MM: Serial.println(" mm"); break;
    }
    
  }
};


DistanceSensor hc_sr04(
  9,  // Trigger pin
  10  // Echo pin
);

void setup() {
  Runnable::setupAll();
  Serial.begin(9600);
}

void loop() {
  Runnable::loopAll();
}
