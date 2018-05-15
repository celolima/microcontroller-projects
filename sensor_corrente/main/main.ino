//Baseado no programa exemplo da biblioteca EmonLib

//Carrega as bibliotecas
#include "EmonLib.h"

EnergyMonitor emon1;

//Pino do sensor SCT
int pino_sct = 0;

void setup() 
{
  Serial.begin(9600);
  //Pino, calibracao - Cur Const= Ratio/BurdenR. 1800/62 = 29. 
  emon1.current(pino_sct, 20);
} 
 
void loop() 
{ 
  //Calcula a corrente  
  double Irms = emon1.calcIrms(1480);
  Serial.println(Irms);
  delay(1000);
}
