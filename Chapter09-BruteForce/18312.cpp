#include <iostream>
using namespace std;

int n, k, ans = 0;

void count(int h, int m, int s) {
  if(h % 10 == k || h / 10 == k || m % 10 == k || m / 10 == k || s % 10 == k || s / 10 == k) {
    ans++;
  }
}

int main() {
  cin >> n >> k;
  for (int h = 0; h <= n; h++) {
    for (int m = 0; m <= 59; m++) {
      for (int s = 0; s <= 59; s++) {
        count(h, m, s);
      }
    }
  }
  cout << ans;

  return 0;
}