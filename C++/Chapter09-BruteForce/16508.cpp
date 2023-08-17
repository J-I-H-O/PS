#include <iostream>
#include <vector>
#include <climits>
using namespace std;

string t, input;
int n, temp, ans = INT_MAX;
bool ansFound = false;
vector<pair<int, string>> books;
vector<pair<int, string>> selected;
int target[26];       // 목표 단어를 만들기 위해 필요한 알파벳의 숫자 저장
int selectedChar[26]; // 현재 선택된 책들에 포함된 알파벳 개수 저장

// 현재 선택된 책들로 목표 단어를 만들 수 있는 경우
bool isCompleted() {
  for(int i = 0; i < 26; i++) {
    if(target[i] != 0) {
      if(target[i] > selectedChar[i]) {
        return false;
      }
    }
  }
  ansFound = true;
  return true;
}

void combination(int cur) {
  if(isCompleted()) {
    int curCost = 0;
    for(int i = 0; i < selected.size(); i++) {
      curCost += selected[i].first;
    }
    ans = min(ans, curCost);
    return;
  }

  for(int i = cur; i < books.size(); i++) {
    selected.push_back(books[i]);
    for(auto c: books[i].second) {
      selectedChar[c - 'A']++;
    }

    combination(i + 1);

    selected.pop_back();
    for(auto c: books[i].second) {
      selectedChar[c - 'A']--;
    }
  }
}

int main() {
  cin >> t;
  // 목표 단어를 만들기 위해 필요한 알파벳의 숫자 저장
  for(auto c : t) {
    target[c - 'A']++;
  }
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> temp >> input;
    books.push_back({temp, input});
  }
  combination(0);

  if(ansFound) {
    cout << ans;
  } else {
    cout << -1;
  }

  return 0;
}