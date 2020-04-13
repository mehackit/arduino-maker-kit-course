void setup() {
  pinbMode(2, INPUT_PULLUP);// Aseta kytkimen portti tilaan INPUT_PULLUP
  pinMode(3, OUTPUT);// Aseta piezon portti ulostuloksi
}

void loop() {
  // Jos portista 2 tuleva tila on LOW, soita piezosta taajuutta 440 Hz
  if (digitalRead(2) == 0){
    tone(3, 440);
  }
  // Muuten älä soita piezosta mitään (noTone-komento)
  else{
    noTone(3);
  }
}
