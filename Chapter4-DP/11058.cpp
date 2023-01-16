#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
long long dp[101];  // dp[i]: 버튼을 i번 눌러서 출력할 수 있는 A의 최대 개수

int main() {
  cin >> n;

  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 3;

  for(int i = 1; i <= n; i++) {
    for(int j = 3; j <= n - i; j++) {
      dp[i+j] = max(max(dp[i+j], dp[i]*(j-1)), dp[i+j-1] + 1);
    }
  }
  cout << dp[n];

  return 0;
}