# Projeto Bike-E: Conectando o Ciclismo à Fórmula E
EDGE COMPUTING & COMPUTER SYSTEMS

## Objetivo
O objetivo desta sprint é desenvolver a arquitetura inicial de uma aplicação IoT capaz de receber e transmitir dados biometricamente por meio de um Edge Device. a partir disso desenvolvemos o Projeto Bike-E que tem como ambição:

- **Promover a Fórmula E:** Tornar a Fórmula E mais acessível e popular para pessoas de todas as idades, conectando-a ao cotidiano das pessoas através do ciclismo urbano.

## Draft de arquitetura da nossa solução Iot
O projeto é composto por uma arquitetura IoT que inclui dispositivos, front-end e back-end, oferecendo uma experiência interativa e em tempo real.

## Iot Front-end principais funcionalidades:
A Bike-E possui diversas funcionalidades que agregam valor à experiência do usuário e tudo isso é exibido em dashboards em tempo real:

1. **Medição de Distância:** Utilizando um sensor magnético instalado no aro da bicicleta, o dispositivo é capaz de medir a distância percorrida e a velocidade do ciclista com precisão.
2. **Contador de Calorias:** Através da lógica desenvolvida, o dispositivo calcula com precisão as calorias gastas durante o trajeto, fornecendo informações valiosas para o usuário.
3. **Iluminação Automática:** Equipado com sensores LDR, os faróis da bicicleta são acionados automaticamente ao anoitecer, garantindo a segurança do ciclista durante a noite.
4. **Display LCD:** Um display LCD integrado fornece informações em tempo real sobre a distância percorrida e as calorias gastas. Além disso, a cada 1 km percorrido, o dispositivo exibe uma mensagem de progresso no display.
5. **Recompensas:** A cada 5 km percorridos, o ciclista ganha 50 moedas, que podem ser acumuladas e trocadas por prêmios exclusivos relacionados à Fórmula E, como camisetas, descontos em eventos e visitas técnicas.

[Link para acessar o projeto no WOKWI](https://wokwi.com/projects/409841153813711873)
![edgeee](https://github.com/user-attachments/assets/7b8ec350-4c8d-4a6d-8001-ef8a821ccf1a)


## Iot devices
### Descrição do Projeto
O Projeto Bike-E é uma iniciativa que busca integrar o mundo do ciclismo urbano e sustentabilidade com a emoção e tecnologia da Fórmula E. Utilizando componentes de IoT (Internet das Coisas) e algoritmos de controle, o projeto visa captar informações relevantes durante o percurso de bicicleta, proporcionando uma experiência única e interativa para ciclistas de todas as idades e níveis de conhecimento sobre automobilismo.

## Componentes
- ESP32
- LCD 16x02
- Sensor Fotoresistor (LDR)
- Sensor de Movimento Infravermelho Passivo (PIR) (substituindo o velocímetro)
- 1 LED vermelho
- 1 LED branco (representa os faróis)
- 2 Resistores de 220 ohm para os LEDs
- Jumpers

## Dependências
- C++ 
- IoT (Internet das Coisas)
- Software Wokwi
- Node-RED
- Servidor Protocolo MQTT 
  
![image](https://github.com/user-attachments/assets/2ec0cd3f-9d25-419e-b02d-302be35028e7)


- **ESP32:** Microcontrolador habilitado para WiFi e Bluetooth é utilizado como o cérebro do nosso projeto, responsável por controlar e processar os dados dos sensores,
- **Sensor de Movimento Infravermelho Passivo (PIR):** Sensor utilizado para detectar o movimento do ciclista, substituindo o velocímetro tradicional.
- **Sensor Fotoresistor (LDR):** Sensor utilizado para detectar a luminosidade ambiente e ligar ou desligar automaticamente os faróis da bicicleta quando necessário.
- **LCD 16x02:** Display utilizado para exibir informações como distância percorrida, calorias gastas, estado dos faróis, mensagem de bonificação por x km rodados.
- **LEDs:** Utilizados para representar os faróis da bicicleta (LED branco) e indicar alertas de km rodado (LED vermelho).

## Funcionamento

O projeto funciona da seguinte forma:
1. O sensor LDR detecta a luminosidade ambiente.
2. Se estiver escuro, o Arduino aciona os faróis da bicicleta (LED branco).
3. O sensor PIR detecta o movimento da roda da bicicleta, enviando os dados para o Arduino.
4. O ESP32 conecta ao wifi Wokwi-GUEST usando o servidor test.mosquitto.org e processa os dados dos sensores e exibe as informações relevantes no LCD 16x02.


## Iot Back-end
### Node-RED e MQTT
Utilizamos o **Node-RED** para criar os dashboards em tempo real e o **MQTT** para transmissão de dados. O **mqtt in** recebe os dados dos tópicos `/bike/calorias`, `/bike/moedas``/bike/quilometros`, `/bike/luminosidade`, e o **gauge** exibe os dados no dashboard.

### Configurações

**1. MQTT In:**

![image](https://github.com/user-attachments/assets/70dfa369-96f9-4fb8-ba4b-c56898c8e5d5)

**2. Bibliotecas:**

  ![image](https://github.com/user-attachments/assets/c9b4b35a-3e13-45b7-9052-0a0251ff307e)

**3. Configuração MQTT:**

![image](https://github.com/user-attachments/assets/43f186ce-4cd9-4781-b995-251031cbc5c3)

**4. Organização dados do Dashbard:**

![image](https://github.com/user-attachments/assets/021a5312-4649-48a6-a2d1-8e1e348dcfef)

## Dashboard:
exibe em tempo real os dados de km rodados, moedas ganhas, calorias gastas e luminosidade do farol da bicilceta que são dados essenciais para o ciclista que esta andando na bike-e

![image](https://github.com/user-attachments/assets/2f84daac-0d35-4416-a456-da6aa53e2984)

## Instruções de Uso
1. Instale o [Node-RED](https://nodered.org/docs/getting-started/local).
2. Configure o MQTT no Node-RED para receber os dados dos tópicos.
3. Execute o projeto no Wokwi e conecte ao servidor test.mosquitto.org.

## Requisitos
- ESP32 com conectividade WiFi
- Conhecimento básico em Node-RED e MQTT
- Acesso ao servidor MQTT (test.mosquitto.org)


## Integrantes do Grupo:

   -  Alexia Ramalho: RM 558385 
   -  Eduardo Dallabella: RM 556803
   -  Heloísa Real: RM 554535
   -  Hellen Silva: RM 559008
   -  Lorenzo Acquesta: RM 557397
