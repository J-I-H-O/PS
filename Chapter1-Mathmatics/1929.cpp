#include <bits/stdc++.h>
using namespace std;

int m, n;
const int MAX = 1000001; 
bool isPrime[MAX];
int res = 0;  // 1~n 까지의 소수의 개수

// 1~n까지의 범위 내의 소수들과 그 개수를 출력
void eratosthenes() {
  isPrime[1] = false;
  // 1. 2이상의 수들을 일단 true로 초기화
  for(int i = 2; i <= n; i++) {
    isPrime[i] = true;
  }

  // 2. 배열을 순차적으로 순회하며 값이 TRUE인 요소들은 소수로 선택, 그 배수에 해당하는 값은 FALSE로 변경
  //    sqrt(n) 이하의 수의 배수만 지우면 됨
  for(int i = 2; i <= sqrt(n); i++) {
    // 값이 이미 FALSE로 설정된 수에 대해서는 이전에 탐색한 수의 배수이므로 지워졌다고 판단하고 넘어감
    if(!isPrime[i]) continue;

    // i의 배수들을 모두 제거
    for(int j = 2*i; j <= n; j += i) {
      isPrime[j] = false;
    }
  }
}

int main() {
  scanf("%d %d", &m, &n);
  eratosthenes();

  for(int i = m; i <= n; i++) {
    if(isPrime[i]) 
      printf("%d\n", i);
  }

  return 0;
}