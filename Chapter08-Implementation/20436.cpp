#include <bits/stdc++.h>
using namespace std;

                              // a       b       c       d       e 
pair<int, int> keyboard[26] = {{2, 1}, {3, 5}, {3, 3}, {2, 3}, {1, 3},
                               {2, 4}, {2, 5}, {2, 6}, {1, 8}, {2, 7},
                               {2, 8}, {2, 9}, {3, 7}, {3, 6}, {1, 9},
                               {1, 10}, {1, 1}, {1, 4}, {2, 2}, {1, 5},
                               {1, 7}, {3, 4}, {1, 2}, {3, 2}, {1, 6}, {3, 1}};
// 한글 자음 위치에 해당하는 알파벳 집합
char consonant[14] = {'q', 'w', 'e', 'r', 't', 'a', 's', 'd', 'f', 'g', 'z', 'x', 'c', 'v'};
// 한글 모음 위치에 해당하는 알파벳 집합
char vowels[12] = {'y', 'u', 'i', 'o', 'p', 'h', 'j', 'k', 'l', 'b', 'n', 'm'};

int main() {
  char sL, sR;
  string input;
  int Ltime = 0;
  int Rtime = 0;
  
  cin >> sL >> sR;
  cin >> input;
  for(auto c : input) {
    // 현재 보고있는 문자가 한글 모음 위치인 경우
    if(find(vowels, vowels + 12, c) != vowels + 12) {
      pair<int, int> curLoc = keyboard[sR - 'a'];
      pair<int, int> nxtLoc = keyboard[c - 'a'];

      // 이동하는데 걸리는 시간
      Rtime += (abs(curLoc.first - nxtLoc.first) + abs(curLoc.second - nxtLoc.second));
      // 키를 누르는데 걸리는 시간
      Rtime++;

      sR = c;
    } else {
      pair<int, int> curLoc = keyboard[sL - 'a'];
      pair<int, int> nxtLoc = keyboard[c - 'a'];

      // 이동하는데 걸리는 시간
      Ltime += (abs(curLoc.first - nxtLoc.first) + abs(curLoc.second - nxtLoc.second));
      // 키를 누르는데 걸리는 시간
      Ltime++;

      sL = c;
    }
  }
  cout << Ltime + Rtime;

  return 0;
}