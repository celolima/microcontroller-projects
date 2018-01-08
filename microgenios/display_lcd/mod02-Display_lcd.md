# Aula 01

## Modelos de display LCD
    Composto de uma matriz de pixels, definada na memória CGROM. Envia uma informação no barramento de dados do display. Endereço -> mem. CGROM -> print.
    O barramento contém pinos de bits, configuração/controle (enable, rw,rs), alimentação(3.3v ou 5v) e contraste (via resistor).
    Além de vcc e gnd do backlight.

### Comandos
    Existe uma tabela de comandos suportados pelo display LCD.
    RS  -> A informação envida é um  Comando ou Dado?
    R/W -> Escrita ou Leitura?
    E   -> Clock
    Vee -> Constraste

    Simulador -> LCDsim http://www.angelfire.com/ultra/lcd/