#define TRUE 1
#define BTN_UP PORTB.RB0
#define BTN_DWN PORTB.RB1

void initConfig() {
    #ifdef PIC18F45K22
        ANSELD = 0;
        ANSELB = 0;
    #else
        ADCON1 |= 0X0F; // Config. todos os pinos ADC como digital Ex: 18F4520
    #endif

    //UP
    TRISB.RB0 = 1; // 1 para entrada
    PORTB.RB0 = 0;

    //DOWN
    TRISB.RB1 = 1;
    PORTB.RB1 = 0;

    //LED
    TRISD = 0; // Conf RD0 para SAIDA
    PORTD = 0; // LED off

    //LED INDICADOR
    TRISC = 0;
    PORTC.RC0 = 0;
    PORTC.RC6 = 0;
}

void main() {
    unsigned char flagAuxUP = 0, flagAuxDOWN = 0;
    unsigned int mask = 0B00000001;
    initConfig();
    while(1) {
        if(BTN_UP == 1 && flagAuxUP == 0) {
            if(LATD == 0) {
                PORTD = mask;
            } else {
                PORTD = mask << 1;   
            }
            flagAuxUP = 1;
            PORTC.RC0 = 1;
            PORTC.RC6 = 0;       
            Delay_ms(500);
        }
        if(BTN_UP == 0 && flagAuxUP == 1) {
            flagAuxUP = 0;
            PORTC.RC0 = 0;
            PORTC.RC6 = 1;
            Delay_ms(500);
        }
    }
}