/* 
    OverflowTime = periodo_ciclo_maq * prescaler * (mod_16bits - valor_inicial)

    calculo para cada segundo:

    1000000 = 0.5us * 128 (prescaler) * (65535 - valor_inicial)
    valor_inicial = 49910, ou em haxa = C2F7
*/

void reiniciaTIMER() {
    TMR0L = 0XF7;
    TMR0H = 0XC2;
    INTCON.TMR0IF = 0;
}

void main() {
    T0CON = 0B00000110;
    T0CON.TMR0ON = 1; // liga o TIMER0
    while(TRUE) {        
        PORTD.RD0 = ~LATD.RD0; // Altera valor do LED
        while(INTCON.TMR0IF == 0); // Aguarda o TIMER ir para nível alto
        reiniciaTIMER();
    }
}