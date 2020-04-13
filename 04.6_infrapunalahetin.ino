int remote;
int remoteMax;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);  //Aseta piezon portti tilaan OUTPUT
  Serial.begin(9600);
}

void loop() {
  remote = analogRead(0);
  if (remote > remoteMax) {
    remoteMax = remote;
  }
  Serial.print("Value = ");
  Serial.print(remote);
  Serial.print("\t");
  Serial.print("Max-value = ");
  Serial.print(remoteMax);
  Serial.print("\n");
  // Jos valitsemasi raja-arvo ylittyy, soita piezolla jokin melodia.
  // Nyt raja-arvoksi on valittu 400, mikä on reilu kolmasosa koko skaalasta (0-1023)
  if (remote > 400) {
    // Alla on hatusta temmattu yksinkertainen melodia. Rohkaise opiskelijoita googlaamaan erilaisia tunnareita ja niiden Arduino-koodeja!
    // Kun melodia on soitettu kerran, loop-metodi luetaan uudestaan.
    tone(4, 440, 200);
    delay(200);
    tone(5, 600, 500);
    delay(500);
    tone(5, 300, 500);
    delay(500);
    }
  }
}
