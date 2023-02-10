#include <bits/stdc++.h>
using namespace std;

int board[19][19];

// 현재 바둑돌을 기준으로 가로, 세로, 두 대각선 방향을 탐색. 5개의 바둑알이 연속되어 있는 경우 해당 색이 이긴 것.
pair<int, int> findWinner(int row, int col, int color) {
  int horizon = 1;      // 가로 방향으로 연속된 바둑알의 개수. 현재 바둑알을 포함하므로 1로 초기화
  int vertical = 1;     // 세로 방향으로 연속된 바둑알의 개수. 현재 바둑알을 포함하므로 1로 초기화
  int mainDiagonal = 1; // 주 대각선 방향으로 연속된 바둑알의 개수. 현재 바둑알을 포함하므로 1로 초기화
  int antiDiagonal = 1; // 반 대각선 방향으로 연속된 바둑알의 개수. 현재 바둑알을 포함하므로 1로 초기화
  int nr;               // 다음에 탐색할 행
  int nc;               // 다음에 탐색할 열

  // 가로방향 탐색
  nr = row;
  nc = col + 1;
  // 가로 오른쪽 방향 탐색
  while(nc < 19 && board[nr][nc] == color) {
    horizon++;
    nc++;
  }
  // 가로 왼쪽 방향 탐색
  nc = col -1;
  while(0 <= nc && board[nr][nc] == color) {
    horizon++;
    nc--;
  }
  if(horizon == 5) {
    cout << color << "\n";
    return {nr + 1, nc + 1 + 1};
  }

  // 세로방향 탐색
  nr = row + 1;
  nc = col;
  // 세로 아래 방향 탐색
  while(nr < 19 && board[nr][nc] == color) {
    vertical++;
    nr++;
  }
  // 세로 위쪽 방향 탐색
  nr = row - 1;
  while(0 <= nr && board[nr][nc] == color) {
    vertical++;
    nr--;
  }
  if(vertical == 5) {
    cout << color << "\n";
    return {nr + 1 + 1, nc + 1};
  }

  // 주 대각선 탐색
  nr = row + 1;
  nc = col + 1;
  while(nr < 19 && nc < 19 && board[nr][nc] == color) {
    mainDiagonal++;
    nr++;
    nc++;
  }
  nr = row - 1;
  nc = col - 1;
  while(0 <= nr && 0 <= nc && board[nr][nc] == color) {
    mainDiagonal++;
    nr--;
    nc--;
  }
  if(mainDiagonal == 5) {
    cout << color << "\n";
    return {nr + 1 + 1, nc + 1 + 1};
  }

  // 반 대각선 탐색
  nr = row - 1;
  nc = col + 1;
  while(0 <= nr && nc < 19 && board[nr][nc] == color) {
    antiDiagonal++;
    nr--;
    nc++;
  }
  nr = row + 1;
  nc = col - 1;
  while(nr < 19 && 0 <= nc && board[nr][nc] == color) {
    antiDiagonal++;
    nr++;
    nc--;
  }
  if(antiDiagonal == 5) {
    cout << color << "\n";
    return {nr - 1 + 1, nc + 1 + 1};
  }

  // 현재 바둑돌을 기준으로 5개의 연속된 바둑돌을 찾지 못한 경우
  return {-1, -1};
}

int main() {
  for(int i = 0; i < 19; i++) {
    for(int j = 0; j < 19; j++) {
      cin >> board[i][j];
    }
  }

  for(int i = 0; i < 19; i++) {
    for(int j = 0; j < 19; j++) {
      if(board[i][j] != 0) {
        pair<int, int> res = findWinner(i, j, board[i][j]);
        // 정답을 찾은 경우
        if(res.first != -1 && res.second != -1) {
          cout << res.first << " " << res.second;
          return 0;
        }
      }
    }
  }
  cout << 0;

  return 0;
}