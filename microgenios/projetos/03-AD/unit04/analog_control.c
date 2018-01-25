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

void main() {

 unsigned int leitura_ADC;
 unsigned char texto[10];

 #ifdef PIC18F45K22
    ANSELA.B0 = 1; // Somente RA0/An0 como ADC;
    ANSELB = 0; // Como digital
 #endif

 TRISA.RA0 = 1; // Entrada do trimpot, usando o AN0
 PORTA.RA0 = 1; // Opcional, estado alto
 ADCON0 = 0B00000001; // Controle de registro vazio-vazio-canal(ANO)-0-Liga_mod_AD
 ADCON1 = 0B00001110; // Define referencia/Define quais pinos na porta são digitais e analógicos
 ADCON2 = 0B10101010; // Justifica_direita/Define TAD's 12Tads/Conversion_Clock(Fosc/32)
 
 Lcd_Init();
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);
 Lcd_Out(1,1,"ADC:");

 while(1) {
  ADCON0.GO_DONE = 1; // Inicio do processo de conversão

  while(ADCON0.GO_DONE == 1) ; // Aguarda até o término da conversão

  /* Agora pode ler adress hi e low, envio para o display LCD
    amplia o ADRESHI para 16 bits em memória, empurra os 8 bits / ex: 11101101 00000000
    e 'soma' com ADRESLOW;
    VAI ATÈ 1023, pois a resolução é de 10 bits, sendo 2^10 = 1023
  */
 
  leitura_ADC = (ADRESH << 8); // Empura os bits do ADRESHI, convertendo para 16 bits
  leitura_ADC = leitura_ADC | ADRESL; // 'Soma' com o valor do ADRESHI, convertendo para 16 bits e salva na variável

  WordToStr(leitura_ADC, texto);
  LCD_Out(1,5,Texto);
  Delay_ms(20);
   
 }


}