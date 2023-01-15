#include <bits/stdc++.h>
using namespace std;

int n, temp, sum = 0;
int dp[501][501]; // dp[i][j]: i번째줄 j번째 숫자까지 도달하는데 방문한 수들의 합의 최댓값  

int main() {
  cin >> n;
  
  cin >> temp;
  dp[1][1] = temp;
  for(int i = 2; i <= n; i++) {
    for(int j = 1; j <= i; j++) {
      cin >> temp;
      if(j == 1) {
        dp[i][j] = dp[i-1][j] + temp;
      }
      else if(j == i) {
        dp[i][j] = dp[i-1][j-1] + temp;
      }
      else {
        dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + temp;
      }
    }
  }

  // 삼각형 시작부터 끝까지 연결되는 경로 중 경로 상 값들의 합이 최대가 되는 경로 찾기
  // dp 배열의 n번째 행에 저장된 값들이 해당 수까지 도달하는데 거친 경로 상 값들의 최대합
  int max = 0;
  for(int i = 0; i <= n; i++) {
    if(max < dp[n][i])
      max = dp[n][i];
  }

  cout << max;

  return 0;
}