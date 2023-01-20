#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0;
int v1, v2;

vector<int> adjList[101];
bool visited[101];

void DFS(int s) {
  ans++;
  visited[s] = true;

  for(int i = 0; i < adjList[s].size(); i++) {
    int next = adjList[s][i];
    if(!visited[next]) {
      visited[next] = true;
      DFS(next);
    }
  }
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    cin >> v1 >> v2;
    adjList[v1].push_back(v2);
    adjList[v2].push_back(v1);
  }

  DFS(1);
  
  // 1번 컴퓨터는 제외
  cout << ans - 1;

  return 0;
}