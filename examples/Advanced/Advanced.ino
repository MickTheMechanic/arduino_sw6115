// Another rediculously good mod by Mick ;)
// MIT licence
// This code is provided as is
// I'm not responsible or liable if stuff breaks or people die as a result of my shitty code



// -----------------------------------------------------------------------------------------
// This example prints all data once every 2 seconds once the battery shield is switched on.
// After ~10 seconds the battery shield switches off
// -----------------------------------------------------------------------------------------



#include <SW6115.h>
#include <Wire.h>


#define SW6115_ADDR 0x3C
SW6115 battery = SW6115(SW6115_ADDR);

uint8_t numChars = 50;
uint8_t count    = 0;


void setup() {
  Wire.begin();
  Serial.begin(115200);
}

void loop() {
  char charBuff [numChars + 1];
  float vBatt     = (battery.readVbatt() / 1000);
  float vOut      = (battery.readVout() / 1000);
  float iChrg     = (battery.readIchrg() / 1000);
  float iDischrg  = (battery.readIdischrg() / 1000);
  float icTemp    = (battery.readTic());
  float vNTC      = (battery.readVntc() / 1000);

  if (vOut < 4) {
    count = 0;
  }
  else {
    snprintf(charBuff, numChars, "Battery voltage: %.5f V", vBatt);
    Serial.println(charBuff);
    snprintf(charBuff, numChars, "Output voltage: %.5f V", vOut);
    Serial.println(charBuff);
    snprintf(charBuff, numChars, "Charging current: %.5f A", iChrg);
    Serial.println(charBuff);
    snprintf(charBuff, numChars, "Discharge current: %.5f A", iDischrg);
    Serial.println(charBuff);
    snprintf(charBuff, numChars, "IC temperature: %.5f °C", icTemp);
    Serial.println(charBuff);
    snprintf(charBuff, numChars, "NTC voltage: %.5f V", vNTC);
    Serial.println(charBuff);
    Serial.println("_______________________________________________");
    Serial.println();
    delay(2000);
    count++;
    if (count == 5) {
      Serial.println("switching off...");
      battery.powerOff();
      delay(500);
      Serial.println("_______________________________________________");
    }
  }
}
