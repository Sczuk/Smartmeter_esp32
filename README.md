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
smartmeter/{smartmeterId}/{recurso}
smartmeter/{smartmeterId}/device/{recurso}
```

## 🔐 Configuração

Para que o sistema possa funcionar e necessario conecta-lo ao Wi-Fi. E tambem e importante instanciar o IP do broke MQTT, caso esteja utilizando o Mosquitto... O Ip sera o mesmo da maquina em que o servidor do Mosquitto esta rodando

Caso o WiFi nao esteja configurado, o sistema do Esp32 abrirá uma conexão com nome `Smartmeter_WiFi_Config`, e será possivel se conectar a `http://192.168.4.1`, onde você vai conseguir configurar seu WiFi.

E para configurar o Broker, o Esp abrirá uma conexão chamada `Smartmeter_Broker_Config`, onde vc poderá acessar `http://192.168.4.1`, e terminar de configurar seu Broker. (Para passar o Ip pedido na configuração, é necessario saber qual o Ip da maquina onde o servidor do Broker esta conectado).


### 🔐 Configuração no codigo

Dentro do codigo, sera necessario configurar o usuario e a senha para acessar seu Broker, onde tem a explicação no arquivo env.example

## 🚀 Como executar

Para que seja possivel excutar o projeto e necessario que o Broker ja estaja pré configurado.

1. Clonar o repositório
2. Abrir no PlatformIO
3. Configurar Wi-Fi e broker
4. Conectar o ESP32
5. Fazer upload

## 🧪 Como testar

Exemplo:

mosquitto_sub -h localhost -t "test/connection" -m 'Hello, Smartmeter'
