// import the serial and video libraries
import processing.serial.*;
import processing.video.*;

// create a Capture variable called video:
Capture video;

// create a Serial variable called myPort and a variable called num which stores the value read from serial port
Serial myPort;
int num;
int num2;

void setup() {
  size(640, 480);
  noStroke();  

  video = new Capture(this, width, height);
  video.start();
  
  //print a list of available ports in the console
  for(int i = 0; i < Serial.list().length; i++){
      println(i + ", " + Serial.list()[i]);
  }
  
  //create a variable portName, choose the number of the port that your arduino is plugged into.
  //the port is the same port as the one you chose in the Arduino -> tools -> port menu.
  String portName = Serial.list()[3]; 
  println(portName);
  myPort = new Serial(this, portName, 9600); 
  num = 0;
  num2 = 0;
  
}

void draw() {

  // check if there's content in the serial port and read a line from it
  if (myPort.available() > 0) {  
    String val = myPort.readStringUntil('\n');  //Read the value from the first line of the serial port data
    String val2 = myPort.readStringUntil('\n'); //Read the value from the second line of the serial port data
    // if the values are not null, they are parsed into variables num and num2
    if (val != null) {
      val = trim(val);
      num = Integer.parseInt(val);
    } 
    if (val2 != null) {
      val2 = trim(val2);
      num2 = Integer.parseInt(val2);
    } else {
      num = 100;
      num2 = 200;  
    }
  } 

  if (video.available()) {
    video.read();
    video.loadPixels();

    for (int i = 0; i < 1000; i++) {
      int x = int(random(video.width));
      int y = int(random(video.height));
      int index = x+(y*video.width);


      float red = red(video.pixels[index]);
      float green = green(video.pixels[index]);
      float blue = blue(video.pixels[index]);

     

      float size = random(num/10); //Create a variable size, which is affected by the value from the first line of serial port 
      float distance = num2/100;   //Create a variable distance, which contains the second number from serial port
      
      float red2 = red/distance;     // Create a variable red2, affected by variable distance 
      fill(red2, green, blue, 100);  // Adjust the amount of red with variable distance
      ellipse(x, y, size, size);     // use the variable size to define the dimensions of an ellipse
    }
  }
}
