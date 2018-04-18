/*
  Conecta.h - Library for connecting on Wi-fi by ESP8266
  Created by Marcelo Lima, April 18, 2018.
*/

#include <ESP8266WiFi.h>
#include "Arduino.h"
#include "Conecta.h"

Conecta::Conecta(char* ssid, char* passwd) {
    _ssid = ssid;
    _passwd = passwd;
}

void Conecta::setupWifi() {
  // We start by connecting to a WiFi network

  Serial.print("Connecting to: ");
  Serial.println(_ssid);

  WiFi.begin(_ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("WiFi connected -- ");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

boolean Conecta::isConnected() {
    return WiFi.status() == WL_CONNECTED;
}

WiFiClient Conecta::getClient() {
    reutrn WiFiClient();
}