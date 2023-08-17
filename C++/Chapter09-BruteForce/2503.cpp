#include <iostream>
using namespace std;

bool isCandidate[1000];  // 어떤 수가 정답의 후보가 될 수 있는지 여부 저장
string input;
int n, strike, ball;
int ans = 0;

// 입력으로 주어진 숫자와 모든 숫자를 비교, strike 수와 ball 수가 같은 것만
// 남기고, 나머지는 후보에서 탈락시킴
void filterCandidate() {
  for (int i = 123; i <= 987; i++) {
    string cur = to_string(i);
    // 이미 후보에서 탈락한 경우, 더이상 살펴보지 않음
    if(!isCandidate[i]) continue;
    // 같은 숫자를 여러개 가지는 수는 후보에서 제외함
    if(cur[0] == cur[1] || cur[1] == cur[2] || cur[0] == cur[2]) {
      isCandidate[i] = false;
      continue;
    }
    // 정답이 1~9 사이의 숫자로만 표현되므로 0이 포함된 숫자는 후보에서 제외함
    if(cur[0] == '0' || cur[1] == '0' || cur[2] == '0') {
      isCandidate[i] = false;
      continue;
    }
    
    int strikeCnt = 0;
    int ballCnt = 0;

    for (int j = 0; j < 3; j++) {
      // 숫자와 그 자리까지 같은 경우
      if (cur[j] == input[j]) {
        strikeCnt++;
      } else {
        for (int k = 0; k < 3; k++) {
          // 자리는 다르지만 같은 수를 갖는 경우
          if (j != k && input[j] == cur[k]) {
            ballCnt++;
          }
        }
      }
    }

    // 스트라이크 수 또는 볼 수가 입력과 다른 경우, 현재 숫자를 후보에서 탈락시킴
    if (strike != strikeCnt || ball != ballCnt) {
      isCandidate[i] = false;
    }
  }
}

int main() {
  fill_n(isCandidate, 1000, true);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> input >> strike >> ball;
    filterCandidate();
  }

  for (int i = 123; i <= 987; i++) {
    if (isCandidate[i]) ans++;
  }
  cout << ans;

  return 0;
}