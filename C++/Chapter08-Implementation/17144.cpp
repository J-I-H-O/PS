#include <iostream>
#include <vector>
using namespace std;

int board[50][50];
int tempBoard[50][50];
int r, c, t;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
vector<int> airCleanerPos; // 공기청정기의 행 번호 저장

// 어떤 칸과 인접한 칸 중 미세먼지가 확산될 수 있는 칸의 개수를 반환
// 그 과정에서 확산될 수 있는 칸의 목록을 list에 삽입
int countSpeadable(int curR, int curC, vector<pair<pair<int, int>, int>> &list) {
  int cnt = 0;
  for(int i = 0; i < 4; i++) {
    int nxtR = curR + dr[i];
    int nxtC = curC + dc[i];

    if(0 <= nxtR && nxtR < r && 0 <= nxtC && nxtC < c && board[nxtR][nxtC] != -1) {
      list.push_back({{nxtR, nxtC}, board[curR][curC] / 5});
      cnt++;
    }
  }

  return cnt;
}

// 미세먼지 확산
void spread() {
  // 확산이 일어날 칸의 <<행, 열>, 값>을 저장
  vector<pair<pair<int, int>, int>> list;

  // 원래 미세먼지가 있던 칸의 값을 먼저 갱신
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      if(0 < board[i][j]) {
        int cnt = countSpeadable(i, j, list);
        board[i][j] -= (board[i][j] / 5) * cnt;
      }
    }
  }

  // 원래 미세먼지가 있던 칸의 인접 칸 갱신
  for(int i = 0; i < list.size(); i++) {
    board[list[i].first.first][list[i].first.second] += list[i].second;
  }
}

// 공기청정기 작동
void cleanAir() {
  int curR, curC;

  // 공기청정기 위쪽 동작
  curR = airCleanerPos[0] - 1;
  curC = 0;
  while(0 < curR) {
    board[curR][curC] = board[curR-1][curC];
    curR--;
  }
  while(curC < c-1) {
    board[curR][curC] = board[curR][curC+1];
    curC++;
  }
  while(curR < airCleanerPos[0]) {
    board[curR][curC] = board[curR+1][curC];
    curR++;
  }
  while(1 < curC) { // 공기청정기 직전칸까지만 갱신
    board[curR][curC] = board[curR][curC-1];
    curC--;
  }
  board[curR][curC] = 0;

  // 공기청정기 아래쪽 동작
  curR = airCleanerPos[1] + 1;
  curC = 0;
  while(curR < r-1) {
    board[curR][curC] = board[curR+1][curC];
    curR++;
  }
  while(curC < c-1) {
    board[curR][curC] = board[curR][curC+1];
    curC++;
  }
  while(curR > airCleanerPos[1]) {
    board[curR][curC] = board[curR-1][curC];
    curR--;
  }
  while(1 < curC) { // 공기청정기 직전칸까지만 갱신
    board[curR][curC] = board[curR][curC-1];
    curC--;
  }
  board[curR][curC] = 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> r >> c >> t;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      cin >> board[i][j];
      if(board[i][j] == -1)
        airCleanerPos.push_back(i);
    }
  }

  while(t--) {
    spread();
    cleanAir();
  }

  int ans = 0;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      if(board[i][j] != -1) 
        ans += board[i][j];
    }
  }
  cout << ans;

  return 0;
}