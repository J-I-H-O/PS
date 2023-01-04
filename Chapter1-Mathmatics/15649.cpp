#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;

void progression() {
  // 모두 채운 경우 모든 요소 출력
  if(v.size() == m) {
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
      printf("%d ", *it);
    }
    printf("\n");
    return;
  }
  // 아직 배열이 모두 채워지지 않은 경우, m부터 n까지의 모든 수들 중 배열에 채워지지 않은 값을 채워넣음
  for(int i = 1; i <= n; i++) {
    // 해당 값이 배열에 존재하지 않는 경우 해당 요소를 배열에 넣고 다음 요소를 찾아 재귀
    if(find(v.begin(), v.end(), i) == v.end()) {
      v.push_back(i);
      progression();
      // 다음 반복을 위해 가장 최근에 넣은 요소를 제거
      v.pop_back();
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  progression();

  return 0;
}