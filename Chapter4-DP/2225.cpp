#include <bits/stdc++.h>
using namespace std;

const int MOD = 1'000'000'000;
long long dp[201][201]; // dp[i][j]: i개의 수의 합으로 j를 표현하는 경우의 수
int n, k;

int main() {
  cin >> n >> k;

  // 초기화.
  // 1개의 수로 어떤 수 x를 표현하는 경우의 수는 모두 1임
  for(int x = 0; x <= n; x++) {
    dp[1][x] = 1;
  }

  for(int i = 2; i <= k; i++) {
    for(int j = 0; j <= n; j++) {
      // i개의 수 중 마지막에 더한 수를 t라고 한다. (이 때, t의 범위는 [0, n])
      // i개의 수의 합으로 j를 표현하는 경우의 수는, t를 제외한 i-1개의 수의 합으로 j-t를 표현하는 경우의 수의 합이다.
      for(int t = 0; t <= j; t++) {
        dp[i][j] = (dp[i][j] % MOD + dp[i-1][j-t] % MOD) % MOD;
      }
    }
  }
  cout << dp[k][n];

  return 0;
}