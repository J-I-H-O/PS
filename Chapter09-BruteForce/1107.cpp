#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m, temp, digit = 0;
bool isBroken[10];
vector<int> selected;
int res, resDigit, minDiff;

// 주어진 숫자 버튼만으로 목표 값에 최대한 가까운 수를 만들어내고(중복 가능),
// 만들어낸 수와 목표 값의 차를 계산 정답은 만들어낸 숫자의 자릿수 + 목표 값과

void makeNum() {
  // 현재 만든 숫자의 자릿수가 목표 값 n의 자릿수보다 2 높은 경우 종료함
  if (selected.size() >= digit + 2) return;

  if (!selected.empty()) {
    // 현재 만들어진 숫자와 목표 값의 차 계산
    int curNum = selected[0];
    for (int i = 1; i < selected.size(); i++) {
      curNum *= 10;
      curNum += selected[i];
    }
    int diff = abs(n - curNum);
    if (minDiff > diff) {
      minDiff = diff;
      res = curNum; 
    } else if(minDiff == diff && res > curNum) {
      // 차가 같은 수 중 더 작은 수 선택(자릿수가 더 적을 수 있으므로)
      minDiff = diff;
      res = curNum; 
    }
  }

  for (int i = 0; i < 10; i++) {
    if (!isBroken[i]) {
      selected.push_back(i);
      makeNum();
      selected.pop_back();
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> temp;
    isBroken[temp] = true;
  }
  minDiff = abs(n - 100);
  res = 100;

  // 목표값 n의 자릿수 계산. 현재 만든 숫자의 자릿수가 목표 값의 자릿수보다 2
  // 높은 경우 종료함
  int tempVal = n;
  while (tempVal > 0) {
    tempVal /= 10;
    digit++;
  }

  makeNum();

  if (res == 0) {
    resDigit = 1;
  } else {
    while (res > 0) {
      res /= 10;
      resDigit++;
    }
  }

  // 시작지점(100) 에서 +, - 버튼만 눌러서 목표 값에 도달하는 것과 고장나지 않은
  // 숫자 버튼을 활용하는 것 중 버튼을 누르는 횟수가 적은 것 선택
  cout << min(abs(100 - n), resDigit + minDiff);

  return 0;
}