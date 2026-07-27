#include <Arduino.h>

#include "../include/configStorage.hpp"
#include "../include/bootManager.hpp"

ConfigStorage configStorage;
BootManager bootManager;

void setup() {
  Serial.begin(115200);

  configStorage.begin();
  bootManager.setup();

}

void loop() {
  bootManager.loop();
}
