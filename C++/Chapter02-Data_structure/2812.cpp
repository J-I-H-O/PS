#include <bits/stdc++.h>
using namespace std;

int n, k;
string input;
deque<char> d;

int main() {
  cin >> n >> k;
  cin >> input;

  for(auto c : input) {
    // 현재 살펴보고 있는 수와 덱에 있는 수들을 비교, 현재 살펴보고 있는 수가 덱에있는 수보다 클 때 덱에 있는 수를 덱에서 제거.
    // 이 때, 제거 횟수가 k번이 되면 반복문 종료
    while(!d.empty() && k != 0 && d.back() < c) {
      d.pop_back();
      k--;  // 제거 횟수 카운트
    }
    d.push_back(c);
  }

  // 모든 수를 삺펴보고도 k개만큼 숫자를 제거하지 못한 경우, 덱의 뒤에서부터 남은 제거 횟수만큼의 수를 제거하고 나머지 출력
  // 뒤에서부터 남은 k개의 수를 제거해도 되는 이유는, 덱에 남은 수들은 자신이 덱에 삽입되면서 자신보다 작은 수를 모두 제거했기 때문
  // (e.g.) 987654321 과 같이 이전에 입력된 모든 수가 자신보다 작은 경우, 아무 수도 제거하지 못한 채 반복문이 종료될 수 있음.
  for(int i = 0; i < d.size() - k; i++) {
    cout << d[i];
  }

  return 0;
}