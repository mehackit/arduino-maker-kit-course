// Tämä ohjelma sopii vaihteistettujen DC-moottoreiden ohjaamiseen.
// moottorin kontrollointipinnit ja niitä vastaavat Arduino-portit:
int oikeaMot1 = 3;   
int oikeaMot2 = 9;   
int vasenMot1 = 11; 
int vasenMot2 = 10;

//Määrittele seuraavaksi pari muuttujaa, joiden avulla moottorien toimintaa ohjaillaan - nopeus ja toiminto:
int nopeus=100;   // moottoreiden pyörimisnopeus
int toiminto=1;   // muuttuja saa arvoja välillä 1-4: robotilla on neljä eri toimintoa.

void setup(){     
  //Määrittele Setup-osassa Arduino-portit ulostuloiksi:
  pinMode(oikeaMot1, OUTPUT); 
  pinMode(oikeaMot2, OUTPUT);
  pinMode(vasenMot1, OUTPUT);
  pinMode(vasenMot2, OUTPUT);
}
void loop() {
  // Arvotaan luku välillä 1-4 
  // Huom: random-funktio ei ota mukaan ylärajaa eli lukua 5!
  toiminto = (random(1,5)); 
  delay(1000);
  // Tähän kirjoitetaan seuraavaksi robotin eri toiminnot
  //Muuttujalle toiminto arvotaan yksi arvo neljästä, ja jokainen arvo tarkoittaa eri toimintoa.
  //Eteenpäin:
  if (toiminto == 1) { 
    analogWrite(oikeaMot1, nopeus);// pyörii eteenpäin nopeudella "nopeus"
    analogWrite(oikeaMot2, 0);  // oikean moottorin nopeus taaksepäin on 0
    analogWrite(vasenMot1, nopeus);// pyörii eteenpäin nopeudella "nopeus"
    analogWrite(vasenMot2, 0);  // vasemman moottorin nopeus taaksepäin on 0
    delay(4000);   // robotti kulkee eteenpäin 4 sekuntia
  }
//Taaksepäin:

if (toiminto == 2) { 
    analogWrite(oikeaMot1, 0);     // oikean moottorin nopeus eteenpäin on 0
    analogWrite(oikeaMot2, nopeus);// pyörii taaksepäin nopeudella "nopeus"
    analogWrite(vasenMot1, 0);   // vasemman moottorin nopeus eteenpäin on 0
    analogWrite(vasenMot2, nopeus);// pyörii taaksepäin nopeudella "nopeus"
    delay(1500);      // robotti kulkee taaksepäin 1,5 sekuntia
  }
//Käännös vasempaan:

if (toiminto == 3) { 
    analogWrite(oikeaMot1, 0);     // oikean moottorin nopeus eteenpäin on 0
    analogWrite(oikeaMot2, 0);     // oikean moottorin nopeus taaksepäin on 0
    analogWrite(vasenMot1, nopeus);// vasen moottori pyörii eteenpäin
    analogWrite(vasenMot2, 0);     // vasemman moottorin nopeus taaksepäin on 0
    delay(1500);       // käännös kestää 1,5 sekuntia
  }
//Käännös oikeaan:

if (toiminto == 4) { 
    analogWrite(oikeaMot1, nopeus); // oikea moottori pyörii eteenpäin 
    analogWrite(oikeaMot2, 0);      // oikean moottorin nopeus taaksepäin on 0
    analogWrite(vasenMot1, 0);      // vasemman moottorin nopeus eteenpäin on 0
    analogWrite(vasenMot2, 0);      // vasemman moottorin nopeus taaksepäin on 0
    delay(1500);      // käännös kestää 1,5 sekuntia
}
}
