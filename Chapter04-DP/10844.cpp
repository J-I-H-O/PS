#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000000;

// dp[i][j] : i자리의 수들 중 마지막 자리가 j인 수들의 개수 저장
int dp[101][10];
int n, ans = 0;

int main() {
  cin >> n;

  // initialize
  dp[1][0] = 0;
  for(int i = 1; i <= 9; i++) {
    dp[1][i] = 1;
  }

  for(int i = 2; i <= n; i++) {
    for(int j = 0; j <= 9; j++) {
      // i자리의 수들 중 마지막 자리가 0인 수의 개수 == i-1 자리의 수들 중 마지막 자리가 1인 수의 개수
      if(j == 0) {
        dp[i][j] = dp[i-1][j+1];
      }
      // i자리의 수들 중 마지막 자리가 9인 수의 개수 == i-1 자리의 수들 중 마지막 자리가 8인 수의 개수
      else if(j == 9) {
        dp[i][j] = dp[i-1][j-1];
      }
      // 나머지의 경우, i-1 자리의 수들 중 마지막 자리가 j-1이거나 j+1인 수의 개수의 합
      else {
        dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
      }
    }
  }

  for(int i = 0; i <= 9; i++) {
    ans = (ans + dp[n][i]) % MOD;
  }
  cout << ans % MOD;

  return 0;
}