// "Copyright 2021 Francisco Aguilera"

#include <Arduino.h>

#include <oprintstream.hpp>

using namespace falven::ad;

OPrintStream print(USBDevice);

void setup() {
  print.begin(9600UL);
  while (!print) {
  }
  print << bin << "Testing... " << 1 << " " << 2 << endl;
}

void loop() {}
