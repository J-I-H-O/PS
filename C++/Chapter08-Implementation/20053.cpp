#include <bits/stdc++.h>
using namespace std;

int nums[1000000];
int t,  n;
int maxVal, minVal;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  cin >> t;
  while(t--) {
    maxVal = -1000001;
    minVal = 1000001;

    cin >> n;
    for(int i = 0; i < n; i++) {
      cin >> nums[i];
      if(nums[i] > maxVal) {
        maxVal = nums[i];
      }
      if(nums[i] < minVal) {
        minVal = nums[i];
      }
    }

    cout << minVal << " " << maxVal << "\n";
  }

  return 0;
}