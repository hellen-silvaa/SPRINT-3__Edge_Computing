# Projeto Bike-E: Conectando o Ciclismo à Fórmula E
EDGE COMPUTING & COMPUTER SYSTEMS

## Objetivo
O objetivo desta sprint é desenvolver a arquitetura inicial de uma aplicação IoT capaz de receber e transmitir dados biometricamente por meio de um Edge Device. a partir disso desenvolvemos o Projeto Bike-E que tem como ambição:

- **Promover a Fórmula E:** Tornar a Fórmula E mais acessível e popular para pessoas de todas as idades, conectando-a ao cotidiano das pessoas através do ciclismo urbano.

## Draft de arquitetura da nossa solução Iot
Para alcançar o objetivo proposto, o Projeto Bike-E foi desenvolvido atraves de uma arquitetura que tem iot devices, front-end e back-end

## Iot Front-end principais funcionalidades:
A Bike-E possui diversas funcionalidades que agregam valor à experiência do usuário:

1. **Medição de Distância:** Utilizando um sensor magnético instalado no aro da bicicleta, o dispositivo é capaz de medir a distância percorrida e a velocidade do ciclista com precisão.
2. **Contador de Calorias:** Através de algoritmos avançados, o dispositivo calcula com precisão as calorias gastas durante o trajeto, fornecendo informações valiosas para o usuário.
3. **Iluminação Automática:** Equipado com sensores LDR, os faróis da bicicleta são acionados automaticamente ao anoitecer, garantindo a segurança do ciclista durante a noite.
4. **Display LCD:** Um display LCD integrado fornece informações em tempo real sobre a distância percorrida e as calorias gastas. Além disso, a cada 1 km percorrido, o dispositivo exibe uma mensagem de progresso no display.
5. **Recompensas:** A cada 5 km percorridos, o ciclista ganha 50 moedas, que podem ser acumuladas e trocadas por prêmios exclusivos relacionados à Fórmula E, como camisetas, descontos em eventos e visitas técnicas.


- **Incentivo à Prática Esportiva:** Ao oferecer recompensas e feedback em tempo real, o Bike-E incentiva a prática regular de exercícios físicos, contribuindo para um estilo de vida mais saudável e ativo.
- **Sustentabilidade:** O uso de bicicletas elétricas promove a mobilidade urbana sustentável, reduzindo as emissões de carbono e contribuindo para um ambiente mais limpo e saudável.
- **Experiência Interativa:** A integração de tecnologia IoT proporciona uma experiência de pedalada interativa e envolvente, cativando ciclistas de todas as idades e níveis de habilidade.

Com o Projeto Bike-E, estamos redefinindo a maneira como as pessoas interagem com o ciclismo urbano e a Fórmula E, oferecendo uma experiência única que combina tecnologia, esporte e sustentabilidade. Junte-se a nós nesta jornada emocionante e descubra o futuro da mobilidade urbana conectada!
## Descrição Detalhada do Projeto

O Projeto Bike-E é uma iniciativa que busca integrar o mundo do ciclismo urbano e sustentabilidade com a emoção e tecnologia da Fórmula E. Utilizando componentes de IoT (Internet das Coisas) e algoritmos de controle, o projeto visa captar informações relevantes durante o percurso de bicicleta, proporcionando uma experiência única e interativa para ciclistas de todas as idades e níveis de conhecimento sobre automobilismo.

## Componentes

- Arduino Uno
- LCD 16x02
- Sensor Fotoresistor (LDR)
- Sensor de Movimento Infravermelho Passivo (PIR) (substituindo o velocímetro)
- 1 LED vermelho
- 1 LED branco (representa os faróis)
- 2 Resistores de 220 ohm para os LEDs
- Jumpers

## Principais Tecnologias Utilizadas

- C++ 
- IoT (Internet das Coisas)
- Software Wokwi

## Iot devices

![image](https://github.com/user-attachments/assets/2ec0cd3f-9d25-419e-b02d-302be35028e7)


- **ESP32:** Plataforma de hardware utilizada como o cérebro do nosso projeto, responsável por controlar e processar os dados dos sensores.
- **Sensor de Movimento Infravermelho Passivo (PIR):** Sensor utilizado para detectar o movimento do ciclista, substituindo o velocímetro tradicional.
- **Sensor Fotoresistor (LDR):** Sensor utilizado para detectar a luminosidade ambiente e ligar ou desligar automaticamente os faróis da bicicleta quando necessário.
- **LCD 16x02:** Display utilizado para exibir informações como distância percorrida, calorias gastas, estado dos faróis, mensagem de bonificação por x km rodados.
- **LEDs:** Utilizados para representar os faróis da bicicleta (LED branco) e indicar alertas de km rodado (LED vermelho).

## Funcionamento

O projeto funciona da seguinte forma:
1. O sensor LDR detecta a luminosidade ambiente.
2. Se estiver escuro, o Arduino aciona os faróis da bicicleta (LED branco).
3. O sensor PIR detecta o movimento da roda da bicicleta, enviando os dados para o Arduino.
4. O Arduino processa os dados dos sensores e exibe as informações relevantes no LCD 16x02.

[Link para acessar o projeto no WOKWI](https://wokwi.com/projects/400391918414007297)

video aquiiiiii


## Iot Back-end
## Instruções de uso
## Requisitos
## Dependências

## Integrantes do Grupo:

   -  Alexia Ramalho: RM 558385 
   -  Eduardo Dallabella: RM 556803
   -  Heloísa Real: RM 554535
   -  Hellen Silva: RM 559008
   -  Lorenzo Acquesta: RM 557397
