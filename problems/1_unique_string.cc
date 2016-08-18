// Implement an algorithm to determine if a string has all unique characters.
// What if you can not use additional data structures?
#include <string>
#include <iostream>
using namespace std;

bool isUniqueString1(const string& s) {
  if (s.length() > 256) return false;
  bool string_set[256] = {false};
  for (size_t i = 0; i < s.length(); i++) {
    int val = s.at(i);
    if (string_set[val]) {
      return false;
    }
    string_set[val] = true;
  }
  return true;
}

bool isUniqueString2(const string& s) {
  if (s.length() > 256) return false;
  int checker = 0;
  for (size_t i = 0; i < s.length(); i++) {
    int val = s.at(i) - 'a';
    if ((checker & (1 << val)) > 0) {
      return false;
    }
    checker |= (1 << val);
  }
  return true;
}

int main() {
  string test_string("tesa_ahj");
  cout << "is \"" << test_string << "\""
       << " a unique string? " << (isUniqueString2(test_string) ? "Yes" : "No")
       << endl;
  return 0;
}