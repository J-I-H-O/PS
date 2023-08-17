#include <bits/stdc++.h>
using namespace std;

deque<int> people;
vector<int> ans;
int n, k;

int main() {
  cin >> n >> k;
  // 덱에 n명의 사람 번호 넣기
  for(int i = 1; i <= n; i++) {
    people.push_back(i);
  }

  while(!people.empty()) {
    // 왼쪽으로 k번 회전 후 가장 뒤에 있는 사람을 제거 (순열에 추가`)
    for(int i = 0; i < k; i++) {
      int deleted = people.front();
      people.pop_front();
      people.push_back(deleted);
    }
    ans.push_back(people.back());
    people.pop_back();
  }

  cout << '<';
  for(int i = 0; i < ans.size() - 1; i++) {
    cout << ans[i] << ", ";
  }
  cout << ans[ans.size() - 1] << '>';

  return 0;
}