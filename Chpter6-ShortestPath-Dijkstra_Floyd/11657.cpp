#include <bits/stdc++.h>
using namespace std;

const int INF = 0x4f4f4f4f;
int n, m, a, b, c;
vector<pair<int, int>> graph[501];  // <노드 번호, 가중치>
// 음수 사이클의 절댓값이 6천만인 경우. 그 과정을 n번 반복하면서 그만큼 절댓값이 커지게 되고, int형의 범위를 벗어남. long long 필요.
long long dist[501];

// 음의 사이클을 가지는 경우, false를 리턴함
bool bellman(int s) {
  // dist 배열 초기화
  for(int i = 1; i <= n; i++) {
    dist[i] = INF;
  }
  dist[s] = 0;

  // n번 반복. n-1번 반복 시 모든 간선의 relax가 완료되고, n번째 반복 때에도 거리값의 변화가 있을 시 그래프가 음의 사이클을 가지는 경우.
  for(int i = 1; i <= n; i++) {
    // j번 노드와 인접 정점들을 잇는 간선 relaxing
    for(int j = 1; j <= n; j++) {
      for(int k = 0; k < graph[j].size(); k++) {
        int nextNode = graph[j][k].first;     // 현재 노드 j의 인접 노드의 번호
        int nextWeight = graph[j][k].second;  // 현재 노드 j와 인접 노드를 잇는 간선의 가중치

        // 현재까지 밝혀진 시작점에서 인접 노드까지의 거리가 시작점에서 노드 j를 거쳐 인접 노드에 도달하는 경로보다 비용이 높은 경우, 거리 테이블을 갱신함
        if(dist[j] != INF && dist[nextNode] > dist[j] + nextWeight) {
          // n번째 반복인데도 거리값의 갱신이 발생한 경우, 음의 사이클을 가지는 것으로 판단함
          if(i == n) return false;
          dist[nextNode] = dist[j] + nextWeight;
        }
      }
    }
  }
  return true;
}

int main() {
  cin >> n >> m;
  for(int i = 1; i <= m; i++) {
    cin >> a >> b >> c;
    graph[a].push_back({b, c});
  }
  
  // 음의 사이클이 없는 경우
  if(bellman(1)) {
    for(int i = 2; i <= n; i++) {
      if(dist[i] < INF) {
        cout << dist[i] << "\n";
      } else {
        cout << -1 << "\n";
      }
    }
  } else {
    cout << -1 << "\n";
  }

  return 0;
}