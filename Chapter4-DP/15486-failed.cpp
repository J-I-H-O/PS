#include <bits/stdc++.h>
using namespace std;

long long counseling[2][1500001]; // 0행 : 상담에 필요한 기간, 1행: 해당 상담 비용
long long dp[1500001];  // dp[i]: i번째 상담까지 진행했을 때 얻을 수 있는 최대 비용
int n, ans = 0;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  cin >> n;
  for(int i = 1; i <= n; i++) { 
    cin >> counseling[0][i] >> counseling[1][i];
  
    dp[i] = counseling[1][i];
    for(int j = 1; j < n; j++) {
      // i번째 상담 이전에 j번째 상담을 끝마칠 수 있는 경우
      if(j + counseling[0][j] <= i) {
        dp[i] = max(dp[i], dp[j] + counseling[1][i]);
      }
    }
    //cout << "dp[i] : " << dp[i] << "\n";

    if(i + counseling[0][i] <= n + 1 && ans < dp[i]) {
      ans = dp[i];
    }
  }
  cout << ans;

  return 0;
}