#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, s, b;
vector<pair<int, int>> material;  // <s: 신맛, b: 쓴맛>
vector<pair<int, int>> selected;
bool visited[10];
int ans = 1000000000;

// 모든 재료들 중 1개만 선택 ~ n개를 모두 선택하는 경우를 모두 따져봐야 함
// upperBound: 선택할 수 있는 재료의 최대 개수
void combination(int upperBound, int cur) {
  // 현재 선택 가능한 최대 개수만큼 선택한 경우
  if(selected.size() == upperBound) {
    int res;
    int sour = selected[0].first;      // 현재 선택된 재료들의 신맛
    int bitter = selected[0].second;   // 현재 선택된 재료들의 쓴맛
    for(int i = 1; i < selected.size(); i++) {
      sour *= selected[i].first;
      bitter += selected[i].second;
    }
    res = abs(sour - bitter);

    if(ans > res) ans = res;
    
    return;
  }

  for(int i = cur; i < n; i++) {
    // 이미 선택한 재료인 경우 건너뜀
    if(visited[i]) continue;

    visited[i] = true;
    selected.push_back(material[i]);
    combination(upperBound, i + 1);
    selected.pop_back();
    visited[i] = false;
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> s >> b;
    material.push_back({s, b});
  }

  // i: 선택할 재료의 개수
  for(int i = 1; i <= n; i++) {
    combination(i, 0);
  }

  cout << ans;

  return 0;
}