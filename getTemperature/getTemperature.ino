#include <SimpleDHT.h>

int pin = 2;
SimpleDHT11 dht;

void setup() {
  Serial.begin(9600);
}

void loop() {
  byte temperature = 0;
  byte humidity = 0;
  byte data[40] = {0};
  // we have to read all of this info in order to know if the sensor works properly
  if (dht.read(pin, &temperature, &humidity, data)) {
    Serial.print("Read DHT11 failed");
    return;
  }
  
  Serial.println("Temperature:" + String((int)temperature)); 
  
  delay(1000);
}
