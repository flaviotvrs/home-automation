void setup() {
  Serial.begin(9600);
  Serial.println("Setup started ...");
  setupDht();
  setupSound();
  setupLight();
  setupTransmitter();
  Serial.print("Setup finished.");
}

void loop() {
  delay(1000);

  float h = readHumidity();
  float t = readTemperature();

  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT sensor!");
  }

  int s = readSound();

  if (isnan(s)) {
    Serial.println("Failed to read from Mic!");
  }

  int l = readLight();
  
  if (isnan(l)) {
    Serial.println("Failed to read from LDR sensor!");
  }

  transmitData(t, h, l, s);
}
