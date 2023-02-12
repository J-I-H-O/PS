#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> dp;

int main() {
  cin >> n;

  dp.push_back(1);
  dp.push_back(1);
  for(int i = 2; i <= n; i++) {
    // 현재 단계의 이친수의 마지막 자리에 대해서,
    // 마지막 자리가 0인 경우: 이전 단계의 마지막 자리가 0과 1 어느 것이어도 관계 없으므로, 이전 단계의 이친수의 수와 같음
    // 마지막 자리가 1인 경우: 2단계 아래인 이친수의 마지막에 무조건 0을 붙여줘야만 현재 단계에서 1을 선택할 수 있음
                          // 2단계 이전의 이친수의 수와 같음

    // 현재 단계의 이친수의 수는 위 두가지 경우를 모두 합한 것과 같다
    dp.push_back(dp[i-2] + dp[i-1]);
  }

  cout << dp[n-1];

  return 0;
}