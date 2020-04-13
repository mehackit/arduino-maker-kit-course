void setup() {
  pinMode(9, OUTPUT);   // määrittele portti 9 ulostuloksi
  Serial.begin(9600);   // käynnistä sarjaliikenne 
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue); // tulosta sensorValue serial monitoriin  

  int aani = map(sensorValue, 0, 1023, 100, 3000);
  tone(9, aani, 1000);

  int potValue = analogRead(A1); // luo kokonaislukumuuttuja potValue ja anna sen arvoksi analogiportin A1 lukema
  Serial.println(potValue)      // tulosta potValue serial monitoriin 
  
  delay(potValue); // muuttujaa potValue käytetään viiveen kestona

}
