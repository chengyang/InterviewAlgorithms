#include <iostream>
#include <fstream>
#include <string>
#define K 8

using namespace std;

int main() {
  string lines[K];
  string line;
  ifstream fin("example.txt");
  int count = 0;
  if (fin.is_open()) {
    while (getline(fin, line)) {
      lines[count % K] = line;
      count++;
    }
    fin.close();

    int start, cnt;
    if (count < K) {
      start = 0;
      cnt = count;
    } else {
      start = count % K;
      cnt = K;
    }
    for (int i = 0; i < cnt; ++i) {
      cout << lines[(start + i) % K] << endl;
    }
  } else {
    cout << "Unable to open this file!" << endl;
  }
  return 0;
}