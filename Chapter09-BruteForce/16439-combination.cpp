#include <iostream>
#include <vector>
using namespace std;

vector<int> selected; // 선택된 치킨 번호 저장
int preference[30][30];
int n, m, ans = 0;

// m개의 치킨 중 3개의 치킨 선택
void combination(int cur) {
  if(selected.size() == 3) {
    int prefSum = 0;
    // 선택한 치킨들에 대한 각 회원들의 만족도의 합 계산
    for(int i = 0; i < n; i++) {
      prefSum += max(max(preference[i][selected[0]], preference[i][selected[1]]),
                     preference[i][selected[2]]);
    }
    if(ans < prefSum) ans = prefSum;
    
    return;
  }

  for(int i = cur; i < m; i++) {
    selected.push_back(i);
    combination(i + 1);
    selected.pop_back();
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> preference[i][j];
    }
  }

  combination(0);

  cout << ans;

  return 0;
}