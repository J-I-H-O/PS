#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

string s, t;
set<string> visited; // set을 이용해 해당 문자열을 만든적 있는지 검사

bool changeString() {
  queue<string> q;
  q.push(t);
  visited.insert(t);

  while(!q.empty()) {
    string cur = q.front();
    q.pop();

    // 목표 문자열을 만든 경우
    if(cur == s) return true;
    // 현재 만들어진 문자열이 목표 문자열(t) 보다 길이가 짧은 경우, 목표 문자열을 만들 수 없음을 뜻함
    if(cur.size() < s.size()) return false;

    // s -> t를 만드는 것이 아닌, t -> s로 지워감 (시간초과 방지)
    // s에서 t를 만드는 경우, 각 단계에서 항상 2개의 경우를 고려해야하는 반면, 
    // t에서 s를 만드는 경우, 조건에 따라 2개 이하의 경우가 고려되기 때문

    // 1. 마지막에 A를 추가한 경우
    if(cur[cur.size()-1] == 'A') {
      string str = cur;
      str.pop_back();
      if(visited.find(str) == visited.end()) {
        q.push(str);
        visited.insert(str);
      }
    }
    // 2. B를 추가하고 문자열을 뒤집은 경우
    if(cur[0] == 'B') {
      string str = cur;
      reverse(str.begin(), str.end());
      str.pop_back();
      if(visited.find(str) == visited.end()) {
        q.push(str);
        visited.insert(str);
      }
    }
  }

  return false;
}

int main() {
  cin >> s >> t;

  if(changeString()) {
    cout << 1;
  } else {
    cout << 0;
  }

  return 0;
}