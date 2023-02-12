#include <bits/stdc++.h>
using namespace std;

int t, n, temp;

int main() {
  cin >> t;
  while(t--) {
    vector<int> adjList[1001];
    bool visited[1001] = {0,};
    stack<int> s;
    int ans = 0;

    cin >> n;
    for(int i = 1; i <= n; i++) {
      cin >> temp;
      adjList[i].push_back(temp);
    }
    // 순열 사이클의 개수 == 연결 요소의 개수
    for(int i = 1; i <= n; i++) {
      if(!visited[i]) {
        ans++;
        // DFS
        s.push(i);
        while(!s.empty()) {
          int cur = s.top();
          visited[cur] = true;
          s.pop();

          for(int i = 0; i < adjList[cur].size(); i++) {
            if(!visited[adjList[cur][i]]) {
              s.push(adjList[cur][i]);
              visited[adjList[cur][i]] = true;
            }
          }
        }
      }
    }
    cout << ans << "\n";
  } 
  


  return 0;
}