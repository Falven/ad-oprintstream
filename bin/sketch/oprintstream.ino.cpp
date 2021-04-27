#line 1 "c:\\Users\\falve\\OneDrive\\Documents\\Arduino\\libraries\\oprintstream\\oprintstream.ino"
// "Copyright 2021 Francisco Aguilera"

#include <Arduino.h>

#include "src/oprintstream.hpp"

using namespace falven::ad;

OPrintStream print(USBDevice);

#line 11 "c:\\Users\\falve\\OneDrive\\Documents\\Arduino\\libraries\\oprintstream\\oprintstream.ino"
void setup();
#line 23 "c:\\Users\\falve\\OneDrive\\Documents\\Arduino\\libraries\\oprintstream\\oprintstream.ino"
void loop();
#line 11 "c:\\Users\\falve\\OneDrive\\Documents\\Arduino\\libraries\\oprintstream\\oprintstream.ino"
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

