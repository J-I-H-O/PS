#include <bits/stdc++.h>
using namespace std;

string input, ans;
int cnt = 0;

int main() {
  cin >> input;
  // input[i+1]을 for문 안에서 사용함. 배열의 범위를 넘어서 참조하지 않도록 더미 데이터 추가
  input += '.';

  for(int i = 0; i < input.size()-1; i++) {
    if(input[i] == 'X') {
      cnt++;
    } else {
      // 보드판을 덮을 수 없는 경우
      if(cnt % 2 != 0) {
        break;
      } else {
        ans += '.';
      }
    }

    if(cnt == 4) {
      ans += "AAAA";
      cnt = 0;
    }
    if(cnt == 2 && input[i+1] != 'X') {
      ans += "BB";
      cnt = 0;
    }
  }

  if(cnt % 2 == 0)
    cout << ans;
  else
    cout << -1;

  return 0;
}