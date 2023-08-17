#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m, temp;
vector<int> cards;

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    cards.push_back(temp);
  }

  sort(cards.begin(), cards.end());

  int maxVal = 0;
  for (int i = n - 1; i >= 2; i--) {
    for (int j = i - 1; j >= 1; j--) {
      for (int k = j - 1; k >= 0; k--) {
        int sum = cards[i] + cards[j] + cards[k];
        if (sum <= m && maxVal < sum) {
          maxVal = sum;
        }
      }
    }
  }
  cout << maxVal;

  return 0;
}