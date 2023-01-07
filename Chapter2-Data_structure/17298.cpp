#include <bits/stdc++.h>
using namespace std;

int n, temp;
vector<pair<pair<int, int>, int>> ans; // <<값, 오큰수>, 원소 번호>
stack<pair<int, int>> s; // <원소 번호, 값>

bool ascending(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  return a.second < b.second;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    // 스택에서 자신보다 작은 수들을 모두 제거. 자신이 제거한 수들의 오큰수가 됨
    while(!s.empty() && s.top().second < temp) {
      ans.push_back({{s.top().second, temp}, s.top().first});
      s.pop();
    }
    s.push({i, temp});
  }

  // 입력이 모두 종료되도 스택에 남아있는 수들은 오큰수가 없는 수
  while(!s.empty()) {
    ans.push_back({{s.top().second, -1}, s.top().first});
    s.pop();
  }

  // ans를 원소 번호 기준으로 정렬 후 출력
  sort(ans.begin(), ans.end(), ascending);

  for(int i = 0; i < ans.size(); i++) {
    printf("%d ", ans[i].first.second);
  }
  

  return 0;
}