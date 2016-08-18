#include <iostream>
#include <unordered_set>
using namespace std;

bool FindString(const unordered_set<string>& stringset, const string& key) {
  int start = 0;
  int length = 1;
  while (start + length <= key.length()) {
    string str = key.substr(start, length);
    cout << str << endl;
    unordered_set<string>::const_iterator got = stringset.find(str);
    if (got == stringset.end()) {
      if (start + length == key.length()) {
        return false;
      }
      length++;
    } else {
      // cout << str << endl;
      start = start + length;
      length = 1;
      if (start == key.length()) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  string a[] = {"test",  "tester",  "testertest", "testing",
                "apple", "seattle", "banana",     "batting",
                "ngcat", "batti",   "bat",        "testingtester"};

  unordered_set<string> strings(a, a + 13);
  string s = "testbattingcat";

  std::cout << FindString(strings, s) << std::endl;
  return 0;
}