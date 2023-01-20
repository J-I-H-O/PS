#include <bits/stdc++.h>
using namespace std;

int n, m, v;
int vertex1, vertex2;

class AdjGraph {
  vector<int> adjList[1001];
  bool visited[1001];

public:
  void sortAdjList() {
    for(int i = 1; i <= n; i++) {
      // 정점 i의 인접 정점들을 오름차순으로 정렬
      sort(adjList[i].begin(), adjList[i].end());
    }
  }

  void insertEdge(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  void clearVisited() {
    for(int i = 1; i <= n; i++) {
      visited[i] = false;
    }
  }

  void DFS(int v) {
    if(visited[v]) return;

    cout << v << " ";
    visited[v] = true;
    for(int i = 0; i < adjList[v].size(); i++) {
      int next = adjList[v][i];
      if(!visited[next]) {
        DFS(next);
      }
    }
  }

  void BFS(int v) {
    queue<int> q;
    q.push(v);

    while(!q.empty()) {
      int cur = q.front();
      visited[cur] = true;
      cout << cur << " ";
      q.pop();
      // 현재 보고있는 정점과 인접한 정점들 중 아직 방문하지 않은 정점들을 큐에 넣음
      for(int i = 0; i < adjList[cur].size(); i++) {
        int nextNode = adjList[cur][i];
        if(!visited[nextNode]) {
          q.push(nextNode);
          visited[nextNode] = true;
        }
      }
    }
  }
};

int main() {
  AdjGraph* adjGraph = new AdjGraph();

  cin >> n >> m >> v;
  for(int i = 0; i < m; i++) {
    cin >> vertex1 >> vertex2;
    adjGraph->insertEdge(vertex1, vertex2);
  }
  // 정점의 번호가 낮은 것 부터 방문하기 위해 인접 리스트 정렬
  adjGraph->sortAdjList();
  adjGraph->DFS(v);
  cout << "\n";
  adjGraph->clearVisited();
  adjGraph->BFS(v);

  return 0;
}