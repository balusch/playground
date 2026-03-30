#include <cassert>
#include <string>
#include <type_traits>
#include <variant>

using Value = std::variant<int, std::string>;

int score(const Value &value) {
  return std::visit(
      [](const auto &item) -> int {
        using T = std::decay_t<decltype(item)>;
        if constexpr (std::is_same_v<T, int>) {
          return item;
        } else {
          return static_cast<int>(item.size());
        }
      },
      value);
}

int main() {
  const Value count = 42;
  const Value name = std::string{"cpp"};

  assert(score(count) == 42);
  assert(score(name) == 3);
}
