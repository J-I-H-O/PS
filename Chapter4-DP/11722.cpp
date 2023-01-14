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

    int max_len = 0;
    for(int j = 0; j < i; j++) {
      // 현재(i번째) 원소보다 큰 원소들에 대해
      if(v[j] > v[i]) {
        // 해당 원소(j번째)들을 포함하는 가장 긴 감소하는 부분 수열의 길이 계산
        if(dp[j] > max_len)
          max_len = dp[j];
      }
    }
    // 현재 숫자 이전의 수들 중 가장 긴 감소하는 부분 수열에 현재 원소를 포함시킨
    dp[i] = max_len + 1;
    if(ans < dp[i])
      ans = dp[i];
  }
  cout << ans;

  return 0;
}