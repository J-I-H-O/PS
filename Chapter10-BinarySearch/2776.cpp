#include <iostream>
#include <algorithm>
using namespace std;

int t, n, m, target;
int note1[1000001];

bool binarySearch() {
  int st = 0;
  int en = n-1;

  while(st <= en) {
    int mid = (st + en) / 2;
    if(note1[mid] == target) return true;
    if(note1[mid] < target) {
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

  cin >> t;
  while(t--) {
    cin >> n;
    for(int i = 0; i < n; i++) {
      cin >> note1[i];
    }

    sort(note1, note1 + n);

    cin >> m;
    for(int i = 0; i < m; i++) {
      cin >> target;
      if(binarySearch()) {
        cout << 1 << "\n";
      } else {
        cout << 0 << "\n";
      }
    }
  }

  return 0;
}