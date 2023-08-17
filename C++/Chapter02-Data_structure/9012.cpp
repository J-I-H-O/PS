#include <bits/stdc++.h>
using namespace std;

stack<char> s;
int t;
string input;

void clearStack() {
  while(!s.empty()) {
    s.pop();
  }
}

int main() {
  cin >> t;
  for(int i = 0; i < t; i++) {
    clearStack();
    bool isCorrect = true;
    cin >> input;
    // 입력된 괄호 문자열의 문자를 하나씩 체크
    for(int j = 0; j < input.size(); j++) {
      // 여는 괄호는 일단 저장
      if(input[j] == '(') {
        s.push('(');
      }
      // 닫는 괄호일 경우, 먼저 스택이 비어있는지 체크
      else {
        if(s.empty()) {
          isCorrect = false;
          break;
        }
        else {
          s.pop();
        }
      }
    }
    // 문자열 내의 모든 문자를 확인했을 때 스택에 괄호가 남아있다면 여는 괄호가 더 많은 경우이므로, 잘못된 괄호 문자열임
    if(!s.empty()) isCorrect = false;

    if(!isCorrect) {
      printf("NO\n");
    }
    else {
      printf("YES\n");
    }
  }

  return 0;
}