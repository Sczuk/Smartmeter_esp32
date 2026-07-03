# 📡 Estrutura de tópicos MQTT

**Padrão adotado:**

```txt
{local}/{dispositivo}/{categoria}/{identificador}/{recurso}
```

**Exemplo:**

```txt
sala/esp32/tomadas/tomada-01/sensores/corrente
```

| Finalidade                        | Tópico                                             | Direção         | Payload de exemplo                                                      |
| --------------------------------- | -------------------------------------------------- | --------------- | ----------------------------------------------------------------------- |
| Dados dos sensores da tomada      | `sala/esp32/tomadas/tomada-01/sensores`            | ESP32 → Backend | `{"corrente": 2.5, "tensao": 127, "timestamp": "2026-06-18T16:00:00Z"}` |
| Estado da tomada                  | `sala/esp32/tomadas/tomada-01/status`              | ESP32 → Backend | `{"estado": "online"}`                                                  |
| Comandos da tomada                | `sala/esp32/tomadas/tomada-01/comandos`            | Backend → ESP32 | `{"acao": "ligar"}`                                                     |
| Dados dos sensores do interruptor | `sala/esp32/interruptores/interruptor-01/sensores` | ESP32 → Backend | `{"corrente": 0.8, "tensao": 127, "timestamp": "2026-06-18T16:00:00Z"}` |
| Estado do interruptor             | `sala/esp32/interruptores/interruptor-01/status`   | ESP32 → Backend | `{"estado": "online"}`                                                  |
| Comandos do interruptor           | `sala/esp32/interruptores/interruptor-01/comandos` | Backend → ESP32 | `{"acao": "ligar"}`                                                     |


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
