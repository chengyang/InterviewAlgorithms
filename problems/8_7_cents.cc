#include <iostream>
#define N 25

// If order matters
int GetCents(int n) {
  if (n <= 0) return 0;
  if (n < 5) return 1;
  if (n >= 5 && n < 10) return 2;
  if (n >= 10 && n < 25) return 9;
  return GetCents(n - 1) + GetCents(n - 5) + GetCents(n - 10) +
         GetCents(n - 25);
}

// If order doesn't matter
int GetCents2(int sum, int limit, int n) {
  int ways = 0;
  if (sum <= n) {
    if (sum == n) return 1;
    if (limit >= 25) ways += GetCents2(sum + 25, 25, n);
    if (limit >= 10) ways += GetCents2(sum + 10, 10, n);
    if (limit >= 5) ways += GetCents2(sum + 5, 5, n);
    if (limit >= 1) ways += GetCents2(sum + 1, 1, n);
  }
  return ways;
}

int main() {
  printf("%d\n", GetCents(N));
  printf("%d\n", GetCents2(0, 25, N));
  return 0;
}