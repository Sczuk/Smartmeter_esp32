#include "WebServer.h"
#include "config/wifi/WifiView.h"
#include "config/wifi/WifiConfig.h"
#include "config/wifi/WifiFlashMemory.h"

WifiView::WifiView(WebServer& server)
    : server(server)
{
}

void WifiView::handleWifiRoot() {
  String html = "<!DOCTYPE html><html>";
  html += "<head><meta charset='UTF-8'><meta name='viewport' content='width=device-width, initial-scale=1'>";
  html += "<title>Configurar Wi-Fi</title>";
  html += "<style>body{font-family:Arial;text-align:center;padding:30px;} input{padding:10px;margin:10px;width:80%;max-width:300px;} button{padding:12px 30px;background:#007BFF;color:white;border:none;border-radius:5px;font-size:16px;}</style>";
  html += "</head><body>";
  html += "<h1>Configuração do Wi-Fi</h1>";
  html += "<p>Digite os dados da sua rede:</p>";
  html += "<form action='/saveWifi' method='POST'>";
  html += "SSID:<br><input type='text' name='ssid' placeholder='Nome da rede' required><br>";
  html += "Senha:<br><input type='password' name='pass' placeholder='Senha da rede'><br><br>";
  html += "<button type='submit'>Salvar e Conectar</button>";
  html += "</form>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void WifiView::handleSaveWifi() {
  WifiFlashMemory wifiFlashMemory;

  if (server.hasArg("ssid") && server.hasArg("pass")) {
    String ssid = server.arg("ssid");
    String password = server.arg("pass");

    Serial.println("credentials provided");
    Serial.print("SSID: "); Serial.println(ssid);
    Serial.print("Senha: "); Serial.println(password);

    wifiFlashMemory.saveWifi(ssid,password);

    String html = "<html><body style='text-align:center;padding:50px;'>";
    html += "<h1> Credenciais salvas com sucesso!</h1>";
    html += "<p>O ESP vai reiniciar e tentar se conectar à rede <b>" + ssid + "</b>.</p>";
    html += "<p>Aguarde alguns segundos...</p>";
    html += "</body></html>";
    server.send(200, "text/html", html);

    delay(3000);
    ESP.restart();
  } else {
    server.send(400, "text/plain", "Erro: envie SSID e Senha.");
  }
}

