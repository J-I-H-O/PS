#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int sum = 0;
  
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    sum += i;
  }
  printf("%d", sum);

  return 0;
}