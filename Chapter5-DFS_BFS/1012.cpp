#include <bits/stdc++.h>
using namespace std;

int t, m, n, k, x, y;
bool visited[51][51];
int field[51][51];
stack<pair<int, int>> s;
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};
int ans = 0;

// 스택을 비우고 visited, field, ans 초기화
void clearTestCase() {
  while(!s.empty()) {
    s.pop();
  }

  for(int i = 0; i < 51; i++) {
    for(int j = 0; j < 51; j++) {
      visited[i][j] = false;
      field[i][j] = 0;
    }
  }
  
  ans = 0;
}

void DFS(int x, int y) {
  if(visited[x][y]) return;

  s.push({x, y});
  while(!s.empty()) {
    int curX = s.top().first;
    int curY = s.top().second;
    s.pop();
    for(int i = 0; i < 4; i++) {
      int nextX = curX + dirX[i];
      int nextY = curY + dirY[i];
      if(0 <= nextX && nextX < m && 0 <= nextY && nextY < n) {
        if(field[nextX][nextY] == 1 && !visited[nextX][nextY]) {
          s.push({nextX, nextY});
          visited[nextX][nextY] = true;
        }
      }
    }
  }
}

int main() {
  cin >> t;

  while(t--) {
    cin >> m >> n >> k;
    for(int i = 0; i < k; i++) {
      cin >> x >> y;
      field[x][y] = 1;
    }

    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        // 배추가 심어져 있는 땅을 아직 방문하지 않은 경우, 해당 위치에 배추흰지렁이가 필요함
        if(field[i][j] == 1 && !visited[i][j]) {
          ans++;
          DFS(i, j);
        }
      }
    }
    cout << ans << "\n";
    clearTestCase();
  }


  return 0;
}