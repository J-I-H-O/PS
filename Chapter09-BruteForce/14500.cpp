#include <iostream>
using namespace std;

int ans = 0, n, m;
int board[500][500];
bool visited[500][500];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

// 어떤 칸을 시작점으로하여 4칸 진행했을 때 종료(현재 칸 포함)
// 한 칸에서 출발하여 4칸을 선택하는 경우는 모든 테트로미노로 덮을 수 있기 때문
// 추가로 ㅗ 모양 테트로미노를 처리하기 위해 현재 칸을 포함해 인접한 칸 중 4개를 선택하는 경우도 고려

void dfs(int depth, int sum, int curR, int curC) {
  if(depth == 4) {
    if(ans < sum) ans = sum;
    return;
  }

  visited[curR][curC] = true;
  for(int i = 0; i < 4; i++) {
    int nxtR = curR + dr[i];
    int nxtC = curC + dc[i];

    if(0 <= nxtR && nxtR < n && 0 <= nxtC && nxtC < m) {
      if(!visited[nxtR][nxtC]) {
        //visited[nxtR][nxtC] = true;
        dfs(depth + 1, sum + board[nxtR][nxtC], nxtR, nxtC);
        //visited[nxtR][nxtC] = false;  
      }
    }
  }
  visited[curR][curC] = false;
}

void calFuckyou(int curR, int curC) {
  if(curR == 0) {
    if(!(curC == 0 || curC == m-1)) {
      // ㅜ만 가능
      int res = board[curR][curC] + board[curR][curC + 1] + board[curR][curC - 1] + board[curR + 1][curC];
      if(ans < res) ans = res;
    }
  }

  if(curR == n-1) {
    if(!(curC == 0 || curC == m-1)) {
      // ㅗ만 가능
      int res = board[curR][curC] + board[curR][curC + 1] + board[curR][curC - 1] + board[curR - 1][curC];
      if(ans < res) ans = res;
    }
  }

  if(curC == 0) {
    if(!(curR == 0 || curR == n-1)) {
      // ㅏ만 가능
      int res = board[curR][curC] + board[curR][curC + 1] + board[curR - 1][curC] + board[curR + 1][curC];
      if(ans < res) ans = res;
    }
  }

  if(curC == m-1) {
    if(!(curR == 0 || curR == n-1)) {
      // ㅓ만 가능
      int res = board[curR][curC] + board[curR][curC - 1] + board[curR - 1][curC] + board[curR + 1][curC];
      if(ans < res) ans = res;
    }
  }

  if(1 <= curR && curR <= n-2 && 1 <= curC && curC <= m-2) {
    // ㅜ, ㅗ, ㅏ, ㅓ 모두 가능
    int res = board[curR][curC] + board[curR][curC + 1] + board[curR][curC - 1] + board[curR + 1][curC];
    res = max(res, board[curR][curC] + board[curR][curC + 1] + board[curR][curC - 1] + board[curR - 1][curC]);
    res = max(res, board[curR][curC] + board[curR][curC + 1] + board[curR - 1][curC] + board[curR + 1][curC]);
    res = max(res, board[curR][curC] + board[curR][curC - 1] + board[curR - 1][curC] + board[curR + 1][curC]);
    
    if(ans < res) ans = res;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> board[i][j];
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      dfs(1, board[i][j], i, j);
      calFuckyou(i, j);
    }
  }

  cout << ans;

  return 0;
}