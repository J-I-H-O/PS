#include <bits/stdc++.h>
using namespace std;

int f, s, g, u, d;
int cnt[1000001]; // cnt[i]: s에서 출발하여 i까지 도달하기 위해 버튼을 누른 횟수

void BFS(int x) {
  fill_n(cnt, 1000001, -1);

  queue<int> q;
  q.push(x);
  cnt[x] = 0;

  while(!q.empty()) {
    int cur = q.front();
    q.pop();
    
    // 현재 위치에서 u만큼 올라간 높이가 주어진 범위 내에 속하고, 아직 방문하지 않은 위치일 때
    if(cur + u <= f && cnt[cur + u] == -1) {
      q.push(cur + u);
      cnt[cur + u] = cnt[cur] + 1;
    }
    // 현재 위치에서 d만큼 내려간 높이가 주어진 범위 내에 속하고, 아직 방문하지 않은 위치일 때
    if(1 <= cur - d && cnt[cur - d] == -1) {
      q.push(cur - d);
      cnt[cur -d] = cnt[cur] + 1;
    }
  }
}

int main() {
  cin >> f >> s >> g >> u >> d;

  BFS(s);

  // 시작 위치로부터 BFS를 수행한 뒤에도 g층에 방문하지 않은 경우
  if(cnt[g] == -1) {
    cout << "use the stairs";
  }
  else {
    cout << cnt[g];
  }

  return 0;
}