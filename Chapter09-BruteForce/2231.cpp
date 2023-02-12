#include <iostream>
using namespace std;

int main() {
  int n;

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int cur = i;
    int sum = 0;
    while (cur > 0) {
      sum += cur % 10;
      cur /= 10;
    }
    sum += i;

    if (sum == n) {
      cout << i;
      return 0;
    }
  }
  cout << 0;

  return 0;
}