#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, temp;
vector<int> nums;
vector<int> selected;

void combination() {
  if(selected.size() == m) {
    for(int i = 0; i < selected.size(); i++) {
      cout << selected[i] << " ";
    }
    cout << "\n";
    return;
  }

  for(int i = 0; i < nums.size(); i++) {
    selected.push_back(nums[i]);
    combination();
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

  nums.erase(unique(nums.begin(), nums.end()), nums.end());

  combination();

  return 0;
}