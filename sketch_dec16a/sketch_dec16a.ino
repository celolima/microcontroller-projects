int ledPin = 14; // GPIO14 - D5

void setup() { 
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  delay(1000);
  Serial.println(F("SETUP")); 
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
  Serial.println(analogRead(A0));  
}
