#include <bits/stdc++.h>
using namespace std;

int n;
int dp[3][1001];    // dp[i][j]: i번 색깔을 이용해 j번 집을 칠했을 때 비용의 최솟값
int cost[3][1001];  // cost[i][j]: i번 색깔을 이용해 j번 집을 칠할 때의 비용

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> cost[0][i] >> cost[1][i] >> cost[2][i];
  }

  dp[0][0] = cost[0][0];
  dp[1][0] = cost[1][0];
  dp[2][0] = cost[2][0];
  for(int i = 1; i < n; i++) {
    dp[0][i] = min(dp[1][i-1] + cost[0][i], dp[2][i-1] + cost[0][i]);
    dp[1][i] = min(dp[0][i-1] + cost[1][i], dp[2][i-1] + cost[1][i]);
    dp[2][i] = min(dp[0][i-1] + cost[2][i], dp[1][i-1] + cost[2][i]);
  }

  cout << min(min(dp[0][n-1], dp[1][n-1]), dp[2][n-1]);

  return 0;
}