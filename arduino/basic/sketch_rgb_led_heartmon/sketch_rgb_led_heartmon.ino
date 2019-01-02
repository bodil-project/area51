//----Begin Code (copy from here)----
//Includes:
//Variables:
int redPin = 6; //Pin that the red LED leg is connected to.
int greenPin = 5; //Pin that the green LED leg is connected to.
int bluePin = 9; //Pin that the blue LED leg is connected to.
byte rVal = 1; //Variable to store the PWM value to run the red LED at.
byte gVal = 0; //Variable to store the PWM value to run the red LED at.
byte bVal = 0; //Variable to store the PWM value to run the red LED at.
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}
  bool redcount = true;
  bool greencount = false;
  bool bluecount = false;

void loop() {
  if (redcount) {
    if (rVal == 255)
    {
      redcount = false;
    } else
    {
      rVal += 1;
    }
  } else
  {
    if (rVal == 1)
    {
      redcount = true;
    } else
    {
      rVal -= 1;
    }
  }
  analogWrite(redPin, rVal);
  analogWrite(greenPin, gVal);
  analogWrite(bluePin, bVal);
  delay(2);
  Serial.println(rVal);
}
