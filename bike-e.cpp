#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <PubSubClient.h>

#define PINO_LED_PIR 32
#define PINO_PIR 19
#define LDR_PIN 34
#define PINO_LED_LDR 33

#define ENDERECO_LCD 0x27
#define LCD_COLUNAS 16
#define LCD_LINHAS 2

LiquidCrystal_I2C lcd(ENDERECO_LCD, LCD_COLUNAS, LCD_LINHAS);

int contagemPisca = 0;
int caloriasGastas = 0;
int moedasGanhas = 0; // Nova variável para moedas
unsigned long ultimoMovimento = 0;
unsigned long tempoMensagemPIR = 0;
unsigned long tempoMensagemLDR = 0;
bool exibindoMensagemPIR = false;
bool exibindoMensagemLDR = false;
bool exibindoMensagemInicial = true;

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqtt_server = "test.mosquitto.org";

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;

void setup_wifi() {
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  unsigned long startAttemptTime = millis();

  while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 10000) {
    delay(500);
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("WiFi connection failed. Continuing without WiFi.");
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      Serial.println("Connected");
      client.publish("/ThinkIOT/Publish", "Welcome");
      client.subscribe("/ThinkIOT/Subscribe");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  pinMode(PINO_LED_PIR, OUTPUT);
  pinMode(PINO_PIR, INPUT);
  pinMode(LDR_PIN, INPUT);
  pinMode(PINO_LED_LDR, OUTPUT);

  digitalWrite(PINO_LED_PIR, LOW);
  digitalWrite(PINO_LED_LDR, LOW);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("     Bike-E");
  lcd.setCursor(0, 1);
  lcd.print("    Mahindra");

  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  unsigned long now = millis();
  int estadoPIR = digitalRead(PINO_PIR);

  // Publica a leitura da luminosidade no MQTT
  String luminosidade = String(analogRead(LDR_PIN));
  client.publish("/bike/luz", luminosidade.c_str());

  // Publica a quilometragem no MQTT
  String quilometros = String(contagemPisca);
  client.publish("/bike/km", quilometros.c_str());

  // Publica as calorias gastas no MQTT
  String calorias = String(caloriasGastas);
  client.publish("/bike/kcal", calorias.c_str());

  // Publica as moedas ganhas no MQTT
  String moedas = String(moedasGanhas); 
  client.publish("/bike/moedas", moedas.c_str());  

  //Sensor PIR
  if (estadoPIR == HIGH && millis() - ultimoMovimento > 2000) {
    digitalWrite(PINO_LED_PIR, HIGH);
    delay(500);
    digitalWrite(PINO_LED_PIR, LOW);

    contagemPisca++;
    caloriasGastas += 23;
    ultimoMovimento = millis();

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Voce andou ");
    lcd.print(contagemPisca);
    lcd.print(" km");

    lcd.setCursor(0, 1);
    lcd.print("Gastou ");
    lcd.print(caloriasGastas);
    lcd.print(" kcal");

    exibindoMensagemPIR = true;
    tempoMensagemPIR = millis();
  }

  //Mensagem de parabéns após atingir 5 km e 115 kcal
  if (contagemPisca == 5 && caloriasGastas == 115) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Parabens! ganhou");
    lcd.setCursor(0, 1);
    lcd.print("    50 moedas");
    moedasGanhas += 50; // Incrementa as moedas ganhas
    delay(5000);
  }

  // Lógica do LDR (sensor de luminosidade)
  if (exibindoMensagemPIR && (millis() - tempoMensagemPIR > 2000)) {
    exibindoMensagemPIR = false;
  }

  if (!exibindoMensagemPIR) {
    int ldrValue = analogRead(LDR_PIN);

    if (ldrValue < 500) {
      digitalWrite(PINO_LED_LDR, HIGH);

      if (!exibindoMensagemLDR) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("   Anoiteceu");
        lcd.setCursor(0, 1);
        lcd.print("  Farol ligado");
        exibindoMensagemLDR = true;
        tempoMensagemLDR = millis() + 3000;
      }
    } else {
      digitalWrite(PINO_LED_LDR, LOW);
      if (exibindoMensagemLDR) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("    Dia claro");
        lcd.setCursor(0, 1);
        lcd.print(" Farol desligado");
        exibindoMensagemLDR = false;
        exibindoMensagemInicial = true;
        delay(3000);
      }
    }
  }

  if (exibindoMensagemInicial) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("     Bike-E");
    lcd.setCursor(0, 1);
    lcd.print("    Mahindra");
    exibindoMensagemInicial = false;
  }

  delay(100);
}
