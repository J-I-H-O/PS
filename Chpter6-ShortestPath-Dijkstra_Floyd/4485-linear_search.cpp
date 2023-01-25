#include <bits/stdc++.h>
using namespace std;

const int INF = 0x4f4f4f4f;
int cave[125][125];
bool visited[125][125];
int dist[125][125];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n;
int testCase = 1;

// 방문한 칸과 인접한 칸들 중, 도둑 루피의 값이 가장 낮은 칸 찾기
pair<int, int> findMinimumIdx() {
  int min = INF;
  pair<int, int> minIdx = {-1, -1};
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(!visited[i][j] && dist[i][j] < min) {
        min = dist[i][j];
        minIdx = {i, j};
      }
    }
  }
  return minIdx;
}

void djikstra() {
  // 시작 노드를 방문 표시
  visited[0][0] = true;
  dist[0][0] = cave[0][0];

  // (0, 0)과 인접한 노드들의 dist 값을 해당 노드(칸)의 값으로 초기화
  dist[0][1] = cave[0][1] + dist[0][0];
  dist[1][0] = cave[1][0] + dist[0][0];

  // 다익스트라 알고리즘은 방문한 칸을 재방문하여 갱신하지 않으므로, (n-1, n-1)칸의 dist값을 구할 때,
  // 해당 칸을 방문한 상태면 반복을 종료하고 출력함.
  while(!visited[n-1][n-1]) {
    // 방문한 칸과 인접한 칸들 중, 도둑 루피의 값이 가장 낮은 칸 찾기
    pair<int, int> cur = findMinimumIdx();
    int cx = cur.first;
    int cy = cur.second;

    visited[cx][cy] = true;
    // test
    // cout << "visited: (" << cx << ", " << cy << "), dist: " << dist[cx][cy] << "\n";
    
    // 현재 방문한 칸과 인접한 칸의 시작 지점으로부터의 거리(dist)를 갱신해줌
    // 방문하지 않은 정점들에 대해서만 값을 갱신해줌.
    for(int i = 0; i < 4; i++) {
      int nx = cx + dx[i];
      int ny = cy + dy[i];
      if(0 <= nx && nx < n && 0 <= ny && ny < n) {
        if(!visited[nx][ny]) {
          dist[nx][ny] = min(dist[nx][ny], dist[cx][cy] + cave[nx][ny]);
        }
      }
    }
  }
  cout << "Problem " << testCase++ << ": " << dist[n-1][n-1] << "\n";
}

int main() {
  cin >> n;
  while(n != 0) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        cin >> cave[i][j];
        visited[i][j] = false;
        dist[i][j] = INF;
      }
    } 
    djikstra();

    cin >> n;
  }


  return 0;
}