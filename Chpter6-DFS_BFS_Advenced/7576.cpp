#include <bits/stdc++.h>
using namespace std;

int tomato[1001][1001];
int cnt[1001][1001];  // 각 칸의 토마토가 익는데 걸린 시간 저장
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int m, n;
queue<pair<int, int>> q;

void BFS() {
  while(!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    for(int i = 0; i < 4; i++) {
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];
      if(0 <= nx && nx < n && 0 <= ny && ny < m) {
        // 익지 않은 토마토에 대해 BFS 진행
        // 해당 칸에 아직 방문하지 않았거나, 다른 익은 토마토의 영향으로 익는 시간보다 현재 익은 토마토의 영향으로 익는 시간이 더 짧은 경우 갱신
        if(tomato[nx][ny] == 0 && (cnt[nx][ny] == -1 || cnt[nx][ny] > cnt[cur.first][cur.second] + 1)) {
          cnt[nx][ny] = cnt[cur.first][cur.second] + 1;
          q.push({nx, ny});
        }
      }
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  cin >> m >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> tomato[i][j];
      // 익은 토마토일 경우, BFS에 사용될 큐에 넣어줌
      // 여러개의 익은 토마토에 대해 익지 않은 토마토들이 가장 인접한 익은 토마토로부터 영향을 받도록 할 수 있음
      if(tomato[i][j] == 1) {
        q.push({i, j});
        cnt[i][j] = 0;
      }
      else {
        cnt[i][j] = -1;
      }
    }
  }

  BFS();

  int timeSpent = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(tomato[i][j] == 0) {
        // 방문하지 못한 칸이 남아있는 경우. 즉 토마토가 모두 익지는 못하는 상황
        if(cnt[i][j] == -1) {
          cout << -1;
          return 0;
        }
        // 모든 토마토가 익는데 소요된 시간 측정
        if(timeSpent < cnt[i][j]) {
          timeSpent = cnt[i][j];
        }
      } 
    }
  }
  cout << timeSpent;

  return 0;
}