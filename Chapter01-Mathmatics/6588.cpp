#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000000;
bool isPrime[MAX + 1];

void eratosthenes() {
  // 초기화
  for(int i = 2; i <= MAX; i++) {
    isPrime[i] = true;
  }

  // 소수 걸러내기
  for(int i = 2; i <= sqrt(MAX); i++) {
    if(!isPrime[i]) continue;

    for(int j = 2*i; j <= MAX; j += i) {
      isPrime[j] = false;  
    }
  }
}

// 주어진 짝수 n에 대한 골드바흐 파티션을 출력
void findGoldbach(int n) {
  int a = 3;
  int b = n-a;
  
  // n = a + b를 유지
  while(a <= b) {
    if(isPrime[a] && isPrime[b]) {
      printf("%d = %d + %d\n", n, a, b);
      return;
    }
    // a와 b는 홀수이므로 2씩 증가
    a += 2;
    b -= 2;
  }
  // while문을 다 돌고도 골드바흐 파티션을 찾지 못한 경우
  printf("Goldbach's conjecture is wrong.\n");
}

int main() {
  int n;

  eratosthenes();

  scanf("%d", &n);
  while(n != 0) {
    findGoldbach(n); 
    scanf("%d", &n);
  }

  return 0;
}