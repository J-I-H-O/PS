#include <bits/stdc++.h>
using namespace std;

int n, temp;
vector<int> input;
vector<int> ans;

// 최대공약수 구하기
int getGCD(int a, int b) {
  int r;
  while(true) {
    r = a % b;
    if(r == 0) return b;

    a = b;
    b = r;
  }
}

int main() {
  int gcd;

  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &temp);
    input.push_back(temp);
  }

  // 계산 편의를 위해 오름차순 정렬
  sort(input.begin(), input.end());

  // 인접한 두 수들의 차를 구하여 묶고, 그들의 최대공약수를 구함
  // 입력된 모든 수들의 최대공약수를 구할 수 있음
  gcd = input[1] - input[0];
  for(int i = 2; i < n; i++) {
    gcd = getGCD(gcd, input[i] - input[i-1]);
  }

  // 구한 최대공약수의 약수들을 모두 출력
  // 입력된 모든 수들의 최대공약수의 약수 집합 == 입력된 모든 수들의 약수 집합
  for(int i = 2; i*i <= gcd; i++) {
    if(gcd % i == 0) {
      ans.push_back(i);
      if(i != gcd/i)
        ans.push_back(gcd/i);
    }
  }
  ans.push_back(gcd);

  sort(ans.begin(), ans.end());
  for(int i = 0; i < ans.size(); i++) {
    printf("%d ", ans[i]);
  }

  return 0;
}