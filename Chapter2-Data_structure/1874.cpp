#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, temp;
  stack<int> s;
  vector<char> ans;
  int nextNum = 1;  // 다음에 스택에 삽입할 수 있는 값
  
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    // 
    while(nextNum <= temp) {
      s.push(nextNum++);
      ans.push_back('+');
    }
    
    if(s.empty()) {
      printf("NO");
      return 0;
    }
    
    while(!s.empty() && s.top() >= temp) {
      s.pop();
      ans.push_back('-');
    }
  }

  // 스택이 비어있지 않으면, 스택 수열을 만들지 못한 경우임.
  if(!s.empty()) {
    printf("NO");
  }
  else {
    for(int i = 0; i < ans.size(); i++) {
      printf("%c\n", ans[i]);
    }
  }


  return 0;
}