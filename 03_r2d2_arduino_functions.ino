// Code originally created by Erik Kringen (https://blog.mycontraption.com/?s=sound+effects)
// Used with permission of the author by Nublert @ mehackit.org

void beep (int speakerPin, float noteFrequency, long noteDuration)
{    
  int x;
  // Convert the frequency to microseconds
  float microsecondsPerWave = 1000000/noteFrequency;
  // Calculate how many HIGH/LOW cycles there are per millisecond
  float millisecondsPerCycle = 1000/(microsecondsPerWave * 2);
  // Multiply noteDuration * number or cycles per millisecond
  float loopTime = noteDuration * millisecondsPerCycle;
  // Play the note for the calculated loopTime.
  for (x=0;x<loopTime;x++)   
          {   
              digitalWrite(speakerPin,HIGH); 
              delayMicroseconds(microsecondsPerWave); 
              digitalWrite(speakerPin,LOW); 
              delayMicroseconds(microsecondsPerWave); 
          } 
}     
     

void r2D2(){
          beep(speakerPin, note_A7,100); //A 
          beep(speakerPin, note_G7,100); //G 
          beep(speakerPin, note_E7,100); //E 
          beep(speakerPin, note_C7,100); //C
          beep(speakerPin, note_D7,100); //D 
          beep(speakerPin, note_B7,100); //B 
          beep(speakerPin, note_F7,100); //F 
          beep(speakerPin, note_C8,100); //C 
          beep(speakerPin, note_A7,100); //A 
          beep(speakerPin, note_G7,100); //G 
          beep(speakerPin, note_E7,100); //E 
          beep(speakerPin, note_C7,100); //C
          beep(speakerPin, note_D7,100); //D 
          beep(speakerPin, note_B7,100); //B 
          beep(speakerPin, note_F7,100); //F 
          beep(speakerPin, note_C8,100); //C 
}

void closeEncounters() {
          beep(speakerPin, note_Bb5,300); //B b
          delay(50);
          beep(speakerPin, note_C6,300); //C
          delay(50);
          beep(speakerPin, note_Ab5,300); //A b
          delay(50);
          beep(speakerPin, note_Ab4,300); //A b
          delay(50);
          beep(speakerPin, note_Eb5,500); //E b   
          delay(500);     
          
          beep(speakerPin, note_Bb4,300); //B b
          delay(100);
          beep(speakerPin, note_C5,300); //C
          delay(100);
          beep(speakerPin, note_Ab4,300); //A b
          delay(100);
          beep(speakerPin, note_Ab3,300); //A b
          delay(100);
          beep(speakerPin, note_Eb4,500); //E b   
          delay(500);  
          
          beep(speakerPin, note_Bb3,300); //B b
          delay(200);
          beep(speakerPin, note_C4,300); //C
          delay(200);
          beep(speakerPin, note_Ab3,300); //A b
          delay(500);
          beep(speakerPin, note_Ab2,300); //A b
          delay(550);
          beep(speakerPin, note_Eb3,500); //E b      
}

void ariel() {

          beep(speakerPin, note_C6,300); //C
          delay(50);
          beep(speakerPin, note_D6,300); //D
          delay(50);
          beep(speakerPin, note_Eb6,600); //D#
          delay(250);
          
          beep(speakerPin, note_D6,300); //D
          delay(50);
          beep(speakerPin, note_Eb6,300); //D#
          delay(50);
          beep(speakerPin, note_F6,600); //F
          delay(250);
          
          beep(speakerPin, note_C6,300); //C
          delay(50);
          beep(speakerPin, note_D6,300); //D
          delay(50);
          beep(speakerPin, note_Eb6,500); //D#
          delay(50);          
          beep(speakerPin, note_D6,300); //D
          delay(50);
          beep(speakerPin, note_Eb6,300); //D#
          delay(50);             
          beep(speakerPin, note_D6,300); //D
          delay(50);
          beep(speakerPin, note_Eb6,300); //D#
          delay(50);
          beep(speakerPin, note_F6,600); //F
          delay(50); 

}
 

