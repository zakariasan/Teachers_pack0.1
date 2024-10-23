#include <Servo.h>
Servo myservo;
int motorfwd = 3;
int motorbwd = 5;
int motorfwd2 = 6;
int motorbwd2 = 9;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the analog pin as an output.
  pinMode(motorfwd, OUTPUT);   
  pinMode(motorbwd, OUTPUT);  
  pinMode(motorfwd2, OUTPUT);   
  pinMode(motorbwd2, OUTPUT);  
  myservo.attach(7);
}
// the loop routine runs over and over again forever:
void loop() {
  analogWrite(motorfwd, 75);   // turn the motor on (75 is the voltage level)
  analogWrite(motorfwd2, 75);   // turn the motor on (75 is the voltage level)
  myservo.write(60);
  delay(1000);               // wait for a second
  analogWrite(motorfwd, 0);    // turn the motor off by making the voltage 0
  analogWrite(motorfwd2, 0);    // turn the motor off by making the voltage 0
  myservo.write(90);
  delay(1000);               // wait for a second
  analogWrite(motorbwd, 75);   // turn the motor on (75 is the voltage level)
  myservo.write(120);
  analogWrite(motorbwd2, 75);   // turn the motor on ( is the voltage level)
  delay(1000);               // wait for a second
  analogWrite(motorbwd, 0);    // turn the motor off by making the voltage 0
  analogWrite(motorbwd2, 0);    // turn the motor off by making the voltage 0
  myservo.write(90);
  delay(1000);               // wait for a second
}
