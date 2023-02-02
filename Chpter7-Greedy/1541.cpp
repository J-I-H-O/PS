#include <bits/stdc++.h>
using namespace std;

int main() {
  string input;
  bool isNegative = false;  // 이전에 '-'를 만났는지 여부 판단
  int curNum = 0;           
  int ans = 0;
  
  cin >> input;
  input += '-'; // dummy data
  for(int i = 0; i < input.size()-1; i++) {
    // 현재 문자가 숫자인 경우
    if('0' <= input[i] && input[i] <= '9') {
      curNum *= 10;
      curNum += input[i] - '0';

      // 현재 보고있는 문자가 숫자의 끝인 경우
      if(input[i+1] == '+' || input[i+1] == '-') {
        if(isNegative) {
          ans -= curNum;
        } else {
          ans += curNum;
        }
        curNum = 0;
      }
    }

    if(input[i] == '-')
      isNegative = true;
  }

  cout << ans;

  return 0;
}