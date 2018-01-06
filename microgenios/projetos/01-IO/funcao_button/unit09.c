/*
 * Utilização da função Button do MIkroC
 * A função elimina a  influência do deboucing
 */

void main() {
 #ifdef P18F45K22
  ANSELB = 0;
  ANSELD = 0;
  INTCON2.RBPU = 0; // Habilita pull-up presentes
  WPUB.WPUB0 = 1; // Ativa o resistor pull-up no pino RB0 
 #else
  ADCON1 |= 0X0F; // Exerce o msm papel o ANSELx, porém hab. ou desab. todos os ADCs presentes no PIC
  INTCON2.RBPU = 0; // Habilita todos os pull-ups presentes  no PORTB
 #endif
 
 TRISB.RB0 = 1; // Config. como entrada
 PORTB.RB0 = 1; // Opcional, nível alto no RB0

 TRISD = 0; // Todas os pinos do PORTD como SAIDA;
 PORTD = 0; // Todos Leds Off
 
 while(1) {
  // Porta, Pino, Delay, ESTADO_ATIVACAO
  if(Button(&PORTB,0,50,0)) {
    PORTD.RD0 ^= 1;
  }
 }
}