#include <bits/stdc++.h>
using namespace std;

const int INF = 0x4f4f4f4f;
int V, E, s;
int u, v, w;
vector<int> dist;
vector<pair<int, int>> graph[20001]; // <가중치, 노드 번호>

void dijkstra(int s) {
  // <가중치, 노드 번호>
  priority_queue<pair<int, int>> pq;

  dist[s] = 0;
  pq.push({0, s});

  while(!pq.empty()) {
    pair<int, int> cur = pq.top();
    int curDist = -cur.first;
    int curNode = cur.second;
    pq.pop();

    // 현재 경로가 큐에 들어있는 동안 다른 최단경로가 발견된 경우, 비용이 더 높은 현재 경로는 고려하지 않아도 됨.
    if(dist[curNode] < curDist) continue;

    // 현재 살펴보고있는 인접 노드에 대해 거리 갱신
    for(int i = 0; i < graph[curNode].size(); i++) {
      // next: 인접 노드 정보
      pair<int, int> next = graph[curNode][i];
      int nDist = curDist + next.first; // 인접 정점까지의 거리
      int nNode = next.second;          // 인접 노드의 노드 번호

      // 현재 노드를 거친 경로의 비용이 현재까지 알려진 시작 노드에서 인접 노드까지의 비용보다 낮은 경우 갱신.
      if(dist[nNode] > nDist) {
        dist[nNode] = nDist;
        // 갱신해준 노드의 정보를 큐에 넣어줌
        pq.push({-nDist, nNode});
      }
    }
  }

  // 출력
  for(int i = 1; i <= V; i++) {
    // 시작점에서 i번 정점으로 가는 경로가 존재하지 않는 경우
    if(dist[i] >= INF) {
      cout << "INF";
    } else {
      cout << dist[i];
    }
    cout << "\n";
  }
}

int main() {
  cin >> V >> E >> s;

  // dist 초기화
  for(int i = 0; i <= V; i++) {
    dist.push_back(INF);
  }

  // 입력
  for(int i = 0; i < E; i++) {
    cin >> u >> v >> w;
    graph[u].push_back({w, v});
  }

  // 다익스트라
  dijkstra(s);

  return 0;
}