#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
vector<pair<int, int>> graph[801];  // <가중치, 노드 번호>
long long dist[801][801];
int N, E;
int a, b, c;
int v1, v2;

void floyd() {
  for(int k = 1; k <= N; k++) {
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        if(dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }
}

int main() {
  cin >> N >> E;

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      if(i == j)
        dist[i][j] = 0;
      else
        dist[i][j] = INF;
    }
  }

  for(int i = 1; i <= E; i++) {
    cin >> a >> b >> c;
    dist[a][b] = c;
    dist[b][a] = c;
  }
  cin >> v1 >> v2;

  floyd();

  // method #1: 1 -> v1 -> v2 -> N
  // method #2: 1 -> v2 -> v1 -> N
  // 두 가지 방법 중 더 거리가 짧은 것을 택함

  bool isImpossible1 = dist[1][v1] >= INF || dist[v1][v2] >= INF || dist[v2][N] >= INF;
  bool isImpossible2 = dist[1][v2] >= INF || dist[v2][v1] >= INF || dist[v1][N] >= INF;

  // 거쳐 갈 수 있는 방법이 없는 경우
  if(isImpossible1 && isImpossible2) {
    cout << -1;
  } 
  // method #1만 가능한 경우
  else if (!isImpossible1 && isImpossible2) {
    cout << dist[1][v1] + dist[v1][v2] + dist[v2][N];
  } 
  // method #2만 가능한 경우
  else if (isImpossible1 && !isImpossible2) {
    cout << dist[1][v2] + dist[v2][v1] + dist[v1][N];
  }
  // 두 경우 모두 가능한 경우
  else {
    cout << min(dist[1][v1] + dist[v1][v2] + dist[v2][N], dist[1][v2] + dist[v2][v1] + dist[v1][N]);
  }

  return 0;
}