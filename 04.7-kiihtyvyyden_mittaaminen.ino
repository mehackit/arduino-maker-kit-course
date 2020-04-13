#include <SPI.h> // Including SPI-library and defining the four pins of accelerometer
#define SS   10
#define MOSI 11
#define MISO 12
#define SCK  13
 
#define SCALE 0.00007019 // LIS331 measures +-24 g so the scale is 48 G's in total (G = 9,81 m/s^2). Accelerations are measured in packages of 16 bits so the scale is: 48/2^16 = 0.00007019
 
double xAcc, yAcc, zAcc; // Three variables of type double. These store the values of accelerations measured in x-, y- and z-directions
double xMax, yMax, zMax; // These variables store the maximum values of each direction (x, y and z)
 
void setup() {
  pinMode(6, OUTPUT);
  Serial.begin(9600);
  while (!Serial);
  SPI_SETUP();  
  Accelerometer_Setup();  
}
 
void loop() {
  ReadAccVal(); //Calling the ReadAccVall-function
  //Printing the accelerations in x-, y- and z-directions.
  Serial.print("X="); //First, the string "X=" is printed and then the value of variable "xAcc", accurate to one decimal
  Serial.print(xAcc, 1);
  Serial.print(" Y=");
  Serial.print(yAcc, 1);
  Serial.print(" Z=");
  Serial.print(zAcc, 1);
  Serial.print("\t");
  Serial.print("X="); 
  Serial.print(xMax, 1);
  Serial.print(" yMax=");
  Serial.print(yMax, 1);
  Serial.print(" zMax=");
  Serial.println(zMax, 1);
  //magicWand();
}

void magicWand(){
    int pitch = (xAcc + yAcc + zAcc) * 4;
    tone(6, pitch);
 }

void ReadAccVal(void){
  byte xAddressByteL = 0x28;      // Low Byte of X value (the first data register)
  byte readBit = B10000000;       // Bit 0 (MSB) HIGH means read register
  byte incrementBit = B01000000;  // Bit 1 HIGH means keep incrementing registers
  byte dataByte = xAddressByteL | readBit | incrementBit; 
  byte b0 = 0x0;                  // An empty byte
 
  digitalWrite(SS, LOW);      //Setting SS to low to communicate with accelerometer
  SPI.transfer(dataByte);
  
  //Sending empty byte (b0) to accelerometer and receiving bytes that indicate accelerations of each direction.
  byte xL = SPI.transfer(b0); // get the low byte of X data
  byte xH = SPI.transfer(b0); // get the high byte of X data
  byte yL = SPI.transfer(b0); // get the low byte of Y data
  byte yH = SPI.transfer(b0); // get the high byte of Y data
  byte zL = SPI.transfer(b0); // get the low byte of Z data
  byte zH = SPI.transfer(b0); // get the high byte of Z data
  
  digitalWrite(SS, HIGH);     //Setting SS to low to communicate with accelerometer
 
  int xVal = (xL | (xH << 8)); // Doing a bitshift so that "xVal" is "xH" and "xL" combined, a number of sixteen bits.
  int yVal = (yL | (yH << 8)); 
  int zVal = (zL | (zH << 8));
 
  xAcc = xVal * SCALE; // Transforming the 16 bit -values to G's.
  yAcc = yVal * SCALE;
  zAcc = zVal * SCALE;

  if(xAcc > xMax){
    xMax = xAcc;
  }
  if(yAcc > yMax){
    yMax = yAcc;
  }
  if(zAcc > zMax){
    zMax = zAcc;
  }
  
}
 
void SPI_SETUP()
{
  pinMode(SS, OUTPUT);
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0);
  SPI.setClockDivider(SPI_CLOCK_DIV8);
}
 
void Accelerometer_Setup(void)
{
  byte addressByte = 0x21;
  byte ctrlRegByte = 0x00;
 
  digitalWrite(SS, LOW);
  SPI.transfer(addressByte);
  SPI.transfer(ctrlRegByte);
  digitalWrite(SS, HIGH);
 
  delay(100);
 
  addressByte = 0x22;
  ctrlRegByte = 0x00;
 
  digitalWrite(SS, LOW);
  SPI.transfer(addressByte);
  SPI.transfer(ctrlRegByte);
  digitalWrite(SS, HIGH);
  
  delay(100);
  
  addressByte = 0x20;
  ctrlRegByte = 0x47;
 
  digitalWrite(SS, LOW);
  SPI.transfer(addressByte);
  SPI.transfer(ctrlRegByte);
  digitalWrite(SS, HIGH);
}
