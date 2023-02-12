#include <bits/stdc++.h>
using namespace std;

string input;

// 내림차순으로 정렬
bool comp(char a, char b) {
  return a > b;
}

int main() {
  cin >> input;
  sort(input.begin(), input.end(), comp);
  cout << input;

  return 0;
}