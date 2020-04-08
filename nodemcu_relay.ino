/* NodeMCU remote relay controller
 * by Juho + Sanna @ Mehackit.org
 */

// the input to the relay pin. 2 equals D4 in Node MCU
 int relayInput = 2; 

// WiFi library
#include <ESP8266WiFi.h>

// WiFi credentials, change these to match your network
const char* ssid = "yourNetwork";
const char* password = "yourNetworkPasswd";

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
  pinMode(relayInput, OUTPUT); // initialize pin as OUTPUT
 
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

  // Turn relay on or off according to request /Req=
  if (request.indexOf("/Req") != -1) {
    String getReq = request.substring(request.indexOf("/Req"));
    degree = getReq.substring((getReq.indexOf('=') + 1)).toInt();
    digitalWrite(relayInput, degree);
  }
  

  // Return response with html content (visible control page)
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); // space between response header and content
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<div align=center ");
  client.println("style=\"border: 5px dotted yellow; margin: 20%; padding: 5%;\">");
  client.println("<h2>Remote light switch! </h2><br><br>");
  client.print("Relay is set to: ");
  client.print(degree); 
  client.println("<br><br>");

  /* Change these to set what the buttons say
   * and to the value given to digital pin 2 (D4).
   */
  String btnText1 = "  Relay On";
  int btnDeg1 = 1;
  
  String btnText2 = " Relay Off";
  int btnDeg2 = 0;
  

  
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
  
  

  client.println("</div>");
  client.println("</html>");
  
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
