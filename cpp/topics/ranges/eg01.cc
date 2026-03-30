#include <array>
#include <ranges>

int main() {
  constexpr std::array numbers{1, 2, 3, 4, 5, 6};

  auto pipeline = numbers
      | std::views::filter([](int value) { return value % 2 == 0; })
      | std::views::transform([](int value) { return value * value; });

  int total = 0;
  for (int value : pipeline) {
    total += value;
  }

  return total == 56 ? 0 : 1;
}
