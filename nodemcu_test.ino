/* NodeMCU remote servo controller
 * by Juho Kostet @ Mehackit
 * Made for the course "Robotiikka Tulevaisuudessa".
 */

// Servo library
#include <Servo.h>
Servo servo;

// WiFi library
#include <ESP8266WiFi.h>

// WiFi credentials, change these to match your network
const char* ssid = "YourWiFiName";
const char* password = "YourWiFiPassword";

WiFiServer server(80);


void setup() {
  /* About pins:
   * NodeMCU has pins labeled different vs Arduino.
   * It's probably easier to use them directly vs
   * using analogRead(number).
   * 
   * Google "NodeMCU pin map" for matching GPIO numbers.
   * digitalRead(D1) == digitalRead(5) for GPIO5.
   */
  servo.attach(D1);

  /* Setup Serial connection for NodeMCU,
   * note the higher baud rate vs Arduino standard 9600.
   */
  Serial.begin(115200);
  delay(10);


  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
  }
  

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);

  server.begin();


  // Print the IP address on the serial monitor
  Serial.print("Browse to this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  Serial.println("");
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while (!client.available()) {
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();


  int degree = 0;

  // Turn servo according to request /Req=
  if (request.indexOf("/Req") != -1) {
    String getReq = request.substring(request.indexOf("/Req"));
    degree = getReq.substring((getReq.indexOf('=') + 1)).toInt();
    servo.write(degree);
  }
  

  // Return respose with html content (visible control page)
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); // space between response header and content
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<div align=center ");
  client.println("style=\"border: 5px dotted yellow; margin: 20%; padding: 5%;\">");
  client.println("<h2>Remote light switch! </h2><br><br>");
  client.print("Servo is set to: ");
  client.print(degree); 
  client.println("<br><br>");

  /* Change these to set what the buttons say
   * and to which degree they turn the servo to.
   */
  String btnText1 = "  0 degrees";
  int btnDeg1 = 0;
  
  String btnText2 = " 90 degrees";
  int btnDeg2 = 90;
  
  String btnText3 = "180 degrees";
  int btnDeg3 = 180;
  
  client.println("<a href=\"/Req=");
  client.print(btnDeg1);
  client.print("\"><button style=\"width: 200px; height: 50px;\">");
  client.print(btnText1);
  client.print("</button></a><br>");
    
  client.println("<a href=\"/Req=");
  client.print(btnDeg2);
  client.print("\"><button style=\"width: 200px; height: 50px; margin: 5px 0 5px 0;\">");
  client.print(btnText2);
  client.print("</button></a><br>");
  
  client.println("<a href=\"/Req=");
  client.print(btnDeg3);
  client.print("\"><button style=\"width: 200px; height: 50px;\">");
  client.print(btnText3);
  client.print("</button></a><br>");

  client.println("</div>");
  client.println("</html>");
  
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
