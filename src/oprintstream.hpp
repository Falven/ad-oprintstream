// "Copyright 2021 Francisco Aguilera"

#ifndef SRC_LOGGER_HPP_
#define SRC_LOGGER_HPP_

#include <stdlib.h>
#include <string>
#include <Arduino.h>
#include <Print.h>
#include <boost_1_76_0.h>
#include <boost/utility/string_view.hpp>

namespace falven {
namespace ad {

#define DEBUG

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

template <typename T>
Print &operator<<(Print &print, T arg) {
  print.print(arg);
  return print;
}

template <>
Print &operator<<<const std::string &>(Print &print, const std::string &arg) {
  print.print(arg.c_str());
  return print;
}

template <>
Print &operator<<<const boost::string_view &>(Print &print,
                                              const boost::string_view &arg) {
  for (const auto c : arg) {
    print.print(c);
  }
  return print;
}

Print &dec(Print &print, unsigned long arg) {
  printf("%lx\n", arg);
  std::to_string(arg);
  return print;
}

Print &endl(Print &print) {
  print.println();
  print.flush();
  return print;
}

}  // namespace ad
}  // namespace falven

#endif  // SRC_LOGGER_HPP_
