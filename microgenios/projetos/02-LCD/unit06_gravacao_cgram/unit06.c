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

void configMCU() {
#ifdef PIC18F45K22
    ANSELB = 0;
#else
    ADCON1 |= 0X0F;
#endif
}

void shift(unsigned char direction) {
    unsigned char ucX = 0;
    while(ucX<16) {
        Lcd_Cmd(direction);
        Delay_ms(70);
        ucX++;
    }             
}

const char character[] = {10,0,14,17,17,17,14,0};

void faceChar(char pos_row, char pos_char) {
  char i;
    Lcd_Cmd(64);
    for (i = 0; i<=7; i++) Lcd_Chr_CP(character[i]);
    Lcd_Cmd(_LCD_RETURN_HOME);
    Lcd_Chr(pos_row, pos_char, 0);
}

void main() {    
    configMCU();
    Lcd_Init();
    Lcd_Cmd(_LCD_CLEAR);
    Lcd_Cmd(_LCD_CURSOR_OFF);
    Lcd_Out(1,1,"MARCELO RIBEIRO DE");
    Lcd_Out(2,1,"SOUSA LIMA");
    shift(_LCD_SHIFT_RIGHT);
    shift(_LCD_SHIFT_LEFT);
    faceChar(2,12);     
}