#include <bits/stdc++.h>
using namespace std;

int k, temp;
vector<int> s;            // 현재 테스트케이스에서의 집합 S
vector<int> selected;     // 현재까지 선택된 요소들

// vector 비우기
void clearS() {
  while(!s.empty())
    s.pop_back();
}

void clearSelected() {
  while(!selected.empty())
    selected.pop_back();
}

// 현재 selected를 모두 출력
void printSelected() {
  for(vector<int>::iterator it = selected.begin(); it != selected.end(); it++) {
    printf("%d ", *it);
  }
  printf("\n");
}

// 테스트 출력용
void printCurStatus() {
  printf("selected : ");
  for(vector<int>::iterator it = selected.begin(); it != selected.end(); it++) {
    printf("%d ", *it);
  }
  printf("\n");
}

// 실제 정답을 출력하는 재귀함수
// cur는 현재 숫자의 index
void selectNum(int cur) {
  // base condition
  // 선택된 숫자가 6개 이상이면 현재 선택된 숫자들을 출력하고 맨 마지막 숫자를 selected에서 제거
  if(selected.size() >= 6) {
    //printSelected();
    
    return;
  }

  selected.push_back(s[cur]);
  //printf("(pushed : %d)\n", s[cur]);
  //printCurStatus();

  for(int i = cur + 1; i < k; i++) {
    selectNum(i);
  }

  if(selected.size() >= 6) {
    printSelected();  
  }

  //printf("(poped : %d)\n", selected.back());
  selected.pop_back();
}

int main() {  
  scanf("%d", &k);
  while(k != 0) {
    // vector s, selected 비우기
    clearS();
    clearSelected();

    // 현재 테스트케이스의 입력
    for(int i = 0; i < k; i++) {
      scanf("%d", &temp);
      s.push_back(temp);
    }

    for(int i = 0; i <= k-6; i++) {
      selectNum(i);
      clearSelected();
    }
    printf("\n");

    scanf("%d", &k);
  }

  return 0;
}