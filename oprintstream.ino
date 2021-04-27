// "Copyright 2021 Francisco Aguilera"

#include <Arduino.h>

#include "src/oprintstream.hpp"

using namespace falven::ad;

#define DEBUG

OPrintStream print(USBDevice);

void setup() {
  print.begin(9600UL);
  while (!print) {
  }
  print << hex << "Testing... " << String("1, 2") << endl;
}

void loop() {}
