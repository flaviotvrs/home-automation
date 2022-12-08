#include <RH_ASK.h>
#include <SPI.h>

#define TXPIN 0

#define RXPIN 0
#define BITSPS 2000 // Bits per second

RH_ASK driver(BITSPS, RXPIN, TXPIN, 0);

void setup()
{
    Serial.begin(9600);
    Serial.println();

    delay(1000);
    Serial.println("starting config");
    
   if (driver.init()) {
     Serial.println("initialized");
   } else {
     Serial.println("init failed");
   }
    
    delay(1000);
}

void loop()
{
   uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
   uint8_t buflen = sizeof(buf);

   if (driver.recv(buf, &buflen)) // Non-blocking
   {
     Serial.println((char*)buf);  
   } else {
     Serial.println(".");
   }

  Serial.println("loop");
  delay(1000);
}