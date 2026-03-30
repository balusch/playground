#include <cassert>
#include <optional>
#include <string_view>

std::optional<int> parse_digit(std::string_view text) {
  if (text.size() != 1 || text[0] < '0' || text[0] > '9') {
    return std::nullopt;
  }
  return text[0] - '0';
}

int main() {
  const auto digit = parse_digit("7");
  const auto missing = parse_digit("ab");

  assert(digit.has_value());
  assert(*digit == 7);
  assert(!missing.has_value());
}
