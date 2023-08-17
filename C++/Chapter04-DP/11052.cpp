#include <bits/stdc++.h>
using namespace std;

int n;
int price[1001];
int dp[1001]; // dp[i]: 카드 i장을 구매하는데 드는 최대비용

int main() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> price[i];
  }

  dp[1] = price[1];
  for(int i = 2; i <= n; i++) {
    dp[i] = price[i];
    for(int j = 1; j < i; j++) {
      dp[i] = max(dp[i], dp[j] + price[i-j]);
    }
  }

  cout << dp[n];

  return 0;
}