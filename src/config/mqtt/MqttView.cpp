#include "WebServer.h"
#include "config/mqtt/MqttView.h"
#include "config/mqtt/MqttFlashMemory.h"

MqttView::MqttView(WebServer& server)
    : server(server)
{
}

void MqttView::handleBrokerRoot() {
  String html = "<!DOCTYPE html><html>";
  html += "<head><meta charset='UTF-8'><meta name='viewport' content='width=device-width, initial-scale=1'>";
  html += "<title>Configurar Broker MQTT</title>";
  html += "<style>body{font-family:Arial;text-align:center;padding:30px;} input{padding:10px;margin:10px;width:80%;max-width:300px;} button{padding:12px 30px;background:#007BFF;color:white;border:none;border-radius:5px;font-size:16px;}</style>";
  html += "</head><body>";
  html += "<h1>Configuração do Broker MQTT</h1>";
  html += "<p>Digite o IP do seu broker:</p>";
  html += "<form action='/saveBroker' method='POST'>";
  html += "IP do Broker:<br><input type='text' name='broker_ip' placeholder='ex: 192.168.0.210' required><br><br>";
  html += "<button type='submit'>Salvar</button>";
  html += "</form>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void MqttView::handleSaveBroker() {
  MqttFlashMemory mqttFlashMemory;
  
  if (server.hasArg("broker_ip")) {
    String brokerIp = server.arg("broker_ip");

    Serial.println("broker credentials provided");
    Serial.print("Broker IP: "); Serial.println(brokerIp);

    mqttFlashMemory.saveBroker(brokerIp);

    String html = "<html><body style='text-align:center;padding:50px;'>";
    html += "<h1>Broker configurado com sucesso!</h1>";
    html += "<p>O ESP vai reiniciar e tentar se conectar ao broker <b>" + brokerIp + "</b>.</p>";
    html += "<p>Aguarde alguns segundos...</p>";
    html += "</body></html>";
    server.send(200, "text/html", html);

    delay(3000);
    ESP.restart();
  } else {
    server.send(400, "text/plain", "Erro: envie o IP do broker.");
  }
}