#include <bits/stdc++.h>
using namespace std;

int n;
long long temp;
vector<long long> muscleLoss;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    muscleLoss.push_back(temp);
  }

  sort(muscleLoss.begin(), muscleLoss.end());

  long long minMuscleLoss = 0;
  // 운동기구의 개수가 홀수인 경우, 근손실이 가장 큰 운동기구만 따로 빼내고 나머지 운동기구들을 짝을 이룸
  if(n % 2 != 0) {
    minMuscleLoss = muscleLoss[n-1];
    n--;
  }
  for(int i = 0; i < n/2; i++) {
    if(minMuscleLoss < muscleLoss[i] + muscleLoss[n-i-1])
      minMuscleLoss = muscleLoss[i] + muscleLoss[n-i-1];
  }

  cout << minMuscleLoss;
  
  return 0;
}