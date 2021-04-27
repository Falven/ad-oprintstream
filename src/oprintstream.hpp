// "Copyright 2021 Francisco Aguilera"

#ifndef SRC_OPRINTSTREAM_HPP_
#define SRC_OPRINTSTREAM_HPP_

#include <Arduino.h>
#include <Print.h>
#include <api/USBAPI.h>

#include <iostream>

namespace falven {
namespace ad {

/**
 * @brief This class is not actually a stream. It does not allocate memory or
 * maintain a sequence of data. It simply provides a more intuitive interface
 * for interacting with the underlying Serial logging class.
 *
 */
class OPrintStream : public Serial_ {
 public:
  /**
   * @brief Constructs a new OPrintStream object using the provided
   * USBDeviceClass
   *
   * @param _usb USB metadata for the Serial connection.
   */
  OPrintStream(USBDeviceClass &_usb) : Serial_(_usb), base_flag_(DEC) {}

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

  /**
   * @brief Prints the provided flash memory string.
   *
   * @param arg The flash memory string to print.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  OPrintStream &operator<<(const __FlashStringHelper *arg) {
    print(arg);
    return *this;
  }

  /**
   * @brief Prints the provided arduino::string.
   *
   * @param arg The arduino::string to print.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  OPrintStream &operator<<(const arduino::String &arg) {
    print(arg);
    return *this;
  }

  /**
   * @brief Prints the provided char[].
   *
   * @param arg The char[] to print.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  OPrintStream &operator<<(const char arg[]) {
    print(arg);
    return *this;
  }

  /**
   * @brief Prints the provided const char.
   *
   * @param arg The const char to print.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  OPrintStream &operator<<(const char arg) {
    print(arg);
    return *this;
  }

  /**
   * @brief Prints the provided unsigned char.
   *
   * @param arg The unsigned char to print.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  OPrintStream &operator<<(unsigned char arg) {
    print(arg, base_flag_);
    return *this;
  }

  /**
   * @brief Prints the provided int.
   *
   * @param arg The int to print.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  OPrintStream &operator<<(int arg) {
    print(arg, base_flag_);
    return *this;
  }

  /**
   * @brief Prints the provided unsigned int.
   *
   * @param arg The unsigned int to print.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  OPrintStream &operator<<(unsigned int arg) {
    print(arg, base_flag_);
    return *this;
  }

  /**
   * @brief Prints the provided long.
   *
   * @param arg The long to print.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  OPrintStream &operator<<(long arg) {
    print(arg, base_flag_);
    return *this;
  }
  /**
   * @brief Prints the provided unsigned long.
   *
   * @param arg The unsigned long to print.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  OPrintStream &operator<<(unsigned long arg) {
    print(arg, base_flag_);
    return *this;
  }

  /**
   * @brief Prints the provided long long.
   *
   * @param arg The long long to print.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  OPrintStream &operator<<(long long arg) {
    print(arg, base_flag_);
    return *this;
  }

  /**
   * @brief Prints the provided unsigned long long.
   *
   * @param arg The unsigned long long to print.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  OPrintStream &operator<<(unsigned long long arg) {
    print(arg, base_flag_);
    return *this;
  }

  /**
   * @brief Prints the provided double.
   *
   * @param arg The double to print.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  OPrintStream &operator<<(double arg) {
    print(arg);
    return *this;
  }

  /**
   * @brief Prints the provided Printable.
   *
   * @param arg The Printable to print.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  OPrintStream &operator<<(const Printable &arg) {
    print(arg);
    return *this;
  }

  /**
   * @brief Manipulator to switch the OPrintStream to printing Decimal number
   * types (Default).
   *
   * @param ops The OPrintStream this manipulator was called on.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  friend OPrintStream &dec(OPrintStream &ops);

  /**
   * @brief Manipulator to switch the OPrintStream to printing Hexadecimal
   * number types.
   *
   * @param ops The OPrintStream this manipulator was called on.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  friend OPrintStream &hex(OPrintStream &ops);

  /**
   * @brief Manipulator to switch the OPrintStream to printing Octal number
   * types.
   *
   * @param ops The OPrintStream this manipulator was called on.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  friend OPrintStream &oct(OPrintStream &ops);

  /**
   * @brief Manipulator to switch the OPrintStream to printing Binary number
   * types.
   *
   * @param ops The OPrintStream this manipulator was called on.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  friend OPrintStream &bin(OPrintStream &ops);

 private:
  /**
   * @brief The current numeral base flag being used.
   *
   */
  uint base_flag_;
};

/**
 *  @brief  Write a newline and flush the stream.
 *
 * This manipulator is often mistakenly used when a simple newline is
 * desired, leading to poor buffering performance. Only call falven::ad::endl
 * when you need to both write a newline /r/n and flush.
 */
OPrintStream &endl(OPrintStream &ops) {
  ops.println();
  ops.flush();
  return ops;
}

/**
 * @brief Manipulator to switch the OPrintStream to printing Decimal number
 * types (Default).
 *
 * @param ops The OPrintStream this manipulator was called on.
 * @return OPrintStream& Returns the OPrintStream reference for continuation.
 */
OPrintStream &dec(OPrintStream &ops) {
  ops.base_flag_ = DEC;
  return ops;
}

/**
 * @brief Manipulator to switch the OPrintStream to printing Hexadecimal number
 * types.
 *
 * @param ops The OPrintStream this manipulator was called on.
 * @return OPrintStream& Returns the OPrintStream reference for continuation.
 */
OPrintStream &hex(OPrintStream &ops) {
  ops.base_flag_ = HEX;
  return ops;
}

/**
 * @brief Manipulator to switch the OPrintStream to printing Octal number
 * types.
 *
 * @param ops The OPrintStream this manipulator was called on.
 * @return OPrintStream& Returns the OPrintStream reference for continuation.
 */
OPrintStream &oct(OPrintStream &ops) {
  ops.base_flag_ = OCT;
  return ops;
}

/**
 * @brief Manipulator to switch the OPrintStream to printing Binary number
 * types.
 *
 * @param ops The OPrintStream this manipulator was called on.
 * @return OPrintStream& Returns the OPrintStream reference for continuation.
 */
OPrintStream &bin(OPrintStream &ops) {
  ops.base_flag_ = BIN;
  return ops;
}

}  // namespace ad
}  // namespace falven

#endif  // SRC_OPRINTSTREAM_HPP_
