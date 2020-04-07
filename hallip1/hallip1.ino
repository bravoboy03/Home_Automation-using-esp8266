#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
 
// Replace with your network credentials
const char* ssid = "tum jano";
const char* password = "password";
 
ESP8266WebServer server(80);   //instantiate server at port 80 (http port)
 
String page = "";
int htv = 12;
int hc = 13;
int hl = 14;
int hf = 15;
int fc0= ;
int fc1=;
int fc2=;
int fc3=;
void setup(void){
  //the HTML of the web page
  page = "<h1>Simple NodeMCU Web Server</h1><p><a href=\"l1on\"><button>ON</button></a>&nbsp;<a href=\"l1off\"><button>OFF</button></a></p>";
  //make the LED pin output and initially turned off
  pinMode(htv, OUTPUT);
  pinMode(hc, OUTPUT);
  pinMode(hl, OUTPUT);
  pinMode(hf, OUTPUT);
  pinMode(fc0, OUTPUT);
  pinMode(fc1, OUTPUT);
  pinMode(fc2, OUTPUT);
  pinMode(fc3, OUTPUT);
  digitalWrite(htv, HIGH);
  digitalWrite(hc, HIGH);
  digitalWrite(hl, HIGH);
  digitalWrite(hf, HIGH);
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
  server.on("/hf1", [](){
    server.send(200, "text/html", page);
    digitalWrite(hf, LOW);
    delay(1000);
  });
  server.on("/hf0", [](){
    server.send(200, "text/html", page);
    digitalWrite(hf, HIGH);
    delay(1000);
  });
    server.on("/hc1", [](){
    server.send(200, "text/html", page);
    digitalWrite(hc, LOW);
    delay(1000);
  });
  server.on("/hc0", [](){
    server.send(200, "text/html", page);
    digitalWrite(hc, HIGH);
    delay(1000);
  });
    server.on("/hl1", [](){
    server.send(200, "text/html", page);
    digitalWrite(hl, LOW);
    delay(1000);
  });
  server.on("/hl0", [](){
    server.send(200, "text/html", page);
    digitalWrite(hl, HIGH);
    delay(1000);
  });
    server.on("/htv1", [](){
    server.send(200, "text/html", page);
    digitalWrite(htv, LOW);
    delay(1000);
  });
  server.on("/htv0", [](){
    server.send(200, "text/html", page);
    digitalWrite(htv, HIGH);
    delay(1000);
  }); 
  server.on("/hfs0", [](){
    server.send(200, "text/html", page);
    digitalWrite(hf, HIGH);
    delay(1000);
  });
  server.on("/hfs1", [](){
    server.send(200, "text/html", page);
    digitalWrite(fc0, HIGH);
    digitalWrite(fc1, HIGH);
    digitalWrite(fc2, HIGH);
    digitalWrite(fc3, HIGH);
    delay(1000);
  });
    server.on("/hfs2", [](){
    server.send(200, "text/html", page);
    digitalWrite(fc0, HIGH);
    digitalWrite(fc1, HIGH);
    digitalWrite(fc2, HIGH);
    digitalWrite(fc3, HIGH);
    delay(1000);
  });
    server.on("/hfs3", [](){
    server.send(200, "text/html", page);
    digitalWrite(fc0, HIGH);
    digitalWrite(fc1, HIGH);
    digitalWrite(fc2, HIGH);
    digitalWrite(fc3, HIGH);
    delay(1000);
  });
    server.on("/hfs4", [](){
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
