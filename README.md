# SmartMeter

## 📌 Sobre o projeto

Este firmware sera responsavel por oraganizar os dados de cada tomada/interruptor para enviar ao backend do sistema, utilizando o protocolo de comunicaçao MQTT e Mosquitto como broker.


## 🎯 Objetivo  

- Ler dados dos sensores
- Organizar os dados para o envio
- Enviar os dados para o broker MQTT
- Manter comunicação com o backend

## 🧰 Tecnologias utilizadas

- **[PlatformIO](https://platformio.org/)**
- **[Mosquitto](https://mosquitto.org/)**
- **[MQTT](https://mqtt.org/)**
- **[Docker](https://www.docker.com/)**

## ⚙️ Componentes utilizados

- **[ESP32](https://www.espressif.com/en/products/socs/esp32)**
- **[Sensor de corrente](https://portal.vidadesilicio.com.br/acs712-medindo-corrente-eletrica-alternada-continua/)**
- **[Fonte de alimentação]()**
- **[Jumpers]()**
- **[Multiplex](https://cdn.sparkfun.com/assets/learn_tutorials/5/5/3/74HC_HCT4051.pdf)**
- **[Sensor de tensao](https://datacapturecontrol-com.translate.goog/articles/io-components/sensors/voltage/zmpt101b-ac-voltage-transformer-sensor-module?_x_tr_sl=en&_x_tr_tl=pt&_x_tr_hl=pt&_x_tr_pto=tc)**
- **[Rele](https://www.circuitbasics.com/wp-content/uploads/2015/11/SRD-05VDC-SL-C-Datasheet.pdf)**

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