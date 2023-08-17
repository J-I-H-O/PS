#include <bits/stdc++.h>
using namespace std;

string input;
string ans = "";
bool isZeroOK = false;  // 0을 출력해도 되는지 여부

int main() {
  cin >> input;
  // 수가 0인 경우 0 출력하고 종료
  if(input == "0") {
    cout << 0;
    return 0;
  }

  for(int i = input.size() - 1; i >= 0; i--) {
    int digit = input[i] - '0';
    for(int j = 0; j < 2; j++) {
      ans.push_back((digit % 2) + '0');
      digit /= 2;
    }
    ans.push_back(digit + '0');
  }
  
  // 출력
  for(int i = ans.size(); i >= 0; i--) {
    if(ans[i] == '1') {
      cout << ans[i];
      isZeroOK = true;
    } else {
      if(isZeroOK) {
        cout << ans[i];
      }
    }
  }

  return 0;
}