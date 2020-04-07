#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
 
// Replace with your network credentials
const char* ssid = "tum jano";
const char* password = "password";
 
ESP8266WebServer server(80);   //instantiate server at port 80 (http port)
 
String page = "";
int r1l1 = 12;
int r1f = 13;
int r1c = 14;
int r1l2 = 15;
void setup(void){
  //the HTML of the web page
  page = "<h1>Simple NodeMCU Web Server</h1><p><a href=\"l1on\"><button>ON</button></a>&nbsp;<a href=\"l1off\"><button>OFF</button></a></p>";
  //make the LED pin output and initially turned off
  pinMode(r1l1, OUTPUT);
  pinMode(r1l2, OUTPUT);
  pinMode(r1f, OUTPUT);
  pinMode(r1c, OUTPUT);
  pinMode(fc0, OUTPUT);
  pinMode(fc1, OUTPUT);
  pinMode(fc2, OUTPUT);
  pinMode(fc3, OUTPUT);
  digitalWrite(r1l1, HIGH);
  digitalWrite(r1l2, LOW);
  digitalWrite(r1f, HIGH);
  digitalWrite(r1c, LOW);
   digitalWrite(fc0, HIGH);
  digitalWrite(fc1, HIGH);
  digitalWrite(fc2, HIGH);
  digitalWrite(fc3, HIGH);
   
  delay(1000);
  Serial.begin(115200);
  WiFi.begin(ssid, password); //begin WiFi connection
  Serial.println("");
 
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
   
  server.on("/", [](){
    server.send(200, "text/html", page);
  });
  server.on("/r1l11", [](){
    server.send(200, "text/html", page);
    digitalWrite(r1l1, LOW);
    delay(1000);
  });
  server.on("/r1l10", [](){
    server.send(200, "text/html", page);
    digitalWrite(r1l1, HIGH);
    delay(1000);
  });
    server.on("/r1l21", [](){
    server.send(200, "text/html", page);
    digitalWrite(r1l2, LOW);
    delay(1000);
  });
  server.on("/r1l20", [](){
    server.send(200, "text/html", page);
    digitalWrite(r1l2, HIGH);
    delay(1000);
  });
    server.on("/r1f1", [](){
    server.send(200, "text/html", page);
    digitalWrite(r1f, LOW);
    delay(1000);
  });
  server.on("/r1f0", [](){
    server.send(200, "text/html", page);
    digitalWrite(r1f, HIGH);
    delay(1000);
  });
    server.on("/r1c1", [](){
    server.send(200, "text/html", page);
    digitalWrite(r1c, LOW);
    delay(1000);
  });
  server.on("/r1c0", [](){
    server.send(200, "text/html", page);
    digitalWrite(r1c, HIGH);
    delay(1000);
  });
  
    server.on("/r1fs0", [](){
    server.send(200, "text/html", page);
    digitalWrite(r1f, HIGH);
    delay(1000);
  });
  server.on("/r1fs1", [](){
    server.send(200, "text/html", page);
    digitalWrite(fc0, HIGH);
    digitalWrite(fc1, HIGH);
    digitalWrite(fc2, HIGH);
    digitalWrite(fc3, HIGH);
    delay(1000);
  });
    server.on("/r1fs2", [](){
    server.send(200, "text/html", page);
    digitalWrite(fc0, HIGH);
    digitalWrite(fc1, HIGH);
    digitalWrite(fc2, HIGH);
    digitalWrite(fc3, HIGH);
    delay(1000);
  });
    server.on("/r1fs3", [](){
    server.send(200, "text/html", page);
    digitalWrite(fc0, HIGH);
    digitalWrite(fc1, HIGH);
    digitalWrite(fc2, HIGH);
    digitalWrite(fc3, HIGH);
    delay(1000);
  });
    server.on("/r1fs4", [](){
    server.send(200, "text/html", page);
    digitalWrite(fc0, HIGH);
    digitalWrite(fc1, HIGH);
    digitalWrite(fc2, HIGH);
    digitalWrite(fc3, HIGH);
    delay(1000);
  });
  server.begin();
  Serial.println("Web server started!");
}

 
void loop(void){
  server.handleClient();
}
