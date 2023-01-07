#include <bits/stdc++.h>
using namespace std;

int n;
deque<int> deck;

int main() {
  cin >> n;
  // 카드 뭉치 생성
  for(int i = 1; i <= n; i++) {
    deck.push_back(i);
  }

  while(deck.size() != 1) {
    deck.pop_front(); // 제일 위의 카드 버리기
    
    int temp = deck.front();
    deck.pop_front();
    deck.push_back(temp);
  }

  cout << deck[0];

  return 0;
}