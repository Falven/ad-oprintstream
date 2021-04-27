# 1 "c:\\Users\\falve\\OneDrive\\Documents\\Arduino\\libraries\\oprintstream\\oprintstream.ino"
// "Copyright 2021 Francisco Aguilera"

# 4 "c:\\Users\\falve\\OneDrive\\Documents\\Arduino\\libraries\\oprintstream\\oprintstream.ino" 2

# 6 "c:\\Users\\falve\\OneDrive\\Documents\\Arduino\\libraries\\oprintstream\\oprintstream.ino" 2

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
