#include <bits/stdc++.h>
using namespace std;

const int INF = 10001;
int graph[101][101];  // 인접 행렬로 그래프 표현
int dist[101][101];   // 모든 정점에서 다른 모든 정점으로의 최단거리 저장
int n;

void floyd() {
  // 플로이드 워셜 알고리즘
  // k번 노드를 거쳐가는 중간 노드로 설정하여 최단거리 테이블을 업데이트
  // k = 0, 1, 2, ..., n-1번째 단계마다 총 n^2개의 모든 dist[i][j]값을 dist[i][k] + dist[k][j] 값과 비교
  // ==> 시간복잡도: O(n^3)
  // 매 단계마다 아래의 값을 비교함.
    // 1) k = 1 일 때,
      // 1. 1번 정점을 거치지 않고 갈 때의 최단거리
      // 2. 1번 정점을 거쳐서 갈 때의 최단거리
    // 2) k = 2 일 때,
      // 1. 2번 정점을 거치지 않고 갈 때의 최단거리 (1번은 거치거나, 거치지 않을 수 있음)
      // 2. 2번 정점을 거쳐서 갈 때의 최단거리 (1번은 거치거나, 거치지 않을 수 있음) ...
  for(int k = 0; k < n; k++) {
    // 플로이드 워셜 알고리즘은 모든 정점에서 시작하여 다른 모든 정점까지의 최단거리를 구하는 알고리즘
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        // i번 노드에서 j번 노드까지 갈 때, k번 노드를 거쳐가는 것이 더 효율적인 경우 갱신
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> graph[i][j];
      
      // 간선(i, j)이 존재하는 경우
      if(graph[i][j] == 1) {
        dist[i][j] = 1; 
      }
      else {
        dist[i][j] = INF;
      }
    }
  }

  floyd();

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(dist[i][j] != INF) {
        cout << 1 << " ";
      }
      else {
        cout << 0 << " ";
      }
    }
    cout << "\n";
  }

  return 0;
}