#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, temp;
vector<int> nums;
vector<int> selected;
bool visited[8];

void combination() {
  if(selected.size() == m) {
    for(int i = 0; i < selected.size(); i++) {
      cout << selected[i] << " ";
    }
    cout << "\n";
    return;
  }

  for(int i = 0; i < n; i++) {
    if(visited[i]) continue;

    visited[i] = true;
    selected.push_back(nums[i]);
    combination();
    selected.pop_back();
    visited[i] = false;
  }
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    nums.push_back(temp);
  }

  sort(nums.begin(), nums.end());
  combination();

  return 0;
}