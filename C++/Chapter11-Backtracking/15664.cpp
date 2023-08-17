#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, temp;
vector<int> nums;
vector<int> selected;
bool visited[8];

void combination(int cur) {
  if(selected.size() == m) {
    for(int i = 0; i < selected.size(); i++) {
      cout << selected[i] << " ";
    }
    cout << "\n";
    return;
  }

  int last = 0;
  for(int i = cur; i < n; i++) {
    if(visited[i] || last == nums[i]) continue;

    visited[i] = true;
    last = nums[i];
    selected.push_back(nums[i]);
    combination(i+1);
    selected.pop_back();
    visited[i] = false;
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