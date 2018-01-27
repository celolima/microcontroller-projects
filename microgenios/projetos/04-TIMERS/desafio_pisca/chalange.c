/* 
    OverflowTime = periodo_ciclo_maq * prescaler * (mod_16bits - valor_inicial)

    calculo para cada segundo:

    1000000 = 0.5us * 128 (prescaler) * (65535 - valor_inicial)
    valor_inicial = 49910, ou em hexa = C2F7
*/

#define TRUE 1

void reiniciaTIMER() {
    TMR0L = 0XE8;
    TMR0H = 0X03;
    INTCON.TMR0IF = 0;
}

void main() {
    ANSELD = 0;
    TRISD = 0;     //todos os pinos do PORTD como saida
    PORTD = 0;     //all LEDs OFF
    T0CON = 0B00000110;
    T0CON.TMR0ON = 1; // liga o TIMER0

    while(TRUE) {        
        PORTD.RD0 = ~LATD.RD0; // Altera valor do LED
        while(INTCON.TMR0IF == 0); // Aguarda o TIMER ir para nível alto
        reiniciaTIMER();
    }
}