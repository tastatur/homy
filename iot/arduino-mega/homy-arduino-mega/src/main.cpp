#include <Arduino.h>
#include "DHT.h"

#define DHTPIN 52
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  dht.begin();
  Serial.begin(9600);
}

void loop() {
  delay(10000);

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

   if (isnan(humidity) || isnan(temperature)) {
     Serial.println("DHT Sensor error");
     return;
   }

   Serial.print("Temperature:");
   Serial.println(temperature);

   Serial.print("Humidity:");
   Serial.println(humidity);
}