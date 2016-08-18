#include <iostream>

void ReplaceSpace(std::string& str) {
  std::string replace_str("%20");
  std::string::iterator it = str.begin();
  while (it != str.end()) {
    if (*it == ' ') {
      str.replace(it, it + 1, replace_str);
      it += 2;
    }
    ++it;
  }
}

int main() {
  std::string s = "a ab ncc ";
  ReplaceSpace(s);
  printf("%s\n", s.c_str());
  return 0;
}