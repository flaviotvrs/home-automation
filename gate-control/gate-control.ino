#include <VirtualWire.h>

#define pinRF  12


struct Token {
  int code;
};

Token token;
uint8_t buf[sizeof(token)];
uint8_t buflen = sizeof(token);

void setup() {
  vw_set_rx_pin(pinRF);
  vw_setup(2000);
  vw_rx_start();
  Serial.begin(9600);
}

void loop() {

  if ( vw_have_message() ) {
    vw_get_message(buf, &buflen);
    memcpy(&token,&buf,buflen);

    
    Serial.print("Recebido: ");
    Serial.println(token.code);

  }  
}
