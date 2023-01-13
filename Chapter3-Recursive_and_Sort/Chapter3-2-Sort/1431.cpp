#include <bits/stdc++.h>
using namespace std;

int n;
string temp;
vector<string> input;

bool comp(string a, string b) {
  // a와 b의 길이가 다르면, 짧은 것이 먼저 옴
  if(a.size() != b.size())
    return a.size() < b.size();

  // 서로 길이가 같다면 a의 모든 자리수의 합과 b의 모든 자리수의 합을 비교해 작은 합을 가지는 것이 먼저 옴(숫자만 합)
  int sumA = 0;
  int sumB = 0;
  for(auto c : a) {
    if('0' <= c && c <= '9')
      sumA += c - '0';
  }
  for(auto c : b) {
    if('0' <= c && c <= '9')
      sumB += c - '0';
  }
  if(sumA != sumB)
    return sumA < sumB;
  
  // 위 두 조건으로 비교할 수 없으면 사전순으로 비교
  for(int i = 0; i < a.size(); i++) {
    if(a[i] != b[i])
      return a[i] < b[i];
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    input.push_back(temp);
  }
  sort(input.begin(), input.end(), comp);
  for(int i = 0; i < n; i++) {
    cout << input[i] << "\n";
  }

  return 0;
}