#include <RHReliableDatagram.h>
#include <RH_ASK.h>
#include <SPI.h>

#define CLIENT_ADDRESS 15
#define SERVER_ADDRESS 14
#define BITSPS 2000 // Bits per second

RH_ASK driver(BITSPS, SERVER_ADDRESS, CLIENT_ADDRESS, CLIENT_ADDRESS);
RHReliableDatagram manager(driver, CLIENT_ADDRESS);

void setupTransmitter() {
  if (manager.init()) {
    Serial.println("transmitter initialized");
  } else {
    Serial.println("transmitter init failed");
  }
}

void transmitData(float temper, float humid, int light, int sound) {

  char msg[RH_ASK_MAX_MESSAGE_LEN];
  snprintf(msg, sizeof(msg), "T:%.1f°C,H:%.1f%%,L:%d,S:%d,", temper, humid, light, sound);

  Serial.print("transmitting message : ");
  Serial.print(msg);
  Serial.print(", size : ");
  Serial.println(sizeof(msg));

  manager.sendtoWait((uint8_t*)msg, sizeof(msg), SERVER_ADDRESS);
}