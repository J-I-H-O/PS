#include <iostream>
#include <vector>
using namespace std;

int h, w, n, a, b;
vector<pair<pair<int, int>, int>> sticker;  // <<높이, 너비>, 스티커 번호>
vector<pair<pair<int, int>, int>> selected;
bool visited[100];
int ans = 0;

void combination() {
  if (selected.size() == 2) {
    // 선택한 두 스티커를 가로로 이어붙일 수 있거나, 세로로 이어붙일 수 있는 경우만 고려
    if ((selected[0].first.first + selected[1].first.first <= h &&
         max(selected[0].first.second, selected[1].first.second) <= w) ||
        (selected[0].first.second + selected[1].first.second <= w) &&
            max(selected[0].first.first, selected[1].first.first) <= h) {
      int res = 0;
      for (int i = 0; i < 2; i++) {
        res += (selected[i].first.first * selected[i].first.second);
      }
      if (res > ans) ans = res;
    }

    return;
  }

  for (int i = 0; i < sticker.size(); i++) {
    // i번 스티커가 이미 선택된 경우 건너뜀
    if (visited[sticker[i].second]) continue;

    visited[sticker[i].second] = true;
    selected.push_back(sticker[i]);
    combination();
    selected.pop_back();
    visited[sticker[i].second] = false;
  }
}

int main() {
  cin >> h >> w >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    // 같은 스티커를 회전시킨 경우도 넣어줌. 조합을 통해 선택 시 같은 스티커를
    // 두 번 선택하지 않도록 스티커 번호로 구분
    sticker.push_back({{a, b}, i});
    sticker.push_back({{b, a}, i});
  }

  combination();

  cout << ans;

  return 0;
}