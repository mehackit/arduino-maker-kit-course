// Tuodaan Processingiin Serial-kirjasto.
import processing.serial.*;

// Luodaan Serial-tyypin muuttuja "port" ja kokonaislukumuuttuja "num". port on portti, josta informaatio tulee ja 
// num-muuttujaan tallennetaan Arduinon lähettämä (potentiometrin) arvo.
Serial myPort;
int num;

void setup() {
  // Luodaan piirtoikkuna, jonka koko on 600 x 600
  size(600, 600);  
  // frameRate-komennolla asetetaan nopeus, jolla draw-looppia suoritetaan. Oletus on 60 krt/s, nyt 10 000 kertaa sekunnissa.
  // Ilman frame raten kasvattamista Processing saattaa reagoida potentiometrin kääntämiseen hitaasti. Kokeile eri arvoja.
  frameRate(10000);
  // Luodaan String-tyypin muuttuja portName, johon tallennetaan Arduinon kanssa viestivän Serial-portin nimi.
  String portName = Serial.list()[0]; 
  println(portName);
  // Luodaan varsinainen Serial Port -olio ja asetetaan viestintänopeudeksi 9600 baudia.
  myPort = new Serial(this, portName, 9600); 
  num = 0;
}

void draw() {
  // Asetetaan taustaväriksi musta. Voit muokata numeroita ja vaihtaa taustaväriä. 
  background(0, 0, 0);
  // Varmista, että Serial-port on käytettävissä. Jos on, lue dataa rivinvaihtoon ("\n") asti ja tallenna tämä data merkkijonona (String) muuttujaan "val".
  if (myPort.available() > 0) {  
    String val = myPort.readStringUntil('\n');  
    // Jos arvo ei ole tyhjä (null).
    if (val != null) {
      // try/catch -rakenteen idea on seuraava. Aluksi yritetään ("try") muuntaa merkkijono (String) kokonaisluvuksi, koska muuten potentiometrista tulevan datan käyttö lukuna ei onnistu. 
      // Jos muunnos merkkijonosta luvuksi ei onnistu, on syynä luultavasti se, että merkkijonoon on tallennettu kirjain, välilyönti tai tyhjä arvo ("") (tyhjä arvo on eri asia kuin aiemmin huomioitu "null"). 
      // Näissä tapauksissa Processing ei osaisi muuntaa dataa kokonaisluvuksi, antaisi meille virheilmoituksen ja pysäyttäisi ohjelman, mutta catch-osassa tämä virheilmoitus on huomioitu ja ehkäisty ennalta.
      try{
         // Poistetaan ylimääräiset välilyönnit merkkijonosta trim-komennolla.
         val = trim(val);
         // Muunnetaan merkkijonon sisältävä muuttuja 'val' kokonaisluvuksi ja tallennetaan kokonaislukuarvo muuttujaan 'num'.
         num = Integer.parseInt(val);
      }
      catch(NumberFormatException npe){      
      } 
    } 
    // Jos arvo on tyhjä (null), asetetaan oletusarvoksi 100.
    else {
      num = 100;
    }
  } 
  // Lopulta piirretään ellipsi, jonka leveydeksi ja korkeudeksi asetetaan potentiomteristä tuleva arvo (num).
  ellipse(width/2, height/2, num, num);
}
