#include <iostream>
#include <vector>
using namespace std;

int n, temp, curLoc = 0;  // curLoc: 현재 지나고 있는 코스 번호
long long k, sum = 0;
vector<int> course;

int main() {
  cin >> n >> k;

  course.push_back(0);  // dummy data
  for (int i = 0; i < n; i++) {
    cin >> temp;
    course.push_back(temp);
  }

  // 먼저 끝까지 이동
  while (sum <= k && curLoc < n) {
    curLoc++;
    sum += course[curLoc];
  }
  // 다시 돌아옴
  while (sum <= k && curLoc > 0) {
    sum += course[curLoc];

    if(sum > k) break;

    curLoc--;
  }

  cout << curLoc;

  return 0;
}