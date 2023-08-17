#include <bits/stdc++.h>
using namespace std;

int n;
int white = 0, blue = 0;
int paper[128][128];

// x: 현재 행 위치, y: 현재 열 위치, 잘려진 종이의 한변의
void countPaper(int x, int y, int k) {
  // base condition
  if(k == 1) {
    paper[x][y] == 0? white++ : blue++;
    return;
  }
  // 현재 종이가 모두 하얀색 또는 파란색으로 칠해진 경우
  bool isFull = true;
  int val = paper[x][y];
  for(int i = x; i < x + k; i++) {
    for(int j = y; j < y + k; j++) {
      // 현재 종이에서 다른 색이 발견된 경우
      if(paper[i][j] != val) {
        isFull = false;
        break;
      }
    }
  }

  // 현재 종이에 다른 색이 없는 경우
  if(isFull) {
    paper[x][y] == 0? white++ : blue++;
    return;
  }
  // 다른 색이 있는 경우, 칸을 나누어 더 작은 칸에 대해 탐색 진행
  else {
    countPaper(x, y, k/2);
    countPaper(x, y + k/2, k/2);
    countPaper(x + k/2, y, k/2);
    countPaper(x + k/2, y + k/2, k/2);
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> paper[i][j];
    }
  }

  countPaper(0, 0, n);

  cout << white << "\n";
  cout << blue << "\n";

  return 0;
}