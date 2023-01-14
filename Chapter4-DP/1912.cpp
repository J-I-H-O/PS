#include <bits/stdc++.h>
using namespace std;

int n, temp, ans;
int dp[100001]; // i번째 원소를 포함한 연속합 중 최댓값을 저장
vector<int> v;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    v.push_back(temp);
  }

  // 수는 한 개 이상 선택되어야 하므로, 첫번째 원소까지의 연속합은 첫번째 원소 자기자신
  dp[0] = v[0];
  ans = v[0];
  for(int i = 1; i < n; i++) {
    // 이전 원소까지의 연속합에 현재 원소를 포함한 것이 현재 원소 자체보다 큰 경우,
    // 현재 원소까지의 연속합의 최댓값은 이전 원소까지의 연속합에 현재 원소를 포함한 것과 같음
    // **즉, 새로 시작하는 것 보다 연속합을 이어나가는 것이 더 큰 경우.**
    if(dp[i-1] + v[i] > v[i]) {
      dp[i] = dp[i-1] + v[i];
    }
    // 연속합을 새로 시작하는 것이 이어나가는 것보다 더 큰 경우
    else {
      dp[i] = v[i];
    }

    if(dp[i] > ans)
      ans = dp[i];
  }

  cout << ans;

  return 0;
}