#include <bits/stdc++.h>
using namespace std;

int k, temp, sum = 0;
stack<int> s;

void calSum() {
  while(!s.empty()) {
    sum += s.top();
    s.pop();
  }
}

int main() {
  cin >> k;
  for(int i = 0; i < k; i++) {
    cin >> temp;
    if(temp != 0) 
      s.push(temp);
    else 
      s.pop();
  }
  calSum();
  printf("%d", sum);

  return 0;
}