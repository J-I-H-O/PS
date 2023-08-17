#include <iostream>
#include <vector>
using namespace std;

int n, ans = 40000;
int teamStat[20][20];
vector<int> selected;
bool visited[20];

// 현재까지 선택된 사람들의 능력치 합과 선택되지 않은 사람들의 능력치 합의 차를 비교

void combination(int uppderBound, int cur) {
  if(selected.size() == uppderBound) {
    int selectedSum = 0;    // 선택된 사람들의 능력치 합
    int unSelectedSum = 0;  // 선택되지 않은 사람들의 능력치 합
    int teamDiff = 0;       // 두 팀의 능력치 차

    // 얘가 너무 구린 것 같은데
    for(int i = 0; i < n-1; i++) {
      for(int j = i+1; j < n; j++) {
        if(visited[i] == true && visited[j] == true) {
          selectedSum += teamStat[i][j];
          selectedSum += teamStat[j][i];
        }
        if(visited[i] == false && visited[j] == false) {
          unSelectedSum += teamStat[i][j];
          unSelectedSum += teamStat[j][i];
        }
      }
    }
    teamDiff = abs(selectedSum - unSelectedSum);
    
    if(ans > teamDiff) ans = teamDiff;

    return;
  }

  for(int i = cur; i < n; i++) {
    if(visited[i]) continue;

    visited[i] = true;
    selected.push_back(i);
    combination(uppderBound, i+1);
    selected.pop_back();
    visited[i] = false;
  }
}


int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> teamStat[i][j];
    }
  }

  // 상대팀에도 1명 이상의 선수가 있어야하므로 n-1명 까지만 선택
  for(int i = 1; i < n; i++) {
    combination(i, 0);
  }

  cout << ans;

  return 0;
}