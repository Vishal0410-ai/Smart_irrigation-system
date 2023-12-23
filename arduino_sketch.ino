
#include "DHT.h"

#define DHTPIN 2 
#define DHTTYPE DHT11   // DHT 11
#define PUMP_PIN 9
int sensor_pin = A0;
int output_value;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(PUMP_PIN,OUTPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  
  delay(2000);
  output_value= analogRead(sensor_pin);
  
  Serial.print(output_value);
  Serial.print("x");
  digitalWrite(6,HIGH);
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print(t);
  //Serial.print(F("%  Temperature: "));
  Serial.print("x");
  Serial.println(h);
  
  while (Serial.available() == 1) {
  char command = Serial.read();
  // turn on/off water pump based on command
    if (command == '1') {
      digitalWrite(PUMP_PIN, HIGH);
    } 
    else {
      digitalWrite(PUMP_PIN, LOW);
    }
  }
  
}
