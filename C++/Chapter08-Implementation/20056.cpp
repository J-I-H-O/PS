#include <iostream>
#include <vector>
using namespace std;

vector<pair<pair<int, int>, int>> fireball[50][50]; // <<m, s>, d>
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int n, m, k;
int r, c, m, s, d;

// 1. 파이어볼이 자신의 방향으로 속력만큼 이동
void moveFireball() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      // 현재 칸에 파이어볼이 존재하는 경우
      for(int k = 0; k < fireball[i][j].size(); k++) {
        pair<pair<int, int>, int> curFireball = fireball[i][j][k];
        int dir = curFireball.second;
        if(dir == 0) {

        }
      }
    }
  }
}

int main() {
  cin >> n >> m >> k;
  for(int i = 0; i < m; i++) {
    cin >> r >> c >> m >> s >> d;
    fireball[r][c].push_back({{m, s}, d});
  }

  while(k--) {
    moveFireball();
  }

  return 0;
}