// triangle(n) = triangle(n-1) + triangle(n-5)

#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
long long pArr[MAX + 1];
int t, n;

long long p(int n) {
    if(n <= 3) {
      return 1;
    }
    if (n <= 5) {
      return 2;
    }

  // 아직 결과값을 메모하지 않은 경우
  if(pArr[n] == 0) {
    long long res = p(n-1) + p(n-5);
    pArr[n] = res;
    return res;
  }
  return pArr[n];
}

int main() {
  // pArr[1] = pArr[2] = pArr[3] = 1;
  // pArr[4] = pArr[5] = 2;
  cin >> t;
  for(int i = 0; i < t; i++) {
    cin >> n;
    cout << p(n) << "\n";
  }
  return 0;
}