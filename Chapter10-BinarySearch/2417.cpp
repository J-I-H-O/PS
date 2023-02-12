#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

ll binarySearch() {
  ll st = 0;
  ll en = sqrt(n) + 1;

  while(st < en) {
    ll mid = (st + en) / 2;
    if(mid*mid >= n) {
      en = mid; // mid 또한 q의 후보가 될 수 있으므로 범위에 포함시킴
    } else {
      st = mid + 1;
    }
  }

  return st;
}

int main() {
  cin >> n;

  cout << binarySearch();

  return 0;
}