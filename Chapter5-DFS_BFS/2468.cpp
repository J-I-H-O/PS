#include <bits/stdc++.h>
using namespace std;

// 가장 높은 지점의 높이. 
// 비의 양에 따른 모든 경우를 조사해야하는데, 비의 양이 가장 높은 지점의 높이가 되기 전까지 조사함.
// 가장 높은 지점보다 더 많은 양의 비가 올 경우, 모든 지점이 잠기게 되므로 안전한 영역의 개수는 0이 되기 때문.
int maxHeight = 0;  
// 물에 잠기지 않는 안전한 영역의 최대 개수 저장. 
// 모든 지점이 물에 잠기지 않는 경우에 안전한 영역의 개수는 1개(전체)이므로, 기본값을 1로 설정
int maxCnt = 1; 
// 현재 강수량에 대하여 안전한 영역의 수 카운트
int cnt = 0;
int n;
int height[100][100];
bool visited[100][100];
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

// k: 현재 강수량
void DFS(int x, int y, int k) {
  visited[x][y] = true;

  for(int i = 0; i < 4; i++) {
    int nextX = x + dirX[i];
    int nextY = y + dirY[i];
    if(0 <= nextX && nextX < n && 0 <= nextY && nextY < n) {
      if(!visited[nextX][nextY] && height[nextX][nextY] > k) {
        visited[nextX][nextY] = true;
        DFS(nextX, nextY, k);
      }
    }
  }
}

int main() {
  cin >> n;
  // get input
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> height[i][j];
      if(maxHeight < height[i][j])
        maxHeight = height[i][j];
    }
  }

  // k: 강수량
  for(int k = 1; k < maxHeight; k++) {
    // visited, cnt 초기화
    clearCase();
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        // 아직 방문하지 않았고, 현재 강수량보다 높은 지점을 대상으로 DFS 수행
        if(!visited[i][j] && height[i][j] > k) {
          cnt++;
          DFS(i, j, k);
        }
      }
    }
    if(maxCnt < cnt)
      maxCnt = cnt;
  }
  cout << maxCnt;

  return 0;
}