#include <bits/stdc++.h>
using namespace std;

const int INF = 0x4f4f4f4f;
int n, m, v1, v2, w, s, d;
// 인접 리스트로 그래프 표현
// graph[u][v].first: 정점 u와 인접한 정점 v의 노드 번호
// graph[u][v].second: 간선 E(u, v)의 가중치
vector<pair<int, int>> graph[1001]; 
int dist[1001];

void dijkstra(int start) {
  // dist INF로 초기화
  fill_n(dist, n+1, INF);

  // 힙(우선순위 큐)을 이용하여 다익스트라 알고리즘 구현
  // 최소힙의 경우, 거리가 가장 작은 노드를 루트 노드로 설정함.
  // <거리, 노드 번호>
  priority_queue<pair<int, int>> pq;

  // 시작 노드의 거리를 0으로 세팅하고, 우선순위 큐에 넣어줌
  dist[start] = 0;
  pq.push({0, start});

  while(!pq.empty()) {
    // priority_queue는 기본적으로 최대힙.
    // 최소힙으로 사용하기 위해 push시 음수로 만들어 값을 넣어주므로, 꺼낼 때 다시 양수로 바꿔줘야 함.
    int cur_dist = -pq.top().first;
    int cur_node = pq.top().second;
    pq.pop();

    // 기존의 우선순위 큐에 있는 경로보다 짧은 경로가 큐에 들어올 경우, 먼저 들어온 경로를 어떻게 처리할지
      // => 기존의 경로를 그래돌 두고 짧은 경로를 추가한다. 그리고 큐에서 처리할 때 먼저 들어온 경로를 무시한다.
    // pq의 top에서 얻은 시작 노드로부터 현재 노드까지의 비용과 
    // 최소 비용 배열 dist에 있는 시작 노드로부터 현재 노드까지의 비용을 비교
    // pq의 top에서 뽑은 시작 노드로부터 현재 노드까지의 비용이 더 크다면
    // 굳이 해당 경로를 통해 인접한 노드들을 확인할 필요가 없으므로, 더이상 확인하지 않음.
    if(dist[cur_node] < cur_dist) continue;

    // cur_node의 인접 노드들에 대하여 반복
    // 이 때, 이전에 방문했는지 여부는 따로 검사하지 않음.
    // 거리값이 업데이트 되지 않는 노드(기존 최단 경로의 비용이 더 낮은 경우)의 경우, 단순히 우선순위 큐에 넣지 않으면 되기 때문.
    for(int i = 0; i < graph[cur_node].size(); i++) {
      int next_dist = cur_dist + graph[cur_node][i].second;
      int next_node = graph[cur_node][i].first;

      // 거리값이 업데이트 된 노드만 우선순위 큐에 넣어줌.
      if(next_dist < dist[next_node]) {
        dist[next_node] = next_dist;
        // priority_queue를 최소힙으로 사용하기 위해 가중치를 음수로 바꾸어 삽입
        pq.push({-next_dist, next_node});
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    cin >> v1 >> v2 >> w;
    graph[v1].push_back({v2, w});
  }
  cin >> s >> d;

  dijkstra(s);
  
  cout << dist[d];

  return 0;
}