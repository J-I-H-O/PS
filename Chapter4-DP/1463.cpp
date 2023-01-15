#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000000;
int calcCnt[MAX + 1];   // n부터 인덱스에 해당하는 수까지 도달하는데 필요한 연산 횟수의 최솟값 저장
int n;

int main() {
  cin >> n;
  calcCnt[1] = 0;

  // dp는 이전 연산 결과를 바탕으로 다음 연산 결과를 계산하므로, 값을 채워나가는 방향을 잘 고려해야 함.
  for(int i = 2; i <= n; i++) {
    calcCnt[i] = calcCnt[i-1] + 1;
    if(i % 3 == 0) {
      calcCnt[i] = min(calcCnt[i], calcCnt[i/3] + 1);
    }
    if(i % 2 == 0) {
      calcCnt[i] = min(calcCnt[i], calcCnt[i/2] + 1);
    }
  }
  cout << calcCnt[n];

  return 0;
}