# Tópicos MQTT — Exemplos para Teste (Mosquitto)

Este documento reúne exemplos de payloads JSON para publicar em cada tópico MQTT, usados para testar o broker Mosquitto.

## Cadastro de Smartmeter

**Tópico:**
```
smartmeter/config/smartmeter
```

**Payload:**
```json
{
  "smartmeterId": "0000-0000-0001"
}
```

## Cadastro de Dispositivo

**Tópico:**
```
smartmeter/{smartmeterId}/config/device
```

**Payload:**
```json
{
  "deviceId": "1234-1234-0001",
  "voltagePin": "1",
  "currentPin": "2",
  "relayPin": "4"
}
```

## Ligar/Desligar dispositivo

**Tópico:**`
```
smartmeter/{smartmeterId}/device/command
```

```json
{
  "deviceId":"1234-1234-0001",
  "command":"TURN_ON"
}
```
