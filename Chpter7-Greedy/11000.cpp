#include <bits/stdc++.h>
using namespace std;

// 강의실 목록을 한번만 탐색하여 답을 구할 방법 찾기
int main() {
  // vector 컨테이너를 이용해 우선순위 큐 구현, 오른차순으로 정렬하겠다는 뜻 (최소 힙)
  priority_queue<int, vector<int>, greater<int>> pq;
  vector<pair<int, int>> v;
  int n, a, b;
  
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a >> b;
    v.push_back({a, b});
  }

  sort(v.begin(), v.end());

  pq.push(v[0].second);
  for(int i = 1; i < n; i++) {
    int cur = pq.top();
    // 큐에 들어있는 (가장 빠른)회의 종료 시간보다 현재 회의 시작 시간이 늦거나 같은 경우. 
    // 즉 회의 시작 가능한 경우, 현재 회의를 해당 강의실에 배정함 (top을 pop한 후, 현재 회의를 push)
    // 그렇지 않은 경우 새로운 강의실을 배정함 (현재 회의를 push)
    if(cur <= v[i].first) {
      pq.pop();
    }
    pq.push(v[i].second);
  }

  cout << pq.size();

  return 0;
}