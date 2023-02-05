#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<pair<int, int>> v;
  priority_queue<int, vector<int>, greater<int>> pq;
  int n, a, b;

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> a >> b;
    v.push_back({a, b});
  }
  sort(v.begin(), v.end());

  pq.push(v[0].second);
  for(int i = 1; i < n; i++) {
    if(pq.top() <= v[i].first) {
      pq.pop();
    }
    pq.push(v[i].second);
  }

  cout << pq.size();

  return 0;
}