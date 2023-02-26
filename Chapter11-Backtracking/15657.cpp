#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, temp;
vector<int> nums;
vector<int> selected;

void combination(int cur) {
  if(selected.size() == m) {
    for(int i = 0; i < selected.size(); i++) {
      cout << selected[i] << " ";
    }
    cout << "\n";
    return;
  }

  for(int i = cur; i < n; i++) {
    selected.push_back(nums[i]);
    combination(i);
    selected.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    nums.push_back(temp);
  }

  sort(nums.begin(), nums.end());

  combination(0);

  return 0;
}