#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000001;
int n, temp;
vector<int> dist;
vector<int> oilPrice;

int main() {
  cin >> n;
  dist.push_back(0);  // dummy data
  for(int i = 0; i < n-1; i++) {
    cin >> temp;
    dist.push_back(temp);
  }
  for(int i = 0; i < n; i++) {
    cin >> temp;
    oilPrice.push_back(temp);
  }

  // 코드의 간결성을 위해 마지막 지역의 기름 가격은 무한대로 설정
  oilPrice.pop_back();
  oilPrice.push_back(INF);

  // 현재까지 방문한 도시의 위치
  int cur = 0;
  long long priceSum = 0;
  while(cur < n-1) {
    int nxt = cur+1;

    // 일단 다음 지역로 이동할 수 있을만큼만 주유
    if(oilPrice[cur] > oilPrice[nxt]) {
      priceSum += oilPrice[cur] * dist[nxt];
    } else {
      // 현재 지역보다 가격이 낮은 지역을 만나기 전까지 그 경로상에 있는 도로의 길이만큼 현재 지역에서 주유
      while(nxt < n && oilPrice[nxt] >= oilPrice[cur]) {
        priceSum += ((long long)oilPrice[cur] * dist[nxt]);
        nxt++;
      }
    }

    cur = nxt;
  }

  cout << priceSum;

  return 0;
}