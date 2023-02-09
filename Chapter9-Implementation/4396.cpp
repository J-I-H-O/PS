#include <bits/stdc++.h>
using namespace std;

int n, m;
char temp;
char board[10][10];
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
bool isMine = false;


int main() {
  cin >> n;
  for(int k = 0; k < 2; k++) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        cin >> temp;
        if(board[i][j] != '*') {
          board[i][j] = temp;
        }
        if(board[i][j] == '*' && temp == 'x') {
          isMine = true;
        }
      }
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(board[i][j] == 'x') {
        // 주변 지뢰 개수 탐색
        int mines = 0;
        for(int k = 0; k < 8; k++) {
          int nx = i + dx[k];
          int ny = j + dy[k];
          if(0 <= nx && nx < n && 0 <= ny && ny < n) {
            if(board[nx][ny] == '*') {
              mines++;
            }
          }
        }
        board[i][j] = mines + '0';
      }
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(board[i][j] == '*') {
        if(isMine) cout << '*';
        else cout << '.';
      } else {
        cout << board[i][j];
      }
    }
    cout << "\n";
  }

  return 0;
}