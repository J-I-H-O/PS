#include <bits/stdc++.h>
using namespace std;

bool isVisited[26];
int n, ans = 0;
string input;

int main() {
  cin >> n;
  while(n--) {
    fill_n(isVisited, 26, false);
    cin >> input;

    isVisited[input[0] - 'a'] = true;
    bool isAns = true;
    for(int i = 1; i < input.size(); i++) {
      // 직전 문자와 현재 문자가 같지 않은 경우
      if(input[i] != input[i-1]) {
        // 이전에 현재 문자와 같은 문자를 발견한 경우(그룹 단어가 될 수 없는 경우)
        if(isVisited[input[i] - 'a']) {
          isAns = false;
          break;
        }
      }
      isVisited[input[i] - 'a'] = true;
    }
    if(isAns) ans++;
  }
  cout << ans;

  return 0;
}