# 📡 Estrutura de tópicos MQTT

**Padrão adotado:**

```txt
{local}/{dispositivo}/{categoria}/{identificador}/{recurso}
```

**Exemplo:**

```txt
sala/esp32/tomadas/tomada-01/sensores/corrente
```

| Finalidade                         | Tópico                                                            | Direção         | Payload de exemplo                                                    |
| ---------------------------------- | ----------------------------------------------------------------- | --------------- | --------------------------------------------------------------------- |
| Medição de corrente                | `sala/esp32/tomadas/tomada-01/sensores/corrente`            | ESP32 → Backend | `{"valor": 2.5, "unidade": "A", "timestamp": "2026-06-18T16:00:00Z"}` |
| Medição de tensão                  | `sala/esp32/tomadas/tomada-01/sensores/tensao`              | ESP32 → Backend | `{"valor": 127, "unidade": "V", "timestamp": "2026-06-18T16:00:00Z"}` |
| Estado da tomada                   | `sala/esp32/tomadas/tomada-01/status`                       | ESP32 → Backend | `{"estado": "online"}`                                                |
| Telemetria da tomada               | `sala/esp32/tomadas/tomada-01/telemetria`                   | ESP32 → Backend | `{"wifi_rssi": -58, "uptime_segundos": 86400, "heap_livre": 154320}`  |
| Comando da tomada                  | `sala/esp32/tomadas/tomada-01/comandos`                     | Backend → ESP32 | `{"acao": "ligar"}`                                                   |
| Comando de desligamento            | `sala/esp32/tomadas/tomada-01/comandos`                     | Backend → ESP32 | `{"acao": "desligar"}`                                                |
| Comando de temporizador            | `sala/esp32/tomadas/tomada-01/comandos`                     | Backend → ESP32 | `{"acao": "timer", "duracao_segundos": 1800}`                         |
| Medição de corrente do interruptor | `sala/esp32/interruptores/interruptor-01/sensores/corrente` | ESP32 → Backend | `{"valor": 0.8, "unidade": "A", "timestamp": "2026-06-18T16:00:00Z"}` |
| Medição de tensão do interruptor   | `sala/esp32/interruptores/interruptor-01/sensores/tensao`   | ESP32 → Backend | `{"valor": 127, "unidade": "V", "timestamp": "2026-06-18T16:00:00Z"}` |
| Estado do interruptor              | `sala/esp32/interruptores/interruptor-01/status`            | ESP32 → Backend | `{"estado": "online"}`                                                |
| Comando do interruptor             | `sala/esp32/interruptores/interruptor-01/comandos`          | Backend → ESP32 | `{"acao": "ligar"}`                                                   |

## Estados permitidos

```txt
online
offline
standby
```

## Ações permitidas

```txt
ligar
desligar
timer
```

## Convenções

* Todos os tópicos devem ser escritos em letras minúsculas.
* Utilizar hífen (`-`) para separar identificadores.
* Não utilizar espaços, acentos ou caracteres especiais.
* Todos os payloads devem ser enviados em formato JSON.
* Recomenda-se incluir `timestamp` em todas as mensagens de telemetria.
