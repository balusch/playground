#include <charconv>
#include <expected>
#include <string>
#include <string_view>

std::expected<int, std::string> parse_non_negative(std::string_view text) {
  int value = 0;
  const auto *begin = text.data();
  const auto *end = begin + text.size();
  const auto [ptr, ec] = std::from_chars(begin, end, value);

  if (ec != std::errc{} || ptr != end) {
    return std::unexpected("input is not an integer");
  }
  if (value < 0) {
    return std::unexpected("value must be non-negative");
  }
  return value;
}

int main() {
  auto ok = parse_non_negative("42");
  auto bad = parse_non_negative("-7");

  if (!ok || bad) {
    return 1;
  }
  return *ok == 42 ? 0 : 1;
}
