#include <bits/stdc++.h>
using namespace std;

int n, temp;
vector<int> input;

// 버블 정렬
// 매 단계별로 바로 다음원소와 비교, 현재 원소가 다음 원소보다 큰 경우 교환.
// IDEA: Move the maximum to the end of unsorted area.
void bubbleSort() {
  for(int i = input.size() - 1; i > 0; i--) {
    for(int j = 0; j < i; j++) {
      if(input[j] > input[j+1]) {
        int temp = input[j];
        input[j] = input[j+1];
        input[j+1] = temp;
      }
    }
  }
}

// 선택 정렬
// 매 단계별로 unsorted area에서 최댓값을 찾아 sorted area로 이동
// IDEA: Move the maximum to the end of unsorted area
void selectionSort() {
  for(int i = input.size() - 1; i > 0; i--) {
    int maxIdx = 0;
    // unsorted area에서의 최대값의 인덱스를 저장
    for(int j = 0; j <= i; j++) {
      if(input[j] > input[maxIdx]) {
        maxIdx = j;
      }
    }
    int temp = input[i];
    input[i] = input[maxIdx];
    input[maxIdx] = temp;
  }
}

// 삽입 정렬
// 매 단계별로 선택한 수를 sorted area의 적절한 자리로 삽입
// IDEA: Pick the front of the unsorted area, and insert it into its right poosition of the sorted area.
void insertionSort() {
  // 첫번째 원소는 이미 정렬되어 sorted area에 포함되어 있다고 생각, 두번째 원소부터 정렬 시작
  // [0, i-1] : sorted area
  for(int i = 1; i < input.size(); i++) {
    int target = input[i];
    int foundIdx = i;
    // sorted area의 값들을 뒤에서부터 확인, target의 적절한 위치를 찾을 때 까지 뒤로 밀어줌
    while(foundIdx-1 >= 0 && input[foundIdx-1] > target) {
      input[foundIdx] = input[foundIdx-1];
      foundIdx--;
    }
    // target보다 큰 수들을 모두 뒤로 밀었다면, 현재 위치가 target이 삽입될 적절한 위치
    input[foundIdx] = target;
  }
}

// 병합 정렬
// 배열을 재귀적으로 반으로 나누어 왼쪽 배열, 오른쪽 배열로 구분. 각 배열들을 정렬한 뒤 병합.
// 왼쪽 배열 : [left, middle], 오른쪽 배열 : [middle + 1, right]
void merge(int left, int middle, int right) {
  vector<int> result;
  int leftCursor = left;
  int rightCursor = middle + 1;
  // 왼쪽 배열과 오른쪽 배열이 모두 비어있지 않은 경우 반복
  while(leftCursor <= middle && rightCursor <= right) {
    // leftCursor가 가리키는 왼쪽 배열의 값이 rightCursor가 가리키는 오른쪽 배열의 값보다 작은 경우, 왼쪽 값을 결과에 넣어줌
    if(input[leftCursor] < input[rightCursor]) 
      result.push_back(input[leftCursor++]);
    else 
      result.push_back(input[rightCursor++]);
    
  }
  // 왼쪽 배열 또는 오른쪽 배열이 비어있는 상태, 아직 비어있지 않은 배열을 결과 배열에 붙여줌
  while(leftCursor <= middle) {
    result.push_back(input[leftCursor++]);
  }
  while(rightCursor <= right) {
    result.push_back(input[rightCursor++]);
  }

  // 병합 결과를 입력 배열에 반영
  for(int i = 0; i <= right - left; i++) {
    input[left + i] = result[i];
  }
}

void mergeSort(int left, int right) {
  if(left < right) {
    int middle = (left + right) / 2;

    // 왼쪽 배열과 오른쪽 배열에 대해 재귀적으로 mergeSort 진행
    mergeSort(left, middle);
    mergeSort(middle + 1, right);
  
    // 나눈 왼쪽 배열과 오른쪽 배열을 병합 (이 때, 양쪽 배열은 모두 정렬된 상태임)
    merge(left, middle, right);
  }
}

// 로무토 파티션
// 퀵 정렬에서 pivot의 올바른 위치를 찾는데 사용
// 마지막 원소를 pivot으로 설정하고, left partition과 right partition의 크기를 점진적으로 증가시킴
int lomutoPartition(int left, int right) {
  // 마지막 원소를 pivot으로 지정
  int pivot = input[right];
  // i는 pivot보다 작은 left partition의 마지막을 가리킴
  int i = left - 1;
  // j를 왼쪽 끝 부분 부터 right-1까지 증가
  for(int j = left; j < right; j++) {
    // pivot보다 작거나 같은 원소를 찾으면 i를 1 증가시키고, i가 가리키는 값과 j가 가리키는 값의 위치를 바꿈
    // (i가 left partition의 끝을 가리키므로.)
    if(input[j] <= pivot) {
      i++;
      int temp = input[j];
      input[j] = input[i];
      input[i] = temp;
    }
  }
  // 일단 선택된 pivot(input[right])의 위치를 left partition의 뒤로 옮김
  int temp = input[i+1];
  input[i+1] = input[right];
  input[right] = temp;

  return i + 1;
}

// 퀵 정렬
// 입력된 배열에서 pivot을 선택, pivot을 기준으로 배열을 둘로 분할
// pivot을 기준으로 pivot보다 작은 원소들은 pivot의 왼쪽으로, pivot보다 큰 원소들은 pivot의 오른쪽으로 옮김
void quickSort(int left, int right) {
  if(left < right) {
    int pivot = lomutoPartition(left, right);

    quickSort(left, pivot - 1);
    quickSort(pivot + 1, right);
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    input.push_back(temp);
  }

  // bubbleSort();
  // selectionSort();
  // insertionSort();
  // mergeSort(0, n-1);
  quickSort(0, n-1);

  for(int i = 0; i < input.size(); i++) {
    cout << input[i] << "\n";
  }

  return 0;
}