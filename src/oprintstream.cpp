// "Copyright 2021 Francisco Aguilera"

#include "oprintstream.hpp"

#include <Arduino.h>
#include <USB/USBAPI.h>

namespace falven {
namespace ad {

OPrintStream::OPrintStream(USBDeviceClass &_usb)
    : Serial_(_usb), base_flag_(DEC) {}

OPrintStream::OPrintStream(const OPrintStream &other)
    : Serial_(other), base_flag_(other.base_flag_) {}

OPrintStream &OPrintStream::operator<<(OPrintStream &(*pmf)(OPrintStream &)) {
  return pmf(*this);
}

OPrintStream &OPrintStream::operator<<(const __FlashStringHelper *arg) {
  print(arg);
  return *this;
}

OPrintStream &OPrintStream::operator<<(const arduino::String &arg) {
  print(arg);
  return *this;
}

OPrintStream &OPrintStream::operator<<(const char arg[]) {
  print(arg);
  return *this;
}

OPrintStream &OPrintStream::operator<<(const char arg) {
  print(arg);
  return *this;
}

OPrintStream &OPrintStream::operator<<(unsigned char arg) {
  print(arg, base_flag_);
  return *this;
}

OPrintStream &OPrintStream::operator<<(int arg) {
  print(arg, base_flag_);
  return *this;
}

OPrintStream &OPrintStream::operator<<(unsigned int arg) {
  print(arg, base_flag_);
  return *this;
}

OPrintStream &OPrintStream::operator<<(long arg) {
  print(arg, base_flag_);
  return *this;
}

OPrintStream &OPrintStream::operator<<(unsigned long arg) {
  print(arg, base_flag_);
  return *this;
}

OPrintStream &OPrintStream::operator<<(long long arg) {
  print(arg, base_flag_);
  return *this;
}

OPrintStream &OPrintStream::operator<<(unsigned long long arg) {
  print(arg, base_flag_);
  return *this;
}

OPrintStream &OPrintStream::operator<<(double arg) {
  print(arg);
  return *this;
}

OPrintStream &OPrintStream::operator<<(const Printable &arg) {
  print(arg);
  return *this;
}

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
