# Jogo de Memória com Arduino

Este projeto é um jogo de memória utilizando Arduino Uno. Ele usa LEDs, botões e um buzzer piezoelétrico para criar um jogo interativo onde o jogador deve repetir uma sequência gerada aleatoriamente de LEDs e sons. Se a sequência for repetida corretamente, o jogador avança para o próximo nível com uma sequência maior. Caso contrário, o jogo reinicia.

## Componentes Utilizados

- 1 Arduino Uno
- 4 LEDs (conectados aos pinos 9, 10, 11 e 12)
- 4 resistores de 220 ohms para os LEDs
- 4 botões (conectados aos pinos 4, 5, 6 e 7)
- 4 resistores pull-down de 10k ohms para os botões
- 1 buzzer piezoelétrico (conectado ao pino 8)
- Jumpers e protoboard

## Conexões

- **LED 1:** Pino 10
- **LED 2:** Pino 11
- **LED 3:** Pino 12
- **LED Portão:** Pino 9
- **Botão 1:** Pino 5
- **Botão 2:** Pino 6
- **Botão 3:** Pino 7
- **Botão Portão:** Pino 4
- **Buzzer:** Pino 8

## Funcionalidades

- **output1(), output2(), output3(), outputPortao():** Funções que ativam os LEDs e o buzzer, emitindo diferentes sons para cada LED.
- **start():** Função que inicia o jogo, piscando todos os LEDs em sequência.
- **gameOver():** Função que reinicia o jogo caso o jogador erre a sequência.
- **memoryClear():** Função que limpa a memória do jogo.
- **complete():** Função que verifica se o jogador completou a sequência correta e avança para o próximo nível.
- **check(byte number):** Função que verifica se o botão pressionado corresponde ao próximo número da sequência.



## Link para acesso

https://www.tinkercad.com/things/45oUtP6Puvg-projeto-final/editel?returnTo=%2Fthings%2F45oUtP6Puvg-projeto-final&sharecode=7_3buKiweEdcPP5Bp9eDOG-AnbIKh1Jjyc7tgh1SrNQ
