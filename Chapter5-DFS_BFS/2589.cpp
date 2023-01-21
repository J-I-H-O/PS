#include <bits/stdc++.h>
using namespace std;

int h, w;
char treasureMap[50][50];
int dist[50][50]; // 출발 지점에서 dist[i][j] 까지의 거리를 나타냄
int ans = 0;
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

void clearDist() {
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      dist[i][j] = -1;
    }
  }
}

void BFS(int x, int y) {
  queue<pair<int, int>> q;
  q.push({x, y});
  dist[x][y] = 0;
  
  while(!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();

    for(int i = 0; i < 4; i++) {
      int nextX = cur.first + dirX[i];
      int nextY = cur.second + dirY[i];
      if(0 <= nextX && nextX < h && 0 <= nextY && nextY < w) {
        if(treasureMap[nextX][nextY] == 'L' && dist[nextX][nextY] == -1) {
          dist[nextX][nextY] = dist[cur.first][cur.second] + 1;
          q.push({nextX, nextY});
          if(ans < dist[nextX][nextY])
            ans = dist[nextX][nextY];
        }
      }
    }
  }
}

int main() {
  cin >> h >> w;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      cin >> treasureMap[i][j];
    }
  }

  // 모든 L에 대해 BFS를 수행해보고, 그 중 최대 dist값이 가장 큰 것을 선택
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(treasureMap[i][j] == 'L') {
        clearDist();
        BFS(i, j);
      }
    }
  }
  cout << ans;

  return 0;
}