//Tämä ohjelma sopii vaihteistettujen DC-moottoreiden ohjaamiseen ja infrapuna-etäisyysanturin käyttämiseen.
int toiminto = 1;
int oikeaMot1 = 3;
int oikeaMot2 = 9;
int vasenMot1 = 11;
int vasenMot2 = 10;
int nopeus = 150;

void setup(){     
  pinMode(oikeaMot1, OUTPUT); 
  pinMode(oikeaMot2, OUTPUT);
  pinMode(vasenMot1, OUTPUT);
  pinMode(vasenMot2, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int sensorValue = analogRead(A0); // arvoksi A0-analogiportista tuleva lukema
  // Tulosta sensorValue serial monitoriin
  Serial.println(sensorValue);
  // jos sensorValue on alle 400, arvo kumpaan suuntaan robotti kääntyy: toiminto = random(3,5);
  // muuten, määrää robotti kulkemaan eteenpäin
  if(sensorValue < 400){
    toiminto = random(3, 5);
  }
  else{
    toiminto = 1;
  }
  if (toiminto == 1) { 
    analogWrite(oikeaMot1, nopeus);// pyörii eteenpäin nopeudella "nopeus"
    analogWrite(oikeaMot2, 0);  // oikean moottorin nopeus taaksepäin on 0
    analogWrite(vasenMot1, nopeus);// pyörii eteenpäin nopeudella "nopeus"
    analogWrite(vasenMot2, 0);  // vasemman moottorin nopeus taaksepäin on 0
    delay(40);                  // Lisää tähän viive, jonka pituus on 40 millisekuntia. 
  }
  // Toiminto 2 eli kulku taaksepäin voidaan poistaa!
  ¨
  if (toiminto == 3) { 
      analogWrite(oikeaMot1, 0);     
      analogWrite(oikeaMot2, 0);    
      analogWrite(vasenMot1, nopeus); // vasen moottori pyörii eteenpäin
      analogWrite(vasenMot2, 0);      
      delay(1500);       // käännös kestää 1,5 sekuntia
   }
   if (toiminto == 4) { 
      analogWrite(oikeaMot1, nopeus);  // oikea moottori pyörii eteenpäin 
      analogWrite(oikeaMot2, 0);     
      analogWrite(vasenMot1, 0); 
      analogWrite(vasenMot2, 0);     
      delay(1500);    // käännös kestää 1,5 sekuntia
   }
}
