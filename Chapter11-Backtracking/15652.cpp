#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> selected;

void combination(int cur) {
  if(selected.size() == m) {
    for(int i = 0; i < selected.size(); i++) {
      cout << selected[i] << " ";
    }
    cout << "\n";
    return;
  }

  for(int i = cur; i <= n; i++) {
    selected.push_back(i);
    combination(i);
    selected.pop_back();
  }
}

int main() {
  cin >> n >> m;
  combination(1);

  return 0;
}