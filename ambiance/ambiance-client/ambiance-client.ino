#include <RHReliableDatagram.h>
#include <RH_ASK.h>
#include <SPI.h>

#define CLIENT_ADDRESS 15
#define SERVER_ADDRESS 14
#define BITSPS 2000 // Bits per second

RH_ASK driver(BITSPS, SERVER_ADDRESS, CLIENT_ADDRESS, CLIENT_ADDRESS);
RHReliableDatagram manager(driver, CLIENT_ADDRESS);

void setup() {
  Serial.begin(9600);
  Serial.println("Setup started ...");
  setupDht();
  setupTransmitter();
  Serial.print("Setup finished.");
}

void setupTransmitter() {
  if (manager.init()) {
    Serial.println("transmitter initialized");
  } else {
    Serial.println("transmitter init failed");
  }
}

void loop() {
  delay(5000);

  float h = readHumidity();
  float t = readTemperature();

  Serial.print("Temperatura..: ");
  if (isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    Serial.println(t);
  }
  Serial.print("Humidade.....: ");
  if (isnan(h)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    Serial.println(h);
  }
  Serial.println("---");
  
  uint8_t msg[] = "Hello World!";
  transmitData(msg);
}

void transmitData(uint8_t *msg) {
  if(manager.sendtoWait(msg, sizeof(msg), SERVER_ADDRESS)){
    Serial.println("message sent");
  } else {
    Serial.println("failed to send message");
  }
  delay(500);
}
