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

#define PORTD.RD0 BTN_CHANGE
#define PORTD.RD1 BTN_SELECT
#define PORTD.RD1 BTN_RETURN
#define 1 TRUE

void configMCU() {
/*  ANSEL
    1 - Para analógico
    0 - Para digital
*/
#ifdef PIC18F45K22
    ANSELB = 0;
    ANSELD = 0;
#else
    ADCON1 |= 0X0F;
#endif

//  TRIS: entrada(1) ou saída(0)
TRISD.RD0 = 1;
TRISD.RD1 = 1;
TRISD.RD2 = 1;
}

void printTelaInicial(char *val) {
    Lcd_Cmd(_LCD_CLEAR);
    Lcd_Cmd(_LCD_CURSOR_OFF);
    Lcd_Out(1,1,"> opcao 1");
    Lcd_Out(2,3,"opcao 2");
    *val = 0;
}

void main() {
    unsigned char auxMenu = 0;
    configMCU();
    Lcd_Init();
    printTelaInicial();
    /*
        0 - OPCAO_1
        1 - OPCAO_2
    */
    while(TRUE) {
        // Porta, Pino, Delay, ESTADO_ATIVACAO
        if(Button(&PORTD,0,50,0)) { // CHANGE
            auxMenu = !auxMenu;
            if(!auxMenu) {
                Lcd_Out(1,1,">");
            } else {
                Lcd_Out(2,1,">");
            }
        }
        else if(Button(&PORTD,1,50,0)) { // SELECT
            
            Lcd_Cmd(_LCD_CLEAR);
            Lcd_Out(2,1,"> Retorno");

            if(auxMenu) {
                Lcd_Out(1,3,"Opcao 2 selected");
            } else {
                Lcd_Out(1,3,"Opcao 1 selected");
            }
        }
        else if(Button(&PORTD,2,50,0)) { // RETURN
            printTelaInicial(&auxMenu);
        }
    }
}