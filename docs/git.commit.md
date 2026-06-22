# 📝 Guia de Commits — Firmware SmartMeter

Este projeto utiliza o padrão **Conventional Commits** para manter o histórico de alterações organizado e facilitar a manutenção do firmware.

## 📋 Formato

Todos os commits devem seguir o padrão:

```text
<tipo>(<escopo opcional>): <descrição>
```

### Exemplos

```text
feat(mqtt): implement topic hierarchy

fix(sensor): correct current calculation

docs: update MQTT documentation
```

---

## 🎯 Tipos permitidos

| Tipo       | Descrição                                |
| ---------- | ---------------------------------------- |
| `feat`     | Nova funcionalidade                      |
| `fix`      | Correção de bug                          |
| `docs`     | Alterações na documentação               |
| `style`    | Alterações de formatação                 |
| `refactor` | Refatoração sem mudança de comportamento |
| `perf`     | Melhorias de desempenho                  |
| `test`     | Adição ou alteração de testes            |
| `build`    | Alterações de build ou PlatformIO        |
| `chore`    | Configurações e tarefas de manutenção    |
| `revert`   | Reversão de commits                      |

---


## ✅ Exemplos válidos

```text
feat(sensor): add voltage sensor support

feat(mqtt): define command topics

fix(wifi): resolve automatic reconnection

refactor(relay): simplify switching logic

build(platformio): update ESP32 framework

docs: add installation guide

chore(config): update environment variables
```

---

## ❌ Exemplos inválidos

```text
add mqtt
```

> Commit sem tipo.

```text
FEAT(mqtt): add topics
```

> Tipo em maiúsculo.

```text
feat:mqtt topics
```

> Formato incorreto.

```text
fix(sensor): fixed current measurement
```

> Evite verbos no passado.

---

## 📌 Regras

* O tipo deve ser escrito em letras minúsculas.
* O escopo é opcional, mas recomendado.
* Utilize verbos no presente do indicativo.
* Não utilize ponto final ao final da descrição.
* Mantenha a descrição objetiva.
* O cabeçalho deve ter no máximo 100 caracteres.

---

## 💡 Exemplos para o SmartMeter

```text
feat(tomada): add timer command

feat(interruptor): implement status topic

feat(mqtt): add retained status messages

fix(sensor): calibrate current readings

fix(mqtt): resolve broker reconnection issue

docs(mqtt): add payload examples

chore(platformio): update dependencies
```
