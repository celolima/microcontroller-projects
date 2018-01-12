# Aula 01

## Modelos de display LCD
    Composto de uma matriz de pixels, definada na memória CGROM. Envia uma informação no barramento de dados do display. Endereço -> mem. CGRAM -> print.
    O barramento contém pinos de bits, configuração/controle (enable, rw,rs), alimentação(3.3v ou 5v) e contraste (via resistor).
    Além de vcc e gnd do backlight.

### Comandos
    Existe uma tabela de comandos suportados pelo display LCD.
    RS  -> A informação envida é um  Comando ou Dado? 0 para dado e 1 para instrução
    R/W -> Escrita ou Leitura? 0 para escrita e 1 para leitura
    E   -> Clock, de nivel alto para nivel baixo
    Vee -> Constraste

    Simulador -> LCDsim http://www.angelfire.com/ultra/lcd/

    Normalmente o pino R/W fica em modo escrita, ou seja 0, não sendo usual, de acordo com o professor realizar a leitura do estado do display LCD. Contudo pode-se aterrá-lo.

    * 0F40 -> Acessa memoria inicial da CGRAM
    * C0 -> Volta para a DDRAM

### Modos de operação

    No intuito de economizar portas lógicas tanto do microcontrolador, quanto do display LCD, ao invés de utilizar 8 bits, utiliza-se 4 bits, sendo que o caractere a ser impresso, representado por um bit, é divido em nibble. Neste modo é necessário dois clocks para realizar a impressão do caractere desejado. Ex:
    1 - Modo 8 bits
        "A" = 0100 0001 -> Necessecita-se de apenas um clock para imprimir o caracter; um clock para o envio do bit.
    2 - MOdo 4 bits
        Neste caso o primeiro clock envia o nible menos significativo (0001) e o segundo clock envia o nible mais significativo (0100)

    O formato padrão do display LCD é 8 bits. Deve-se setar o display para operar no modo de 4 bits.