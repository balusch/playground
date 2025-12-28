#include "view01.h"

#include <fmt/core.h>

std::string make_greeting(std::string_view name) {
  return fmt::format("hello, {}!", name);
}

#ifndef VIEW01_NO_MAIN
int main() {
  fmt::print("{}\n", make_greeting("modern-cpp"));
}
#endif
