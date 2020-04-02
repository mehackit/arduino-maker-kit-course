/*
*
* Arduino Speed Test Game
* Mehackit 2017
*
* CC-BY-2.0
*
*/

/* 
 *  Length of the random sequence
 *  The type of this variable is "const int". 
 *  "const" means that the value is constant: it doesn't change 
 *  during the execution of the program. 
*/ 
const int MAX_LEVEL = 100; 

int sequence[MAX_LEVEL]; // Create array for the random sequence

// This variable states the current "level"
int questionIndex;
// This variable states the current answer from the player
int answerIndex;

/* 
 * These two variables are used for the time intervals between 
 * blinking new lights. The type is "unsigned long". Unsigned means 
 * that the variables contain only positive values and long means 
 * the variable fits more bits than an int.
 * 
 * int is capable of containing at least 16 bits (from −32,767 to 32,767) 
 * and unsigned long 32 bits (from 0 to 4,294,967,295). This is important 
 * as we're storing ammounts of milliseconds into these variables
*/
unsigned long showNewQuestionAt = 0;
unsigned long interval = 1000;
unsigned long turnLastLedOfAt = 0;

const int LEDS[] = {5,6,7}; // array of pin numbers for leds
const int SPEAKER = 8; // pin number for piezo buzzer
const int NOTES[] = {131, 165, 196}; // array of note values for tone-function
const int BUTTONS[] = {2,3,4}; // array of pin numbers for buttons

/* 
 *  These two variables are used for a short delay between reading the 
 *  values of the buttons. This helps with the reliability and flickering 
 *  of the buttons.
*/
long lastDebounceTimes[] = {0,0,0};
const long debounceDelay = 50;
/* 
 * These boolean (0 or 1) variables are used to detect when the button goes 
 * from not being pressed to being pressed
*/
bool lastButtonStates[] = {HIGH, HIGH, HIGH};

// Set pin modes and start the game by calling the startGame function. 
// This code only runs once.
void setup() {
  pinMode(LEDS[0], OUTPUT);
  pinMode(LEDS[1], OUTPUT);
  pinMode(LEDS[2], OUTPUT);
  pinMode(BUTTONS[0], INPUT_PULLUP);
  pinMode(BUTTONS[1], INPUT_PULLUP);
  pinMode(BUTTONS[2], INPUT_PULLUP);
  startGame();
}

/*
 * If question level is equal to MAX_LEVEL player won the game
 * Otherwise:
 * 1) Check if it's time to show the next light
 * 2) Check if its time to turn off the last light
 * 3) Process user input:
 *   a) If the input is correct, advance answerIndex
 *   b) If the inspus is incorrect game is over
 */
void loop() {
  if (questionIndex >= MAX_LEVEL) {
    gameWon();
  }
  unsigned long now = millis();
 
  if(now > showNewQuestionAt){ // Check if it's time to show next light
    playNextInSequence(); // Show next light in the sequence
  }
  if(now > turnLastLedOfAt) {
    turnAllLedsOff(); // turn all leds off
  }

  // isButtonPressed function returns the number of the pressed button 
  // or -1 if no button is pressed
  // here the returned value is stored to a variable called button
  int button = isButtonPressed(); 
  
  if(button >= 0) { // if button is positive, a button is pressed
    if(sequence[answerIndex] == button){ // check if the answer is right
      answerIndex = answerIndex + 1; // increment the answerIndex variable
      tone(SPEAKER, NOTES[button], 100); // play a tone
      turnAllLedsOff(); // turn all leds off
    } else {
      gameOver(); // end the game if the answer is wrong
    }
  }
}

// show next led for the player
void playNextInSequence() {
  /* 
   * LEDS[] is an array containing all the pin numbers for leds. 
   * LEDS[0] returns the pin for the first led etc. Sequence[questionIndex] 
   * returns the current led number. LEDS[sequence[questionIndex]] combines 
   * these two and returns the pin number of current led.
   */
  digitalWrite(LEDS[sequence[questionIndex]], HIGH);
  // Increase the questionIndex by 1
  questionIndex++;
  // Set the time for next question
  showNewQuestionAt = millis() + interval;
  // Set time to turn the led off
  turnLastLedOfAt = showNewQuestionAt - 200;
  // Speed up 10 percent
  interval = interval - 10;
}

// Turn all leds off
void turnAllLedsOff() {
  for(int i=0; i<3; i++){ // loop through values 0,1 and 2
    digitalWrite(LEDS[i], LOW); // turn each led off
  }
}

// Start game by generating a random sequence and reseting the variables
void startGame() {
  randomSeed(analogRead(0)); //seed with somewhat random value
  // fill the sequence array with random values
  for(int i=0; i<MAX_LEVEL; i++){
    sequence[i] = random(0, 3); 
  }
  // reset variables
  questionIndex = 0;
  answerIndex = 0;
  interval = 1000;
}

void gameWon() {
  while(true) {
    digitalWrite(LEDS[0], HIGH);
    digitalWrite(LEDS[1], HIGH);
    digitalWrite(LEDS[2], HIGH);
  }
}

// Indicate ending of the game by blinking all leds. 
//Start the game again by calling the startGame function
void gameOver() {
  digitalWrite(LEDS[0], HIGH);
  digitalWrite(LEDS[1], HIGH);
  digitalWrite(LEDS[2], HIGH);
  delay(1000);
  digitalWrite(LEDS[0], LOW);
  digitalWrite(LEDS[1], LOW);
  digitalWrite(LEDS[2], LOW);
  delay(1000);
  digitalWrite(LEDS[0], HIGH);
  digitalWrite(LEDS[1], HIGH);
  digitalWrite(LEDS[2], HIGH);
  delay(1000);
  digitalWrite(LEDS[0], LOW);
  digitalWrite(LEDS[1], LOW);
  digitalWrite(LEDS[2], LOW);
  delay(1000);
  startGame();
}

// If a button is pressed, return the number of the button
// Otherwise return -1 
int isButtonPressed() {
  // iterate through 0, 1 and 2
  for (int i = 0; i < 3; i++) {
    long now = millis(); //save the current time
    
    // read the state of the switch into a local variable:
    int reading = digitalRead(BUTTONS[i]);
  
    // check to see if you just pressed the button 
    // (i.e. the input went from HIGH to LOW)
    // note that this could have caused by noise
    if (reading == LOW && lastButtonStates[i] == HIGH) {
      // check if the reading is longer than the debounce time
      if ((now - lastDebounceTimes[i]) > debounceDelay) {
        lastButtonStates[i] = LOW; //save the last state
        return i; // return the button number
      }
    } else {
      lastButtonStates[i] = reading; //save the last state
      lastDebounceTimes[i] = now; // reset the debounce timer
    }
  }
  return -1; // return -1 indicating no button was pressed
}
