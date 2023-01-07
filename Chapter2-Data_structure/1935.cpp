#include <bits/stdc++.h>
using namespace std;

int n, temp;
stack<double> operands;   // 입력된 피연산자 저장
vector<int> inputs;
string postfix;

int main() {
  cin >> n;
  cin >> postfix;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    inputs.push_back(temp);
  }

  // calculate postfix
  for(auto c : postfix) {
    // 현재 보고있는 c가 피연산자일 경우, 그 값을 operands 스택에 저장
    if('A' <= c && c <= 'Z') {
      operands.push(inputs[c - 'A']);
    }
    // 현재 보고있는 c가 연산자일 경우 operand에 저장된 숫자 두개를 꺼내 계산 후 다시 스택에 집어넣음
    else {
      double n1, n2;
      n2 = operands.top();
      operands.pop();
      n1 = operands.top();
      operands.pop();

      if(c == '+') operands.push(n1 + n2);
      if(c == '-') operands.push(n1 - n2);
      if(c == '*') operands.push(n1 * n2);
      if(c == '/') operands.push(n1 / n2);
    }
  }
  printf("%.2lf", operands.top());

  return 0;
}