#include <Servo.h>

int buttonState = 0; // Luo muuttuja buttonState ja aseta sen alkuarvoksi 0
int lastButtonState = 0; // Luo muuttuja lastButtonState ja aseta sen alkuarvoksi 0
int kulma = 0; // Luo muuttuja kulma ja aseta sen alkuarvoksi 0

Servo myServo;

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(6, OUTPUT);
  myServo.attach(6);
  Serial.begin(9600);
}

void loop(){
  buttonState = digitalRead(2);
  // Jos buttonState on erisuuri kuin lastButtonState ja jos buttonState on 1, lisää muuttujaan kulma arvo 5. 
  if (buttonState != lastButtonState){
    if (buttonState == 0){
      kulma = kulma + 5;
    }
  }
  myServo.write(kulma);
  if(kulma >= 180){
    kulma = 0;
  }
  lastButtonState = buttonState;
  Serial.println(kulma);
}
