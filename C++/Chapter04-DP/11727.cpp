#include <bits/stdc++.h>
using namespace std;

vector<long long> dp;
int n;

int main() {
  cin >> n;

  dp.push_back(1);
  dp.push_back(3);
  for(int i = 2; i < n; i++) {
    dp.push_back((dp[i-1] % 10007 + ((dp[i-2] % 10007) * 2) % 10007) % 10007);
  }

  cout << dp[n-1];

  return 0;
}