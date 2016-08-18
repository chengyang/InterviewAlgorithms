#include <iostream>
#define N 4

void print_pare(int l, int r, char str[], int count) {
  if (l < 0 || r < l) {
    return;
  }
  if (l == 0 && r == 0) {
    for (int i = 0; i < count; ++i) {
      printf("%c", str[i]);
    }
    printf("\n");
  } else {
    if (l > 0) {
      str[count] = '(';
      print_pare(l - 1, r, str, count + 1);
    }
    if (r > l) {
      str[count] = ')';
      print_pare(l, r - 1, str, count + 1);
    }
  }
}

int main() {
  char str[N * 2];
  print_pare(N, N, str, 0);
  return 0;
}