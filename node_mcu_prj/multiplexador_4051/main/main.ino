/*
* static const uint8_t D6   = 12;
* static const uint8_t D7   = 13;
* static const uint8_t D8   = 15;
*/

int sensorValue;

#define A 12 // D6
#define B 13 // D7
#define C 15 // D8
#define PIEZO 14 // D5

boolean flag = true;

void setup()
{
    Serial.begin(9600);
// seta os pinos select como saída
    pinMode(A,OUTPUT);
    pinMode(B,OUTPUT);
    pinMode(C,OUTPUT);
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
    //tone(PIEZO, sensorValue, sensorValue);
}
