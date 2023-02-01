#include <bits/stdc++.h>
using namespace std;

int n, temp;
vector<int> rope;

bool descending(int a, int b) {
  return a > b;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> temp;
    rope.push_back(temp);
  }

  sort(rope.begin(), rope.end(), descending);

  // 각각의 로프에 걸리는 최대 중량
  int maxWeight = rope[0];
  for(int i = 1; i < rope.size(); i++) {
    // 현재 로프를 선택했을 때 각각의 로프가 견딜 수 있는 최대 중량이 더 증가하는 경우
    if(maxWeight < rope[i] * (i+1)) {
      maxWeight = rope[i] * (i+1);
    }
  }

  cout << maxWeight;

  return 0;
}