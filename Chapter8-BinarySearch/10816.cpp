#include <bits/stdc++.h>
using namespace std;

int n, m, temp;
vector<int> nums;

// target이 삽입될 수 있는 가장 왼쪽 인덱스와 가장 오른쪽 인덱스의 차가 상근이가 가진 숫자카드의 수
int binarySearch(int target) {
  int leftIdx, rightIdx;
  int st = 0;
  int en = n; // 배열의 가장 뒤쪽에 삽입될 수도 있기 때문에 최대 인덱스보다 하나 더 큰 값으로 초기화

  // leftIdx(target이 오른차순을 지키며 삽입될 수 있는 가장 왼쪽 위치) 찾기
  while(st < en) {
    int mid = (st + en) / 2;
    if(nums[mid] < target) {
      st = mid + 1;
    } else {
      // 현재 위치가 target이 삽입될 수 있는 가장 왼쪽일 수 있으므로 범위에 포함시키는 것
      en = mid;
    }
  }
  leftIdx = st;

  // rightIdx(target이 오른차순을 지키며 삽입될 수 있는 가장 오른쪽 위치) 찾기
  st = 0;
  en = n;
  while(st < en) {
    int mid = (st + en) / 2;
    if(nums[mid] <= target) {
      st = mid + 1;
    } else {
      en = mid;
    }
  }
  rightIdx = st;

  return rightIdx - leftIdx;
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
    cout << binarySearch(temp) << " ";
  }

  return 0;
}