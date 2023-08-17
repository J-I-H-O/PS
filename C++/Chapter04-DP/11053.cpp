#include <bits/stdc++.h>
using namespace std;

int n, temp, ans = 0;
int dp[1001]; // i번째 원소까지의 수열 중 가장 긴 증가하는 수열의 길이 저장
vector<int> v;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    v.push_back(temp);

    int max_len = 0;  // 현재 보고있는 원소(j번째)까지의 수열 중 가장 긴 증가하는 수열
    for(int j = 0; j < i; j++) {
      // 현재 입력받은 수 이전에 입력받은 수 중, 현재 입력받은 수보다 작은 수들에 대하여
      // 해당 수들 까지의 수열 중 가장 긴 것에 현재 수를 포함시킨 것이 현재 수까지의 수열 중 가장 긴 증가하는 부분 수열
      if(v[j] < v[i]) {
        if(dp[j] > max_len)
          max_len = dp[j];
      }
    }
    dp[i] = max_len + 1;
    if(dp[i] > ans)
      ans = dp[i];
  }

  cout << ans;
 
  return 0;
}