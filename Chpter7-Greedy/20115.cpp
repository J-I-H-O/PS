#include <bits/stdc++.h>
using namespace std;

int n, temp;
double ans;
vector<int> drinks;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    drinks.push_back(temp);
  }

  sort(drinks.begin(), drinks.end());

  for(int i = 0; i < n-1; i++) {
    ans += drinks[i]/(double)2;
  }
  ans += drinks[n-1];

  cout << ans;

  return 0;
}