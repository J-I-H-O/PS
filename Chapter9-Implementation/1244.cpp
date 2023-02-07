#include <bits/stdc++.h>
using namespace std;

int n, m;
int gender, switchNum;
int switchStat[101];

// gen: 성별, sNum: 스위치 번호
void changeSwitchStat(int gen, int sNum) {
  // 남학생인 경우
  if(gen == 1) {
    for(int i = sNum; i <= n; i += sNum) {
      switchStat[i] = (switchStat[i] + 1) % 2;
    }
  } else {
    // 여학생인 경우
    int dist = 0;
    int nxtDist = 1;

    while(1 <= sNum - nxtDist && sNum + nxtDist <= n && switchStat[sNum - nxtDist] == switchStat[sNum + nxtDist]) {
      dist++;
      nxtDist++;
    }

    for(int i = sNum - dist; i <= sNum + dist; i++) {
      switchStat[i] = (switchStat[i] + 1) % 2;
    }
  }
}

int main() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> switchStat[i];
  }
  cin >> m;
  for(int i = 1; i <= m; i++) {
    cin >> gender >> switchNum;
    changeSwitchStat(gender, switchNum);
  }

  int printCnt = 0;
  for(int i = 1; i <= n; i++) {
    cout << switchStat[i] << " ";
    printCnt++;
    if(printCnt == 20) cout << "\n";
  }

  return 0;
}