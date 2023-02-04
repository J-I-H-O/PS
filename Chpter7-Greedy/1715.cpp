#include <bits/stdc++.h>
using namespace std;


int main() {
  int n, temp;
  long long ans = 0;
  priority_queue<long long, vector<long long>, greater<long long>> decks;

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    decks.push(temp);
  }

  // 이미 합친 카드팩을 포함하여 카드 묶음 중 가장 작은 것 두개를 선택해 합침
  // 최소 힙에서 두개의 원소를 꺼내고, 합친 결과를 다시 최소 힙에 넣음.
  // 최소 힙의 원소가 한 개만 남는 경우 종료
  while(decks.size() > 1) {
    long long n1 = decks.top();
    decks.pop();
    long long n2 = decks.top();
    decks.pop();

    ans += n1 + n2;
    decks.push(n1 + n2);
  }

  cout << ans;

  return 0;
}