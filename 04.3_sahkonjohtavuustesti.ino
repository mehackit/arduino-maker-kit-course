int sensorValue;
int kirkkaus;

// muuttujat, joita tarvitaan resistanssin laskemiseen
int Vin = 5;   // jännite, jonka Arduino syöttää virtapiiriin (5V)
float Vout;    // jännite, jonka A0-portti mittaa piiristä
float R1 = 10000;  // kiinteän vastuksen resistanssi (10 kilo-ohm)
float R2;     // mitattavan aineen resistanssi

void setup() {
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(A0);

  Vout = sensorValue*Vin / 1024.0;  // muunnetaan anturilukema jännitteeksi
  R2 = R1 * ((Vin / Vout) - 1);     // lasketaan mitattavan aineen resistanssi
                                   // tunnettujen arvojen perusteella
  Serial.print("Vout: ");
  Serial.println(Vout);
  Serial.print("R2: ");
  Serial.println(R2);
  delay(1000);
  
  kirkkaus = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(5, kirkkaus);
}
