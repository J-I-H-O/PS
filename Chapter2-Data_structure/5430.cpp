#include <bits/stdc++.h>
using namespace std;

int t, n;
string command;
string numStr;
deque<int> inputNum;

void clearDeque() {
  while(!inputNum.empty()) {
    inputNum.pop_back();
  }
}

void printDeque() {
  cout << '[';
  for(int i = 0; i < inputNum.size(); i++) {
    cout << inputNum[i];
    if(i + 1 != inputNum.size())
      cout << ',';
  }
  cout << "]\n";
}

// 입력받은 숫자들을 문자열로 취급하여 파싱, 덱에 저장함
void parseInt() {
  for(int index = 1; index < numStr.size() - 1; index++) {
    // 현재 보고있는 문자의 다음 문자 저장
    char nextCh = numStr[index + 1];
    // 현재 보고있는 문자가 숫자인 경우
    if('0' <= numStr[index] && numStr[index] <= '9') {
      int num = numStr[index] - '0';

      // 다음 문자가 숫자가 아닐때까지 반복
      while('0' <= numStr[index + 1] && numStr[index + 1] <= '9') {
        num *= 10;
        num += numStr[index + 1] - '0';
        index++;
      }
      inputNum.push_back(num);
    }
  }
}

int main() {
  cin >> t;
  for(int i = 0; i < t; i++) {
    cin >> command;
    cin >> n;
    cin >> numStr;

    clearDeque();
    parseInt();

    bool isInverted = false;
    bool isError = false;
    for(auto c : command) {
      if(c == 'R') {
        isInverted = !isInverted;
      }
      else {
        if(inputNum.empty()) {
          cout << "error\n";
          isError = true;
          break;
        }

        // 뒤집히지 않은 경우(이전에 짝수번의 R을 입력받은 경우)
        if(!isInverted) {
          inputNum.pop_front();
        }
        // 뒤집힌 경우(이전에 홀수번의 R을 입력받은 경우)
        else {
          inputNum.pop_back();
        }
      }
    }

    if(isInverted)
      reverse(inputNum.begin(), inputNum.end());

    if(!isError) {
      printDeque();
    }
  }

  return 0;
}