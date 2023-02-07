#include <bits/stdc++.h>
using namespace std;

int n, m;
int temp;
string inputStr;
vector<pair<int, string>> title;  // <칭호, 전투력 상한값>

string binarySearch(int target) {
  int st = 0;
  int en = title.size() - 1;

  while(st < en) {
    int mid = (st + en) / 2;
    if(target <= title[mid].first) {
      en = mid;
    } else {
      st = mid + 1;
    }
  }

  return title[en].second;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> inputStr >> temp;

    // 같은 상한값을 가진 칭호가 중복되어 입력되지 않도록 하기 위함
    // 칭호가 비내림차순으로 입력되므로 가장 마지막 원소와 비교해주면 됨
    if(!title.empty() && title.back().first == temp) continue;
    
    title.push_back({temp, inputStr});
  }

  sort(title.begin(), title.end());

  for(int i = 0; i < m; i++) {
    cin >> temp;
    cout << binarySearch(temp) << "\n";
  }

  return 0;
}