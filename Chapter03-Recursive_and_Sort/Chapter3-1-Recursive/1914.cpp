#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;
vector<pair<short, short>> process;

// a: 출발, b: 중간, c: 도착
void hanoi(short a, short b, short c, int k) {
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

  // 하노이 탑의 이동 횟수는 2^n - 1
  // 표현 범위를 커버하기 위해 string으로 변환
  string ans = to_string(pow(2, n));
  // to_string()의 결과는 부동소수값이므로 소수점 아래 수는 버리기
  int x = ans.find('.');
  ans = ans.substr(0, x);
  // ans에 1을 빼줌
  // 마지막 문자에 1을 빼도 정답을 보장하는 이유는 2^n의 마지막 자리로 가능한 수가 2, 4, 6, 8이기 때문
  ans[ans.length() - 1] -= 1;

  cout << ans << "\n";

  if(n <= 20) {
    hanoi(1, 2, 3, n);
  }

  return 0;
}