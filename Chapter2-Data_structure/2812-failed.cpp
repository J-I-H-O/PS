#include <bits/stdc++.h>
using namespace std;

int n, k;
string input;
string ans;
int deleteCnt = 0;  // 제거 한 숫자의 개수 카운트
int startIdx;       // 범위 시작 인덱스
int endIdx;         // 범위 종료 인덱스
int maxIdx;         // 범위 내의 숫자 중 가장 큰 것의 인덱스 저장
int maxVal;         // 범위 내의 숫자 중 가장 큰 것의 값 저장

int main() {
  cin >> n >> k;
  cin >> input;

  startIdx = 0;
  endIdx = startIdx + (k - deleteCnt);
  while(endIdx < n) {
    maxIdx = startIdx;
    maxVal = input[maxIdx];
    // 범위 내의 수 중 가장 큰 것의 인덱스와 값 찾기
    for(int i = startIdx; i <= endIdx; i++) {
      if(input[i] > maxVal) {
        maxIdx = i;
        maxVal = input[maxIdx];
      }
    }

    // 가장 큰 값 이전의 숫자들은 제거했다고 판단, 제거한 수의 개수만큼 deleteCnt 증가
    deleteCnt += maxIdx - startIdx;

    // 현재 범위 시작 인덱스의 숫자가 가장 큰 경우, 다음 자리 숫자를 시작 인덱스로 살펴봄
    if(maxIdx == startIdx) {
      startIdx++;
    }
    else {
      // 가장 큰 숫자의 다음 자리 숫자부터 다시 살펴봄
      startIdx = maxIdx + 1;
    }
    endIdx = startIdx + (k - deleteCnt); // (k - deleteCnt) : 남은 제거 횟수

    // 범위 내의 숫자 중 가장 큰 것을 선택(정답에 이어붙임), 이전의 수들은 모두 제거한 것으로 판단
    ans.push_back(maxVal);
  }

  // k개의 숫자를 지운 후, 아직 살펴보지 못한 수가 있으면 모두 정답에 이어붙임
  if(deleteCnt == k) {
    for(int i = startIdx; i < n; i++) {
      ans.push_back(input[i]);
    }
  }

  cout << ans;

  return 0;
}