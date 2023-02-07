#include <bits/stdc++.h>
using namespace std;

int n, ans = 0, cowNum, location;
int cowLoc[11];

int main() {
  fill_n(cowLoc, 11 , -1);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> cowNum >> location;
    if(cowLoc[cowNum] == -1) {
      cowLoc[cowNum] = location;
    } else {
      if(cowLoc[cowNum] != location) {
        ans++;
        cowLoc[cowNum] = location;
      }
    } 
  }
  cout << ans;

  return 0;  
}