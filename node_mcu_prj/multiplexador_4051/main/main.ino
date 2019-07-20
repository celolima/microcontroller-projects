/*
* static const uint8_t D6   = 12;
* static const uint8_t D7   = 13;
* static const uint8_t D8   = 15;
*/

int sensorValue;

unsigned long currentMillis = 0;
long previousMillis = 0;        // Variável de controle do tempo
long redLedInterval = 250;     // Tempo em ms do intervalo a ser executado

#define ANALOG_PORT A0
#define A 4 // D2
#define B 1 // D3
#define C 2 // D4 - Bit mais significativo

boolean flag = true;

void setup()
{
  Serial.begin(115200);
    Serial.println("teste ");
// seta os pinos select como saída
    pinMode(A,OUTPUT);
    pinMode(B,OUTPUT);
    pinMode(C,OUTPUT);
}

void loop()
{
     delay(5000);
     Serial.println("teste ");
  /*
    if(flag) {
      // 000
      digitalWrite(A,0);
      digitalWrite(B,0);
      digitalWrite(C,0); // Bit mais significativo
    } else {
      // 110
      digitalWrite(A,0);
      digitalWrite(B,1);
      digitalWrite(C,1); // Bit mais significativo
    }
    currentMillis = millis();    //Tempo atual em ms
    //Lógica de verificação do tempo
    if (currentMillis - previousMillis > redLedInterval) {
      previousMillis = currentMillis;    // Salva o tempo atual  
      sensorValue=analogRead(ANALOG_PORT);
    }   
    delay(5000);
    if(flag) {
      Serial.print("Analog 01: ");
    } else {
      Serial.print("Analog 02: ");  
    }    
    Serial.print(sensorValue);
    Serial.print(" --------- Tensão: ");
    Serial.println(sensorValue * (3.3 / 1024));
    //flag = !flag;
    */
}
