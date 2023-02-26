#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> selected;

void combination() {
  if(selected.size() == m) {
    for(int i = 0; i < selected.size(); i++) {
      cout << selected[i] << " ";
    }
    cout << "\n";
    return;
  }

  for(int i = 1; i <= n; i++) {
    selected.push_back(i);
    combination();
    selected.pop_back();
  }
}

int main() {
  cin >> n >> m;
  combination();

  return 0;
}