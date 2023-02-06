#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, height, temp;
int maxTreeHeight = 0;
vector<int> trees;

// 주어진 높이로 나무를 잘랐을 때 얻을 수 있는 나무의 길이의 합이 m보다 크거나 같은지 판별
bool isTreeSumOverM(int height) {
  ll treeSum = 0;
  for(int i = trees.size() - 1; i >= 0 ; i--) {
    int cur = trees[i] - height;
    if(0 < cur) {
      treeSum += cur;
    }
    if(treeSum >= m) return true;
  }

  return false;
}

// 설정할 수 있는 높이의 최댓값 반환
int binarySearch() {
  int st = 0;
  int en = maxTreeHeight; // 가장 높은 나무의 높이로 설정

  while(st < en) {
    int mid = (st + en + 1) / 2;
    // treeSum >= m
    if(isTreeSumOverM(mid)) {
      st = mid;
    } else {
      en = mid - 1;
    }
  }

  return st;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    trees.push_back(temp);

    if(maxTreeHeight < temp) {
      maxTreeHeight = temp;
    }
  }

  sort(trees.begin(), trees.end());

  cout << binarySearch();

  return 0;
}