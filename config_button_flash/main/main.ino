#define BUTTON_PIN 0

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {  
  if(BUTTON_PIN) {
    Serial.println("pressionado");
  } else {
    Serial.println("solto");
  }
  delay(3000);
}
