void setup() {
 //Aseta reed-kytkimen portti tilaan INPUT_PULLUP
 pinMode(5, INPUT_PULLUP);
 //Aseta transistorin portti tilaan OUTPUT
 pinMode(6, OUTPUT);
}

void loop() {
  //Jos reed-kytkin sulkeutuu, johda jännitettä transistorille ja käynnistä lelu
  if(digitalRead(5) == LOW{
    digitalWrite(6, HIGH);
  }
}
