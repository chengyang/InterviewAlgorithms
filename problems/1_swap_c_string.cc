// Implement a function void reverse(char* str) in C or C++ which reverses a
// nullterminated string. (C-String means that “abcd” is represented as five
// characters, including the null character.)
// note strlen() will give you the the length of the char* without the
// terminateor
#include <iostream>

void reverse1(char(&str)[7]) {
  int length = strlen(str);
  int traverse = length / 2;
  for (int i = 0; i < traverse; i++) {
    char temp = str[i];
    str[i] = str[length - i - 1];
    str[length - i - 1] = temp;
  }
}

int main() {
  char string[] = "d9sf0A";
  reverse1(string);
  std::cout << string << std::endl;
  return 0;
}
