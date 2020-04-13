int sensorValue;
int kirkkaus;

void setup() {
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  kirkkaus = map(sensorValue, 0, 1023, 255, 0); // 255 ja 0 vaihtavat paikkaa!
  analogWrite(5, kirkkaus);
}
