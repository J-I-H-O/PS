#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> selected;

void printSelected() {
  for(int i = 0; i < selected.size(); i++) {
    printf("%d ", selected[i]);
  }
  printf("\n");
}

bool isIncluded(int x) {
  for(int i = 0; i < selected.size(); i++) {
    if(selected[i] == x)
      return true;
  }
  return false;
}

void progression(int cur) {
  // base condition
  // n개가 모두 선택된 경우
  if(selected.size() >= n) {
    printSelected();
    return;
  }

  for(int i = 1; i <= n; i++) {
    // i가 현재 선택되지 않은 경우
    if(!isIncluded(i)) {
      selected.push_back(i);
      progression(i+1);
      selected.pop_back();
    }
  }
}

int main() {
  scanf("%d", &n);

  progression(1);

  return 0;
}