#include <bits/stdc++.h>
using namespace std;

bool submitted[31];
int n;

int main() {
  for(int i = 1; i <= 28; i++) {
    cin >> n;
    submitted[n] = true;
  }

  for(int i = 1; i <= 30; i++) {
    if(!submitted[i]) {
      cout << i << "\n";
    }
  }

  return 0;
}