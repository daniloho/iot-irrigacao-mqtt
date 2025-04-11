# 💧 Aplicação de IoT para Monitoramento de Irrigação Inteligente

Este projeto implementa uma solução de irrigação inteligente baseada em IoT utilizando o ESP32, sensores ambientais e o protocolo MQTT. Ele permite o monitoramento remoto da umidade do solo e condições atmosféricas, controlando automaticamente a irrigação de acordo com as leituras dos sensores.

---

## 📦 Componentes Utilizados

- ESP32 NodeMCU  
- Sensor Capacitivo de Umidade do Solo  
- Sensor DHT22 (Temperatura e Umidade)  
- Módulo Relé 5V  
- Válvula Solenoide 12V  
- Protoboard e Jumpers

> *Observação: este projeto foi desenvolvido e testado por meio de simulação digital usando a plataforma [Wokwi](https://wokwi.com).*

---

## 🌐 Comunicação

A comunicação entre os dispositivos é feita via protocolo MQTT, utilizando o broker público `broker.hivemq.com`. O ESP32 publica os dados dos sensores e escuta comandos enviados para ativar a irrigação.

Tópicos utilizados:
- `iot/irrigacao/umidade_solo`
- `iot/irrigacao/temperatura`
- `iot/irrigacao/umidade_atmosferica`
- `iot/irrigacao/comando`

---

## 🔧 Funcionalidades

- Leitura contínua de umidade do solo (sensor capacitivo)
- Medição de temperatura e umidade do ar (DHT22)
- Publicação de dados via MQTT
- Acionamento automático da válvula por comando MQTT
- Visualização do funcionamento via serial monitor ou painel MQTT

---

## 📊 Diagrama do Circuito

Diagrama completo disponível na pasta `imagens/` e também no artigo.  
A montagem foi simulada com o software **Fritzing**.

---

## 🧠 Fluxograma de Funcionamento

O fluxograma do processo está disponível no artigo e na pasta `documentacao/`.

---

## 📹 Demonstração em Vídeo

Assista à demonstração do funcionamento do protótipo simulado com MQTT no vídeo abaixo:

🔗 [Clique aqui para assistir no YouTube](https://youtube.com/link-aqui)

---

## 📂 Organização do Repositório


---

## 🧪 Testes de Desempenho

Foram realizadas 4 medições do tempo de resposta entre sensores, atuadores e o MQTT. Resultados e gráficos disponíveis na seção de resultados do artigo.

---

## 📘 Referências

- AYAZ, M. et al. Internet-of-Things (IoT)-Based Smart Agriculture: IEEE Access, 2019.  
- HEATH, S. Embedded Systems Design.  
- SANTOS, B. et al. Internet das Coisas: da teoria à prática.  
- MQTT.ORG. O protocolo MQTT para IoT. Disponível em: http://mqtt.org  
