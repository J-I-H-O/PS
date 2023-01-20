#include <bits/stdc++.h>
using namespace std;

int n, m;
int vertex1, vertex2;
int ans = 0;
bool visited[1001];

class AdjListGraph {
  vector<int> adjList[1001];

public:
  void insertEdge(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  void DFS(int v) {
    visited[v] = true;

    for(int i = 0; i < adjList[v].size(); i++) {
      int next = adjList[v][i];
      if(!visited[next]) {
        DFS(next);
      }
    }
  }
};

int main() {
  AdjListGraph* adjListGraph = new AdjListGraph();

  cin >> n >> m; 
  for(int i = 0; i < m; i++) {
    cin >> vertex1 >> vertex2;
    adjListGraph->insertEdge(vertex1, vertex2);
  }

  for(int i = 1; i <= n; i++) {
    // 하나의 시작 정점에 대해 DFS를 마친 뒤에도 아직 방문하지 않은 노드가 있는 경우, 이는 서로 다른 연결 요소가 존재한다는 의미.
    if(!visited[i]) {
      ans++;
      adjListGraph->DFS(i);
    }
  }

  cout << ans;

  return 0;
}