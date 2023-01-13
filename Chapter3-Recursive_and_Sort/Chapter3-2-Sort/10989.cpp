#include <bits/stdc++.h>
using namespace std;

int n, temp;
map<short, int> m;  // <수, 빈도>

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    // 입력받은 값이 이전에 입력된 적 있는 경우
    if(m.find(temp) != m.end()) {
      m[temp]++;
    }
    else {
      m.insert({temp, 1});
    }
  }

  for(map<short, int>::iterator it = m.begin(); it != m.end(); it++) {
    for(int i = 0; i < (*it).second; i++) {
      cout << (*it).first << "\n";
    }
  }

  return 0;
}