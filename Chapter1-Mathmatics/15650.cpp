#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> selected;

void printSelected() {
  for(vector<int>::iterator it = selected.begin(); it != selected.end(); it++) {
    printf("%d ", *it);
  }
  printf("\n");
}

void progression(int cur) {
  if(selected.size() >= m) {
    printSelected();
    return;
  }

  for(int i = cur; i <= n; i++) {
    selected.push_back(i);
    progression(i+1);
    selected.pop_back();
  }
}

int main() {
  scanf("%d %d", &n, &m);

  progression(1);

  return 0;
}