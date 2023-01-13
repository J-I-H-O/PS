#include <bits/stdc++.h>
using namespace std;

int n;

// x: 현재 행, y: 현재 열, k: 현재 한 변의 길이
void star(int x, int y, int k) {
  // 공백
  if((x/k)%3 == 1 && (y/k)%3 == 1) {
    cout << " ";
  }
  else{
    if(k == 1) {
      cout << "*";
    }  
    else {
      star(x, y, k/3);
    }
  }
}

int main() {
  cin >> n;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      // 매 호출마다 한 문자씩 출력됨
      star(i, j, n);
    }
    cout << "\n";
  }

  return 0;
}