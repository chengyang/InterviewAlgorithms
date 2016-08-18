#include <iostream>
#include <algorithm>

using namespace std;
// when you want to print the sorted string
// bool compare(string& s1, string& s2) {
//  sort(&s1[0], &s1[0] + s1.length());
//  sort(&s2[0], &s2[0] + s2.length());
//  return s1 < s2;
//}

bool compare(string s1, string s2) {
  sort(&s1[0], &s1[0] + s1.length());
  sort(&s2[0], &s2[0] + s2.length());
  return s1 < s2;
}

int main() {
  string s[] = {"axyz", "abc", "yzax", "bac", "zyxa", "fg", "gf"};
  sort(s, s + 7, compare);
  for (int i = 0; i < 7; i++) {
    cout << s[i] << endl;
  }
  return 0;
}