// RB0 -> TECLA
// RD0 -> LED

unsigned char uContador = 0;

void incremento(unsigned char contador) {
  switch(contador) {
    case 1: {PORTD.RD0 = 1; break;}
    case 2: {PORTD.RD1 = 1; break;}
    case 3: {PORTD.RD2 = 1; break;}
    case 4: {PORTD.RD3 = 1; break;}
    default: {PORTD = 0; uContador = 0; break;}
  }
}

void main() {
  unsigned char flagAux = 0;

  // Diretivas de pré-compilação
  #ifdef P1C8F45K22
    ANSELB = 0; // Conf. todos os pinos PORTB como digital
    ANSELD = 0; // Conf. todos os pinos PORTD como digital
  #else
    ADCON1 |= 0X0F; // Config. todos os pinos ADC como digital Ex: 18F4520
  #endif

  //TECLA
  TRISB.RB0 = 1; // Conf. RB0 para ENTRADA
  PORTB.RB0 = 0; // Joga nível lógico zero

  //LED
  TRISD = 0; // Conf RD0 para SAIDA
  PORTD = 0; // LED off

  while(1) {
    if(PORTB.RB0 == 1 && flagAux == 0)  { // Clicked and flagAux == 0
      incremento(++uContador);
      flagAux == 1;
      Delay_ms(220); // tratamento de debounce
    }
    if(PORTB.RB0 == 0 && flagAux == 1) { // Not clicked and flagAux == 1
      flagAux == 0;
      Delay_ms(220); // tratamento de debounce
    }
  }
}