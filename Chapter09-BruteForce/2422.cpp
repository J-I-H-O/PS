#include <iostream>
#include <vector>
using namespace std;

int n, m, ans = 0;
int a, b;
bool isImpossible[201][201];
vector<int> selected;

// DFS로 가능한 아이스크림의 조합 개수 세기
void combination(int cur) {
  if (selected.size() == 3) {
    ans++;
    return;
  }

  for (int i = cur + 1; i <= n; i++) {
    // 현재 selected에 들어있는 수들과 i가 불가능한 조합을 갖지 않는 경우(가능한 경우) true
    bool flag = true;
    for (int j = 0; j < selected.size(); j++) {
      if (isImpossible[i][selected[j]]) {
        flag = false;
        break;
      }
    }

    if (flag) {
      selected.push_back(i);
      combination(i);
      selected.pop_back();
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    isImpossible[a][b] = isImpossible[b][a] = true;
  }

  for (int i = 1; i <= n; i++) {
    selected.clear();
    selected.push_back(i);
    combination(i);
  }

  cout << ans;

  return 0;
}