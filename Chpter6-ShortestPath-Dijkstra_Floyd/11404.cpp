#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, a, b, c;
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

  // initialize
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(i == j) {
        dist[i][j] = 0;
      }
      else {
        dist[i][j] = INF;
      }
    }
  }

  // input
  for(int i = 1; i <= m; i++) {
    cin >> a >> b >> c;
    if(dist[a][b] > c) {
      dist[a][b] = c;
    }
  }

  floyd();

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(dist[i][j] < INF)
        cout << dist[i][j] << " ";
      else
        cout << 0 << " ";
    }
    cout << "\n";
  }

  return 0;
}