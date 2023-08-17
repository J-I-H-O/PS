#include <iostream>
#include <vector>
using namespace std;

int n, kNum, temp;
vector<int> k;
vector<int> selected;
int ans = 0;

// 현재 선택된 수들을 정수로 변환
int calSelected() {
  int res = 0;
  for (int i = 0; i < selected.size(); i++) {
    res *= 10;
    res += selected[i];
  }
  return res;
}

void findAns() {
  // 현재까지 선택된 결과가 n보다 작을 때 현재까지의 최댓값보다 크면 ans 갱신
  int res = calSelected();
  if (res > n) {
    return;
  } else {
    if (ans < res) {
      ans = res;
    }
  }

  for (int i = 0; i < k.size(); i++) {
    selected.push_back(k[i]);
    findAns();
    selected.pop_back();
  }
}

int main() {
  cin >> n >> kNum;
  for (int i = 0; i < kNum; i++) {
    cin >> temp;
    k.push_back(temp);
  }

  findAns();

  cout << ans;

  return 0;
}