#include <bits/stdc++.h>
using namespace std;

const int INF = 0x4f4f4f4f;
int N, M, W, TC, S, E, T;

int dist[501];

void resetDist() {
  for(int i = 1; i <= N; i++) {
    dist[i] = INF;
  }
}

bool bellman(int s, vector<pair<int, int>> *graph) {
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      // j번 노드의 인접 노드들에 대해 거리 갱신
      for(int k = 0; k < graph[j].size(); k++) {
        int nextNode = graph[j][k].first;
        int nextWeight = graph[j][k].second;

        // INF 비교를 하지 않아도 됨. dist[j]가 INF라서 지나치게 되면 뒤에있는 사이클의 유무를 판단할 수 없음.
        // 만약 단절된 경우라면 dist[j]는 INF고, 단절된 정점끼리 사이클을 형성했다면 사이클은 형성되었지만 사이클 유무를 판단할 수 없게됨
        // https://www.acmicpc.net/board/view/50494
        if(dist[nextNode] > dist[j] + nextWeight) {
          // N번 반복 시에도 거리가 갱신됨 == 음의 사이클이 존재함을 의미
          if(i == N) return true;

          dist[nextNode] = dist[j] + nextWeight;
        }
      }
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> TC;
  while(TC--) {
    vector<pair<int, int>> graph[501];  // <노드 번호, 가중치>

    cin >> N >> M >> W;
    // 도로는 방향이 없음
    for(int i = 1; i <= M; i++) {
      cin >> S >> E >> T;
      graph[S].push_back({E, T});
      graph[E].push_back({S, T});
    }
    // 웜홀은 방향이 있음
    for(int i = 1; i <= W; i++) {
      cin >> S >> E >> T;
      graph[S].push_back({E, -T});
    }

     resetDist();
    
    // 출발 지점으로 다시 돌아올 수 있는 경우, 해당 그래프는 무조건 사이클을 가진다.
    // 이 때, 음의 사이클을 가지는 경우가 출발 지점으로 돌아왔을 때의 비용이 음수가 되는 경우이다.
    // 즉, 음의 사이클 여부만 판단하면 되므로 아무 노드나 출발 지점으로 선택하여 벨만-포드 알고리즘을 적용해도 된다.
    // https://www.acmicpc.net/board/view/54167
    if(bellman(1, graph)) {              
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }

  return 0;
}