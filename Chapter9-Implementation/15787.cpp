#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

int n, m;
int command, trainNum, seatNum;
deque<string> train;  // train[i][j]: i번째 기차의 j번 좌석 상태. 0은 빈 좌석, 1은 사람이 타있는 좌석

int main() {
  cin >> n >> m;

  // 가독성을 위해 n+1개의 기차를 추가함 (1개의 더미데이터)
  for (int i = 0; i <= n; i++) {
    // 가독성을 위해 21개의 좌석 생성 (1개의 더미데이터)
    train.push_back("000000000000000000000");
  }

  for (int i = 0; i < m; i++) {
    cin >> command;
    switch (command) {
      case 1:
        cin >> trainNum >> seatNum;
        if (train[trainNum][seatNum] == '0') {
          train[trainNum][seatNum] = '1';
        }
        break;
      case 2:
        cin >> trainNum >> seatNum;
        if (train[trainNum][seatNum] == '1') {
          train[trainNum][seatNum] = '0';
        }
        break;
      case 3:
        cin >> trainNum;
        for (int i = 20; i > 1; i--) {
          train[trainNum][i] = train[trainNum][i - 1];
        }
        train[trainNum][1] = '0';
        break;
      case 4:
        cin >> trainNum;
        for (int i = 1; i < 20; i++) {
          train[trainNum][i] = train[trainNum][i + 1];
        }
        train[trainNum][20] = '0';
        break;
    }
  }

  // 더미 데이터 제거
  train.pop_front();
  // 중복 제거. sort 후 erase, unique 적용. 원리 찾아보기
  sort(train.begin(), train.end());
  train.erase(unique(train.begin(), train.end()), train.end());
  cout << train.size();
}