# Aula 01

## O que é
    O conversosr A/D é responsável em converter um sinal analógico em um sinal digital correspondente.
    Diversar entradas analógicas multiplexadas para um único conversor AD.
    Logo a leitura deve ser de um pino por vez. Leitura de pinos serial por chaveamento.
    O conversos A/D tem que possuir as tensões de refência, entre tensão máxima e tensão mínima.
    Podendo utilizar uma referência externa ou interna, pela própria alimentação do microcontrolador.
    Utilizando as referências internas libera-se os pinos para GPIO ou AD.
    Todo conversor possui um número de resolução (precisão).

## Tempos

### Tempo de aquisição e tempo de conversão.
    Internamento o conversor A/D possui dois tempos definidos, de aquisição e conversão.
    O tempo de aquisição é determinado pela capacitância do pino e pela impedância da fonte
    
#### Tempo de aquisição
    O tempo de aquisição é o tempo de carga do capacitor.
    Capacitor armazena a tensão do pino por determinado tempo.
    Após carga do capacitor, o pino é desconetado da fonte analógica e então envia o valor de tensão armazenado para o conversor A/D.
    E então ocorre o tempo de conversão.

### Steps
#### Inicialização do módulo A/D
        Configura os pinos, tensão de referência, e pinos como analógico (ANSEL)
        Seleciona o canal do A/D (qual pino pela multiplexação)
        Seleciona o tempo de aquisição
        Seleciona a fonte de clock de conversão do A/D
        Habilita o módulo A/D (set ADON bit)
#### Configura a interrupção (opcional) - em geral não habilitado
        Apaga ADIF bit - Sinaliza o status do periférico (sinaliza o fim da conversão)
        Nível um em ADIE bit
        Nível um em GIE bit
#### Aguarda o tempo de aquisição
#### Inicia a conversão do A/D via GO/DONE bit
#### Aguarda a finalização da converão A/D
#### Lê o resultado
#### Aguarda antes da próxima aquisição
    
### Funcionamento da precisão
    http://www.arnerobotics.com.br/eletronica/Medidas_Analogicas_w_PIC.htm 
    Quanto maior o número de bits do conversor melhor é a precisão do mesmo. Um conversor de 8 bits possui uma precisão maior do que um de 10 bits.
    O cômputo da resolução é dado por -> Vref(MAX) / (pow(2,n) - 1);  Onde n é número de bits.
    
    Ex: Para 8 bits e uma referência máxima de 5V -> 5 / 255 = 19,61mV
        A variação é a cada 19,61mV

    Ex: Para 10 bits e uma referência máxima de 5V -> 5 / 1023 = 4,89mV
    A variação é a cada 4,89mV

### Registradores
    Existem três registradores responsáveis por trabalhar com conversor analógico para digital: ADCON0, ADCON1, ADCON2; Composto por 8 bits que devem ser configurados.
    Consultar o datasheet do microcontrolador. Ex PIC18F4520
    
    *ADCON0* -> config quais canais analógicos serão utilizados/status da conversão
    |bit7|bit6|bit5|bit4|bit3|bit2|bit1|bit0|
    |-   |-   | ch | ch | ch | ch |go/done|Adon|

    Do bit2 ao bit5: seleção dos canais analógicos utilizados
    Do bit1: status de conversão A/D (responsável por dar start no conversor)
    Do bit0: ligando o conversor ADCON1

    *ADCON1* -> ajuste de tensão de referência/config pinos digitais e analógicos
    |bit7|bit6|bit5|bit4|bit3|bit2|bit1|bit0|
    |-   |-   | ref | ref | pin | pin |pin|pin|

    Do bit4 ao bit5: tensão de referência (interna ou externa)
    Do bit0 ao bit3: configuração de quais pinos serão digitais e quais analógicos

    *ADCON2* -> ajuste de frequência/tempo aquisição
    |bit7|bit6|bit5|bit4|bit3|bit2|bit1|bit0|
    |justifica   |-   | acqt | acqt | acqt | adcs |adcs|adcs|

    Do bit7: result Format Select bit -> right or left justified
    Do bit3 ao bit5: configuração do tempo de aquisição TADs: 12tads
    Do bit0 ao bit2: configuração de convesion clock: Fosc/32

    Após conversão A/D, o resultado se encontra nos registradores ADRESH e ADRESL, cada um registrador de 8 bits, formando uma palavra de 16 bits, no entanto este conversor possui um resultado de apenas 10 bits.
    Ex: 
        ADRESH = 0B11101101;
        (ADRESH << 8) => 11101101 0000000
        
        Logo têm-se: Leitura_ADC = ((ADRESH << 8) | ADRESL) -> formando uma palavra final de 16 bits.
    

### Resumo
    *Os registradores do ADC são: ADCON0, ADCON1, ADCON2, ANSELx, TRISx, ADRESH, ADRESL;*
    - ADCON0: Seleciona o canal ADC, habilita o periférico ADC e realiza o start de conversão.
    - ADCON1: Define a tensão de referência do conversor ADC(interna ou externa) e informa qual o pino do PIC será AD ou I/O digital. 
        No caso do 18F45k22 esse registrador configura a tensão de referência apenas. Logo será necessário configurar via ANSELx.
    - ADCON2: Define a justificativa do resultado da conversão, ajusta a frequência e tempo de conversão.
    - ANSELx: Encontrado no 18F45k22 -> Defnine o pino como AD ou I/O digital.
    - TRIsx: Necessário configurar o pino como entrada.
    - ADRESH e ADRESL: Registrador que armazena o resultado da conversão.
    - TAD: Tempo de conversão de cada bit.
