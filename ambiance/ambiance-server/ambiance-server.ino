#include <RHReliableDatagram.h>
#include <RH_ASK.h>
#include <SPI.h>

#define CLIENT_ADDRESS 15
#define SERVER_ADDRESS 14
#define BITSPS 2000 // Bits per second

RH_ASK driver(BITSPS, SERVER_ADDRESS, CLIENT_ADDRESS, CLIENT_ADDRESS);
RHReliableDatagram manager(driver, SERVER_ADDRESS);

void setup() {
  Serial.begin(9600);
  Serial.println("Setup started ...");
  setupReceiver();
  Serial.print("Setup finished.");
}

void setupReceiver() {
  if (manager.init()) {
    Serial.println("receiver initialized");
  } else {
    Serial.println("receiver init failed");
  }
}

uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];

void loop() {
  if (manager.available()) {
    uint8_t size = sizeof(buf);
    uint8_t from;

    if (manager.recvfromAck(buf, &size, &from)) {
      Serial.print("Recebido de 0x");
      Serial.print(from, HEX);
      Serial.print(": ");
      Serial.println((char*)buf);
    }
  }
}