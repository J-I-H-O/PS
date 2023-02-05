#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n, temp;
long long ans = 0;

bool descending(int a, int b) {
  return a > b;
}

int main() {
  cin >> n; 
  for(int i = 0; i < n; i++) {
    cin >> temp;
    v.push_back(temp);
  }

  sort(v.begin(), v.end(), descending);

  for(int i = 0; i < n; i++) {
    int val = v[i] - i;
    if(val >= 0)
      ans += val;
  }

  cout << ans;

  return 0;
}