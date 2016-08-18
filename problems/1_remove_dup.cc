// Design an algorithm and write code to remove the duplicate characters in a
// string without using any additional buffer. NOTE: One or two additional
// variables are fine. An extra copy of the array is not.

#include <iostream>
#include <string>
using namespace std;
void removeDuplication(string& str) {
  bool string_bool[256] = {false};
  string::iterator it = str.begin();
  while (it != str.end()) {
    int val = *it;
    if (string_bool[val]) {
      str.erase(it);
    } else {
      string_bool[val] = true;
      ++it;
    }
  }
}

int main() {
  string s("aabbsaccasldfiqlntjkansjdhfkajbg");
  removeDuplication(s);
  cout << s << endl;
  // printf("%s\n", s.c_str());
  return 0;
}