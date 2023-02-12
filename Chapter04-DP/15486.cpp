#include <bits/stdc++.h>
using namespace std;

int counseling[2][1500001]; // 0행 : 상담에 필요한 기간, 1행: 해당 상담 비용
int dp[1500001];  // dp[i]: i번째 상담까지 진행했을 때 얻을 수 있는 최대 비용
int n, ans = 0, curMax;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  cin >> n;
  for(int i = 1; i <= n; i++) { 
    cin >> counseling[0][i] >> counseling[1][i];
  }

  for(int i = 1; i <= n; i++) {
    curMax = max(curMax, dp[i]);
    if(i + counseling[0][i] <= n+1) {
      dp[i + counseling[0][i]] = max(dp[i + counseling[0][i]], curMax + counseling[1][i]);

      ans = max(ans, dp[i + counseling[0][i]]);
      }
  }

  cout << ans;

  return 0;
}