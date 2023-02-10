#include <bits/stdc++.h>
using namespace std;

int n, m, r;
int arr[300][300];
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

void rotateArray() {
  int boundary = (min(n, m) - 1) / 2;
  for(int i = 0; i <= boundary; i++) {  // i: 현재 회전시키려는 i번째 외곽
    int startVal = arr[i][i];

    int curR = i;
    int curC = i;

    for(int direction = 0; direction < 4; direction++) {
      int nxtR = curR + dr[direction];
      int nxtC = curC + dc[direction];
      while(i <= nxtR && nxtR < n - i && i <= nxtC && nxtC < m - i) {
        arr[curR][curC] = arr[nxtR][nxtC];

        curR = nxtR;
        curC = nxtC;

        nxtR += dr[direction];
        nxtC += dc[direction];
      }
    }
    arr[i+1][i] = startVal;
  }
}

int main() {
  cin >> n >> m >> r;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  for(int i = 0; i < r; i++) {
    rotateArray();
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}