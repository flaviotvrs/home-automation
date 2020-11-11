/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on NodeMCU.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right NodeMCU module
  in the Tools -> Board menu!

  For advanced settings please follow ESP examples :
   - ESP8266_Standalone_Manual_IP.ino
   - ESP8266_Standalone_SmartConfig.ino
   - ESP8266_Standalone_SSL.ino

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#define WARN_LED_PIN 13
#define CON_PIN 12

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "5nAHMKQcF3QxlM8_6Ek7pEczF5vlmlic";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "UNIVERSO_FLAVIO";
char pass[] = "Rede@107";

BLYNK_CONNECTED() {
    Blynk.syncAll();
}

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt();
  digitalWrite(CON_PIN, pinValue);
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  pinMode(WARN_LED_PIN, OUTPUT);
  pinMode(CON_PIN, OUTPUT);
  
  digitalWrite(WARN_LED_PIN, HIGH);
  digitalWrite(CON_PIN, LOW);

  Blynk.begin(auth, ssid, pass);

  if (Blynk.connect()) {
    BLYNK_LOG("Connected.");
    digitalWrite(WARN_LED_PIN, LOW);
  }
}

void loop()
{
  
  if (Blynk.connected()) {
    
    Blynk.run();
    
  } else {
    
    digitalWrite(WARN_LED_PIN, HIGH);
    BLYNK_LOG("Disconnected. Trying to reconnect.");
    
    if (Blynk.connect()) {
      BLYNK_LOG("Reconnected.");
      digitalWrite(WARN_LED_PIN, LOW);
    }
      
  }
  
}
