#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, d, temp;
vector<int> arr;

int binarySearch() {
  int st = 0;
  int en = n - 1;
  bool isFound = false;

  while(st <= en) {
    int mid = (st + en) / 2;

    if(arr[mid] >= d) {
      if(arr[mid] == d) isFound = true;
      en = mid - 1;
    } else {
      st = mid + 1;
    }
  }

  if(isFound) {
    return st;
  } else {
    return -1;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    arr.push_back(temp);
  }
  sort(arr.begin(), arr.end());

  for(int i = 0; i < m; i++) {
    cin >> d;
    cout << binarySearch() << "\n";
  }

  return 0;
}