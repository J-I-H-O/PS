#include <bits/stdc++.h>
using namespace std;

const int MOD = 10007;
long long dp[1001][10]; //dp[i][j] : i자리의 수 중 마지막 자리의 수가 j인 수의 개수 저장
int n;
long long ans = 0;

int main() {
  cin >> n;
  for(int i = 0; i <= 9; i++) {
    dp[1][i] = 1;
  }

  for(int i = 2; i <= n; i++) {
    for(int j = 0; j <= 9; j++) {
      for(int k = 0; k <= j; k++) {
        dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
      } 
    }
  }

  for(int i = 0; i <= 9; i++) {
    ans = (ans + dp[n][i]) % MOD;
  }

  cout << ans;

  return 0;
}