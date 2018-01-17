# Aula 01

## O que é
    O conversosr A/D é responsável em converter um sinal analógico em um sinal digital correspondente.
    Diversar entradas analógicas multiplexadas para um único conversor AD.
    Logo a leitura deve ser de um pino por vez. Leitura de pinos serial por chaveamento.
    O conversos A/D tem que possuir as tensões de refência, entre tensão máxima e tensão mínima.
    Podendo utilizar uma referência externa ou interna, pela própria alimentação do microcontrolador.
    Utilizando as referências internas libera-se os pinos para GPIO ou AD.
    Todo conversor possui um número de resolução (precisão).

##Tempos

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