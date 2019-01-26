// Include Wire Library for I2C
#include <Wire.h>
// Include NewLiquidCrystal Library for I2C
#include <LiquidCrystal_I2C.h>

// Include DHT Libraries from Adafruit
// Dependant upon Adafruit_Sensors Library
#include "DHT.h";

// Define LCD pinout
const int  en = 2, rw = 1, rs = 0, d4 = 4, d5 = 5, d6 = 6, d7 = 7, bl = 3;
const int i2c_addr = 0x27;
LiquidCrystal_I2C lcd(i2c_addr, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE);

// DHT-11
#define DHTPIN 2       // DHT-11 Output Pin connection to GPIO2 = D4 of ESP8266
#define DHTTYPE DHT11  // DHT Type is DHT 11

// Define Variables
float hum;    // Stores humidity value in percent
float temp;   // Stores temperature value in Celcius

// Setup DHT sensor for normal 16mhz Arduino
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  
  // Set display type as 16 char, 2 rows
  lcd.begin(16,2);
  
  // Initialize DHT-11
  dht.begin();
}

void loop() {
  delay(2000);  // Delay so DHT-22 sensor can stabalize
  
  hum = dht.readHumidity();  // Get Humidity value
  temp= dht.readTemperature();  // Get Temperature value
  
  // Clear the display
  lcd.clear();
  
  // Print temperature on top line
  lcd.setCursor(0,0);
  lcd.print("Temp:  ");
  lcd.print(temp);
  lcd.print(" C");
  
  // Print humidity on bottom line
  lcd.setCursor(0,1);
  lcd.print("Humid: ");
  lcd.print(hum);
  lcd.print(" %");

}
