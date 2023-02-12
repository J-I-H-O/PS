#include <bits/stdc++.h>
using namespace std;

vector<int> input;
int dp[301];  // dp[i] : i 번째 계단까지 오르는데 얻을 수 있는 점수의 최댓값
int ans = 0;
int n, temp;


int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    input.push_back(temp);
  }

  // 첫 번째 계단까지 오를 때 점수의 최댓값은 첫 번째 계단 자기자신의 점수
  dp[0] = input[0];
  // 두 번째 계단까지 오를 때 점수의 최댓값은 max(첫 번째 계단 + 두 번째 계단, 두 번째 계단)
  // 이 때 계단에 쓰여있는 점수는 자연수이므로, 최댓값은 첫 번째 계단 + 두 번째 계단
  dp[1] = input[0] + input[1];
  // 세 번째 계단까지 오를 때 점수의 최댓값은 max(첫 번째 계단 + 세 번째 계단, 두 번째 계단 + 세 번째 계단)
  dp[2] = max(input[0] + input[2], input[1] + input[2]);

  // k 번째 계단까지 오를 때 점수가 최대가 되는 경우는 아래 두 가지 경우 중 더 큰 값을 갖는 경우이다.
    // 1. k-2 번째 계단과 k 번째 계단을 선택하는 경우: 
      // k-2 번째 계단까지의 최댓값과 k 번째 계단의 값의 합 계산
    // 2. k-3 번째 계단, k-1 번째 계단과 k 번째 계단을 선택하는 경우 : 
      // k-3 번째 계단까지의 최댓값 + k-1 번째 계단의 값 + k번째 계단의 값 계산
  for(int k = 3; k < n; k++) {
    dp[k] = max(dp[k-2] + input[k], dp[k-3] + input[k-1] + input[k]);
  }

  cout << dp[n-1];

  return 0;
}