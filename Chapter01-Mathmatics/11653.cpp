#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, temp;
  scanf("%d", &n);
  temp = n;

  while(temp > 1) {
    for(int i = 2; i <= temp; i++) {
      if(temp % i == 0) {
        printf("%d\n", i);
        temp /= i;
        break;
      }
    }
  }

  return 0;
}