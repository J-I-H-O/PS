#include <bits/stdc++.h>
using namespace std;

int visited[101][101];
char maze[101][101];
int n, m;
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {1, 0, -1, 0};

void BFS(int x, int y) {
  queue<pair<int, int>> q;  // <x, y>

  visited[x][y] = 1;
  q.push({x, y});
  while(!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    for(int i = 0; i < 4; i++) {
      int nextX = cur.first + dirX[i];
      int nextY = cur.second + dirY[i];

      if(1 <= nextX && nextX <= n && 1 <= nextY && nextY <= m) {
        if(visited[nextX][nextY] == 0 && maze[nextX][nextY] == '1') {
          visited[nextX][nextY] = visited[cur.first][cur.second] + 1;
          q.push({nextX, nextY});
        }
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cin >> maze[i][j];
    }
  }

  BFS(1, 1);
  cout << visited[n][m];

  return 0;
}