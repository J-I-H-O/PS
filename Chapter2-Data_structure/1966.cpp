#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, n, m, temp;
  cin >> t;
  for(int i = 0; i < t; i++) {
    deque<pair<int, int>> deq;  // <문서 번호, 우선순위>

    cin >> n >> m;

    for(int j = 0; j < n; j++) {
      cin >> temp;
      deq.push_back({j, temp});
    }

    // 나머지 문서들 중 현재 문서보다 중요도가 높은 문서가 있는 경우, 현재 문서를 덱의 가장 뒤로 재배치. 
    int maxPriority = deq[0].second;
    for(int k = 0; k < deq.size(); k++) {
      if(maxPriority < deq[i].second) {
        
        break;
      }
    }
  }

  return 0;
}