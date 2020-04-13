#include <CapacitiveSensor.h>

CapacitiveSensor sensor = CapacitiveSensor(4, 2);

void setup(){
  // käynnistä sarjaliikenne 
  // määrittele portti 9 ulostuloksi
}

void loop() {
  long sensorValue =  sensor.capacitiveSensor(30);
  // tulosta sensorValue serial monitoriin
  // ohjelmoi 10 millisekunnin viive

 
  if (sensorValue > 100) {
    tone(7,sensorValue);
    int kirkkaus = map(sensorValue, 0, 2000, 0, 255);
    if (sensorValue > 2000) {
       kirkkaus = 255;
    }
    // laita led päälle komennolla analogWrite - käytä muuttujaa kirkkaus
  }  else {
    noTone(7);
    // laita led pois päältä 
  }

}
