#include <bits/stdc++.h>
using namespace std;

int temp;
vector<int> nums;

void printVector() {
  for(int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
  cout << "\n";
}

int main() {
  for(int i = 0; i < 5; i++) {
    cin >> temp;
    nums.push_back(temp);
  }

  for(int i = 4; i > 0; i--) {
    for(int j = 0; j < i; j++) {
      if(nums[j] > nums[j+1]) {
        int temp = nums[j];
        nums[j] = nums[j+1];
        nums[j+1] = temp;

        printVector();
      }
    }
  }


  return 0;
}