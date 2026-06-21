# SmartMeter

## 📌 Sobre o projeto

Este firmware sera responsavel por oraganizar os dados de cada tomada/interruptor para enviar ao backend do sistema, utilizando o protocolo de comunicaçao MQTT e Mosquitto como broker.


## 🎯 Objetivo  

- Ler dados dos sensores
- Organizar os dados para o envio
- Enviar os dados para o broker MQTT
- Manter comunicação com o backend

## 🧰 Tecnologias utilizadas

- PlatformIO
- 
- Wi-Fi
- Mosquitto
- MQTT
- Docker

## ⚙️ Componentes utilizados

- ESP32
- Sensor de corrente
- Fonte de alimentação
- Jumpers
- Multiplex
- Sensor de tensao
- Rele 

## 📡 Comunicação

O ESP32 se conecta à rede Wi-Fi e publica mensagens MQTT em tópicos específicos.

Exemplo da Estrutura dos topicos:

```txt
    quarto/
    └── esp32/
        ├── tomadas/
        │   └── tomada-01/
        │       ├── sensores/
        │       │   ├── corrente
        │       │   └── tensao
        │       ├── status
        │       └── comandos
        └── interruptores/
            └── interruptor-01/
                ├── sensores/
                │   ├── corrente
                │   └── tensao
                ├── status
                └── comandos  
```

## 🔐 Configuração

Para que o sistema possa funcionar e necessario conecta-lo ao Wi-Fi. E tambem e importante instanciar o IP do broke MQTT, caso esteja utilizando o Mosquitto... O Ip sera o mesmo da maquina em que o servidor do Mosquitto esta rodando

Exemplo:

WIFI_SSID=
WIFI_PASSWORD=
MQTT_BROKER=
MQTT_PORT= 1883 (porta comum do Mosquitto)

## 🚀 Como executar

Para que seja possivel excutar o projeto e necessario que o Mosquitto ja estaja pre configurado com 

1. Clonar o repositório
2. Abrir no PlatformIO
3. Configurar Wi-Fi e broker
4. Conectar o ESP32
5. Fazer upload

## 🧪 Como testar

Exemplo:

mosquitto_sub -h localhost -t "esp32/#"

mosquitto_pub -h localhost -t "esp32/tomadas/tomada-01/comandos" -m '{"acao":"ligar"}'