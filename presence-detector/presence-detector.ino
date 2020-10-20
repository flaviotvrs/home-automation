/* HC-SR501 Motion Detector */
#define ledPin 13 // D7 // Red LED
#define pirPin 5 // D1 // Input for HC-SR501
#define buzzPin 12 // D6 // Buzzer

int pirValue; // variable to store read PIR Value

void setup() 
{
  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  pinMode(pirPin, INPUT);
  
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzPin, LOW);
}

void loop() 
{
  pirValue = digitalRead(pirPin);
  Serial.print("Pir: ");
  Serial.println(pirValue);
  
  detect(pirValue);
  
  delay(1000);
}

void detect(int pirValue){
  if (pirValue == HIGH){
    digitalWrite(buzzPin, HIGH);
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(buzzPin, LOW);
    digitalWrite(ledPin, LOW);
  }
}
