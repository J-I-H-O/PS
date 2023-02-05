#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000001;
int n, temp;
vector<int> oilCost;  // 각 도시에서의 기름값
vector<int> dist;     // 간선의 비용
long long ans;

int main() {
  cin >> n;
  for(int i = 0; i < n-1; i++) {
    cin >> temp;
    dist.push_back(temp);
  }
  for(int i = 0; i < n; i++) {
    cin >> temp;
    oilCost.push_back(temp);
  }

  oilCost[n-1] = INF;
  int cur = 0;  // 현재 도시 번호
  int nxt = 1;  // 다음에 살펴볼 도시 번호
  while(nxt < n) {
    ans += oilCost[cur] * (long long) dist[nxt-1];
    if(oilCost[cur] > oilCost[nxt])
      cur = nxt;
    nxt++;
  }

  cout << ans;

  return 0;
}