#include <bits/stdc++.h>
using namespace std;

int a, b;

void BFS(int s) {
  queue<pair<int, int>> q;  // <시작 숫자, cnt>
  q.push({s, 1});

  while(!q.empty()) {
    int cur = q.front().first;
    int curCnt = q.front().second;
    q.pop();

    if(cur == b) {
      cout << curCnt;
      return;
    }

    long long nxt = (long long)cur*2;
    if(nxt <= b) {
      q.push({nxt, curCnt + 1});
    }
    nxt = (long long)cur * 10 + 1;
    if(nxt <= b) {
      q.push({nxt, curCnt + 1});
    }
  }
  cout << -1;
}

int main() {
  cin >> a >> b;

  BFS(a);

  return 0;
}