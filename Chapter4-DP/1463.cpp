#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000000;
int calcCnt[MAX + 1];   // n부터 인덱스에 해당하는 수까지 도달하는데 필요한 연산 횟수의 최솟값 저장
int n;

int countCalc(int cur) {
  // base condition
  if(cur == 1)
    return calcCnt[1]; // 0

  vector<int> calcList;

  // 현재 숫자에서 한번의 연산을 통해 만들 수 있는 수 목록을 calcList에 저장
  if(cur % 3 == 0) {
    calcList.push_back(cur/3);
  }
  if(cur % 2 == 0) {
    calcList.push_back(cur/2);
  }
  calcList.push_back(cur-1);

  int minCalc;
  if(calcCnt[calcList[0]] == 0) {
    minCalc= countCalc(calcList[0]) + 1;
  }
  else {
    minCalc = calcList[0] + 1;
  }

  for(int i = 1; i < calcList.size(); i++) {
    int comp;
    if(calcCnt[calcList[i]] == 0) {
      comp = countCalc(calcList[i]) + 1;
    }
    else {
      comp = calcCnt[calcList[i]] + 1;
    }

    if(minCalc > comp)
      minCalc = comp;
  }
  calcCnt[cur] = minCalc;
  return minCalc;
}

int main() {
  cin >> n;
  calcCnt[1] = 0;
  cout << countCalc(n);

  return 0;
}