#include <bits/stdc++.h>
using namespace std;

int glasses[10001];
int dp[10001];
int n;

int main() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> glasses[i];
  }

  dp[1] = glasses[1];
  dp[2] = glasses[1] + glasses[2];
  dp[3] = max(max(glasses[1] + glasses[3], glasses[2] + glasses[3]), dp[2]);
  for(int i = 4; i <= n; i++) {
    // 현재 보고있는 포도주를 마시지 않는 경우도 존재.
    // 이전 단계의 최대합이 현재 단계의 최대합보다 큰 경우, 현재 단계의 최대합을 이전 단계의 최대합으로 설정.
    dp[i] = max(max(dp[i-3] + glasses[i-1] + glasses[i], dp[i-2] + glasses[i]), dp[i-1]); 
  }
  cout << dp[n];

  return 0;
}