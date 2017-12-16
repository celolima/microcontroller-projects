#define LED_VERDE 2
#define LED_AMARELO 3
#define LED_VERMELHO 4
#define LED_AZUL 5
#define TAMANHO_SEQUENCIA 4
#define UM_SEGUNDO 1000
#define MEIO_SEGUNDO 500

int sequenciaLuzes[TAMANHO_SEQUENCIA];

void setup(){
  Serial.begin(9600);  
  iniciaPortas();
  iniciaJogo();  
}

void loop(){
  for (int i = 0; i < TAMANHO_SEQUENCIA; i++) {
    piscaLed(sequenciaLuzes[i]);
  }
}

void iniciaJogo() {
  for (int i = 0; i < TAMANHO_SEQUENCIA; i++) {
    sequenciaLuzes[i] = sorteiaCor();
  }
}


int sorteiaCor() {
  return random(LED_VERDE, LED_AZUL + 1);
} 

void iniciaPortas() {
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
}

void piscaLed(int portaLed) {

  digitalWrite(portaLed,HIGH);
  delay(UM_SEGUNDO);
  digitalWrite(portaLed,LOW);
  delay(MEIO_SEGUNDO);  
}
