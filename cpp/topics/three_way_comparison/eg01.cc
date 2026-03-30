#include <cassert>
#include <compare>
#include <string>

struct Topic {
  int priority;
  std::string name;

  auto operator<=>(const Topic &) const = default;
};

int main() {
  const Topic basics{1, "span"};
  const Topic advanced{3, "coroutines"};
  const Topic basics_copy{1, "span"};

  assert((basics <=> advanced) < 0);
  assert(basics == basics_copy);
}
