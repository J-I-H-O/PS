#include <bits/stdc++.h>
using namespace std;

int t, n;
int nums[3] = {1, 2, 3};
int selectedSum = 0;
int ansCnt = 0;
vector<int> selected;

void selectNum() {
  if(selectedSum == n) {
    ansCnt++;
    return;
  }

  for(int i = 0; i < 3; i++) {
    if(selectedSum + nums[i] <= n) {
      selectedSum += nums[i];

      selectNum();

      selectedSum -= nums[i];
    }
  }  
}

int main() {
  cin >> t;
  for(int i = 0; i < t; i++) {
    selectedSum = 0;
    ansCnt = 0;

    cin >> n;
    selectNum();
    cout << ansCnt << "\n";
  }

  return 0;
}