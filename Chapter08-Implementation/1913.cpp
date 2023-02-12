#include <bits/stdc++.h>
using namespace std;

int n, target, targetR, targetC;
int snail[1000][1000];
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

void fillSnail() {
  int cur = n * n;
  int r = 1, c = 1; // (1, 1)부터 채워나감
  int dir = 0;      // 다음에 이동할 방향(0: 아래, 1: 오른쪽, 2: 위쪽, 3: 왼쪽)

  while(cur >= 1) {
    if(cur == target) {
      targetR = r;
      targetC = c;
    }

    snail[r][c] = cur--;

    int nxtR = r + dr[dir];
    int nxtC = c + dc[dir];

    // 다음에 방문할 좌표가 정상 범위를 벗어났거나, 이미 방문한 칸인 경우 방향 전환
    if(!(1 <= nxtR && nxtR <= n && 1 <= nxtC && nxtC <= n && snail[nxtR][nxtC] == 0)) {
      dir = (dir + 1) % 4;
      nxtR = r + dr[dir];
      nxtC = c + dc[dir];
    }

    r = nxtR;
    c = nxtC;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  cin >> n >> target;

  fillSnail();

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      cout << snail[i][j] << " ";
    }  
    cout << "\n";
  }

  cout << targetR << " " << targetC;

  return 0;
}