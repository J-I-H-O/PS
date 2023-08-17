#include <iostream>
#include <vector>
using namespace std;

int garden[10][10];
bool visited[10][10];
int n;
int ans = 0x4f4f4f4f;  // INF
vector<pair<int, int>> selected;  // <row, col>
int dr[5] = {-1, 0, 1, 0, 0};
int dc[5] = {0, 1, 0, -1, 0};

// 현재 위치에 꽃을 심을 수 있는지 판단
bool check(int curR, int curC) {
  // 1. 상하좌우 끝쪽에는 꽃을 심을 수 없음
  if(curR <= 0 || curC <= 0 || curR >= n-1 || curC >= n-1) return false;

  // 2. 지금까지 꽃을 심은 지점(selected)과 겹치는 경우에는 꽃을 심을 수 없음
  for(int i = 0; i < 5; i++) {
    int crFlower = curR + dr[i];
    int ccFlower = curC + dc[i];

    if(visited[crFlower][ccFlower]) return false;
  }

  return true;
}

int calCost() {
  int res = 0;
  for(int i = 0; i < selected.size(); i++) {
    int curR = selected[i].first;
    int curC = selected[i].second;

    for(int j = 0; j < 5; j++) {
      int crFlower = curR + dr[j];
      int ccFlower = curC + dc[j];

      res += garden[crFlower][ccFlower];
    }
  }
  return res;
}

void combination() {
  if(selected.size() == 3) {
    int costSum = calCost();
    if(ans > costSum) {
      ans = costSum;
    }
    return;
  }

  for(int i = 1; i < n; i++) {
    for(int j = 1; j < n; j++) {
      // 다른 꽃들과 겹치지 않고, 화단 밖으로 꽃잎이 나가지 않는 경우만 고려
      if(check(i, j)) {
        for(int k = 0; k < 5; k++) {
          visited[i + dr[k]][j + dc[k]] = true;
        }
        selected.push_back({i, j});
        combination();
        selected.pop_back();
        for(int k = 0; k < 5; k++) {
          visited[i + dr[k]][j + dc[k]] = false;
        }
      }
    }
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> garden[i][j];
    }
  }
  
  combination();

  cout << ans;

  return 0;
}