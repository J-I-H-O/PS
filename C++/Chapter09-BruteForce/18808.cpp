#include <algorithm>
#include <iostream>
using namespace std;

int notebook[40][40];  // true: 해당 칸에 스티커가 붙어있는 상태
int sticker[10][10];
int resSticker[10][10];  // 스티커를 90도 회전시킨 결과 저장
int n, m, k;
int r, c;  // 현재 스티커의 세로와 가로 길이
int ans = 0;

// 스티커를 90도 회전. 가로와 세로 길이를 바꿔줘야 함
void rotateSticker() {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      resSticker[j][r - i - 1] = sticker[i][j];
    }
  }
  swap(r, c);
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      sticker[i][j] = resSticker[i][j];
    }
  }
}

void putSticker() {
  int cnt = 4;
  while (cnt--) {
    for (int i = 0; i < n; i++) {
      // 스티커를 붙이려는 위치가 노트북을 벗어나는 경우
      if (i + r > n) break;
      for (int j = 0; j < m; j++) {
        // 스티커를 붙이려는 위치가 노트북을 벗어나는 경우
        if (j + c > m) break;

        bool isPossible = true;
        for (int curR = 0; isPossible && (curR < r); curR++) {
          for (int curC = 0; isPossible && (curC < c); curC++) {
            // 현재 스티커를 붙일 자리에 이미 스티커가 붙어있는 경우
            if (sticker[curR][curC] == 1 && notebook[i + curR][j + curC] == 1) {
              isPossible = false;
            }
          }
        }

        if (isPossible) {
          for (int curR = 0; curR < r; curR++) {
            for (int curC = 0; curC < c; curC++) {
              if (sticker[curR][curC] == 1) {
                ans++;
                notebook[i + curR][j + curC] = 1;
              }
            }
          }
          return;
        }
      }
    }
    if (cnt != 0) rotateSticker();
  }
}

int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    cin >> r >> c;
    for (int j = 0; j < r; j++) {
      for (int k = 0; k < c; k++) {
        cin >> sticker[j][k];
      }
    }
    putSticker();
  }
  cout << ans;
}