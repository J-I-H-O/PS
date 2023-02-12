// 연결 리스트를 활용하여 배정된 강의는 리스트에서 삭제하며 그리디를 수행함.
// 그리디 한 라운드가 종료되면 리스트에 남아있는 강의들에 대해 다시 그리디를 수행
// 위 과정을 반복하고, 반복된 그리디 라운드의 횟수를 출력함
// 최악의 경우 O(n^2)로 시간초과

// ========================================
//         ================================
//                 ========================
//                          ===============
//                              ===========
//                                    =====
//                                       ==

// 강의 시간이 위와 같은 경우, 각 라운드 당 하나의 강의만 선택되고, 매 라운드마다 남아있는 모든 강의들을 살펴봐야 함.

#include <bits/stdc++.h>
using namespace std;

int n, s, e;
list<pair<int, int>> classes; // <강의 시작 시각, 강의 종료 시각>
int ans = 0;

bool comp(pair<int, int> a, pair<int, int> b) {
  // 강의 종료 시각이 같은 경우, 강의 시작 시각이 빠른 것 부터 선택
  if(a.second == b.second) {
    return a.first < b.first;
  }
  return a.second < b.second;
}

// 강의가 끝나는 시각이 빠른 순으로 겹치지 않게 선택.
// 겹친 강의들에 대해서 다시 그리디 수행. 그리디를 수행한 횟수를 출력
// △ 시간초과. 
int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> s >> e;
    classes.push_back({s, e});
  }

  // 강의 종료 시각을 기준으로 오름차순 정렬
  classes.sort(comp);

  // 배정된 강의는 리스트에서 삭제하므로, 모든 강의가 배정되면 리스트가 비어있게 됨
  while(!classes.empty()) {
    pair<int, int> cur = classes.front();
    classes.pop_front();
    for(list<pair<int, int>>::iterator it = classes.begin(); it != classes.end(); it++) {
      // 현재 살펴보고 있는 강의의 시작 시각이 가장 최근 강의의 종료 시각보다 늦거나, 같은 경우
      if(cur.second <= (*it).first) {
        cur = (*it);
        it = classes.erase(it);
      }
    }
    ans++;
  }

  cout << ans;


  return 0;
}