#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include <time.h>
#include <stdlib.h>

const char* ssid = "PERICLES";
const char* password = "12345678";
const char* mqtt_server = "iot.eclipse.org";
const char* topic = "/dev-15/tensão/0c27556f-a1b0-4d54-bcc2-255dc8f1b185";

WiFiClient espClient;
PubSubClient client(espClient);

long lastMsg = 0;
char msg[50];
int value = 0;

void setup() {  
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  
  client.loop();

  long now = millis();

  // A cada X segundos  
  
  if (now - lastMsg > 7000) {
    lastMsg = now;
    getAnalogVal();
    snprintf(msg, 75, "%f", getAnalogVal());
    Serial.println("Publish message: ");
    Serial.print(msg);
    client.publish(topic, msg);
  }
}

float getAnalogVal() {
    // read the input on analog pin 0:
    int sensorValue = analogRead(A0);
    // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
    float voltage = sensorValue * (5.0 / 1023.0);
    // print out the value you read:
    return voltage;
}

void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
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
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      
      // Once connected, publish an announcement...
      client.publish(topic, "Im Alive!");
    } else {
      Serial.print("failed, rc = ");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
