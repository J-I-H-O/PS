#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, k, s;
int a, b;
int dist[401][401];

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
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(i == j)
        dist[i][j] = 0;
      else
        dist[i][j] = INF;
    }
  }

  for(int i = 1; i <= k; i++) {
    cin >> a >> b;
    dist[a][b] = 1;
  }

  floyd();

  cin >> s;
  for(int i = 1; i <= s; i++) {
    cin >> a >> b;
    // a가 b보다 먼저 일어난 경우
    if(dist[a][b] < INF) {
      cout << -1 << "\n";
    }
    // b가 a보다 먼저 일어난 경우 
    else if (dist[b][a] < INF) {
      cout << 1 << "\n";
    } 
    // a와 b의 순서 관계를 유추할 수 없는 경우
    else {
      cout << 0 << "\n";
    }
  }

  return 0;
}