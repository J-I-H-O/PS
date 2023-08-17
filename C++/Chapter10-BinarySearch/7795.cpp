#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int t, n, m, temp;
vector<int> A, B;

// target 보다 작은 수의 최댓값 구하기
int binarySearch(int target) {
  int st = 0;
  int en = m - 1;

  while(st < en) {
    int mid = (st + en + 1) / 2;
    if(B[mid] < target) {
      st = mid;
    } else {
      en = mid - 1;
    }
  }
  return st;
}

int main() {
  cin >> t;
  while (t--) {
    int ans = 0;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> temp;
      A.push_back(temp);
    }
    for (int i = 0; i < m; i++) {
      cin >> temp;
      B.push_back(temp);
    }

    sort(B.begin(), B.end());

    for(int i = 0; i < n; i++) {
      int res = binarySearch(A[i]);
      if(!(res == 0 && B[res] >= A[i]))
        ans += res + 1;
    }

    cout << ans << "\n";
    A.clear();
    B.clear();
  }

  return 0;
}