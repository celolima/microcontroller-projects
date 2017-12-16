#include <ESP8266WiFi.h>
 
const char* ssid = "DEUS";
const char* password = "filo2017";
 
int ledPin = 14; // GPIO16
WiFiServer server(80);
 
void setup() {
  Serial.begin(9600);
  delay(10);
 
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if(client) {
    clientConnection(client);
  } else {
    Serial.print(".");
    delay(1000);
  }
}

void clientConnection(WiFiClient client) {
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Match the request
  int value = 9;
  if (request.indexOf("/LED=ON") != -1)  {
    digitalWrite(ledPin, HIGH);
    value = HIGH;
  } else if (request.indexOf("/LED=OFF") != -1) {
    digitalWrite(ledPin, LOW);
    value = LOW;
  }
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head><style>*{ font-family: arial; } .on {color:green;} .off {color:red;}</style></head>");
  client.println("<body>");
 
  client.print("Led pin is now: ");
 
  if(value == HIGH) {
    client.print("<span class=\"on\">On</span>");
  } else if(value == LOW){
    client.print("<span class=\"off\">Off</span>");
  } else {
    client.print("<span>Undefined</span>");
  }
  
  client.println("<br /><br />");
  client.println("<a href=\"/LED=ON\"\"><button>ON</button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button>OFF</button></a><br />");  
  client.println("</body>");
  client.println("</html>");

  Serial.println("Client response finished");
  Serial.println("");
}

