/*
  MqttClientPublisher.h - Library to configure and publish on MQTT borker by ESP8266
  Created by Marcelo Lima, April 18, 2018.
*/

#ifndef MqttClientPublisher_h
#define MqttClientPublisher_h

#include "Arduino.h"
#include "MqttClientPublisher.h"

class MqttClientPublisher
{
  public:
    MqttClientPublisher(char* server, int port, WiFiClient espClient);
    boolean publish(char* topic);
    void connect();    
    boolean isConnected();
  private:    
    void reconnect();
    Client _client;
};

#endif