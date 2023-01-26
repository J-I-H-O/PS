#include <bits/stdc++.h>
using namespace std;

int n, k;
int dist[100001];

void BFS(int s) {
  // dist 초기화
  fill_n(dist, 100001, -1);

  queue<int> q;
  q.push(s);
  dist[s] = 0;

  while(!q.empty()) {
    int cur = q.front();
    q.pop();

    // 해당 칸에 방문하지 않았거나, 해당 칸에 방문한 시간을 더 적은 시간으로 갱신할 수 있는 경우
    if(0 <= cur-1 && (dist[cur-1] == -1 || dist[cur-1] > dist[cur]+1)) {
      q.push(cur-1);
      dist[cur-1] = dist[cur] + 1;
    }
    if(cur+1 <= 100000 && (dist[cur+1] == -1 || dist[cur+1] > dist[cur]+1)) {
      q.push(cur+1);
      dist[cur+1] = dist[cur] + 1;
    }
    if(cur*2 <= 100000 && (dist[cur*2] == -1 || dist[cur*2] > dist[cur])) {
      q.push(cur*2);
      dist[cur*2] = dist[cur];
    }
  }
}

int main() {
  cin >> n >> k;
  BFS(n);
  cout << dist[k];

  return 0;
}