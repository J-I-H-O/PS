#include <bits/stdc++.h>
using namespace std;

int A[50][50];
bool visited[50][50];
int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {1, 0, -1, 0};
int N, L, R, days = 0;
bool flag = true;  // 하루가 지났을 때 전체 나라 중 인구이동이 발생했는지 여부 저장
vector<pair<int, int>> unit; // 하나의 연합에 속하는 나라들의 좌표 저장

void clearVisited() {
  // visited 초기화
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      visited[i][j] = false;
    }
  }
}

void clearUnit() {
  for(int i = 0; i < unit.size(); i++) {
    unit.pop_back();
  }
}

void BFS(int x, int y) {
  int sum = 0;  // 하나의 연합 내의 나라들의 인구 수의 합

  queue<pair<int, int>> q;
  q.push({x, y});

  visited[x][y] = true;
  sum += A[x][y];
  unit.push_back({x, y}); // 인구가 변경될 국가 추적

  while(!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();

    for(int i = 0; i < 4; i++) {
      int nextX = cur.first + dirX[i];
      int nextY = cur.second + dirY[i];
      if(0 <= nextX && nextX < N && 0 <= nextY && nextY < N) {
        if(!visited[nextX][nextY]) {
          int diff = abs(A[cur.first][cur.second] - A[nextX][nextY]);
          if(L <= diff && diff <= R) {
            q.push({nextX, nextY});

            visited[nextX][nextY] = true;
            sum += A[nextX][nextY];
            unit.push_back({nextX, nextY}); // 인구가 변경될 국가 추적

            flag = true;
          }
        }
      }
    }
  }

  // 인구 수 변경
  for(int k = 0; k < unit.size(); k++) {
    int curX = unit[k].first;
    int curY = unit[k].second;
    A[curX][curY] = sum / unit.size();
  }
  clearUnit();
}

int main() {
  cin >> N >> L >> R;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> A[i][j];
    }
  }

  // 더이상 인구이동이 없을 때 까지 반복
  while(flag) {
    days++;
    flag = false;
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        if(!visited[i][j]) {
          BFS(i, j);
        }
      }
    }
    clearVisited();
  }

  // 이전 단계에서 인구 이동이 있는 경우 위 과정을 한번 더 반복하므로, 
  // 인구 이동이 더이상 없을 때까지 소요된 기간은 현재까지 반복된 횟수-1임
  cout << days-1;

  return 0;
}