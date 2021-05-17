// "Copyright 2021 Francisco Aguilera"

#ifndef OPRINTSTREAM_HPP_
#define OPRINTSTREAM_HPP_

#include <USB/USBAPI.h>

#include <algorithm>
#include <type_traits>

namespace falven {
namespace ad {

/**
 * @brief This class is not actually a stream. It does not allocate memory or
 * maintain a sequence of data. It simply provides a more intuitive interface
 * for interacting with the underlying Serial logging class.
 *
 */
template <typename D = void>
class OPrintStream : public Serial_ {
 public:
  using CD = typename std::conditional<std::is_same<D, void>::value,
                                       OPrintStream<D>, D>::type;

  /**
   * @brief Constructs a new OPrintStream object using the provided
   * USBDeviceClass
   *
   * @param _usb USB metadata for the Serial connection.
   */
  explicit OPrintStream(USBDeviceClass &_usb)
      : Serial_(_usb), base_flag_(DEC) {}

  /**
   *  @brief  Interface for manipulators.
   *
   *  Manipulators such as @c falven::ad::endl and @c falven::ad::hex use these
   *  functions in constructs like "falven::ad::cout << falven::ad::endl".  For
   * more information, see the iomanip header.
   */
  auto operator<<(CD &(*pmf)(CD &)) -> CD & {
    return pmf(*(static_cast<CD *>(this)));
  }

  /**
   * @brief Prints the provided flash memory string.
   *
   * @param arg The flash memory string to print.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  auto operator<<(const __FlashStringHelper *arg) -> CD & {
    print(arg);
    return *(static_cast<CD *>(this));
  }

  /**
   * @brief Prints the provided arduino::string.
   *
   * @param arg The arduino::string to print.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  auto operator<<(const arduino::String &arg) -> CD & {
    print(arg);
    return *(static_cast<CD *>(this));
  }

  /**
   * @brief Prints the provided char[].
   *
   * @param arg The char[] to print.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  auto operator<<(const char arg[]) -> CD  // NOLINT(modernize-avoid-c-arrays,
                                           // cppcoreguidelines-avoid-c-arrays)
      & {
    print(arg);
    return *(static_cast<CD *>(this));
  }

  /**
   * @brief Prints the provided const char.
   *
   * @param arg The const char to print.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  auto operator<<(const char arg) -> CD & {
    print(arg);
    return *(static_cast<CD *>(this));
  }

  /**
   * @brief Prints the provided unsigned char.
   *
   * @param arg The unsigned char to print.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  auto operator<<(unsigned char arg) -> CD & {
    print(arg, base_flag_);
    return *(static_cast<CD *>(this));
  }

  /**
   * @brief Prints the provided int.
   *
   * @param arg The int to print.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  auto operator<<(int arg) -> CD & {
    print(arg, base_flag_);
    return *(static_cast<CD *>(this));
  }

  /**
   * @brief Prints the provided unsigned int.
   *
   * @param arg The unsigned int to print.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  auto operator<<(unsigned int arg) -> CD & {
    print(arg, base_flag_);
    return *(static_cast<CD *>(this));
  }

  /**
   * @brief Prints the provided long.
   *
   * @param arg The long to print.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  auto operator<<(long arg) -> CD & {  // NOLINT(google-runtime-int)
    print(arg, base_flag_);
    return *(static_cast<CD *>(this));
  }
  /**
   * @brief Prints the provided unsigned long.
   *
   * @param arg The unsigned long to print.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  auto operator<<(unsigned long arg) -> CD & {  // NOLINT(google-runtime-int)
    print(arg, base_flag_);
    return *(static_cast<CD *>(this));
  }

  /**
   * @brief Prints the provided long long.
   *
   * @param arg The long long to print.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  auto operator<<(long long arg) -> CD & {  // NOLINT(google-runtime-int)
    print(arg, base_flag_);
    return *(static_cast<CD *>(this));
  }

  /**
   * @brief Prints the provided unsigned long long.
   *
   * @param arg The unsigned long long to print.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  auto operator<<(unsigned long long arg)  // NOLINT(google-runtime-int)
      -> CD & {
    print(arg, base_flag_);
    return *(static_cast<CD *>(this));
  }

  /**
   * @brief Prints the provided double.
   *
   * @param arg The double to print.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  auto operator<<(double arg) -> CD & {
    print(arg);
    return *(static_cast<CD *>(this));
  }

  /**
   * @brief Prints the provided Printable.
   *
   * @param arg The Printable to print.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  auto operator<<(const Printable &arg) -> CD & {
    print(arg);
    return *(static_cast<CD *>(this));
  }

  /**
   * @brief Manipulator to switch the OPrintStream to printing Decimal number
   * types (Default).
   *
   * @param ops The OPrintStream this manipulator was called on.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  template <typename FD, typename FCD>
  friend auto dec(FCD &ops) -> FCD &;

  /**
   * @brief Manipulator to switch the OPrintStream to printing Hexadecimal
   * number types.
   *
   * @param ops The OPrintStream this manipulator was called on.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  template <typename FD, typename FCD>
  friend auto hex(FCD &ops) -> FCD &;

  /**
   * @brief Manipulator to switch the OPrintStream to printing Octal number
   * types.
   *
   * @param ops The OPrintStream this manipulator was called on.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  template <typename FD, typename FCD>
  friend auto oct(FCD &ops) -> FCD &;

  /**
   * @brief Manipulator to switch the OPrintStream to printing Binary number
   * types.
   *
   * @param ops The OPrintStream this manipulator was called on.
   * @return OPrintStream& Returns the OPrintStream reference for continuation.
   */
  template <typename FD, typename FCD>
  friend auto bin(FCD &ops) -> FCD &;

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
template <typename D = void,
          typename CD = typename std::conditional<std::is_same<D, void>::value,
                                                  OPrintStream<D>, D>::type>
auto endl(CD &ops) -> CD & {
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
template <typename D = void,
          typename CD = typename std::conditional<std::is_same<D, void>::value,
                                                  OPrintStream<D>, D>::type>
auto dec(CD &ops) -> CD & {
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
template <typename D = void,
          typename CD = typename std::conditional<std::is_same<D, void>::value,
                                                  OPrintStream<D>, D>::type>
auto hex(CD &ops) -> CD & {
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
template <typename D = void,
          typename CD = typename std::conditional<std::is_same<D, void>::value,
                                                  OPrintStream<D>, D>::type>
auto oct(CD &ops) -> CD & {
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
template <typename D = void,
          typename CD = typename std::conditional<std::is_same<D, void>::value,
                                                  OPrintStream<D>, D>::type>
auto bin(CD &ops) -> CD & {
  ops.base_flag_ = BIN;
  return ops;
}

}  // namespace ad
}  // namespace falven

#endif  // OPRINTSTREAM_HPP_
