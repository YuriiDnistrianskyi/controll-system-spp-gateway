#include <Arduino.h>

#include "../include/bootManager.hpp"

BootManager bootManager;

void setup() {
  Serial.begin(115200);

  bootManager.setup();
}

void loop() {
  bootManager.loop();
}
