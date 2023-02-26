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
  }

  int last = 0;
  for(int i = 0; i < n; i++) {
    // last는 마지막으로 넣었다 빼는 수를 가리킴
    // 이후 같은 수를 다시 넣는 경우는 중복되는 수열을 출력하는 경우가 되므로, 해당 경우는 건너뜀
    if(visited[i] || last == nums[i]) continue;

    visited[i] = true;
    selected.push_back(nums[i]);
    last = nums[i];
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