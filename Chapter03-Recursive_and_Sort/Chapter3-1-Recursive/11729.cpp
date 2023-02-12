#include <bits/stdc++.h>
using namespace std;

int n;

// a: 시작 지점, b: 경유 지점, c: 도착 지점, k: 높이
void hanoi(int a, int b, int c, int k) {
  if(k == 1) {
    cout << a << " " << c << "\n";
    return;
  }

  hanoi(a, c, b, k-1);
  hanoi(a, b, c, 1);
  hanoi(b, a, c, k-1);
}

int main() {
  cin >> n;

  // 높이가 n인 하노이탑의 이동 횟수는 2^n - 1 회
  // pow는 double 값을 리턴하므로 int형으로 형변환해야 오류 x
  cout << (int)pow(2, n) - 1 << "\n";
  hanoi(1, 2, 3, n);

  return 0;
}