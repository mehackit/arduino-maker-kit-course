void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(2);
  Serial.println(buttonState);

if (buttonState == 0){
    digitalWrite(5, HIGH); 
  } else { 
    digitalWrite(5, LOW); 
  }

}
