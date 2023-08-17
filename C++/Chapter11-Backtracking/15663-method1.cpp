#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int n, m, temp;
vector<int> nums;
vector<int> selected;
map<string, bool> visitedStr;
bool visited[8];

void combination() {
  if(selected.size() == m) {
    string str; // 현재 수열을 문자열로 변환, 이전에 출력된 적이 없는 경우에만 출력함
    for(int i = 0; i < selected.size(); i++) {
      str.push_back(selected[i] + '0');
    }
    if(visitedStr[str] != true) {
      visitedStr[str] = true;
      for(int i = 0; i < selected.size(); i++) {
        cout << selected[i] << " ";
      } 
      cout << "\n";
    }
  }

  for(int i = 0; i < n; i++) {
    if(visited[i]) continue;

    visited[i] = true;
    selected.push_back(nums[i]);
    combination();
    selected.pop_back();
    visited[i] = false;
  }
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    nums.push_back(temp);
  }

  sort(nums.begin(), nums.end());

  combination();

  return 0;
}