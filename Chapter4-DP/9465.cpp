#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, n;

  cin.tie(0);
  ios::sync_with_stdio(0);

  cin >> t;
  while(t--) {
    int sticker[2][100001];
    int dp[2][100001];  // dp[i][j]: i행 j열의 스티커를 떼어냈을 때, 지금까지 떼어낸 스티커값의 합의 최댓값 저장

    cin >> n;
    for(int i = 0; i < 2; i++) {
      for(int j = 1; j <= n; j++) {
        cin >> sticker[i][j];
      }
    }

    dp[0][0] = dp[1][0] = 0;
    dp[0][1] = sticker[0][1];
    dp[1][1] = sticker[1][1];
    for(int i = 2; i <= n; i++) {
      // 대각선 방향 왼쪽 한칸 또는 두칸의 누적 최대치 비교
      // 세칸 왼쪽의 경우, 다른 행의 이전 스티커가 커버 가능하므로 한칸, 두칸만 고려함.
      dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + sticker[0][i];
      dp[1][i] = max(dp[0][i-1], dp[0][i-2]) + sticker[1][i];
    }
    cout << max(dp[0][n], dp[1][n]) << "\n";
  }
  return 0;
}