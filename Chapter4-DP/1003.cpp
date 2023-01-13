#include <bits/stdc++.h>
using namespace std;

const int MAX = 40;
int t, n;
// fiboCnt(n)이 호출되었을 때, 해당 n에 대해 fiboCnt(0)과 fiboCnt(1)이 몇 번 호출되는지 저장(memo)
// <fiboCnt(0)이 호출된 횟수, fiboCnt(1)이 호출된 횟수>
pair<int, int> callCnt[MAX + 1]; 

pair<int, int> fiboCnt(int n) {
  // n이 0 또는 1인 경우
  if(n == 1 || n == 0)
    return callCnt[n];
  
  // n이 0 또는 1이 아닌 경우
  // 이전에 fiboCnt(n)이 호출된적 없으면(callCnt[n] == {0, 0}인 경우), 값을 직접 구해 메모 후 리턴
  if(callCnt[n].first == 0 && callCnt[n].second == 0) {
    pair<int, int> fiboFirst = fiboCnt(n-1);
    pair<int, int> fiboSecond = fiboCnt(n-2);
    // memo
    callCnt[n] = {fiboFirst.first + fiboSecond.first, fiboFirst.second + fiboSecond.second};
  }
  return callCnt[n];
}

int main() {
  cin >> t;
  callCnt[0] = {1, 0};
  callCnt[1] = {0, 1};
  for(int i = 0; i < t; i++) {
    cin >> n;
    pair<int, int> res = fiboCnt(n);
    cout << res.first << " " << res.second << "\n";
  }

  return 0;
}