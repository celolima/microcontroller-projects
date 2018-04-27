#include <Mux.h>
#define LED_BUILTIN 2
byte porta = 4;
Mux mux;
void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(porta == 4) {
    porta = 6;
  } else {
    porta = 4;
  }
  Serial.print("Porta: ");
  Serial.print(porta);
  Serial.print(" ----- ");
  Serial.println(mux.getAnalogValue(porta));
  Serial.print(mux.getConvertedAnalogValue(porta, 3.3));
  Serial.println("V");
  //blinkLed();
  delay(3000);
}

void blinkLed() {
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
}
