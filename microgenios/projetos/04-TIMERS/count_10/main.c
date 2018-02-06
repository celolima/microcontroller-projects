/* 
 *  Programar o modo counter do TIMER0 para contar apenas 10 pulsos;
 *  O botão conta até 10 e altera o estado do LED;
 *  Para contar até 10: 65536 (16bits) - 10 (contar até dez) = 65526(decimal) ou 0XFFF6;
*/

void main() {
    ANSELA = 0; // Counter - > Digital para T0CKI
    ANSELB = 0; // Botão
    ANSELD = 0; // Leds

    // Modo counter

    T0CON = OB00111000; // Modo Counter, Timer OFF, modo 16 bits, borda descida
    TMR0L = 0XF6;
    TMR0H = 0XFF;
    
    TRISA.RA4 = 1; // T0CKI -> Input do contador; Pino RA4 como entrada pois esse pino é o T0CKI(datasheet)

    INTCON.TMR0IF = 0; // Flag de sinalização de overflow
    
    // CONFIGURAÇÃO DOS LEDS
    TRISD = 0;
    PORTD = 0;

    // CONFIGURAÇÃO DO BTN
    TRISB = 1;
    PORTB = 1;

    while(1) {
        if(INTCON.TMR0IF == 1) {
            PORTD.RD0 = ~LATD.RD0; // Altera o estado do led

            // Reinicia o contador

            TMR0L = 0XF6; // Recarga para o contagem de 10 pulsos
            TMR0H = 0XFF;
            INTCON.TMR0IF = 0; // Flag de sinalização de overflow
        }
    }
}