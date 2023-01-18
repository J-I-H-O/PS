#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int dp[1001][1001]; // dp[i][j]: i행 까지의 s1과 j열 까지의 s2를 비교했을 때 두 문자열의 LCS의 길이

// https://ongveloper.tistory.com/36
// https://melonicedlatte.com/algorithm/2018/03/15/181550.html

int main() {
  cin >> s1 >> s2;
  for(int i = 1; i <= s1.size(); i++) {
    for(int j = 1; j <= s2.size(); j++) {
      // 현재 비교하고 있는 s1의 문자와 s2의 문자가 같은 경우, 
      // 현재까지의 LCS 길이는 s1의 이전 문자와 s2의 이전 문자를 비교했을 때의 + 1
      if(s1[i-1] == s2[j-1]) {
        dp[i][j] = dp[i-1][j-1] + 1;
      }
      // 현재 비교하고 있는 s1의 문자와 s2의 문자가 다른 경우, 현재까지의 LCS 길이는 이전 단계의 LCS 길이와 같음.
      // 이 때 두 문자열 모두에서의 이전 단계를 고려해야하므로 바로 이전 행의 dp값과 이전 열의 dp값 중 최대값을 선택한다.
      else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }

  cout << dp[s1.size()][s2.size()];

  return 0;
}