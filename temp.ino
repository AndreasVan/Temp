// Reading Temperature and Humidity  - Last update: AndreasVan 2014-11-05 Vers. 1.2
// Micro controller = Arduino UNO + LCD Shield + DHT22
// this code is public domain, enjoy!


#include "DHT.h"
#include <LiquidCrystal.h>
#define DHTPIN A1    
#define DHTTYPE DHT22  
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  Serial.begin(9600); 
  Serial.println(" Reading Sensor");
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print(" Reading Sensor");
  lcd.setCursor(0,2);
  lcd.print(" Please wait...");
  delay(2000);
  lcd.clear();
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht.readTemperature(true);
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  float hi = dht.computeHeatIndex(f, h);
 
  lcd.setCursor(0,0);
  lcd.print("Temp.: "); 
  lcd.print(t);
  lcd.print(" C ");
  lcd.setCursor(0,2); 
  lcd.print("Humidity: "); 
  lcd.print(h);
  lcd.print(" %\t");

  Serial.print("Humidity: "); 
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: "); 
  Serial.print(t);
  Serial.print(" *C ");
}
