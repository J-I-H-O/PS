#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int dist[1001][1001];
int n, m, x;
int a, b, c;

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
  cin >> n >> m >> x;

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(i == j)
        dist[i][j] = 0;
      else  
        dist[i][j] = INF;
    }
  }

  for(int i = 1; i <= m; i++) {
    cin >> a >> b >> c;
    dist[a][b] = c;
  }

  floyd();

  int maxVal = 0;
  for(int i = 1; i <= n; i++) {
    if(maxVal < dist[i][x] + dist[x][i]) {
      maxVal = dist[i][x] + dist[x][i];
    }
  }
  cout << maxVal;

  return 0;
}