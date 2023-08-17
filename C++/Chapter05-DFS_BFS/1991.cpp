#include <bits/stdc++.h>
using namespace std;

vector<pair<int, char>> adjList[27];
bool visited[27];
int n;
char parent, leftChild, rightChild;

void clearVisited() {
  for(int i = 0; i < 27; i++) {
      visited[i] = false;
  }
}

// 전위, 중위, 후위 순회를 DFS를 이용하여 구현
// 전위 순회
void preorder(int s) {
  visited[s] = true;
  cout << (char)(s + 'A');

  for(int i = 0; i < adjList[s].size(); i++) {
    int next = adjList[s][i].first;
    if(!visited[next]) {
      visited[next] = true;
      preorder(next);
    }
  }
}

// 중위 순회
void inorder(int s) {
  visited[s] = true;

  // 자식이 없는 경우, 자기 자신을 출력하고 종료
  if(adjList[s].size() == 0) {
    cout << (char)(s + 'A');
    return;
  }
  // 자식이 있는 경우.
  // 왼쪽 자식이 있는 경우, 왼쪽 자식에 대해 DFS 먼저 진행하고 자신을 출력
  // 오른쪽 자식이 있는 경우, 자신을 출력한 뒤 오른쪽 자식에 대해 DFS 진행
  else {
    pair<int, char> child = adjList[s][0];

    // 왼쪽 자식이 있는 경우
    if(child.second == 'L') {
      if(!visited[child.first]) {
        visited[child.first] = true;
        inorder(child.first);
      }
    }

    cout << (char)(s + 'A');

    // 양쪽 자식이 모두 있는 경우, child가 오른쪽 자식을 가리키도록 변경
    if(adjList[s].size() == 2)
      child = adjList[s][1];

    // 오른쪽 자식이 있는 경우
    if(child.second == 'R') {
      if(!visited[child.first]) {
        visited[child.first] = true;
        inorder(child.first);
      }
    }
  }
}

// 후위 순회
void postorder(int s) {
  visited[s] = true;

  for(int i = 0; i < adjList[s].size(); i++) {
    int next = adjList[s][i].first;
    if(!visited[next]) {
      visited[next] = true;
      postorder(next);
    }
  }
  cout << (char)(s + 'A');
}

int main() {
  cin >> n;
  // 이진트리를 인접 리스트로 표현
  for(int i = 0; i < n; i++) {
    cin >> parent >> leftChild >> rightChild;
    if('A' <= leftChild && leftChild <= 'Z') {
      adjList[parent - 'A'].push_back({leftChild - 'A', 'L'});
    }
    if('A' <= rightChild && rightChild <= 'Z') {
      adjList[parent - 'A'].push_back({rightChild - 'A', 'R'});
    }
  }

  preorder(0);
  clearVisited();
  cout << "\n";

  inorder(0);
  clearVisited();
  cout << "\n";

  postorder(0);

  return 0;
}