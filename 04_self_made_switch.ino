/*
A short Goldberg Machine -excercise which is a part of an introductory course of Arduino and robotics. 
First switch causes a sweeping of a servo which then pours water to a cup and closes the second switch. That then plays a tune with piezo!

The course is organised by Mehackit (www.mehackit.org).
*/

#include <Servo.h>
Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position

// note frequencies and durations specified as lists. Together they make a "victory-melody"
int melody[] = {262, 196,196, 220, 196,0, 247, 262};
int noteDurations[] = {4, 8, 8, 4,4,4,4,4 };

void setup() {
  myservo.attach(9);        // attaches the servo on pin 9 to the servo object
  pinMode(2, INPUT_PULLUP); // pin of the first switch
  pinMode(3, OUTPUT;        // pin of the piezo
  pinMode(4, INPUT_PULLUP); // pin of the second switch
}

void loop() {
  if(digitalRead(2) == LOW){
    for (pos = 0; pos <= 45; pos += 1) { // goes from 0 degrees to 45 degrees in steps of 1 degree
      myservo.write(pos);                // tell servo to go to position in variable 'pos'
      delay(15);                         // waits 15ms for the servo to reach the position
    }
    for (pos = 45; pos >= 0; pos -= 1) { // goes from 45 degrees to 0 degrees
      myservo.write(pos);                // tell servo to go to position in variable 'pos'
      delay(15);                         // waits 15ms for the servo to reach the position
    }
  }
  if(digitalRead(4) == LOW){
    for (int thisNote = 0; thisNote < 8; thisNote++) {
      int noteDuration = 1000/noteDurations[thisNote];
      tone(2, melody[thisNote],noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      noTone(2);
    }
  }
}
