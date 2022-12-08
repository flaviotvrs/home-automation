#define MIC_PIN A0

void setupSound() {
  pinMode(MIC_PIN, INPUT);
}

int readSound() {
  // not working
  return 0;//analogRead(MIC_PIN);
}
