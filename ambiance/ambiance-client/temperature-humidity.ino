#include <DHT.h>

#define DHTPIN 2 //GPIO2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setupDht() {
  dht.begin();
  Serial.println("dht initialized");
}

float readHumidity() {
  return dht.readHumidity();
}

float readTemperature() {
  return dht.readTemperature();
}