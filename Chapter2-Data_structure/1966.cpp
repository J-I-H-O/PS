#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, n, m, temp;
  cin >> t;
  for(int i = 0; i < t; i++) {
    int printCnt = 0; // 현재까지 프린트된 문서 개수 저장
    deque<pair<int, int>> deq;  // <문서 번호, 우선순위>

    cin >> n >> m;

    for(int j = 0; j < n; j++) {
      cin >> temp;
      deq.push_back({j, temp});
    }

    while(printCnt < n) {
      // 나머지 문서들 중 현재 문서보다 중요도가 높은 문서가 있는 경우, 현재 문서를 덱의 가장 뒤로 재배치.
      int maxIdx = deq[0].first;
      int maxPriority = deq[0].second;
      // 가장 우선순위가 높은 문서 찾기
      for(int k = 0; k < deq.size(); k++) {
        if(maxPriority < deq[k].second) {
          maxIdx = deq[k].first;
          maxPriority = deq[k].second;
        }
      }
      // 가장 우선순위가 높은 문서가 맨 앞으로 나올 때 까지 프린트 순서를 바꿈
      while(deq[0].first != maxIdx) {
        pair<int, int> doc = deq[0];
        deq.pop_front();
        deq.push_back(doc);
      }

      pair<int, int> printedDoc = deq.front();
      deq.pop_front();
      printCnt++;
      // 위 for문을 빠져나온 뒤, deq.front()는 남은 문서 중 가장 우선순위가 높은 문서.
      // m번 문서가 프린트 될 차례인 경우
      if(printedDoc.first == m) {
        cout << printCnt << '\n';
        break;
      }
    }
  }

  return 0;
}