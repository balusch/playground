#include <cassert>
#include <string>
#include <string_view>

std::string_view trim_prefix(std::string_view text, std::string_view prefix) {
  if (text.substr(0, prefix.size()) == prefix) {
    text.remove_prefix(prefix.size());
  }
  return text;
}

int main() {
  const std::string line = "topic:string_view";
  const std::string_view value = trim_prefix(line, "topic:");

  assert(value == "string_view");
  assert(value.data() == line.data() + 6);
}
