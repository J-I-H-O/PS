#include <bits/stdc++.h>
using namespace std;

int temp, ans;
int board[5][5];
pair<int, int> nums[26];  // 숫자 i의 위치를 저장

// 어떤 칸을 칠했을 때 몇개의 빙고가 완성되는지 판별
int findBingo() {
  int bingo = 0;
  int Rdiagonal = 0;
  int Ldiagonal = 0;
  for(int i = 0; i < 5; i++) {
    int row = 0;
    int col = 0;
    for(int j = 0; j < 5; j++) {
      // 가로 빙고 판별
      if(board[i][j] == 0) {
        row++;
      }
      // 세로 빙고 판별
      if(board[j][i] == 0) {
        col++;
      }
    }
    // 좌측 상단 -> 우측 하단 대각선 빙고 판별
    if(board[i][i] == 0) {
      Rdiagonal++;
    }
    // 우측 상단 -> 좌측 하단 대각선 빙고 판별
    if(board[i][4-i] == 0) {
      Ldiagonal++;
    }

    if(row == 5) {
      bingo++;
    }
    if(col == 5) {
      bingo++;
    }
  }
  if(Rdiagonal == 5) {
    bingo++;
  }
  if(Ldiagonal == 5) {
    bingo++;
  }

  return bingo;
}

int main() {
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 5; j++) {
      cin >> board[i][j];
      nums[board[i][j]] = {i, j};
    }
  }

  for(int i = 1; i <= 25; i++) {
    cin >> temp;
    int row = nums[temp].first;
    int col = nums[temp].second;

    board[row][col] = 0;  // 사회자가 부르는 수를 0으로 변경함
    
    if(ans == 0 && findBingo() >= 3) {
      ans = i;
    }
  }

  cout << ans;

  return 0;
}