#include <bits/stdc++.h>
using namespace std;

int n, val;
string command;

const int MAX = 100000;
// 배열로 스택 구현
class Stack {
  private:
  int data[MAX + 1];
  int top; 

  public:
  Stack() {
    top = -1;
  }

  void push(int x) {
    if(top != MAX) {
      data[++top] = x;
    }
  }
  void pop() {
    // 스택에 들어있는 정수가 없는 경우(비어있는 경우)
    if(top == -1)
      printf("-1\n");
    else {
      // pop은 top을 하나 감소시킴으로써 구현
      printf("%d\n", data[top--]);
    }
  }
  void size() {
    printf("%d\n", top + 1);
  }
  void empty() {
    // 스택이 비어있는 경우
    if(top == -1)
      printf("1\n");
    else
      printf("0\n");
  }
  void getTop() {
    // 스택이 비어있는 경우
    if(top == -1) 
      printf("-1\n");
    else 
      printf("%d\n", data[top]);
  }
};

int main() {
  Stack *s = new Stack();
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> command;
    
    if(command == "push") {
      cin >> val;
      s->push(val);
    }
    else if(command == "pop") {
      s->pop();
    }
    else if(command == "size") {
      s->size();
    }
    else if(command == "empty") {
      s->empty();
    }
    else if(command == "top") {
      s->getTop();
    }
  }

  delete s;

  return 0;
}