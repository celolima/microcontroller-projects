const byte interruptPin = 13;
volatile byte interruptCounter = 0;
int numberOfInterrupts = 0;

unsigned long timeFirst = 0;
unsigned long timeSecond = 0;

unsigned long total = 0;
double finalFreq = 0;
byte clk = 1;

void setup() {
  Serial.begin(115200);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), handleInterrupt, FALLING);
}
 
void handleInterrupt() {     
  if(clk == 1) {
    timeFirst = millis();    
    clk++;
  } else if(clk == 2) {
    timeSecond = millis();
    total = (timeSecond - timeFirst);
    finalFreq = (double)( (double)1/((double)total/(double)1000) );
    clk = 1;
    Serial.print("Frequência:\t");
    Serial.println(finalFreq);
  }
  interruptCounter++;
}
 
void loop() {      
  if(interruptCounter>0){
 
      interruptCounter--;
      numberOfInterrupts++;
 /*
      Serial.print("An interrupt has occurred. Total: ");
      Serial.println(numberOfInterrupts);
*/
  }
 
}

