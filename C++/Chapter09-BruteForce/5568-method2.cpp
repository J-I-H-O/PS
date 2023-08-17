#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n, k, temp;
vector<int> cards;
vector<int> selected;
map<int, int> ans;  // map은 중복을 허용하지 않으므로 만들어진 정수를 map에 W저장하면 map.size()가 정답이 됨
bool visited[10];   // 각 카드가 selected에 포함되어있는지 여부 저장

// 순열
void permutation() {
  // base condition
  if (selected.size() == k) {
    int res = 0;
    for (int i = 0; i < selected.size(); i++) {
      // 두자리 수인 경우
      if (selected[i] >= 10) {
        res *= 100;
      } else {
        res *= 10;
      }
      res += selected[i];
    }
    ans[res] += 1;
  }

  for (int i = 0; i < n; i++) {
    if (visited[i]) continue;
    visited[i] = true;  // visited를 true로 바꾸어 i번째 카드가 선택되었음을 나타냄
    selected.push_back(cards[i]);
    permutation();
    selected.pop_back();
    visited[i] = false;  // i번째 카드를 선택 해제했으므로 visited를 false로 바꿔줌
  }
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    cards.push_back(temp);
  }

  permutation();
  cout << ans.size();

  return 0;
}