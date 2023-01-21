#include <bits/stdc++.h>
using namespace std;

int field[51][51];
bool visited[51][51];
int w, h, ans = 0;
int dirX[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dirY[8] = {0, 1, 0, -1, 1, -1, 1, -1};

void clearTestcase() {
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      visited[i][j] = false;
    }
  }
  ans = 0;
}

void DFS(int x, int y) {
  visited[x][y] = true;

  for(int i = 0; i < 8; i++) {
    int nextX = x + dirX[i];
    int nextY = y + dirY[i];
    if(0 <= nextX && nextX < h && 0 <= nextY && nextY < w) {
      if(!visited[nextX][nextY] && field[nextX][nextY] == 1) {
        visited[nextX][nextY] = true;
        DFS(nextX, nextY);
      }
    }
  }
}

int main() {
  cin >> w >> h;
  while(w != 0 && h != 0) {
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        cin >> field[i][j];
      }
    }

    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        if(!visited[i][j] && field[i][j] == 1) {
          ans++;
          DFS(i, j);
        }
      }
    }
    cout << ans << "\n";
    clearTestcase();
    cin >> w >> h;
  }

  return 0;
}