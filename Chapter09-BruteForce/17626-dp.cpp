#include <iostream>
#include <vector>
using namespace std;

const int INF = 5;
int n;
vector<int> squares;
int dp[50001];  // dp[i]: 정수 i를 표현할 때 사용되는 제곱수의 최소 개수

int main() {
  fill_n(dp, 50001, INF);

  cin >> n;
  for(int i = 1; i*i <= n; i++) {
    squares.push_back(i*i);
    dp[i*i] = 1;  // 제곱수는 제곱수 자체로 표현됨
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j*j < i; j++) {
      dp[i] = min(dp[i], dp[i - j*j] + 1);
    }
  }

  cout << dp[n];

  return 0;
}