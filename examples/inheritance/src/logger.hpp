// "Copyright 2021 Francisco Aguilera"

#ifndef INCLUDE_LOGGER_HPP_
#define INCLUDE_LOGGER_HPP_

#include <USB/USBAPI.h>

#include <oprintstream.hpp>
#include <string>

namespace falven {
namespace ad {

class Logger : public OPrintStream<Logger> {
 public:
  static auto getInstance() -> Logger & {
    static Logger instance(  // NOLINT(bugprone-dynamic-static-initializers)
        USBDevice);
    return instance;
  }

  explicit Logger(USBDeviceClass &usb) : OPrintStream<Logger>(usb) {}

  void begin(uint32_t baudRate) {
    static_cast<Serial_ *>(this)->begin(baudRate);
    while (!Serial) {
    }
  }

  /**
   * @brief Prints the string referenced by the provided std::string.
   *
   * @param arg The std::string to print.
   * @return OPrintStream& Returns the OPrintStream reference for
   * continuation.
   */
  auto operator<<(const std::string &arg) -> OPrintStream<Logger> & {
    print(arg.data());
    return *this;
  }

  using OPrintStream<Logger>::operator<<;
};

}  // namespace ad
}  // namespace falven

#endif  // INCLUDE_LOGGER_HPP_
