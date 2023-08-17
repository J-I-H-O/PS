#include <bits/stdc++.h>
using namespace std;

int n, m, v1, v2, ans = 0;
vector<int> adjList[501];
// 상근이로부터 몇명의 지인을 거치는지 카운트. 상근이의 친구와 친구의 친구만 초대해야 하므로.
// 상근이: 0
// 상근이 친구: 1
// 상근이 친구의 친구: 2
// 아직 방문 안함: -1
int friends[501]; 

void BFS(int x) {
  queue<int> q;
  q.push(x);
  while(!q.empty()) {
    int cur = q.front();
    q.pop();

    for(int i = 0; i < adjList[cur].size(); i++) {
      int next = adjList[cur][i];
      if(friends[next] == -1) {
        q.push(next);
        friends[next] = friends[cur] + 1;
        if(friends[next] == 1 || friends[next] == 2) {
          ans++;
        }
      }
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

  fill_n(friends, 501, -1);
  friends[1] = 0;
  BFS(1);

  cout << ans;

  return 0;
}