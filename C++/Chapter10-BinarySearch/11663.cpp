#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> points;
int n, m, temp;
int stVal, enVal;

// 선분 위에 있는 점의 개수 반환
// 선분의 시작위치보다 크거나 같은 수 중 최솟값, 선분위 끝 위치보다 작거나 같은 수 중 최댓값 찾기
int binarySearch(int stVal, int enVal) {
  int resSt, resEn;

  // 선분의 시작위치보다 크거나 같은 수 중 최솟값 찾기
  int st = 0;
  int en = n-1;
  while(st <= en) {
    int mid = (st + en) / 2;
    if(points[mid] < stVal) {
      st = mid + 1;
    } else {
      en = mid - 1;
    }
  }
  resSt = st;

  // 선분위 끝 위치보다 작거나 같은 수 중 최댓값 찾기
  st = 0;
  en = n-1;
  while(st <= en) {
    int mid = (st + en) / 2;
    if(points[mid] <= enVal) {
      st = mid + 1;
    } else {
      en = mid - 1;
    }
  }
  resEn = en;

  return resEn - resSt + 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    points.push_back(temp);
  }

  sort(points.begin(), points.end());

  for(int i = 0; i < m; i++) {
    cin >> stVal >> enVal;
    cout << binarySearch(stVal, enVal) << "\n";
  }

  return 0;
}