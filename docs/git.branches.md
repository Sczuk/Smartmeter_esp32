# 🌿 Guia de Branches — Firmware SmartMeter

Este documento define o padrão de criação de branches e abertura de Pull Requests para o firmware do SmartMeter.

## 📌 Branches principais

| Branch | Função                                                            |
| ------ | ----------------------------------------------------------------- |
| `main` | Contém a versão estável do firmware                               |
| `dev`  | Recebe as funcionalidades finalizadas antes de irem para a `main` |

## 🌱 Branches de desenvolvimento

As branches de desenvolvimento devem ser criadas a partir da `dev`.

Formato:

```text
<tipo>/<descricao-curta>
```

Exemplos:

```text
feat/leitura-de-sensor
feat/comunicacao-mqtt
feat/controle-rele
fix/reconexao-wifi
docs/topicos-mqtt
chore/config-platformio
```

## 🎯 Tipos de branches

| Tipo       | Quando usar                                    |
| ---------- | ---------------------------------------------- |
| `feat`     | Nova funcionalidade                            |
| `fix`      | Correção de bug                                |
| `docs`     | Alterações na documentação                     |
| `refactor` | Refatoração do código                          |
| `test`     | Testes                                         |
| `chore`    | Configurações e tarefas de manutenção          |
| `build`    | Alterações relacionadas ao build ou PlatformIO |

## 🔁 Fluxo de trabalho

```text
dev → feat/nova-funcionalidade → dev → main
```

1. Criar a branch a partir da `dev`
2. Desenvolver a funcionalidade ou correção
3. Fazer commits seguindo o guia de commits
4. Abrir Pull Request para a `dev`
5. Testar o firmware na `dev`
6. Abrir Pull Request da `dev` para a `main`
7. Gerar uma versão estável na `main`

## 🧪 Exemplo de criação de branch

```bash
git checkout dev
git pull origin dev
git checkout -b feat/leitura-de-sensor
```

## 🔀 Exemplo de envio da branch

```bash
git add .
git commit -m "feat(sensor): add current reading"
git push origin feat/leitura-de-sensor
```

## ✅ Pull Request

Todo Pull Request deve conter:

* Resumo das alterações
* Tipo de mudança
* Como foi testado
* Checklist de revisão

## 📝 Template de Pull Request

```md
# Description

Resumo das alterações feitas nesta branch.

Fixes #issue

## Type of change

- [ ] Bug fix
- [ ] New feature
- [ ] Breaking change
- [ ] Documentation update
- [ ] Refactor
- [ ] Chore

## How Has This Been Tested?

Descreva como o firmware foi testado.

Exemplo:

- [ ] Upload realizado no ESP32
- [ ] Leitura do sensor validada no monitor serial
- [ ] Publicação MQTT testada com Mosquitto
- [ ] Comando recebido via tópico MQTT

## Checklist

- [ ] O código segue o padrão do projeto
- [ ] Realizei uma auto-revisão do código
- [ ] A documentação foi atualizada quando necessário
- [ ] O firmware compila sem erros
- [ ] O firmware foi testado no ESP32
- [ ] As mensagens MQTT foram validadas
- [ ] Não foram adicionadas credenciais no código
```

# 🚀 Template de Pull Request — Release

Use este template apenas para Pull Requests da branch `dev` para a branch `main`.

```md
# Release

## Version

v0.1.0

## Description

Descreva o objetivo desta nova versão do firmware.

Exemplo:

Esta versão adiciona a primeira estrutura funcional de comunicação MQTT, leitura dos sensores e controle inicial dos relés.

## What was added?

- [ ] Leitura de corrente
- [ ] Leitura de tensão
- [ ] Comunicação MQTT
- [ ] Controle de relé
- [ ] Reconexão Wi-Fi
- [ ] Reconexão MQTT
- [ ] Documentação atualizada

## Bug fixes

- [ ] Correção na leitura dos sensores
- [ ] Correção na conexão Wi-Fi
- [ ] Correção na publicação MQTT

## Breaking changes

- [ ] Nenhuma
- [ ] Alteração na estrutura dos tópicos MQTT
- [ ] Alteração no formato dos payloads
- [ ] Alteração na configuração do firmware

## How was this version tested?

- [ ] Firmware compilado com sucesso
- [ ] Upload realizado no ESP32
- [ ] Conexão Wi-Fi validada
- [ ] Conexão MQTT validada
- [ ] Publicação dos sensores validada com Mosquitto
- [ ] Recebimento de comandos validado via MQTT
- [ ] Teste de reconexão realizado
- [ ] Monitor serial verificado

## Release checklist

- [ ] A branch `dev` está estável
- [ ] Não existem conflitos pendentes
- [ ] O README foi atualizado
- [ ] A documentação MQTT foi atualizada
- [ ] As variáveis de configuração foram revisadas
- [ ] Nenhuma credencial foi adicionada ao código
- [ ] Esta versão está pronta para ir para a `main`

## Related PRs / Issues

- #
- #
```

# 🔖 Convenção de Versionamento

O firmware do SmartMeter utiliza versionamento semântico no formato:

```text
vMAJOR.MINOR.PATCH
```

Exemplo:

```text
v1.2.3
```

## Como funciona

| Parte   | Quando alterar                                                        | Exemplo             |
| ------- | --------------------------------------------------------------------- | ------------------- |
| `MAJOR` | Mudanças incompatíveis ou grandes alterações na estrutura do firmware | `v1.0.0` → `v2.0.0` |
| `MINOR` | Novas funcionalidades sem quebrar o funcionamento atual               | `v1.0.0` → `v1.1.0` |
| `PATCH` | Correções pequenas, ajustes e bugs                                    | `v1.1.0` → `v1.1.1` |

## Exemplos no SmartMeter

```text
v0.1.0
```

Primeira versão funcional do firmware.

```text
v0.2.0
```

Adição da comunicação MQTT.

```text
v0.2.1
```

Correção na reconexão Wi-Fi.

```text
v0.3.0
```

Adição de leitura de tensão.

```text
v1.0.0
```

Primeira versão estável do firmware.

## Regras

* Toda versão estável deve sair da branch `main`.
* Todo merge de `dev` para `main` deve gerar uma nova versão.
* Toda versão publicada deve possuir uma tag no Git.
* O nome da tag deve seguir o formato `vMAJOR.MINOR.PATCH`.

## Criando uma tag

```bash
git checkout main
git pull origin main

git tag -a v0.1.0 -m "Release v0.1.0"
git push origin v0.1.0
```


## 📌 Regras

* A `main` deve receber apenas versões estáveis.
* A `dev` deve receber funcionalidades finalizadas.
* Toda branch deve sair da `dev`.
* Toda branch deve ter um nome claro e objetivo.
* Não fazer commit direto na `main`.
* Evitar branches genéricas como `teste`, `ajustes` ou `nova-branch`.

## ✅ Exemplos bons

```text
feat/leitura-corrente
feat/topicos-mqtt
fix/reconexao-wifi
docs/guia-instalacao
chore/atualizar-dependencias
```

## ❌ Exemplos ruins

```text
teste
codigo-novo
ajustes
branch1
final
```
