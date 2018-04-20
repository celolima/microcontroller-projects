#include <Conecta.h>
#include <MqttClientPublisher.h>

const char* ssid = "DEUS";
const char* password = "filo2017";
const char* mqtt_server = "test.mosquitto.org";
const int mqtt_port = 1883;
const char* topic = "/device01/sensor04";
int counter = 0;

Conecta conecta(ssid, password);
MqttClientPublisher mqtt(mqtt_server, mqtt_port, conecta.getClient());

void setup() {
  Serial.begin(115200);
  Serial.println(" --- Inicializando a aplicação ESP8266 --- ");
}

void loop() {

  if(isReady) {
    
  }

  long now = millis();
  if (now - lastMsg > 4000) {
    lastMsg = now;
    mqtt.publish(topic, ++counter);
  }
}

boolean isReady() {
  boolean isOk = true;

  if (!conecta.isConnected()) {
    isOk = false;
    // Pisca led de conexão Wifi;  
    conecta.setupWifi();    
  } else {
    // Acende led de conexão Wifi;
  }

  if (!mqtt.isConnected()) {
    isOk = false;
    // Pisca led de conexão com o broker;
    mqtt.connect();
  } else {
    // Acende led de conexão com o broker;
  }
  return isOk;
}