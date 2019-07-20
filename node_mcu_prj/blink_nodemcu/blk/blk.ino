#include "EmonLib.h"
#include "Thermistor.h"

#define ANALOG_PORT A0
#define A 2 // D2 
#define B 0 // D3
#define C 4 // D4 - Bit mais significativo
int sensorValue;
int PINLED = 14;
boolean led = false;
//EnergyMonitor emon1;
Thermistor temp(ANALOG_PORT);


// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(14, OUTPUT);
  Serial.println("Inicializando");

    
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);

  digitalWrite(A,0); 
  digitalWrite(B,0);
  digitalWrite(C,1); // Bit mais significativo
  //emon1.current(ANALOG_PORT, 20);
}

// the loop function runs over and over again forever
void loop() {
  sensorValue=analogRead(ANALOG_PORT);
  delay(800);
  Serial.print("Analog 01: ");
  Serial.println(sensorValue);  
  /*
  Serial.print(" --------- Tensão: ");
  Serial.println(sensorValue * (3.3 / 1024));  
  */
  //Serial.println(emon1.calcIrms(1480));
  Serial.println((double)temp.getTemp());
  digitalWrite(13,led); 
  digitalWrite(12,led); 
  digitalWrite(14,led);
  
  led = !led;
}
