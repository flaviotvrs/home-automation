#define LDR_PIN A0

void setupLight() {
  pinMode(LDR_PIN, INPUT);
}

int readLight() {
  return analogRead(LDR_PIN);
}
