#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c;
int graph[501][501];
int dist[501][501];

// 모든 파티장에서 다른 모든 파티장으로 이동하데 걸리는 최소 시간을 계산해야 하므로 floyd-warshall 알고리즘 사용
void floyd() {
  // i번 파티장에서 j번 파티장으로 향할 때 k번 파티장을 경유하는 경로가 기존 경로보다 빠른 경우 대체
  for(int k = 1; k <= n; k++) {
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        if(dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cin >> graph[i][j];
      dist[i][j] = graph[i][j];
    }
  }

  floyd();

  for(int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    if(dist[a][b] <= c) {
      cout << "Enjoy other party" << "\n";
    } else {
      cout << "Stay here" << "\n";
    }
  }

  return 0;
}