#include <bits/stdc++.h>
using namespace std;

int n, s, temp;
vector<int> dst; // 수빈이와 동생들 사이의 거리

int getGCD(int a, int b) {
  while(b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int main() {  
  scanf("%d %d", &n, &s);
  for(int i = 0; i < n; i++) {
    scanf("%d", &temp);
    dst.push_back(abs(temp - s));
  }

  sort(dst.begin(), dst.end());

  int gcdVal = dst[0];
  for(int i = 0; i < dst.size() - 1; i++) {
    gcdVal = getGCD(gcdVal, dst[i+1]);
  }

  printf("%d", gcdVal);

  return 0;
}