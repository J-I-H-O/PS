#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int V, E;
int a, b, c;
int dist[401][401];

void floyd() {
  for(int k = 1; k <= V; k++) {
    for(int i = 1; i <= V; i++) {
      for(int j = 1; j <= V; j++) {
        if(dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }
}

int main() {
  cin >> V >> E;
  for(int i = 1; i <= V; i++) {
    for(int j = 1; j <= V; j++) {
      dist[i][j] = INF;
    }
  }

  for(int i = 1; i <= E; i++) {
    cin >> a >> b >> c;
    dist[a][b] = c;
  }

  floyd();

  int ans = INF;
  for(int i = 1; i <= V; i++) {
    if(ans > dist[i][i])
      ans = dist[i][i];
  }

  if(ans < INF)
    cout << ans;
  else 
    cout << -1;

  return 0;
}