#include <RCSwitch.h>

RCSwitch myswitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  myswitch.enableReceive(0);
  Serial.println("Receiver configured!");
}

void loop() {

  if (myswitch.available()) {

    int value = myswitch.getReceivedValue();

    if (value == 0) {
      Serial.println("Unknown encoding!");
    } else {
      Serial.print("Received: ");
      Serial.println(value);
    }

    mySwitch.resetAvailable();

  } else {
    Serial.println("Not available!");
  }
  

}