void laugh2() {
          beep(speakerPin, note_C6,200); //C
          beep(speakerPin, note_E6,200); //E  
          beep(speakerPin, note_G6,200); //G 
          beep(speakerPin, note_C7,200); //C 
          beep(speakerPin, note_C6,200); //C
          delay(50);
          beep(speakerPin, note_C6,200); //C
          beep(speakerPin, note_E6,200); //E  
          beep(speakerPin, note_G6,200); //G 
          beep(speakerPin, note_C7,200); //C 
          beep(speakerPin, note_C6,200); //C
          delay(50);
          beep(speakerPin, note_C6,50); //C
          delay(50);
          beep(speakerPin, note_C6,50); //C
          delay(50);
          beep(speakerPin, note_C6,50); //C
          delay(50);
          beep(speakerPin, note_C6,50); //C
          delay(50);
          beep(speakerPin, note_C6,50); //C
          delay(50);
          beep(speakerPin, note_C6,50); //C
          delay(50);
          beep(speakerPin, note_C6,50); //C
          

          
}
  
void squeak() {
  for (int i=100; i<5000; i=i*1.45) {
    beep(speakerPin,i,60);
  }
  delay(10);
  for (int i=100; i<6000; i=i*1.5) {
    beep(speakerPin,i,20);
  }
}

void waka() {
  for (int i=1000; i<3000; i=i*1.05) {
    beep(speakerPin,i,10);
  }
  delay(100);
  for (int i=2000; i>1000; i=i*.95) {
    beep(speakerPin,i,10);
  }
    for (int i=1000; i<3000; i=i*1.05) {
    beep(speakerPin,i,10);
  }
  delay(100);
  for (int i=2000; i>1000; i=i*.95) {
    beep(speakerPin,i,10);
  }
    for (int i=1000; i<3000; i=i*1.05) {
    beep(speakerPin,i,10);
  }
  delay(100);
  for (int i=2000; i>1000; i=i*.95) {
    beep(speakerPin,i,10);
  }
    for (int i=1000; i<3000; i=i*1.05) {
    beep(speakerPin,i,10);
  }
  delay(100);
  for (int i=2000; i>1000; i=i*.95) {
    beep(speakerPin,i,10);
  }
}

void catcall() {
  for (int i=1000; i<5000; i=i*1.05) {
    beep(speakerPin,i,10);
  }
 delay(300);
 
  for (int i=1000; i<3000; i=i*1.03) {
    beep(speakerPin,i,10);
  }
  for (int i=3000; i>1000; i=i*.97) {
    beep(speakerPin,i,10);
  }
}

void ohhh() {
  for (int i=1000; i<2000; i=i*1.02) {
    beep(speakerPin,i,10);
  }
  for (int i=2000; i>1000; i=i*.98) {
    beep(speakerPin,i,10);
  }
}

void uhoh() {
  for (int i=1000; i<1244; i=i*1.01) {
    beep(speakerPin,i,30);
  }
  delay(200);
  for (int i=1244; i>1108; i=i*.99) {
    beep(speakerPin,i,30);
  }
}

void laugh() {
  for (int i=1000; i<2000; i=i*1.10) {
    beep(speakerPin,i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    beep(speakerPin,i,10);
  }
  delay(50);
  for (int i=1000; i<2000; i=i*1.10) {
    beep(speakerPin,i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    beep(speakerPin,i,10);
  }
  delay(50);
    for (int i=1000; i<2000; i=i*1.10) {
    beep(speakerPin,i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    beep(speakerPin,i,10);
  }
  delay(50);
    for (int i=1000; i<2000; i=i*1.10) {
    beep(speakerPin,i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    beep(speakerPin,i,10);
  }
  delay(50);
}
