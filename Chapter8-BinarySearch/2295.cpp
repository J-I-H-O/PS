#include <bits/stdc++.h>
using namespace std;

int n, temp;
vector<int> nums;
vector<int> two;  // 두개의 수를 미리 선택하여 합을 구해놓음. O(N^2)
int ans = 0;

bool binarySearch(int target) {
  int st = 0;
  int en = two.size() - 1;

  while(st <= en) {
    int mid = (st + en) / 2;
    if(two[mid] == target) {
      return true;
    } else if(two[mid] < target) {
      st = mid + 1;
    } else {
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

  // 두개의 수를 미리 선택하여 합을 구해놓음. O(N^2)
  // 이후 two에 저장된 모든 수와 num에 저장된 모든 수를 더해보며 이분탐색을 수행
  // 이분탐색: O(logN)
  // nums와 two 배열의 각각의 원소에 대해 반복: O(N^2)
  // 총 시간복잡도는 O(N^2logN)
  for(int i = 0; i < n; i++) {
    for(int j = i; j < n; j++) {
      two.push_back(nums[i] + nums[j]);
    }
  }

  sort(nums.begin(), nums.end());
  sort(two.begin(), two.end());

  // 총 O(N^2logN)
  // 큰 값부터 비교하므로 가장 처음에 찾은 수가 정답
  // nums는 오름차순으로 정렬되어있으므로, 아래와 같은 조건에서 항상 nums[i] >= nums[j]를 만족
  for(int i = nums.size() - 1; i >= 0; i--) {
    for(int j = i; j >= 0; j--) {
      // a + b + c = d를 변형하면 a + b = d - c식을 얻을 수 있음
      // a+b의 집합은 두 수의 합을 저장한 two배열과 같음
      // d: nums[i], c: nums[j]
      // d가 최대가 되려면 c도 큰 값부터 시작해야 함
      // 즉 집합U(nums 배열)에 속한 d와 c의 차가 two 배열에 속한 경우는 세 수의 합이 U에 속하는 경우와 같다.
      int DsubC = nums[i] - nums[j];

      if(binarySearch(DsubC)) {
        ans = max(ans, nums[i]); 
      }
    }
  }

  cout << ans;

  return 0;
}