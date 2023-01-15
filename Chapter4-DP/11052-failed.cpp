#include <bits/stdc++.h>
using namespace std;

int n, temp;
vector<pair<pair<int, int>, double>> price; // <<한 팩 당 카드 개수, 팩 가격>, 카드 한 장 당 가격>
int moneySpent = 0;

// 팩에 포함 된 카드 한 장 당 가격(효율)을 기준으로 내림차순 정렬
// 효율이 같다면 포함된 카드 개수가 적은 팩을 선택
// 효율이 좋지 않은 팩 먼저 선택 (값이 클수록 효율 낮음)
bool comp(pair<pair<int, int>, double> a, pair<pair<int, int>, double> b) {
  // 두 팩의 효율이 같은 경우, 포함된 카드 개수가 적은 팩을 우선적으로 선택
  if(a.second == b.second) {
    return a.first.first < b.first.first;
  }
  // 효율이 낮은 팩을 우선적으로 선택
  return a.second > b.second;
}

int main() {
  cin >> n;

  int copyN = n;

  for(int i = 1; i <= n; i++) {
    cin >> temp;
    price.push_back({{i, temp}, (double)temp / (double)i});
  }

  sort(price.begin(), price.end(), comp);

  // copyN은 더 구입해야 할 카드 개수
  while(copyN > 0) {
    for(int i = 0; i < n; i++) {
      // 구입해야 할 카드 개수보다 현재 보고있는 카드팩의 카드 개수가 더 적거나 같은 경우
      while(copyN - price[i].first.first >= 0) {
        copyN -= price[i].first.first;
        moneySpent += price[i].first.second;
      }
    }
  }
  cout << moneySpent;

  return 0;
}