#define LED_VERDE 7
#define LED_VERMELHO 5
#define LED_AMARELO 3
#define LED_BRANCO 2
#define MEIO_SEGUNDO 500

int sequenciaLuzes[] = {LED_VERDE, LED_VERMELHO, LED_AMARELO, LED_BRANCO};
int total = 10;

void setup() {
  Serial.begin(9600);
  inicializaLED();
}

void loop(){
 for(int i=0;i<4;i++) {
  digitalWrite(sequenciaLuzes[i],HIGH);
  delay(MEIO_SEGUNDO);
  digitalWrite(sequenciaLuzes[i],LOW);
 }
 delay(MEIO_SEGUNDO);

 if(total-- < 0) {
  exit(0);
 }
}

void inicializaLED() {
 for(int i=0;i<4;i++) {
  pinMode(sequenciaLuzes[i],OUTPUT);
 }
}
