#include <bits/stdc++.h>
using namespace std;

string input;
string minAns;
string maxAns;

string getMax() {
  int mCnt = 0;
  for(int i = 0; i < input.size(); i++) {
    if(input[i] == 'K') {
      // k를 만나면 추가한 M의 개수만큼 pop
      for(int j = 0; j < mCnt; j++) {
        maxAns.pop_back();
      }

      maxAns += '5';
      for(int j = 0; j < mCnt; j++) {
          maxAns += '0';
      }
      mCnt = 0;
    }

    if(input[i] == 'M') {
      mCnt++;
      // M을 만나면 일단 정답에 1을 추가하고, 이후 k를 만나면 추가한 M의 개수만큼 pop
      maxAns += '1';
    }
  }
  return maxAns;
}

string getMin() {
  string temp = input + 'K';
  int mCnt = 0;
  for(int i = 0; i < temp.size(); i++) {
    if(temp[i] == 'K') {
      if(mCnt != 0) {
        minAns += '1';
        for(int j = 1; j < mCnt; j++) {
          minAns += '0';
        }
        mCnt = 0;
      }
      minAns += '5';
    } else {
      mCnt++;
    }
  }
  minAns.pop_back();
  
  return minAns;
}

int main() {
  cin >> input;
  cout << getMax() << "\n" << getMin();

  return 0;
}