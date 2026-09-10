# 📡 Estrutura de tópicos MQTT — SmartMeter

**Padrão adotado:**

```txt
smartmeter/{smartmeterId}/{recurso}
smartmeter/{smartmeterId}/device/{recurso}
```

Um `smartmeterId` identifica a placa ESP32 física. Cada placa gerencia um ou mais `device` (tomada/interruptor), cada um com seu próprio conjunto de pinos (tensão, corrente, relé). Por isso os tópicos de telemetria e comando são escopados pelo `smartmeterId`, e o `deviceId` (quando necessário) vai no payload em vez de no tópico — já que measurements reporta todos os devices de uma vez.

## Tópicos

| Finalidade                          | Tópico                                        | Direção         | Payload de exemplo |
| ------------------------------------ | ---------------------------------------------- | ---------------- | -------------------- |
| Registro de um novo smartmeter       | `smartmeter/config/smartmeter`                 | ESP32 → Backend  | `{"smartmeterId": "0243-8081-1595"}` |
| Registro/configuração de um device   | `smartmeter/{smartmeterId}/config/device`      | ESP32 → Backend  | `{"deviceId": "3737-4070-8279", "voltagePin": 1, "currentPin": 2, "relePin": 3}` |
| Dados dos sensores (todos os devices)| `smartmeter/{smartmeterId}/measurements`       | ESP32 → Backend  | ver exemplo abaixo |
| Comando de um device específico      | `smartmeter/{smartmeterId}/device/command`     | Backend → ESP32  | `{"deviceId": "6540-9186-7349", "command": "TURN_OFF"}` |

**Exemplo — `measurements`:**

```json
{
  "smartmeterId": "8323-4559-3633",
  "devices": [
    {
      "deviceId": "2043-6465-3633",
      "releState": "ONLINE",
      "current_a": 2.5,
      "voltage_v": 127,
      "power_w": 317.5
    },
    {
      "deviceId": "3622-4476-3633",
      "releState": "OFFLINE",
      "current_a": "0",
      "voltage_v": "0",
      "power_w": "0"
    }
  ]
}
```

## Estados permitidos (`releState`)

```txt
ONLINE
OFFLINE
```

## Ações permitidas (`command`)

```txt
TURN_ON
TURN_OFF
```

## Convenções

* Tópicos em letras minúsculas; valores de `releState`/`command` em maiúsculas com underscore (`TURN_ON`, `OFFLINE`).
* `camelCase` para chaves de identificador (`smartmeterId`, `deviceId`).
* Não utilizar espaços, acentos ou caracteres especiais nos tópicos.
* Todos os payloads devem ser enviados em formato JSON.
