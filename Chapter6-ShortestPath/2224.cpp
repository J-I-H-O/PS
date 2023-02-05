#include <bits/stdc++.h>
using namespace std;

const int MAX = 52;
const int INF = 0x3f3f3f3f;
char p, q;
string temp;
int n, startVal, endVal;
int dist[MAX][MAX];
vector<pair<char, char>> ans;

void floyd() {
  // 모든 노드에 대하여 반복
  for(int k = 0; k < MAX; k++) {
    // 모든 노드-모든 노드 쌍의 경로 파악
    for(int i = 0; i < MAX; i++) {
      for(int j = 0; j < MAX; j++) {
        if(dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }
  }
}

int main() {
  // 인접행렬 초기화
  for(int i = 0; i < MAX; i++) {
    for(int j = 0; j < MAX; j++) {
      dist[i][j] = INF;
    }
  }

  cin >> n;
  for(int i = 0; i < n; i++) {
      cin >> p;
      cin >> temp;
      cin >> q;

    if('A' <= p && p <= 'Z') {
      startVal = p - 'A';
    }
    if('a' <= p && p <= 'z') {
      startVal = p - 'a' + 26;
    }
    if('A' <= q && q <= 'Z') {
      endVal = q - 'A';
    }
    if('a' <= q && q <= 'z') {
      endVal = q - 'a' + 26;
    }
    
    dist[startVal][endVal] = 1;
  }

  floyd();

  for(int i = 0; i < MAX; i++) {
    for(int j = 0; j < MAX; j++) {
      if(i != j && dist[i][j] < INF) {
        char a, b;
        // 소문자인 경우
        if(i < 26) {
          a = i + 'A';
        } else {
          a = i + 'a' - 26;
        }
        if(j < 26) {
          b = j + 'A';
        } else {
          b = j + 'a' - 26;
        }
        ans.push_back({a, b});
      }
    }
  }

  sort(ans.begin(), ans.end());

  cout << ans.size() << "\n";
  for(int i = 0; i < ans.size(); i++) {
    cout << ans[i].first << " => " << ans[i].second << "\n";
  }

  return 0;
}