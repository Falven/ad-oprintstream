#line 1 "c:\\Users\\falve\\OneDrive\\Documents\\Arduino\\libraries\\oprintstream\\src\\oprintstream.hpp"
// "Copyright 2021 Francisco Aguilera"

#ifndef SRC_LOGGER_HPP_
#define SRC_LOGGER_HPP_

#include <Arduino.h>
#include <Print.h>
#include <Stream.h>
#include <api/USBAPI.h>

#include <iostream>

namespace falven {
namespace ad {

// #define DEBUG

// #ifdef DEBUG
// #define DEBUG_LOCATION()                                             \
//   Serial << millis() << "ms: " << __FILE__ << ':' << __LINE__ << ' ' \
//          << __PRETTY_FUNCTION__ << endl;
// #define DEBUG_PRINTLN(str)                                           \
//   Serial << millis() << "ms: " << __FILE__ << ':' << __LINE__ << ' ' \
//          << __PRETTY_FUNCTION__ << ' ' << str << endl;
// #else
// #define DEBUG_LOCATION()
// #define DEBUG_PRINTLN(str)
// #endif

class OPrintStream : public Serial_ {
 public:
  OPrintStream(USBDeviceClass &_usb) : Serial_(_usb) {}

  template <typename T>
  Print &operator<<(T arg) {
    print(arg);
    return *(dynamic_cast<Print *>(this));
  }

  Print &operator<<(Print &(*opsf)(Print &)) { return opsf(*this); }
  // template <>
  // Print &operator<<<const std::string &>(const std::string &arg) {
  //   print(arg.c_str());
  //   return *this;
  // }

  // Print &dec(unsigned long arg) { return *this; }

 private:
};

template <typename T>
Print &operator<<(Print &p, T arg) {
  p.print(arg);
  return p;
}

/**
 *  @brief  Write a newline and flush the stream.
 *
 *  This manipulator is often mistakenly used when a simple newline is
 *  desired, leading to poor buffering performance.  See
 *  https://gcc.gnu.org/onlinedocs/libstdc++/manual/streambufs.html#io.streambuf.buffering
 *  for more on this subject.
 */
Print &endl(Print &ops) {
  ops.println();
  ops.flush();
  return ops;
}

}  // namespace ad
}  // namespace falven

#endif  // SRC_LOGGER_HPP_
