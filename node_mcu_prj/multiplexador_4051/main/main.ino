/*
* static const uint8_t D6   = 12;
* static const uint8_t D7   = 13;
* static const uint8_t D8   = 15;
*/


int sensorValue;

#define A 12 // D6
#define B 13 // D7
#define C 15 // D8

boolean flag = true;

void setup()
{
    Serial.begin(9600);
// seta os pinos select como saída
    pinMode(A,OUTPUT);
    pinMode(B,OUTPUT);
    pinMode(C,OUTPUT);
// 100
    digitalWrite(A,0);
    digitalWrite(B,0);
    digitalWrite(C,1); // Bit mais significativo
}

void loop()
{
    if(flag) {
      // 100
      digitalWrite(A,0);
      digitalWrite(B,0);
      digitalWrite(C,1); // Bit mais significativo
    } else {
      // 110
      digitalWrite(A,0);
      digitalWrite(B,1);
      digitalWrite(C,1); // Bit mais significativo
    }
    delay(300);
    sensorValue=analogRead(A0);
    delay(300);
    if(flag) {
      Serial.print("Analog 01: ");
    } else {
      Serial.print("Analog 02: ");  
    }    
    Serial.println(sensorValue);
    Serial.println(sensorValue * (3.3 / 1024));
    flag = !flag;
    /*
    for (int i=0; i<2; i++)
    {
// pega os bits do contador e coloca nas variáveis a serem enviadas. 
    r0=bitRead(i,0);
// envia os bits para as respectivas portas select (s0 a s3 no CI)
    //digitalWrite(ps0,r0);
    digitalWrite(ps0,4);
//  em seguida, lê o valor do sensor correspondente, que vai estar disponível no pino A0
    
//  exibe os valores lidos, por sensor
    Serial.print("i: ");
    Serial.println(i);
    Serial.print("BINARIO: ");
    Serial.println(r0,BIN);
    Serial.print("Analog: ");
    Serial.println(sensorValue);
    delay(1000);
    Serial.println("-------------------------");
    }
    Serial.println("*************************");
    */
}
