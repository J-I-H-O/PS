#include <bits/stdc++.h>
using namespace std;

int n, height;
stack<pair<int, int>> s;  // <탑 번호, 높이>

int main() {
  // 실패 이유 : cin과 printf를 섞어 씀. printf를 cout으로 바꾸고, stdio와의 sync를 끊으니 통과
  // 입출력 빈도가 커지면 신경써야함
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin >> n;

  for(int i = 1; i <= n; i++) {
    cin >> height;
    // 현재까지 입력된 탑 중 현재 탑의 신호를 수신하지 못하는 탑은 모두 삭제
    // 즉, 입력받은 height 이하의 값을 갖는 탑들을 스택에서 제거
    // 현재 탑이 이전 탑들보다 클 경우, 현재 탑이 이전에 입력된 탑들을 가릴 것이기 때문
    while(!s.empty() && s.top().second <= height) {
      s.pop();
    }

    if(s.empty()) {
      cout << "0" << " ";
    }
    else {
      cout << s.top().first << " ";
    }
    s.push({i, height});
  }

  return 0;
}