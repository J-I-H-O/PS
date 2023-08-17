#include <bits/stdc++.h>
using namespace std;

string input;
int ans = 0;
stack<char> s;
char prevCh;    // 바로 직전에 살펴본 문자 저장

int main() {
  cin >> input;
  for(auto c : input) {
    // c가 여는 괄호면 무조건 push
    if(c == '(') {
      s.push('(');
    }
    else {
      // 레이저인 경우
      if(prevCh == '(') {
        s.pop();
        ans += s.size();
      }
      // 쇠막대의 끝인 경우 
      else {
        s.pop();
        ans++;
      }
    }
    prevCh = c;
  }
  printf("%d", ans);

  return 0;
}