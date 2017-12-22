# Aula 01

## Estrutura Básica dos pinos I/O

Família 18F fornece 25mA por pino

## Registradores

Registrador - região especifica em memoria, onde é possível controlar um periférico.
Para utilizar um pino é necessário configurar três registradores: TRISx, LATx, PORTx

### TRISx - Principal registrador estudado. Define se o pino será entrada(1) ou saída(0)
    Para realizar um acionamento, o pino deve fornecer corrente (Saída). Para isso deve-se configura o registrador TRISx.
    Quando o pino é configurado como entrada, o pino fica em alta impedância, observando a tensão do pino e não corrente, de forma que não interfira no circuito externo.
    ENTRADA - leitura do nível de tensão (alta impedância) 
    SAIDA - fornecimento de corrente (25mA)

### LATx e PORTx: o 'x' é o número da porta
    Ambos permitem escrever no pino físico (joga nível lógico 1 ou 0), quando escreve em um, escreve-se em outro. 
    No entanto o LATx é um buffer, memorizando o último valor escrito no PORTx. 
    Leitura do pino através do PORTx.
    **LATx - Apenas na família 18F**.

### ANSELx ou ADCOM1
    Permite configurar se o pino será análogico ou digital.
    1 - Para analógico
    0 - Para digital

### WPUx 
    Responsável por atrelar uma configuração pull-up ao pino correspondente.


*PIC16F1937*       
*!! Cada Registrador PORT contém 8 pinos de I/O ??*

# Aula 02

## Estudo do PORT

### Read - Modify - Write (RMW)
### Buffer LAT
    Obtem os valores dos pinos e grava em memória no registrador interno.
    Modifica o bit no registrador interno e escreve novamente na porta.
    *Existe casos em que o circuito em questão possui um comportamento capacitivo, gerando atrasos na gravação e consequentemente leitura incorreta do valor do pino, quando feita pelo PORT. Quando se joga nível lógico, ocorre um atraso, pois o capacitor descarregado atua como um circuito aberto.*
    *Perigo de modificar um bit e em seguida modificar um outro bit, no entanto devido a presença do capacitor descarregado, ocorre um gravação errônea no primeiro bit modificado, salvando-o como nível lógico 0*
    O LAT vêm como workaround para esta situação, atuando como buffer da porta o LAT não lê direto do pino como o PORT, ele lê do buffer interno.
    *Nos microcontroladores que não possuem o buffer LAT, utiliza-se uma instrução delay entre uma linha e outra de leitura e gravação dos PINOS I/O, ou um resistor na saída*

    **Para realizar sucessivas leituras e escritas de um pino em um pequeno intervalo de tempo, é recomendado utilizar o registrador LAT.**

    **O nível lógico alto em um pino é defino pela tensão de alimentação do microcontrolador**