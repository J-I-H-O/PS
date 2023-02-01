#include <bits/stdc++.h>
using namespace std;

int n, temp, ans = 0;
vector<int> v;

bool descending(int a, int b) {
  return a > b;
}

int main() {
  cin >> n; 
  for(int i = 0; i <n; i++) {
    cin >> temp;
    v.push_back(temp);
  }

  sort(v.begin(), v.end(), descending);

  // 가격이 높은 순으로 정렬하고, 세개씩 묶어냄
  for(int i = 0; i < n; i++) {
    if((i+1)%3 != 0)
      ans += v[i];
  }
  cout << ans;

  return 0;
}