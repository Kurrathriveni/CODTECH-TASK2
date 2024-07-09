#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11 or DHT 22 sensor type
DHT dht(DHTPIN, DHTTYPE);

// Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // Initialize the DHT sensor
  dht.begin();

  // Initialize the LCD
  lcd.begin(16, 2);

  // Print initial message to the LCD
  lcd.print("Temp: ");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
}

void loop() {
  // Read temperature and humidity
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check if any reads failed
  if (isnan(temperature) || isnan(humidity)) {
    lcd.setCursor(6, 0);
    lcd.print("Error");
    lcd.setCursor(10, 1);
    lcd.print("Error");
    delay(2000);
    return;
  }

  // Print temperature on LCD
  lcd.setCursor(6, 0);
  lcd.print(temperature);
  lcd.print(" C ");

  // Print humidity on LCD
  lcd.setCursor(10, 1);
  lcd.print(humidity);
  lcd.print(" % ");

  // Print temperature and humidity to serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  delay(2000); // Delay for 2 seconds between readings
}
