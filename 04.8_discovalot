unsigned long interval = 200;
unsigned long currentMillis;
unsigned long previousMillis = 0;

int ledPin1 = 7;
int ledPin2 = 8;  
int ledPin3 = 9; 
int ledPin4 = 10; 
int ledPin5 = 11; 

void setup() {
     pinMode(ledPin1, OUTPUT);
     pinMode(ledPin2, OUTPUT);
     pinMode(ledPin3, OUTPUT);
     pinMode(ledPin4, OUTPUT);
     pinMode(ledPin5, OUTPUT);
     Serial.begin(9600);
}

void loop() {     
  currentMillis = millis();
  // määrittele kokonaislukumuuttuja sensor ja lue sen arvoksi portin A0 lukema
  // lisää 8 ms viive
  // tulosta sensor serial monitoriin
  int sensor = analogRead(0);
  delay(8);
  if ((sensor > 50) && (sensor < 150)){
    digitalWrite(ledPin1, HIGH);
  }
  // Kirjoita yllä olevan mallin mukaan ehtolauseet myös muille ledeille
  if ((sensor > 150) && (sensor < 250)){
    digitalWrite(ledPin2, HIGH);
  }
  if ((sensor > 250) && (sensor < 350)){
    digitalWrite(ledPin3, HIGH);
  }
  if ((sensor > 350) && (sensor < 450)){
    digitalWrite(ledPin4, HIGH);
  }
  if ((sensor > 450) && (sensor < 550)){
    digitalWrite(ledPin5, HIGH);
  }

  //delay(10); Kommentoi tai editoi pois tämä aiemmin tarvittu delay.
  if(currentMillis - previousMillis >= interval) {
     previousMillis = currentMillis;
     digitalWrite(ledPin1, LOW);
      // Ohjelmoi yllä olevan mallin mukaan muut ledit pois päältä.
     digitalWrite(ledPin2, LOW);
     digitalWrite(ledPin3, LOW);
     digitalWrite(ledPin4, LOW);
     digitalWrite(ledPin5, LOW);
  }
}
