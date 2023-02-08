#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
string input;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> input;

    bool isAnswer = true;
    for(int i = 0; i < input.size() && isAnswer; i++) {
      char curChar = input[i];
      bool isSameAsCur = true;
      for(int j = i; j < input.size(); j++) {
        if(curChar != input[j]) {
          isSameAsCur = false;
        } else {
          // 현재 문자와 같은 문자가 떨어져 존재하는 경우
          if(!isSameAsCur) {
            isAnswer = false;
            break;
          }
        }
      }
    }
    if(isAnswer) ans++;
  }

  cout << ans;

  return 0;
}