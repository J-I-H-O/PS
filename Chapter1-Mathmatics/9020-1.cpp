#include <bits/stdc++.h>
using namespace std;

const int MAX = 10000;
bool isPrime[MAX + 1];
vector<int> primes;

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

  for(int i = 2; i <= MAX; i++) {
    if(isPrime[i]) {
      primes.push_back(i);
    }
  }
}

// 주어진 짝수 n에 대한 골드바흐 파티션을 출력
// O(n^2)... 더 나은 방법이 있을까?
void findGoldbach(int n) {
  int a = 0, b = 0;
  
  for(int i = 0; i < primes.size(); i++) {
    if(primes[i] > n) break;
    for(int j = i; j < primes.size(); j++) {
      if(primes[j] > n) break;

      // 골드바흐 파티션 발견
      if(primes[i] + primes[j] == n) {
        // 이전에 골드바흐 파티션이 발견되지 않은 경우
        if(a == 0) {
          a = primes[i];
          b = primes[j];
        }
        // 새로운 골드바흐 파티션이 발견되었을 때, 그 차가 기존 골드바흐 파티션의 차보다 작은 경우 대체
        if(primes[j] - primes[i] < b - a) {
          a = primes[i];
          b = primes[j]; 
        }
      }
    }
  }

  printf("%d %d\n", a, b);
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