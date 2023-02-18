#include <iostream>
using namespace std;

int x, y, z;

int binarySearch() {
  int st = 1;
  int en = x;

  while(st < en) {
    int mid = (st + en) / 2;  // 추가로 플레이한 게임 횟수
    int winRate = ((y + mid) / (long double)(x + mid)) * 100;
    
    if(winRate != z) {
      // mid 만큼 플레이했을 때 승률이 변한 경우, 해당 경우를 포함하여 범위를 좁힘
      en = mid;
    } else {
      // 승률이 변하지 않은 경우, 현재 추가로 플레이한 횟수보다 더 많이 플레이해야 함
      st = mid + 1;
    }
  }

  return en;
}

int main() {
  cin >> x >> y;
  z = (y / (long double)x) * 100;

  // 기존 승률이 99% 이상이어서 승률이 절대 변하지 않는 경우
  if(z >= 99) {
    cout << -1;
  } else {
    cout << binarySearch();
  }

  return 0;
}