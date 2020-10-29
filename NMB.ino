#define BLYNK_PRINT Serial
#define DHTPIN 12 //D5
#define SoilNMB A0
#define D0 16
int SoilValueNMB = 0;
int SoilValue = 0;
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
char auth[] = "code";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "wifi";
char pass[] = "pass";
#define WATER_PUMP 4
boolean state = false;

void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(WATER_PUMP, OUTPUT);
    pinMode(D0, OUTPUT);
      pinMode(D1, OUTPUT);
  Serial.println();
  dht.begin();
        digitalWrite(WATER_PUMP,LOW);
}

void loop()

{
  delay(2000);
        digitalWrite(WATER_PUMP,LOW);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
          digitalWrite(D0,LOW);
          digitalWrite(D1,HIGH);
    SoilValueNMB = analogRead(SoilNMB);
    delay (1000);
              digitalWrite(D0,HIGH);
              digitalWrite(D1,HIGH);
                   Serial.print("LOW");
    SoilValue = analogRead(SoilNMB);
                Serial.print(SoilValueNMB);
                Serial.print(SoilValue);
  Serial.print(t);
  Blynk.run();
  delay(100);
  Blynk.virtualWrite(V5, t);
    Blynk.virtualWrite(V6, SoilValueNMB);
      Blynk.virtualWrite(V7, SoilValue);
}
BLYNK_WRITE(V1)
{
  if (state == false) {
    state = true;
    Blynk.notify("You just watered your plant.");
    digitalWrite(WATER_PUMP,HIGH);
    delay(2000);
  }
  else {
    state = false;
    digitalWrite(WATER_PUMP,LOW);
  }
}
