#line 1 "c:\\Users\\falve\\OneDrive\\Documents\\Arduino\\libraries\\oprintstream\\oprintstream.ino"
// "Copyright 2021 Francisco Aguilera"

#include <Arduino.h>

#include "src/oprintstream.hpp"

using namespace falven::ad;

#define DEBUG

OPrintStream print(USBDevice);

#line 13 "c:\\Users\\falve\\OneDrive\\Documents\\Arduino\\libraries\\oprintstream\\oprintstream.ino"
void setup();
#line 21 "c:\\Users\\falve\\OneDrive\\Documents\\Arduino\\libraries\\oprintstream\\oprintstream.ino"
void loop();
#line 13 "c:\\Users\\falve\\OneDrive\\Documents\\Arduino\\libraries\\oprintstream\\oprintstream.ino"
void setup() {
  print.begin(9600UL);
  while (!print) {
  }
  DEBUG_LOCATION();
  print << hex << "Testing... " << String("1, 2") << endl;
}

void loop() {}

