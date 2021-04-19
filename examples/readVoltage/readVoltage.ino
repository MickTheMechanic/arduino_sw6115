// Another rediculously good mod by Mick ;)
// MIT licence
// This code is provided as is
// I'm not responsible or liable if stuff breaks or people die as a result of my shitty code



// -------------------------------------------------------
// This example prints the battery voltage every 2 seconds
// -------------------------------------------------------



#include <SW6115.h>
#include <Wire.h>


#define SW6115_ADDR 0x3C
SW6115 battery = SW6115(SW6115_ADDR);

void setup() {
    Wire.begin();
    Serial.begin(9600);
}

void loop() {
  float vBatt = battery.readVbatt();
  Serial.println(vBatt,5);
  delay(2000);
}
