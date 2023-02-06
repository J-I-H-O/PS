#include <bits/stdc++.h>
using namespace std;

int n, m, temp;
vector<int> req;

// 상한액이 주어졌을 때, 해당 상한액을 반영한 총 배정 예산 반환
long long calTotalBudget(int upperBudget) {
  long long res = 0;
  for(int i = 0; i < n; i++) {
    if(req[i] < upperBudget) {
      res += req[i];
    } else {
      res += upperBudget;
    }
  }
  return res;
}

// 상한액의 최댓값 반환
int binarySearch() {
  int st = 0;
  int en = m;

  while(st < en) {
    int mid = (st + en + 1) / 2;
    long long totalBudget = calTotalBudget(mid);

    if(totalBudget <= m) {
      st = mid;
    } else {
      en = mid - 1;
    }
  }

  return st;
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    req.push_back(temp);
  }
  cin >> m;

  sort(req.begin(), req.end());

  // 배정된 예산들 중 최댓값을 출력해야 하므로, 상한액의 최댓값과 요청받은 예산 중 더 작은 것을 출력함
  cout << min(binarySearch(), req[req.size() - 1]);

  return 0;
}