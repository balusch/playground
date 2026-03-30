#include <cassert>
#include <tuple>

std::tuple<int, int, int> rgb() {
  return {32, 64, 128};
}

int main() {
  const auto [red, green, blue] = rgb();
  assert(red + green + blue == 224);
}
