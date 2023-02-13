#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n, k, temp;
vector<pair<int, int>> cards;     // <카드에 적힌 값, 입력으로 들어온 인덱스>
vector<pair<int, int>> selected;  // <카드에 적힌 값, 입력으로 들어온 인덱스>
map<int, int> cnt;  // <만들 수 있는 정수, 해당 정수를 만들 수 있는 횟수>

void makeInteager() {
  // k개의 카드를 선택한 경우, 해당 카드들을 일렬로 이어붙인 숫자를 key로 하는
  // cnt의 value 값을 증가 중복 방지 위함
  if (selected.size() == k) {
    int res = 0;
    for (int i = 0; i < k; i++) {
      // 다음에 붙일 숫자가 두 자리수인 경우
      if (selected[i].first >= 10) {
        res *= 100;
      } else {
        res *= 10;
      }
      res += selected[i].first;
    }
    cnt[res] += 1;
  }

  for (int i = 0; i < n; i++) {
    bool isSelected = false;
    for(int j = 0; j < selected.size(); j++) {
      // 현재 보고있는 i번째 카드가 이미 선택되어 있는 경우
      if(selected[j].second == i) {
        isSelected = true;
        break;
      }
    }

    if(!isSelected) {
      selected.push_back(cards[i]);
      makeInteager();
      selected.pop_back();
    }
  }
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    cards.push_back({temp, i});
  }

  makeInteager();
  cout << cnt.size();

  return 0;
}