// https://cocoon1787.tistory.com/562
#include <bits/stdc++.h>
using namespace std;

int n, temp, cnt = 0;
// v :   <입력받은 값, 원본 index>
// ans : <원본 index, 좌표 압축 결과>
// pair를 원소로 가지는 벡터를 sort 함수를 이용하여 정렬할 경우, pair의 first를 기준으로 정렬하므로 코드 간결성을 위해 위와 같은 순서로 정의
vector<pair<int, int>> v, ans; 

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    // 입력받은 값과 원본 index 저장
    v.push_back({temp, i});
  }
  
  // 입력받은 값에 대해 오름차순 정렬
  sort(v.begin(), v.end());

  // 입력받은 수 중 가장 작은 값의 좌표 압축 결과는 0
  ans.push_back({v[0].second, 0});
  for(int i = 1; i < n; i++) {
    // 중복되는 값은 카운트 하지 않음
    if(v[i-1].first == v[i].first) {
      ans.push_back({v[i].second, cnt});
    } 
    else {
      ans.push_back({v[i].second, ++cnt});
    }
  }

  // 처음에 입력받은 순서에 대해 오름차순 정렬
  sort(ans.begin(), ans.end());

  for(int i = 0; i < ans.size(); i++) {
    cout << ans[i].second << " ";
  }


  return 0;
}