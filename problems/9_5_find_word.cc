#include <iostream>
using namespace std;

int FindWord(string s[], string target, int low, int high) {
  while (low <= high) {
    int middle = (low + high) / 2;
    int t = middle;
    while (s[t] == "" && t <= high) t++;
    if (t > high) {
      high = middle - 1;
    } else if (s[t] == target) {
      return t;
    } else if (s[t] < target) {
      low = t + 1;
    } else {
      high = middle - 1;
    }
  }
  return -1;
}

int main() {
  string s[] = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
  cout << FindWord(s, "dsfs", 0, 12) << endl;
  return 0;
}