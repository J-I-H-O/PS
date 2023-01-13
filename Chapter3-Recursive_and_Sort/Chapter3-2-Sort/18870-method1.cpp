#include <bits/stdc++.h>
using namespace std;

int n, temp;
vector<int> input;
vector<int> compressed;

// compressed 벡터에 입력된 값을 중복 없이 저장하고, 오름차순으로 정렬.
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    input.push_back(temp);
    // 입력된 값을 따로 저장해두고 중복 제거
    compressed.push_back(temp);
  }

  // https://donggoolosori.github.io/2020/09/26/boj-18870/
  // https://cocoon1787.tistory.com/562

  // 정렬
  sort(compressed.begin(), compressed.end());
  // 중복 제거. unique 함수는 연속된 중복값만 제거하므로 한번 정렬해야함.
  // unique는 중복값을 제거한 뒤, 앞에서부터 다시 씀. 중복값이 사라져 남게 된 공간은 원본값 유지.
  // 원본이 유지 된 원소들의 첫번째 주소값을 리턴하므로, erase로 지워주면 최종적으로 중복되지 않은 값들을 얻을 수 있음
  compressed.erase(unique(compressed.begin(), compressed.end()), compressed.end());

  for(int i = 0; i < n; i++) {
    // compressed 벡터는 중복이 제거되었고, 오름차순으로 정렬된 상태이므로 해당 위치 이전에 존재하는 값의 개수가 압축된 좌표.
    // lower_bound 함수는 주어진 값보다 크거나 같은 값이 제일 처음 등장하는 곳 위치를 리턴함.
    auto it = lower_bound(compressed.begin(), compressed.end(), input[i]);
    // it - compressed.begin()은 전체 입력값들 중 현재 값보다 작은 값의 개수
    cout << it - compressed.begin() << " ";
  }

  return 0;
}