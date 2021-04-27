// "Copyright 2021 Francisco Aguilera"

#include <Arduino.h>

#include "src/oprintstream.hpp"

using namespace falven::ad;

OPrintStream print(USBDevice);

void setup() {
  print.begin(9600UL);
  while (!print) {
  }

  print.println("Testing");
  // Serial.begin(9600UL);
  // while (!Serial) {
  // }
  // DEBUG_LOCATION();
}

void loop() {
  print << 100UL << endl;
  delay(2000UL);
}
