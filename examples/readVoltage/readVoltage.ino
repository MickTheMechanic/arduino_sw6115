#include <SW6115.h>
#include <Wire.h>


#define SW6115_ADDR 0x3C
SW6115 battery = SW6115(SW6115_ADDR);

void setup() {
    Wire.begin();
    Serial.begin(115200);
}

void loop() {
  float vBatt;
  vBatt = battery.readVoltage();
  Serial.println(vBatt,4);
  delay(1000);
}
