#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m;
int a, b;
int dist[101][101];

void floyd() {
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
      if(i == j)
        dist[i][j] = 0;
      else 
        dist[i][j] = INF;
    }
  }

  for(int i = 1; i <= m; i++) {
    cin >> a >> b;
    dist[a][b] = 1;
  }

  floyd();

  for(int i = 1; i <= n; i++) {
    int cnt = 0;
    for(int j = 1; j <= n; j++) {
      if(i != j) {
        // i에서 j로 가는 경로와 j에서 i로 가는 경로가 모두 존재하지 않을 때
        if(dist[i][j] >= INF && dist[j][i] >= INF) cnt++;
      }
    }
    cout << cnt << "\n";
  }

  return 0;
}