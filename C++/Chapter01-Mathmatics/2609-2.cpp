#include <bits/stdc++.h>
using namespace std;

// 유클리드 호제법. a > b라고 가정
int euclidean(int a, int b) {
  int r;

  // 반복문의 조건식이 평가될 때 b에는 나머지가 저장됨
  while(b != 0) {
    r = a % b;
    a = b;        // a : 나뉘는 수
    b = r;        // b : 나누는 수
  }
  // while문을 빠져나온 뒤 a에는 나누는 수가 저장
  return a;
}

int main() {
  int a, b;
  int gcd, lcm;
  scanf("%d %d", &a, &b);

  // 최대공약수 구하기
  gcd = euclidean(max(a, b), min(a, b));

  // 최소공배수 구하기
  lcm =a * b / gcd;

  printf("%d\n%d", gcd, lcm);

  return 0;
}