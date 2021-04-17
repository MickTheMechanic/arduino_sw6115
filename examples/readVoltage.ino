#include <SW6115.h>
#include <Wire.h>


#define SV6115_ADDR 0x3C
SW6115 battery = SW6115(SW6115_ADDR);

void setup() {
    Wire.begin();
    Serial.begin(115200);
    battery.init();
}

void loop() {
  float vBatt;
  vBatt = battery.readVoltage();
  Serial.println(vBatt);
  delay(1000);
}