## O que é
    Com base no temporizadores que é possível sincronizar as tarefas. Simulaçao de que tudo está sendo ao mesmo tempo.
    Existem diversos Timers nos microcontroladores. No entanto o funcionamento é comum a todos.

## Funcionamento

    Existe um flag de sinalização do TIMER. Sinalizado quando ocorre overflow de 16 bits = 65535. Resetando para 0 o TMRxL TMRxH.

    Ex: Cada pulso gasta 1us. Quando ocorrer 65535 pulsos, ocorre overflow dos registradores(contadores) do timers, setando o flag de status para nível alto.
    Como contar 50000 us? Basta setar o valor inicial do timer para 15536, ou seja 65535 - 50000 = 15536.

    Após setar o flag, via estouro, overflow, é necessário resetar o FLAG do Timer, de acordo com a aplicação.

#### Como calcular 10000 ciclos?

    Via Prescaler, que reduz o tempo de pulsos, em uma escala pré-definida, 1:2 ou 1:16.
    Ou seja, configura o preescaler para 1:4 e seta o valor inicial do contador para 15536, sobrando 50000 antes do overflow. Contudo no final teremos os tempo de 100000.

    O prescaler server para reduzir a frequência de pulsos de entrada. Vide CicloMaquina

#### Cálculo do tempo total após prescaler

    Escala de 1:2, 1us * 2 * 50000 = 100000

## MODO DE OPERAÇÃO

    modo_16bits - valor_final = valor_inicial_setado;

## Ciclo de máquina

    Frequencia do oscilador = 8MHz
    Ciclo_de_maquina = Fosc/4 => 8/4 = 2MHz
    Periodos = 1/f => 1/2 = 0.5us - Ou seja velocidade do pulso, cada instrução do assembler consome esse tempo, exceto 'linhas de salto, GOTO?'.

    Tempo=periodo_ciclo_maquina * prescaler * (modo_16 - cargaInicial);
    Ex: 
    Tempo = 0.5us * 2 * (65535 - 15536); Logo Tempo = 50000us. -- Prescaler de 1:2
    Tempo = 0.5us * 4* (65535 - 15536); Logo Tempo = 100000us. -- Prescaler de 1:4

## TIMER0
    Trabalha até 256 do prescaler. Pode trabalhar como Counter.

## FAMILIA PIC16F
    - 8-bit Timer/Counter
    - 8-bit Prescaler programável
    - Fonte de clock interna ou externa
    - Interrupção do overflow (FF -> 00)    

## Registradores de Timers
    T0CON Register - Responsável por configurar quase todo o TIMER0.
    TMRON:  Liga ou desliga (interrompe ou não os pulsos de entrada).
    T08BIT: Configura o modo 8 ou 16 bits.
    T0CS:   Configura o modo de operação, ou como TIMER ou como CONTADOR.
    T0SE:   Configuração de borda de subida ou descida do pulso.
    PSA:    Habilita ou desabilita o Prescaler. Sendo 0 habilita.
    T0PS2:  Configuração a razão ou rate do prescaler.

## OBSERVAÇÃO 
> Sempre aconcelho meus alunos a aprendere bem a programar o TIMER0 e o TIMER1, pois o TIMER0 é padronizado (ou quase sempre) entre a família PIC16 e PIC18, enquanto o TIMER1 é idêntico comparado com o TIMER3 e 5, ou seja, aprendeu bem a programar o TIMER1, “valeu” também para o TIMER3 e 5.
> O TIMER2 é mais usado compartilhado com outros periféricos, tal como o PWM.