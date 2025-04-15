# 🌱 Sistema de Irrigação Inteligente com ESP32 e MQTT

Este repositório contém os arquivos do projeto desenvolvido para a disciplina de IoT da Universidade Presbiteriana Mackenzie. O projeto simula um sistema automatizado de irrigação utilizando sensores, atuadores e comunicação via protocolo MQTT.

## 📘 Descrição do Projeto

O sistema foi desenvolvido com o objetivo de monitorar a umidade do solo e as condições atmosféricas para controlar, de forma automatizada, a irrigação de uma plantação. Para isso, foram utilizados sensores conectados a uma placa ESP32, que se comunica com um broker MQTT para envio e recebimento de dados.

## 🔧 Componentes Utilizados

- **ESP32 NodeMCU** – Placa de prototipagem com Wi-Fi integrado.
- **Sensor de Umidade do Solo Capacitivo** – Mede o nível de umidade do solo.
- **Sensor DHT22** – Mede temperatura e umidade relativa do ar.
- **Módulo Relé 5V** – Controla o acionamento da válvula.
- **Válvula Solenoide 12V** – Libera ou bloqueia o fluxo de água.
- **Simulador Wokwi** – Ambiente de simulação para o protótipo.

## 🌐 Comunicação MQTT

- **Broker utilizado:** Mosquitto (local e HiveMQ WebSocket Client)
- **Tópicos utilizados:**
  - `iot/irrigacao/umidade_solo`
  - `iot/irrigacao/temperatura`
  - `iot/irrigacao/umidade_atmosferica`
  - `iot/irrigacao/comando`

O ESP32 publica os dados dos sensores nos tópicos correspondentes e escuta comandos de acionamento no tópico `iot/irrigacao/comando`.

## 🧪 Funcionamento

1. Sensores fazem leituras periódicas.
2. ESP32 publica os dados no broker MQTT.
3. Um cliente MQTT (simulado) avalia os dados e envia comandos.
4. O ESP32 aciona ou desativa a válvula de irrigação com base no comando recebido.

## 💻 Código-fonte

O código completo desenvolvido em C/C++ para a plataforma Arduino está disponível na pasta [`/codigo`](./codigo/). O código contém:
- Conexão Wi-Fi
- Comunicação MQTT
- Leitura de sensores
- Publicação de dados
- Ação com base em comando recebido

## 🔁 Simulação no Wokwi

A simulação do sistema pode ser acessada pelo seguinte link:

🔗 [Acessar simulação no Wokwi](https://wokwi.com/projects/427968689341007873)

## 📽️ Vídeo Demonstração

A apresentação completa do projeto com identificação, explicação oral e funcionamento com MQTT está disponível no YouTube:

🎥 [Assista ao vídeo](https://youtu.be/8CQ8Y3AEKDM)
