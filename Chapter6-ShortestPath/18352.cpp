#include <bits/stdc++.h>
using namespace std;

const int INF = 10000001;
int n, m, k, x, vertex1, vertex2;
vector<pair<int, int>> graph[300001];
int dist[300001];
vector<int> ans;

void dijkstra(int start) {
  // dist 초기화
  fill_n(dist, n+1, INF);

  priority_queue<pair<int, int>> pq;  // <거리, 노드 번호>
  pq.push({0, start});
  dist[start] = 0;

  while(!pq.empty()) {
    pair<int, int> cur = pq.top();
    int curDist = -cur.first;
    int curNode = cur.second;
    pq.pop();

    // curDist에 의해 갱신이 되지 않는 경우, 현재 노드를 거쳐가는 경로를 살펴볼 이유가 없으므로 건너뜀
    if(curDist > dist[curNode]) continue;
    
    // 현재 노드의 인접 노드들의 거리 갱신
    for(int i = 0; i < graph[curNode].size(); i++) {
      pair<int, int> next = graph[curNode][i];
      int nextNode = next.first;
      int nextDist = curDist + next.second;

      if(dist[nextNode] > nextDist) {
        dist[nextNode] = nextDist;
        pq.push({-nextDist, nextNode});
      }
    }
  }
}

int main() {
  cin >> n >> m >> k >> x;
  for(int i = 0; i < m; i++) {
    cin >> vertex1 >> vertex2;
    graph[vertex1].push_back({vertex2, 1});   // 가중치가 1인 간선(vertex1, vertex2) 삽입
  }
  dijkstra(x);

  for(int i = 1; i <= n; i++) {
    if(dist[i] == k)
      ans.push_back(i);
  }

  if(ans.size() == 0) {
    cout << -1;
  } else {
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++) {
      cout << ans[i] << "\n";
    }
  }

  return 0;
}