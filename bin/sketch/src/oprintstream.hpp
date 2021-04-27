#line 1 "c:\\Users\\falve\\OneDrive\\Documents\\Arduino\\libraries\\oprintstream\\src\\oprintstream.hpp"
// "Copyright 2021 Francisco Aguilera"

#ifndef SRC_LOGGER_HPP_
#define SRC_LOGGER_HPP_

#include <Arduino.h>
#include <Print.h>
#include <Stream.h>
#include <api/USBAPI.h>

#include <iostream>

#ifdef DEBUG
#define DEBUG_LOCATION()                                             \
  Serial << millis() << "ms: " << __FILE__ << ':' << __LINE__ << ' ' \
         << __PRETTY_FUNCTION__ << endl;
#define DEBUG_PRINTLN(str)                                           \
  Serial << millis() << "ms: " << __FILE__ << ':' << __LINE__ << ' ' \
         << __PRETTY_FUNCTION__ << ' ' << str << endl;
#else
#define DEBUG_LOCATION()
#define DEBUG_PRINTLN(str)
#endif

namespace falven {
namespace ad {

/**
 * @brief This class is not actually a stream. It does not allocate memory or
 * maintain a sequence of data. It simply provides a more intuitive interface
 * for interacting with the underlying Stream class.
 *
 */
class OPrintStream : public Serial_ {
 public:
  OPrintStream(USBDeviceClass &_usb) : Serial_(_usb), base_flag_(DEC) {}

  //@{
  /**
   *  @brief  Interface for manipulators.
   *
   *  Manipulators such as @c falven::ad::endl and @c falven::ad::hex use these
   *  functions in constructs like "falven::ad::cout << falven::ad::endl".  For
   * more information, see the iomanip header.
   */
  OPrintStream &operator<<(OPrintStream &(*pmf)(OPrintStream &)) {
    return pmf(*this);
  }

  OPrintStream &operator<<(const __FlashStringHelper *arg) {
    print(arg);
    return *this;
  }

  OPrintStream &operator<<(const arduino::String &arg) {
    print(arg);
    return *this;
  }

  OPrintStream &operator<<(const char arg[]) {
    print(arg);
    return *this;
  }

  OPrintStream &operator<<(const char arg) {
    print(arg);
    return *this;
  }

  OPrintStream &operator<<(unsigned char arg) {
    print(arg, base_flag_);
    return *this;
  }

  OPrintStream &operator<<(int arg) {
    print(arg, base_flag_);
    return *this;
  }

  OPrintStream &operator<<(unsigned int arg) {
    print(arg, base_flag_);
    return *this;
  }

  OPrintStream &operator<<(long arg) {
    print(arg, base_flag_);
    return *this;
  }

  OPrintStream &operator<<(unsigned long arg) {
    print(arg, base_flag_);
    return *this;
  }

  OPrintStream &operator<<(long long arg) {
    print(arg, base_flag_);
    return *this;
  }

  OPrintStream &operator<<(unsigned long long arg) {
    print(arg, base_flag_);
    return *this;
  }

  OPrintStream &operator<<(double arg) {
    print(arg);
    return *this;
  }

  OPrintStream &operator<<(const Printable &arg) {
    print(arg);
    return *this;
  }

  friend OPrintStream &dec(OPrintStream &ops);
  friend OPrintStream &hex(OPrintStream &ops);
  friend OPrintStream &oct(OPrintStream &ops);
  friend OPrintStream &bin(OPrintStream &ops);

 private:
  uint base_flag_;
};

/**
 *  @brief  Write a newline and flush the stream.
 *
 *  This manipulator is often mistakenly used when a simple newline is
 *  desired, leading to poor buffering performance.  See
 *  https://gcc.gnu.org/onlinedocs/libstdc++/manual/streambufs.html#io.streambuf.buffering
 *  for more on this subject.
 */
OPrintStream &endl(OPrintStream &ops) {
  ops.println();
  ops.flush();
  return ops;
}

OPrintStream &dec(OPrintStream &ops) {
  ops.base_flag_ = DEC;
  return ops;
}

OPrintStream &hex(OPrintStream &ops) {
  ops.base_flag_ = HEX;
  return ops;
}

OPrintStream &oct(OPrintStream &ops) {
  ops.base_flag_ = OCT;
  return ops;
}

OPrintStream &bin(OPrintStream &ops) {
  ops.base_flag_ = BIN;
  return ops;
}

}  // namespace ad
}  // namespace falven

#endif  // SRC_LOGGER_HPP_
