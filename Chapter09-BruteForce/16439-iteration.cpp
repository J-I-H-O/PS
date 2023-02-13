#include <algorithm>
#include <iostream>
using namespace std;

int n, m;
int preference[30][30];

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> preference[i][j];
    }
  }

  // i, j, k번 치킨을 선택했을 경우 각 회원들의 만족도의 합 계산
  int ans = 0;
  for (int i = 0; i < m - 2; i++) {
    for (int j = i + 1; j < m - 1; j++) {
      for (int k = j + 1; k < m; k++) {
        int prefSum = 0;
        // 각 회원의 만족도 계산
        // 시킨 치킨(i, j, k번) 중 선호도가 가장 큰 값 선택
        for (int member = 0; member < n; member++) {
          prefSum += max(max(preference[member][i], preference[member][j]),
                         preference[member][k]);
        }
        if (ans < prefSum) ans = prefSum;
      }
    }
  }
  cout << ans;

  return 0;
}