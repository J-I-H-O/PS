#include <bits/stdc++.h>
using namespace std;

const int MOD = 10007;
vector<long long> dp;
int n;

int main() {
  cin >> n;
  
  dp.push_back(1);
  dp.push_back(2);
  for(int i = 2; i < n; i++) {
    dp.push_back((dp[i-2] % MOD + dp[i-1] % MOD) % MOD);
  }

  cout << dp[n-1];

  return 0;
}