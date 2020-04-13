// Tämä ohjelma sopii vaihteistetun DC-moottorin ohjaamiseen.

int rightVal;
int leftVal;
int dif;

void setup() {
  pinMode(3, OUTPUT);  // 3,9,10 ja 11 ovat moottoreiden ohjausportteja.
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  rightVal = analogRead(A0);
  leftVal = analogRead(A1);
  dif = abs(rightVal - leftVal);
  Serial.print("Left Sensor = "); 
  Serial.print(leftVal);
  Serial.print("\t");
  Serial.print("Right Sensor = "); 
  Serial.print(rightVal); 
  Serial.print("\t"); 
  Serial.print("Difference = ");
  Serial.print(dif); 
  Serial.print("\n"); 
  // Jos vasemman ja oikeanpuoleisen infrapunasensorin ero on yli 60, täytyy kääntyä siihen suuntaan, jossa arvo on suurempi.
  if(dif > 60){  
    // Jos rightVal > leftVal, käänny oikealle (kutsu komentoa turnRight).
    if (rightVal > leftVal){
      turnRight();
    }
    // Jos rightVal < leftVal, käänny vasemmalle(kutsu komentoa turnLeft).
    if (rightVal < leftVal){
      turnLeft();
    }
  }
  else{
    // Jatka infrapunan etsimistä
      forward();
  }
}

void turnRight(){
  analogWrite(oikeaMot1, 255);  // oikea moottori pyörii eteenpäin 
  analogWrite(oikeaMot2, 0);     
  analogWrite(vasenMot1, 0); 
  analogWrite(vasenMot2, 0);     
  delay(300);    
}

void turnLeft(){
  analogWrite(oikeaMot1, 0);     
  analogWrite(oikeaMot2, 0);    
  analogWrite(vasenMot1, 255); // vasen moottori pyörii eteenpäin
  analogWrite(vasenMot2, 0);      
  delay(300);       
}

void forward(){
  analogWrite(oikeaMot1, 255);     
  analogWrite(oikeaMot2, 0);    
  analogWrite(vasenMot1, 255); // vasen moottori pyörii eteenpäin
  analogWrite(vasenMot2, 0);      
  delay(40);
}
