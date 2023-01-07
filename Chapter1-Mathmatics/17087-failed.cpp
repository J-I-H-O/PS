#include <bits/stdc++.h>
using namespace std;

int minVal = 1000000001;
int maxVal = -1;
int n, s, found = 0, temp, ans = 1;
bool breakFlag = false;
vector<bool> visited; // DP
vector<int> kidLoc;    // 동생들의 위치 저장

void clearVisited() {
  for(int i = 0; i <= maxVal; i++) {
    visited[i] = false;
  }
}

void findKid(int cur, int d) {
  // 이미 방문한 위치는 건너뜀
  if(visited[cur]) return;
  if(breakFlag) return;     // 동생을 모두 찾은 경우 true가 됨. 바로 함수 종료

  visited[cur] = true;
  // 현재 위치에 동생이 있는 경우
  if(find(kidLoc.begin(), kidLoc.end(), cur) != kidLoc.end()) {
    found++;
    // 동생을 모두 찾은 경우
    if(found == kidLoc.size()) {
      breakFlag = true;
      ans = d;
    }
  }

  if(minVal <= cur - d) {
    findKid(cur - d, d);
  }

  if(cur + d <= maxVal) {
    findKid(cur + d, d);
  }
}

int main() {
  scanf("%d %d", &n, &s);

  for(int i = 0; i < n; i++) {
    scanf("%d", &temp);
    kidLoc.push_back(temp);
    if(temp > maxVal) maxVal = temp;
    if(temp < minVal) minVal = temp;
  }

  for(int i = 0; i <= maxVal; i++) {
    visited.push_back(false);
  }

  for(int i = 2; i < maxVal; i++) {
    found = 0;
    breakFlag = false;
    clearVisited();
    findKid(s, i);
  }

  printf("%d", ans);

  return 0;
}