#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
vector<int> selected;

void countPinary(int cur) {
  if(selected.size() == n) {
    ans++;
    return;
  }

  if(cur == 1) {
    selected.push_back(0);
    countPinary(0);
    selected.pop_back();
  }
  else {
    selected.push_back(0);
    countPinary(0);
    selected.pop_back();

    selected.push_back(1);
    countPinary(1);
    selected.pop_back();
  }
}

int main() {
  cin >> n;

  selected.push_back(1);
  countPinary(1);
  
  cout << ans;

  return 0;
}