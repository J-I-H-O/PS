#include <bits/stdc++.h>
using namespace std;

int n, m;
// nCm을 combination[n][m]의 형태로 저장. 
// 계산 결과가 long long 자료형의 범위를 벗어나므로 문자열로 bit inteager를 구현하여 사용함
// long long 자료형으로 나타낼 수 있는 최대값은 (2^63 - 1) 이나, 구하고자 하는 조합은 이를 아득히 뛰어넘음
// e.g) 100C50
string combination[101][101]; 

// 문자열로 표현된 두 수를 더한 값을 문자열로 리턴
// long long 자료형의 범위를 넘는 값의 덧셈을 위함
string addStringNum(string a, string b) {
  int lastDigitSum = 0;
  string res = "";

  // a 또는 b의 크기가 0보다 큰 동안 반복
  while(!a.empty() || !b.empty()) {
    int lastDigitA = 0;
    int lastDigitB = 0;

    if(!a.empty()) {
      // a의 마지막 자리 문자를 숫자로 변환
      lastDigitA = a.back() - '0';
      a.pop_back();
    }
    if(!b.empty()) {
      // b의 마지막 자리 문자를 숫자로 변환
      lastDigitB = b.back() - '0';
      b.pop_back();
    }
    // a와 b의 마지막 자리수의 합 계산 결과 중 자리올림을 제외한 수를 문자로 변환하여 res에 저장
    lastDigitSum += lastDigitA + lastDigitB;
    res.push_back(lastDigitSum % 10 + '0');

    // lastDigitA + lastDigitB 계산 중 발생한 자리올림을 다음 자릿수 계산에 반영하기 위함
    lastDigitSum /= 10;
  }
  // 계산 종료 후 마지막으로 자리올림 된 수도 결과에 추가
  if(lastDigitSum != 0) 
    res.push_back(lastDigitSum + '0');

  // 계산 결과를 res에 거꾸로 저장했으므로 뒤집어서 리턴
  reverse(res.begin(), res.end());
  return res;
}

// 파스칼의 삼각형 이용
// nCm = n-1Cm-1 + n-1Cm
string getCombination(int n, int m) {
  // 파스칼 삼각형의 양쪽 끝
  if(n == m || m == 0) 
    return "1";
  // 이전에 계산해놓은 값이 있는 경우 재사용 (DP)
  if(combination[n][m] != "")
    return combination[n][m];
  
  // memorization
  // nCm = n-1Cm-1 + n-1Cm
  combination[n][m] = addStringNum(getCombination(n-1, m-1), getCombination(n-1, m));
  return combination[n][m];
}

int main() {
  cin >> n >> m;
  cout << getCombination(n, m);

  return 0;
}