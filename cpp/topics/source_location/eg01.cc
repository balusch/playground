#include <cassert>
#include <source_location>
#include <string_view>

std::source_location capture_here(
    const std::source_location where = std::source_location::current()) {
  return where;
}

int main() {
  const auto where = capture_here();
  const std::string_view file = where.file_name();

  assert(file.ends_with("eg01.cc"));
  assert(where.line() > 0);
}
