// "Copyright 2021 Francisco Aguilera"

#include <Arduino.h>

#include <string>

#include "src/logger.hpp"

// Our printing object.
static auto kLogger = falven::ad::Logger::getInstance();
const static auto kBaudRate = 9600U;

void setup() {
  // Your typical Serial initialization.
  kLogger.begin(kBaudRate);

  std::string testing("Testing... ");
  kLogger << testing << 1 << " " << 2 << falven::ad::endl;
}

void loop() {}
