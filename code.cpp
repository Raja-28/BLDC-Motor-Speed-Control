#include <Servo.h>

Servo myServo;  // create servo object to control a servo

const int joystickPin = A0;  // analog pin for joystick
const int escPin = 9;        // digital pin for ESC

void setup() {
  myServo.attach(escPin);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);      // initialize serial communication
}

void loop() {
  int joystickValue = analogRead(joystickPin);  // read the input on analog pin
  int servoValue = map(joystickValue, 0, 1023, 0, 180);  // map the joystick value to servo angle
  myServo.write(servoValue);  // set the servo position
  Serial.print("Joystick Value: ");
  Serial.print(joystickValue);
  Serial.print(" -> Servo Angle: ");
  Serial.println(servoValue);
  delay(15);  // wait for the servo to reach the position
}
