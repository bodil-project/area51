//----Begin Code (copy from here)----
//Includes:
//Variables:
double a = 0.75; //Alpha
double c = 0.0; //Difference
int period = 20; //Delay period
void setup() {
 // put your setup code here, to run once:
Serial.begin(9600);
pinMode(13, OUTPUT);
}
void loop() {
 // put your main code here, to run repeatedly:
static double oldVal = 0;
static double oldC = 0;
int rawVal = analogRead(A0);
double val = a*oldVal+(1-a)*rawVal;
c = val - oldVal;
int temp = (c<0.0&&oldC>0.0);
digitalWrite(13, temp);
if (temp) {
Serial.println("Beat.");
}
else {
 Serial.print(".");
}
oldVal = val;
oldC = c;
delay(period);
}
