#include <bits/stdc++.h>
using namespace std;

int n, k, weight, value;
vector<pair<int, int>> stuff; // <무게, 가치>
int dp[101][100001];  // dp[row][col]: row번 물건까지 넣는 경우에서 무게가 col일 때 가치의 최댓값

int main() {
  cin >> n >> k;
  stuff.push_back({0, 0});  // dummy data
  for(int i = 1; i <= n; i++) {
    cin >> weight >> value;
    stuff.push_back({weight, value});
  }

  // col: 현재 무게 제한, rowL 
  // 배낭의 무게 제한을 차례로 늘려가며 최대 
  for(int col = 1; col <= k; col++) {
    for(int row = 1; row <= n; row++) {
      // 현재 무게 제한(col)보다 현재 보고있는 물건(stuff[row])의 무게가 큰 경우
      // 즉 배낭에 물건을 담을 수 없는 경우
      // 물건을 담지 않음. 이전 물건을 살펴볼 때의 가치의 최대값을 넣어줌
      if(stuff[row].first > col) {
        dp[row][col] = dp[row-1][col];
      }
      else {
        // 현재 물건을 담을 수 있는 경우
        // 현재 물건을 넣기 전 이전 배낭 상태와, 이전에 넣은 물건을 빼내고 현재 물건을 넣는 경우를 비교
        dp[row][col] = max(dp[row-1][col], dp[row - 1][col - stuff[row].first] + stuff[row].second);
      }
    }
  }
  cout << dp[n][k];

  return 0;
}