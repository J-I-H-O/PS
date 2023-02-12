#include <bits/stdc++.h>
using namespace std;

int n;
int inputNum;
string inputStr;
vector<pair<int, string>> members;

bool comp(pair<int, string> a, pair<int, string> b) {
  return a.first < b.first;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> inputNum;
    cin >> inputStr;
    members.push_back({inputNum, inputStr});
  }

  sort(members.begin(), members.end(), comp);

  for(int i = 0; i < members.size(); i++) {
    cout << members[i].first << " " << members[i].second << "\n";
  }

  return 0;
}