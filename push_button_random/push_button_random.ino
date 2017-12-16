#define LED_VERDE 5
#define LED_VERMELHO 4
#define LED_AMARELO 3
#define LED_BRANCO 2

#define BTN_ON_VERDE 12
#define BTN_ON_VERMELHO 11
#define BTN_ON_AMARELO 10
#define BTN_ON_BRANCO 9

#define POTENCIOMETRO_PORT 5
#define UM_SEGUNDO 1000
#define MEIO_SEGUNDO 500
#define TAMANHO_ARRAY 4

enum Estados {
  PRONTO_PARA_PROXIMA_RODADA,
  USUARIO_RESPONDENDO,
  JOGO_FINALIZADO_SUCESSO,
  JOGO_FINALIZADO_FALHA
};

int sequenciaLuzes[TAMANHO_ARRAY];
int sequenciaBotoes[] = {BTN_ON_VERDE, BTN_ON_VERMELHO, BTN_ON_AMARELO, BTN_ON_BRANCO};
int sequenciaResposta[TAMANHO_ARRAY];

Estados estado = PRONTO_PARA_PROXIMA_RODADA;

int rodada = 0;

void setup() {
  Serial.begin(9600);
  iniciaJogo();
  inicializaLED();
  inicializaBTNS();
}

void loop() {
  switch (estado) {
    case PRONTO_PARA_PROXIMA_RODADA:
      Serial.println("Pronto para a proxima rodada");
      preparaNovaRodada();
      break;
    case USUARIO_RESPONDENDO:
      Serial.println("Jogador respondendo");
      leituraBTN();
      break;
    case JOGO_FINALIZADO_SUCESSO:
      Serial.println("Jogo finalizado com sucesso");
      break;
    case JOGO_FINALIZADO_FALHA:
      Serial.println("Jogo finalizado com falha");
      break;
  }
  delay(MEIO_SEGUNDO);
}

void preparaNovaRodada() {
  if(rodada == TAMANHO_ARRAY) {
    estado = JOGO_FINALIZADO_SUCESSO;  
  } else {
    rodada++;
    tocaLedsRodada();
    estado = USUARIO_RESPONDENDO;
  }
}

void tocaLedsRodada() {
  for (int i = 0; i < rodada; i++) {
    piscaLed(sequenciaLuzes[i]);
  }
}

int piscaLed(int portaLed) {

  digitalWrite(portaLed,HIGH);
  delay(UM_SEGUNDO);
  digitalWrite(portaLed,LOW);
  delay(MEIO_SEGUNDO);

  return portaLed;
}

void iniciaJogo() {  
  int led;
  int seed = analogRead(POTENCIOMETRO_PORT);
  randomSeed(seed);
  for(int indicie = 0; indicie < TAMANHO_ARRAY; indicie ++) {
    led = sorteiaCor();
    sequenciaLuzes[indicie] = led;
  }
}

int sorteiaCor() {
  int rando = (int)random(LED_BRANCO, LED_VERDE + 1);//2-5 (6)
  return contemValor(rando) ? sorteiaCor() : rando;
}

boolean contemValor(int value) {
  for(int indicie = 0; indicie < TAMANHO_ARRAY; indicie ++) {
    if(sequenciaLuzes[indicie] == value) return true;
  }
  return false;
}

void leituraBTN() {
 int estadoBotao;
 boolean isRespondeu = false;

 while(!isRespondeu) {
   for(int i=0;i<4;i++) {
    estadoBotao = digitalRead(sequenciaBotoes[i]); 
    if(estadoBotao == LOW) {
      isRespondeu = true;
      piscaLed(sequenciaLuzes[i]);
      //sequenciaResposta[] = sequenciaLuzes[i];
    }
   }
 }

 //estado = !isRespondeu ? USUARIO_RESPONDENDO : isRespostaCorreta ? PRONTO_PARA_PROXIMA_RODADA : JOGO_FINALIZADO_FALHA;
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
