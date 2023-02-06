#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int k, n, temp;
int maxCableLen = 0;
vector<int> cables;

// 길이 len으로 만들 수 있는 랜선의 개수 계산
int getCableNum(ll len) {
  ll res = 0;
  for(int i = 0; i < k; i++) {
    res += cables[i] / len;
  }
  return res;
}

// N개를 만들 수 있는 랜선의 최대 길이 리턴
int binarySerch() {
  ll st = 1;
  ll en = maxCableLen; // 가장 긴 케이블의 길이

  while(st < en) {
    ll mid = (st + en + 1) / 2;
    // mid를 기준으로 랜선을 자르는 경우, n개의 랜선보다 적은 랜선을 얻을 수 있다면 길이의 범위를 줄여야 함.
    if(getCableNum(mid) < n) {
      en = mid - 1;
    } else {
      st = mid;
    }
  }

  return st;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  cin >> k >> n;
  for(int i = 0 ; i < k; i++) {
    cin >> temp;
    cables.push_back(temp);

    if(maxCableLen < temp) {
      maxCableLen = temp;
    }
  }
  
  sort(cables.begin(), cables.end());

  cout << binarySerch();

  return 0;
}