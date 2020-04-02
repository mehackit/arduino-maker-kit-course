void setup() {
 pinMode(5, OUTPUT);
 pinMode(6, OUTPUT); //Tämä ledi liitetään mukaan myöhemmässä vaiheessa
}

void loop() {
  digitalWrite(5, HIGH);
  delay(1000);
  digitalWrite(5, LOW)
  delay(500); //delay -arvoja voi muokata halunsa mukaan!
}
