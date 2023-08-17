#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000000;
bool isPrime[MAX + 1];
int t, n;

void eratosthenes() {
  // 초기화
  for(int i = 2; i <= MAX; i++) {
    isPrime[i] = true;
  }
  
  for(int i = 2; i <= sqrt(MAX); i++) {
    if(!isPrime[i]) continue;
    for(int j = 2*i; j <= MAX; j += i) {
      isPrime[j] = false;
    }
  }
}

// 입력된 수의 골드바흐 파티션의 수 리턴
int goldbach(int num) {
  int res = 0;
  int front = 2;
  int back = num - 2;

  while(front <= back) {
    // front와 back 모두 소수이면 두 수는 num의 골드바흐 파티션
    if(isPrime[front] && isPrime[back]) {
      res++;
    }
    front++;
    back--;
  }
  return res;
}

int main() {
  // 1~MAX까지 소수 여부 판별
  eratosthenes();

  scanf("%d", &t);
  for(int i = 0; i < t; i++) {
    scanf("%d", &n);
    printf("%d\n", goldbach(n));
  }

  return 0;
}