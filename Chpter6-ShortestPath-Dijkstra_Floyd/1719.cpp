#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m;
int a, b, w;
int dist[201][201];
int nxt[201][201]; // nxt[u][v]: 정점 u에서 정점 v까지 이동하기 위해 다음에 방문해야 하는 정점의 번호 저장

// floyd-warshall 알고리즘과 경로 추적
// 1. 중간에 다른 정점을 거치지 않았을 때: u에서 v로 가는 간선이 있으면 nxt[u][v] = v로 초기화
// 2. 중간에 다른 정점을 거쳐 가는 것이 더 효율적인 경우(dist가 갱신되는 경우), nxt 배열도 갱신해줌
  // 기존 u에서 v까지 가는 경로보다 u에서 k를 거쳐 k에서 v로 가는 경로가 더 효율적인 상황에서,
  // nxt[u][v]를 nxt[u][k]로 대체함.
  // u에서 k를 거쳐 k에서 v로 가는 경로가 어떻게 생겼는지는 모르지만, 일단 u에서 k로 가야하는 것이 자명하기 때문에,
  // u에서 v까지 최단 경로로 가기 위해서는 u에서 출발해 제일 먼저 nxt[u][k]로 이동해야 함.
void floyd() {
  // nxt 배열 초기화
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      // i에서 j로 가는 간선이 있는 경우, 일단 i에서 다음에 방문할 정점을 j로 초기화 함
      if(dist[i][j] < INF) {
        nxt[i][j] = j;
      }
    }
  }

  for(int k = 1; k <= n; k++) {
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        // 최단 경로 갱신
        if(dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          nxt[i][j] = nxt[i][k];
        }
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(i == j) 
        dist[i][j] = 0;
      else
        dist[i][j] = INF;
    }
  }

  for(int i = 1; i <= m; i++) {
    cin >> a >> b >> w;
    dist[a][b] = w;
    dist[b][a] = w;
  }

  floyd();

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(i == j)
        cout << "- ";
      else
        cout << nxt[i][j] << " ";
    }
    cout << "\n";
  }


  return 0;
}