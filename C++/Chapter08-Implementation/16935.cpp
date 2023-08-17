#include <iostream>
#include <algorithm>
using namespace std;

int n, m, r, command;
int arr[100][100];
int tempArr[100][100];  // 3, 4번 연산 시 결과 배열을 임시 저장하기 위해 사용

void execOp(int command) {
  switch(command) {
    // 1번 연산, 상하 반전
    case 1:
      for(int i = 0; i < (n+1)/2; i++) {
        for(int j = 0; j < m; j++) {
          swap(arr[i][j], arr[n-i-1][j]);
        }
      }
      break;

    // 2번 연산
    case 2:
      for(int i = 0; i < (m+1)/2; i++) {
        for(int j = 0; j < n; j++) {
          swap(arr[j][i], arr[j][m-i-1]);
        }
      }
      break;

    // 3번 연산. 3번, 4번 연산의 경우, 배열의 가로 세로 길이가 바뀌므로 n과 m을 바꿔줘야 함
    case 3:
      // 오른쪽으로 90도 회전
      // -> arr의 각 행이 tempArr의 열로 뒤에서부터 채워짐
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
          tempArr[j][n-1-i] = arr[i][j];
        }
      }
      for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
          arr[i][j] = tempArr[i][j];
        }
      }
      swap(n, m);
      break;

    // 4번 연산
    case 4:
      // 왼쪽으로 90도 회전
      // -> arr의 각 행이 tempArr의 열로 앞에서부터 뒤집혀서 채워짐
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
          tempArr[m-1-j][i] = arr[i][j];
        }
      }
      for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
          arr[i][j] = tempArr[i][j];
        }
      }
      swap(n, m);
    break;

    // 5번 연산
    case 5:
      //  2   1
      //  4   3
      for(int i = 0; i < n/2; i++) {
        for(int j = 0; j < m/2; j++) {
          swap(arr[i][j], arr[i][m/2 + j]);
        }
      }
      //  3   1
      //  4   2
      for(int i = 0; i < n/2; i++) {
        for(int j = 0; j < m/2; j++) {
          swap(arr[i][j], arr[n/2 + i][m/2 + j]);
        }
      }
      //  4   1
      //  3   2
      for(int i = 0; i < n/2; i++) {
        for(int j = 0; j < m/2; j++) {
          swap(arr[i][j], arr[n/2 + i][j]);
        }
      }
      break;

    // 6번 연산
    case 6:
      //  4   2
      //  1   3
      for(int i = 0; i < n/2; i++) {
        for(int j = 0; j < m/2; j++) {
          swap(arr[i][j], arr[n/2 + i][j]);
        }
      }
      //  3   2
      //  1   4
      for(int i = 0; i < n/2; i++) {
        for(int j = 0; j < m/2; j++) {
          swap(arr[i][j], arr[n/2 + i][m/2 + j]);
        }
      }
      //  2   3
      //  1   4
      for(int i = 0; i < n/2; i++) {
        for(int j = 0; j < m/2; j++) {
          swap(arr[i][j], arr[i][m/2 + j]);
        }
      }
      break;
  }
}

int main() {
  cin >> n >> m >> r;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
    
  for(int i = 0; i < r; i++) {
    cin >> command;
    execOp(command);
  }
    
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }
    
  return 0;
}