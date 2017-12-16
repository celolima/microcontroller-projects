#define LED_VERDE 5
#define LED_VERMELHO 4
#define LED_AMARELO 3
#define LED_BRANCO 2

#define BTN_ON_VERDE 12
#define BTN_ON_VERMELHO 11
#define BTN_ON_AMARELO 10
#define BTN_ON_BRANCO 9

#define MEIO_SEGUNDO 500

int sequenciaLuzes[] = {LED_VERDE, LED_VERMELHO, LED_AMARELO, LED_BRANCO};
int sequenciaBotoes[] = {BTN_ON_VERDE, BTN_ON_VERMELHO, BTN_ON_AMARELO, BTN_ON_BRANCO};
int total = 10;

void setup() {
  Serial.begin(9600);
  inicializaLED();
  inicializaBTNS();
}

void loop(){
  leituraBTN();
}

void leituraBTN() {
 int estadoBotao;
 for(int i=0;i<4;i++) {
  estadoBotao = digitalRead(sequenciaBotoes[i]); 
  if(estadoBotao  == 0) {
    digitalWrite(sequenciaLuzes[i],HIGH);
    delay(MEIO_SEGUNDO);
    digitalWrite(sequenciaLuzes[i],LOW);
  }
 }
}

void inicializaLED() {
 for(int i=0;i<4;i++) {
  pinMode(sequenciaLuzes[i],OUTPUT);
 }
}

void inicializaBTNS() {
 for(int i=0;i<4;i++) {
  pinMode(sequenciaBotoes[i],INPUT_PULLUP);
 }
}
