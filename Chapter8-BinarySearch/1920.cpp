#include <bits/stdc++.h>
using namespace std;

int n, m, temp;
vector<int> nums;

// target이 존재하면 true, 그렇지 않으면 false 반환
bool binarySearch(int target) {
  int st = 0;
  int en = n-1;

  while(st <= en) {
    int mid = (st + en + 1) / 2;

    if(nums[mid] == target) {         // 값을 찾은 경우
      return true;
    } else if(nums[mid] < target) {   // mid보다 target이 큰 경우, mid의 오른쪽으로 범위 변경
      st = mid + 1;
    } else {                          // mid보다 target이 작은 경우, mid의 왼쪽으로 범위 변경
      en = mid - 1;
    }
  }
  return false;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    nums.push_back(temp);
  }

  sort(nums.begin(), nums.end());

  cin >> m;
  for(int i = 0; i < m; i++) {
    cin >> temp;
    if(binarySearch(temp)) {
      cout << 1 << "\n";
    } else {
      cout << 0 << "\n";
    }
  }

  return 0;
}