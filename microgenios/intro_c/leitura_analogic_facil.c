unsigned int leitura;
unsigned char texto[6];

// Configura os dos primeiros bits do anselA para analogico
ANSELA.B0 = 1;
ANSELA.B1 = 1;

//Configuração como entrada
TRISA.RA0 = 1;
TRISA.RA1 = 1;

//Configuração nível alto
PORTA.RA0 = 1;
PORTA.RA1 = 1;

ADC_Init();

while(TRUE) {
    leitura = ADC_Read(0);
    leitura = (int)(leitura * (100./1023.)); // Converte de 0 a 100%

    WordToStr(leitura, texto);
    LCD_Out(1,4,texto);
    LCD_Chr_Cp('%');
    Delay_ms(20);
}