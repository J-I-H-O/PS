#include <bits/stdc++.h>
using namespace std;

int n, m, temp;
int cnt = 0;
int targetIdx;
deque<int> deq;

int getTargetIdx(int target) {
  int targetIdx;
  for(int i = 0; i < deq.size(); i++) {
    if(deq[i] == target) {
      targetIdx = i;
      break;
    }
  }
  return targetIdx;
}

// deq의 앞에서 원소를 빼내 뒤로 삽입
void rotateLeft() {
  int val = deq.front();
  deq.pop_front();
  deq.push_back(val);
}

void rotateRight() {
  int val = deq.back();
  deq.pop_back();
  deq.push_front(val);
}

int main() {
  cin >> n >> m;
  // 초기화
  for(int i = 1; i <= n; i++) {
    deq.push_back(i);
  }

  // 필요한 연산 수 카운트
  for(int i = 0; i < m; i++) {
    cin >> temp;
    // 입력 받은 수의 현재 인덱스 찾기
    targetIdx = getTargetIdx(temp);

    if(targetIdx > deq.size() / 2) {
      // 오른쪽으로 회전
      for(int j = 0; j < deq.size() - targetIdx; j++) {
        rotateRight();
        cnt++;
      }
    }
    else {
      // 왼쪽으로 회전
      for(int j = 0; j < targetIdx; j++) {
        rotateLeft();
        cnt++;
      }
    }
    deq.pop_front();
  }

  cout << cnt;

  return 0;
}