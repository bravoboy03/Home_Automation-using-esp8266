#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
 
// Replace with your network credentials
const char* ssid = "tum jano";
const char* password = "password";
 
ESP8266WebServer server(80);   //instantiate server at port 80 (http port)
 
String page = "";
int kro = 12;
int kl = 13;
int kf = 14;
int kc = 15;
void setup(void){
  //the HTML of the web page
  page = "<h1>Simple NodeMCU Web Server</h1><p><a href=\"l1on\"><button>ON</button></a>&nbsp;<a href=\"l1off\"><button>OFF</button></a></p>";
  //make the LED pin output and initially turned off
  pinMode(kro, OUTPUT);
  pinMode(kl, OUTPUT);
  pinMode(kf, OUTPUT);
  pinMode(kc, OUTPUT);
  pinMode(fc0, OUTPUT);
  pinMode(fc1, OUTPUT);
  pinMode(fc2, OUTPUT);
  pinMode(fc3, OUTPUT);
  digitalWrite(kro, HIGH);
  digitalWrite(kl, LOW);
  digitalWrite(kf, HIGH);
  digitalWrite(kc, LOW);
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
  server.on("/kro1", [](){
    server.send(200, "text/html", page);
    digitalWrite(kro, LOW);
    delay(1000);
  });
  server.on("/kro0", [](){
    server.send(200, "text/html", page);
    digitalWrite(kro, HIGH);
    delay(1000);
  });
    server.on("/kl1", [](){
    server.send(200, "text/html", page);
    digitalWrite(kl, LOW);
    delay(1000);
  });
  server.on("/kl0", [](){
    server.send(200, "text/html", page);
    digitalWrite(kl, HIGH);
    delay(1000);
  });
    server.on("/kf1", [](){
    server.send(200, "text/html", page);
    digitalWrite(kf, LOW);
    delay(1000);
  });
  server.on("/kf0", [](){
    server.send(200, "text/html", page);
    digitalWrite(kf, HIGH);
    delay(1000);
  });
    server.on("/kc1", [](){
    server.send(200, "text/html", page);
    digitalWrite(kc, LOW);
    delay(1000);
  });
  server.on("/kc0", [](){
    server.send(200, "text/html", page);
    digitalWrite(kc, HIGH);
    delay(1000);
  });
  
    server.on("/kfs0", [](){
    server.send(200, "text/html", page);
    digitalWrite(hf, HIGH);
    delay(1000);
  });
  server.on("/kfs1", [](){
    server.send(200, "text/html", page);
    digitalWrite(fc0, HIGH);
    digitalWrite(fc1, HIGH);
    digitalWrite(fc2, HIGH);
    digitalWrite(fc3, HIGH);
    delay(1000);
  });
    server.on("/kfs2", [](){
    server.send(200, "text/html", page);
    digitalWrite(fc0, HIGH);
    digitalWrite(fc1, HIGH);
    digitalWrite(fc2, HIGH);
    digitalWrite(fc3, HIGH);
    delay(1000);
  });
    server.on("/kfs3", [](){
    server.send(200, "text/html", page);
    digitalWrite(fc0, HIGH);
    digitalWrite(fc1, HIGH);
    digitalWrite(fc2, HIGH);
    digitalWrite(fc3, HIGH);
    delay(1000);
  });
    server.on("/kfs4", [](){
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
