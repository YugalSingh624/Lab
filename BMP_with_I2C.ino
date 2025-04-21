

#include <Wire.h>
#include <Adafruit_BMP085.h>  // Or use <Adafruit_BMP280.h> for BMP280
#include <LiquidCrystal_I2C.h>

Adafruit_BMP085 bmp;  // Change to BMP280 if needed
LiquidCrystal_I2C lcd(0x27, 16, 2); // Check your I2C address (0x27 is common)

void setup() {
  lcd.begin(16, 2);  // 👈 Fix applied here
  lcd.backlight();
  
  if (!bmp.begin()) {
    lcd.print("Sensor error");
    while (1);
  }
}

void loop() {
  float temp = bmp.readTemperature();  // Celsius
  float pressure = bmp.readPressure() / 100.0;  // hPa

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Pres: ");
  lcd.print(pressure);
  lcd.print(" hPa");

  delay(2000);
}
