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
    // i 자리의 수 중 마지막 자리가 0으로 끝나는 수는 각각 1가지씩 존재
    dp[i][0] = 1;
    // dp[i][j-1]이 이미 dp[i-1][0]~dp[i-1][9]의 오르막 수의 개수를 계산해둔 상태.
    // dp[i][j]는 이미 계산된 dp[i][j-1]에 dp[i-1][j]만 더해주면 됨.
    for(int j = 1; j <= 9; j++) {
      dp[i][j] = (dp[i][j-1] % MOD + dp[i-1][j] % MOD) % MOD;
    }
  }

  for(int i = 0; i <= 9; i++) {
    ans = (ans % MOD + dp[n][i] % MOD) % MOD;
  }

  cout << ans;

  return 0;
}