#include <bits/stdc++.h>
using namespace std;

int n;
const int MAX = 20;
long long fiboVal[MAX + 1] = {0,};

long long fibo(int n) {
  if(n == 0) return 0;
  if(n <= 2) return 1;

  // DP
  if(fiboVal[n] != 0) return fiboVal[n];
  long long val = fibo(n-1) + fibo(n-2);
  fiboVal[n] = val;
  return val;
}

int main() {
  cin >> n;
  cout << fibo(n);

  return 0;
}