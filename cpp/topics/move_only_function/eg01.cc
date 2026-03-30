#include <functional>
#include <memory>

int main() {
  auto counter = std::make_unique<int>(0);

  std::move_only_function<int()> next = [state = std::move(counter)]() mutable {
    *state += 1;
    return *state;
  };

  const int first = next();
  const int second = next();

  return (first == 1 && second == 2) ? 0 : 1;
}
