#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int n, m, ans = INT_MAX;
int city[50][50];
vector<pair<int, int>> houses;    // <row, col> 집의 좌표 목록
vector<pair<int, int>> chicken;   // <row, col> 치킨집의 좌표 목록
vector<pair<int, int>> selected;  // <row, col> 선택된 치킨집의 좌표 목록

void combination(int cur) {
  // m개의 치킨집을 선택한 경우. 현재 선택한 치킨집들에 대한 치킨거리 계산
  if(selected.size() == m) {
    int cityChickenDist = 0;
    // 각 집에서 현재 선택한 치킨집 중 가장 가까운 치킨집과의 치킨거리 계산
    for(int i = 0; i < houses.size(); i++) {
      int chickenDist = 100;
      for(int j = 0; j < selected.size(); j++) {
        chickenDist = min(chickenDist, abs(houses[i].first - selected[j].first) + abs(houses[i].second - selected[j].second));
      }
      cityChickenDist += chickenDist;
    }
    ans = min(ans, cityChickenDist);
    return;
  }

  for(int i = cur; i < chicken.size(); i++) {
    selected.push_back(chicken[i]);
    combination(i + 1);
    selected.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> city[i][j];
      // 집
      if(city[i][j] == 1) {
        houses.push_back({i, j});
      }
      // 치킨집
      if(city[i][j] == 2) {
        chicken.push_back({i, j});
      }
    }
  }

  combination(0);
  cout << ans;

  return 0;
}