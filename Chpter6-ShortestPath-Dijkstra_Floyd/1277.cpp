#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, w, x, y, a, b;
vector<pair<int, int>> location;    // location[i]: i번 발전소의 위치
double graph[1001][1001]; 
double dist[1001];
double m;

// 좌표상의 두 점 사이의 거리 계산
double calcDist(pair<int, int> a, pair<int, int> b) {
  int xDiff = a.first - b.first;
  int yDiff = a.second - b.second;
  
  return sqrt(pow(xDiff, 2) + pow(yDiff, 2));
}

void dijkstra(int s) {
  dist[s] = 0;
  priority_queue<pair<double, int>> pq;  // <가중치, 노드 번호>
  pq.push({0, s});

  while(!pq.empty()) {
    double curDist = -pq.top().first;
    int curNode = pq.top().second;
    pq.pop();

    if(dist[curNode] < curDist) continue;

    for(int i = 1; i <= n; i++) {
      if(curNode != i && graph[curNode][i] != INF) {
        int nxtNode = i;
        double nxtDist = dist[curNode] + graph[curNode][nxtNode];

        if(dist[nxtNode] > nxtDist) {
          dist[nxtNode] = nxtDist;
          pq.push({-nxtDist, nxtNode});
        }
      }
    }
  }
}

int main() {
  cin >> n >> w;
  cin >> m;

  location.push_back({0, 0}); // dummy data
  for(int i = 1; i <= n; i++) {
    cin >> x >> y;
    location.push_back({x, y});
  }

  // 초기화
  for(int i = 1; i <= n; i++) {
    dist[i] = INF;
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(i == j) {
        graph[i][j] = 0;
      } else {
        double temp = calcDist(location[i], location[j]);
        // 안정성 문제가 없다면 두 발전소 사이의 거리를 계산해서 간선으로 추가해줌
        if(temp <= m) {
          graph[i][j] = graph[j][i] = temp;
        } else {
          graph[i][j] = graph[j][i] = INF;
        }
      }
    }
  }

  // 현재 구하려는 값은 추가 전선 길이의 최솟값이므로 남아있는 전선이 있는 경우는 추가 전선 길이로 포함시키지 않음
  for(int i = 1; i <= w; i++) {
    cin >> a >> b;
    graph[a][b] = 0;
    graph[b][a] = 0;
  }

  dijkstra(1);
  cout << (int)(dist[n] * 1000);

  return 0;
}