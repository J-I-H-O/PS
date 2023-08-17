#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  int gcd, lcm;
  scanf("%d %d", &a, &b);

  // 최대공약수 구하기
  for(int i = 1; i <= max(a, b); i++) {
    if(a % i == 0 && b % i == 0) {
      gcd = i;
    }
  }

  // 최소공배수 구하기
  lcm =a * b / gcd;

  printf("%d\n%d", gcd, lcm);

  return 0;
}