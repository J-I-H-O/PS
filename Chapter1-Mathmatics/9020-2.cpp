#include <bits/stdc++.h>
using namespace std;

const int MAX = 10000;
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
  int a = 2;
  int b = n - a;
  int resA, resB;

  while(a <= b) {
    if(isPrime[a] && isPrime[b]) {
      resA = a;
      resB = b;
    }
    a++;
    b--;
  }
  printf("%d %d\n", resA, resB);
}

int main() {
  int T, n;
  scanf("%d", &T);

  eratosthenes();

  for(int i = 0; i < T; i++) {
    scanf("%d", &n);

    findGoldbach(n);
  }

  return 0;
}