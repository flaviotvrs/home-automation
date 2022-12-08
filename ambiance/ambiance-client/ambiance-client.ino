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
  delay(500);

  float h = readHumidity();
  float t = readTemperature();

  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT sensor!");
  }

  transmitData(t, h);
}

void transmitData(float temper, float humid) {

  char msg[RH_ASK_MAX_MESSAGE_LEN];
  snprintf(msg, sizeof(msg), "T:%f,H:%f", temper, humid);

  Serial.print("transmitting message : ");
  Serial.print(msg);
  Serial.print(", size : ");
  Serial.println(sizeof(msg));

  manager.sendtoWait((uint8_t*)msg, sizeof(msg), SERVER_ADDRESS);
  delay(500);
}
