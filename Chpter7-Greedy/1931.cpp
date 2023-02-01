#include <bits/stdc++.h>
using namespace std;

int n, a, b, ans = 0;
vector<pair<int, int>> v; // <회의 종료 시각, 회의 시작 시각>

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a >> b;
    v.push_back({b, a});
  }

  // 현재 선택 가능한 회의 중 회의 종료 시각이 가장 빠른 것부터 선택
  sort(v.begin(), v.end());

  // cur: 현재 진행중인 회의 정보
  pair<int, int> cur = v[0];
  ans++;
  for(int i = 1; i < v.size(); i++) {
    // 다음 회의로 선택 가능한 경우
    if(cur.first <= v[i].second ) {
      cur = v[i];
      ans++;
    }
  }

  cout << ans;

  return 0;
}