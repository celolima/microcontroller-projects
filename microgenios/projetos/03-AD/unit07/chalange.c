/* Desafio
Leitura de dois trimpots, e apresente da seguinte forma:

1- linha S1: xxxx // formatação 0  100%
2- linha S2: xxxx // formatação 0 a 255
*/

/*Configuração dos pinos do LCD*/
sbit LCD_RS at LATB4_bit;
sbit LCD_EN at LATB5_bit;
sbit LCD_D4 at LATB0_bit;
sbit LCD_D5 at LATB1_bit;
sbit LCD_D6 at LATB2_bit;
sbit LCD_D7 at LATB3_bit;

sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;


// AN0/RA0 -> TRIMPOT -> LER o TRIMPOT
// Tensão de referência interna -> 0v ao 3.3v

void configADC() {
 // Configuração do primeiro trimpot AN0
 TRISA.RA0 = 1; // Entrada do trimpot, usando o AN0
 PORTA.RA0 = 1; // Opcional, estado alto

 // Configuração do segundo trimpot AN14
 TRISC.RC2 = 1; // Entrada do trimpot, usando o AN14
 PORTA.RC2 = 1; // Opcional, estado alto

 // Configuração padrão
 ADCON1 = 0B00001110; // Define referencia/Define quais pinos na porta são digitais e analógicos
 ADCON2 = 0B10101010; // Justifica_direita/Define TAD's 12Tads/Conversion_Clock(Fosc/32)     
}

int leituraADC(unsigned char canal) {
 if(canal==0) {
  ADCON0 = 0B00000001; // Controle de registro vazio-vazio-canal(ANO)-0-Liga_mod_AD
 } else if(canal==1){
  ADCON0 = 0B00111001;
 }
  while(ADCON0.GO_DONE == 1) ; // Aguarda até o término da conversão
  return (ADRESH << 8) | ADRESL;
}

void initLCD() {
 Lcd_Init();
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);
 Lcd_Out(1,1,"1 - Trim:");
 Lcd_Out(2,1,"2 - Trim:");
}

void main() {

 unsigned int leitura_ADC;
 unsigned char texto[10];
 unsigned char chanel = 0;

 #ifdef PIC18F45K22
    ANSELA.A0 = 1; // Somente RA0/AN0 como ADC;
    ANSELC.C2 = 1; // Somente RC2/AN14 como ADC;
    ANSELB = 0; // Como digital
 #endif
    
 configADC();
 initLCD();

 while(1) {
  ADCON0.GO_DONE = 1; // Inicio do processo de conversão
  WordToStr(leituraADC(chanel), texto);
  LCD_Out(chanel == 0 ? 1 : 2,10,Texto);
  Delay_ms(20);
  chanel = !chanel;
 }
}