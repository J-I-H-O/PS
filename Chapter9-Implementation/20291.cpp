#include <bits/stdc++.h>
using namespace std;

int n;
string input;
map<string, int> files;  // <확장자, 등장횟수>

int main() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> input;

    // '.'을 구분자로 입력 파일 이름을 자름
    istringstream ss(input);
    vector<string> subStr;
    while(getline(ss, input, '.')) {
      subStr.push_back(input);
    }

    // 입력된 파일의 확장자
    string extension = subStr[subStr.size() - 1];
    files[extension] += 1;
  }

  for(map<string, int>::iterator it = files.begin(); it != files.end(); it++) {
    cout << it->first << " " << it->second << "\n";
  }

  return 0;
}