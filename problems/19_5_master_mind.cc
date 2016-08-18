#include <iostream>

struct Result {
  int hits;
  int pseudo_hits;
};

Result MasterMind(const char* a, const char* b) {
  Result result;
  result.hits = 0;
  result.pseudo_hits = 0;
  for (int i = 0; i < 4; ++i) {
    if (a[i] == b[i]) {
      result.hits++;
    }
  }
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (i != j && b[i] == a[j]) {
        result.pseudo_hits++;
      }
    }
  }
  return result;
}

int main() {
  char a[] = "RYGB";
  char b[] = "YRRR";
  Result r = MasterMind(a, b);

  std::cout << r.hits << "  " << r.pseudo_hits << std::endl;
  return 0;
}