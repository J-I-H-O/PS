#include <bits/stdc++.h>
using namespace std;

int n, temp, ans = 0;
vector<int> v;
int dp[1001];

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    v.push_back(temp);
  }

  sort(v.begin(), v.end());

  dp[0] = v[0];
  ans += dp[0];
  for(int i = 1; i < n; i++) {
    dp[i] = dp[i-1] + v[i];
    ans += dp[i];
  }

  cout << ans;

  return 0;
}