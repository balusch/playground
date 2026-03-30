#include <array>
#include <cassert>
#include <span>
#include <string_view>

int sum(std::span<const int> values) {
  int total = 0;
  for (int value : values) {
    total += value;
  }
  return total;
}

int main() {
  std::array values{1, 2, 3, 4, 5};

  std::span<int> all = values;
  std::span<int> middle = all.subspan(1, 3);

  assert(sum(all) == 15);
  assert(sum(middle) == 9);

  std::string_view label = "span keeps views cheap";
  assert(label.starts_with("span"));
}
