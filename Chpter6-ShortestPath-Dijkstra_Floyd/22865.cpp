#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
const int INF = 0x3f3f3f3f;
vector<pair<int, int>> graph[MAX + 1]; // <가중치, 노드 번호>
int frnds[4];
long long dist[4][MAX + 1]; // dist[i][j]: i번째 친구의 집을 시작 노드로 구한 다른 땅으로의 거리
int N, M;
int A, B, C, D, E, L;

void clearDist() {
  for(int i = 1; i <= 3; i++) {
    for(int j = 1; j <= N; j++) {
      dist[i][j] = INF;
    }
  }
}

// k: k번째 다익스트라
void dijkstra(int k, int s) {
  dist[k][s] = 0;

  priority_queue<pair<int, int>> pq;  // <가중치, 노드 번호>
  pq.push({0, s});
  while(!pq.empty()) {
    int curDist = -pq.top().first;
    int curNode = pq.top().second;
    pq.pop();

    if(curDist > dist[k][curNode]) continue;

    for(int i = 0; i < graph[curNode].size(); i++) {
      int nxtDist = curDist + graph[curNode][i].first;
      int nxtNode = graph[curNode][i].second;

      if(dist[k][nxtNode] > nxtDist) {
        dist[k][nxtNode] = nxtDist;
        pq.push({-nxtDist, nxtNode});
      }
    }
  }
}

int main() {
  // 땅 후보의 개수 입력
  cin >> N;
  // 친구 집의 위치 입력
  for(int i = 1; i <= 3; i++) {
    cin >> frnds[i];
  }
  // 도로의 개수 입력
  cin >> M;
  // 도로 정보 입력
  for(int i = 1; i <= M; i++) {
    cin >> D >> E >> L;
    graph[D].push_back({L, E});
    graph[E].push_back({L, D});
  }

  clearDist();
  for(int i = 1; i <= 3; i++) {
    dijkstra(i, frnds[i]);
  }

  int ansVal = 0;
  int ansIdx = 0;
  for(int i = 1; i <= N; i++) {
    // 세 집으로부터의 거리가 가장 먼 땅을 선택해야 함.
    // 친구들로부터 떨어진 현재 땅의 거리
    int curDist = min(min(dist[1][i], dist[2][i]), dist[3][i]);
    if(ansVal < curDist) {
      ansVal = curDist;
      ansIdx = i;
    }
  }

  cout << ansIdx;

  return 0;
}