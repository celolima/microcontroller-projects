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
    