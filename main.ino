#define BLYNK_TEMPLATE_ID "TMPL3LbU-g5ve"             /// give your template id here
#define BLYNK_TEMPLATE_NAME "Smart Home Security"
#define BLYNK_AUTH_TOKEN "FLg4nGNMaMsFHIEdatIQZPzQb3nU63yL"            /// token id here

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

#define DHTPIN 4
#define PIR_PIN 13
#define FLAME_PIN 34
#define RELAY_PIN 26
#define BUZZER_PIN 27

DHT dht(DHTPIN, DHT22);

void setup() {
  Serial.begin(115200);

  pinMode(PIR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Relay OFF (active LOW relay)
  digitalWrite(RELAY_PIN, HIGH);
  digitalWrite(BUZZER_PIN, LOW);

  dht.begin();
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int pir = digitalRead(PIR_PIN);
  int flameValue = analogRead(FLAME_PIN);

  // Send sensor updates
  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, humidity);
  Blynk.virtualWrite(V2, pir);
  Blynk.virtualWrite(V4, flameValue);

  bool alarm = false;

  // ------------ PIR MOTION ------------
  if (pir == 1) {
    Serial.println("Motion Detected!");

    alarm = true;

    digitalWrite(RELAY_PIN, HIGH);   // Relay ON → LED ON
    digitalWrite(BUZZER_PIN, HIGH);

    Blynk.virtualWrite(V5, 1);      // House light ON
    Blynk.virtualWrite(V10, 1);     // Alarm ON
  }
  else {
    digitalWrite(RELAY_PIN, LOW);  // Relay OFF
    Blynk.virtualWrite(V5, 0);      // House light OFF
  }

  // ------------ FLAME DETECTION ------------
  if (flameValue > 2000) {
    Serial.println("Flame Detected!");

    alarm = true;

    Blynk.virtualWrite(V4, 1);    // Flame widget ON
    Blynk.virtualWrite(V10, 1);   // Alarm ON

    digitalWrite(BUZZER_PIN, HIGH);
  }

  // ------------ IF NO ALARM ------------
  if (!alarm) {
    digitalWrite(BUZZER_PIN, LOW);
    Blynk.virtualWrite(V10, 0);   // Alarm OFF
  }

  delay(50);
}
