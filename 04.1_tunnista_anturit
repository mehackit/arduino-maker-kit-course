void setup() {
  pinMode(6, OUTPUT); // määrittele komennolla pinMode portti 6 ulostuloksi (OUTPUT)
  Serial.begin(9600);
}

void loop() {
  int sensor = analogRead(0);  // määrittele kokonaislukumuuttuja (int) nimeltä sensor, ja aseta sen arvoksi 
                               // portin A0 lukema komennolla analogRead.
  Serial.println(sensor);
  delay(10);  // lisää 10 millisekunnin viive käskyllä delay

  if (sensor < 300) {
    digitalWrite(6, HIGH); // laita portissa 6 oleva led päälle (HIGH) komennolla digitalWrite.
  } else {
    digitalWrite(6, LOW);  // laita portissa 6 oleva led pois päältä (LOW) komennolla digitalWrite.
  }

}
