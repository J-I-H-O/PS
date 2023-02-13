#include <iostream>
#include <vector>
using namespace std;

vector<int> squares;
int selected = 0;
int n, ans = 5;

void combination(int cur, int curSum) {
  // 선택된 제곱수들의 합이 n이 되는 경우, 선택된 제곱수의 수가 현재까지 밝혀진 제곱수의 수보다 작은 경우 갱신 후 종료
  // 모든 자연수는 4개 이하의 제곱수의 합으로 표현되므로 selected가 4개 이상인 경우 선택된 제곱수의 합이 n이 되는지 확인 후 종료함
  if (selected == 4 || curSum == n) {
    if (curSum == n) {
      ans = selected;
    }
    return;
  }

  for (int i = cur; i < squares.size(); i++) {
    if (curSum + squares[i] > n) break;

    // ans를 갱신할 수 있는 경우에만 실행
    selected++;
    if(selected < ans) {
      combination(i, curSum + squares[i]);
    }
    selected--;
  }
}

int main() {
  cin >> n;
  for (int i = 1; i * i <= n; i++) {
    squares.push_back(i * i);
  }

  combination(0, 0);

  cout << ans;

  return 0;
}