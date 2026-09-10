# 📝 Guia de Commits — Firmware SmartMeter

Este projeto utiliza o padrão **Conventional Commits** para manter o histórico de alterações organizado e facilitar a manutenção do firmware.

## 📋 Formato

Todos os commits devem seguir o padrão:

```text
<tipo>(<escopo opcional>): <descrição>
```

### Exemplos

```text
feat(mqtt): implementa hierarquia de tópicos

fix(sensor): corrige cálculo de corrente

docs: atualiza documentação do MQTT
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
feat(sensor): adiciona suporte a sensor de tensão

feat(mqtt): define tópicos de comando

fix(wifi): resolve reconexão automática

refactor(rele): simplifica lógica de acionamento

build(platformio): atualiza framework do ESP32

docs: adiciona guia de instalação

chore(config): atualiza variáveis de ambiente
```

---

## ❌ Exemplos inválidos

```text
adiciona mqtt
```

> Commit sem tipo.

```text
FEAT(mqtt): adiciona tópicos
```

> Tipo em maiúsculo.

```text
feat:tópicos mqtt
```

> Formato incorreto.

```text
fix(sensor): corrigiu medição de corrente
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
feat(tomada): adiciona comando de timer

feat(interruptor): implementa tópico de status

feat(mqtt): adiciona mensagens de status retidas

fix(sensor): calibra leituras de corrente

fix(mqtt): resolve problema de reconexão do broker

docs(mqtt): adiciona exemplos de payload

chore(platformio): atualiza dependências
```
