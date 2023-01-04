#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 123456;
const int LEN = MAX_N * 2 + 1;  // 배열 길이
bool isPrime[LEN];

// 1~LEN 까지의 소수 여부를 isPrime에 저장
void eratosthenes() {
  // 초기화
  isPrime[0] = isPrime[1] = false;
  for(int i = 2; i < LEN; i++) {
    isPrime[i] = true;
  }

  for(int i = 2; i <= sqrt(LEN); i++) {
    if(!isPrime[i]) continue;

    for(int j = 2*i; j < LEN; j += i) {
      isPrime[j] = false;
    }
  }
}

int main() {
  int n;

  // 1~LEN 까지의 소수 여부를 미리 저장
  eratosthenes();

  // 0이 입력될 때 까지 입력을 받으며 n~2n 까지의 소수 개수 구하기
  scanf("%d", &n);
  while(n != 0) {
    int res = 0;
    for(int i = n + 1; i <= 2*n; i++) {
      if(isPrime[i]) res++;
    }
    printf("%d\n", res);
    scanf("%d", &n);
  }

  return 0;
}