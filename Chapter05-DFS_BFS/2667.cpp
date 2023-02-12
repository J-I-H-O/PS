#include <bits/stdc++.h>
using namespace std;

char aptMap[26][26];
bool visited[26][26];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {1, 0, -1, 0};
int n;
// total: 총 단지 수, cnt: 하나의 단지내 집의 수
int total = 0, cnt = 0;
// 하나의 단지내 집의 수를 기록한 벡터. 오름차순으로 정렬하여 출력함.
vector<int> houses;

void DFS(int x, int y) {
  visited[x][y] = true;
  cnt++;

  for(int i = 0; i < 4; i++) {
    int nextX = x + dirX[i];
    int nextY = y + dirY[i];

    // 다음 좌표가 지도 상 유효한 범위에 속할 경우
    if(0 <= nextX && nextX < n && 0 <= nextY && nextY < n) {
      // 다음 좌표를 아직 방문하지 않았고, 지도 상 아파트가 있는 위치일 경우 탐색
      if(!visited[nextX][nextY] && aptMap[nextX][nextY] == '1') {
        visited[nextX][nextY] = true;
        DFS(nextX, nextY);
      }
    }
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> aptMap[i][j];
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(!visited[i][j] && aptMap[i][j] == '1') {
        total++;
        cnt = 0;
        DFS(i, j);
        houses.push_back(cnt);
      }
    }
  }

  sort(houses.begin(), houses.end());

  cout << total << "\n";
  for(int i = 0; i < houses.size(); i++) {
    cout << houses[i] << "\n";
  }

  return 0;
}