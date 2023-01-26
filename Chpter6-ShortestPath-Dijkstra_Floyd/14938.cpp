#include <bits/stdc++.h>
using namespace std;

const int INF = 0x2f2f2f2f;
int n, m, r;
int a, b, w;
int itemNum[101];
int dist[101][101];

void floyd() {
  for(int k = 1; k <= n; k++) {
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        if(dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }
}

// 지역 번호를 매개변수로 입력받아, 해당 지역에 낙하했을 때 얻을 수 있는 아이템의 개수를 리턴
int getItemSum(int locNum) {
  int itemSum = 0;

  for(int i = 1; i <= n; i++) {
    if(dist[locNum][i] <= m)
      itemSum += itemNum[i];
  }

  return itemSum;
}

int main() {
  cin >> n >> m >> r;
  for(int i = 1; i <= n; i++) {
    cin >> itemNum[i];

    // dist 배열 초기화
    for(int j = 1; j <= n; j++) {
      if(i == j)
        dist[i][j] = 0;
      else
        dist[i][j] = INF;
    }
  }

  for(int i = 1; i <= r; i++) {
    cin >> a >> b >> w;
    dist[a][b] = w;
    dist[b][a] = w;
  }

  floyd();

  // 획득할 수 있는 최대 아이템 개수 구하기
  int maxItemNum = 0;
  for(int i = 1; i <= n; i++) {
    // i번 지역에 낙하했을 때 얻을 수 있는 아이템의 개수 반환
    int res = getItemSum(i);

    if(maxItemNum < res)
      maxItemNum = res;
  }
  cout << maxItemNum;

  return 0;
}