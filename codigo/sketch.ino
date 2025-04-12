#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT22
#define LED_RELE 2
#define SENSOR_SOLO 34

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);
DHT dht(DHTPIN, DHTTYPE);

void setup_wifi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi conectado!");
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Conectando ao MQTT...");
    if (client.connect("esp32-irrigacao")) {
      Serial.println("conectado!");
    } else {
      Serial.print("falhou, rc=");
      Serial.print(client.state());
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_RELE, OUTPUT);
  dht.begin();
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  float temp = dht.readTemperature();
  float umid = dht.readHumidity();
  int umidadeSolo = analogRead(SENSOR_SOLO);

  if (isnan(temp) || isnan(umid)) {
    Serial.println("Erro ao ler o sensor DHT22.");
  } else {
    String tempStr = String(temp, 2);
    String umidStr = String(umid, 2);
    String soloStr = String(umidadeSolo);

    client.publish("iot/irrigacao/temperatura", tempStr.c_str());
    client.publish("iot/irrigacao/umidade_atmosferica", umidStr.c_str());
    client.publish("iot/irrigacao/umidade_solo", soloStr.c_str());

    Serial.println("------ Dados enviados ------");
    Serial.println("Temperatura: " + tempStr);
    Serial.println("Umidade Ar: " + umidStr);
    Serial.println("Umidade Solo: " + soloStr);

    if (umidadeSolo < 1200) {
      digitalWrite(LED_RELE, HIGH);
      Serial.println(">>> Irrigação ATIVADA");
    } else {
      digitalWrite(LED_RELE, LOW);
      Serial.println(">>> Irrigação DESLIGADA");
    }
  }

  delay(5000);
}
