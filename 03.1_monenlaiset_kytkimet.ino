void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(10, OUTPUT);
}

void loop() {
  if(digitalRead(2) == LOW){
    digitalWrite(10, HIGH);
  }
  else{
    digitalWrite(10, LOW);
  }
}
