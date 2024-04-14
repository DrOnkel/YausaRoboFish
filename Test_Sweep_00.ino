/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(115200);
  Serial.print("Test_Sweep_00");
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  Serial.println(analogRead(A0));
  for (pos = 0; pos <= 180; pos += analogRead(A0)/64 ) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    if(pos>180)
    pos=180;
    if (pos<0)
    pos=0;
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    Serial.println(pos);
    delay(10);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= analogRead(A0)/64) { // goes from 180 degrees to 0 degrees
     if(pos>180)
    pos=180;
    if (pos<0)
    pos=0;
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    Serial.println(pos);
    delay(10);                       // waits 15 ms for the servo to reach the position
  }
}
