#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;
char paint[101][101];
bool visited[101][101];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {1, 0, -1, 0};

void clearCase() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      visited[i][j] = false;
    }
  }
  cnt = 0;
}

// 적록색약의 시점으로 그림 변환
// 빨간색과 초록색을 같은 색으로 취급
void changePaint() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(paint[i][j] == 'R' || paint[i][j] == 'G') {
        paint[i][j] = 'W';
      }
    }
  }
}

void DFS(int x, int y, char color) {
  visited[x][y] = true;

  for(int i = 0; i < 4; i++) {
    int nextX = x + dirX[i];
    int nextY = y + dirY[i];
    if(0 <= nextX && nextX < n && 0 <= nextY && nextY < n) {
      if(!visited[nextX][nextY] && paint[nextX][nextY] == color) {
        visited[nextX][nextY] = true;
        DFS(nextX, nextY, color);
      }
    }
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> paint[i][j];
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(!visited[i][j]) {
        cnt++;
        DFS(i, j, paint[i][j]);
      }
    }
  }

  cout << cnt << " ";
  clearCase();
  changePaint();

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(!visited[i][j]) {
        cnt++;
        DFS(i, j, paint[i][j]);
      }
    }
  }
  cout << cnt;

  return 0;
}