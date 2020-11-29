#include <LiquidCrystal.h> // inclui a biblioteca para uso do Display LCD
#include <DHT.h>

#define DHTPIN 3
#define DHTTYPE DHT22
// inicializa o objeto que lê temperatura/umidade
DHT dht(DHTPIN, DHTTYPE);

#define BUZZ_PIN 2

// inicializa um objeto nos pinos para acesso as funções do LCD
const int RS = 12, EN = 11, D4 = 10, D5 = 9, D6 = 8, D7 = 7;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup(){
  // Configura o LCD com os número de colunas e linhas
  lcd.begin(16, 2); // 16 colunas e 2 linhas

  // Limpa o LCD
  lcd.clear();

  // inicializa o sensor
  dht.begin();
}

void loop(){

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    lcd.clear();  
    lcd.setCursor(0, 0); // (coluna 0, linha 0)
    lcd.print("Erro de leitura!");
  } else {
    lcd.clear();
    
    // posiciona o cursor do LCD
    lcd.setCursor(0, 0); // (coluna 0, linha 0)
    lcd.print("Temperatura:");
    lcd.setCursor(13, 0);
    lcd.print((int) trunc(t));
    lcd.print("C");

    // posiciona o cursor do LCD
    lcd.setCursor(0, 1); // (coluna 0, linha 0)
    lcd.print("Umidade:");
    lcd.setCursor(13, 1);
    lcd.print((int) trunc(h));
    lcd.print("%");

    if (t >= 32) {
      tone(BUZZ_PIN, 440, 1000);  
    }
  }
 
  delay(2000);
}
