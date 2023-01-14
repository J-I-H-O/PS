#include <bits/stdc++.h>
using namespace std;

int n, temp, ans = 0;
int dp[1001];
vector<int> v;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    v.push_back(temp);

    int max_sum = 0;
    for(int j = 0; j < i; j++) {
      if(v[j] < v[i]) {
        if(dp[j] > max_sum)
          max_sum = dp[j];
      }
    }
    dp[i] = max_sum + temp;
    if(dp[i] > ans)
      ans = dp[i];
  }

  cout << ans;

  return 0;
}