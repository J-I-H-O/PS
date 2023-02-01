#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;

int main() {
  cin >> n;

  while (n % 5 != 0 && n > 0) {
    n -= 2;
    ans++;
  }
  while (n > 0) {
    n -= 5;
    ans++;
  }

  if (n == 0) {
    cout << ans;
  } else {
    cout << -1;
  }

  return 0;
}