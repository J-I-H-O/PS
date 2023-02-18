#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, temp;
int st = 0, en = 0;
vector<int> lectures;

// 블루레이 크기가 주어졌을 때, 모든 강의를 블루레이에 담으려면 몇개의 블루레이가 필요한지 계산
int getGroupNum(int storageSize) {
  // 모든 강의를 담는데 필요한 총 블루레이의 개수
  int res = 1;
  int size = 0;
  for(int i = 0; i < lectures.size(); i++) {
    if(size + lectures[i] > storageSize) {
      // 새로운 블루레이에 현재 강의를 저장
      size = 0;
      res++;
    } 
    size += lectures[i];
  }
  return res;
}

// 가능한 블루레이 크기 결정(파라메트릭 서치)
int binarySearch() {
  while(st <= en) {
    int mid = (st + en) / 2;
    int groupNum = getGroupNum(mid);

    if(groupNum <= m) {
      en = mid - 1;
    } else {
      st = mid + 1;
    }
  }

  return st;
}

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    lectures.push_back(temp);

    // 하나의 블루레이 사이즈로 선택 가능한 수의 최솟값은 입력된 강의 길이의 최댓값과 같음
    // 하나의 블루레이 사이즈로 선택 가능한 수의 최댓값은 모든 강의 길이의 합과 같음
    st = max(st, lectures[i]);
    en += lectures[i];
  }
  cout << binarySearch();

  return 0;
}