#include <cassert>
#include <string>
#include <type_traits>

template <typename T>
std::string describe(T value) {
  if constexpr (std::is_integral_v<T>) {
    return value % 2 == 0 ? "even integer" : "odd integer";
  } else {
    return value.empty() ? "empty string" : "non-empty string";
  }
}

int main() {
  assert(describe(8) == "even integer");
  assert(describe(std::string{"cpp"}) == "non-empty string");
}
