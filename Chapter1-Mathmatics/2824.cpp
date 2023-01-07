#include <bits/stdc++.h>
using namespace std;

// 입력으로 들어오는 각각의 수에 대하여 소인수분해, 
// A의 소인수분해 리스트와  B의 소인수분해 리스트를 비교해서 공통된 base를 가지는 것 중 exponent값이 더 작은 것들만 취해서 곱해주면 최대공약수를 얻을 수 있다

// map 이용, key는 해당 소인수(base), value는 등장 횟수(exponent)

// 소인수분해는 다음과 같이 진행
  // 어떤 수로 입력된 수를 나누었을 때 나누어 떨어지면 그 수(약수)를 map에 저장
  // 입력된 수를 해당 약수로 나누어줌
  // 입력된 수가 완전히 나누어 떨어질 때까지 반복

int n, m, temp;
vector<int> primes;
map<int, int> mapA;
map<int, int> mapB;

// 소인수분해
void primeFactorization(int num, map<int, int> &map) {
  // 
  for(int i = 2; i*i <= num; i++) {
    while(num % i == 0) {
      map[i]++;
      num /= i;
    }
  }
  if(num != 1)
    map[num]++;
}

int main() {
  // A의 약수들을 입력받고, 그 수들을 소인수분해하여 (값, 빈도) 쌍의 map으로 저장
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &temp);
    primeFactorization(temp, mapA);
  }

  // B의 약수들을 입력받고, 그 수들을 소인수분해하여 (값, 빈도) 쌍의 map으로 저장
  scanf("%d", &m);
  for(int i = 0; i < m; i++) {
    scanf("%d", &temp);
    primeFactorization(temp, mapB);
  }

  long long ans = 1;
  bool isBig = false;
  for(map<int, int>::iterator it = mapA.begin(); it != mapA.end(); it++) {
    // mapA에 저장된 소인수가 mapB에도 존재하는 경우
    if(mapB.find(it->first) != mapB.end()) {
      int repeat = min(it->second, mapB[it->first]);
      for(int i = 0; i < repeat; i++) {
        ans *= it->first;
        // 정답이 9자리보다 긴 경우
        if(ans > 999'999'999) {
          isBig = true;
          ans %= 1000000000;
        }
      }
    }
  }

  if(isBig) {
    printf("%09d", ans);  
  } else {
    printf("%d", ans);
  }
  
  return 0;
}