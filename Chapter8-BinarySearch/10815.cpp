#include <bits/stdc++.h>
using namespace std;

int n, m, temp;
vector<int> cards;

int binarySearch(int target) {
  int st = 0;
  int en = n-1;
  while(st <= en) {
    int mid = (st + en) / 2;

    if(cards[mid] == target) {
      return 1;
    } else if (cards[mid] < target) {
      st = mid + 1;
    } else {
      en = mid - 1;
    }
  }
  return 0;
} 

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    cards.push_back(temp);
  }

  sort(cards.begin(), cards.end());

  cin >> m;
  for(int i = 0; i < m; i++) {
    cin >> temp;
    cout << binarySearch(temp) << " ";
  }

  return 0;
}