#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, m;
  string input;
  vector<string> DNA;

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> input;
    DNA.push_back(input);
  }

  string ans = "";
  int ansCnt = 0;
  for (int i = 0; i < m; i++) {
    map<char, int> cnt;  // 전체 문자열의 i번째 문자의 빈도 수 검사

    for (int j = 0; j < n; j++) {
      cnt[DNA[j][i]] += 1;
    }

    int maxCnt = 0;  // i번째 문자 중 가장 많이 등장한 문자의 빈도수
    char maxChar;  // i번째 문자 중 가장 많이 등장한 문자 저장
    for(map<char, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
      // map은 기본적으로 key 값을 기준으로 오름차순 정렬되어있음
      if(maxCnt < it->second) {
        maxChar = it->first;
        maxCnt = it->second;
      }
    }

    ansCnt += n - maxCnt;
    ans += maxChar;
  }

  cout << ans << "\n";
  cout << ansCnt;

  return 0;
}