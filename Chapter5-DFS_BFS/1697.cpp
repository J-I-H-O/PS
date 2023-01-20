#include <bits/stdc++.h>
using namespace std;

int visited[100001];
int n, k;

void BFS(int x) {
  // visited[x]가 -1이면 해당 위치 x는 아직 방문하지 않았음을 뜻함
  fill_n(visited, 100001, -1);

  queue<int> q;

  q.push(x);
  visited[x]++;
  while(!q.empty()) {
    int curLoc = q.front();
    if(curLoc == k) {
      cout << visited[k];
      break;
    }

    q.pop();
    if(curLoc-1 >= 0 && visited[curLoc-1] == -1) {
      q.push(curLoc-1);
      visited[curLoc-1] = visited[curLoc] + 1;
    }
    if(curLoc+1 <= 100000 && visited[curLoc+1] == -1) {
      q.push(curLoc+1);
      visited[curLoc+1] = visited[curLoc] + 1;
    }
    if(curLoc*2 <= 100000 && visited[curLoc*2] == -1) {
      q.push(curLoc*2);
      visited[curLoc*2] = visited[curLoc] + 1;
    }
  }
}

int main() {
  cin >> n >> k;
  BFS(n);

  return 0;
}