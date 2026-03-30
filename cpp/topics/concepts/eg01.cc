#include <cassert>
#include <concepts>
#include <vector>

template <typename T>
concept ReservableRange = requires(T container, typename T::size_type n) {
  container.reserve(n);
  container.size();
};

template <ReservableRange T>
void grow_for_batch(T &container, typename T::size_type extra) {
  container.reserve(container.size() + extra);
}

int main() {
  std::vector<int> values{1, 2, 3};
  grow_for_batch(values, 10);

  assert(values.capacity() >= 13);
}
