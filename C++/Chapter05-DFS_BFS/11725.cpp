#include <bits/stdc++.h>
using namespace std;

// 인접 리스트로 트리를 표현하고, DFS로 트리를 순회하며 부모 자식 관계 저장
vector<int> adjList[100001];
bool visited[100001];
vector<pair<int, int>> ans; // <자신의 노드 번호, 부모의 노드 번호>
int n, v1, v2;

void DFS(int s) {
  visited[s] = true;

  for(int i = 0; i < adjList[s].size(); i++) {
    int next = adjList[s][i];
    if(!visited[next]) {
      visited[next] = true;
      ans.push_back({next, s});
      DFS(next);
    }
  }
}

int main() {
  cin >> n;
  for(int i = 1; i <= n-1; i++) {
    cin >> v1 >> v2;
    adjList[v1].push_back(v2);
    adjList[v2].push_back(v1);
  }

  DFS(1);
  // 정답을 노드 번호 순으로 정렬 후, 순서대로 해당 노드의 부모 노드 번호 출력
  sort(ans.begin(), ans.end());
  for(int i = 0; i < ans.size(); i++) {
    cout << ans[i].second << "\n";
  }

  return 0;
}