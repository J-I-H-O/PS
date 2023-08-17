#include <iostream>
using namespace std;

int peopleNum, t, chant;  // 게임을 진행하는 사람 수, 구하고자 하는 번째, 구하고자 하는 구호
int cnt1 = 0, cnt2 = 0;   // cnt1: "뻔"을 외친 횟수, cnt2: "데기"를 외친 횟수
int cur = 0;              // 현재 차례의 사람 번호
int roundNum = 2;

int main() {
  cin >> peopleNum >> t >> chant;

  while (true) {
    cnt1++;  // 뻔
    if (chant == 0 && cnt1 == t) {
      cout << cur;
      return 0;
    }
    cur = (cur + 1) % peopleNum;

    cnt2++;  // 데기
    if (chant == 1 && cnt2 == t) {
      cout << cur;
      return 0;
    }
    cur = (cur + 1) % peopleNum;

    cnt1++;  // 뻔
    if (chant == 0 && cnt1 == t) {
      cout << cur;
      return 0;
    }
    cur = (cur + 1) % peopleNum;

    cnt2++;  // 데기
    if (chant == 1 && cnt2 == t) {
      cout << cur;
      return 0;
    }
    cur = (cur + 1) % peopleNum;

    for (int i = 0; i < roundNum; i++) {
      cnt1++;  // 뻔
      if (chant == 0 && cnt1 == t) {
        cout << cur;
        return 0;
      }
      cur = (cur + 1) % peopleNum;
    }

    for (int i = 0; i < roundNum; i++) {
      cnt2++;  // 데기
      if (chant == 1 && cnt2 == t) {
        cout << cur;
        return 0;
      }
      cur = (cur + 1) % peopleNum;
    }
    roundNum++;
  }

  return 0;
}