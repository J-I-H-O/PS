#include <bits/stdc++.h>
using namespace std;

int n, s, temp;
int sum = 0, ans = 0;
vector<int> input;
vector<int> subset;

void printInfo() {
  printf("subset : ");
  for(vector<int>::iterator it = subset.begin(); it != subset.end(); it++) {
    printf("%d ", *it);
  }
  printf("\n");
  printf("sum : %d\n", sum);
}

void getSubsetSum0(int cur) {
  subset.push_back(cur);
  sum += input[cur];
  if(sum == s) ans++;

  // printInfo();

  // base
  if(cur == n-1) return;

  for(int i = cur + 1; i < n; i++) {
    getSubsetSum0(i);
    subset.pop_back();
    sum -= input[i];
  }
}

int main() {
  scanf("%d %d", &n, &s);

  for(int i = 0; i < n; i++) {
    scanf("%d", &temp);
    input.push_back(temp);
  }

  for(int i = 0; i < n; i++) {
    getSubsetSum0(i);
    // i를 시작으로 subset 모두 구한 뒤, 남아있는 i를 빼내고 다음 차례로 넘어가야 함
    subset.pop_back();
    sum -= input[i];
  }

  printf("%d", ans);

  return 0;
}