int buttonState = 0;
int lastButtonState = 0;
int ledState = 0;
int counter = 0; 

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(counter);
  buttonState = digitalRead(2);
  // Alla kokeillaan, onko napin tila vaihtunut loop-kierroksien välillä JA onko tila nyt HIGH
  if (buttonState != lastButtonState){
    if(buttonState == HIGH){
      // Mikäli ehto täyttyy, vaihdetaan ledin tilaa ja lisätään muuttujaan counter arvo 1.
      // counter-kokonaislukumuuttujan funktio on esimerkissä ainoastaan havainnollistaa kytkimen toimintaa.
      ledState = !ledState;
      counter = counter + 1;
   }
  }
  lastButtonState = buttonState;
  digitalWrite(5, ledState);
}
