#include <bits/stdc++.h>
using namespace std;

string input, ans;
stack<char> s;
int wordStartIdx, wordEndIdx; // 단어의 시작 인덱스와 끝 인덱스 저장

int main() {
  getline(cin, input);
  for(int i = 0; i < input.size(); i++) {
    // tag 처리
    if(input[i] == '<') {
      while(input[i] != '>') {
        ans.push_back(input[i]);
        i++;
      }
      ans.push_back(input[i]);
    } else if(input[i] == ' ') {
      ans.push_back(input[i]);
    } else {
      // 단어인 경우
      while(i+1 < input.size() && input[i+1] != ' ' && input[i+1] != '<') {        
        s.push(input[i]);
        i++;
      }
      s.push(input[i]);

      while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
      }
    }
  }

  cout << ans;

  return 0;
}