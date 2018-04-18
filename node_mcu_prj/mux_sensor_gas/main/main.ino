/*
* static const uint8_t D6   = 12;
* static const uint8_t D7   = 13;
* static const uint8_t D8   = 15;
*/

int sensorValue;

#define A 12 // D6
#define B 13 // D7
#define C 15 // D8
#define MQ2 16 // SD2

void setup()
{
    Serial.begin(9600);
// seta os pinos select como saída
    pinMode(A,OUTPUT);
    pinMode(B,OUTPUT);
    pinMode(C,OUTPUT);
    
    pinMode(A0,INPUT);
    pinMode(MQ2,INPUT);
// config pin 4 do 4051 do MUX
    digitalWrite(A,0);
    digitalWrite(B,0);
    digitalWrite(C,1); // Bit mais significativo    
}

void loop()
{
  // Le os dados do pino digital D0 do sensor
  int valor_digital = digitalRead(MQ2);
  // Le os dados do pino analogico A0 do sensor
  //delay(3000);
  int valor_analogico = analogRead(A0);
  //delay(3000);
  // Mostra os dados no serial monitor
  Serial.print("Pino Mq2 : ");
  Serial.print(valor_digital);
  Serial.print(" Pino A0 : ");
  Serial.println(valor_analogico);
}
