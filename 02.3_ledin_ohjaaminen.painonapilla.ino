void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(digitalRead(2););

  if (digitalRead(2) == 0){
    digitalWrite(5, HIGH); 
  } 
  else { 
    digitalWrite(5, LOW); 
  }
}
